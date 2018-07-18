/* ========================================
 *
*/
#include "envelope_generator.h"

void InitEnvelopeGenerator(){
    // attack_pot_high_Write(1);
    attack_pot_low_Write(0);
    decay_pot_high_Write(1);
    decay_pot_low_Write(0);
    sustain_pot_high_Write(1);
    sustain_pot_low_Write(0);
    release_pot_high_Write(1);
    release_pot_low_Write(0);
    
    //pwm_value = 0;
    envelope_triggered = 0;
}
/*
uint16_t CalculateNewPwmValue(uint8_t state){
    switch(state) {
        case ATTACK_MODE:
            ++pwm_value;
            break;
        
        case DECAY_MODE:
            --pwm_value;
            break;
        
        case SUSTAIN_MODE: 
            break;
        
        case RELEASE_MODE:
            --pwm_value;
            break;
    }
    
    return pwm_value;
}
*/
/* [] END OF FILE */
