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
LIBS:SparkFun-Electromechanical
LIBS:control_board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L POT RV1
U 1 1 5C3644B6
P 700 1350
F 0 "RV1" V 525 1350 50  0000 C CNN
F 1 "20kA" V 600 1350 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 700 1350 50  0001 C CNN
F 3 "" H 700 1350 50  0001 C CNN
	1    700  1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5C3645AA
P 700 1800
F 0 "#PWR01" H 700 1550 50  0001 C CNN
F 1 "GND" H 700 1650 50  0000 C CNN
F 2 "" H 700 1800 50  0001 C CNN
F 3 "" H 700 1800 50  0001 C CNN
	1    700  1800
	1    0    0    -1  
$EndComp
$Comp
L POT RV6
U 1 1 5C364654
P 1850 1350
F 0 "RV6" V 1675 1350 50  0000 C CNN
F 1 "20kA" V 1750 1350 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 1850 1350 50  0001 C CNN
F 3 "" H 1850 1350 50  0001 C CNN
	1    1850 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5C364660
P 1850 1800
F 0 "#PWR02" H 1850 1550 50  0001 C CNN
F 1 "GND" H 1850 1650 50  0000 C CNN
F 2 "" H 1850 1800 50  0001 C CNN
F 3 "" H 1850 1800 50  0001 C CNN
	1    1850 1800
	1    0    0    -1  
$EndComp
Text Label 850  1350 0    60   ~ 0
osc1_freq_wiper
$Comp
L POT RV2
U 1 1 5C364A7A
P 700 2650
F 0 "RV2" V 525 2650 50  0000 C CNN
F 1 "20kA" V 600 2650 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 700 2650 50  0001 C CNN
F 3 "" H 700 2650 50  0001 C CNN
	1    700  2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5C364A88
P 700 3100
F 0 "#PWR03" H 700 2850 50  0001 C CNN
F 1 "GND" H 700 2950 50  0000 C CNN
F 2 "" H 700 3100 50  0001 C CNN
F 3 "" H 700 3100 50  0001 C CNN
	1    700  3100
	1    0    0    -1  
$EndComp
$Comp
L POT RV7
U 1 1 5C364A8E
P 1850 2650
F 0 "RV7" V 1675 2650 50  0000 C CNN
F 1 "20kA" V 1750 2650 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 1850 2650 50  0001 C CNN
F 3 "" H 1850 2650 50  0001 C CNN
	1    1850 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5C364A9C
P 1850 3100
F 0 "#PWR04" H 1850 2850 50  0001 C CNN
F 1 "GND" H 1850 2950 50  0000 C CNN
F 2 "" H 1850 3100 50  0001 C CNN
F 3 "" H 1850 3100 50  0001 C CNN
	1    1850 3100
	1    0    0    -1  
$EndComp
Text Label 850  2650 0    60   ~ 0
osc2_freq_wiper
$Comp
L POT RV3
U 1 1 5C364C23
P 700 3950
F 0 "RV3" V 525 3950 50  0000 C CNN
F 1 "20kA" V 600 3950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 700 3950 50  0001 C CNN
F 3 "" H 700 3950 50  0001 C CNN
	1    700  3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5C364C31
P 700 4400
F 0 "#PWR05" H 700 4150 50  0001 C CNN
F 1 "GND" H 700 4250 50  0000 C CNN
F 2 "" H 700 4400 50  0001 C CNN
F 3 "" H 700 4400 50  0001 C CNN
	1    700  4400
	1    0    0    -1  
$EndComp
$Comp
L POT RV8
U 1 1 5C364C37
P 1850 3950
F 0 "RV8" V 1675 3950 50  0000 C CNN
F 1 "20kA" V 1750 3950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 1850 3950 50  0001 C CNN
F 3 "" H 1850 3950 50  0001 C CNN
	1    1850 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5C364C45
P 1850 4400
F 0 "#PWR06" H 1850 4150 50  0001 C CNN
F 1 "GND" H 1850 4250 50  0000 C CNN
F 2 "" H 1850 4400 50  0001 C CNN
F 3 "" H 1850 4400 50  0001 C CNN
	1    1850 4400
	1    0    0    -1  
$EndComp
Text Label 850  3950 0    60   ~ 0
osc3_freq_wiper
$Comp
L POT RV4
U 1 1 5C364D70
P 700 5250
F 0 "RV4" V 525 5250 50  0000 C CNN
F 1 "20kA" V 600 5250 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 700 5250 50  0001 C CNN
F 3 "" H 700 5250 50  0001 C CNN
	1    700  5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5C364D7E
P 700 5700
F 0 "#PWR07" H 700 5450 50  0001 C CNN
F 1 "GND" H 700 5550 50  0000 C CNN
F 2 "" H 700 5700 50  0001 C CNN
F 3 "" H 700 5700 50  0001 C CNN
	1    700  5700
	1    0    0    -1  
$EndComp
$Comp
L POT RV9
U 1 1 5C364D84
P 1850 5250
F 0 "RV9" V 1675 5250 50  0000 C CNN
F 1 "20kA" V 1750 5250 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 1850 5250 50  0001 C CNN
F 3 "" H 1850 5250 50  0001 C CNN
	1    1850 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5C364D92
P 1850 5700
F 0 "#PWR08" H 1850 5450 50  0001 C CNN
F 1 "GND" H 1850 5550 50  0000 C CNN
F 2 "" H 1850 5700 50  0001 C CNN
F 3 "" H 1850 5700 50  0001 C CNN
	1    1850 5700
	1    0    0    -1  
$EndComp
Text Label 850  5250 0    60   ~ 0
osc4_freq_wiper
Text Label 2000 1350 0    60   ~ 0
osc1_pwm_wiper
Text Label 2000 2650 0    60   ~ 0
osc2_pwm_wiper
Text Label 2000 3950 0    60   ~ 0
osc3_pwm_wiper
Text Label 2000 5250 0    60   ~ 0
osc4_pwm_wiper
$Comp
L POT RV10
U 1 1 5C3AA947
P 3100 1350
F 0 "RV10" V 2925 1350 50  0000 C CNN
F 1 "20kB" V 3000 1350 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 3100 1350 50  0001 C CNN
F 3 "" H 3100 1350 50  0001 C CNN
	1    3100 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5C3AA953
P 3100 1800
F 0 "#PWR09" H 3100 1550 50  0001 C CNN
F 1 "GND" H 3100 1650 50  0000 C CNN
F 2 "" H 3100 1800 50  0001 C CNN
F 3 "" H 3100 1800 50  0001 C CNN
	1    3100 1800
	1    0    0    -1  
$EndComp
Text Label 3250 1350 0    60   ~ 0
osc1_speed
$Comp
L POT RV11
U 1 1 5C3AA96C
P 3100 2650
F 0 "RV11" V 2925 2650 50  0000 C CNN
F 1 "20kB" V 3000 2650 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 3100 2650 50  0001 C CNN
F 3 "" H 3100 2650 50  0001 C CNN
	1    3100 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5C3AA978
P 3100 3100
F 0 "#PWR010" H 3100 2850 50  0001 C CNN
F 1 "GND" H 3100 2950 50  0000 C CNN
F 2 "" H 3100 3100 50  0001 C CNN
F 3 "" H 3100 3100 50  0001 C CNN
	1    3100 3100
	1    0    0    -1  
$EndComp
Text Label 3250 2650 0    60   ~ 0
osc2_speed
$Comp
L POT RV12
U 1 1 5C3AA991
P 3100 3950
F 0 "RV12" V 2925 3950 50  0000 C CNN
F 1 "20kB" V 3000 3950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 3100 3950 50  0001 C CNN
F 3 "" H 3100 3950 50  0001 C CNN
	1    3100 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5C3AA99D
P 3100 4400
F 0 "#PWR011" H 3100 4150 50  0001 C CNN
F 1 "GND" H 3100 4250 50  0000 C CNN
F 2 "" H 3100 4400 50  0001 C CNN
F 3 "" H 3100 4400 50  0001 C CNN
	1    3100 4400
	1    0    0    -1  
$EndComp
Text Label 3250 3950 0    60   ~ 0
osc3_speed
$Comp
L POT RV13
U 1 1 5C3AA9B6
P 3100 5250
F 0 "RV13" V 2925 5250 50  0000 C CNN
F 1 "20kB" V 3000 5250 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 3100 5250 50  0001 C CNN
F 3 "" H 3100 5250 50  0001 C CNN
	1    3100 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5C3AA9C2
P 3100 5700
F 0 "#PWR012" H 3100 5450 50  0001 C CNN
F 1 "GND" H 3100 5550 50  0000 C CNN
F 2 "" H 3100 5700 50  0001 C CNN
F 3 "" H 3100 5700 50  0001 C CNN
	1    3100 5700
	1    0    0    -1  
$EndComp
Text Label 3250 5250 0    60   ~ 0
osc4_speed
$Comp
L SW_SPST SW3
U 1 1 5C556BD2
P 6400 1100
F 0 "SW3" H 6400 1225 50  0000 C CNN
F 1 "SW_SPST" H 6400 1000 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 6400 1100 50  0001 C CNN
F 3 "" H 6400 1100 50  0001 C CNN
	1    6400 1100
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW4
U 1 1 5C556AE3
P 6400 1200
F 0 "SW4" H 6400 1325 50  0000 C CNN
F 1 "SW_SPST" H 6400 1100 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 6400 1200 50  0001 C CNN
F 3 "" H 6400 1200 50  0001 C CNN
	1    6400 1200
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW2
U 1 1 5C5569F3
P 6400 1000
F 0 "SW2" H 6400 1125 50  0000 C CNN
F 1 "SW_SPST" H 6400 900 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 6400 1000 50  0001 C CNN
F 3 "" H 6400 1000 50  0001 C CNN
	1    6400 1000
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW5
U 1 1 5C5562AE
P 6400 1300
F 0 "SW5" H 6400 1425 50  0000 C CNN
F 1 "SW_SPST" H 6400 1200 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 6400 1300 50  0001 C CNN
F 3 "" H 6400 1300 50  0001 C CNN
	1    6400 1300
	1    0    0    -1  
$EndComp
Text Label 9150 700  0    60   ~ 0
osc1_repeat
Text Label 9150 1100 0    60   ~ 0
osc2_repeat
Text Label 9150 1400 0    60   ~ 0
osc3_repeat
Text Label 9150 1700 0    60   ~ 0
osc4_repeat
Text Label 6000 1300 2    60   ~ 0
envelope_pwm_bypass_in_4
Text Label 6000 1200 2    60   ~ 0
envelope_pwm_bypass_in_3
Text Label 6000 1100 2    60   ~ 0
envelope_pwm_bypass_in_2
Text Label 6000 1000 2    60   ~ 0
envelope_pwm_bypass_in_1
Text Notes 850  700  0    60   ~ 0
Check tapers of speed control.\nI believe these should be linear.
$Comp
L POT RV5
U 1 1 5C5C948E
P 4450 5950
F 0 "RV5" V 4275 5950 50  0000 C CNN
F 1 "10kA" V 4350 5950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 4450 5950 50  0001 C CNN
F 3 "" H 4450 5950 50  0001 C CNN
	1    4450 5950
	0    1    1    0   
$EndComp
Text Label 5700 2050 2    60   ~ 0
osc1_freq_wiper
Text Label 5700 2250 2    60   ~ 0
osc1_pwm_wiper
Text Label 5700 2450 2    60   ~ 0
osc1_speed
Text Label 5700 2950 2    60   ~ 0
envelope_pwm_bypass_in_1
Text Label 6850 1300 0    60   ~ 0
envelope_pwm_bypass_out_4
Text Label 6850 1200 0    60   ~ 0
envelope_pwm_bypass_out_3
Text Label 6850 1100 0    60   ~ 0
envelope_pwm_bypass_out_2
Text Label 6850 1000 0    60   ~ 0
envelope_pwm_bypass_out_1
Text Label 5700 2850 2    60   ~ 0
envelope_pwm_bypass_out_1
Text Label 5700 2750 2    60   ~ 0
osc1_repeat
Text Label 5700 2550 2    60   ~ 0
osc1_quant
Text Label 1000 6300 2    60   ~ 0
freq_in_1
Text Label 950  6850 2    60   ~ 0
freq_in_2
Text Label 950  7350 2    60   ~ 0
freq_in_3
Text Label 950  7800 2    60   ~ 0
freq_in_4
Text Label 10400 3850 2    60   ~ 0
freq_in_1
Text Label 2700 6300 0    60   ~ 0
freq_out_1
Text Label 2700 6850 0    60   ~ 0
freq_out_2
Text Label 2750 7350 0    60   ~ 0
freq_out_3
Text Label 2750 7800 0    60   ~ 0
freq_out_4
Text Label 10400 4050 2    60   ~ 0
freq_out_1
Text Label 4100 5950 2    60   ~ 0
LFO_freq_in
Text Label 4700 5950 0    60   ~ 0
LFO_freq_out
Text Label 5350 7550 2    60   ~ 0
LFO_freq_in
Text Label 5350 7650 2    60   ~ 0
LFO_freq_out
$Comp
L +5V #PWR013
U 1 1 5C5CBE8C
P 5700 1950
F 0 "#PWR013" H 5700 1800 50  0001 C CNN
F 1 "+5V" H 5700 2090 50  0000 C CNN
F 2 "" H 5700 1950 50  0001 C CNN
F 3 "" H 5700 1950 50  0001 C CNN
	1    5700 1950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5C5CC347
P 5700 3050
F 0 "#PWR014" H 5700 2800 50  0001 C CNN
F 1 "GND" H 5700 2900 50  0000 C CNN
F 2 "" H 5700 3050 50  0001 C CNN
F 3 "" H 5700 3050 50  0001 C CNN
	1    5700 3050
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR015
U 1 1 5C5DF7D9
P 700 900
F 0 "#PWR015" H 700 750 50  0001 C CNN
F 1 "+5V" H 700 1040 50  0000 C CNN
F 2 "" H 700 900 50  0001 C CNN
F 3 "" H 700 900 50  0001 C CNN
	1    700  900 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 5C5DF938
P 1850 900
F 0 "#PWR016" H 1850 750 50  0001 C CNN
F 1 "+5V" H 1850 1040 50  0000 C CNN
F 2 "" H 1850 900 50  0001 C CNN
F 3 "" H 1850 900 50  0001 C CNN
	1    1850 900 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 5C5DF9A9
P 3100 900
F 0 "#PWR017" H 3100 750 50  0001 C CNN
F 1 "+5V" H 3100 1040 50  0000 C CNN
F 2 "" H 3100 900 50  0001 C CNN
F 3 "" H 3100 900 50  0001 C CNN
	1    3100 900 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 5C5DFA1A
P 700 2200
F 0 "#PWR018" H 700 2050 50  0001 C CNN
F 1 "+5V" H 700 2340 50  0000 C CNN
F 2 "" H 700 2200 50  0001 C CNN
F 3 "" H 700 2200 50  0001 C CNN
	1    700  2200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR019
U 1 1 5C5DFACF
P 1850 2200
F 0 "#PWR019" H 1850 2050 50  0001 C CNN
F 1 "+5V" H 1850 2340 50  0000 C CNN
F 2 "" H 1850 2200 50  0001 C CNN
F 3 "" H 1850 2200 50  0001 C CNN
	1    1850 2200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR020
U 1 1 5C5DFB40
P 3100 2200
F 0 "#PWR020" H 3100 2050 50  0001 C CNN
F 1 "+5V" H 3100 2340 50  0000 C CNN
F 2 "" H 3100 2200 50  0001 C CNN
F 3 "" H 3100 2200 50  0001 C CNN
	1    3100 2200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR021
U 1 1 5C5DFBB1
P 3100 3500
F 0 "#PWR021" H 3100 3350 50  0001 C CNN
F 1 "+5V" H 3100 3640 50  0000 C CNN
F 2 "" H 3100 3500 50  0001 C CNN
F 3 "" H 3100 3500 50  0001 C CNN
	1    3100 3500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 5C5DFC22
P 1850 3500
F 0 "#PWR022" H 1850 3350 50  0001 C CNN
F 1 "+5V" H 1850 3640 50  0000 C CNN
F 2 "" H 1850 3500 50  0001 C CNN
F 3 "" H 1850 3500 50  0001 C CNN
	1    1850 3500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR023
U 1 1 5C5DFC93
P 700 3500
F 0 "#PWR023" H 700 3350 50  0001 C CNN
F 1 "+5V" H 700 3640 50  0000 C CNN
F 2 "" H 700 3500 50  0001 C CNN
F 3 "" H 700 3500 50  0001 C CNN
	1    700  3500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR024
U 1 1 5C5DFD26
P 700 4800
F 0 "#PWR024" H 700 4650 50  0001 C CNN
F 1 "+5V" H 700 4940 50  0000 C CNN
F 2 "" H 700 4800 50  0001 C CNN
F 3 "" H 700 4800 50  0001 C CNN
	1    700  4800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR025
U 1 1 5C5DFE41
P 1850 4800
F 0 "#PWR025" H 1850 4650 50  0001 C CNN
F 1 "+5V" H 1850 4940 50  0000 C CNN
F 2 "" H 1850 4800 50  0001 C CNN
F 3 "" H 1850 4800 50  0001 C CNN
	1    1850 4800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR026
U 1 1 5C5DFEB2
P 3100 4800
F 0 "#PWR026" H 3100 4650 50  0001 C CNN
F 1 "+5V" H 3100 4940 50  0000 C CNN
F 2 "" H 3100 4800 50  0001 C CNN
F 3 "" H 3100 4800 50  0001 C CNN
	1    3100 4800
	1    0    0    -1  
$EndComp
Text Label 1800 6000 2    60   ~ 0
freq_fb_1
Text Label 1800 6550 2    60   ~ 0
freq_fb_2
Text Label 1800 7050 2    60   ~ 0
freq_fb_3
Text Label 1800 7500 2    60   ~ 0
freq_fb_4
Text Label 10400 3950 2    60   ~ 0
freq_fb_1
$Comp
L SW_DPDT_x2 SW1
U 1 1 5C5E11B0
P 3750 6650
F 0 "SW1" H 3750 6820 50  0000 C CNN
F 1 "SW_DPDT_x2" H 4000 6650 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 3750 6650 50  0001 C CNN
F 3 "" H 3750 6650 50  0001 C CNN
	1    3750 6650
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x03 J2
U 1 1 5C5E130C
P 4600 6650
F 0 "J2" H 4600 6850 50  0000 C CNN
F 1 "Conn_01x03" H 4600 6450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4600 6650 50  0001 C CNN
F 3 "" H 4600 6650 50  0001 C CNN
	1    4600 6650
	1    0    0    -1  
$EndComp
Text Label 3550 6400 0    60   ~ 0
LFO_square
Text Label 3650 6950 0    60   ~ 0
LFO_tri
Text Label 4000 6650 0    60   ~ 0
LFO_out
$Comp
L POT RV18
U 1 1 5C61E4A8
P 6450 4050
F 0 "RV18" V 6275 4050 50  0000 C CNN
F 1 "100kA" V 6350 4050 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 6450 4050 50  0001 C CNN
F 3 "" H 6450 4050 50  0001 C CNN
	1    6450 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5C61E93E
P 6450 4200
F 0 "#PWR027" H 6450 3950 50  0001 C CNN
F 1 "GND" H 6450 4050 50  0000 C CNN
F 2 "" H 6450 4200 50  0001 C CNN
F 3 "" H 6450 4200 50  0001 C CNN
	1    6450 4200
	1    0    0    -1  
$EndComp
$Comp
L POT RV19
U 1 1 5C61EA65
P 6450 4700
F 0 "RV19" V 6275 4700 50  0000 C CNN
F 1 "100kA" V 6350 4700 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 6450 4700 50  0001 C CNN
F 3 "" H 6450 4700 50  0001 C CNN
	1    6450 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5C61EA6B
P 6450 4850
F 0 "#PWR028" H 6450 4600 50  0001 C CNN
F 1 "GND" H 6450 4700 50  0000 C CNN
F 2 "" H 6450 4850 50  0001 C CNN
F 3 "" H 6450 4850 50  0001 C CNN
	1    6450 4850
	1    0    0    -1  
$EndComp
$Comp
L POT RV20
U 1 1 5C61EB63
P 6450 5300
F 0 "RV20" V 6275 5300 50  0000 C CNN
F 1 "100kA" V 6350 5300 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 6450 5300 50  0001 C CNN
F 3 "" H 6450 5300 50  0001 C CNN
	1    6450 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 5C61EB69
P 6450 5450
F 0 "#PWR029" H 6450 5200 50  0001 C CNN
F 1 "GND" H 6450 5300 50  0000 C CNN
F 2 "" H 6450 5450 50  0001 C CNN
F 3 "" H 6450 5450 50  0001 C CNN
	1    6450 5450
	1    0    0    -1  
$EndComp
$Comp
L POT RV21
U 1 1 5C61EB6F
P 6450 5950
F 0 "RV21" V 6275 5950 50  0000 C CNN
F 1 "100kA" V 6350 5950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 6450 5950 50  0001 C CNN
F 3 "" H 6450 5950 50  0001 C CNN
	1    6450 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 5C61EB75
P 6450 6100
F 0 "#PWR030" H 6450 5850 50  0001 C CNN
F 1 "GND" H 6450 5950 50  0000 C CNN
F 2 "" H 6450 6100 50  0001 C CNN
F 3 "" H 6450 6100 50  0001 C CNN
	1    6450 6100
	1    0    0    -1  
$EndComp
Text Label 10400 4150 2    60   ~ 0
lfo_in_1
Text Label 10400 4250 2    60   ~ 0
lfo_out_1
$Comp
L +5V #PWR031
U 1 1 5C6248F4
P 5700 2150
F 0 "#PWR031" H 5700 2000 50  0001 C CNN
F 1 "+5V" H 5700 2290 50  0000 C CNN
F 2 "" H 5700 2150 50  0001 C CNN
F 3 "" H 5700 2150 50  0001 C CNN
	1    5700 2150
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR032
U 1 1 5C6249EF
P 5700 2350
F 0 "#PWR032" H 5700 2200 50  0001 C CNN
F 1 "+5V" H 5700 2490 50  0000 C CNN
F 2 "" H 5700 2350 50  0001 C CNN
F 3 "" H 5700 2350 50  0001 C CNN
	1    5700 2350
	0    -1   -1   0   
$EndComp
Text Label 5700 2650 2    60   ~ 0
osc1_hold
Text Label 6200 2050 0    60   ~ 0
osc2_freq_wiper
Text Label 6200 2250 0    60   ~ 0
osc2_pwm_wiper
Text Label 6200 2450 0    60   ~ 0
osc2_speed
Text Label 6200 2950 0    60   ~ 0
envelope_pwm_bypass_in_2
Text Label 6200 2850 0    60   ~ 0
envelope_pwm_bypass_out_2
Text Label 6200 2750 0    60   ~ 0
osc2_repeat
Text Label 6200 2550 0    60   ~ 0
osc2_quant
Text Label 10400 4500 2    60   ~ 0
freq_in_2
Text Label 10400 4700 2    60   ~ 0
freq_out_2
$Comp
L +5V #PWR033
U 1 1 5C62522F
P 6200 1950
F 0 "#PWR033" H 6200 1800 50  0001 C CNN
F 1 "+5V" H 6200 2090 50  0000 C CNN
F 2 "" H 6200 1950 50  0001 C CNN
F 3 "" H 6200 1950 50  0001 C CNN
	1    6200 1950
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR034
U 1 1 5C625235
P 6200 3050
F 0 "#PWR034" H 6200 2800 50  0001 C CNN
F 1 "GND" H 6200 2900 50  0000 C CNN
F 2 "" H 6200 3050 50  0001 C CNN
F 3 "" H 6200 3050 50  0001 C CNN
	1    6200 3050
	0    -1   1    0   
$EndComp
Text Label 10400 4600 2    60   ~ 0
freq_fb_2
Text Label 10400 4800 2    60   ~ 0
lfo_in_2
Text Label 10400 4900 2    60   ~ 0
lfo_out_2
$Comp
L +5V #PWR035
U 1 1 5C625244
P 6200 2150
F 0 "#PWR035" H 6200 2000 50  0001 C CNN
F 1 "+5V" H 6200 2290 50  0000 C CNN
F 2 "" H 6200 2150 50  0001 C CNN
F 3 "" H 6200 2150 50  0001 C CNN
	1    6200 2150
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR036
U 1 1 5C62524A
P 6200 2350
F 0 "#PWR036" H 6200 2200 50  0001 C CNN
F 1 "+5V" H 6200 2490 50  0000 C CNN
F 2 "" H 6200 2350 50  0001 C CNN
F 3 "" H 6200 2350 50  0001 C CNN
	1    6200 2350
	0    1    -1   0   
$EndComp
Text Label 6200 2650 0    60   ~ 0
osc2_hold
Text Label 8800 2100 2    60   ~ 0
osc3_freq_wiper
Text Label 8800 2300 2    60   ~ 0
osc3_pwm_wiper
Text Label 8800 2500 2    60   ~ 0
osc3_speed
Text Label 8800 2900 2    60   ~ 0
envelope_pwm_bypass_in_3
Text Label 8800 3000 2    60   ~ 0
envelope_pwm_bypass_out_3
Text Label 8800 2800 2    60   ~ 0
osc3_repeat
Text Label 8800 2600 2    60   ~ 0
osc3_quant
Text Label 10400 5200 2    60   ~ 0
freq_in_3
Text Label 10400 5400 2    60   ~ 0
freq_out_3
$Comp
L +5V #PWR037
U 1 1 5C6257DA
P 8800 2000
F 0 "#PWR037" H 8800 1850 50  0001 C CNN
F 1 "+5V" H 8800 2140 50  0000 C CNN
F 2 "" H 8800 2000 50  0001 C CNN
F 3 "" H 8800 2000 50  0001 C CNN
	1    8800 2000
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR038
U 1 1 5C6257E0
P 8800 3200
F 0 "#PWR038" H 8800 2950 50  0001 C CNN
F 1 "GND" H 8800 3050 50  0000 C CNN
F 2 "" H 8800 3200 50  0001 C CNN
F 3 "" H 8800 3200 50  0001 C CNN
	1    8800 3200
	0    1    -1   0   
$EndComp
Text Label 10400 5300 2    60   ~ 0
freq_fb_3
Text Label 10400 5500 2    60   ~ 0
lfo_in_3
Text Label 10400 5600 2    60   ~ 0
lfo_out_3
$Comp
L +5V #PWR039
U 1 1 5C6257EF
P 8800 2200
F 0 "#PWR039" H 8800 2050 50  0001 C CNN
F 1 "+5V" H 8800 2340 50  0000 C CNN
F 2 "" H 8800 2200 50  0001 C CNN
F 3 "" H 8800 2200 50  0001 C CNN
	1    8800 2200
	0    -1   1    0   
$EndComp
$Comp
L +5V #PWR040
U 1 1 5C6257F5
P 8800 2400
F 0 "#PWR040" H 8800 2250 50  0001 C CNN
F 1 "+5V" H 8800 2540 50  0000 C CNN
F 2 "" H 8800 2400 50  0001 C CNN
F 3 "" H 8800 2400 50  0001 C CNN
	1    8800 2400
	0    -1   1    0   
$EndComp
Text Label 8800 2700 2    60   ~ 0
osc3_hold
Text Label 9300 2100 0    60   ~ 0
osc4_freq_wiper
Text Label 9300 2300 0    60   ~ 0
osc4_pwm_wiper
Text Label 9300 2500 0    60   ~ 0
osc4_speed
Text Label 9300 2900 0    60   ~ 0
envelope_pwm_bypass_in_4
Text Label 9300 3000 0    60   ~ 0
envelope_pwm_bypass_out_4
Text Label 9300 2800 0    60   ~ 0
osc4_repeat
Text Label 9300 2600 0    60   ~ 0
osc4_quant
Text Label 10400 5900 2    60   ~ 0
freq_in_4
Text Label 10400 6100 2    60   ~ 0
freq_out_4
$Comp
L +5V #PWR041
U 1 1 5C62580C
P 9300 2000
F 0 "#PWR041" H 9300 1850 50  0001 C CNN
F 1 "+5V" H 9300 2140 50  0000 C CNN
F 2 "" H 9300 2000 50  0001 C CNN
F 3 "" H 9300 2000 50  0001 C CNN
	1    9300 2000
	0    1    1    0   
$EndComp
$Comp
L GND #PWR042
U 1 1 5C625812
P 9300 3200
F 0 "#PWR042" H 9300 2950 50  0001 C CNN
F 1 "GND" H 9300 3050 50  0000 C CNN
F 2 "" H 9300 3200 50  0001 C CNN
F 3 "" H 9300 3200 50  0001 C CNN
	1    9300 3200
	0    -1   -1   0   
$EndComp
Text Label 10400 6000 2    60   ~ 0
freq_fb_4
Text Label 10400 6200 2    60   ~ 0
lfo_in_4
Text Label 10400 6300 2    60   ~ 0
lfo_out_4
$Comp
L +5V #PWR043
U 1 1 5C625821
P 9300 2200
F 0 "#PWR043" H 9300 2050 50  0001 C CNN
F 1 "+5V" H 9300 2340 50  0000 C CNN
F 2 "" H 9300 2200 50  0001 C CNN
F 3 "" H 9300 2200 50  0001 C CNN
	1    9300 2200
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR044
U 1 1 5C625827
P 9300 2400
F 0 "#PWR044" H 9300 2250 50  0001 C CNN
F 1 "+5V" H 9300 2540 50  0000 C CNN
F 2 "" H 9300 2400 50  0001 C CNN
F 3 "" H 9300 2400 50  0001 C CNN
	1    9300 2400
	0    1    1    0   
$EndComp
Text Label 9300 2700 0    60   ~ 0
osc4_hold
$Comp
L POT RV22
U 1 1 5C627148
P 8350 3900
F 0 "RV22" V 8175 3900 50  0000 C CNN
F 1 "100kA" V 8250 3900 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 8350 3900 50  0001 C CNN
F 3 "" H 8350 3900 50  0001 C CNN
	1    8350 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR045
U 1 1 5C62714E
P 8350 4050
F 0 "#PWR045" H 8350 3800 50  0001 C CNN
F 1 "GND" H 8350 3900 50  0000 C CNN
F 2 "" H 8350 4050 50  0001 C CNN
F 3 "" H 8350 4050 50  0001 C CNN
	1    8350 4050
	1    0    0    -1  
$EndComp
$Comp
L POT RV23
U 1 1 5C627154
P 8350 4550
F 0 "RV23" V 8175 4550 50  0000 C CNN
F 1 "100kA" V 8250 4550 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 8350 4550 50  0001 C CNN
F 3 "" H 8350 4550 50  0001 C CNN
	1    8350 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR046
U 1 1 5C62715A
P 8350 4700
F 0 "#PWR046" H 8350 4450 50  0001 C CNN
F 1 "GND" H 8350 4550 50  0000 C CNN
F 2 "" H 8350 4700 50  0001 C CNN
F 3 "" H 8350 4700 50  0001 C CNN
	1    8350 4700
	1    0    0    -1  
$EndComp
$Comp
L POT RV24
U 1 1 5C627160
P 8350 5150
F 0 "RV24" V 8175 5150 50  0000 C CNN
F 1 "100kA" V 8250 5150 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 8350 5150 50  0001 C CNN
F 3 "" H 8350 5150 50  0001 C CNN
	1    8350 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR047
U 1 1 5C627166
P 8350 5300
F 0 "#PWR047" H 8350 5050 50  0001 C CNN
F 1 "GND" H 8350 5150 50  0000 C CNN
F 2 "" H 8350 5300 50  0001 C CNN
F 3 "" H 8350 5300 50  0001 C CNN
	1    8350 5300
	1    0    0    -1  
$EndComp
$Comp
L POT RV25
U 1 1 5C62716C
P 8350 5800
F 0 "RV25" V 8175 5800 50  0000 C CNN
F 1 "100kA" V 8250 5800 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 8350 5800 50  0001 C CNN
F 3 "" H 8350 5800 50  0001 C CNN
	1    8350 5800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR048
U 1 1 5C627172
P 8350 5950
F 0 "#PWR048" H 8350 5700 50  0001 C CNN
F 1 "GND" H 8350 5800 50  0000 C CNN
F 2 "" H 8350 5950 50  0001 C CNN
F 3 "" H 8350 5950 50  0001 C CNN
	1    8350 5950
	1    0    0    -1  
$EndComp
Text Notes 6000 6750 0    60   ~ 0
Output volume mix
Text Notes 8600 6050 0    60   ~ 0
LFO mod depth
Text Label 7400 4650 0    60   ~ 0
vol_in_1
Text Label 7400 4750 0    60   ~ 0
vol_out_1
Text Label 7400 4850 0    60   ~ 0
vol_in_2
Text Label 7400 4950 0    60   ~ 0
vol_out_2
Text Label 7400 5050 0    60   ~ 0
vol_in_3
Text Label 7400 5150 0    60   ~ 0
vol_out_3
Text Label 7400 5250 0    60   ~ 0
vol_in_4
Text Label 7400 5350 0    60   ~ 0
vol_out_4
Text Label 9300 4500 0    60   ~ 0
lfo_in_1
Text Label 9300 4600 0    60   ~ 0
lfo_out_1
Text Label 9300 4700 0    60   ~ 0
lfo_in_2
Text Label 9300 4800 0    60   ~ 0
lfo_out_2
Text Label 9300 4900 0    60   ~ 0
lfo_in_3
Text Label 9300 5000 0    60   ~ 0
lfo_out_3
Text Label 9300 5100 0    60   ~ 0
lfo_in_4
Text Label 9300 5200 0    60   ~ 0
lfo_out_4
Text Label 9150 500  0    60   ~ 0
osc1_hold
Text Label 9150 900  0    60   ~ 0
osc2_hold
Text Label 9150 1200 0    60   ~ 0
osc3_hold
Text Label 9150 1500 0    60   ~ 0
osc4_hold
$Comp
L SW_SPDT SW9
U 1 1 5C6395CA
P 8700 600
F 0 "SW9" H 8700 770 50  0000 C CNN
F 1 "SW_SPDT" H 8700 400 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 8700 600 50  0001 C CNN
F 3 "" H 8700 600 50  0001 C CNN
	1    8700 600 
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW8
U 1 1 5C63968E
P 8700 1000
F 0 "SW8" H 8700 1170 50  0000 C CNN
F 1 "SW_SPDT" H 8700 800 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 8700 1000 50  0001 C CNN
F 3 "" H 8700 1000 50  0001 C CNN
	1    8700 1000
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW7
U 1 1 5C639730
P 8700 1300
F 0 "SW7" H 8700 1470 50  0000 C CNN
F 1 "SW_SPDT" H 8700 1100 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 8700 1300 50  0001 C CNN
F 3 "" H 8700 1300 50  0001 C CNN
	1    8700 1300
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW6
U 1 1 5C6397C9
P 8700 1600
F 0 "SW6" H 8700 1770 50  0000 C CNN
F 1 "SW_SPDT" H 8700 1400 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 8700 1600 50  0001 C CNN
F 3 "" H 8700 1600 50  0001 C CNN
	1    8700 1600
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x05 J7
U 1 1 5C63B7E7
P 10600 4050
F 0 "J7" H 10600 4350 50  0000 C CNN
F 1 "Conn_01x05" H 10600 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 10600 4050 50  0001 C CNN
F 3 "" H 10600 4050 50  0001 C CNN
	1    10600 4050
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x05 J8
U 1 1 5C63B889
P 10600 4700
F 0 "J8" H 10600 5000 50  0000 C CNN
F 1 "Conn_01x05" H 10600 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 10600 4700 50  0001 C CNN
F 3 "" H 10600 4700 50  0001 C CNN
	1    10600 4700
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x05 J9
U 1 1 5C63BBB5
P 10600 5400
F 0 "J9" H 10600 5700 50  0000 C CNN
F 1 "Conn_01x05" H 10600 5100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 10600 5400 50  0001 C CNN
F 3 "" H 10600 5400 50  0001 C CNN
	1    10600 5400
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x05 J10
U 1 1 5C63BC62
P 10600 6100
F 0 "J10" H 10600 6400 50  0000 C CNN
F 1 "Conn_01x05" H 10600 5800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 10600 6100 50  0001 C CNN
F 3 "" H 10600 6100 50  0001 C CNN
	1    10600 6100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR049
U 1 1 5C63783E
P 8800 3100
F 0 "#PWR049" H 8800 2850 50  0001 C CNN
F 1 "GND" H 8800 2950 50  0000 C CNN
F 2 "" H 8800 3100 50  0001 C CNN
F 3 "" H 8800 3100 50  0001 C CNN
	1    8800 3100
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR050
U 1 1 5C6379D8
P 9300 3100
F 0 "#PWR050" H 9300 2850 50  0001 C CNN
F 1 "GND" H 9300 2950 50  0000 C CNN
F 2 "" H 9300 3100 50  0001 C CNN
F 3 "" H 9300 3100 50  0001 C CNN
	1    9300 3100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR051
U 1 1 5C637E71
P 6200 3150
F 0 "#PWR051" H 6200 2900 50  0001 C CNN
F 1 "GND" H 6200 3000 50  0000 C CNN
F 2 "" H 6200 3150 50  0001 C CNN
F 3 "" H 6200 3150 50  0001 C CNN
	1    6200 3150
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR052
U 1 1 5C63814D
P 5700 3150
F 0 "#PWR052" H 5700 2900 50  0001 C CNN
F 1 "GND" H 5700 3000 50  0000 C CNN
F 2 "" H 5700 3150 50  0001 C CNN
F 3 "" H 5700 3150 50  0001 C CNN
	1    5700 3150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR053
U 1 1 5C638308
P 8500 1600
F 0 "#PWR053" H 8500 1350 50  0001 C CNN
F 1 "GND" H 8500 1450 50  0000 C CNN
F 2 "" H 8500 1600 50  0001 C CNN
F 3 "" H 8500 1600 50  0001 C CNN
	1    8500 1600
	0    1    1    0   
$EndComp
$Comp
L GND #PWR054
U 1 1 5C6383A3
P 8500 1300
F 0 "#PWR054" H 8500 1050 50  0001 C CNN
F 1 "GND" H 8500 1150 50  0000 C CNN
F 2 "" H 8500 1300 50  0001 C CNN
F 3 "" H 8500 1300 50  0001 C CNN
	1    8500 1300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR055
U 1 1 5C63843E
P 8500 1000
F 0 "#PWR055" H 8500 750 50  0001 C CNN
F 1 "GND" H 8500 850 50  0000 C CNN
F 2 "" H 8500 1000 50  0001 C CNN
F 3 "" H 8500 1000 50  0001 C CNN
	1    8500 1000
	0    1    1    0   
$EndComp
$Comp
L GND #PWR056
U 1 1 5C6384D9
P 8500 600
F 0 "#PWR056" H 8500 350 50  0001 C CNN
F 1 "GND" H 8500 450 50  0000 C CNN
F 2 "" H 8500 600 50  0001 C CNN
F 3 "" H 8500 600 50  0001 C CNN
	1    8500 600 
	0    1    1    0   
$EndComp
$Comp
L Conn_01x08 J11
U 1 1 5C64AA03
P 6650 7200
F 0 "J11" H 6650 7600 50  0000 C CNN
F 1 "Conn_01x08" H 6650 6700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 6650 7200 50  0001 C CNN
F 3 "" H 6650 7200 50  0001 C CNN
	1    6650 7200
	1    0    0    -1  
$EndComp
Text Label 6450 6900 2    60   ~ 0
vol_in_1
Text Label 6450 7000 2    60   ~ 0
vol_out_1
Text Label 6450 7100 2    60   ~ 0
vol_in_2
Text Label 6450 7200 2    60   ~ 0
vol_out_2
Text Label 6450 7300 2    60   ~ 0
vol_in_3
Text Label 6450 7400 2    60   ~ 0
vol_out_3
Text Label 6450 7500 2    60   ~ 0
vol_in_4
Text Label 6450 7600 2    60   ~ 0
vol_out_4
$Comp
L POT RV26
U 1 1 5C64B53E
P 4650 4050
F 0 "RV26" V 4475 4050 50  0000 C CNN
F 1 "50kB" V 4550 4050 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 4650 4050 50  0001 C CNN
F 3 "" H 4650 4050 50  0001 C CNN
	1    4650 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR057
U 1 1 5C64B544
P 4650 4200
F 0 "#PWR057" H 4650 3950 50  0001 C CNN
F 1 "GND" H 4650 4050 50  0000 C CNN
F 2 "" H 4650 4200 50  0001 C CNN
F 3 "" H 4650 4200 50  0001 C CNN
	1    4650 4200
	1    0    0    -1  
$EndComp
$Comp
L POT RV27
U 1 1 5C64B54A
P 4650 4700
F 0 "RV27" V 4475 4700 50  0000 C CNN
F 1 "100kA" V 4550 4700 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 4650 4700 50  0001 C CNN
F 3 "" H 4650 4700 50  0001 C CNN
	1    4650 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 5C64B550
P 4650 4850
F 0 "#PWR058" H 4650 4600 50  0001 C CNN
F 1 "GND" H 4650 4700 50  0000 C CNN
F 2 "" H 4650 4850 50  0001 C CNN
F 3 "" H 4650 4850 50  0001 C CNN
	1    4650 4850
	1    0    0    -1  
$EndComp
$Comp
L POT RV28
U 1 1 5C64B556
P 4650 5300
F 0 "RV28" V 4475 5300 50  0000 C CNN
F 1 "50k" V 4550 5300 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 4650 5300 50  0001 C CNN
F 3 "" H 4650 5300 50  0001 C CNN
	1    4650 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR059
U 1 1 5C64B55C
P 4800 5300
F 0 "#PWR059" H 4800 5050 50  0001 C CNN
F 1 "GND" H 4800 5150 50  0000 C CNN
F 2 "" H 4800 5300 50  0001 C CNN
F 3 "" H 4800 5300 50  0001 C CNN
	1    4800 5300
	0    -1   -1   0   
$EndComp
Text Notes 4950 6800 0    60   ~ 0
Delay controls
Text Label 5600 4650 0    60   ~ 0
delay_fb_in
Text Label 5600 4750 0    60   ~ 0
delay_fb_out
Text Label 5600 4850 0    60   ~ 0
delay_time_in
Text Label 5600 4950 0    60   ~ 0
delay_time_out
Text Label 5600 5050 0    60   ~ 0
delay_mix_in
Text Label 5600 5150 0    60   ~ 0
delay_mix_out
Text Label 5350 6950 2    60   ~ 0
delay_fb_in
Text Label 5350 7050 2    60   ~ 0
delay_fb_out
Text Label 5350 7150 2    60   ~ 0
delay_time_in
Text Label 5350 7250 2    60   ~ 0
delay_time_out
Text Label 5350 7350 2    60   ~ 0
delay_mix_in
Text Label 5350 7450 2    60   ~ 0
delay_mix_out
$Comp
L Conn_02x13_Odd_Even J1
U 1 1 5C746E83
P 5900 2550
F 0 "J1" H 5950 3250 50  0000 C CNN
F 1 "Conn_02x13_Odd_Even" H 5950 1850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x13_Pitch2.54mm" H 5900 2550 50  0001 C CNN
F 3 "" H 5900 2550 50  0001 C CNN
	1    5900 2550
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x13_Odd_Even J3
U 1 1 5C747643
P 9000 2600
F 0 "J3" H 9050 3300 50  0000 C CNN
F 1 "Conn_02x13_Odd_Even" H 9050 1900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x13_Pitch2.54mm" H 9000 2600 50  0001 C CNN
F 3 "" H 9000 2600 50  0001 C CNN
	1    9000 2600
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW11
U 1 1 5C7470DD
P 10550 1050
F 0 "SW11" H 10550 1175 50  0000 C CNN
F 1 "SW_SPST" H 10550 950 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 10550 1050 50  0001 C CNN
F 3 "" H 10550 1050 50  0001 C CNN
	1    10550 1050
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW12
U 1 1 5C7470E3
P 10550 1150
F 0 "SW12" H 10550 1275 50  0000 C CNN
F 1 "SW_SPST" H 10550 1050 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 10550 1150 50  0001 C CNN
F 3 "" H 10550 1150 50  0001 C CNN
	1    10550 1150
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW10
U 1 1 5C7470E9
P 10550 950
F 0 "SW10" H 10550 1075 50  0000 C CNN
F 1 "SW_SPST" H 10550 850 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 10550 950 50  0001 C CNN
F 3 "" H 10550 950 50  0001 C CNN
	1    10550 950 
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW13
U 1 1 5C7470EF
P 10550 1250
F 0 "SW13" H 10550 1375 50  0000 C CNN
F 1 "SW_SPST" H 10550 1150 50  0000 C CNN
F 2 "switches:switch_toggle_4.7mm_pitch" H 10550 1250 50  0001 C CNN
F 3 "" H 10550 1250 50  0001 C CNN
	1    10550 1250
	1    0    0    -1  
$EndComp
Text Label 11000 1150 0    60   ~ 0
osc3_quant
Text Label 11000 1250 0    60   ~ 0
osc4_quant
$Comp
L GND #PWR060
U 1 1 5C747812
P 10150 950
F 0 "#PWR060" H 10150 700 50  0001 C CNN
F 1 "GND" H 10150 800 50  0000 C CNN
F 2 "" H 10150 950 50  0001 C CNN
F 3 "" H 10150 950 50  0001 C CNN
	1    10150 950 
	0    1    1    0   
$EndComp
$Comp
L GND #PWR061
U 1 1 5C74797B
P 10150 1050
F 0 "#PWR061" H 10150 800 50  0001 C CNN
F 1 "GND" H 10150 900 50  0000 C CNN
F 2 "" H 10150 1050 50  0001 C CNN
F 3 "" H 10150 1050 50  0001 C CNN
	1    10150 1050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR062
U 1 1 5C747A1C
P 10150 1150
F 0 "#PWR062" H 10150 900 50  0001 C CNN
F 1 "GND" H 10150 1000 50  0000 C CNN
F 2 "" H 10150 1150 50  0001 C CNN
F 3 "" H 10150 1150 50  0001 C CNN
	1    10150 1150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR063
U 1 1 5C747ABD
P 10150 1250
F 0 "#PWR063" H 10150 1000 50  0001 C CNN
F 1 "GND" H 10150 1100 50  0000 C CNN
F 2 "" H 10150 1250 50  0001 C CNN
F 3 "" H 10150 1250 50  0001 C CNN
	1    10150 1250
	0    1    1    0   
$EndComp
Text Label 11000 950  0    60   ~ 0
osc1_quant
Text Label 11000 1050 0    60   ~ 0
osc2_quant
$Comp
L POT RV29
U 1 1 5C74C7C8
P 3700 7450
F 0 "RV29" V 3525 7450 50  0000 C CNN
F 1 "10kA" V 3600 7450 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_PTV09A-1_Horizontal" H 3700 7450 50  0001 C CNN
F 3 "" H 3700 7450 50  0001 C CNN
	1    3700 7450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR064
U 1 1 5C74C8D6
P 3700 7600
F 0 "#PWR064" H 3700 7350 50  0001 C CNN
F 1 "GND" H 3700 7450 50  0000 C CNN
F 2 "" H 3700 7600 50  0001 C CNN
F 3 "" H 3700 7600 50  0001 C CNN
	1    3700 7600
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08 J4
U 1 1 5C74DACB
P 5550 7250
F 0 "J4" H 5550 7650 50  0000 C CNN
F 1 "Conn_01x08" H 5550 6750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 5550 7250 50  0001 C CNN
F 3 "" H 5550 7250 50  0001 C CNN
	1    5550 7250
	1    0    0    -1  
$EndComp
Text Label 3300 7200 2    60   ~ 0
delay_in
$Comp
L R R1
U 1 1 5C74EA1D
P 3500 7200
F 0 "R1" V 3580 7200 50  0000 C CNN
F 1 "R" V 3500 7200 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3430 7200 50  0001 C CNN
F 3 "" H 3500 7200 50  0001 C CNN
	1    3500 7200
	0    1    1    0   
$EndComp
$Comp
L C_Small C1
U 1 1 5C74F6A7
P 4050 7450
F 0 "C1" H 4060 7520 50  0000 L CNN
F 1 "C_Small" H 4060 7370 50  0000 L CNN
F 2 "digikey-footprints:0805" H 4050 7450 50  0001 C CNN
F 3 "" H 4050 7450 50  0001 C CNN
	1    4050 7450
	0    1    1    0   
$EndComp
Text Label 4150 7450 0    60   ~ 0
delay_in
Wire Wire Line
	10150 1250 10350 1250
Wire Wire Line
	10150 1150 10350 1150
Wire Wire Line
	10150 1050 10350 1050
Wire Wire Line
	10750 1250 11000 1250
Wire Wire Line
	10750 1150 11000 1150
Wire Wire Line
	10750 1050 11000 1050
Wire Wire Line
	10150 950  10350 950 
Wire Wire Line
	10750 950  11000 950 
Wire Wire Line
	4650 5550 4650 5450
Wire Wire Line
	5200 5550 4650 5550
Wire Wire Line
	5200 5150 5600 5150
Wire Wire Line
	5200 5150 5200 5550
Wire Wire Line
	4650 5050 5600 5050
Wire Wire Line
	4650 5050 4650 5150
Wire Wire Line
	5200 4700 4800 4700
Wire Wire Line
	5200 4950 5200 4700
Wire Wire Line
	5600 4950 5200 4950
Wire Wire Line
	5300 4850 5600 4850
Wire Wire Line
	5300 4450 5300 4850
Wire Wire Line
	4650 4450 5300 4450
Wire Wire Line
	4650 4550 4650 4450
Wire Wire Line
	4650 3800 4650 3900
Wire Wire Line
	5500 3800 4650 3800
Wire Wire Line
	5500 4650 5500 3800
Wire Wire Line
	5600 4650 5500 4650
Wire Wire Line
	5400 4750 5600 4750
Wire Wire Line
	5400 4050 5400 4750
Wire Wire Line
	4800 4050 5400 4050
Wire Wire Line
	9300 3200 9300 3200
Wire Wire Line
	9150 1500 8900 1500
Wire Wire Line
	9150 1200 8900 1200
Wire Wire Line
	9150 900  8900 900 
Wire Wire Line
	9150 500  8900 500 
Wire Wire Line
	9200 5200 9300 5200
Wire Wire Line
	9200 5800 9200 5200
Wire Wire Line
	8500 5800 9200 5800
Wire Wire Line
	9050 5100 9300 5100
Wire Wire Line
	9050 5500 9050 5100
Wire Wire Line
	8350 5500 9050 5500
Wire Wire Line
	8350 5650 8350 5500
Wire Wire Line
	8900 5000 9300 5000
Wire Wire Line
	8900 5150 8900 5000
Wire Wire Line
	8500 5150 8900 5150
Wire Wire Line
	8350 4900 9300 4900
Wire Wire Line
	8350 4900 8350 5000
Wire Wire Line
	8900 4550 8500 4550
Wire Wire Line
	8900 4800 8900 4550
Wire Wire Line
	9300 4800 8900 4800
Wire Wire Line
	9000 4700 9300 4700
Wire Wire Line
	9000 4300 9000 4700
Wire Wire Line
	8350 4300 9000 4300
Wire Wire Line
	8350 4400 8350 4300
Wire Wire Line
	8350 3650 8350 3750
Wire Wire Line
	9200 3650 8350 3650
Wire Wire Line
	9200 4500 9200 3650
Wire Wire Line
	9300 4500 9200 4500
Wire Wire Line
	9100 4600 9300 4600
Wire Wire Line
	9100 3900 9100 4600
Wire Wire Line
	8500 3900 9100 3900
Wire Wire Line
	6200 3150 6200 3150
Wire Wire Line
	5700 3150 5700 3150
Wire Wire Line
	7300 5350 7400 5350
Wire Wire Line
	7300 5950 7300 5350
Wire Wire Line
	6600 5950 7300 5950
Wire Wire Line
	7150 5250 7400 5250
Wire Wire Line
	7150 5650 7150 5250
Wire Wire Line
	6450 5650 7150 5650
Wire Wire Line
	6450 5800 6450 5650
Wire Wire Line
	7000 5150 7400 5150
Wire Wire Line
	7000 5300 7000 5150
Wire Wire Line
	6600 5300 7000 5300
Wire Wire Line
	6450 5050 7400 5050
Wire Wire Line
	6450 5050 6450 5150
Wire Wire Line
	7000 4700 6600 4700
Wire Wire Line
	7000 4950 7000 4700
Wire Wire Line
	7400 4950 7000 4950
Wire Wire Line
	7100 4850 7400 4850
Wire Wire Line
	7100 4450 7100 4850
Wire Wire Line
	6450 4450 7100 4450
Wire Wire Line
	6450 4550 6450 4450
Wire Wire Line
	6450 3800 6450 3900
Wire Wire Line
	7300 3800 6450 3800
Wire Wire Line
	7300 4650 7300 3800
Wire Wire Line
	7400 4650 7300 4650
Wire Wire Line
	7200 4750 7400 4750
Wire Wire Line
	7200 4050 7200 4750
Wire Wire Line
	6600 4050 7200 4050
Wire Wire Line
	4100 6750 4400 6750
Wire Wire Line
	4100 6950 4100 6750
Wire Wire Line
	3450 6950 4100 6950
Wire Wire Line
	3450 6750 3450 6950
Wire Wire Line
	3550 6750 3450 6750
Wire Wire Line
	3450 6550 3550 6550
Wire Wire Line
	3450 6400 3450 6550
Wire Wire Line
	4100 6400 3450 6400
Wire Wire Line
	4100 6550 4100 6400
Wire Wire Line
	4400 6550 4100 6550
Wire Wire Line
	4400 6650 3950 6650
Connection ~ 1800 6300
Wire Wire Line
	1800 6000 1800 6300
Wire Wire Line
	4700 5950 4600 5950
Connection ~ 4250 5950
Wire Wire Line
	4100 5950 4300 5950
Wire Wire Line
	4250 6150 4250 5950
Wire Wire Line
	4450 6150 4250 6150
Wire Wire Line
	4450 6100 4450 6150
Wire Wire Line
	2550 6850 2700 6850
Wire Wire Line
	2600 6300 2700 6300
Wire Wire Line
	1800 6300 2000 6300
Wire Wire Line
	1000 6300 1200 6300
Wire Wire Line
	8900 1700 9150 1700
Wire Wire Line
	8900 1400 9150 1400
Wire Wire Line
	8900 1100 9150 1100
Wire Wire Line
	8900 700  9150 700 
Wire Wire Line
	6000 1300 6200 1300
Wire Wire Line
	6000 1200 6200 1200
Wire Wire Line
	6000 1100 6200 1100
Wire Wire Line
	6600 1300 6850 1300
Wire Wire Line
	6600 1200 6850 1200
Wire Wire Line
	6600 1100 6850 1100
Wire Wire Line
	6000 1000 6200 1000
Wire Wire Line
	6600 1000 6850 1000
Wire Wire Line
	3700 7200 3700 7300
Wire Wire Line
	3300 7200 3350 7200
Wire Wire Line
	3650 7200 3700 7200
Wire Wire Line
	3950 7450 3850 7450
Wire Wire Line
	1500 6050 1500 6100
Wire Wire Line
	2300 6050 2300 6100
Wire Wire Line
	950  6850 1100 6850
Wire Wire Line
	1700 6850 1950 6850
Wire Wire Line
	1400 6650 1400 6600
Wire Wire Line
	1800 6550 1800 6850
Connection ~ 1800 6850
Wire Wire Line
	2250 6650 2250 6600
Wire Wire Line
	950  7350 1100 7350
Wire Wire Line
	1400 7150 1400 7100
Wire Wire Line
	1700 7350 1950 7350
Wire Wire Line
	1800 7050 1800 7350
Connection ~ 1800 7350
Wire Wire Line
	2250 7150 2250 7100
Wire Wire Line
	2550 7350 2750 7350
Wire Wire Line
	950  7800 1100 7800
Wire Wire Line
	1400 7600 1400 7550
Wire Wire Line
	1700 7800 1950 7800
Wire Wire Line
	1800 7500 1800 7800
Connection ~ 1800 7800
Wire Wire Line
	2250 7600 2250 7550
Wire Wire Line
	2550 7800 2750 7800
$Comp
L POT_DUAL RV17
U 1 1 5C755D90
P 1500 6300
F 0 "RV17" V 1665 5900 50  0000 L BNN
F 1 "POT_DUAL" V 1365 5900 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 1530 6450 20  0001 C CNN
F 3 "" H 1500 6300 60  0001 C CNN
	1    1500 6300
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV17
U 2 1 5C755EA9
P 2300 6300
F 0 "RV17" V 2465 5900 50  0000 L BNN
F 1 "POT_DUAL" V 2165 5900 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 2330 6450 20  0001 C CNN
F 3 "" H 2300 6300 60  0001 C CNN
	2    2300 6300
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV14
U 1 1 5C755FDE
P 1400 6850
F 0 "RV14" V 1565 6450 50  0000 L BNN
F 1 "POT_DUAL" V 1265 6450 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 1430 7000 20  0001 C CNN
F 3 "" H 1400 6850 60  0001 C CNN
	1    1400 6850
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV15
U 1 1 5C7560A0
P 1400 7350
F 0 "RV15" V 1565 6950 50  0000 L BNN
F 1 "POT_DUAL" V 1265 6950 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 1430 7500 20  0001 C CNN
F 3 "" H 1400 7350 60  0001 C CNN
	1    1400 7350
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV16
U 1 1 5C756165
P 1400 7800
F 0 "RV16" V 1565 7400 50  0000 L BNN
F 1 "POT_DUAL" V 1265 7400 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 1430 7950 20  0001 C CNN
F 3 "" H 1400 7800 60  0001 C CNN
	1    1400 7800
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV14
U 2 1 5C756225
P 2250 6850
F 0 "RV14" V 2415 6450 50  0000 L BNN
F 1 "POT_DUAL" V 2115 6450 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 2280 7000 20  0001 C CNN
F 3 "" H 2250 6850 60  0001 C CNN
	2    2250 6850
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV15
U 2 1 5C7562F4
P 2250 7350
F 0 "RV15" V 2415 6950 50  0000 L BNN
F 1 "POT_DUAL" V 2115 6950 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 2280 7500 20  0001 C CNN
F 3 "" H 2250 7350 60  0001 C CNN
	2    2250 7350
	0    1    -1   0   
$EndComp
$Comp
L POT_DUAL RV16
U 2 1 5C7563C0
P 2250 7800
F 0 "RV16" V 2415 7400 50  0000 L BNN
F 1 "POT_DUAL" V 2115 7400 50  0000 L BNN
F 2 "SparkFun-Electromechanical:POT_PANASONIC_DUAL_VERT_KIT" H 2280 7950 20  0001 C CNN
F 3 "" H 2250 7800 60  0001 C CNN
	2    2250 7800
	0    1    -1   0   
$EndComp
$Comp
L R R6
U 1 1 5C758255
P 700 1050
F 0 "R6" V 780 1050 50  0000 C CNN
F 1 "R" V 700 1050 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 1050 50  0001 C CNN
F 3 "" H 700 1050 50  0001 C CNN
	1    700  1050
	-1   0    0    1   
$EndComp
$Comp
L R R14
U 1 1 5C7586B2
P 1850 1050
F 0 "R14" V 1930 1050 50  0000 C CNN
F 1 "R" V 1850 1050 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 1050 50  0001 C CNN
F 3 "" H 1850 1050 50  0001 C CNN
	1    1850 1050
	-1   0    0    1   
$EndComp
$Comp
L R R22
U 1 1 5C7587A5
P 3100 1050
F 0 "R22" V 3180 1050 50  0000 C CNN
F 1 "R" V 3100 1050 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 1050 50  0001 C CNN
F 3 "" H 3100 1050 50  0001 C CNN
	1    3100 1050
	-1   0    0    1   
$EndComp
$Comp
L R R7
U 1 1 5C758B73
P 700 1650
F 0 "R7" V 780 1650 50  0000 C CNN
F 1 "R" V 700 1650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 1650 50  0001 C CNN
F 3 "" H 700 1650 50  0001 C CNN
	1    700  1650
	-1   0    0    1   
$EndComp
$Comp
L R R15
U 1 1 5C758CCC
P 1850 1650
F 0 "R15" V 1930 1650 50  0000 C CNN
F 1 "R" V 1850 1650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 1650 50  0001 C CNN
F 3 "" H 1850 1650 50  0001 C CNN
	1    1850 1650
	-1   0    0    1   
$EndComp
$Comp
L R R23
U 1 1 5C758DC0
P 3100 1650
F 0 "R23" V 3180 1650 50  0000 C CNN
F 1 "R" V 3100 1650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 1650 50  0001 C CNN
F 3 "" H 3100 1650 50  0001 C CNN
	1    3100 1650
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5C7595D2
P 700 2350
F 0 "R2" V 780 2350 50  0000 C CNN
F 1 "R" V 700 2350 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 2350 50  0001 C CNN
F 3 "" H 700 2350 50  0001 C CNN
	1    700  2350
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5C7595D9
P 1850 2350
F 0 "R10" V 1930 2350 50  0000 C CNN
F 1 "R" V 1850 2350 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 2350 50  0001 C CNN
F 3 "" H 1850 2350 50  0001 C CNN
	1    1850 2350
	-1   0    0    1   
$EndComp
$Comp
L R R18
U 1 1 5C7595E0
P 3100 2350
F 0 "R18" V 3180 2350 50  0000 C CNN
F 1 "R" V 3100 2350 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 2350 50  0001 C CNN
F 3 "" H 3100 2350 50  0001 C CNN
	1    3100 2350
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5C759767
P 700 2950
F 0 "R3" V 780 2950 50  0000 C CNN
F 1 "R" V 700 2950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 2950 50  0001 C CNN
F 3 "" H 700 2950 50  0001 C CNN
	1    700  2950
	-1   0    0    1   
$EndComp
$Comp
L R R11
U 1 1 5C75976E
P 1850 2950
F 0 "R11" V 1930 2950 50  0000 C CNN
F 1 "R" V 1850 2950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 2950 50  0001 C CNN
F 3 "" H 1850 2950 50  0001 C CNN
	1    1850 2950
	-1   0    0    1   
$EndComp
$Comp
L R R19
U 1 1 5C759775
P 3100 2950
F 0 "R19" V 3180 2950 50  0000 C CNN
F 1 "R" V 3100 2950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 2950 50  0001 C CNN
F 3 "" H 3100 2950 50  0001 C CNN
	1    3100 2950
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5C759FB3
P 700 3650
F 0 "R8" V 780 3650 50  0000 C CNN
F 1 "R" V 700 3650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 3650 50  0001 C CNN
F 3 "" H 700 3650 50  0001 C CNN
	1    700  3650
	-1   0    0    1   
$EndComp
$Comp
L R R16
U 1 1 5C759FBA
P 1850 3650
F 0 "R16" V 1930 3650 50  0000 C CNN
F 1 "R" V 1850 3650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 3650 50  0001 C CNN
F 3 "" H 1850 3650 50  0001 C CNN
	1    1850 3650
	-1   0    0    1   
$EndComp
$Comp
L R R24
U 1 1 5C759FC1
P 3100 3650
F 0 "R24" V 3180 3650 50  0000 C CNN
F 1 "R" V 3100 3650 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 3650 50  0001 C CNN
F 3 "" H 3100 3650 50  0001 C CNN
	1    3100 3650
	-1   0    0    1   
$EndComp
$Comp
L R R9
U 1 1 5C75A14E
P 700 4250
F 0 "R9" V 780 4250 50  0000 C CNN
F 1 "R" V 700 4250 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 4250 50  0001 C CNN
F 3 "" H 700 4250 50  0001 C CNN
	1    700  4250
	-1   0    0    1   
$EndComp
$Comp
L R R17
U 1 1 5C75A155
P 1850 4250
F 0 "R17" V 1930 4250 50  0000 C CNN
F 1 "R" V 1850 4250 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 4250 50  0001 C CNN
F 3 "" H 1850 4250 50  0001 C CNN
	1    1850 4250
	-1   0    0    1   
$EndComp
$Comp
L R R25
U 1 1 5C75A15C
P 3100 4250
F 0 "R25" V 3180 4250 50  0000 C CNN
F 1 "R" V 3100 4250 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 4250 50  0001 C CNN
F 3 "" H 3100 4250 50  0001 C CNN
	1    3100 4250
	-1   0    0    1   
$EndComp
$Comp
L R R4
U 1 1 5C75A598
P 700 4950
F 0 "R4" V 780 4950 50  0000 C CNN
F 1 "R" V 700 4950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 4950 50  0001 C CNN
F 3 "" H 700 4950 50  0001 C CNN
	1    700  4950
	-1   0    0    1   
$EndComp
$Comp
L R R12
U 1 1 5C75A59F
P 1850 4950
F 0 "R12" V 1930 4950 50  0000 C CNN
F 1 "R" V 1850 4950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 4950 50  0001 C CNN
F 3 "" H 1850 4950 50  0001 C CNN
	1    1850 4950
	-1   0    0    1   
$EndComp
$Comp
L R R20
U 1 1 5C75A5A6
P 3100 4950
F 0 "R20" V 3180 4950 50  0000 C CNN
F 1 "R" V 3100 4950 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 4950 50  0001 C CNN
F 3 "" H 3100 4950 50  0001 C CNN
	1    3100 4950
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 5C75A871
P 700 5550
F 0 "R5" V 780 5550 50  0000 C CNN
F 1 "R" V 700 5550 50  0000 C CNN
F 2 "digikey-footprints:0805" V 630 5550 50  0001 C CNN
F 3 "" H 700 5550 50  0001 C CNN
	1    700  5550
	-1   0    0    1   
$EndComp
$Comp
L R R13
U 1 1 5C75A878
P 1850 5550
F 0 "R13" V 1930 5550 50  0000 C CNN
F 1 "R" V 1850 5550 50  0000 C CNN
F 2 "digikey-footprints:0805" V 1780 5550 50  0001 C CNN
F 3 "" H 1850 5550 50  0001 C CNN
	1    1850 5550
	-1   0    0    1   
$EndComp
$Comp
L R R21
U 1 1 5C75A87F
P 3100 5550
F 0 "R21" V 3180 5550 50  0000 C CNN
F 1 "R" V 3100 5550 50  0000 C CNN
F 2 "digikey-footprints:0805" V 3030 5550 50  0001 C CNN
F 3 "" H 3100 5550 50  0001 C CNN
	1    3100 5550
	-1   0    0    1   
$EndComp
$Comp
L C_Small C5
U 1 1 5C75BCAC
P 850 1450
F 0 "C5" H 860 1520 50  0000 L CNN
F 1 "C_Small" H 860 1370 50  0000 L CNN
F 2 "digikey-footprints:0805" H 850 1450 50  0001 C CNN
F 3 "" H 850 1450 50  0001 C CNN
	1    850  1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR065
U 1 1 5C75BDDD
P 850 1550
F 0 "#PWR065" H 850 1300 50  0001 C CNN
F 1 "GND" H 850 1400 50  0000 C CNN
F 2 "" H 850 1550 50  0001 C CNN
F 3 "" H 850 1550 50  0001 C CNN
	1    850  1550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C9
U 1 1 5C75BF34
P 2000 1450
F 0 "C9" H 2010 1520 50  0000 L CNN
F 1 "C_Small" H 2010 1370 50  0000 L CNN
F 2 "digikey-footprints:0805" H 2000 1450 50  0001 C CNN
F 3 "" H 2000 1450 50  0001 C CNN
	1    2000 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR066
U 1 1 5C75C051
P 2000 1550
F 0 "#PWR066" H 2000 1300 50  0001 C CNN
F 1 "GND" H 2000 1400 50  0000 C CNN
F 2 "" H 2000 1550 50  0001 C CNN
F 3 "" H 2000 1550 50  0001 C CNN
	1    2000 1550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C13
U 1 1 5C75CC0B
P 3250 1450
F 0 "C13" H 3260 1520 50  0000 L CNN
F 1 "C_Small" H 3260 1370 50  0000 L CNN
F 2 "digikey-footprints:0805" H 3250 1450 50  0001 C CNN
F 3 "" H 3250 1450 50  0001 C CNN
	1    3250 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR067
U 1 1 5C75CC12
P 3250 1550
F 0 "#PWR067" H 3250 1300 50  0001 C CNN
F 1 "GND" H 3250 1400 50  0000 C CNN
F 2 "" H 3250 1550 50  0001 C CNN
F 3 "" H 3250 1550 50  0001 C CNN
	1    3250 1550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C11
U 1 1 5C75CFD6
P 3250 2750
F 0 "C11" H 3260 2820 50  0000 L CNN
F 1 "C_Small" H 3260 2670 50  0000 L CNN
F 2 "digikey-footprints:0805" H 3250 2750 50  0001 C CNN
F 3 "" H 3250 2750 50  0001 C CNN
	1    3250 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR068
U 1 1 5C75CFDD
P 3250 2850
F 0 "#PWR068" H 3250 2600 50  0001 C CNN
F 1 "GND" H 3250 2700 50  0000 C CNN
F 2 "" H 3250 2850 50  0001 C CNN
F 3 "" H 3250 2850 50  0001 C CNN
	1    3250 2850
	1    0    0    -1  
$EndComp
$Comp
L C_Small C7
U 1 1 5C75D12C
P 2000 2750
F 0 "C7" H 2010 2820 50  0000 L CNN
F 1 "C_Small" H 2010 2670 50  0000 L CNN
F 2 "digikey-footprints:0805" H 2000 2750 50  0001 C CNN
F 3 "" H 2000 2750 50  0001 C CNN
	1    2000 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR069
U 1 1 5C75D133
P 2000 2850
F 0 "#PWR069" H 2000 2600 50  0001 C CNN
F 1 "GND" H 2000 2700 50  0000 C CNN
F 2 "" H 2000 2850 50  0001 C CNN
F 3 "" H 2000 2850 50  0001 C CNN
	1    2000 2850
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 5C75D50F
P 850 2750
F 0 "C3" H 860 2820 50  0000 L CNN
F 1 "C_Small" H 860 2670 50  0000 L CNN
F 2 "digikey-footprints:0805" H 850 2750 50  0001 C CNN
F 3 "" H 850 2750 50  0001 C CNN
	1    850  2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR070
U 1 1 5C75D516
P 850 2850
F 0 "#PWR070" H 850 2600 50  0001 C CNN
F 1 "GND" H 850 2700 50  0000 C CNN
F 2 "" H 850 2850 50  0001 C CNN
F 3 "" H 850 2850 50  0001 C CNN
	1    850  2850
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 5C75D5A7
P 850 4050
F 0 "C6" H 860 4120 50  0000 L CNN
F 1 "C_Small" H 860 3970 50  0000 L CNN
F 2 "digikey-footprints:0805" H 850 4050 50  0001 C CNN
F 3 "" H 850 4050 50  0001 C CNN
	1    850  4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR071
U 1 1 5C75D5AE
P 850 4150
F 0 "#PWR071" H 850 3900 50  0001 C CNN
F 1 "GND" H 850 4000 50  0000 C CNN
F 2 "" H 850 4150 50  0001 C CNN
F 3 "" H 850 4150 50  0001 C CNN
	1    850  4150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C10
U 1 1 5C75D662
P 2000 4050
F 0 "C10" H 2010 4120 50  0000 L CNN
F 1 "C_Small" H 2010 3970 50  0000 L CNN
F 2 "digikey-footprints:0805" H 2000 4050 50  0001 C CNN
F 3 "" H 2000 4050 50  0001 C CNN
	1    2000 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR072
U 1 1 5C75D669
P 2000 4150
F 0 "#PWR072" H 2000 3900 50  0001 C CNN
F 1 "GND" H 2000 4000 50  0000 C CNN
F 2 "" H 2000 4150 50  0001 C CNN
F 3 "" H 2000 4150 50  0001 C CNN
	1    2000 4150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C14
U 1 1 5C75DCDF
P 3250 4050
F 0 "C14" H 3260 4120 50  0000 L CNN
F 1 "C_Small" H 3260 3970 50  0000 L CNN
F 2 "digikey-footprints:0805" H 3250 4050 50  0001 C CNN
F 3 "" H 3250 4050 50  0001 C CNN
	1    3250 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR073
U 1 1 5C75DCE6
P 3250 4150
F 0 "#PWR073" H 3250 3900 50  0001 C CNN
F 1 "GND" H 3250 4000 50  0000 C CNN
F 2 "" H 3250 4150 50  0001 C CNN
F 3 "" H 3250 4150 50  0001 C CNN
	1    3250 4150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C12
U 1 1 5C75E09C
P 3250 5350
F 0 "C12" H 3260 5420 50  0000 L CNN
F 1 "C_Small" H 3260 5270 50  0000 L CNN
F 2 "digikey-footprints:0805" H 3250 5350 50  0001 C CNN
F 3 "" H 3250 5350 50  0001 C CNN
	1    3250 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR074
U 1 1 5C75E0A3
P 3250 5450
F 0 "#PWR074" H 3250 5200 50  0001 C CNN
F 1 "GND" H 3250 5300 50  0000 C CNN
F 2 "" H 3250 5450 50  0001 C CNN
F 3 "" H 3250 5450 50  0001 C CNN
	1    3250 5450
	1    0    0    -1  
$EndComp
$Comp
L C_Small C8
U 1 1 5C75E12A
P 2000 5350
F 0 "C8" H 2010 5420 50  0000 L CNN
F 1 "C_Small" H 2010 5270 50  0000 L CNN
F 2 "digikey-footprints:0805" H 2000 5350 50  0001 C CNN
F 3 "" H 2000 5350 50  0001 C CNN
	1    2000 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR075
U 1 1 5C75E131
P 2000 5450
F 0 "#PWR075" H 2000 5200 50  0001 C CNN
F 1 "GND" H 2000 5300 50  0000 C CNN
F 2 "" H 2000 5450 50  0001 C CNN
F 3 "" H 2000 5450 50  0001 C CNN
	1    2000 5450
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 5C75E4F7
P 850 5350
F 0 "C4" H 860 5420 50  0000 L CNN
F 1 "C_Small" H 860 5270 50  0000 L CNN
F 2 "digikey-footprints:0805" H 850 5350 50  0001 C CNN
F 3 "" H 850 5350 50  0001 C CNN
	1    850  5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR076
U 1 1 5C75E4FE
P 850 5450
F 0 "#PWR076" H 850 5200 50  0001 C CNN
F 1 "GND" H 850 5300 50  0000 C CNN
F 2 "" H 850 5450 50  0001 C CNN
F 3 "" H 850 5450 50  0001 C CNN
	1    850  5450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR077
U 1 1 5C75E853
P 4300 950
F 0 "#PWR077" H 4300 800 50  0001 C CNN
F 1 "+5V" H 4300 1090 50  0000 C CNN
F 2 "" H 4300 950 50  0001 C CNN
F 3 "" H 4300 950 50  0001 C CNN
	1    4300 950 
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR078
U 1 1 5C75E975
P 4300 1150
F 0 "#PWR078" H 4300 900 50  0001 C CNN
F 1 "GND" H 4300 1000 50  0000 C CNN
F 2 "" H 4300 1150 50  0001 C CNN
F 3 "" H 4300 1150 50  0001 C CNN
	1    4300 1150
	1    0    0    -1  
$EndComp
$Comp
L CP1_Small C2
U 1 1 5C75EB8F
P 4300 1050
F 0 "C2" H 4310 1120 50  0000 L CNN
F 1 "10uF" H 4310 970 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P5.00mm" H 4300 1050 50  0001 C CNN
F 3 "" H 4300 1050 50  0001 C CNN
	1    4300 1050
	1    0    0    -1  
$EndComp
Text Notes 3650 7900 0    60   ~ 0
Global FB knob
Wire Wire Line
	1500 6050 1800 6050
Connection ~ 1800 6050
Wire Wire Line
	2300 6050 2650 6050
Wire Wire Line
	2650 6050 2650 6300
Connection ~ 2650 6300
Wire Wire Line
	2250 6600 2650 6600
Wire Wire Line
	2650 6600 2650 6850
Connection ~ 2650 6850
Wire Wire Line
	2250 7100 2650 7100
Wire Wire Line
	2650 7100 2650 7350
Connection ~ 2650 7350
Wire Wire Line
	2250 7550 2650 7550
Wire Wire Line
	2650 7550 2650 7800
Connection ~ 2650 7800
Wire Wire Line
	1400 7550 1800 7550
Connection ~ 1800 7550
Wire Wire Line
	1400 7100 1800 7100
Connection ~ 1800 7100
Wire Wire Line
	1400 6600 1800 6600
Connection ~ 1800 6600
$EndSCHEMATC
