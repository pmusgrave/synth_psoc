#include "project.h"
#include "oscillator.h"
#include "globals.h"

void InitOscillator(){
    //freq_pot_low_Write(0);
    //freq_pot_high_Write(1);    
    //pulse_width_pot_high_Write(1);
    //pulse_width_pot_low_Write(0);
}

void SetMainOscValue(){
    // this is a square wave with 50% duty cycle
    //main_osc_PWM_WriteCompare((uint16) (65535/freq)/2);
    
    // this is pulse width modulation, although the 2000 does not make any sense.
    // wasn't getting good results with 65535/pulse_width?
    // fix this later
    
}

void EnableOscillators(){
    main_osc_PWM_0_Start();
    main_osc_PWM_1_Start();
    main_osc_PWM_2_Start();
    main_osc_PWM_3_Start();
}

void DisableOscillators(){
    main_osc_PWM_0_Stop();
    main_osc_PWM_1_Stop();
    main_osc_PWM_2_Stop();
    main_osc_PWM_3_Stop();
}

/* [] END OF FILE */
