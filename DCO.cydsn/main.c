#include "project.h"

#define ADC_CHANNEL 0u

int convert_voltage_to_frequency(int voltage);
int convert_frequency_to_time_delay(int frequency);
void toggle_square_wave();

CY_ISR(ADC_EOC) {
    float freq = 0;
    float pulse_width = 0;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(1);
   
    PWM_1_WritePeriod((uint16) 65535/freq);
    PWM_1_WriteCompare((uint16) (65535/freq)/2);
   
    ADC_EOC_INT_ClearPending();
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    freq_pot_high_Write(1);
    pulse_width_pot_high_Write(1);
    pulse_width_pot_low_Write(0);
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    PWM_1_Start();
    ADC_EOC_INT_StartEx(ADC_EOC);
       
    for(;;)
    {
        //ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT);
       
    }
}

int convert_voltage_to_frequency(int voltage) {
    return voltage;
}

int convert_frequency_to_time_delay(int frequency){
    return ((1.0/(frequency+1)) * 1000);
}

void toggle_square_wave(){
    square_wave_output_Write(~square_wave_output_Read());
}

/* [] END OF FILE */
