// references Cypress USB MIDI code example
#include "project.h"

/* Need for Identity Reply message */
extern volatile uint8 USB_MIDI1_InqFlags;
extern volatile uint8 USB_MIDI2_InqFlags;
extern uint8 inqFlagsOld;

void USBMIDI_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg) CYREENTRANT;

/* [] END OF FILE */
