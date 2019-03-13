#include "project.h"
#include "oscillator.h"
#include "globals.h"

void HandleButton(struct button *button){
    if(!(*button).hold_check_function() && CapSense_Buttons_CheckIsWidgetActive((*button).capsense_widget)){
        (*button).note_triggered = 1;
        EnableSingleOscillator((*button).osc_enable_function);
    }
    else if((*button).hold_check_function()){
        (*button).note_triggered = 1;
        EnableSingleOscillator((*button).osc_enable_function);
    }
    else{
        (*button).note_triggered = 0;
        
        //main_osc_PWM_0_Stop();
        //DisableSingleOscillator((*button).osc_disable_function);
    }
}
/* [] END OF FILE */
