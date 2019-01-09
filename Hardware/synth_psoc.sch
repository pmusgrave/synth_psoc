EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 900  750  650  800 
U 5C3546FC
F0 "Microcontroller" 60
F1 "mcu.sch" 60
F2 "osc1" O R 1550 800 60 
F3 "osc2" O R 1550 900 60 
F4 "osc3" O R 1550 1000 60 
F5 "osc4" O R 1550 1100 60 
F6 "osc5" O R 1550 1200 60 
F7 "osc6" O R 1550 1300 60 
F8 "osc7" O R 1550 1400 60 
F9 "osc8" O R 1550 1500 60 
$EndSheet
$Sheet
S 1950 750  550  800 
U 5C355489
F0 "Filters" 60
F1 "vcf.sch" 60
F2 "osc1" I L 1950 800 60 
F3 "osc2" I L 1950 900 60 
F4 "osc3" I L 1950 1000 60 
F5 "osc4" I L 1950 1100 60 
F6 "osc5" I L 1950 1200 60 
F7 "osc6" I L 1950 1300 60 
F8 "osc7" I L 1950 1400 60 
F9 "osc8" I L 1950 1500 60 
$EndSheet
Wire Wire Line
	1550 800  1950 800 
Wire Wire Line
	1550 900  1950 900 
Wire Wire Line
	1550 1000 1950 1000
Wire Wire Line
	1550 1100 1950 1100
Wire Wire Line
	1550 1200 1950 1200
Wire Wire Line
	1550 1300 1950 1300
Wire Wire Line
	1550 1400 1950 1400
Wire Wire Line
	1550 1500 1950 1500
$EndSCHEMATC