// references Cypress USB MIDI code example
#ifndef USB_MIDI_H
#define USB_MIDI_H
#include "project.h"

/* Need for Identity Reply message */
extern volatile uint8 USB_MIDI1_InqFlags;
extern volatile uint8 USB_MIDI2_InqFlags;
extern uint8 inqFlagsOld;

void USBMIDI_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg) CYREENTRANT;
void ServiceUSB(void);

#endif
/* [] END OF FILE */
