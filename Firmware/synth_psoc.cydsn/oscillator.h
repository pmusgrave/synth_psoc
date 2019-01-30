#ifndef OSCILLATOR_H
#define OSCILLATOR_H
#include "project.h"
    
void EnableAllOscillators(void);
void DisableAllOscillators(void);
void EnableSingleOscillator(void (*osc_enable_function)(void));
void DisableSingleOscillator(void (*osc_disable_function)(void));
double Quantize(float);
#endif
/* [] END OF FILE */
