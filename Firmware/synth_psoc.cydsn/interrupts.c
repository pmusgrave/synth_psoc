#include "project.h"
#include "envelope_generator.h"
#include "interrupts.h"
#include "globals.h"

CY_ISR(ADC_EOC) {
    adc_update_flag = 1;

    ADC_EOC_INT_ClearPending();
}

CY_ISR_PROTO(OSC_0_OVF_VECT){
    main_osc_PWM_0_WritePeriod((uint16_t) 65535/Osc_0.freq);
    main_osc_PWM_0_WriteCompare((uint16_t) (65535/Osc_0.freq)/(2000/Osc_0.pulse_width));
    //main_osc_PWM_0_WriteCompare((uint16_t) (65535/freq_0)/2);
}

CY_ISR_PROTO(OSC_1_OVF_VECT){
    main_osc_PWM_1_WritePeriod((uint16_t) 65535/Osc_1.freq);
    main_osc_PWM_1_WriteCompare((uint16_t) (65535/Osc_1.freq)/(2000/Osc_1.pulse_width));
    //main_osc_PWM_1_WriteCompare((uint16_t) (65535/freq_1)/2);
}

CY_ISR_PROTO(OSC_2_OVF_VECT){
    main_osc_PWM_2_WritePeriod((uint16_t) 65535/Osc_2.freq);
    main_osc_PWM_2_WriteCompare((uint16_t) (65535/Osc_2.freq)/(2000/Osc_2.pulse_width));
    //main_osc_PWM_2_WriteCompare((uint16_t) (65535/freq_2)/2);
}

CY_ISR_PROTO(OSC_3_OVF_VECT){
    main_osc_PWM_3_WritePeriod((uint16_t) 65535/Osc_3.freq);
    main_osc_PWM_3_WriteCompare((uint16_t) (65535/Osc_3.freq)/(2000/Osc_3.pulse_width));
    //main_osc_PWM_3_WriteCompare((uint16_t) (65535/freq_3)/2);
}

CY_ISR_PROTO(ENV_0_OVF_VECT){
    envelope_PWM_0_WriteCompare((uint16_t) env0_pwm);
    //envelope_PWM_0_WriteCompare((uint16_t) pwm);
}

CY_ISR_PROTO(ENV_1_OVF_VECT){
    envelope_PWM_1_WriteCompare((uint16_t) env1_pwm);
    //envelope_PWM_1_WriteCompare((uint16_t) pwm);
}

CY_ISR_PROTO(ENV_2_OVF_VECT){
    envelope_PWM_2_WriteCompare((uint16_t) env2_pwm);
    //envelope_PWM_2_WriteCompare((uint16_t) pwm);
}

CY_ISR_PROTO(ENV_3_OVF_VECT){
    envelope_PWM_3_WriteCompare((uint16_t) env3_pwm);
    //envelope_PWM_3_WriteCompare((uint16_t) pwm);
}

CY_ISR_PROTO(MIDI_RX_VECT){
    //MIDI_RX_flag = 1;
}

/* [] END OF FILE */
