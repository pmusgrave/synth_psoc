#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"

extern uint8_t current_mode;
extern uint8_t pwm_update_flag;
extern uint16_t pwm_value;
extern float freq;
extern float pulse_width;

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
    //led_1_Write(~led_1_Read());
    
    switch(current_mode){
    case NOT_TRIGGERED:
        current_mode = ATTACK_MODE;
        pwm_value = 0;
        break;
    case SUSTAIN_MODE:
        current_mode = RELEASE_MODE;
        break;
    }

    envelope_trigger_ClearPending();    
}

CY_ISR(envelope_timer_vect){  
    //led_1_Write(~led_1_Read());
    
    switch(current_mode){
    case NOT_TRIGGERED:
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
/* [] END OF FILE */
