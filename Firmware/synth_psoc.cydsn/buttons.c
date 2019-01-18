#include "project.h"
#include "oscillator.h"

void HandleButton(uint8_t widget, void (*osc_enable_function)(void), void (*osc_disable_function)(void)){
    if(CapSense_Buttons_CheckIsWidgetActive(widget)){
        EnableSingleOscillator(osc_enable_function);
    }
    else{
        //main_osc_PWM_0_Stop();
        DisableSingleOscillator(osc_disable_function);
    }
}
/* [] END OF FILE */
