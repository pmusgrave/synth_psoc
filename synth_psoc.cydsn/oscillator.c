#include "project.h"
#include "oscillator.h"

void InitOscillator(){
    freq_pot_low_Write(0);
    freq_pot_high_Write(1);    
    pulse_width_pot_high_Write(1);
    pulse_width_pot_low_Write(0);
}

/* [] END OF FILE */
