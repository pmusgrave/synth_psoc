#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    pwm_update_flag = 1;

    ADC_EOC_INT_ClearPending();
}

CY_ISR_PROTO(OSC_0_OVF_VECT){
    main_osc_PWM_0_WritePeriod((uint16) 65535/freq);
    main_osc_PWM_0_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
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

CY_ISR_PROTO(SYS_TICK_OVF_VECT){
    update_delay_buffer_flag = 1;
}

/* [] END OF FILE */
