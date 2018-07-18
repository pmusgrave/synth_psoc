/* ========================================
 *
*/
#include "project.h"
#define ATTACK_POT_ADC_CHANNEL 2
#define DECAY_POT_ADC_CHANNEL 3
#define SUSTAIN_POT_ADC_CHANNEL 4
#define RELEASE_POT_ADC_CHANNEL 5

static volatile uint16_t attack_pot_value;
static volatile uint16_t decay_pot_value;
static volatile uint16_t sustain_pot_value;
static volatile uint16_t release_pot_value;
static volatile _Bool envelope_triggered;

void InitEnvelopeGenerator();
uint16_t GetAttackPotValue();
uint16_t GetDecayPotValue();
uint16_t GetSustainPotValue();
uint16_t GetReleasePotValue();
/* [] END OF FILE */
