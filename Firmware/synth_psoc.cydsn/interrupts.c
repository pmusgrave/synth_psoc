#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    pwm_update_flag = 1;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(1);  
    
    freq_1 = ADC_SAR_Seq_1_GetResult16(2);
    pulse_width_1 = ADC_SAR_Seq_1_GetResult16(3);  
    
    freq_2 = ADC_SAR_Seq_1_GetResult16(4);
    pulse_width_2 = ADC_SAR_Seq_1_GetResult16(5);  
    
    freq_3 = ADC_SAR_Seq_1_GetResult16(6);
    pulse_width_3 = ADC_SAR_Seq_1_GetResult16(7);  
    
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
    
    switch(current_mode){
    case NOT_TRIGGERED:
        current_mode = NOT_TRIGGERED;
        break;
    case ATTACK_MODE:
        current_mode = DECAY_MODE;
        break;
    case DECAY_MODE:
        current_mode = SUSTAIN_MODE;
        break;
    case SUSTAIN_MODE:
        current_mode = SUSTAIN_MODE;
        break;
    case RELEASE_MODE:
        current_mode = NOT_TRIGGERED;
        break;
    }
    
    ENVELOPE_TIMER_ReadStatus();
    ENVELOPE_TIMER_ClearInterrupt(ENVELOPE_TIMER_INTR_MASK_TC);
}

CY_ISR(ramp_timer_vect){
    RAMP_TIMER_ReadStatus();
    RAMP_TIMER_ClearInterrupt(RAMP_TIMER_INTR_MASK_TC);
}
/* [] END OF FILE */
