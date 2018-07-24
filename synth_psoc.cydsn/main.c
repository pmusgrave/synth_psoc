#include "project.h"
#include "envelope_generator.h"

void InitOscillator();

static volatile uint8_t current_mode = NOT_TRIGGERED;
static volatile uint8_t pwm_update_flag = 0;
static volatile uint16_t pwm_value = 0;
static volatile float freq = 0;
static volatile float pulse_width = 0;

CY_ISR(ADC_EOC) {
    pwm_update_flag = 1;
   
    freq = ADC_SAR_Seq_1_GetResult16(0);
    pulse_width = ADC_SAR_Seq_1_GetResult16(1);  
    
    attack_pot_value = ADC_SAR_Seq_1_GetResult16(ATTACK_POT_ADC_CHANNEL);
    decay_pot_value = ADC_SAR_Seq_1_GetResult16(DECAY_POT_ADC_CHANNEL);
    sustain_pot_value = ADC_SAR_Seq_1_GetResult16(SUSTAIN_POT_ADC_CHANNEL);
    release_pot_value = ADC_SAR_Seq_1_GetResult16(RELEASE_POT_ADC_CHANNEL);

    LED_PWM_WriteCompare(pwm_value);
    
    ADC_EOC_INT_ClearPending();
}

CY_ISR(envelope_trigger_vector){
    // led_Write(~led_Read());
    // envelope_triggered = 1;
    
    switch(current_mode){
    case NOT_TRIGGERED:
        current_mode = ATTACK_MODE;
        pwm_value = 0;
        break;
    case SUSTAIN_MODE:
        current_mode = RELEASE_MODE;
        break;
    }
    
    envelope_trigger_ClearPending();
}

CY_ISR(envelope_timer_vect){  
    //led_1_Write(~led_1_Read());
    
    switch(current_mode){
    case NOT_TRIGGERED:
        break;
    case ATTACK_MODE:
        current_mode = DECAY_MODE;
        break;
    case DECAY_MODE:
        current_mode = SUSTAIN_MODE;
        break;
    case SUSTAIN_MODE:
        current_mode = SUSTAIN_MODE;
        break;
    case RELEASE_MODE:
        current_mode = NOT_TRIGGERED;
        break;
    }
    
    ENVELOPE_TIMER_ReadStatus();
    ENVELOPE_TIMER_ClearInterrupt(ENVELOPE_TIMER_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable;
    
    InitOscillator();
    InitEnvelopeGenerator();
    envelope_trigger_StartEx(envelope_trigger_vector);
    
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
    PWM_1_Start();
    LED_PWM_Start();    
    ADC_EOC_INT_StartEx(ADC_EOC);
    ENVELOPE_TIMER_Start();
    ENVELOPE_TIMER_INT_StartEx(envelope_timer_vect);
    
    current_mode = NOT_TRIGGERED;
    
    //led_1_Write(1);

    for(;;)
    {
        if(current_mode == SUSTAIN_MODE){
            led_1_Write(0);
        }
        else{
            led_1_Write(1);
        }
        
        if(pwm_update_flag != 0){ 
            pwm_update_flag = 0;
            PWM_1_WritePeriod((uint16) 65535/freq);
            
            // this is a square wave with 50% duty cycle
            //PWM_1_WriteCompare((uint16) (65535/freq)/2);
            
            // this is pulse width modulation, although the 2000 does not make any sense.
            // wasn't getting good results with 65535/pulse_width?
            // fix this later
            PWM_1_WriteCompare((uint16) (65535/freq)/(2000/pulse_width));
      
            switch(current_mode){
            case NOT_TRIGGERED:
                pwm_value = 0;
                ENVELOPE_TIMER_WriteCounter(0);
                break;
            case ATTACK_MODE:
                ENVELOPE_TIMER_WritePeriod(attack_pot_value);
                ENVELOPE_TIMER_WriteCompare(attack_pot_value);
                pwm_value = (65535 / attack_pot_value) * ENVELOPE_TIMER_ReadCounter();
                break;
            case DECAY_MODE:
                ENVELOPE_TIMER_WritePeriod(decay_pot_value);
                ENVELOPE_TIMER_WriteCompare(decay_pot_value);
                pwm_value = (double)((sustain_pot_value - 65535)/ decay_pot_value) * ENVELOPE_TIMER_ReadCounter() + 65535;
                break;
            case SUSTAIN_MODE:
                ENVELOPE_TIMER_WriteCounter(0);
                ENVELOPE_TIMER_Stop();
                pwm_value = sustain_pot_value;
                break;
            case RELEASE_MODE:
                ENVELOPE_TIMER_Enable();
                ENVELOPE_TIMER_WritePeriod(release_pot_value);
                ENVELOPE_TIMER_WriteCompare(release_pot_value);
                pwm_value = (double)((-sustain_pot_value * ENVELOPE_TIMER_ReadCounter() / release_pot_value)) + sustain_pot_value;
                break;
            }            
        }
    }
}

void InitOscillator(){
    freq_pot_low_Write(0);
    // freq_pot_high_Write(1);
    pulse_width_pot_high_Write(1);
    pulse_width_pot_low_Write(0);
}
/* [] END OF FILE */
