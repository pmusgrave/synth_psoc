// references Cypress USB MIDI code example
#include "usb_midi.h"

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
