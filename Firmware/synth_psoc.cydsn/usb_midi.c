// references Cypress USB MIDI code example
#include "usb_midi.h"

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
    
void ServiceUSB(){
    // Handle USB enumeration

    /* Host can send double SET_INTERFACE request */
    if(0u != USBMIDI_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device configured */
        if(0u != USBMIDI_GetConfiguration())   
        {
        	/* Enable output endpoint */
            USBMIDI_MIDI_Init();
        }
        else
        {
            // SleepTimer_Stop();
        }    
    }        
    
    /* Service USB MIDI when device is configured */
    if(0u != USBMIDI_GetConfiguration())    
    {
        /* Call this API from UART RX ISR for Auto DMA mode */
        #if(!USB_EP_MANAGEMENT_DMA_AUTO) 
            USBMIDI_MIDI_IN_Service();
        #endif
        /* In Manual EP Memory Management mode OUT_EP_Service() 
        *  may have to be called from main foreground or from OUT EP ISR
        */
        #if(!USB_EP_MANAGEMENT_DMA_AUTO) 
            USBMIDI_MIDI_OUT_Service();
        #endif

        /* Sending Identity Reply Universal System Exclusive message 
         * back to computer */
        if(0u != (USB_MIDI1_InqFlags & USBMIDI_INQ_IDENTITY_REQ_FLAG))
        {
            USBMIDI_PutUsbMidiIn(sizeof(MIDI_IDENTITY_REPLY), \
                        (uint8 *)MIDI_IDENTITY_REPLY, USBMIDI_MIDI_CABLE_00);
            USB_MIDI1_InqFlags &= ~USBMIDI_INQ_IDENTITY_REQ_FLAG;
        }
        #if (USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF)
            if(0u != (USB_MIDI2_InqFlags & USBMIDI_INQ_IDENTITY_REQ_FLAG))
            {
                USBMIDI_PutUsbMidiIn(sizeof(MIDI_IDENTITY_REPLY), \
                        (uint8 *)MIDI_IDENTITY_REPLY, USBMIDI_MIDI_CABLE_01);
                USB_MIDI2_InqFlags &= ~USBMIDI_INQ_IDENTITY_REQ_FLAG;
            }
        #endif /* End USB_MIDI_EXT_MODE >= USB_TWO_EXT_INTRF */
    }
}

/*******************************************************************************
* Function Name: USB_callbackLocalMidiEvent
********************************************************************************
* Summary: Local processing of the USB MIDI out-events.
*
*******************************************************************************/
void USBMIDI_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg) CYREENTRANT
{
    /* Support General System On/Off Message. */
    if((0u == (USB_MIDI1_InqFlags & USBMIDI_INQ_SYSEX_FLAG)) \
            && (0u != (inqFlagsOld & USBMIDI_INQ_SYSEX_FLAG)))
    {
        if(midiMsg[USBMIDI_EVENT_BYTE0] == USBMIDI_MIDI_SYSEX_GEN_MESSAGE)
        {
            if(midiMsg[USBMIDI_EVENT_BYTE1] == USBMIDI_MIDI_SYSEX_SYSTEM_ON)
            {
                // MIDI_PWR_Write(0u); /* Power ON */
            }
            else if(midiMsg[USBMIDI_EVENT_BYTE1] == USBMIDI_MIDI_SYSEX_SYSTEM_OFF)
            {
                // MIDI_PWR_Write(1u); /* Power OFF */
            }
        }
    }
    inqFlagsOld = USB_MIDI1_InqFlags;
    cable = cable;
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
    // LED_OutA_Write(1);
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
    // LED_OutA_Write(0);
}


/*******************************************************************************
* Function Name: USB_MIDI2_ProcessUsbOut_EntryCallback
********************************************************************************
* Summary:  Turn the LED_OutB on at the beginning of the function  
* USB_MIDI2_ProcessUsbOut() when data comes to be put in the UART2 out- 
* buffer  
* 
*******************************************************************************/
void USB_MIDI2_ProcessUsbOut_EntryCallback(void)
{
    // LED_OutB_Write(1);
}


/*******************************************************************************
* Function Name: USB_MIDI2_ProcessUsbOut_ExitCallback
********************************************************************************
* Summary:  Turn the LED_OutB off at the end of the function  
* USB_MIDI2_ProcessUsbOut() when data is put in the UART2 out-buffer.
* 
*******************************************************************************/
void USB_MIDI2_ProcessUsbOut_ExitCallback(void)
{
    // LED_OutB_Write(0);
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
    // LED_InA_Write(1);
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
    
    // LED_InA_Write(0);
}


/*******************************************************************************
* Function Name: MIDI2_UART_RXISR_EntryCallback
********************************************************************************
* Summary:  Turn the LED_InB on at the beginning of the MIDI2_UART_RXISR ISR  
* when data comes to UART2 to be put in the USBFS_MIDI IN endpoint  
* buffer.
*
*******************************************************************************/
void MIDI2_UART_RXISR_EntryCallback(void)
{
    /* These LEDs indicate MIDI input activity */
    // LED_InB_Write(1);
}


/*******************************************************************************
* Function Name: MIDI2_UART_RXISR_ExitCallback
********************************************************************************
* Summary:  Turn the LED_InB off at the end of the MIDI2_UART_RXISR ISR  
* when data is put in the USBFS_MIDI IN endpoint buffer
*
*******************************************************************************/
void MIDI2_UART_RXISR_ExitCallback(void)
{
    #if (USB_EP_MANAGEMENT_DMA_AUTO) 
        USB_MIDI_IN_Service();
    #endif /* (USB_EP_MANAGEMENT_DMA_AUTO) */
    
    // LED_InB_Write(0);
}


/* [] END OF FILE */
