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
L power:GND #PWR0101
U 1 1 5ED9DF54
P 2075 5575
F 0 "#PWR0101" H 2075 5325 50  0001 C CNN
F 1 "GND" H 2080 5402 50  0000 C CNN
F 2 "" H 2075 5575 50  0001 C CNN
F 3 "" H 2075 5575 50  0001 C CNN
	1    2075 5575
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male PWR_CONN1
U 1 1 5FF19694
P 1500 2075
F 0 "PWR_CONN1" H 1550 1900 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1608 2165 50  0001 C CNN
F 2 "" H 1500 2075 50  0001 C CNN
F 3 "~" H 1500 2075 50  0001 C CNN
	1    1500 2075
	1    0    0    -1  
$EndComp
$Comp
L custom:ESP32-DevKitC U1
U 1 1 5FF1CAFE
P 3350 1600
F 0 "U1" H 3500 1715 50  0000 C CNN
F 1 "ESP32-DevKitC" H 3500 1624 50  0000 C CNN
F 2 "custom:ESP32-DevKitC-DIP-38" H 3350 1600 50  0001 C CNN
F 3 "" H 3350 1600 50  0001 C CNN
	1    3350 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1750 4100 1225
Wire Wire Line
	4100 1225 2550 1225
$Comp
L custom:LED_sign_connection CONN1
U 1 1 5FF28B39
P 7425 2375
F 0 "CONN1" H 7903 1696 50  0000 L CNN
F 1 "LED_sign_connection" H 7903 1605 50  0000 L CNN
F 2 "" H 7425 2375 50  0001 C CNN
F 3 "" H 7425 2375 50  0001 C CNN
	1    7425 2375
	1    0    0    -1  
$EndComp
$Comp
L custom:MC74VHC1GT125 U2
U 1 1 5FF2D432
P 6800 3575
F 0 "U2" H 6800 2925 50  0000 C CNN
F 1 "MC74VHC1GT125" H 6800 2825 50  0000 C CNN
F 2 "" H 6800 3575 50  0001 C CNN
F 3 "" H 6800 3575 50  0001 C CNN
	1    6800 3575
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5FF3118B
P 6800 3625
F 0 "C1" V 6663 3625 50  0000 C CNN
F 1 "0.1uF" V 6662 3625 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6800 3625 50  0001 C CNN
F 3 "~" H 6800 3625 50  0001 C CNN
	1    6800 3625
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5FF3214D
P 6800 4575
F 0 "C2" V 6663 4575 50  0000 C CNN
F 1 "0.1uF" V 6662 4575 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6800 4575 50  0001 C CNN
F 3 "~" H 6800 4575 50  0001 C CNN
	1    6800 4575
	0    1    1    0   
$EndComp
Wire Wire Line
	6475 4100 6425 4100
Wire Wire Line
	6425 3800 6475 3800
Wire Wire Line
	6425 3625 6700 3625
Connection ~ 6425 3800
Wire Wire Line
	6425 4575 6700 4575
Connection ~ 6425 4100
Wire Wire Line
	6425 4575 6425 4750
Wire Wire Line
	6425 4750 6475 4750
Connection ~ 6425 4575
Wire Wire Line
	6425 4750 6425 5050
Connection ~ 6425 4750
Wire Wire Line
	7175 3800 7125 3800
Wire Wire Line
	7175 4750 7125 4750
Wire Wire Line
	6900 4575 7175 4575
Connection ~ 7175 4575
Wire Wire Line
	7175 4575 7175 4750
Wire Wire Line
	6425 4100 6425 4575
Wire Wire Line
	7175 3800 7175 4575
Wire Wire Line
	6425 3800 6425 4100
Wire Wire Line
	6900 3625 7175 3625
Wire Wire Line
	7175 3625 7175 3800
Connection ~ 7175 3800
$Comp
L Device:C_Small C3
U 1 1 5FF44794
P 2550 3400
F 0 "C3" H 2475 3400 50  0000 R CNN
F 1 "0.1uF" V 2412 3400 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2550 3400 50  0001 C CNN
F 3 "~" H 2550 3400 50  0001 C CNN
	1    2550 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	2550 3500 2550 3550
Connection ~ 2550 3550
Wire Wire Line
	2550 3550 2900 3550
Wire Wire Line
	7425 3625 7425 5050
Wire Wire Line
	7125 5050 7425 5050
Wire Wire Line
	7425 3525 7350 3525
Wire Wire Line
	7350 3525 7350 4100
Wire Wire Line
	7125 4100 7350 4100
$Comp
L custom:MAX17601 U4
U 1 1 5FF69DE0
P 5300 1450
F 0 "U4" H 5300 1540 50  0000 C CNN
F 1 "MAX17601" H 5300 1449 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5300 1450 50  0001 C CNN
F 3 "" H 5300 1450 50  0001 C CNN
	1    5300 1450
	1    0    0    -1  
$EndComp
$Comp
L custom:MAX17601 U5
U 1 1 5FF6A669
P 5300 2425
F 0 "U5" H 5300 2515 50  0000 C CNN
F 1 "MAX17601" H 5300 2424 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5300 2425 50  0001 C CNN
F 3 "" H 5300 2425 50  0001 C CNN
	1    5300 2425
	1    0    0    -1  
$EndComp
$Comp
L custom:MAX17601 U6
U 1 1 5FF6DFCA
P 5300 3400
F 0 "U6" H 5300 3490 50  0000 C CNN
F 1 "MAX17601" H 5300 3399 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5300 3400 50  0001 C CNN
F 3 "" H 5300 3400 50  0001 C CNN
	1    5300 3400
	1    0    0    -1  
$EndComp
$Comp
L custom:MAX17601 U7
U 1 1 5FF71E1D
P 5300 4375
F 0 "U7" H 5300 4465 50  0000 C CNN
F 1 "MAX17601" H 5300 4374 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 5300 4375 50  0001 C CNN
F 3 "" H 5300 4375 50  0001 C CNN
	1    5300 4375
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 5FF9BD43
P 5275 5125
F 0 "C5" V 5138 5125 50  0000 C CNN
F 1 "0.1uF" V 5137 5125 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5275 5125 50  0001 C CNN
F 3 "~" H 5275 5125 50  0001 C CNN
	1    5275 5125
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5FFA1134
P 5300 2175
F 0 "C6" V 5163 2175 50  0000 C CNN
F 1 "0.1uF" V 5162 2175 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5300 2175 50  0001 C CNN
F 3 "~" H 5300 2175 50  0001 C CNN
	1    5300 2175
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5FFA334B
P 5300 3150
F 0 "C7" V 5163 3150 50  0000 C CNN
F 1 "0.1uF" V 5162 3150 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5300 3150 50  0001 C CNN
F 3 "~" H 5300 3150 50  0001 C CNN
	1    5300 3150
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5FFA441B
P 5275 4125
F 0 "C4" V 5138 4125 50  0000 C CNN
F 1 "0.1uF" V 5137 4125 50  0001 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5275 4125 50  0001 C CNN
F 3 "~" H 5275 4125 50  0001 C CNN
	1    5275 4125
	0    1    1    0   
$EndComp
Wire Wire Line
	6425 5500 4550 5500
Connection ~ 2075 5500
Wire Wire Line
	2075 5500 2075 5575
Wire Wire Line
	7175 3625 7175 2525
Wire Wire Line
	7175 1175 5975 1175
Connection ~ 7175 3625
Wire Wire Line
	4850 1800 4550 1800
Wire Wire Line
	4550 5125 5175 5125
Wire Wire Line
	5175 4125 4550 4125
Wire Wire Line
	4550 1800 4550 2175
Connection ~ 4550 4125
Wire Wire Line
	4550 4125 4550 4725
Wire Wire Line
	5200 3150 4550 3150
Connection ~ 4550 3150
Wire Wire Line
	5200 2175 4550 2175
Connection ~ 4550 2175
Wire Wire Line
	4550 2175 4550 2775
Wire Wire Line
	5750 1800 5975 1800
Wire Wire Line
	5975 5125 5375 5125
Wire Wire Line
	5400 2175 5975 2175
Connection ~ 5975 2175
Wire Wire Line
	5400 3150 5975 3150
Connection ~ 5975 3150
Wire Wire Line
	5375 4125 5975 4125
Connection ~ 5975 4125
Wire Wire Line
	5975 4125 5975 4225
Wire Wire Line
	4550 5125 4550 5500
Connection ~ 4550 5125
Connection ~ 4550 5500
Wire Wire Line
	4550 5500 2075 5500
Wire Wire Line
	5975 1800 5975 1600
Connection ~ 5975 1800
Connection ~ 5975 1175
Wire Wire Line
	5750 1600 5975 1600
Connection ~ 5975 1600
Wire Wire Line
	5975 1600 5975 1175
Wire Wire Line
	5750 2575 5975 2575
Wire Wire Line
	5975 2175 5975 2275
Connection ~ 5975 2575
Wire Wire Line
	5975 2575 5975 2775
Wire Wire Line
	5750 2775 5975 2775
Connection ~ 5975 2775
Wire Wire Line
	5975 2775 5975 3075
Wire Wire Line
	5975 3150 5975 3250
Wire Wire Line
	5750 3550 5975 3550
Connection ~ 5975 3550
Wire Wire Line
	5975 3550 5975 3750
Wire Wire Line
	5750 3750 5975 3750
Connection ~ 5975 3750
Wire Wire Line
	5975 3750 5975 4050
Wire Wire Line
	5750 4525 5975 4525
Connection ~ 5975 4525
Wire Wire Line
	5975 4525 5975 4725
Wire Wire Line
	5750 4725 5975 4725
Connection ~ 5975 4725
Wire Wire Line
	5975 4725 5975 5125
Wire Wire Line
	4850 4725 4550 4725
Connection ~ 4550 4725
Wire Wire Line
	4550 4725 4550 5125
Wire Wire Line
	4850 2775 4550 2775
Connection ~ 4550 2775
Wire Wire Line
	4550 2775 4550 3150
Wire Wire Line
	7425 2725 6200 2725
Wire Wire Line
	6200 2725 6200 1700
Wire Wire Line
	6200 1700 5750 1700
Wire Wire Line
	5750 1900 6150 1900
Wire Wire Line
	6150 1900 6150 2825
Wire Wire Line
	6150 2825 7425 2825
Wire Wire Line
	5750 2675 6100 2675
Wire Wire Line
	6100 2675 6100 2925
Wire Wire Line
	6100 2925 7425 2925
Wire Wire Line
	5750 2875 6050 2875
Wire Wire Line
	6050 2875 6050 3025
Wire Wire Line
	6050 3025 7425 3025
Wire Wire Line
	5750 3650 6050 3650
Wire Wire Line
	6050 3650 6050 3125
Wire Wire Line
	6050 3125 7425 3125
Wire Wire Line
	5750 3850 6100 3850
Wire Wire Line
	6100 3850 6100 3225
Wire Wire Line
	6100 3225 7425 3225
Wire Wire Line
	5750 4625 6150 4625
Wire Wire Line
	6150 4625 6150 3325
Wire Wire Line
	6150 3325 7425 3325
Wire Wire Line
	7425 2625 7275 2625
Wire Wire Line
	7275 2625 7275 3425
Wire Wire Line
	7275 3425 7425 3425
Wire Wire Line
	7425 2525 7175 2525
Connection ~ 7175 2525
Wire Wire Line
	7175 2525 7175 1175
Wire Wire Line
	7275 3425 6425 3425
Wire Wire Line
	6425 3425 6425 3625
Connection ~ 7275 3425
Connection ~ 6425 3625
Wire Wire Line
	6425 3625 6425 3800
$Comp
L Device:CP1 C8
U 1 1 6004C982
P 2075 2100
F 0 "C8" H 2175 2100 50  0000 L CNN
F 1 "CP1" H 1825 2100 50  0000 L CNN
F 2 "" H 2075 2100 50  0001 C CNN
F 3 "~" H 2075 2100 50  0001 C CNN
	1    2075 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2175 1775 2175
Wire Wire Line
	1775 2175 1775 2250
Wire Wire Line
	1775 2250 2075 2250
Wire Wire Line
	2075 1950 1775 1950
Wire Wire Line
	1775 1950 1775 2075
Wire Wire Line
	1775 2075 1700 2075
Connection ~ 2075 1950
Wire Wire Line
	2075 2250 2075 3050
Connection ~ 2075 2250
Wire Wire Line
	2075 3050 2075 5500
Connection ~ 2075 3050
Wire Wire Line
	2550 3050 2900 3050
Wire Wire Line
	2550 3300 2550 3050
Connection ~ 2550 3050
Wire Wire Line
	2550 1225 2550 3050
Connection ~ 2400 1950
Wire Wire Line
	2075 1950 2400 1950
Wire Wire Line
	2400 1175 2400 1950
Connection ~ 2400 1175
Wire Wire Line
	2400 1100 2400 1175
Wire Wire Line
	2550 3050 2075 3050
Wire Wire Line
	2400 2350 2400 3550
Wire Wire Line
	2400 3550 2550 3550
$Comp
L Jumper:Jumper_2_Open JP1
U 1 1 5FF1DC1E
P 2400 2150
F 0 "JP1" V 2400 2050 50  0000 L CNN
F 1 "Jumper_2_Open" H 2400 2294 50  0001 C CNN
F 2 "" H 2400 2150 50  0001 C CNN
F 3 "~" H 2400 2150 50  0001 C CNN
	1    2400 2150
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5ED9DBF3
P 2400 1100
F 0 "#PWR0102" H 2400 950 50  0001 C CNN
F 1 "+5V" H 2415 1273 50  0000 C CNN
F 2 "" H 2400 1100 50  0001 C CNN
F 3 "" H 2400 1100 50  0001 C CNN
	1    2400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2950 2725 2950
Wire Wire Line
	2725 2950 2725 1275
Wire Wire Line
	2725 1275 4550 1275
Wire Wire Line
	4550 1275 4550 1700
Wire Wire Line
	4550 1700 4775 1700
Wire Wire Line
	2900 3150 2775 3150
Wire Wire Line
	2775 3150 2775 1325
Wire Wire Line
	4500 1325 4500 1900
Wire Wire Line
	4500 1900 4775 1900
Wire Wire Line
	2775 1325 4500 1325
Wire Wire Line
	2900 2850 2825 2850
Wire Wire Line
	2825 2850 2825 1375
Wire Wire Line
	2825 1375 4450 1375
Wire Wire Line
	4450 1375 4450 2675
Wire Wire Line
	4450 2675 4775 2675
Wire Wire Line
	4850 2575 4850 2475
Wire Wire Line
	4850 2275 5975 2275
Connection ~ 5975 2275
Wire Wire Line
	5975 2275 5975 2575
Wire Wire Line
	4850 3550 4850 3450
Wire Wire Line
	4850 3250 5975 3250
Connection ~ 5975 3250
Wire Wire Line
	5975 3250 5975 3550
Wire Wire Line
	4100 3250 4500 3250
Wire Wire Line
	4500 3250 4500 2875
Wire Wire Line
	4500 2875 4775 2875
Wire Wire Line
	4450 2850 4450 3650
Wire Wire Line
	4450 3650 4775 3650
Wire Wire Line
	4100 2750 4400 2750
Wire Wire Line
	4400 2750 4400 3850
Wire Wire Line
	4400 3850 4775 3850
Wire Wire Line
	4550 3150 4550 3750
Wire Wire Line
	4550 3750 4850 3750
Connection ~ 4550 3750
Wire Wire Line
	4550 3750 4550 4125
Wire Wire Line
	4100 2550 4350 2550
Wire Wire Line
	4100 1950 4250 1950
Wire Wire Line
	4250 1950 4250 5250
Wire Wire Line
	4250 5250 6200 5250
Wire Wire Line
	6200 5250 6200 3950
Wire Wire Line
	6200 3950 6475 3950
Wire Wire Line
	6475 4900 6250 4900
Wire Wire Line
	6250 4900 6250 5350
Wire Wire Line
	6250 5350 4300 5350
Wire Wire Line
	4100 1850 4300 1850
Wire Wire Line
	4300 1850 4300 5350
$Comp
L custom:MC74VHC1GT125 U3
U 1 1 5FF2DA6C
P 6800 4525
F 0 "U3" H 6800 3875 50  0000 C CNN
F 1 "MC74VHC1GT125" H 6800 3775 50  0000 C CNN
F 2 "" H 6800 4525 50  0001 C CNN
F 3 "" H 6800 4525 50  0001 C CNN
	1    6800 4525
	1    0    0    -1  
$EndComp
Wire Wire Line
	6475 5050 6425 5050
Connection ~ 6425 5050
Wire Wire Line
	6425 5050 6425 5500
Wire Wire Line
	4100 2850 4450 2850
Wire Wire Line
	4350 4625 4775 4625
Wire Wire Line
	4350 2550 4350 4625
Wire Wire Line
	4850 4525 4850 4425
Wire Wire Line
	4850 4225 5975 4225
Connection ~ 5975 4225
Wire Wire Line
	5975 4225 5975 4525
$Comp
L Device:R_Small_US R7
U 1 1 602BC053
P 4775 4525
F 0 "R7" H 4925 4525 50  0000 R CNN
F 1 "10k" H 4843 4480 50  0001 L CNN
F 2 "" H 4775 4525 50  0001 C CNN
F 3 "~" H 4775 4525 50  0001 C CNN
	1    4775 4525
	-1   0    0    1   
$EndComp
Connection ~ 4775 4625
Wire Wire Line
	4775 4625 4850 4625
$Comp
L Device:R_Small_US R5
U 1 1 602DB408
P 4775 3550
F 0 "R5" H 4925 3550 50  0000 R CNN
F 1 "10k" H 4843 3505 50  0001 L CNN
F 2 "" H 4775 3550 50  0001 C CNN
F 3 "~" H 4775 3550 50  0001 C CNN
	1    4775 3550
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 602DB7FE
P 4775 3950
F 0 "R6" H 4925 3950 50  0000 R CNN
F 1 "10k" H 4843 3905 50  0001 L CNN
F 2 "" H 4775 3950 50  0001 C CNN
F 3 "~" H 4775 3950 50  0001 C CNN
	1    4775 3950
	-1   0    0    1   
$EndComp
Connection ~ 4775 3650
Wire Wire Line
	4775 3650 4850 3650
Connection ~ 4775 3850
Wire Wire Line
	4775 3850 4850 3850
Wire Wire Line
	4775 4425 4850 4425
Connection ~ 4850 4425
Wire Wire Line
	4850 4425 4850 4225
Wire Wire Line
	4775 3450 4850 3450
Connection ~ 4850 3450
Wire Wire Line
	4850 3450 4850 3250
Wire Wire Line
	4775 4050 5975 4050
Connection ~ 5975 4050
Wire Wire Line
	5975 4050 5975 4125
$Comp
L Device:R_Small_US R3
U 1 1 6033F646
P 4775 2575
F 0 "R3" H 4925 2575 50  0000 R CNN
F 1 "10k" H 4843 2530 50  0001 L CNN
F 2 "" H 4775 2575 50  0001 C CNN
F 3 "~" H 4775 2575 50  0001 C CNN
	1    4775 2575
	-1   0    0    1   
$EndComp
Connection ~ 4775 2675
Wire Wire Line
	4775 2675 4850 2675
Wire Wire Line
	4775 2475 4850 2475
Connection ~ 4850 2475
Wire Wire Line
	4850 2475 4850 2275
$Comp
L Device:R_Small_US R4
U 1 1 60359320
P 4775 2975
F 0 "R4" H 4925 2975 50  0000 R CNN
F 1 "10k" H 4843 2930 50  0001 L CNN
F 2 "" H 4775 2975 50  0001 C CNN
F 3 "~" H 4775 2975 50  0001 C CNN
	1    4775 2975
	-1   0    0    1   
$EndComp
Connection ~ 4775 2875
Wire Wire Line
	4775 2875 4850 2875
Wire Wire Line
	4775 3075 5975 3075
Connection ~ 5975 3075
Wire Wire Line
	5975 3075 5975 3150
$Comp
L Device:R_Small_US R1
U 1 1 60367451
P 4775 1600
F 0 "R1" H 4925 1600 50  0000 R CNN
F 1 "10k" H 4843 1555 50  0001 L CNN
F 2 "" H 4775 1600 50  0001 C CNN
F 3 "~" H 4775 1600 50  0001 C CNN
	1    4775 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 1175 4850 1175
Connection ~ 4775 1700
Wire Wire Line
	4775 1700 4850 1700
Wire Wire Line
	4850 1600 4850 1500
Connection ~ 4850 1175
Wire Wire Line
	4850 1175 5975 1175
Wire Wire Line
	4775 1500 4850 1500
Connection ~ 4850 1500
Wire Wire Line
	4850 1500 4850 1175
$Comp
L Device:R_Small_US R2
U 1 1 6037DA3C
P 4775 2000
F 0 "R2" H 4925 2000 50  0000 R CNN
F 1 "10k" H 4843 1955 50  0001 L CNN
F 2 "" H 4775 2000 50  0001 C CNN
F 3 "~" H 4775 2000 50  0001 C CNN
	1    4775 2000
	-1   0    0    1   
$EndComp
Connection ~ 4775 1900
Wire Wire Line
	4775 1900 4850 1900
Wire Wire Line
	4775 2100 5975 2100
Wire Wire Line
	5975 1800 5975 2100
Connection ~ 5975 2100
Wire Wire Line
	5975 2100 5975 2175
$EndSCHEMATC
