#ifndef GLOBALS_H
#define GLOBALS_H
#include "project.h"

extern volatile uint8_t current_mode;
extern volatile uint8_t adc_update_flag;
extern volatile float env0_pwm;
extern volatile float env1_pwm;
extern volatile float env2_pwm;
extern volatile float env3_pwm;
extern volatile float freq_0;
extern volatile float pulse_width_0;
extern volatile float freq_1;
extern volatile float pulse_width_1;
extern volatile float freq_2;
extern volatile float pulse_width_2;
extern volatile float freq_3;
extern volatile float pulse_width_3;

/* Need for Identity Reply message */
extern volatile uint8 USB_MIDI1_InqFlags;
extern volatile uint8 USB_MIDI2_InqFlags;
extern uint8 inqFlagsOld;
    
struct button {
    uint8_t note_triggered;
    uint8_t capsense_widget;
    void (*osc_enable_function)(void);
    void (*osc_disable_function)(void);
};

extern volatile double music_notes[];

#endif
/* [] END OF FILE */
