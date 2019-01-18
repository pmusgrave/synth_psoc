#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "oscillator.h"
#include "buttons.h"

#define ENVELOPE_MAX_PERIOD 2048

#define FREQ_0_ADC_CHAN 0
#define PW_0_ADC_CHAN 1
#define FREQ_1_ADC_CHAN 2
#define PW_1_ADC_CHAN 3
#define FREQ_2_ADC_CHAN 4
#define PW_2_ADC_CHAN 5
#define FREQ_3_ADC_CHAN 6
#define PW_3_ADC_CHAN 7

volatile uint8_t adc_update_flag = 0;
volatile uint16_t pwm_value = 0;
volatile float freq_0 = 0;
volatile float pulse_width_0 = 0;
volatile float freq_1 = 0;
volatile float pulse_width_1 = 0;
volatile float freq_2 = 0;
volatile float pulse_width_2 = 0;
volatile float freq_3 = 0;
volatile float pulse_width_3 = 0;

int main(void)
{
    CyGlobalIntEnable;

    // Start all ADC components
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_EOC_INT_StartEx(ADC_EOC);
    CyDelayUs(10);
    
    // Init main oscillator PWM components
    EnableAllOscillators();
    
    // Init interrupts to change PWM values on overflow
    osc_0_ovf_StartEx(OSC_0_OVF_VECT);
    osc_1_ovf_StartEx(OSC_1_OVF_VECT);
    osc_2_ovf_StartEx(OSC_2_OVF_VECT);
    osc_3_ovf_StartEx(OSC_3_OVF_VECT);
    
    // Init Capsense
    CapSense_Buttons_Start();	
	CapSense_Buttons_InitializeAllBaselines();
    CapSense_Buttons_ScanEnabledWidgets();
    
    
    
    while(1){
        // update all ADC values when the end of conversion interrupt triggers
        if(adc_update_flag != 0){ 
            adc_update_flag = 0;
               
            freq_0 = ADC_SAR_Seq_GetResult16(FREQ_0_ADC_CHAN);
            pulse_width_0 = ADC_SAR_Seq_GetResult16(PW_0_ADC_CHAN);  
            
            freq_1 = ADC_SAR_Seq_GetResult16(FREQ_1_ADC_CHAN);
            pulse_width_1 = ADC_SAR_Seq_GetResult16(PW_1_ADC_CHAN);
            
            freq_2 = ADC_SAR_Seq_GetResult16(FREQ_2_ADC_CHAN);
            pulse_width_2 = ADC_SAR_Seq_GetResult16(PW_2_ADC_CHAN);  
            
            freq_3 = ADC_SAR_Seq_GetResult16(FREQ_3_ADC_CHAN);
            pulse_width_3 = ADC_SAR_Seq_GetResult16(PW_3_ADC_CHAN);  
        }
        
        // scan all CapSense buttons sequentially,
        // and start oscillator if button is pressed
        if(!CapSense_Buttons_IsBusy()) {
            CapSense_Buttons_UpdateEnabledBaselines();
            
            HandleButton(CapSense_Buttons_BUTTON0__BTN, &main_osc_PWM_0_Start, &main_osc_PWM_0_Stop);
            HandleButton(CapSense_Buttons_BUTTON1__BTN, &main_osc_PWM_1_Start, &main_osc_PWM_1_Stop);
            HandleButton(CapSense_Buttons_BUTTON2__BTN, &main_osc_PWM_2_Start, &main_osc_PWM_2_Stop);
            HandleButton(CapSense_Buttons_BUTTON3__BTN, &main_osc_PWM_3_Start, &main_osc_PWM_3_Stop);
            
            CapSense_Buttons_ScanEnabledWidgets();
        }
    }
}
/* [] END OF FILE */
