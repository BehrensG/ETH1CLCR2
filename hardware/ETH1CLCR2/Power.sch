EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 13
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
L ETH1CLCR2:MAX5902 U903
U 1 1 608E4A52
P 3100 3550
F 0 "U903" H 3100 3915 50  0000 C CNN
F 1 "MAX5902" H 3100 3824 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 3100 3550 60  0001 C CNN
F 3 "" H 3100 3550 60  0001 C CNN
	1    3100 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GDS Q901
U 1 1 608E6663
P 3750 3150
F 0 "Q901" V 4092 3150 50  0000 C CNN
F 1 "IRFR5410" V 4001 3150 50  0000 C CNN
F 2 "ETH1CLCR2:TO-252-2_Rectifier" H 3950 3250 50  0001 C CNN
F 3 "~" H 3750 3150 50  0001 C CNN
	1    3750 3150
	0    1    -1   0   
$EndComp
$Comp
L Device:Fuse F901
U 1 1 608EB3A4
P 1350 3050
F 0 "F901" V 1153 3050 50  0000 C CNN
F 1 "MF-LSMF185/33X" V 1244 3050 50  0000 C CNN
F 2 "ETH1CLCR2:Fuse_SMD2920" V 1280 3050 50  0001 C CNN
F 3 "~" H 1350 3050 50  0001 C CNN
	1    1350 3050
	0    1    1    0   
$EndComp
$Comp
L Device:R R901
U 1 1 608F9CA4
P 2150 3350
F 0 "R901" H 2220 3396 50  0000 L CNN
F 1 "100k" H 2220 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 2080 3350 50  0001 C CNN
F 3 "~" H 2150 3350 50  0001 C CNN
	1    2150 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 3550 2150 3550
Wire Wire Line
	2150 3550 2150 3500
$Comp
L Device:D_Zener D902
U 1 1 608FCF20
P 1550 3550
F 0 "D902" V 1504 3630 50  0000 L CNN
F 1 "SM6T30AY" V 1595 3630 50  0000 L CNN
F 2 "ETH1CLCR2:DO_214AA_REV" H 1550 3550 50  0001 C CNN
F 3 "~" H 1550 3550 50  0001 C CNN
	1    1550 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 3450 3750 3450
Wire Wire Line
	3750 3450 3750 3350
Wire Wire Line
	3700 3550 4050 3550
Wire Wire Line
	3550 3050 2500 3050
Wire Wire Line
	2150 3050 2150 3200
Wire Wire Line
	2500 3450 2500 3050
Connection ~ 2500 3050
Wire Wire Line
	2500 3050 2150 3050
Wire Wire Line
	1550 3400 1550 3050
Wire Wire Line
	1550 3050 2150 3050
Connection ~ 2150 3050
Wire Wire Line
	1500 3050 1550 3050
Connection ~ 1550 3050
NoConn ~ 3700 3650
Wire Wire Line
	4050 3050 3950 3050
Wire Wire Line
	4050 3550 4050 3050
$Comp
L Device:D_Zener D901
U 1 1 60942372
P 4300 3250
F 0 "D901" V 4254 3330 50  0000 L CNN
F 1 "MMSZ5249B" V 4345 3330 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 4300 3250 50  0001 C CNN
F 3 "~" H 4300 3250 50  0001 C CNN
	1    4300 3250
	0    1    1    0   
$EndComp
$Comp
L Device:R R902
U 1 1 60944080
P 4300 3550
F 0 "R902" H 4370 3596 50  0000 L CNN
F 1 "330" H 4370 3505 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 4230 3550 50  0001 C CNN
F 3 "~" H 4300 3550 50  0001 C CNN
	1    4300 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D903
U 1 1 609460EA
P 4300 3850
F 0 "D903" V 4339 3732 50  0000 R CNN
F 1 "RED" V 4248 3732 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4300 3850 50  0001 C CNN
F 3 "~" H 4300 3850 50  0001 C CNN
	1    4300 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4050 3050 4300 3050
Wire Wire Line
	4300 3050 4300 3100
Wire Wire Line
	4300 4100 2500 4100
Wire Wire Line
	1550 4100 1550 3700
Connection ~ 4050 3050
Wire Wire Line
	4300 4100 4300 4000
Wire Wire Line
	2500 3650 2500 4100
Connection ~ 2500 4100
Wire Wire Line
	2500 4100 1550 4100
$Comp
L power:GNDPWR #PWR0906
U 1 1 6095535D
P 950 4150
F 0 "#PWR0906" H 950 3950 50  0001 C CNN
F 1 "GNDPWR" H 954 3996 50  0000 C CNN
F 2 "" H 950 4100 50  0001 C CNN
F 3 "" H 950 4100 50  0001 C CNN
	1    950  4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 3050 950  3050
Wire Wire Line
	950  3050 950  2900
$Comp
L power:+24V #PWR0901
U 1 1 609583C1
P 950 2900
F 0 "#PWR0901" H 950 2750 50  0001 C CNN
F 1 "+24V" H 965 3073 50  0000 C CNN
F 2 "" H 950 2900 50  0001 C CNN
F 3 "" H 950 2900 50  0001 C CNN
	1    950  2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  4150 950  4100
Wire Wire Line
	950  4100 1550 4100
Connection ~ 1550 4100
$Comp
L ETH1CLCR2:NMK_SINGLE U905
U 1 1 609DE2AA
P 7100 4350
F 0 "U905" H 7100 4815 50  0000 C CNN
F 1 "NMK2409SAC" H 7100 4724 50  0000 C CNN
F 2 "ETH1CLCR2:NMK_SINGLE" H 7100 4350 50  0001 C CNN
F 3 "" H 7100 4350 50  0001 C CNN
	1    7100 4350
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR2:NMK_DUAL U907
U 1 1 609E098F
P 7150 5650
F 0 "U907" H 7150 6115 50  0000 C CNN
F 1 "NMK2409SC" H 7150 6024 50  0000 C CNN
F 2 "ETH1CLCR2:NMK_DUAL" H 7150 5650 50  0001 C CNN
F 3 "" H 7150 5650 50  0001 C CNN
	1    7150 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C901
U 1 1 609E5909
P 8300 3250
F 0 "C901" H 8415 3296 50  0000 L CNN
F 1 "10u" H 8415 3205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 8338 3100 50  0001 C CNN
F 3 "~" H 8300 3250 50  0001 C CNN
	1    8300 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3450 8300 3400
Wire Wire Line
	8300 3100 8300 3050
Connection ~ 8300 3050
Connection ~ 8300 3450
$Comp
L Device:C C902
U 1 1 609EC1FE
P 9550 3250
F 0 "C902" H 9665 3296 50  0000 L CNN
F 1 "10u" H 9665 3205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9588 3100 50  0001 C CNN
F 3 "~" H 9550 3250 50  0001 C CNN
	1    9550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3400 9550 3450
Wire Wire Line
	8300 3450 9000 3450
Wire Wire Line
	9550 3100 9550 3050
Wire Wire Line
	9550 3050 9300 3050
Wire Wire Line
	9000 3350 9000 3450
Connection ~ 9000 3450
Wire Wire Line
	9000 3450 9550 3450
$Comp
L power:GND #PWR0903
U 1 1 609EE938
P 10600 3500
F 0 "#PWR0903" H 10600 3250 50  0001 C CNN
F 1 "GND" H 10605 3327 50  0000 C CNN
F 2 "" H 10600 3500 50  0001 C CNN
F 3 "" H 10600 3500 50  0001 C CNN
	1    10600 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 3500 10600 3450
Connection ~ 9550 3450
$Comp
L power:+3.3V #PWR0902
U 1 1 609F4385
P 10600 3000
F 0 "#PWR0902" H 10600 2850 50  0001 C CNN
F 1 "+3.3V" H 10615 3173 50  0000 C CNN
F 2 "" H 10600 3000 50  0001 C CNN
F 3 "" H 10600 3000 50  0001 C CNN
	1    10600 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 3000 10600 3050
Connection ~ 9550 3050
$Comp
L Device:C C907
U 1 1 609FCF54
P 7800 4350
F 0 "C907" H 7915 4396 50  0000 L CNN
F 1 "10u" H 7915 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 7838 4200 50  0001 C CNN
F 3 "~" H 7800 4350 50  0001 C CNN
	1    7800 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4550 7800 4500
Wire Wire Line
	7800 4200 7800 4150
Wire Wire Line
	8200 4150 7800 4150
Connection ~ 7800 4150
Connection ~ 7800 4550
$Comp
L Device:C C908
U 1 1 609FCF61
P 9050 4350
F 0 "C908" H 9165 4396 50  0000 L CNN
F 1 "10u" H 9165 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9088 4200 50  0001 C CNN
F 3 "~" H 9050 4350 50  0001 C CNN
	1    9050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4500 9050 4550
Wire Wire Line
	7800 4550 8500 4550
Wire Wire Line
	9050 4200 9050 4150
Wire Wire Line
	9050 4150 8800 4150
Wire Wire Line
	8500 4450 8500 4550
Connection ~ 8500 4550
Wire Wire Line
	8500 4550 9050 4550
$Comp
L power:GND #PWR0907
U 1 1 609FCF6E
P 10100 4600
F 0 "#PWR0907" H 10100 4350 50  0001 C CNN
F 1 "GND" H 10105 4427 50  0000 C CNN
F 2 "" H 10100 4600 50  0001 C CNN
F 3 "" H 10100 4600 50  0001 C CNN
	1    10100 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 4600 10100 4550
Connection ~ 9050 4550
Wire Wire Line
	10100 4100 10100 4150
Connection ~ 9050 4150
$Comp
L power:+5V #PWR0905
U 1 1 60A018C1
P 10100 4100
F 0 "#PWR0905" H 10100 3950 50  0001 C CNN
F 1 "+5V" H 10115 4273 50  0000 C CNN
F 2 "" H 10100 4100 50  0001 C CNN
F 3 "" H 10100 4100 50  0001 C CNN
	1    10100 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C911
U 1 1 60A6652D
P 7900 5450
F 0 "C911" H 8015 5496 50  0000 L CNN
F 1 "10u" H 8015 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 7938 5300 50  0001 C CNN
F 3 "~" H 7900 5450 50  0001 C CNN
	1    7900 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C912
U 1 1 60A6A7BE
P 9050 5450
F 0 "C912" H 9165 5496 50  0000 L CNN
F 1 "10u" H 9165 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9088 5300 50  0001 C CNN
F 3 "~" H 9050 5450 50  0001 C CNN
	1    9050 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 5650 7900 5650
Wire Wire Line
	8500 5600 8500 5650
Connection ~ 8500 5650
Wire Wire Line
	8500 5650 9050 5650
Wire Wire Line
	7600 5450 7650 5450
Wire Wire Line
	7650 5450 7650 5300
Wire Wire Line
	7650 5300 7900 5300
Connection ~ 7900 5300
Wire Wire Line
	7900 5300 8200 5300
Wire Wire Line
	7900 5600 7900 5650
Connection ~ 7900 5650
Wire Wire Line
	7900 5650 8500 5650
Wire Wire Line
	8800 5300 9050 5300
Wire Wire Line
	9050 5650 9050 5600
$Comp
L Device:C C916
U 1 1 60A75F4C
P 7900 5850
F 0 "C916" H 8015 5896 50  0000 L CNN
F 1 "10u" H 8015 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 7938 5700 50  0001 C CNN
F 3 "~" H 7900 5850 50  0001 C CNN
	1    7900 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C917
U 1 1 60A76326
P 9050 5850
F 0 "C917" H 9165 5896 50  0000 L CNN
F 1 "10u" H 9165 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9088 5700 50  0001 C CNN
F 3 "~" H 9050 5850 50  0001 C CNN
	1    9050 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 6000 7900 6000
Wire Wire Line
	7650 6000 7650 5850
Wire Wire Line
	7650 5850 7600 5850
Connection ~ 7900 6000
Wire Wire Line
	7900 6000 7650 6000
Wire Wire Line
	7900 5700 7900 5650
Wire Wire Line
	8500 5700 8500 5650
Wire Wire Line
	9050 5650 9050 5700
Connection ~ 9050 5650
Wire Wire Line
	9050 6000 8800 6000
Wire Wire Line
	10800 5650 10600 5650
$Comp
L power:+5VA #PWR0909
U 1 1 60AC054B
P 10600 5250
F 0 "#PWR0909" H 10600 5100 50  0001 C CNN
F 1 "+5VA" H 10615 5423 50  0000 C CNN
F 2 "" H 10600 5250 50  0001 C CNN
F 3 "" H 10600 5250 50  0001 C CNN
	1    10600 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 5250 10600 5300
$Comp
L power:-5VA #PWR0912
U 1 1 60ACB6E0
P 10600 6050
F 0 "#PWR0912" H 10600 6150 50  0001 C CNN
F 1 "-5VA" H 10615 6223 50  0000 C CNN
F 2 "" H 10600 6050 50  0001 C CNN
F 3 "" H 10600 6050 50  0001 C CNN
	1    10600 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	10600 6050 10600 6000
Wire Wire Line
	6650 4150 6200 4150
Wire Wire Line
	6700 5450 6200 5450
$Comp
L power:GNDPWR #PWR0904
U 1 1 60B09A96
P 6600 3550
F 0 "#PWR0904" H 6600 3350 50  0001 C CNN
F 1 "GNDPWR" H 6604 3396 50  0000 C CNN
F 2 "" H 6600 3500 50  0001 C CNN
F 3 "" H 6600 3500 50  0001 C CNN
	1    6600 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3550 6600 3450
$Comp
L power:GNDPWR #PWR0908
U 1 1 60B0ED3F
P 6600 4650
F 0 "#PWR0908" H 6600 4450 50  0001 C CNN
F 1 "GNDPWR" H 6604 4496 50  0000 C CNN
F 2 "" H 6600 4600 50  0001 C CNN
F 3 "" H 6600 4600 50  0001 C CNN
	1    6600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4650 6600 4550
Wire Wire Line
	6600 4550 6650 4550
$Comp
L power:GNDPWR #PWR0911
U 1 1 60B129E4
P 6650 5950
F 0 "#PWR0911" H 6650 5750 50  0001 C CNN
F 1 "GNDPWR" H 6654 5796 50  0000 C CNN
F 2 "" H 6650 5900 50  0001 C CNN
F 3 "" H 6650 5900 50  0001 C CNN
	1    6650 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 5950 6650 5850
Wire Wire Line
	6650 5850 6700 5850
Wire Wire Line
	7550 4150 7800 4150
Wire Wire Line
	7550 4550 7800 4550
$Comp
L Device:C C913
U 1 1 60F4B484
P 9600 5450
F 0 "C913" H 9715 5496 50  0000 L CNN
F 1 "1u" H 9715 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9638 5300 50  0001 C CNN
F 3 "~" H 9600 5450 50  0001 C CNN
	1    9600 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C918
U 1 1 60F4D101
P 9600 5850
F 0 "C918" H 9715 5896 50  0000 L CNN
F 1 "1u" H 9715 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9638 5700 50  0001 C CNN
F 3 "~" H 9600 5850 50  0001 C CNN
	1    9600 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C919
U 1 1 60F4EDE5
P 10100 5850
F 0 "C919" H 10215 5896 50  0000 L CNN
F 1 "100n" H 10215 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 10138 5700 50  0001 C CNN
F 3 "~" H 10100 5850 50  0001 C CNN
	1    10100 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C914
U 1 1 60F50B6C
P 10100 5450
F 0 "C914" H 10215 5496 50  0000 L CNN
F 1 "100n" H 10215 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 10138 5300 50  0001 C CNN
F 3 "~" H 10100 5450 50  0001 C CNN
	1    10100 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 6000 9600 6000
Connection ~ 9050 6000
Wire Wire Line
	9600 6000 10100 6000
Connection ~ 9600 6000
Connection ~ 10100 6000
Wire Wire Line
	9600 5700 9600 5650
Connection ~ 9600 5650
Wire Wire Line
	9600 5650 9050 5650
Wire Wire Line
	9050 5300 9600 5300
Connection ~ 9050 5300
Wire Wire Line
	9600 5600 9600 5650
Wire Wire Line
	9600 5300 10100 5300
Connection ~ 9600 5300
Connection ~ 10100 5300
Wire Wire Line
	10100 5600 10100 5650
Connection ~ 10100 5650
Wire Wire Line
	10100 5650 9600 5650
Wire Wire Line
	10100 5700 10100 5650
$Comp
L Device:C C909
U 1 1 60F841C5
P 9600 4350
F 0 "C909" H 9715 4396 50  0000 L CNN
F 1 "1u" H 9715 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9638 4200 50  0001 C CNN
F 3 "~" H 9600 4350 50  0001 C CNN
	1    9600 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C910
U 1 1 60F841CB
P 10100 4350
F 0 "C910" H 10215 4396 50  0000 L CNN
F 1 "100n" H 10215 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 10138 4200 50  0001 C CNN
F 3 "~" H 10100 4350 50  0001 C CNN
	1    10100 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C903
U 1 1 60F8D591
P 10100 3250
F 0 "C903" H 10215 3296 50  0000 L CNN
F 1 "1u" H 10215 3205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 10138 3100 50  0001 C CNN
F 3 "~" H 10100 3250 50  0001 C CNN
	1    10100 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C904
U 1 1 60F8D597
P 10600 3250
F 0 "C904" H 10715 3296 50  0000 L CNN
F 1 "100n" H 10715 3205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 10638 3100 50  0001 C CNN
F 3 "~" H 10600 3250 50  0001 C CNN
	1    10600 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4150 9600 4150
Wire Wire Line
	10100 4150 10100 4200
Wire Wire Line
	10100 4550 9600 4550
Wire Wire Line
	10100 4500 10100 4550
Wire Wire Line
	9600 4550 9600 4500
Wire Wire Line
	9600 4200 9600 4150
Connection ~ 9600 4550
Wire Wire Line
	9600 4550 9050 4550
Connection ~ 9600 4150
Wire Wire Line
	9600 4150 10100 4150
Connection ~ 10100 4150
Connection ~ 10100 4550
Wire Wire Line
	9550 3450 10100 3450
Wire Wire Line
	10600 3450 10600 3400
Wire Wire Line
	10600 3050 10100 3050
Wire Wire Line
	10600 3100 10600 3050
Wire Wire Line
	10100 3050 10100 3100
Wire Wire Line
	10100 3400 10100 3450
Connection ~ 10100 3050
Wire Wire Line
	10100 3050 9550 3050
Connection ~ 10100 3450
Wire Wire Line
	10100 3450 10600 3450
Connection ~ 10600 3450
Connection ~ 10600 3050
Wire Wire Line
	8050 3450 8300 3450
Wire Wire Line
	8050 3050 8300 3050
Connection ~ 6200 4150
Wire Wire Line
	6200 4150 6200 3050
Wire Wire Line
	6200 4150 6200 5450
$Comp
L power:PWR_FLAG #FLG0904
U 1 1 61AC5B47
P 7650 5250
F 0 "#FLG0904" H 7650 5325 50  0001 C CNN
F 1 "PWR_FLAG" H 7650 5423 50  0000 C CNN
F 2 "" H 7650 5250 50  0001 C CNN
F 3 "~" H 7650 5250 50  0001 C CNN
	1    7650 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5250 7650 5300
Connection ~ 7650 5300
$Comp
L power:PWR_FLAG #FLG0905
U 1 1 61AC9875
P 7650 6050
F 0 "#FLG0905" H 7650 6125 50  0001 C CNN
F 1 "PWR_FLAG" H 7650 6223 50  0000 C CNN
F 2 "" H 7650 6050 50  0001 C CNN
F 3 "~" H 7650 6050 50  0001 C CNN
	1    7650 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7650 6050 7650 6000
Connection ~ 7650 6000
$Comp
L power:PWR_FLAG #FLG0903
U 1 1 61AD0B07
P 1550 4150
F 0 "#FLG0903" H 1550 4225 50  0001 C CNN
F 1 "PWR_FLAG" H 1550 4323 50  0000 C CNN
F 2 "" H 1550 4150 50  0001 C CNN
F 3 "~" H 1550 4150 50  0001 C CNN
	1    1550 4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1550 4150 1550 4100
$Comp
L power:+24V #PWR0913
U 1 1 61E016E0
P 950 7200
F 0 "#PWR0913" H 950 7050 50  0001 C CNN
F 1 "+24V" H 965 7373 50  0000 C CNN
F 2 "" H 950 7200 50  0001 C CNN
F 3 "" H 950 7200 50  0001 C CNN
	1    950  7200
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0906
U 1 1 61E0421A
P 950 7200
F 0 "#FLG0906" H 950 7275 50  0001 C CNN
F 1 "PWR_FLAG" H 950 7373 50  0000 C CNN
F 2 "" H 950 7200 50  0001 C CNN
F 3 "~" H 950 7200 50  0001 C CNN
	1    950  7200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0914
U 1 1 61EF651E
P 1400 7200
F 0 "#PWR0914" H 1400 6950 50  0001 C CNN
F 1 "GND" H 1405 7027 50  0000 C CNN
F 2 "" H 1400 7200 50  0001 C CNN
F 3 "" H 1400 7200 50  0001 C CNN
	1    1400 7200
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0907
U 1 1 61EF671F
P 1400 7200
F 0 "#FLG0907" H 1400 7275 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 7373 50  0000 C CNN
F 2 "" H 1400 7200 50  0001 C CNN
F 3 "~" H 1400 7200 50  0001 C CNN
	1    1400 7200
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0902
U 1 1 61F2F056
P 7800 4100
F 0 "#FLG0902" H 7800 4175 50  0001 C CNN
F 1 "PWR_FLAG" H 7800 4273 50  0000 C CNN
F 2 "" H 7800 4100 50  0001 C CNN
F 3 "~" H 7800 4100 50  0001 C CNN
	1    7800 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4100 7800 4150
$Comp
L power:PWR_FLAG #FLG0901
U 1 1 61F32C38
P 8300 3000
F 0 "#FLG0901" H 8300 3075 50  0001 C CNN
F 1 "PWR_FLAG" H 8300 3173 50  0000 C CNN
F 2 "" H 8300 3000 50  0001 C CNN
F 3 "~" H 8300 3000 50  0001 C CNN
	1    8300 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3000 8300 3050
$Comp
L Connector:TestPoint TP901
U 1 1 6114D0C3
P 9050 4600
F 0 "TP901" H 8992 4626 50  0000 R CNN
F 1 "TestPoint" H 8992 4717 50  0000 R CNN
F 2 "TestPoint:TestPoint_Plated_Hole_D2.0mm" H 9250 4600 50  0001 C CNN
F 3 "~" H 9250 4600 50  0001 C CNN
	1    9050 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	9050 4600 9050 4550
$Comp
L Device:C C905
U 1 1 611D1D2A
P 5050 3550
F 0 "C905" H 5165 3596 50  0000 L CNN
F 1 "4u7/50V" H 5165 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 5088 3400 50  0001 C CNN
F 3 "~" H 5050 3550 50  0001 C CNN
	1    5050 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3400 5050 3050
Wire Wire Line
	5050 3050 4300 3050
Connection ~ 4300 3050
Wire Wire Line
	5050 3700 5050 4100
Wire Wire Line
	5050 4100 4300 4100
Connection ~ 4300 4100
$Comp
L Device:C C906
U 1 1 611DDF1B
P 5650 3550
F 0 "C906" H 5765 3596 50  0000 L CNN
F 1 "4u7/50V" H 5765 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 5688 3400 50  0001 C CNN
F 3 "~" H 5650 3550 50  0001 C CNN
	1    5650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3400 5650 3050
Connection ~ 5650 3050
Wire Wire Line
	5650 3050 6200 3050
Wire Wire Line
	5050 3050 5650 3050
Connection ~ 5050 3050
Wire Wire Line
	5050 4100 5650 4100
Wire Wire Line
	5650 4100 5650 3700
Connection ~ 5050 4100
$Comp
L Device:CP C915
U 1 1 6093A953
P 10600 5450
F 0 "C915" H 10718 5496 50  0000 L CNN
F 1 "100u" H 10718 5405 50  0000 L CNN
F 2 "" H 10638 5300 50  0001 C CNN
F 3 "~" H 10600 5450 50  0001 C CNN
	1    10600 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 5650 10600 5600
Wire Wire Line
	10600 5300 10100 5300
Connection ~ 10600 5650
Wire Wire Line
	10600 5650 10100 5650
Connection ~ 10600 5300
$Comp
L Device:CP C920
U 1 1 6094BAF0
P 10600 5850
F 0 "C920" H 10718 5896 50  0000 L CNN
F 1 "100u" H 10718 5805 50  0000 L CNN
F 2 "" H 10638 5700 50  0001 C CNN
F 3 "~" H 10600 5850 50  0001 C CNN
	1    10600 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 6000 10600 6000
Wire Wire Line
	10600 5700 10600 5650
Connection ~ 10600 6000
$Comp
L power:GNDA #PWR0919
U 1 1 60F40D30
P 10800 5650
F 0 "#PWR0919" H 10800 5400 50  0001 C CNN
F 1 "GNDA" V 10805 5522 50  0000 R CNN
F 2 "" H 10800 5650 50  0001 C CNN
F 3 "" H 10800 5650 50  0001 C CNN
	1    10800 5650
	0    -1   -1   0   
$EndComp
$Comp
L Regulator_Linear:NCP1117-3.3_TO252 U908
U 1 1 60F51126
P 9000 3050
F 0 "U908" H 9000 3292 50  0000 C CNN
F 1 "NCP1117-3.3_TO252" H 9000 3201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 9000 3275 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 9000 3050 50  0001 C CNN
	1    9000 3050
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:NCP1117-5.0_TO252 U909
U 1 1 60F5313A
P 8500 4150
F 0 "U909" H 8500 4392 50  0000 C CNN
F 1 "NCP1117-5.0_TO252" H 8500 4301 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 8500 4375 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 8500 4150 50  0001 C CNN
	1    8500 4150
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:NCP1117-5.0_SOT223 U910
U 1 1 60F58B37
P 8500 5300
F 0 "U910" H 8500 5542 50  0000 C CNN
F 1 "NCP1117-5.0_SOT223" H 8500 5451 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8500 5500 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 8600 5050 50  0001 C CNN
	1    8500 5300
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LT1175-5_SOT223 U911
U 1 1 60F5A1C1
P 8500 6000
F 0 "U911" H 8500 5851 50  0000 C CNN
F 1 "LT1175-5_SOT223" H 8500 5760 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8500 5800 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/1175ff.pdf" H 8525 6000 50  0001 C CNN
	1    8500 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 3050 8700 3050
$Comp
L ETH1CLCR2:NCS3 U?
U 1 1 60B9EE6D
P 7600 3250
F 0 "U?" H 7600 3715 50  0000 C CNN
F 1 "NCS3S1205SC" H 7600 3624 50  0000 C CNN
F 2 "" H 7600 3250 50  0001 C CNN
F 3 "" H 7600 3250 50  0001 C CNN
	1    7600 3250
	1    0    0    -1  
$EndComp
NoConn ~ 7150 3250
$Comp
L Device:L L?
U 1 1 60BCA4CE
P 6900 3050
F 0 "L?" V 7090 3050 50  0000 C CNN
F 1 "10u" V 6999 3050 50  0000 C CNN
F 2 "" H 6900 3050 50  0001 C CNN
F 3 "~" H 6900 3050 50  0001 C CNN
	1    6900 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7050 3050 7150 3050
$Comp
L Device:C C?
U 1 1 60BCC6E4
P 6600 3250
F 0 "C?" H 6715 3296 50  0000 L CNN
F 1 "4u7" H 6715 3205 50  0000 L CNN
F 2 "" H 6638 3100 50  0001 C CNN
F 3 "~" H 6600 3250 50  0001 C CNN
	1    6600 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3050 6600 3050
Connection ~ 6200 3050
Wire Wire Line
	6600 3100 6600 3050
Connection ~ 6600 3050
Wire Wire Line
	6600 3050 6750 3050
Wire Wire Line
	6600 3450 6600 3400
Connection ~ 6600 3450
Wire Wire Line
	6600 3450 7150 3450
$EndSCHEMATC
