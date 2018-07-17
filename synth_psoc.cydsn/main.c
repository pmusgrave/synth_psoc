#include "project.h"
#include "envelope_generator.h"

void InitOscillator();

CY_ISR(ADC_EOC) {
    float freq = 0;
    float pulse_width = 0;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(1);
   
    PWM_1_WritePeriod((uint16) 65535/freq);
    
    // this is a square wave with 50% duty cycle
    //PWM_1_WriteCompare((uint16) (65535/freq)/2);
    
    // this is pulse width modulation, although the 2000 does not make any sense.
    // wasn't getting good results with 65535/pulse_width?
    // fix this later
    PWM_1_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
    
    attack_pot_value = ADC_SAR_Seq_1_GetResult16(ATTACK_POT_ADC_CHANNEL);
    decay_pot_value = ADC_SAR_Seq_1_GetResult16(DECAY_POT_ADC_CHANNEL);
    sustain_pot_value = ADC_SAR_Seq_1_GetResult16(SUSTAIN_POT_ADC_CHANNEL);
    release_pot_value = ADC_SAR_Seq_1_GetResult16(RELEASE_POT_ADC_CHANNEL);
    
    ADC_EOC_INT_ClearPending();
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    InitOscillator();
    InitEnvelopeGenerator();
    
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    PWM_1_Start();
    ADC_EOC_INT_StartEx(ADC_EOC);
       
    for(;;)
    {
       
    }
}

void InitOscillator(){
    freq_pot_high_Write(1);
    pulse_width_pot_high_Write(1);
    pulse_width_pot_low_Write(0);
}
/* [] END OF FILE */
