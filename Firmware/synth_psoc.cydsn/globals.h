#ifndef GLOBALS_H
#define GLOBALS_H
#include "project.h"

struct oscillator {
    volatile float freq;
    volatile float pulse_width;
    uint8 (*quant_check_function)(void);
};

struct envelope {
    float env_speed;
    float env_pwm;
};
    
struct button {
    uint8_t (*hold_check_function)(void);
    uint8_t (*repeat_check_function)(void);
    uint8_t note_triggered;
    uint8_t capsense_widget;
    void (*osc_enable_function)(void);
    void (*osc_disable_function)(void);
};
    
extern volatile uint8_t current_mode;
extern volatile uint8_t adc_update_flag;
extern volatile uint8_t MIDI_RX_flag;

extern volatile struct oscillator Osc_0;
extern volatile struct oscillator Osc_1;
extern volatile struct oscillator Osc_2;
extern volatile struct oscillator Osc_3;

extern volatile struct envelope Osc_0_Envelope;
extern volatile struct envelope Osc_1_Envelope;
extern volatile struct envelope Osc_2_Envelope;
extern volatile struct envelope Osc_3_Envelope;

extern volatile double music_notes[];

#endif
/* [] END OF FILE */
