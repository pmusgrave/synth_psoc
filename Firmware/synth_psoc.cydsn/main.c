#include "project.h"
#include "interrupts.h"
#include "globals.h"
#include "oscillator.h"
#include "buttons.h"

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

volatile float pwm = 0;

struct button Osc_0_Button = {&osc_0_hold_Read, &osc_0_repeat_Read, 0, CapSense_Buttons_BUTTON0__BTN, &main_osc_PWM_0_Start, &main_osc_PWM_0_Stop};
struct button Osc_1_Button = {&osc_1_hold_Read, &osc_1_repeat_Read, 0, CapSense_Buttons_BUTTON1__BTN, &main_osc_PWM_1_Start, &main_osc_PWM_1_Stop};
struct button Osc_2_Button = {&osc_2_hold_Read, &osc_2_repeat_Read, 0, CapSense_Buttons_BUTTON2__BTN, &main_osc_PWM_2_Start, &main_osc_PWM_2_Stop};
struct button Osc_3_Button = {&osc_3_hold_Read, &osc_3_repeat_Read, 0, CapSense_Buttons_BUTTON3__BTN, &main_osc_PWM_3_Start, &main_osc_PWM_3_Stop};

    
/*******************************************************************************
* USB and MIDI stuff
*******************************************************************************/
#define DEVICE                  (0u)
#define MIDI_MSG_SIZE           (4u)

/*MIDI Message Fields */
#define MIDI_MSG_TYPE           (0u)
#define MIDI_NOTE_NUMBER        (1u)
#define MIDI_NOTE_VELOCITY      (2u)

/* MIDI Notes*/
#define NOTE_72                 (72u)
#define NOTE_76                 (76u)

/* MIDI Notes Velocity*/
#define VOLUME_OFF              (0u)
#define VOLUME_ON               (100u)

#define USB_SUSPEND_TIMEOUT     (2u)

/* Identity Reply message */
const uint8 CYCODE MIDI_IDENTITY_REPLY[] = {
    0xF0u,      /* SysEx */
    0x7Eu,      /* Non-real time */
    0x7Fu,      /* ID of target device (7F - "All Call") */
    0x06u,      /* Sub-ID#1 - General Information */
    0x02u,      /* Sub-ID#2 - Identity Reply */
    0x7Du,      /* Manufacturer's ID: 7D - Educational Use */
    0xB4u, 0x04u,               /* Family code */
    0x32u, 0xD2u,               /* Model number */
    0x01u, 0x00u, 0x00u, 0x00u, /* Version number */
    /*0xF7         End of SysEx automatically appended */
};

/* Need for Identity Reply message */
volatile uint8 USB_MIDI1_InqFlags;

volatile uint8 usbActivityCounter = 0u;

uint8 inqFlagsOld = 0u;

uint8 midiMsg[MIDI_MSG_SIZE];   
char buff[32];//output UART buffer

volatile uint8_t MIDI_RX_flag = 0;


/*******************************************************************************
* Function Prototypes
*******************************************************************************/

void UpdateADCValues(uint8_t *AMux_ADC);
void UpdateEnvelope(struct envelope *envelope, struct button *button);

/******************************************************************************/

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
    
    // Init USB and MIDI
    // references Cypress USB MIDI code example
    /* Start USBFS device 0 with VDDD operation */
    USB_Start(DEVICE, USB_DWR_VDDD_OPERATION); 
    //MIDI1_UART_Start();
    //MIDI_RX_StartEx(MIDI_RX_VECT);
    
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
        
        /*******************************************************************************
        * USB AND MIDI STUFF
        * references Cypress USB MIDI code examples
        *******************************************************************************/
        if(0u != USB_IsConfigurationChanged()){
            if(0u != USB_GetConfiguration())   // Initialize IN endpoints when device configured
            {
                USB_MIDI_Init(); // Enable output endpoint
            }
        }            
        
        /* Service USB MIDI when device is configured */
        if(0u != USB_GetConfiguration())    
        {
            /* Call this API from UART RX ISR for Auto DMA mode */
            #if(!USB_EP_MANAGEMENT_DMA_AUTO) 
                USB_MIDI_IN_Service();
            #endif
            /* In Manual EP Memory Management mode OUT_EP_Service() 
            *  may have to be called from main foreground or from OUT EP ISR
            */
            #if(!USB_EP_MANAGEMENT_DMA_AUTO) 
                USB_MIDI_OUT_Service();
            #endif

            /* Sending Identity Reply Universal System Exclusive message 
             * back to computer */
            if(0u != (USB_MIDI1_InqFlags & USB_INQ_IDENTITY_REQ_FLAG))
            {
                USB_PutUsbMidiIn(sizeof(MIDI_IDENTITY_REPLY), (uint8 *)MIDI_IDENTITY_REPLY, USB_MIDI_CABLE_00);
                USB_MIDI1_InqFlags &= ~USB_INQ_IDENTITY_REQ_FLAG;
            }
        }

        /******************************************************************************/
        
        /*
        if(MIDI_RX_flag) {
            MIDI_RX_flag = 0;
            midiMsg[0] = MIDI1_UART_ReadRxData();
            if(midiMsg[0] == 0x90){
                Osc_0_Button.note_triggered = 1;
            }
            if(midiMsg[0] == 0x80){
                Osc_0_Button.note_triggered = 0;
            }
        }
        */
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
    CyDelayUs(10);
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
    CyDelayUs(10);
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



/*******************************************************************************
* Function Name: USB_callbackLocalMidiEvent
********************************************************************************
* Summary: Local processing of the USB MIDI out-events.
* References: Cypress code examples, 
* and https://community.cypress.com/message/144752#144752
*******************************************************************************/
void USB_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg) CYREENTRANT
{
    uint8_t note;
    
    /* Support General System On/Off Message. */
    if((0u == (USB_MIDI1_InqFlags & USB_INQ_SYSEX_FLAG)) \
            && (0u != (inqFlagsOld & USB_INQ_SYSEX_FLAG)))
    {
        if(midiMsg[USB_EVENT_BYTE0] == USB_MIDI_SYSEX_GEN_MESSAGE)
        {
            if(midiMsg[USB_EVENT_BYTE1] == USB_MIDI_SYSEX_SYSTEM_ON)
            {
                //MIDI_PWR_Write(0u); /* Power ON */
            }
            else if(midiMsg[USB_EVENT_BYTE1] == USB_MIDI_SYSEX_SYSTEM_OFF)
            {
                //MIDI_PWR_Write(1u); /* Power OFF */
            }
        }
    }
    inqFlagsOld = USB_MIDI1_InqFlags;
    cable = cable;
    
    // note command received
    if (midiMsg[USB_EVENT_BYTE0] == USB_MIDI_NOTE_ON)
    {
        note = midiMsg[USB_EVENT_BYTE1];
        //index = note - 0x30;        // index in array
        //notes[index].on = 1;        // note enablesnotes[index]
        //notes[index].acc = 0;       // reset DDS accumulator (not necessary?)
        //notes[index].env_acc = 0;   // reset envelope acc
        //notecount++; if (notecount>0) isrDrq_Enable();
        
        Osc_0_Button.note_triggered = 1;
        Osc_1_Button.note_triggered = 1;
        Osc_2_Button.note_triggered = 1;
        Osc_3_Button.note_triggered = 1;
    }
    else if (midiMsg[USB_EVENT_BYTE0] == USB_MIDI_NOTE_OFF)
    {
        note = midiMsg[USB_EVENT_BYTE1];
        //index = note - 0x30;        // index in array 
        //notes[index].on = 0;        // note off
        //notecount--; if (notecount==0) isrDrq_Disable();
        
        // can test CPU clocks spent in isr using StopWatch component // debug only
        //sprintf(buff, "\r\n%lu ", StopWatch_Cycles);
        MIDI1_UART_PutString(buff);
        
        Osc_0_Button.note_triggered = 0;
        Osc_1_Button.note_triggered = 0;
        Osc_2_Button.note_triggered = 0;
        Osc_3_Button.note_triggered = 0;
    }
}    


/*******************************************************************************
* Function Name: USB_MIDI1_ProcessUsbOut_EntryCallback
********************************************************************************
* Summary:  Turn the LED_OutA on at the beginning of the function
* USB_MIDI1_ProcessUsbOut() when data comes to be put in the UART1 out
* buffer.
* 
*******************************************************************************/
void USB_MIDI1_ProcessUsbOut_EntryCallback(void)
{
    //LED_OutA_Write(1);
}


/*******************************************************************************
* Function Name: USB_MIDI1_ProcessUsbOut_ExitCallback
********************************************************************************
* Summary:  Turn the LED_OutA off at the end of the function  
* USB_MIDI1_ProcessUsbOut() when data is put in the UART1 out-buffer.
* 
*******************************************************************************/
void USB_MIDI1_ProcessUsbOut_ExitCallback(void)
{
    //LED_OutA_Write(0);
}

/*******************************************************************************
* Function Name: MIDI1_UART_RXISR_EntryCallback
********************************************************************************
* Summary:  Turn the LED_InA on at the beginning of the MIDI1_UART_RXISR ISR  
* when data comes to UART1 to be put in the USBFS_MIDI IN endpoint
* buffer.
*
*******************************************************************************/
void MIDI1_UART_RXISR_EntryCallback(void)
{
    /* These LEDs indicate MIDI input activity */
    //LED_InA_Write(1);
}


/*******************************************************************************
* Function Name: MIDI1_UART_RXISR_ExitCallback
********************************************************************************
* Summary:  Turn the LED_InA off at the end of the MIDI1_UART_RXISR ISR  
* when data is put in the USBFS_MIDI IN endpoint buffer.
*
*******************************************************************************/
void MIDI1_UART_RXISR_ExitCallback(void)
{
    #if (USB_EP_MANAGEMENT_DMA_AUTO) 
        USB_MIDI_IN_Service();
    #endif /* (USB_EP_MANAGEMENT_DMA_AUTO) */
    
    //LED_InA_Write(0);
    main_osc_PWM_0_WritePeriod((uint16_t) 65535/10000);
    main_osc_PWM_0_WriteCompare((uint16_t) (65535/10000)/(2000/pulse_width_0));
}

/* [] END OF FILE */