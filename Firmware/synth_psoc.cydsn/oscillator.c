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


// I don't think these have to be separate functions,
// unless I want to do something more complicated than execute the function pointer.
// It might be good to check the state of the oscillator before calling the
// enable function? Otherwise, I could probably get rid of this function
// and the disable single oscillator function.
void EnableSingleOscillator(void (*osc_enable_function)(void)){
    (*osc_enable_function)();
}

void DisableSingleOscillator(void (*osc_disable_function)(void)){
    (*osc_disable_function)();
}

double Quantize(float unquantized_freq){
    volatile double music_notes[99] = {
        27.50,
        29.14,	
        30.87,	
        32.70,	
        34.65,	
        36.71,	
        38.89,	
        41.20,	
        43.65,	
        46.25,	
        49.00,	
        51.91,	
        55.00,
        58.27,	
        61.74,	
        65.41,	
        69.30,	
        73.42,	
        77.78,	
        82.41,	
        87.31,	
        92.50,	
        98.00,	
        103.83,	
        110.00,	
        116.54,
        123.47,
        130.81,
        138.59,
        146.83,	
        155.56,	
        164.81,	
        174.61,	
        185.00,	
        196.00,	
        207.65,	
        220.00,	
        233.08,	
        246.94,	
        261.63,	
        277.18,
        293.66,
        311.13,	
        329.63,	
        349.23,	
        369.99,
        392.00,	
        415.30,	
        440.00,	
        466.16,	
        493.88,	
        523.25,	
        554.37,	
        587.33,	
        622.25,
        659.25,	
        698.46,	
        739.99,	
        783.99,	
        830.61,	
        880.00,	
        932.33,	
        987.77,	
        1046.50,
        1108.73,
        1174.66,
        1244.51,
        1318.51,
        1396.91,
        1479.98,
        1567.98,
        1661.22,
        1760.00,
        1864.66,
        1975.53,
        2093.00,
        2217.46,
        2349.32,
        2489.02,
        2637.02,
        2793.83,
        2959.96,
        3135.96,
        3322.44,
        3520.00,
        3729.31,
        3951.07,
        4186.01,
        4434.92,
        4698.63,
        4978.03,
        5274.04,
        5587.65,
        5919.91,
        6271.93,
        6644.88,
        7040.00,
        7458.62,
        7902.13
    };

    double hz = 65535/(200000/unquantized_freq);
    double quantized_freq = 0;

    for (int i = 0; i < 99; i++){
        if(hz >= music_notes[i]){
            quantized_freq = music_notes[i];
        }
    }
    
    return (200000*quantized_freq/65535);
}
/* [] END OF FILE */
