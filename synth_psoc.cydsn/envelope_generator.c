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
    
    envelope_triggered = 0;
}


/* [] END OF FILE */
