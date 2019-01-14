#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "envelope_generator.h"
#include "oscillator.h"

#define ENVELOPE_MAX_PERIOD 2048

volatile uint8_t current_mode = NOT_TRIGGERED;
volatile uint8_t pwm_update_flag = 0;
volatile uint16_t pwm_value = 0;
volatile float freq = 0;
volatile float pulse_width = 0;
volatile float freq_1 = 0;
volatile float pulse_width_1 = 0;
volatile float freq_2 = 0;
volatile float pulse_width_2 = 0;
volatile float freq_3 = 0;
volatile float pulse_width_3 = 0;

volatile uint8_t NOTE_ENABLE = 0; 

int main(void)
{
    CyGlobalIntEnable;

    // Start all ADC components
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_EOC_INT_StartEx(ADC_EOC);
    CyDelayUs(10);
    
    // Init main oscillator, triangle, saw wave PWM, and LFO components
    InitOscillator();
    EnableOscillators();
    
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
    
    while(1){
        if(pwm_update_flag != 0){ 
            pwm_update_flag = 0;
            
            if (NOTE_ENABLE == 1){
                EnableOscillators();
            }
            else{
                DisableOscillators();
            }
               
            freq = ADC_SAR_Seq_GetResult16(0);
            pulse_width = ADC_SAR_Seq_GetResult16(1);  
            
            freq_1 = ADC_SAR_Seq_GetResult16(2);
            pulse_width_1 = ADC_SAR_Seq_GetResult16(3);  
            
            freq_2 = ADC_SAR_Seq_GetResult16(4);
            pulse_width_2 = ADC_SAR_Seq_GetResult16(5);  
            
            freq_3 = ADC_SAR_Seq_GetResult16(6);
            pulse_width_3 = ADC_SAR_Seq_GetResult16(7);  
            
            
            
      
            //LFO_PWM_WritePeriod((uint16) 65535/freq);
            //LFO_PWM_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
            
            /*
            switch(current_mode){
            case NOT_TRIGGERED:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                pwm_value = 0;
                ENVELOPE_TIMER_Stop();
                ENVELOPE_TIMER_WriteCounter(0);
                break;
            case ATTACK_MODE:
                attack_debug_led_Write(1);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                ENVELOPE_TIMER_Enable();
                ENVELOPE_TIMER_WritePeriod(attack_pot_value);
                ENVELOPE_TIMER_WriteCompare(attack_pot_value);
                pwm_value = (ENVELOPE_MAX_PERIOD / attack_pot_value) * ENVELOPE_TIMER_ReadCounter();
                if(pwm_value >= ENVELOPE_MAX_PERIOD){
                    current_mode++;
                }
                break;
            case DECAY_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(1);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                ENVELOPE_TIMER_WritePeriod(decay_pot_value);
                ENVELOPE_TIMER_WriteCompare(decay_pot_value);
                pwm_value = (double)((sustain_pot_value - ENVELOPE_MAX_PERIOD)/ decay_pot_value) * ENVELOPE_TIMER_ReadCounter() + ENVELOPE_MAX_PERIOD;
                if(pwm_value <= sustain_pot_value){
                    current_mode++;
                }
                break;
            case SUSTAIN_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(1);
                release_debug_led_Write(0);

                ENVELOPE_TIMER_Stop();
                //ENVELOPE_TIMER_WriteCounter(0);
                pwm_value = sustain_pot_value;
                break;
            case RELEASE_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(1);
                
                ENVELOPE_TIMER_WritePeriod(release_pot_value);
                ENVELOPE_TIMER_WriteCompare(release_pot_value);
                ENVELOPE_TIMER_Enable();
                //pwm_value = (double)((-sustain_pot_value * ENVELOPE_TIMER_ReadCounter() / release_pot_value)) + ENVELOPE_MAX_PERIOD;
                pwm_value = (double)((0- sustain_pot_value)/ release_pot_value) * ENVELOPE_TIMER_ReadCounter() + sustain_pot_value;
                
                if(pwm_value == 0){
                    current_mode = NOT_TRIGGERED;
                }
                break;
            }
            
            LED_PWM_WriteCompare(pwm_value);
            
            RAMP_TIMER_WritePeriod(freq);
            RAMP_TIMER_WriteCompare(freq);
            */
        }
        
        if(!CapSense_Buttons_IsBusy()) {
            CapSense_Buttons_UpdateEnabledBaselines();
            
            if(CapSense_Buttons_CheckIsAnyWidgetActive()){
                led_Write(0);
                NOTE_ENABLE = 1;
            }
            else{
                led_Write(1);
                NOTE_ENABLE = 0;
            }
            
            CapSense_Buttons_ScanEnabledWidgets();
        }
        
    }
}
/* [] END OF FILE */
