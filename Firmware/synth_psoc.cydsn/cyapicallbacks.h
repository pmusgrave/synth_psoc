/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef CYAPICALLBACKS_H
#define CYAPICALLBACKS_H
    
#define USB_MIDI1_PROCESS_USB_OUT_ENTRY_CALLBACK
void USB_MIDI1_ProcessUsbOut_EntryCallback(void);

#define USB_MIDI1_PROCESS_USB_OUT_EXIT_CALLBACK
void USB_MIDI1_ProcessUsbOut_ExitCallback(void);

#define MIDI1_UART_RXISR_ENTRY_CALLBACK
void MIDI1_UART_RXISR_EntryCallback(void);

#define MIDI1_UART_RXISR_EXIT_CALLBACK
void MIDI1_UART_RXISR_ExitCallback(void);
    
#endif /* CYAPICALLBACKS_H */   
/* [] */
