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
Sheet 5 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3250 950  0    60   Input ~ 0
osc1
Text HLabel 950  750  0    60   Input ~ 0
osc2
Text HLabel 950  850  0    60   Input ~ 0
osc3
Text HLabel 950  950  0    60   Input ~ 0
osc4
Text HLabel 950  1050 0    60   Input ~ 0
osc5
Text HLabel 950  1150 0    60   Input ~ 0
osc6
Text HLabel 950  1250 0    60   Input ~ 0
osc7
Text HLabel 950  1350 0    60   Input ~ 0
osc8
$Comp
L Q_PJFET_DSG Q?
U 1 1 5C359797
P 4450 1400
F 0 "Q?" H 4650 1450 50  0000 L CNN
F 1 "MMBFJ177" H 4650 1350 50  0000 L CNN
F 2 "" H 4650 1500 50  0001 C CNN
F 3 "" H 4450 1400 50  0001 C CNN
	1    4450 1400
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C359814
P 4100 950
F 0 "R?" V 4180 950 50  0000 C CNN
F 1 "22k" V 4100 950 50  0000 C CNN
F 2 "" V 4030 950 50  0001 C CNN
F 3 "" H 4100 950 50  0001 C CNN
	1    4100 950 
	0    1    1    0   
$EndComp
$Comp
L TL074 U?
U 1 1 5C359D57
P 5850 1050
F 0 "U?" H 5850 1250 50  0000 L CNN
F 1 "TL074" H 5850 850 50  0000 L CNN
F 2 "" H 5800 1150 50  0001 C CNN
F 3 "" H 5900 1250 50  0001 C CNN
	1    5850 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1050 6300 1050
Wire Wire Line
	6300 1050 6800 1050
Wire Wire Line
	6300 1050 6300 1600
Wire Wire Line
	6300 1600 5400 1600
Wire Wire Line
	5400 1600 5400 1150
Wire Wire Line
	5400 1150 5550 1150
$Comp
L GNDA #PWR?
U 1 1 5C359DD5
P 4550 1600
F 0 "#PWR?" H 4550 1350 50  0001 C CNN
F 1 "GNDA" H 4550 1450 50  0000 C CNN
F 2 "" H 4550 1600 50  0001 C CNN
F 3 "" H 4550 1600 50  0001 C CNN
	1    4550 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 950  4550 950 
Wire Wire Line
	4550 950  5550 950 
Wire Wire Line
	3950 950  3250 950 
Wire Wire Line
	4550 1200 4550 950 
$Comp
L R R?
U 1 1 5C359EAD
P 4000 1400
F 0 "R?" V 4080 1400 50  0000 C CNN
F 1 "1MEG" V 4000 1400 50  0000 C CNN
F 2 "" V 3930 1400 50  0001 C CNN
F 3 "" H 4000 1400 50  0001 C CNN
	1    4000 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 1400 4250 1400
Connection ~ 4550 950 
Text HLabel 3250 1300 0    60   Input ~ 0
lfo1
Text HLabel 3250 1500 0    60   Input ~ 0
adsr1
$Comp
L SW_DPDT_x2 SW?
U 1 1 5C35A0BC
P 3650 1400
F 0 "SW?" H 3650 1570 50  0000 C CNN
F 1 "SW_DPDT_x2" H 3650 1200 50  0000 C CNN
F 2 "" H 3650 1400 50  0001 C CNN
F 3 "" H 3650 1400 50  0001 C CNN
	1    3650 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3250 1300 3450 1300
Wire Wire Line
	3250 1500 3450 1500
Text HLabel 6800 1050 2    60   Output ~ 0
env_out_1
Connection ~ 6300 1050
$EndSCHEMATC
