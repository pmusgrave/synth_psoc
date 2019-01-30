#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    adc_update_flag = 1;

    ADC_EOC_INT_ClearPending();
}

CY_ISR_PROTO(OSC_0_OVF_VECT){
    main_osc_PWM_0_WritePeriod((uint16) 65535/freq_0);
    main_osc_PWM_0_WriteCompare((uint16) (65535/freq_0)/(2000/pulse_width_0));
}

CY_ISR_PROTO(OSC_1_OVF_VECT){
    main_osc_PWM_1_WritePeriod((uint16) 65535/freq_1);
    main_osc_PWM_1_WriteCompare((uint16) (65535/freq_1)/(2000/pulse_width_1));
    
}

CY_ISR_PROTO(OSC_2_OVF_VECT){
    main_osc_PWM_2_WritePeriod((uint16) 65535/freq_2);
    main_osc_PWM_2_WriteCompare((uint16) (65535/freq_2)/(2000/pulse_width_2));
}

CY_ISR_PROTO(OSC_3_OVF_VECT){
    main_osc_PWM_3_WritePeriod((uint16) 65535/freq_3);
    main_osc_PWM_3_WriteCompare((uint16) (65535/freq_3)/(2000/pulse_width_3));
}

CY_ISR_PROTO(ENV_0_OVF_VECT){
}

CY_ISR_PROTO(ENV_1_OVF_VECT){
}

CY_ISR_PROTO(ENV_2_OVF_VECT){
}

CY_ISR_PROTO(ENV_3_OVF_VECT){
}

/* [] END OF FILE */
