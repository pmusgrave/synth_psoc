#include "project.h"
#include "oscillator.h"
#include "globals.h"

void InitOscillator(){
    freq_pot_low_Write(0);
    freq_pot_high_Write(1);    
    pulse_width_pot_high_Write(1);
    pulse_width_pot_low_Write(0);
}

void SetMainOscValue(){
    main_osc_PWM_WritePeriod((uint16) 65535/freq);
            
    // this is a square wave with 50% duty cycle
    //main_osc_PWM_WriteCompare((uint16) (65535/freq)/2);
    
    // this is pulse width modulation, although the 2000 does not make any sense.
    // wasn't getting good results with 65535/pulse_width?
    // fix this later
    main_osc_PWM_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
    
    main_osc_PWM_1_WritePeriod((uint16) 65535/freq_1);
    main_osc_PWM_1_WriteCompare((uint16) (65535/freq_1)/(2000/pulse_width_1));
    
    main_osc_PWM_2_WritePeriod((uint16) 65535/freq_2);
    main_osc_PWM_2_WriteCompare((uint16) (65535/freq_2)/(2000/pulse_width_2));
    
    main_osc_PWM_3_WritePeriod((uint16) 65535/freq_3);
    main_osc_PWM_3_WriteCompare((uint16) (65535/freq_3)/(2000/pulse_width_3));
}

/* [] END OF FILE */
