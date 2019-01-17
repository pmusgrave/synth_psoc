#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "envelope_generator.h"
#include "oscillator.h"

#define ENVELOPE_MAX_PERIOD 2048

volatile uint8_t current_mode = NOT_TRIGGERED;
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
    
    // and interrupts to change PWM values on overflow
    osc_0_ovf_StartEx(OSC_0_OVF_VECT);
    osc_1_ovf_StartEx(OSC_1_OVF_VECT);
    osc_2_ovf_StartEx(OSC_2_OVF_VECT);
    osc_3_ovf_StartEx(OSC_3_OVF_VECT);
    
    // Init Capsense
    CapSense_Buttons_Start();	
	CapSense_Buttons_InitializeAllBaselines();
    CapSense_Buttons_ScanEnabledWidgets();
    
    current_mode = NOT_TRIGGERED;
    volatile uint8_t NOTE_ENABLE = 0; 
    
    while(1){
        // update all ADC values when the end of conversion interrupt triggers
        if(adc_update_flag != 0){ 
            adc_update_flag = 0;
               
            freq_0 = ADC_SAR_Seq_GetResult16(0);
            pulse_width_0 = ADC_SAR_Seq_GetResult16(1);  
            
            freq_1 = ADC_SAR_Seq_GetResult16(2);
            pulse_width_1 = ADC_SAR_Seq_GetResult16(3);  
            
            freq_2 = ADC_SAR_Seq_GetResult16(4);
            pulse_width_2 = ADC_SAR_Seq_GetResult16(5);  
            
            freq_3 = ADC_SAR_Seq_GetResult16(6);
            pulse_width_3 = ADC_SAR_Seq_GetResult16(7);  
        }
        
        // scan all CapSense buttons sequentially,
        // and start oscillator if button is pressed
        if(!CapSense_Buttons_IsBusy()) {
            CapSense_Buttons_UpdateEnabledBaselines();
            
            /*
            if(CapSense_Buttons_CheckIsAnyWidgetActive()){
                NOTE_ENABLE = 1;
            }
            else{
                NOTE_ENABLE = 0;
            }
            */
            
            if(CapSense_Buttons_CheckIsWidgetActive(CapSense_Buttons_BUTTON0__BTN)){
                main_osc_PWM_0_Start();
            }
            else{
                main_osc_PWM_0_Stop();
            }
            
            if(CapSense_Buttons_CheckIsWidgetActive(CapSense_Buttons_BUTTON1__BTN)){
                main_osc_PWM_1_Start();
            }
            else{
                main_osc_PWM_1_Stop();
            }
            
            if(CapSense_Buttons_CheckIsWidgetActive(CapSense_Buttons_BUTTON2__BTN)){
                main_osc_PWM_2_Start();
            }
            else{
                main_osc_PWM_2_Stop();
            }
            
            if(CapSense_Buttons_CheckIsWidgetActive(CapSense_Buttons_BUTTON3__BTN)){
                main_osc_PWM_3_Start();
            }
            else{
                main_osc_PWM_3_Stop();
            }
            
            CapSense_Buttons_ScanEnabledWidgets();
        }
    }
}
/* [] END OF FILE */
