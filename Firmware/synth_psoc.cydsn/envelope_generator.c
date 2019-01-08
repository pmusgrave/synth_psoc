/* ========================================
 *
*/
#include "envelope_generator.h"

void InitEnvelopeGenerator(){
    // attack_pot_high_Write(1);
    
    
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
