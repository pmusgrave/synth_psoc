/* ========================================
 *
*/
#include "project.h"
#define ATTACK_POT_ADC_CHANNEL 2
#define DECAY_POT_ADC_CHANNEL 3
#define SUSTAIN_POT_ADC_CHANNEL 4
#define RELEASE_POT_ADC_CHANNEL 5

#define ATTACK_MODE 0
#define DECAY_MODE 1
#define SUSTAIN_MODE 2
#define RELEASE_MODE 3

static volatile uint16_t attack_pot_value;
static volatile uint16_t decay_pot_value;
static volatile uint16_t sustain_pot_value;
static volatile uint16_t release_pot_value;
//static volatile uint16_t pwm_value;
static volatile _Bool envelope_triggered;

void InitEnvelopeGenerator();
uint16_t CalculateNewPwmValue(uint8_t);

/* [] END OF FILE */
