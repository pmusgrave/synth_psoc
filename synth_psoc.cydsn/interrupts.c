#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    pwm_update_flag = 1;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(2);  
    
    attack_pot_value = ADC_SAR_Seq_1_GetResult16(ATTACK_POT_ADC_CHANNEL);
    decay_pot_value = ADC_SAR_Seq_1_GetResult16(DECAY_POT_ADC_CHANNEL);
    sustain_pot_value = ADC_SAR_Seq_1_GetResult16(SUSTAIN_POT_ADC_CHANNEL);
    release_pot_value = ADC_SAR_Seq_1_GetResult16(RELEASE_POT_ADC_CHANNEL);
    
    ADC_EOC_INT_ClearPending();
}

CY_ISR(envelope_trigger_vector){
    //green_led_Write(~green_led_Read());
    
    /*
    switch(current_mode){
    case NOT_TRIGGERED:
        current_mode = ATTACK_MODE;
        pwm_value = 0;
        break;
    case SUSTAIN_MODE:
        current_mode = RELEASE_MODE;
        break;
    default:
        current_mode = current_mode;
    }
    */
    
    
    switch(current_mode){
    case NOT_TRIGGERED:
        current_mode = ATTACK_MODE;
        break;
    case ATTACK_MODE:
        current_mode = DECAY_MODE;
        break;
    case DECAY_MODE:
        
        current_mode = SUSTAIN_MODE;
        break;
    case SUSTAIN_MODE:
        
        current_mode = RELEASE_MODE;
        break;
    case RELEASE_MODE:
        current_mode = NOT_TRIGGERED;
        break;
    }
    
    
    envelope_trigger_ClearPending();    
}

CY_ISR(envelope_timer_vect){  
    //green_led_Write(~green_led_Read());
    /*
    switch(current_mode){
    case NOT_TRIGGERED:
        attack_debug_led_Write(0);
        decay_debug_led_Write(0);
        sustain_debug_led_Write(0);
        release_debug_led_Write(0);
        break;
    case ATTACK_MODE:
        attack_debug_led_Write(1);
        decay_debug_led_Write(0);
        sustain_debug_led_Write(0);
        release_debug_led_Write(0);
        current_mode = DECAY_MODE;
        break;
    case DECAY_MODE:
        attack_debug_led_Write(0);
        decay_debug_led_Write(1);
        sustain_debug_led_Write(0);
        release_debug_led_Write(0);
        current_mode = SUSTAIN_MODE;
        break;
    case SUSTAIN_MODE:
        attack_debug_led_Write(0);
        decay_debug_led_Write(0);
        sustain_debug_led_Write(1);
        release_debug_led_Write(0);
        current_mode = SUSTAIN_MODE;
        break;
    case RELEASE_MODE:
        attack_debug_led_Write(0);
        decay_debug_led_Write(0);
        sustain_debug_led_Write(0);
        release_debug_led_Write(1);
        current_mode = NOT_TRIGGERED;
        break;
    }
    */
    
    ENVELOPE_TIMER_ReadStatus();
    ENVELOPE_TIMER_ClearInterrupt(ENVELOPE_TIMER_INTR_MASK_TC);
}
/* [] END OF FILE */
