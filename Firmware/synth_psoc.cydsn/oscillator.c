#include "project.h"
#include "oscillator.h"
#include "globals.h"

// this is a square wave with 50% duty cycle
//main_osc_PWM_WriteCompare((uint16) (65535/freq)/2);

// this is pulse width modulation, although the 2000 does not make any sense.
// wasn't getting good results with 65535/pulse_width?
// fix this later

void EnableAllOscillators(){
    main_osc_PWM_0_Start();
    main_osc_PWM_1_Start();
    main_osc_PWM_2_Start();
    main_osc_PWM_3_Start();
}

void DisableAllOscillators(){
    main_osc_PWM_0_Stop();
    main_osc_PWM_1_Stop();
    main_osc_PWM_2_Stop();
    main_osc_PWM_3_Stop();
}

void EnableSingleOscillator(void (*osc_enable_function)(void)){
    // I don't think these have to be separate functions,
    // unless I want to do something more complicated than call the function pointer.
    // It might be good to check the state of the oscillator before calling the
    // enable function? Otherwise, I could probably get rid of this function
    // and the disable single oscillator function.
    (*osc_enable_function)();
}

void DisableSingleOscillator(void (*osc_disable_function)(void)){
    (*osc_disable_function)();
}
/* [] END OF FILE */
