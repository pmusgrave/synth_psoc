#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "oscillator.h"
#include "buttons.h"
#include "usb_midi.h"

#define ENVELOPE_MAX_PERIOD 2048

#define FREQ_0_ADC_CHAN 0
#define PW_0_ADC_CHAN 1
#define FREQ_1_ADC_CHAN 2
#define PW_1_ADC_CHAN 3
#define FREQ_2_ADC_CHAN 4
#define PW_2_ADC_CHAN 5
#define FREQ_3_ADC_CHAN 6
#define PW_3_ADC_CHAN 7

volatile uint8_t adc_update_flag = 0;
volatile float env0_pwm = 0;
volatile float env1_pwm = 0;
volatile float env2_pwm = 0;
volatile float env3_pwm = 0;
volatile float freq_0 = 0;
volatile float pulse_width_0 = 0;
volatile float freq_1 = 0;
volatile float pulse_width_1 = 0;
volatile float freq_2 = 0;
volatile float pulse_width_2 = 0;
volatile float freq_3 = 0;
volatile float pulse_width_3 = 0;

/* Need for Identity Reply message */
volatile uint8 USB_MIDI1_InqFlags;
volatile uint8 USB_MIDI2_InqFlags;
uint8 inqFlagsOld = 0u;

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
    
    // Init Capsense
    CapSense_Buttons_Start();	
	CapSense_Buttons_InitializeAllBaselines();
    CapSense_Buttons_ScanEnabledWidgets();
        
    struct button Osc_0_Button = {&osc_0_hold_Read, 0, CapSense_Buttons_BUTTON0__BTN, &main_osc_PWM_0_Start, &main_osc_PWM_0_Stop};
    struct button Osc_1_Button = {&osc_1_hold_Read, 0, CapSense_Buttons_BUTTON1__BTN, &main_osc_PWM_1_Start, &main_osc_PWM_1_Stop};
    struct button Osc_2_Button = {&osc_2_hold_Read, 0, CapSense_Buttons_BUTTON2__BTN, &main_osc_PWM_2_Start, &main_osc_PWM_2_Stop};
    struct button Osc_3_Button = {&osc_3_hold_Read, 0, CapSense_Buttons_BUTTON3__BTN, &main_osc_PWM_3_Start, &main_osc_PWM_3_Stop};

    float env0_speed = 0;
    float env1_speed = 0;
    float env2_speed = 0;
    float env3_speed = 0;
    
    
    // Init USB and MIDI
    // references Cypress USB MIDI code example
    USBMIDI_Start(0u, USBMIDI_5V_OPERATION);
    MIDI_UART_Start();
    
    while(1){
        // update all ADC values when the end of conversion interrupt triggers
        if(adc_update_flag != 0) { 
            adc_update_flag = 0;
               
            freq_0 = ADC_SAR_Seq_GetResult16(FREQ_0_ADC_CHAN);
            if(osc_0_quant_Read() == 1){
                freq_0 = Quantize(freq_0);
            }
            pulse_width_0 = ADC_SAR_Seq_GetResult16(PW_0_ADC_CHAN); 
            // envelope
            AMux_Select(0);
            CyDelayUs(100);
            env0_speed = ADC_SAR_Seq_GetResult16(8);
            
            freq_1 = ADC_SAR_Seq_GetResult16(FREQ_1_ADC_CHAN);
            if(osc_1_quant_Read()){
                freq_1 = Quantize(freq_1);
            }
            pulse_width_1 = ADC_SAR_Seq_GetResult16(PW_1_ADC_CHAN);
            // envelope
            AMux_Select(1);
            CyDelayUs(100);
            env1_speed = ADC_SAR_Seq_GetResult16(8);
            
            freq_2 = ADC_SAR_Seq_GetResult16(FREQ_2_ADC_CHAN);
            if(osc_2_quant_Read()){
                freq_2 = Quantize(freq_2);
            }
            pulse_width_2 = ADC_SAR_Seq_GetResult16(PW_2_ADC_CHAN);  
            // envelope
            AMux_Select(2);
            CyDelayUs(100);
            env2_speed = ADC_SAR_Seq_GetResult16(8);
            
            freq_3 = ADC_SAR_Seq_GetResult16(FREQ_3_ADC_CHAN);
            if(osc_3_quant_Read()){
                freq_3 = Quantize(freq_3);
            }
            pulse_width_3 = ADC_SAR_Seq_GetResult16(PW_3_ADC_CHAN); 
            // envelope
            AMux_Select(3);
            CyDelayUs(100);
            env3_speed = ADC_SAR_Seq_GetResult16(8);
        }

        if(env0_speed < 50){
            Osc_0_Button.note_triggered = 1;
        }
        if(Osc_0_Button.note_triggered == 1){
            env0_pwm = env0_pwm + (env0_speed * 0.002);
            if(!osc_0_repeat_Read() || osc_0_hold_Read()){
                if (env0_pwm > 65000) {
                    env0_pwm  = 65000;
                }
            }
        }
        else {
            if(env0_pwm > 0.1){
                env0_pwm = env0_pwm - (env0_speed * 0.002);
            }
            if (env0_pwm < 0.5){
                main_osc_PWM_0_Stop();
            }
        }
        
        if(env1_speed < 50){
            Osc_1_Button.note_triggered = 1;
        }
        if(Osc_1_Button.note_triggered == 1){
            env1_pwm = env1_pwm + (env1_speed * 0.002);
            if (env1_pwm > 65000) {
                env1_pwm  = 65000;
            }
        }
        else{
            if(env1_pwm > 0.1){
                env1_pwm = env1_pwm - (env1_speed * 0.002);
            }
            if (env1_pwm < 0.5){
                main_osc_PWM_1_Stop();
            }
        }
        
        if(env2_speed < 50){
            Osc_2_Button.note_triggered = 1;
        }
        if(Osc_2_Button.note_triggered == 1){
            env2_pwm = env2_pwm + (env2_speed * 0.02);
            if (env2_pwm > 65000) {
                env2_pwm  = 65000;
            }
        }
        else{
            if(env2_pwm > 0){
                env2_pwm = env2_pwm - (env2_speed * 0.02);
            }
            if (env2_pwm < 0.5){
                main_osc_PWM_2_Stop();
            }
        }
        
        if(env3_speed < 50){
            Osc_3_Button.note_triggered = 1;
        }
        if(Osc_3_Button.note_triggered == 1){
            env3_pwm = env3_pwm + (env3_speed * 0.02);
            if (env3_pwm > 65000) {
                env3_pwm  = 65000;
            }
        }
        else{
            if(env3_pwm > 0){
                env3_pwm = env3_pwm - (env3_speed * 0.02);
            }
            if (env3_pwm < 0.5){
                main_osc_PWM_3_Stop();
            }
        }
       
        
        
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
            
            
            
        // Handle USB enumeration and scan for MIDI messages
        ServiceUSB();
        
    }
}

/* [] END OF FILE */