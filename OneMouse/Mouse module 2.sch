EESchema Schematic File Version 4
EELAYER 30 0
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
Text GLabel 1550 4450 0    50   Input ~ 0
GPIO11(SCLK)
Text GLabel 1550 5000 0    50   Input ~ 0
GPIO10(MOSI)
Text GLabel 2350 4450 2    50   Input ~ 0
SCK
Text GLabel 2350 5000 2    50   Input ~ 0
SDI
Text GLabel 2350 5550 2    50   Input ~ 0
GATE
Text GLabel 2350 6100 2    50   Input ~ 0
TRIG
$Comp
L Device:C_Small C5
U 1 1 5FAA2A19
P 4700 3250
F 0 "C5" V 4471 3250 50  0000 C CNN
F 1 "0.1uF" V 4562 3250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4700 3250 50  0001 C CNN
F 3 "~" H 4700 3250 50  0001 C CNN
	1    4700 3250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FAA3016
P 4350 3450
F 0 "#PWR013" H 4350 3200 50  0001 C CNN
F 1 "GND" H 4355 3277 50  0000 C CNN
F 2 "" H 4350 3450 50  0001 C CNN
F 3 "" H 4350 3450 50  0001 C CNN
	1    4350 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5FAA33D3
P 4000 3250
F 0 "C3" V 3771 3250 50  0000 C CNN
F 1 "0.1uF" V 3862 3250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4000 3250 50  0001 C CNN
F 3 "~" H 4000 3250 50  0001 C CNN
	1    4000 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 3150 4000 3100
Wire Wire Line
	4000 3100 4050 3100
Wire Wire Line
	4000 3050 4000 3100
Connection ~ 4000 3100
Wire Wire Line
	4700 3150 4700 3100
Wire Wire Line
	4700 3100 4650 3100
Wire Wire Line
	4700 3100 4700 3050
Connection ~ 4700 3100
Wire Wire Line
	4700 3400 4700 3350
Wire Wire Line
	4000 3350 4000 3400
$Comp
L power:-12V #PWR08
U 1 1 5FBFC8A7
P 4000 3050
F 0 "#PWR08" H 4000 3150 50  0001 C CNN
F 1 "-12V" H 4015 3223 50  0000 C CNN
F 2 "" H 4000 3050 50  0001 C CNN
F 3 "" H 4000 3050 50  0001 C CNN
	1    4000 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR014
U 1 1 5FBFD9A1
P 4700 3050
F 0 "#PWR014" H 4700 2900 50  0001 C CNN
F 1 "+12V" H 4715 3223 50  0000 C CNN
F 2 "" H 4700 3050 50  0001 C CNN
F 3 "" H 4700 3050 50  0001 C CNN
	1    4700 3050
	1    0    0    -1  
$EndComp
Text GLabel 1550 5550 0    50   Input ~ 0
GPIO5
Text GLabel 1550 6100 0    50   Input ~ 0
GPIO6
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J2
U 1 1 5FA94DC4
P 4400 5150
F 0 "J2" H 4450 4525 50  0000 C CNN
F 1 "02x08_IDC" H 4450 4616 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x08_P2.54mm_Vertical" H 4400 5150 50  0001 C CNN
F 3 "~" H 4400 5150 50  0001 C CNN
	1    4400 5150
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR010
U 1 1 5FA9EF2C
P 4050 5600
F 0 "#PWR010" H 4050 5700 50  0001 C CNN
F 1 "-12V" H 4065 5773 50  0000 C CNN
F 2 "" H 4050 5600 50  0001 C CNN
F 3 "" H 4050 5600 50  0001 C CNN
	1    4050 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 5450 4050 5450
Wire Wire Line
	4050 5450 4050 5550
Wire Wire Line
	4600 5150 4650 5150
Wire Wire Line
	4650 5150 4650 5250
Wire Wire Line
	4650 5350 4600 5350
Wire Wire Line
	4600 5250 4650 5250
Connection ~ 4650 5250
Wire Wire Line
	4650 5250 4650 5350
Wire Wire Line
	4100 5150 4050 5150
Wire Wire Line
	4050 5150 4050 5250
Wire Wire Line
	4050 5350 4100 5350
Wire Wire Line
	4100 5250 4050 5250
Connection ~ 4050 5250
Wire Wire Line
	4050 5250 4050 5350
Wire Wire Line
	4050 5600 4050 5550
Connection ~ 4050 5550
Wire Wire Line
	4050 5550 4400 5550
$Comp
L power:GND #PWR07
U 1 1 5FAE2E12
P 3750 5900
F 0 "#PWR07" H 3750 5650 50  0001 C CNN
F 1 "GND" H 3755 5727 50  0000 C CNN
F 2 "" H 3750 5900 50  0001 C CNN
F 3 "" H 3750 5900 50  0001 C CNN
	1    3750 5900
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR06
U 1 1 5FB0E9AF
P 3750 4300
F 0 "#PWR06" H 3750 4150 50  0001 C CNN
F 1 "+12V" H 3765 4473 50  0000 C CNN
F 2 "" H 3750 4300 50  0001 C CNN
F 3 "" H 3750 4300 50  0001 C CNN
	1    3750 4300
	1    0    0    -1  
$EndComp
NoConn ~ 4100 4750
NoConn ~ 4100 4850
NoConn ~ 4600 4750
NoConn ~ 4600 4850
$Comp
L power:+5V #PWR09
U 1 1 5FBA89DF
P 4000 4600
F 0 "#PWR09" H 4000 4450 50  0001 C CNN
F 1 "+5V" H 4015 4773 50  0000 C CNN
F 2 "" H 4000 4600 50  0001 C CNN
F 3 "" H 4000 4600 50  0001 C CNN
	1    4000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4650 4000 4650
Wire Wire Line
	4000 4650 4000 4950
Wire Wire Line
	4000 4950 4100 4950
Wire Wire Line
	4000 4600 4000 4650
Connection ~ 4000 4650
Wire Notes Line
	550  7600 3500 7600
Wire Notes Line
	3500 3950 550  3950
Wire Notes Line
	550  3950 550  7600
Wire Notes Line
	3500 3950 3500 7600
Text Notes 550  3950 0    50   ~ 0
Level Shift
Text Notes 3550 3950 0    50   ~ 0
Power & Connectors
$Comp
L power:PWR_FLAG #FLG03
U 1 1 5FD57C6E
P 4700 4600
F 0 "#FLG03" H 4700 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 4700 4773 50  0000 C CNN
F 2 "" H 4700 4600 50  0001 C CNN
F 3 "~" H 4700 4600 50  0001 C CNN
	1    4700 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4600 4700 4650
$Comp
L power:PWR_FLAG #FLG04
U 1 1 5FD647C3
P 4700 4300
F 0 "#FLG04" H 4700 4375 50  0001 C CNN
F 1 "PWR_FLAG" H 4700 4473 50  0000 C CNN
F 2 "" H 4700 4300 50  0001 C CNN
F 3 "~" H 4700 4300 50  0001 C CNN
	1    4700 4300
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG05
U 1 1 5FD712D7
P 4950 5900
F 0 "#FLG05" H 4950 5975 50  0001 C CNN
F 1 "PWR_FLAG" H 4950 6073 50  0000 C CNN
F 2 "" H 4950 5900 50  0001 C CNN
F 3 "~" H 4950 5900 50  0001 C CNN
	1    4950 5900
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5FD7E572
P 4400 5600
F 0 "#FLG02" H 4400 5675 50  0001 C CNN
F 1 "PWR_FLAG" H 4400 5773 50  0000 C CNN
F 2 "" H 4400 5600 50  0001 C CNN
F 3 "~" H 4400 5600 50  0001 C CNN
	1    4400 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 5600 4400 5550
Wire Wire Line
	3750 5050 3750 4350
Wire Wire Line
	3750 4350 4700 4350
Wire Wire Line
	3750 5050 4100 5050
Wire Wire Line
	3750 5150 3750 5850
Wire Wire Line
	3750 5850 4950 5850
Wire Wire Line
	4950 5850 4950 5150
Wire Wire Line
	3750 4300 3750 4350
Connection ~ 3750 4350
Wire Wire Line
	4700 4300 4700 4350
Wire Wire Line
	3750 5150 4050 5150
Connection ~ 4050 5150
Wire Wire Line
	4950 5150 4650 5150
Connection ~ 4650 5150
Wire Wire Line
	4950 5900 4950 5850
Connection ~ 4950 5850
Wire Wire Line
	3750 5900 3750 5850
Connection ~ 3750 5850
$Comp
L Analog_DAC:MCP4922 U3
U 1 1 5FA4D1CA
P 5150 1800
F 0 "U3" H 5150 2381 50  0000 C CNN
F 1 "MCP4922" H 5150 2290 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5950 1500 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22250A.pdf" H 5950 1500 50  0001 C CNN
	1    5150 1800
	1    0    0    -1  
$EndComp
NoConn ~ 2250 1500
NoConn ~ 2250 1600
NoConn ~ 2250 1700
NoConn ~ 2250 2200
NoConn ~ 2250 2500
NoConn ~ 2250 2700
NoConn ~ 2250 2900
NoConn ~ 2250 3000
NoConn ~ 2250 3100
NoConn ~ 1750 2900
NoConn ~ 1750 2800
NoConn ~ 1750 2500
NoConn ~ 1750 2200
NoConn ~ 1750 1900
NoConn ~ 1750 1800
NoConn ~ 1750 1700
NoConn ~ 1750 1500
NoConn ~ 1750 1400
NoConn ~ 1750 1300
Text GLabel 1650 2600 0    50   Input ~ 0
GPIO5
Wire Wire Line
	1750 2600 1650 2600
Text GLabel 1650 2700 0    50   Input ~ 0
GPIO6
Wire Wire Line
	1650 2700 1750 2700
Text GLabel 1650 3000 0    50   Input ~ 0
GPIO26
Wire Wire Line
	1750 3000 1650 3000
Wire Notes Line
	7450 650  3550 650 
Wire Notes Line
	7450 3800 7450 650 
Wire Notes Line
	3550 3800 7450 3800
Wire Notes Line
	3550 650  3550 3800
Wire Wire Line
	5850 3350 5850 3400
Wire Wire Line
	5900 1700 5650 1700
Wire Wire Line
	3950 1900 4350 1900
Wire Wire Line
	3950 1850 3950 1900
Wire Wire Line
	3950 1600 4350 1600
Wire Wire Line
	3950 1650 3950 1600
$Comp
L Device:C_Small C2
U 1 1 5FC37CD2
P 3950 1750
F 0 "C2" H 3859 1704 50  0000 R CNN
F 1 "10uF" H 3859 1795 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 3950 1750 50  0001 C CNN
F 3 "~" H 3950 1750 50  0001 C CNN
	1    3950 1750
	1    0    0    1   
$EndComp
Wire Wire Line
	4350 1850 4350 1900
Wire Wire Line
	4350 1650 4350 1600
$Comp
L Device:C_Small C4
U 1 1 5FC2D6E0
P 4350 1750
F 0 "C4" H 4259 1704 50  0000 R CNN
F 1 "0.1uF" H 4259 1795 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4350 1750 50  0001 C CNN
F 3 "~" H 4350 1750 50  0001 C CNN
	1    4350 1750
	1    0    0    1   
$EndComp
Text GLabel 4650 1800 0    50   Input ~ 0
SCK
$Comp
L power:-12V #PWR024
U 1 1 5FBB05B7
P 6200 2050
F 0 "#PWR024" H 6200 2150 50  0001 C CNN
F 1 "-12V" H 6215 2223 50  0000 C CNN
F 2 "" H 6200 2050 50  0001 C CNN
F 3 "" H 6200 2050 50  0001 C CNN
	1    6200 2050
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR016
U 1 1 5FBAFEA1
P 5350 2900
F 0 "#PWR016" H 5350 3000 50  0001 C CNN
F 1 "-12V" H 5365 3073 50  0000 C CNN
F 2 "" H 5350 2900 50  0001 C CNN
F 3 "" H 5350 2900 50  0001 C CNN
	1    5350 2900
	-1   0    0    1   
$EndComp
Text Notes 3550 650  0    50   ~ 0
DAC
Text GLabel 4650 2000 0    50   Input ~ 0
SDI
Text GLabel 7050 2900 2    50   Input ~ 0
CV_Y
Text GLabel 7050 1600 2    50   Input ~ 0
CV_X
Wire Wire Line
	5950 2400 5950 2000
Wire Wire Line
	7000 2900 7050 2900
Wire Wire Line
	7000 2900 6900 2900
Connection ~ 7000 2900
Wire Wire Line
	7000 3350 7000 2900
Wire Wire Line
	6200 3350 6550 3350
Wire Wire Line
	6200 3000 6300 3000
Wire Wire Line
	6200 3350 6200 3000
Connection ~ 6200 3350
Wire Wire Line
	6100 3350 6200 3350
Wire Wire Line
	5850 3350 5900 3350
$Comp
L power:GND #PWR023
U 1 1 5F9BA98C
P 5850 3400
F 0 "#PWR023" H 5850 3150 50  0001 C CNN
F 1 "GND" H 5855 3227 50  0000 C CNN
F 2 "" H 5850 3400 50  0001 C CNN
F 3 "" H 5850 3400 50  0001 C CNN
	1    5850 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3350 7000 3350
$Comp
L Device:R_Small R10
U 1 1 5F9BA981
P 6650 3350
F 0 "R10" V 6454 3350 50  0000 C CNN
F 1 "5.6k" V 6545 3350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6650 3350 50  0001 C CNN
F 3 "~" H 6650 3350 50  0001 C CNN
	1    6650 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5F9BA97B
P 6000 3350
F 0 "R7" V 5804 3350 50  0000 C CNN
F 1 "3.9k" V 5895 3350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6000 3350 50  0001 C CNN
F 3 "~" H 6000 3350 50  0001 C CNN
	1    6000 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	5350 2800 5450 2800
Wire Wire Line
	5350 2900 5350 2800
Wire Wire Line
	6300 2800 5950 2800
Wire Wire Line
	5650 2800 5950 2800
Connection ~ 5950 2800
Wire Wire Line
	5950 2600 5950 2800
$Comp
L Device:R_Small R3
U 1 1 5F9AF611
P 5550 2800
F 0 "R3" V 5354 2800 50  0000 C CNN
F 1 "33k" V 5445 2800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5550 2800 50  0001 C CNN
F 3 "~" H 5550 2800 50  0001 C CNN
	1    5550 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 2000 5650 2000
Wire Wire Line
	6200 2050 6200 2000
Wire Wire Line
	5850 1100 5900 1100
Wire Wire Line
	5850 1150 5850 1100
$Comp
L power:GND #PWR022
U 1 1 5F9A46E1
P 5850 1150
F 0 "#PWR022" H 5850 900 50  0001 C CNN
F 1 "GND" H 5855 977 50  0000 C CNN
F 2 "" H 5850 1150 50  0001 C CNN
F 3 "" H 5850 1150 50  0001 C CNN
	1    5850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1600 7050 1600
Wire Wire Line
	7000 1600 6900 1600
Connection ~ 7000 1600
Wire Wire Line
	7000 1100 7000 1600
Wire Wire Line
	6750 1100 7000 1100
Wire Wire Line
	6200 1100 6100 1100
Wire Wire Line
	6200 1500 6200 1100
Wire Wire Line
	6300 1500 6200 1500
Connection ~ 6200 1100
Wire Wire Line
	6550 1100 6200 1100
Wire Wire Line
	6300 1700 6200 1700
Wire Wire Line
	6200 1700 6100 1700
Connection ~ 6200 1700
Wire Wire Line
	6200 1800 6200 1700
$Comp
L Device:R_Small R8
U 1 1 5F991806
P 6200 1900
F 0 "R8" H 6141 1854 50  0000 R CNN
F 1 "33k" H 6141 1945 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6200 1900 50  0001 C CNN
F 3 "~" H 6200 1900 50  0001 C CNN
	1    6200 1900
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R4
U 1 1 5F985BD1
P 5950 2500
F 0 "R4" H 6009 2546 50  0000 L CNN
F 1 "6.8k" H 6009 2455 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5950 2500 50  0001 C CNN
F 3 "~" H 5950 2500 50  0001 C CNN
	1    5950 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R9
U 1 1 5F9857B0
P 6650 1100
F 0 "R9" V 6454 1100 50  0000 C CNN
F 1 "5.6k" V 6545 1100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6650 1100 50  0001 C CNN
F 3 "~" H 6650 1100 50  0001 C CNN
	1    6650 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R5
U 1 1 5F9854FB
P 6000 1100
F 0 "R5" V 5804 1100 50  0000 C CNN
F 1 "3.9k" V 5895 1100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6000 1100 50  0001 C CNN
F 3 "~" H 6000 1100 50  0001 C CNN
	1    6000 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R6
U 1 1 5F984F60
P 6000 1700
F 0 "R6" V 5804 1700 50  0000 C CNN
F 1 "6.8k" V 5895 1700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6000 1700 50  0001 C CNN
F 3 "~" H 6000 1700 50  0001 C CNN
	1    6000 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 2100 5700 2100
Wire Wire Line
	5700 2100 5700 1600
Wire Wire Line
	5700 1600 5700 1350
Connection ~ 5700 1600
Wire Wire Line
	5650 1600 5700 1600
Connection ~ 4350 1600
Wire Wire Line
	4350 1350 4350 1600
Wire Wire Line
	5700 1350 5150 1350
Wire Wire Line
	5150 1350 4350 1350
Connection ~ 5150 1350
Wire Wire Line
	5150 1400 5150 1350
Connection ~ 4350 1350
Wire Wire Line
	4350 1300 4350 1350
Connection ~ 4350 1900
Wire Wire Line
	4350 1900 4650 1900
Wire Wire Line
	4350 2350 4350 2100
Wire Wire Line
	5150 2350 5150 2300
Wire Wire Line
	4350 2350 5150 2350
Connection ~ 4350 2350
Wire Wire Line
	4350 2350 4350 2400
$Comp
L power:GND #PWR012
U 1 1 5F9A4F16
P 4350 2400
F 0 "#PWR012" H 4350 2150 50  0001 C CNN
F 1 "GND" H 4355 2227 50  0000 C CNN
F 2 "" H 4350 2400 50  0001 C CNN
F 3 "" H 4350 2400 50  0001 C CNN
	1    4350 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1600 4650 1600
$Comp
L power:+5V #PWR011
U 1 1 5F9A040C
P 4350 1300
F 0 "#PWR011" H 4350 1150 50  0001 C CNN
F 1 "+5V" H 4365 1473 50  0000 C CNN
F 2 "" H 4350 1300 50  0001 C CNN
F 3 "" H 4350 1300 50  0001 C CNN
	1    4350 1300
	1    0    0    -1  
$EndComp
Text Notes 550  650  0    50   ~ 0
Raspberry Pi Zero GPIO Header
Wire Notes Line
	3500 650  550  650 
Wire Notes Line
	3500 3800 3500 650 
Wire Notes Line
	550  3800 3500 3800
Wire Notes Line
	550  650  550  3800
Wire Wire Line
	3200 2800 3200 3350
Connection ~ 3200 2800
Wire Wire Line
	2250 2800 3200 2800
Wire Wire Line
	3200 2600 3200 2800
Connection ~ 3200 2600
Wire Wire Line
	2250 2600 3200 2600
Wire Wire Line
	3200 2100 3200 2600
Connection ~ 3200 2100
Wire Wire Line
	2250 2100 3200 2100
Wire Wire Line
	3200 1800 3200 2100
Wire Wire Line
	3200 1800 3200 1400
Connection ~ 3200 1800
Wire Wire Line
	2250 1800 3200 1800
Wire Wire Line
	2250 1400 3200 1400
Wire Wire Line
	2000 3350 2000 3500
Connection ~ 2000 3350
Wire Wire Line
	800  3350 2000 3350
Wire Wire Line
	3200 1200 3200 1300
Wire Wire Line
	800  1600 1750 1600
Wire Wire Line
	800  1600 800  2400
Connection ~ 800  2400
Wire Wire Line
	800  2400 1750 2400
Wire Wire Line
	800  3100 800  3350
Wire Wire Line
	800  2400 800  3100
Connection ~ 800  3100
Wire Wire Line
	800  3100 1750 3100
Wire Wire Line
	1650 2300 1750 2300
Wire Wire Line
	1650 2100 1750 2100
Text GLabel 1650 2300 0    50   Input ~ 0
GPIO11(SCLK)
Text GLabel 1650 2100 0    50   Input ~ 0
GPIO10(MOSI)
$Comp
L power:GND #PWR03
U 1 1 5F973765
P 2000 3500
F 0 "#PWR03" H 2000 3250 50  0001 C CNN
F 1 "GND" H 2005 3327 50  0000 C CNN
F 2 "" H 2000 3500 50  0001 C CNN
F 3 "" H 2000 3500 50  0001 C CNN
	1    2000 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR05
U 1 1 5F96FD09
P 3200 1200
F 0 "#PWR05" H 3200 1050 50  0001 C CNN
F 1 "+5V" H 3215 1373 50  0000 C CNN
F 2 "" H 3200 1200 50  0001 C CNN
F 3 "" H 3200 1200 50  0001 C CNN
	1    3200 1200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J1
U 1 1 5F96B64B
P 1950 2100
F 0 "J1" H 2000 3217 50  0000 C CNN
F 1 "Conn_02x20_Odd_Even" H 2000 3126 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x20_P2.54mm_Vertical" H 1950 2100 50  0001 C CNN
F 3 "~" H 1950 2100 50  0001 C CNN
	1    1950 2100
	1    0    0    -1  
$EndComp
Text GLabel 5600 4500 0    50   Input ~ 0
CV_X
Text GLabel 5600 4950 0    50   Input ~ 0
CV_Y
Text GLabel 5600 5400 0    50   Input ~ 0
GATE
Text GLabel 5600 5850 0    50   Input ~ 0
TRIG
$Comp
L Device:R_Small R2
U 1 1 5FAF19A6
P 5400 7050
F 0 "R2" H 5341 7004 50  0000 R CNN
F 1 "5.6k" H 5341 7095 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5400 7050 50  0001 C CNN
F 3 "~" H 5400 7050 50  0001 C CNN
	1    5400 7050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5FB00468
P 5400 7150
F 0 "#PWR017" H 5400 6900 50  0001 C CNN
F 1 "GND" H 5405 6977 50  0000 C CNN
F 2 "" H 5400 7150 50  0001 C CNN
F 3 "" H 5400 7150 50  0001 C CNN
	1    5400 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 6900 5150 6900
$Comp
L Device:R_Small R1
U 1 1 5FAC6AAC
P 5250 6900
F 0 "R1" V 5054 6900 50  0000 C CNN
F 1 "2.7k" V 5145 6900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5250 6900 50  0001 C CNN
F 3 "~" H 5250 6900 50  0001 C CNN
	1    5250 6900
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 6900 5350 6900
Wire Wire Line
	5400 6950 5400 6900
Text GLabel 5600 6900 2    50   Input ~ 0
GPIO26
Wire Wire Line
	5600 6900 5400 6900
Connection ~ 5400 6900
Text Notes 4850 7000 0    50   ~ 0
CLK_IN
Text Notes 1100 2650 0    50   ~ 0
GATE0
Text Notes 1100 2750 0    50   ~ 0
TRIG0
Text Notes 1050 3050 0    50   ~ 0
CLK_IN
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5FA611DC
P 8700 1650
F 0 "H1" V 8937 1653 50  0000 C CNN
F 1 "MountingHole_Pad" V 8846 1653 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_Pad" H 8700 1650 50  0001 C CNN
F 3 "~" H 8700 1650 50  0001 C CNN
	1    8700 1650
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5FA62107
P 8700 2050
F 0 "H2" V 8937 2053 50  0000 C CNN
F 1 "MountingHole_Pad" V 8846 2053 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_Pad" H 8700 2050 50  0001 C CNN
F 3 "~" H 8700 2050 50  0001 C CNN
	1    8700 2050
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5FA624EA
P 8700 2450
F 0 "H3" V 8937 2453 50  0000 C CNN
F 1 "MountingHole_Pad" V 8846 2453 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_Pad" H 8700 2450 50  0001 C CNN
F 3 "~" H 8700 2450 50  0001 C CNN
	1    8700 2450
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5FA62954
P 8700 2850
F 0 "H4" V 8937 2853 50  0000 C CNN
F 1 "MountingHole_Pad" V 8846 2853 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_Pad" H 8700 2850 50  0001 C CNN
F 3 "~" H 8700 2850 50  0001 C CNN
	1    8700 2850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5FA62CE2
P 9150 2950
F 0 "#PWR025" H 9150 2700 50  0001 C CNN
F 1 "GND" H 9155 2777 50  0000 C CNN
F 2 "" H 9150 2950 50  0001 C CNN
F 3 "" H 9150 2950 50  0001 C CNN
	1    9150 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 2950 9150 2850
Wire Wire Line
	9150 2850 8800 2850
Wire Wire Line
	8800 2450 9150 2450
Wire Wire Line
	9150 2450 9150 2850
Connection ~ 9150 2850
Wire Wire Line
	8800 2050 9150 2050
Wire Wire Line
	9150 2050 9150 2450
Connection ~ 9150 2450
Wire Wire Line
	8800 1650 9150 1650
Wire Wire Line
	9150 1650 9150 2050
Connection ~ 9150 2050
$Comp
L Amplifier_Operational:TL072 U2
U 1 1 5FADD140
P 6600 1600
F 0 "U2" H 6600 1233 50  0000 C CNN
F 1 "TL072" H 6600 1324 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6600 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6600 1600 50  0001 C CNN
	1    6600 1600
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:TL072 U2
U 2 1 5FAE101F
P 6600 2900
F 0 "U2" H 6600 3267 50  0000 C CNN
F 1 "TL072" H 6600 3176 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6600 2900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6600 2900 50  0001 C CNN
	2    6600 2900
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U2
U 3 1 5FAE2E34
P 4350 3200
F 0 "U2" V 4025 3200 50  0000 C CNN
F 1 "TL072" V 4116 3200 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 4350 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4350 3200 50  0001 C CNN
	3    4350 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 3400 4350 3400
Wire Wire Line
	4350 3450 4350 3400
Connection ~ 4350 3400
Wire Wire Line
	4350 3400 4700 3400
NoConn ~ 2250 2300
NoConn ~ 2250 2400
NoConn ~ 2250 1900
NoConn ~ 2250 2000
Wire Wire Line
	4650 2100 4350 2100
Connection ~ 4350 2100
Wire Wire Line
	4350 2100 4350 1900
$Comp
L 74xx:74LS125 U1
U 1 1 5FC6C3A7
P 1950 4450
F 0 "U1" H 1950 4767 50  0000 C CNN
F 1 "74LS125" H 1950 4676 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1950 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 1950 4450 50  0001 C CNN
	1    1950 4450
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 2 1 5FC741C3
P 1950 5000
F 0 "U1" H 2050 5200 50  0000 C CNN
F 1 "74LS125" H 2150 5100 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1950 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 1950 5000 50  0001 C CNN
	2    1950 5000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 3 1 5FC83CFF
P 1950 5550
F 0 "U1" H 2050 5750 50  0000 C CNN
F 1 "74LS125" H 2150 5650 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1950 5550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 1950 5550 50  0001 C CNN
	3    1950 5550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 4 1 5FC84F95
P 1950 6100
F 0 "U1" H 2050 6300 50  0000 C CNN
F 1 "74LS125" H 2150 6200 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1950 6100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 1950 6100 50  0001 C CNN
	4    1950 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 5800 1950 5850
Wire Wire Line
	1950 5850 2750 5850
Wire Wire Line
	2750 5850 2750 6400
Wire Wire Line
	2750 6400 1950 6400
Wire Wire Line
	1950 6400 1950 6350
Wire Wire Line
	1950 5250 1950 5300
Wire Wire Line
	1950 5300 2750 5300
Wire Wire Line
	2750 5300 2750 5850
Connection ~ 2750 5850
Wire Wire Line
	1950 4700 1950 4750
Wire Wire Line
	1950 4750 2750 4750
Wire Wire Line
	2750 4750 2750 5300
Connection ~ 2750 5300
Wire Wire Line
	1650 4450 1550 4450
Wire Wire Line
	2250 4450 2350 4450
Wire Wire Line
	2350 5000 2250 5000
Wire Wire Line
	1650 5000 1550 5000
Wire Wire Line
	1550 5550 1650 5550
Wire Wire Line
	2250 5550 2350 5550
Wire Wire Line
	2350 6100 2250 6100
Wire Wire Line
	1650 6100 1550 6100
$Comp
L power:GND #PWR04
U 1 1 5FD249DA
P 2750 7300
F 0 "#PWR04" H 2750 7050 50  0001 C CNN
F 1 "GND" H 2755 7127 50  0000 C CNN
F 2 "" H 2750 7300 50  0001 C CNN
F 3 "" H 2750 7300 50  0001 C CNN
	1    2750 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 7300 2750 7150
Connection ~ 2750 6400
$Comp
L 74xx:74LS125 U1
U 5 1 5FD38412
P 1900 6850
F 0 "U1" V 2267 6850 50  0000 C CNN
F 1 "74LS125" V 2176 6850 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 1900 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 1900 6850 50  0001 C CNN
	5    1900 6850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2750 6850 2400 6850
Connection ~ 2750 6850
Wire Wire Line
	2750 6850 2750 6400
$Comp
L power:+5V #PWR02
U 1 1 5FD61B1E
P 1350 6750
F 0 "#PWR02" H 1350 6600 50  0001 C CNN
F 1 "+5V" H 1365 6923 50  0000 C CNN
F 2 "" H 1350 6750 50  0001 C CNN
F 3 "" H 1350 6750 50  0001 C CNN
	1    1350 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 6850 1400 6850
$Comp
L Device:C_Small C1
U 1 1 5FD92074
P 1900 7150
F 0 "C1" V 2037 7150 50  0000 C CNN
F 1 "0.1uF" V 2128 7150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 1900 7150 50  0001 C CNN
F 3 "~" H 1900 7150 50  0001 C CNN
	1    1900 7150
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 7150 1350 7150
Wire Wire Line
	1350 6750 1350 6850
Connection ~ 1350 6850
Wire Wire Line
	1350 6850 1350 7150
Wire Wire Line
	2000 7150 2750 7150
Connection ~ 2750 7150
Wire Wire Line
	2750 7150 2750 6850
$Comp
L Connector:AudioJack3 J4
U 1 1 5FDC84D6
P 5900 4400
F 0 "J4" H 5620 4425 50  0000 R CNN
F 1 "AudioJack3" H 5620 4334 50  0000 R CNN
F 2 "SJ1-3533:CUI_SJ1-3533" H 5900 4400 50  0001 C CNN
F 3 "~" H 5900 4400 50  0001 C CNN
	1    5900 4400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5600 4500 5700 4500
NoConn ~ 5700 4400
$Comp
L power:GND #PWR018
U 1 1 5FDDD8EA
P 5600 4300
F 0 "#PWR018" H 5600 4050 50  0001 C CNN
F 1 "GND" V 5605 4172 50  0000 R CNN
F 2 "" H 5600 4300 50  0001 C CNN
F 3 "" H 5600 4300 50  0001 C CNN
	1    5600 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 4300 5700 4300
$Comp
L Connector:AudioJack3 J5
U 1 1 5FDE90FD
P 5900 4850
F 0 "J5" H 5620 4875 50  0000 R CNN
F 1 "AudioJack3" H 5620 4784 50  0000 R CNN
F 2 "SJ1-3533:CUI_SJ1-3533" H 5900 4850 50  0001 C CNN
F 3 "~" H 5900 4850 50  0001 C CNN
	1    5900 4850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5600 4950 5700 4950
NoConn ~ 5700 4850
$Comp
L power:GND #PWR019
U 1 1 5FDE9105
P 5600 4750
F 0 "#PWR019" H 5600 4500 50  0001 C CNN
F 1 "GND" V 5605 4622 50  0000 R CNN
F 2 "" H 5600 4750 50  0001 C CNN
F 3 "" H 5600 4750 50  0001 C CNN
	1    5600 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 4750 5700 4750
$Comp
L Connector:AudioJack3 J6
U 1 1 5FDF3AC4
P 5900 5300
F 0 "J6" H 5620 5325 50  0000 R CNN
F 1 "AudioJack3" H 5620 5234 50  0000 R CNN
F 2 "SJ1-3533:CUI_SJ1-3533" H 5900 5300 50  0001 C CNN
F 3 "~" H 5900 5300 50  0001 C CNN
	1    5900 5300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5600 5400 5700 5400
NoConn ~ 5700 5300
$Comp
L power:GND #PWR020
U 1 1 5FDF3ACC
P 5600 5200
F 0 "#PWR020" H 5600 4950 50  0001 C CNN
F 1 "GND" V 5605 5072 50  0000 R CNN
F 2 "" H 5600 5200 50  0001 C CNN
F 3 "" H 5600 5200 50  0001 C CNN
	1    5600 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 5200 5700 5200
$Comp
L Connector:AudioJack3 J7
U 1 1 5FDFE1EB
P 5900 5750
F 0 "J7" H 5620 5775 50  0000 R CNN
F 1 "AudioJack3" H 5620 5684 50  0000 R CNN
F 2 "SJ1-3533:CUI_SJ1-3533" H 5900 5750 50  0001 C CNN
F 3 "~" H 5900 5750 50  0001 C CNN
	1    5900 5750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5600 5850 5700 5850
NoConn ~ 5700 5750
$Comp
L power:GND #PWR021
U 1 1 5FDFE1F3
P 5600 5650
F 0 "#PWR021" H 5600 5400 50  0001 C CNN
F 1 "GND" V 5605 5522 50  0000 R CNN
F 2 "" H 5600 5650 50  0001 C CNN
F 3 "" H 5600 5650 50  0001 C CNN
	1    5600 5650
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 5650 5700 5650
$Comp
L Connector:AudioJack3 J3
U 1 1 5FE1582D
P 4650 6800
F 0 "J3" H 4632 7125 50  0000 C CNN
F 1 "AudioJack3" H 4632 7034 50  0000 C CNN
F 2 "SJ1-3533:CUI_SJ1-3533" H 4650 6800 50  0001 C CNN
F 3 "~" H 4650 6800 50  0001 C CNN
	1    4650 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FE2D3AC
P 4900 6700
F 0 "#PWR015" H 4900 6450 50  0001 C CNN
F 1 "GND" V 4905 6572 50  0000 R CNN
F 2 "" H 4900 6700 50  0001 C CNN
F 3 "" H 4900 6700 50  0001 C CNN
	1    4900 6700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 6700 4850 6700
NoConn ~ 4850 6800
Wire Notes Line
	3550 3950 3550 7600
Wire Notes Line
	3550 7600 6800 7600
Wire Notes Line
	6800 7600 6800 3950
Wire Notes Line
	6800 3950 3550 3950
NoConn ~ 1750 1200
NoConn ~ 4600 5050
NoConn ~ 4600 5450
NoConn ~ 4600 4950
NoConn ~ 1750 2000
Wire Wire Line
	2250 1300 2350 1300
Wire Wire Line
	2000 3350 3200 3350
Wire Wire Line
	2250 1200 2350 1200
Wire Wire Line
	2350 1200 2350 1300
Connection ~ 2350 1300
Wire Wire Line
	2350 1300 3200 1300
$EndSCHEMATC
