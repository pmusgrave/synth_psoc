#ifndef INTERRUPTS_H
#define INTERRUPTS_H
		
#include "cytypes.h"

CY_ISR_PROTO(ADC_EOC);
CY_ISR_PROTO(envelope_trigger_vector);
CY_ISR_PROTO(envelope_timer_vect);
CY_ISR_PROTO(ramp_timer_vect);

#endif
/* [] END OF FILE */
