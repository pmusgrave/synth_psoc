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
LIBS:synth_psoc-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 2N3904 Q?
U 1 1 5C367DF2
P 5150 1650
F 0 "Q?" H 5350 1725 50  0000 L CNN
F 1 "2N3904" H 5350 1650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 5350 1575 50  0001 L CIN
F 3 "" H 5150 1650 50  0001 L CNN
	1    5150 1650
	1    0    0    -1  
$EndComp
Text Label 4750 1500 0    60   ~ 0
bias
$Comp
L R R?
U 1 1 5C367F46
P 5250 1150
F 0 "R?" V 5330 1150 50  0000 C CNN
F 1 "10k" V 5250 1150 50  0000 C CNN
F 2 "" V 5180 1150 50  0001 C CNN
F 3 "" H 5250 1150 50  0001 C CNN
	1    5250 1150
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C367FA3
P 5250 2150
F 0 "R?" V 5330 2150 50  0000 C CNN
F 1 "10k" V 5250 2150 50  0000 C CNN
F 2 "" V 5180 2150 50  0001 C CNN
F 3 "" H 5250 2150 50  0001 C CNN
	1    5250 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5C367FDF
P 5250 2350
F 0 "#PWR?" H 5250 2100 50  0001 C CNN
F 1 "GND" H 5250 2200 50  0000 C CNN
F 2 "" H 5250 2350 50  0001 C CNN
F 3 "" H 5250 2350 50  0001 C CNN
	1    5250 2350
	1    0    0    -1  
$EndComp
$Comp
L +15V #PWR?
U 1 1 5C368017
P 5250 950
F 0 "#PWR?" H 5250 800 50  0001 C CNN
F 1 "+15V" H 5250 1090 50  0000 C CNN
F 2 "" H 5250 950 50  0001 C CNN
F 3 "" H 5250 950 50  0001 C CNN
	1    5250 950 
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5C368040
P 5700 1500
F 0 "C?" H 5710 1570 50  0000 L CNN
F 1 "33nF" H 5710 1420 50  0000 L CNN
F 2 "" H 5700 1500 50  0001 C CNN
F 3 "" H 5700 1500 50  0001 C CNN
	1    5700 1500
	1    0    0    -1  
$EndComp
$Comp
L POT RV?
U 1 1 5C368098
P 5700 1800
F 0 "RV?" V 5525 1800 50  0000 C CNN
F 1 "10k" V 5600 1800 50  0000 C CNN
F 2 "" H 5700 1800 50  0001 C CNN
F 3 "" H 5700 1800 50  0001 C CNN
	1    5700 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1650 4950 1650
Wire Wire Line
	5250 2350 5250 2300
Wire Wire Line
	5250 1850 5250 2000
Wire Wire Line
	5250 1300 5250 1450
Wire Wire Line
	5250 950  5250 1000
Wire Wire Line
	5700 1400 5700 1350
Wire Wire Line
	5700 1350 5250 1350
Connection ~ 5250 1350
Wire Wire Line
	5700 1650 5700 1600
Wire Wire Line
	5850 1800 5850 1600
Wire Wire Line
	5700 1600 6250 1600
Wire Wire Line
	5700 1950 5250 1950
Connection ~ 5250 1950
Connection ~ 5850 1600
Wire Wire Line
	4750 1500 4750 1650
Connection ~ 4750 1650
$Comp
L CP1_Small C?
U 1 1 5C36835D
P 4500 1650
F 0 "C?" H 4510 1720 50  0000 L CNN
F 1 "220uF" H 4510 1570 50  0000 L CNN
F 2 "" H 4500 1650 50  0001 C CNN
F 3 "" H 4500 1650 50  0001 C CNN
	1    4500 1650
	0    1    1    0   
$EndComp
$Comp
L CP1_Small C?
U 1 1 5C368390
P 6350 1600
F 0 "C?" H 6360 1670 50  0000 L CNN
F 1 "220uF" H 6360 1520 50  0000 L CNN
F 2 "" H 6350 1600 50  0001 C CNN
F 3 "" H 6350 1600 50  0001 C CNN
	1    6350 1600
	0    -1   -1   0   
$EndComp
Text Notes 6050 1400 0    60   ~ 0
Double check conrner \nfrequency of DC blocking \ncaps.
Text HLabel 7000 1900 2    60   Output ~ 0
lfo1
Text Notes 6300 1950 2    60   ~ 0
lfo_1 phase
$Comp
L POT RV?
U 1 1 5C36940A
P 6700 1900
F 0 "RV?" V 6525 1900 50  0000 C CNN
F 1 "10k" V 6600 1900 50  0000 C CNN
F 2 "" H 6700 1900 50  0001 C CNN
F 3 "" H 6700 1900 50  0001 C CNN
	1    6700 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1900 6850 1900
Wire Wire Line
	6700 1750 6700 1600
Wire Wire Line
	6700 1600 6450 1600
$Comp
L GND #PWR?
U 1 1 5C3694AC
P 6700 2100
F 0 "#PWR?" H 6700 1850 50  0001 C CNN
F 1 "GND" H 6700 1950 50  0000 C CNN
F 2 "" H 6700 2100 50  0001 C CNN
F 3 "" H 6700 2100 50  0001 C CNN
	1    6700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2100 6700 2050
Text Notes 7450 2050 2    60   ~ 0
lfo1 mod level
$EndSCHEMATC
