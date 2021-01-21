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
$Comp
L Connector:Conn_01x02_Male PWR_CONN1
U 1 1 5FF19694
P 2575 1525
F 0 "PWR_CONN1" V 2500 1500 50  0000 C CNN
F 1 "Conn_01x02_Male" H 2683 1615 50  0001 C CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 2575 1525 50  0001 C CNN
F 3 "~" H 2575 1525 50  0001 C CNN
	1    2575 1525
	0    1    1    0   
$EndComp
$Comp
L custom:ESP32-DevKitC U1
U 1 1 5FF1CAFE
P 2975 3800
F 0 "U1" H 3125 3915 50  0000 C CNN
F 1 "ESP32-DevKitC" H 3125 3824 50  0000 C CNN
F 2 "custom:ESP32-DevKitC-DIP-38" H 2975 3800 50  0001 C CNN
F 3 "" H 2975 3800 50  0001 C CNN
	1    2975 3800
	1    0    0    -1  
$EndComp
$Comp
L custom:LED_sign_connection CONN1
U 1 1 5FF28B39
P 7350 1700
F 0 "CONN1" H 7828 1021 50  0000 L CNN
F 1 "LED_sign_connection" H 7828 930 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B12B-XH-A_1x12_P2.50mm_Vertical" H 7350 1700 50  0001 C CNN
F 3 "" H 7350 1700 50  0001 C CNN
	1    7350 1700
	1    0    0    -1  
$EndComp
$Comp
L custom:MC74VHC1GT125 U2
U 1 1 5FF2D432
P 7575 4225
F 0 "U2" H 7575 3575 50  0000 C CNN
F 1 "MC74VHC1GT125" H 7575 3475 50  0000 C CNN
F 2 "Package_SO:TSOP-5_1.65x3.05mm_P0.95mm" H 7575 4225 50  0001 C CNN
F 3 "" H 7575 4225 50  0001 C CNN
	1    7575 4225
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5FF3118B
P 7575 4275
F 0 "C7" V 7438 4275 50  0000 C CNN
F 1 "0.1uF" V 7437 4275 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7575 4275 50  0001 C CNN
F 3 "~" H 7575 4275 50  0001 C CNN
	1    7575 4275
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C8
U 1 1 5FF3214D
P 7575 5225
F 0 "C8" V 7438 5225 50  0000 C CNN
F 1 "0.1uF" V 7437 5225 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7575 5225 50  0001 C CNN
F 3 "~" H 7575 5225 50  0001 C CNN
	1    7575 5225
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 4750 7200 4750
Wire Wire Line
	7200 4450 7250 4450
Wire Wire Line
	7200 4275 7475 4275
Connection ~ 7200 4450
Wire Wire Line
	7200 5225 7475 5225
Wire Wire Line
	7200 5225 7200 5400
Wire Wire Line
	7200 5400 7250 5400
Wire Wire Line
	7200 5400 7200 5700
Connection ~ 7200 5400
Wire Wire Line
	7950 4450 7900 4450
Wire Wire Line
	7950 5400 7900 5400
Wire Wire Line
	7675 5225 7950 5225
Wire Wire Line
	7950 5225 7950 5400
Wire Wire Line
	7200 4450 7200 4750
Wire Wire Line
	7675 4275 7950 4275
Wire Wire Line
	7950 4275 7950 4450
$Comp
L Device:C_Small C2
U 1 1 5FF44794
P 2400 5950
F 0 "C2" H 2325 5950 50  0000 R CNN
F 1 "0.1uF" V 2262 5950 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2400 5950 50  0001 C CNN
F 3 "~" H 2400 5950 50  0001 C CNN
	1    2400 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 5850 2400 5750
Wire Wire Line
	7900 5700 7950 5700
Wire Wire Line
	7900 4750 7975 4750
$Comp
L custom:MAX17601 U5
U 1 1 5FF6A669
P 5650 3050
F 0 "U5" H 5425 3100 50  0000 C CNN
F 1 "MAX17601" H 5875 2575 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5650 3050 50  0001 C CNN
F 3 "" H 5650 3050 50  0001 C CNN
	1    5650 3050
	1    0    0    -1  
$EndComp
$Comp
L custom:MAX17601 U6
U 1 1 5FF6DFCA
P 5650 4250
F 0 "U6" H 5425 4300 50  0000 C CNN
F 1 "MAX17601" H 5850 3775 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5650 4250 50  0001 C CNN
F 3 "" H 5650 4250 50  0001 C CNN
	1    5650 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5FFA1134
P 5825 2850
F 0 "C4" V 5775 2950 50  0000 C CNN
F 1 "0.1uF" V 5687 2850 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5825 2850 50  0001 C CNN
F 3 "~" H 5825 2850 50  0001 C CNN
	1    5825 2850
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C5
U 1 1 5FFA334B
P 5850 4050
F 0 "C5" V 5800 4150 50  0000 C CNN
F 1 "0.1uF" V 5712 4050 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5850 4050 50  0001 C CNN
F 3 "~" H 5850 4050 50  0001 C CNN
	1    5850 4050
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5FFA441B
P 5825 5275
F 0 "C6" V 5775 5375 50  0000 C CNN
F 1 "0.1uF" V 5687 5275 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5825 5275 50  0001 C CNN
F 3 "~" H 5825 5275 50  0001 C CNN
	1    5825 5275
	0    1    1    0   
$EndComp
Connection ~ 7950 4275
Wire Wire Line
	7275 2250 7350 2250
Wire Wire Line
	7275 2350 7350 2350
Wire Wire Line
	7275 2450 7350 2450
Wire Wire Line
	7275 2550 7350 2550
Wire Wire Line
	7275 2650 7350 2650
Wire Wire Line
	7350 1950 7100 1950
Wire Wire Line
	7100 1950 7100 2750
Wire Wire Line
	7100 2750 7350 2750
Wire Wire Line
	7350 1850 7100 1850
Connection ~ 7100 2750
Wire Wire Line
	7200 4275 7200 4450
$Comp
L Device:CP1 C1
U 1 1 6004C982
P 3650 1875
F 0 "C1" H 3425 1875 50  0000 L CNN
F 1 "CP1" H 3400 1875 50  0001 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 3650 1875 50  0001 C CNN
F 3 "~" H 3650 1875 50  0001 C CNN
	1    3650 1875
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2025 3650 2775
Wire Wire Line
	2300 5250 2525 5250
Wire Wire Line
	2525 5150 2375 5150
Wire Wire Line
	3725 5450 3775 5450
Wire Wire Line
	3725 4950 3775 4950
Wire Wire Line
	3725 4750 3775 4750
Wire Wire Line
	3725 4150 3825 4150
Wire Wire Line
	6975 4600 7250 4600
Wire Wire Line
	7250 5550 6975 5550
Wire Wire Line
	3725 4050 3825 4050
$Comp
L custom:MC74VHC1GT125 U3
U 1 1 5FF2DA6C
P 7575 5175
F 0 "U3" H 7575 4525 50  0000 C CNN
F 1 "MC74VHC1GT125" H 7575 4425 50  0000 C CNN
F 2 "Package_SO:TSOP-5_1.65x3.05mm_P0.95mm" H 7575 5175 50  0001 C CNN
F 3 "" H 7575 5175 50  0001 C CNN
	1    7575 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 5700 7200 5700
Wire Wire Line
	3725 5050 3775 5050
$Comp
L Device:R_Small_US R1
U 1 1 60367451
P 4250 4625
F 0 "R1" H 4200 4625 50  0000 R CNN
F 1 "4.7k" H 4318 4580 50  0001 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 4250 4625 50  0001 C CNN
F 3 "~" H 4250 4625 50  0001 C CNN
	1    4250 4625
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 4450 4250 4525
$Comp
L Device:LED D1
U 1 1 5FFF4A83
P 3400 2300
F 0 "D1" V 3450 2225 50  0000 R CNN
F 1 "PWR" V 3375 2225 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3400 2300 50  0001 C CNN
F 3 "~" H 3400 2300 50  0001 C CNN
	1    3400 2300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 5FFF4A89
P 3400 2050
F 0 "R2" H 3350 2050 50  0000 R CNN
F 1 "150" H 3468 2005 50  0001 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 3400 2050 50  0001 C CNN
F 3 "~" H 3400 2050 50  0001 C CNN
	1    3400 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 4725 4250 5150
$Comp
L power:+5V #PWR0102
U 1 1 5ED9DBF3
P 3850 1625
F 0 "#PWR0102" H 3850 1475 50  0001 C CNN
F 1 "+5V" H 3865 1798 50  0000 C CNN
F 2 "" H 3850 1625 50  0001 C CNN
F 3 "" H 3850 1625 50  0001 C CNN
	1    3850 1625
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 600F043E
P 3850 2300
F 0 "R3" H 4000 2300 50  0000 R CNN
F 1 "150" H 3650 2300 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 3850 2300 50  0001 C CNN
F 3 "~" H 3850 2300 50  0001 C CNN
	1    3850 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 2450 3400 2775
Wire Wire Line
	3400 1950 3400 1725
$Comp
L custom:STD26P3LLH6 Q1
U 1 1 5FF8708A
P 2900 2200
F 0 "Q1" V 3242 2200 50  0000 C CNN
F 1 "STD26P3LLH6" V 3151 2200 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 3095 2125 50  0001 L CIN
F 3 "https://www.vishay.com/docs/69253/sud19p06.pdf" H 2900 2200 50  0001 C CNN
	1    2900 2200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 5FF884EC
P 2900 2575
F 0 "R5" H 3050 2575 50  0000 R CNN
F 1 "100k" H 2968 2530 50  0001 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 2900 2575 50  0001 C CNN
F 3 "~" H 2900 2575 50  0001 C CNN
	1    2900 2575
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 2400 2900 2475
$Comp
L Device:D_Zener D4
U 1 1 5FFCF8DA
P 3225 2250
F 0 "D4" V 3225 2100 50  0000 L CNN
F 1 "D_Zener" V 3270 2330 50  0001 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3225 2250 50  0001 C CNN
F 3 "~" H 3225 2250 50  0001 C CNN
	1    3225 2250
	0    1    1    0   
$EndComp
$Comp
L Jumper:Jumper_2_Open JP2
U 1 1 5FFD197E
P 2900 1725
F 0 "JP2" H 2850 1875 50  0000 L CNN
F 1 "prot_short" H 2900 1869 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2900 1725 50  0001 C CNN
F 3 "~" H 2900 1725 50  0001 C CNN
	1    2900 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2100 3225 2100
Wire Wire Line
	3225 2400 2900 2400
Connection ~ 2900 2400
Wire Wire Line
	2700 1725 2625 1725
Wire Wire Line
	2625 1725 2625 2100
Wire Wire Line
	2625 2100 2700 2100
Wire Wire Line
	3100 1725 3225 1725
Wire Wire Line
	3225 1725 3225 2100
Connection ~ 3225 2100
Wire Wire Line
	2575 1725 2625 1725
Connection ~ 2625 1725
Wire Wire Line
	3225 1725 3400 1725
Connection ~ 3225 1725
Connection ~ 3400 1725
Wire Wire Line
	3400 1725 3650 1725
Connection ~ 3650 1725
Text Label 3775 4450 0    50   ~ 0
EN
Wire Wire Line
	6150 2000 6200 2000
Wire Wire Line
	6150 3200 6200 3200
$Comp
L custom:MAX17601 U4
U 1 1 5FF69DE0
P 5650 1850
F 0 "U4" H 5425 1900 50  0000 C CNN
F 1 "MAX17601" H 5850 1375 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5650 1850 50  0001 C CNN
F 3 "" H 5650 1850 50  0001 C CNN
	1    5650 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3325 6200 3325
Wire Wire Line
	6150 4525 6200 4525
$Comp
L custom:MAX17601 U7
U 1 1 5FF71E1D
P 5650 5475
F 0 "U7" H 5425 5525 50  0000 C CNN
F 1 "MAX17601" H 5875 5000 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5650 5475 50  0001 C CNN
F 3 "" H 5650 5475 50  0001 C CNN
	1    5650 5475
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 5625 6200 5625
Wire Wire Line
	5175 1925 5050 1925
$Comp
L power:+5V #PWR0103
U 1 1 60044259
P 5375 1625
F 0 "#PWR0103" H 5375 1475 50  0001 C CNN
F 1 "+5V" H 5390 1798 50  0000 C CNN
F 2 "" H 5375 1625 50  0001 C CNN
F 3 "" H 5375 1625 50  0001 C CNN
	1    5375 1625
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 60045999
P 5375 2850
F 0 "#PWR0104" H 5375 2700 50  0001 C CNN
F 1 "+5V" H 5390 3023 50  0000 C CNN
F 2 "" H 5375 2850 50  0001 C CNN
F 3 "" H 5375 2850 50  0001 C CNN
	1    5375 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5375 1625 5650 1625
Wire Wire Line
	5175 3125 5050 3125
Wire Wire Line
	5175 4325 5050 4325
Text Label 5050 4325 0    50   ~ 0
EN
Wire Wire Line
	5175 5550 5050 5550
Text Label 5050 5550 0    50   ~ 0
EN
Text Label 5050 1925 0    50   ~ 0
EN
Text Label 5050 3125 0    50   ~ 0
EN
Wire Wire Line
	6150 4400 6200 4400
Text Label 7275 2050 0    50   ~ 0
R1
Wire Wire Line
	7350 2050 7275 2050
Text Label 6200 2000 0    50   ~ 0
R1
$Comp
L power:GND #PWR0105
U 1 1 5FFC162B
P 2900 2825
F 0 "#PWR0105" H 2900 2575 50  0001 C CNN
F 1 "GND" H 2905 2652 50  0001 C CNN
F 2 "" H 2900 2825 50  0001 C CNN
F 3 "" H 2900 2825 50  0001 C CNN
	1    2900 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2675 2900 2775
Wire Wire Line
	2475 1725 2475 2775
Wire Wire Line
	6150 2125 6200 2125
Text Label 6200 2125 0    50   ~ 0
R2
Wire Wire Line
	7350 2150 7275 2150
Text Label 7275 2150 0    50   ~ 0
R2
$Comp
L power:+5V #PWR0106
U 1 1 60001FC3
P 7100 1775
F 0 "#PWR0106" H 7100 1625 50  0001 C CNN
F 1 "+5V" H 7115 1948 50  0000 C CNN
F 2 "" H 7100 1775 50  0001 C CNN
F 3 "" H 7100 1775 50  0001 C CNN
	1    7100 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1775 7100 1850
Text Label 6200 3200 0    50   ~ 0
R3
Text Label 6200 3325 0    50   ~ 0
R4
Text Label 7275 2250 0    50   ~ 0
R3
Text Label 7275 2350 0    50   ~ 0
R4
Text Label 7275 2450 0    50   ~ 0
R5
Text Label 7275 2550 0    50   ~ 0
R6
Text Label 6200 4400 0    50   ~ 0
R5
Text Label 6200 4525 0    50   ~ 0
R6
Text Label 6200 5625 0    50   ~ 0
R7
Text Label 7275 2650 0    50   ~ 0
R7
Wire Wire Line
	2900 2775 3400 2775
Connection ~ 2900 2775
Wire Wire Line
	2900 2775 2900 2825
Wire Wire Line
	2900 2775 2475 2775
Wire Wire Line
	3400 2775 3650 2775
Connection ~ 3400 2775
$Comp
L power:GND #PWR0107
U 1 1 6016992C
P 2300 5450
F 0 "#PWR0107" H 2300 5200 50  0001 C CNN
F 1 "GND" H 2305 5277 50  0001 C CNN
F 2 "" H 2300 5450 50  0001 C CNN
F 3 "" H 2300 5450 50  0001 C CNN
	1    2300 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 5450 2300 5250
Wire Wire Line
	2400 5750 2525 5750
$Comp
L power:GND #PWR0108
U 1 1 6019D693
P 2400 6125
F 0 "#PWR0108" H 2400 5875 50  0001 C CNN
F 1 "GND" H 2405 5952 50  0001 C CNN
F 2 "" H 2400 6125 50  0001 C CNN
F 3 "" H 2400 6125 50  0001 C CNN
	1    2400 6125
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 6050 2400 6125
Wire Wire Line
	3850 1625 3850 1725
Wire Wire Line
	3650 1725 3850 1725
Connection ~ 3850 1725
$Comp
L Jumper:Jumper_2_Open JP1
U 1 1 5FF1DC1E
P 3850 1925
F 0 "JP1" V 3850 1825 50  0000 L CNN
F 1 "ESP32_5V" H 3850 2069 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3850 1925 50  0001 C CNN
F 3 "~" H 3850 1925 50  0001 C CNN
	1    3850 1925
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 2775 3850 2775
Wire Wire Line
	3850 2700 3850 2775
Connection ~ 3650 2775
Wire Wire Line
	3850 2125 3850 2150
Connection ~ 3850 2150
Wire Wire Line
	3850 2150 3850 2200
Wire Wire Line
	2400 5750 2175 5750
Connection ~ 2400 5750
Text Label 2175 5750 0    50   ~ 0
C5V
$Comp
L power:GND #PWR0109
U 1 1 60294A0F
P 4200 3975
F 0 "#PWR0109" H 4200 3725 50  0001 C CNN
F 1 "GND" H 4205 3802 50  0001 C CNN
F 2 "" H 4200 3975 50  0001 C CNN
F 3 "" H 4200 3975 50  0001 C CNN
	1    4200 3975
	1    0    0    -1  
$EndComp
Wire Wire Line
	3725 3950 4200 3950
Wire Wire Line
	4200 3950 4200 3975
Wire Wire Line
	5175 2025 5050 2025
Text Label 5050 2025 0    50   ~ 0
C1
Text Label 2375 5150 0    50   ~ 0
C1
Wire Wire Line
	5175 2125 5050 2125
Text Label 5050 2125 0    50   ~ 0
EN
Wire Wire Line
	2375 5350 2525 5350
Text Label 2375 5350 0    50   ~ 0
C2
Wire Wire Line
	5175 2225 5050 2225
Text Label 5050 2225 0    50   ~ 0
C2
Wire Wire Line
	2375 5050 2525 5050
Text Label 2375 5050 0    50   ~ 0
C3
Wire Wire Line
	5175 3225 5050 3225
Text Label 5050 3225 0    50   ~ 0
C3
Wire Wire Line
	5175 3325 5050 3325
Text Label 5050 3325 0    50   ~ 0
EN
Wire Wire Line
	5175 3425 5050 3425
Text Label 5050 3425 0    50   ~ 0
C4
Wire Wire Line
	5175 4425 5050 4425
Wire Wire Line
	5175 4525 5050 4525
Wire Wire Line
	5175 4625 5050 4625
Text Label 5050 4525 0    50   ~ 0
EN
Text Label 5050 4425 0    50   ~ 0
C5
Text Label 5050 4625 0    50   ~ 0
C6
Text Label 3775 5450 0    50   ~ 0
C4
Wire Wire Line
	5175 5650 5050 5650
Text Label 5050 5650 0    50   ~ 0
C7
Text Label 3775 5050 0    50   ~ 0
C5
Text Label 3775 4950 0    50   ~ 0
C6
Text Label 3775 4750 0    50   ~ 0
C7
$Comp
L Device:LED D2
U 1 1 600F026A
P 3850 2550
F 0 "D2" V 3875 2475 50  0000 R CNN
F 1 "ESP32_PWR" V 3800 2475 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3850 2550 50  0001 C CNN
F 3 "~" H 3850 2550 50  0001 C CNN
	1    3850 2550
	0    -1   -1   0   
$EndComp
Text Label 4050 2150 0    50   ~ 0
C5V
Wire Wire Line
	3850 2150 4050 2150
$Comp
L Device:LED D3
U 1 1 5FFD0A92
P 4100 4925
F 0 "D3" V 4200 4900 50  0000 R CNN
F 1 "LED" V 4050 5150 50  0001 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 4100 4925 50  0001 C CNN
F 3 "~" H 4100 4925 50  0001 C CNN
	1    4100 4925
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 5075 4100 5150
Wire Wire Line
	4100 4450 4100 4525
Wire Wire Line
	4100 4725 4100 4775
$Comp
L Device:R_Small_US R4
U 1 1 5FFD1F90
P 4100 4625
F 0 "R4" H 4250 4625 50  0000 R CNN
F 1 "68ohm" H 4168 4580 50  0001 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 4100 4625 50  0001 C CNN
F 3 "~" H 4100 4625 50  0001 C CNN
	1    4100 4625
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 5150 4100 5150
Wire Wire Line
	4250 4450 4100 4450
$Comp
L power:GND #PWR0101
U 1 1 5ED9DF54
P 4100 5225
F 0 "#PWR0101" H 4100 4975 50  0001 C CNN
F 1 "GND" H 4105 5052 50  0000 C CNN
F 2 "" H 4100 5225 50  0001 C CNN
F 3 "" H 4100 5225 50  0001 C CNN
	1    4100 5225
	1    0    0    -1  
$EndComp
Connection ~ 4100 5150
Wire Wire Line
	4100 5150 4100 5225
Wire Wire Line
	3725 4450 4100 4450
Connection ~ 4100 4450
Text Label 7975 4750 0    50   ~ 0
DATA
Text Label 7200 2850 0    50   ~ 0
DATA
Wire Wire Line
	7200 2850 7350 2850
Wire Wire Line
	7350 2950 7200 2950
Text Label 7200 2950 0    50   ~ 0
CLK
Text Label 7950 5700 0    50   ~ 0
CLK
$Comp
L power:+5V #PWR0110
U 1 1 6052D6D8
P 7950 4225
F 0 "#PWR0110" H 7950 4075 50  0001 C CNN
F 1 "+5V" H 7965 4398 50  0000 C CNN
F 2 "" H 7950 4225 50  0001 C CNN
F 3 "" H 7950 4225 50  0001 C CNN
	1    7950 4225
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4225 7950 4275
$Comp
L power:GND #PWR0111
U 1 1 60536471
P 7100 2950
F 0 "#PWR0111" H 7100 2700 50  0001 C CNN
F 1 "GND" H 7105 2777 50  0001 C CNN
F 2 "" H 7100 2950 50  0001 C CNN
F 3 "" H 7100 2950 50  0001 C CNN
	1    7100 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 2750 7100 2950
Text Label 6975 5550 0    50   ~ 0
CCLK
Text Label 6975 4600 0    50   ~ 0
CDATA
$Comp
L power:+5V #PWR0112
U 1 1 605669D9
P 7950 5175
F 0 "#PWR0112" H 7950 5025 50  0001 C CNN
F 1 "+5V" H 7965 5348 50  0000 C CNN
F 2 "" H 7950 5175 50  0001 C CNN
F 3 "" H 7950 5175 50  0001 C CNN
	1    7950 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5175 7950 5225
Connection ~ 7950 5225
$Comp
L power:GND #PWR0113
U 1 1 6056DED0
P 7200 4850
F 0 "#PWR0113" H 7200 4600 50  0001 C CNN
F 1 "GND" H 7205 4677 50  0001 C CNN
F 2 "" H 7200 4850 50  0001 C CNN
F 3 "" H 7200 4850 50  0001 C CNN
	1    7200 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4750 7200 4850
Connection ~ 7200 4750
$Comp
L power:GND #PWR0114
U 1 1 60575613
P 7200 5750
F 0 "#PWR0114" H 7200 5500 50  0001 C CNN
F 1 "GND" H 7205 5577 50  0001 C CNN
F 2 "" H 7200 5750 50  0001 C CNN
F 3 "" H 7200 5750 50  0001 C CNN
	1    7200 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 5700 7200 5750
Connection ~ 7200 5700
$Comp
L Device:C_Small C3
U 1 1 605CD12B
P 5825 1625
F 0 "C3" V 5775 1725 50  0000 C CNN
F 1 "0.1uF" V 5687 1625 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5825 1625 50  0001 C CNN
F 3 "~" H 5825 1625 50  0001 C CNN
	1    5825 1625
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 605CDC77
P 6025 1650
F 0 "#PWR0115" H 6025 1400 50  0001 C CNN
F 1 "GND" H 6030 1477 50  0001 C CNN
F 2 "" H 6025 1650 50  0001 C CNN
F 3 "" H 6025 1650 50  0001 C CNN
	1    6025 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1625 5725 1625
Connection ~ 5650 1625
Wire Wire Line
	5650 1625 5650 1650
Wire Wire Line
	5925 1625 6025 1625
Wire Wire Line
	6025 1625 6025 1650
$Comp
L power:GND #PWR0116
U 1 1 605E6C9C
P 5650 2525
F 0 "#PWR0116" H 5650 2275 50  0001 C CNN
F 1 "GND" H 5655 2352 50  0001 C CNN
F 2 "" H 5650 2525 50  0001 C CNN
F 3 "" H 5650 2525 50  0001 C CNN
	1    5650 2525
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2475 5650 2525
Wire Wire Line
	5375 2850 5650 2850
Wire Wire Line
	5650 2850 5725 2850
Connection ~ 5650 2850
$Comp
L power:GND #PWR0117
U 1 1 6061B017
P 6050 2875
F 0 "#PWR0117" H 6050 2625 50  0001 C CNN
F 1 "GND" H 6055 2702 50  0001 C CNN
F 2 "" H 6050 2875 50  0001 C CNN
F 3 "" H 6050 2875 50  0001 C CNN
	1    6050 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 2850 6050 2850
Wire Wire Line
	6050 2850 6050 2875
Text Label 3825 4150 0    50   ~ 0
CDATA
Text Label 3825 4050 0    50   ~ 0
CCLK
$Comp
L power:+5V #PWR0118
U 1 1 6068799D
P 5375 4050
F 0 "#PWR0118" H 5375 3900 50  0001 C CNN
F 1 "+5V" H 5390 4223 50  0000 C CNN
F 2 "" H 5375 4050 50  0001 C CNN
F 3 "" H 5375 4050 50  0001 C CNN
	1    5375 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 6068D201
P 6050 4100
F 0 "#PWR0119" H 6050 3850 50  0001 C CNN
F 1 "GND" H 6055 3927 50  0001 C CNN
F 2 "" H 6050 4100 50  0001 C CNN
F 3 "" H 6050 4100 50  0001 C CNN
	1    6050 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5375 4050 5650 4050
Wire Wire Line
	5750 4050 5650 4050
Connection ~ 5650 4050
Wire Wire Line
	5950 4050 6050 4050
Wire Wire Line
	6050 4050 6050 4100
$Comp
L power:GND #PWR0120
U 1 1 606A4D73
P 5650 3750
F 0 "#PWR0120" H 5650 3500 50  0001 C CNN
F 1 "GND" H 5655 3577 50  0001 C CNN
F 2 "" H 5650 3750 50  0001 C CNN
F 3 "" H 5650 3750 50  0001 C CNN
	1    5650 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3675 5650 3750
$Comp
L power:GND #PWR0121
U 1 1 606AB901
P 5650 4950
F 0 "#PWR0121" H 5650 4700 50  0001 C CNN
F 1 "GND" H 5655 4777 50  0001 C CNN
F 2 "" H 5650 4950 50  0001 C CNN
F 3 "" H 5650 4950 50  0001 C CNN
	1    5650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4875 5650 4950
$Comp
L power:+5V #PWR0122
U 1 1 606C0231
P 5375 5275
F 0 "#PWR0122" H 5375 5125 50  0001 C CNN
F 1 "+5V" H 5390 5448 50  0000 C CNN
F 2 "" H 5375 5275 50  0001 C CNN
F 3 "" H 5375 5275 50  0001 C CNN
	1    5375 5275
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 606C0A69
P 5650 6175
F 0 "#PWR0123" H 5650 5925 50  0001 C CNN
F 1 "GND" H 5655 6002 50  0001 C CNN
F 2 "" H 5650 6175 50  0001 C CNN
F 3 "" H 5650 6175 50  0001 C CNN
	1    5650 6175
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6100 5650 6175
Wire Wire Line
	5375 5275 5650 5275
Wire Wire Line
	5650 5275 5725 5275
Connection ~ 5650 5275
$Comp
L power:GND #PWR0124
U 1 1 606D318E
P 6025 5325
F 0 "#PWR0124" H 6025 5075 50  0001 C CNN
F 1 "GND" H 6030 5152 50  0001 C CNN
F 2 "" H 6025 5325 50  0001 C CNN
F 3 "" H 6025 5325 50  0001 C CNN
	1    6025 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 5275 6025 5275
Wire Wire Line
	6025 5275 6025 5325
Wire Notes Line
	2000 3300 4625 3300
Wire Notes Line
	2000 975  2000 6375
Wire Notes Line
	6700 3600 8775 3600
Text Notes 2925 1225 0    98   ~ 0
Power
Text Notes 2850 3550 0    98   ~ 0
ESP32
Text Notes 6950 1350 0    98   ~ 0
Sign Connector
Text Notes 7100 3875 0    98   ~ 0
Level Shifters
Text Notes 5150 1300 0    98   ~ 0
Row Drivers
Wire Notes Line
	2000 6375 8775 6375
Wire Notes Line
	8775 975  8775 6375
Wire Notes Line
	6700 975  6700 6375
Wire Notes Line
	4625 975  4625 6375
Wire Notes Line
	2000 975  8775 975 
$EndSCHEMATC
