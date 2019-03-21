#include "project.h"
#include "oscillator.h"
#include "globals.h"

void HandleButton(struct button *button){
    if((*button).hold_check_function() && (*button).repeat_check_function()){
        (*button).note_triggered = 0;
    }
    else if(!(*button).hold_check_function()){
        (*button).note_triggered = 1;
        EnableSingleOscillator((*button).osc_enable_function);
    }
    else if(!(*button).repeat_check_function()){
        (*button).note_triggered = 0;
    }
    else if((*button).hold_check_function() && (CapSense_Buttons_CheckIsWidgetActive((*button).capsense_widget || (*button).MIDI_triggered))){
        (*button).note_triggered = 1;
        EnableSingleOscillator((*button).osc_enable_function);
    }
    else{
        (*button).note_triggered = 0;
    }
}
/* [] END OF FILE */
