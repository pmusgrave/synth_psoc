// put this in globals.h
extern volatile uint16_t attack_pot_value;
extern volatile uint16_t decay_pot_value;
extern volatile uint16_t sustain_pot_value;
extern volatile uint16_t release_pot_value;

// and this in main

#include "envelope_generator.h"
volatile uint8_t current_mode = NOT_TRIGGERED;

//initialize above event loop
// current_mode = NOT_TRIGGERED;


// within event loop
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