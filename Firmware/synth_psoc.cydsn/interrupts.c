#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    pwm_update_flag = 1;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(2);  
    
    attack_pot_value = ADC_SAR_Seq_1_GetResult16(ATTACK_POT_ADC_CHANNEL);
    if(attack_pot_value < 100){
        attack_pot_value = 1;
    }    
    decay_pot_value = ADC_SAR_Seq_1_GetResult16(DECAY_POT_ADC_CHANNEL);
    if(decay_pot_value < 100){
        decay_pot_value = 1;
    }    
    sustain_pot_value = ADC_SAR_Seq_1_GetResult16(SUSTAIN_POT_ADC_CHANNEL);
    if(sustain_pot_value < 100){
        sustain_pot_value = 1;
    }    
    release_pot_value = ADC_SAR_Seq_1_GetResult16(RELEASE_POT_ADC_CHANNEL);
    if(release_pot_value < 100){
        release_pot_value = 5;
    }    
    ADC_EOC_INT_ClearPending();
}

/* [] END OF FILE */
