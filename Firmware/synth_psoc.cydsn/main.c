#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "oscillator.h"
#include "buttons.h"
#include "usb_midi.h"

#define FREQ_0_ADC_CHAN 0
#define PW_0_ADC_CHAN 1
#define FREQ_1_ADC_CHAN 2
#define PW_1_ADC_CHAN 3
#define FREQ_2_ADC_CHAN 4
#define PW_2_ADC_CHAN 5
#define FREQ_3_ADC_CHAN 6
#define PW_3_ADC_CHAN 7
#define ENV_MUX_ADC_CHAN 8

#define ENVELOPE_MAX_PERIOD 2048

volatile uint8_t adc_update_flag = 0;
volatile uint8_t MIDI_RX_flag = 0;
uint8_t MIDI_in_buf = 0;
float env0_pwm = 0;
float env1_pwm = 0;
float env2_pwm = 0;
float env3_pwm = 0;
volatile float freq_0 = 0;
volatile float pulse_width_0 = 0;
volatile float freq_1 = 0;
volatile float pulse_width_1 = 0;
volatile float freq_2 = 0;
volatile float pulse_width_2 = 0;
volatile float freq_3 = 0;
volatile float pulse_width_3 = 0;

float env0_speed = 0;
float env1_speed = 0;
float env2_speed = 0;
float env3_speed = 0;

/* Need for Identity Reply message */
volatile uint8 USB_MIDI1_InqFlags;
volatile uint8 USB_MIDI2_InqFlags;
uint8 inqFlagsOld = 0u;

void UpdateADCValues(uint8_t *AMux_ADC);
void UpdateEnvelope(struct envelope *envelope, struct button *button);

volatile float pwm = 0;

int main(void)
{
    CyGlobalIntEnable;

    // Start all ADC components
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    ADC_EOC_INT_StartEx(ADC_EOC);
    CyDelayUs(10);
    
    // Init main oscillator PWM components
    EnableAllOscillators();
    
    // Init interrupts to change PWM values on overflow
    osc_0_ovf_StartEx(OSC_0_OVF_VECT);
    osc_1_ovf_StartEx(OSC_1_OVF_VECT);
    osc_2_ovf_StartEx(OSC_2_OVF_VECT);
    osc_3_ovf_StartEx(OSC_3_OVF_VECT);
    
    // Init envelope components and PWM interrupts
    envelope_PWM_0_Start();
    envelope_PWM_1_Start();
    envelope_PWM_2_Start();
    envelope_PWM_3_Start();
    
    envelope_0_ovf_StartEx(ENV_0_OVF_VECT);
    envelope_1_ovf_StartEx(ENV_1_OVF_VECT);
    envelope_2_ovf_StartEx(ENV_2_OVF_VECT);
    envelope_3_ovf_StartEx(ENV_3_OVF_VECT);
    
    AMux_Start();
    AMux_Init();
    Opamp_Start();
    uint8_t AMux_ADC_counter = 0;
    
    // Init Capsense
    CapSense_Buttons_Start();	
	CapSense_Buttons_InitializeAllBaselines();
    CapSense_Buttons_ScanEnabledWidgets();
    
    struct envelope Osc_0_Envelope = {&env0_speed, &env0_pwm};
    struct envelope Osc_1_Envelope = {&env1_speed, &env1_pwm};
    struct envelope Osc_2_Envelope = {&env2_speed, &env2_pwm};
    struct envelope Osc_3_Envelope = {&env3_speed, &env3_pwm};
    
    struct button Osc_0_Button = {&osc_0_hold_Read, &osc_0_repeat_Read, 0, CapSense_Buttons_BUTTON0__BTN, &main_osc_PWM_0_Start, &main_osc_PWM_0_Stop};
    struct button Osc_1_Button = {&osc_1_hold_Read, &osc_1_repeat_Read, 0, CapSense_Buttons_BUTTON1__BTN, &main_osc_PWM_1_Start, &main_osc_PWM_1_Stop};
    struct button Osc_2_Button = {&osc_2_hold_Read, &osc_2_repeat_Read, 0, CapSense_Buttons_BUTTON2__BTN, &main_osc_PWM_2_Start, &main_osc_PWM_2_Stop};
    struct button Osc_3_Button = {&osc_3_hold_Read, &osc_3_repeat_Read, 0, CapSense_Buttons_BUTTON3__BTN, &main_osc_PWM_3_Start, &main_osc_PWM_3_Stop};

    // Init USB and MIDI
    // references Cypress USB MIDI code example
    USBMIDI_Start(0u, USBMIDI_5V_OPERATION);
    MIDI_UART_Start();
    MIDI_RX_StartEx(MIDI_RX_VECT);
    
    while(1){
        if(adc_update_flag != 0) { 
            adc_update_flag = 0;
            UpdateADCValues(&AMux_ADC_counter);
        }

        UpdateEnvelope(&Osc_0_Envelope, &Osc_0_Button);
        UpdateEnvelope(&Osc_1_Envelope, &Osc_1_Button);
        UpdateEnvelope(&Osc_2_Envelope, &Osc_2_Button);
        UpdateEnvelope(&Osc_3_Envelope, &Osc_3_Button);
        //pwm = pwm + 0.1;
        //envelope_PWM_0_WriteCompare((uint16_t) pwm);
       
        // scan all CapSense buttons sequentially,
        // and start oscillator if button is pressed
        if(!CapSense_Buttons_IsBusy()) {
            CapSense_Buttons_UpdateEnabledBaselines();
            
            HandleButton(&Osc_0_Button);
            HandleButton(&Osc_1_Button);
            HandleButton(&Osc_2_Button);
            HandleButton(&Osc_3_Button);
            
            CapSense_Buttons_ScanEnabledWidgets();
        }
        
        /*
        if(MIDI_RX_flag) {
            MIDI_RX_flag = 0;
            MIDI_in_buf = MIDI_UART_ReadRxData();
            if(MIDI_in_buf == 0x90){
                Osc_0_Button.note_triggered = 1;
            }
            if(MIDI_in_buf == 0x80){
                Osc_0_Button.note_triggered = 0;
            }
        }
        */

        // Handle USB enumeration
        //ServiceUSB();
    }
}

void UpdateADCValues(uint8_t *AMux_ADC){
    freq_0 = ADC_SAR_Seq_GetResult16(FREQ_0_ADC_CHAN);
    if(osc_0_quant_Read() == 1){
        freq_0 = Quantize(freq_0);
    }
    pulse_width_0 = ADC_SAR_Seq_GetResult16(PW_0_ADC_CHAN); 
    
    freq_1 = ADC_SAR_Seq_GetResult16(FREQ_1_ADC_CHAN);
    if(osc_1_quant_Read()){
        freq_1 = Quantize(freq_1);
    }
    pulse_width_1 = ADC_SAR_Seq_GetResult16(PW_1_ADC_CHAN);
    
    freq_2 = ADC_SAR_Seq_GetResult16(FREQ_2_ADC_CHAN);
    if(osc_2_quant_Read()){
        freq_2 = Quantize(freq_2);
    }
    pulse_width_2 = ADC_SAR_Seq_GetResult16(PW_2_ADC_CHAN);  
    
    freq_3 = ADC_SAR_Seq_GetResult16(FREQ_3_ADC_CHAN);
    if(osc_3_quant_Read()){
        freq_3 = Quantize(freq_3);
    }
    pulse_width_3 = ADC_SAR_Seq_GetResult16(PW_3_ADC_CHAN); 

    
    // envelope
    AMux_Select(*AMux_ADC);
    CyDelayUs(1000);
    switch(*AMux_ADC){
    case 0:
        env0_speed = ADC_SAR_Seq_GetResult16(ENV_MUX_ADC_CHAN);
    case 1:
        env1_speed = ADC_SAR_Seq_GetResult16(ENV_MUX_ADC_CHAN);
    case 2:
        env2_speed = ADC_SAR_Seq_GetResult16(ENV_MUX_ADC_CHAN);
    case 3:
        env3_speed = ADC_SAR_Seq_GetResult16(ENV_MUX_ADC_CHAN);
    }
    (*AMux_ADC) += 1;
    if (*AMux_ADC == 4){
        *AMux_ADC = 0;
    }
    CyDelayUs(1000);
}

void UpdateEnvelope(struct envelope *envelope, struct button *button){
    if(*(*envelope).env_speed < 50){
        //(*button).note_triggered = 1;
        *(*envelope).env_speed = 50;
    }
    if((*button).note_triggered == 1){
        *(*envelope).env_pwm = *(*envelope).env_pwm + *(*envelope).env_speed * 0.002;
        if(!(*button).repeat_check_function() || (*button).hold_check_function()){
            if (*(*envelope).env_pwm > 65000) {
                *(*envelope).env_pwm  = 65000;
            }
        }
    }
   else {
        if(*(*envelope).env_pwm > 0.5){
            *(*envelope).env_pwm = *(*envelope).env_pwm - *(*envelope).env_speed * 0.002;
        }
        if (*(*envelope).env_pwm < 0.5){
            (*button).osc_disable_function();
        }
    }
}
/* [] END OF FILE */