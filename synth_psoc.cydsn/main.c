#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "envelope_generator.h"
#include "oscillator.h"

volatile uint8_t current_mode = NOT_TRIGGERED;
volatile uint8_t pwm_update_flag = 0;
volatile uint16_t pwm_value = 0;
volatile float freq = 0;
volatile float pulse_width = 0;

int main(void)
{
    CyGlobalIntEnable;

    InitEnvelopeGenerator();
    envelope_trigger_StartEx(envelope_trigger_vector);
    ENVELOPE_TIMER_Start();
    ENVELOPE_TIMER_INT_StartEx(envelope_timer_vect);
    
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    ADC_EOC_INT_StartEx(ADC_EOC);
    
    InitOscillator();
    main_osc_PWM_Start();
    //LFO_PWM_Start();
    LED_PWM_Start();    
    
    current_mode = NOT_TRIGGERED;
    
    green_led_Write(1);

    for(;;)
    {
        if(pwm_update_flag != 0){ 
            pwm_update_flag = 0;
            
            SetMainOscValue(freq, pulse_width);
      
            //LFO_PWM_WritePeriod((uint16) 65535/freq);
            //LFO_PWM_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
            
            switch(current_mode){
            case NOT_TRIGGERED:
                attack_debug_led_Write(1);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                pwm_value = 0;
                ENVELOPE_TIMER_WriteCounter(0);
                break;
            case ATTACK_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(1);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                ENVELOPE_TIMER_WritePeriod(attack_pot_value);
                ENVELOPE_TIMER_WriteCompare(attack_pot_value);
                pwm_value = (65535 / attack_pot_value) * ENVELOPE_TIMER_ReadCounter();
                break;
            case DECAY_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(1);
                release_debug_led_Write(0);
                
                ENVELOPE_TIMER_WritePeriod(decay_pot_value);
                ENVELOPE_TIMER_WriteCompare(decay_pot_value);
                pwm_value = (double)((sustain_pot_value - 65535)/ decay_pot_value) * ENVELOPE_TIMER_ReadCounter() + 65535;
                break;
            case SUSTAIN_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(1);
                
                ENVELOPE_TIMER_WriteCounter(0);
                ENVELOPE_TIMER_Stop();
                pwm_value = sustain_pot_value;
                break;
            case RELEASE_MODE:
                attack_debug_led_Write(0);
                decay_debug_led_Write(0);
                sustain_debug_led_Write(0);
                release_debug_led_Write(0);
                
                ENVELOPE_TIMER_Enable();
                ENVELOPE_TIMER_WritePeriod(release_pot_value);
                ENVELOPE_TIMER_WriteCompare(release_pot_value);
                pwm_value = (double)((-sustain_pot_value * ENVELOPE_TIMER_ReadCounter() / release_pot_value)) + sustain_pot_value;
                break;
            }
            
            /*
            pwm_value+=100;
            if (pwm_value >= 1000){
                pwm_value = 0;
            }
            LED_PWM_WriteCompare(pwm_value);
            */
        }
    }
}
/* [] END OF FILE */
