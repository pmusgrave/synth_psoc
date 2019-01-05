/* ========================================
 *
*/
#ifndef ENVELOPE_GENERATOR_H
#define ENVELOPE_GENERATOR_H
    
#include "project.h"
#include "globals.h"
#define ATTACK_POT_ADC_CHANNEL 3
#define DECAY_POT_ADC_CHANNEL 4
#define SUSTAIN_POT_ADC_CHANNEL 5
#define RELEASE_POT_ADC_CHANNEL 6

#define NOT_TRIGGERED 0
#define ATTACK_MODE 1
#define DECAY_MODE 2
#define SUSTAIN_MODE 3
#define RELEASE_MODE 4

volatile uint16_t attack_pot_value;
volatile uint16_t decay_pot_value;
volatile uint16_t sustain_pot_value;
volatile uint16_t release_pot_value;
//static volatile uint16_t pwm_value;
static volatile _Bool envelope_triggered;

void InitEnvelopeGenerator();
uint16_t CalculateNewPwmValue(uint8_t);

#endif
/* [] END OF FILE */
