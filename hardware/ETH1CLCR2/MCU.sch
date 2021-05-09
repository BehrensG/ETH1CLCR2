EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 11 12
Title "MCU"
Date "2020-03-07"
Rev "1.00"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	8150 900  8150 850 
Wire Wire Line
	8150 850  8350 850 
Wire Wire Line
	10550 850  10550 900 
Wire Wire Line
	10350 900  10350 850 
Connection ~ 10350 850 
Wire Wire Line
	10350 850  10550 850 
Wire Wire Line
	10150 900  10150 850 
Connection ~ 10150 850 
Wire Wire Line
	10150 850  10350 850 
Wire Wire Line
	9950 900  9950 850 
Connection ~ 9950 850 
Wire Wire Line
	9950 850  10150 850 
Wire Wire Line
	9750 900  9750 850 
Connection ~ 9750 850 
Wire Wire Line
	9750 850  9950 850 
Wire Wire Line
	9550 900  9550 850 
Connection ~ 9550 850 
Wire Wire Line
	9550 850  9750 850 
Wire Wire Line
	9350 900  9350 850 
Connection ~ 9350 850 
Wire Wire Line
	9350 850  9550 850 
Wire Wire Line
	9150 900  9150 850 
Connection ~ 9150 850 
Wire Wire Line
	8950 900  8950 850 
Connection ~ 8950 850 
Wire Wire Line
	8950 850  9150 850 
Wire Wire Line
	8750 900  8750 850 
Connection ~ 8750 850 
Wire Wire Line
	8750 850  8950 850 
Wire Wire Line
	8550 900  8550 850 
Connection ~ 8550 850 
Wire Wire Line
	8550 850  8750 850 
Wire Wire Line
	8350 900  8350 850 
Connection ~ 8350 850 
Wire Wire Line
	8350 850  8550 850 
Wire Wire Line
	9350 800  9350 850 
Wire Wire Line
	8550 9000 8550 9050
Wire Wire Line
	8550 9050 8750 9050
Wire Wire Line
	10150 9050 10150 9000
Wire Wire Line
	9950 9000 9950 9050
Connection ~ 9950 9050
Wire Wire Line
	9950 9050 10150 9050
Wire Wire Line
	9750 9000 9750 9050
Connection ~ 9750 9050
Wire Wire Line
	9750 9050 9950 9050
Wire Wire Line
	9550 9000 9550 9050
Connection ~ 9550 9050
Wire Wire Line
	9550 9050 9750 9050
Wire Wire Line
	9350 9000 9350 9050
Connection ~ 9350 9050
Wire Wire Line
	9350 9050 9550 9050
Wire Wire Line
	9150 9000 9150 9050
Connection ~ 9150 9050
Wire Wire Line
	9150 9050 9350 9050
Wire Wire Line
	8950 9000 8950 9050
Connection ~ 8950 9050
Wire Wire Line
	8950 9050 9150 9050
Wire Wire Line
	8750 9000 8750 9050
Connection ~ 8750 9050
Wire Wire Line
	8750 9050 8950 9050
Wire Wire Line
	9350 9050 9350 9100
$Comp
L power:GND #PWR01111
U 1 1 5DAA3278
P 9350 9100
F 0 "#PWR01111" H 9350 8850 50  0001 C CNN
F 1 "GND" H 9355 8927 50  0000 C CNN
F 2 "" H 9350 9100 50  0001 C CNN
F 3 "" H 9350 9100 50  0001 C CNN
	1    9350 9100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1105
U 1 1 5DAA6CE1
P 15050 8900
F 0 "R1105" H 15120 8946 50  0000 L CNN
F 1 "10k" H 15120 8855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 14980 8900 50  0001 C CNN
F 3 "~" H 15050 8900 50  0001 C CNN
	1    15050 8900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1104
U 1 1 5DAA8BD1
P 15500 8500
F 0 "R1104" H 15570 8546 50  0000 L CNN
F 1 "10k" H 15570 8455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 15430 8500 50  0001 C CNN
F 3 "~" H 15500 8500 50  0001 C CNN
	1    15500 8500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1105
U 1 1 5DAA918D
P 15500 8900
F 0 "C1105" H 15615 8946 50  0000 L CNN
F 1 "100n" H 15615 8855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 15538 8750 50  0001 C CNN
F 3 "~" H 15500 8900 50  0001 C CNN
	1    15500 8900
	1    0    0    -1  
$EndComp
Wire Wire Line
	15500 8700 15500 8750
Wire Wire Line
	15500 8650 15500 8700
Connection ~ 15500 8700
$Comp
L power:GND #PWR01109
U 1 1 5DAAC0BD
P 15500 9050
F 0 "#PWR01109" H 15500 8800 50  0001 C CNN
F 1 "GND" H 15505 8877 50  0000 C CNN
F 2 "" H 15500 9050 50  0001 C CNN
F 3 "" H 15500 9050 50  0001 C CNN
	1    15500 9050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01108
U 1 1 5DAACD0D
P 15050 9050
F 0 "#PWR01108" H 15050 8800 50  0001 C CNN
F 1 "GND" H 15055 8877 50  0000 C CNN
F 2 "" H 15050 9050 50  0001 C CNN
F 3 "" H 15050 9050 50  0001 C CNN
	1    15050 9050
	1    0    0    -1  
$EndComp
Text HLabel 15100 2600 2    50   BiDi ~ 0
RMII_TXD1
Text HLabel 15100 2500 2    50   BiDi ~ 0
RMII_TXD0
Text HLabel 15100 2300 2    50   BiDi ~ 0
RMII_TXEN
Text HLabel 3600 5300 0    50   BiDi ~ 0
RMII_RXD0
Text HLabel 3600 5400 0    50   BiDi ~ 0
RMII_RXD1
Text HLabel 3600 3900 0    50   BiDi ~ 0
RMII_CRS_DV
Text HLabel 3600 3400 0    50   BiDi ~ 0
RMII_MDIO
Text HLabel 3600 5000 0    50   BiDi ~ 0
RMII_MDC
Text HLabel 3600 3300 0    50   BiDi ~ 0
REF_CLK
Wire Wire Line
	3650 3300 3600 3300
Wire Wire Line
	3650 3400 3600 3400
Wire Wire Line
	3650 3900 3600 3900
Wire Wire Line
	3650 5000 3600 5000
Wire Wire Line
	3650 5300 3600 5300
Wire Wire Line
	3650 5400 3600 5400
Wire Wire Line
	15750 8700 15500 8700
Wire Wire Line
	3650 8300 3600 8300
Wire Wire Line
	3600 8300 3600 8100
Wire Wire Line
	3600 8100 3650 8100
Wire Wire Line
	3150 8300 3600 8300
Connection ~ 3600 8300
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J1102
U 1 1 5DA8679B
P 8550 10450
F 0 "J1102" H 8600 10867 50  0000 C CNN
F 1 "20021111-00010T4LF" H 8600 10776 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 8550 10450 50  0001 C CNN
F 3 "~" H 8550 10450 50  0001 C CNN
	1    8550 10450
	1    0    0    -1  
$EndComp
NoConn ~ 8350 10550
NoConn ~ 8350 10650
Wire Wire Line
	8350 10450 8100 10450
Wire Wire Line
	8100 10450 8100 10350
Wire Wire Line
	8100 10350 8350 10350
$Comp
L power:GND #PWR01125
U 1 1 5DAA5490
P 8100 10700
F 0 "#PWR01125" H 8100 10450 50  0001 C CNN
F 1 "GND" H 8105 10527 50  0000 C CNN
F 2 "" H 8100 10700 50  0001 C CNN
F 3 "" H 8100 10700 50  0001 C CNN
	1    8100 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 10700 8100 10450
Connection ~ 8100 10450
Wire Wire Line
	8100 10150 8100 10250
Wire Wire Line
	8100 10250 8350 10250
Wire Wire Line
	8850 10250 9300 10250
Text Label 9300 10250 2    50   ~ 0
TMS_SWDIO
Wire Wire Line
	8850 10350 9300 10350
Text Label 9300 10350 2    50   ~ 0
TCK_SWCLK
Wire Wire Line
	8850 10650 9300 10650
Text Label 9300 10650 2    50   ~ 0
NRST
Text Label 15750 8700 2    50   ~ 0
NRST
Text Label 3150 8300 0    50   ~ 0
MCU_VDDA
$Comp
L power:GND #PWR01106
U 1 1 5DACCD5C
P 3600 8500
F 0 "#PWR01106" H 3600 8250 50  0001 C CNN
F 1 "GND" V 3605 8372 50  0000 R CNN
F 2 "" H 3600 8500 50  0001 C CNN
F 3 "" H 3600 8500 50  0001 C CNN
	1    3600 8500
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 8500 3650 8500
$Comp
L Device:C C1106
U 1 1 5DAD0A63
P 3600 8950
F 0 "C1106" H 3715 8996 50  0000 L CNN
F 1 "1u" H 3715 8905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3638 8800 50  0001 C CNN
F 3 "~" H 3600 8950 50  0001 C CNN
	1    3600 8950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 8700 3600 8700
Wire Wire Line
	3600 8800 3600 8700
Connection ~ 3600 8700
Wire Wire Line
	3600 8700 3650 8700
$Comp
L power:GND #PWR01110
U 1 1 5DAD7BE9
P 3600 9100
F 0 "#PWR01110" H 3600 8850 50  0001 C CNN
F 1 "GND" H 3605 8927 50  0000 C CNN
F 2 "" H 3600 9100 50  0001 C CNN
F 3 "" H 3600 9100 50  0001 C CNN
	1    3600 9100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 850  9350 850 
$Comp
L Device:C C1109
U 1 1 5DAEBFB7
P 650 10700
F 0 "C1109" H 765 10746 50  0000 L CNN
F 1 "100n" H 765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 688 10550 50  0001 C CNN
F 3 "~" H 650 10700 50  0001 C CNN
	1    650  10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1110
U 1 1 5DAECAD7
P 1150 10700
F 0 "C1110" H 1265 10746 50  0000 L CNN
F 1 "100n" H 1265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 1188 10550 50  0001 C CNN
F 3 "~" H 1150 10700 50  0001 C CNN
	1    1150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1111
U 1 1 5DAEE29B
P 1650 10700
F 0 "C1111" H 1765 10746 50  0000 L CNN
F 1 "100n" H 1765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 1688 10550 50  0001 C CNN
F 3 "~" H 1650 10700 50  0001 C CNN
	1    1650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1112
U 1 1 5DAEE2A1
P 2150 10700
F 0 "C1112" H 2265 10746 50  0000 L CNN
F 1 "100n" H 2265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2188 10550 50  0001 C CNN
F 3 "~" H 2150 10700 50  0001 C CNN
	1    2150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1113
U 1 1 5DAF1A5F
P 2650 10700
F 0 "C1113" H 2765 10746 50  0000 L CNN
F 1 "100n" H 2765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2688 10550 50  0001 C CNN
F 3 "~" H 2650 10700 50  0001 C CNN
	1    2650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1114
U 1 1 5DAF1A65
P 3150 10700
F 0 "C1114" H 3265 10746 50  0000 L CNN
F 1 "100n" H 3265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3188 10550 50  0001 C CNN
F 3 "~" H 3150 10700 50  0001 C CNN
	1    3150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1115
U 1 1 5DAF1A6B
P 3650 10700
F 0 "C1115" H 3765 10746 50  0000 L CNN
F 1 "100n" H 3765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3688 10550 50  0001 C CNN
F 3 "~" H 3650 10700 50  0001 C CNN
	1    3650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1116
U 1 1 5DAF1A71
P 4150 10700
F 0 "C1116" H 4265 10746 50  0000 L CNN
F 1 "100n" H 4265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 4188 10550 50  0001 C CNN
F 3 "~" H 4150 10700 50  0001 C CNN
	1    4150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1117
U 1 1 5DAF5DB7
P 4650 10700
F 0 "C1117" H 4765 10746 50  0000 L CNN
F 1 "100n" H 4765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 4688 10550 50  0001 C CNN
F 3 "~" H 4650 10700 50  0001 C CNN
	1    4650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1118
U 1 1 5DAF5DBD
P 5150 10700
F 0 "C1118" H 5265 10746 50  0000 L CNN
F 1 "100n" H 5265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5188 10550 50  0001 C CNN
F 3 "~" H 5150 10700 50  0001 C CNN
	1    5150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1119
U 1 1 5DAF5DC3
P 5650 10700
F 0 "C1119" H 5765 10746 50  0000 L CNN
F 1 "100n" H 5765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5688 10550 50  0001 C CNN
F 3 "~" H 5650 10700 50  0001 C CNN
	1    5650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1120
U 1 1 5DAF5DC9
P 6150 10700
F 0 "C1120" H 6265 10746 50  0000 L CNN
F 1 "100n" H 6265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6188 10550 50  0001 C CNN
F 3 "~" H 6150 10700 50  0001 C CNN
	1    6150 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  10550 650  10500
Wire Wire Line
	650  10500 1150 10500
Wire Wire Line
	6150 10500 6150 10550
Wire Wire Line
	5650 10550 5650 10500
Connection ~ 5650 10500
Wire Wire Line
	5650 10500 6150 10500
Wire Wire Line
	5150 10550 5150 10500
Connection ~ 5150 10500
Wire Wire Line
	5150 10500 5650 10500
Wire Wire Line
	4650 10550 4650 10500
Connection ~ 4650 10500
Wire Wire Line
	4650 10500 5150 10500
Wire Wire Line
	4150 10550 4150 10500
Connection ~ 4150 10500
Wire Wire Line
	4150 10500 4650 10500
Wire Wire Line
	3650 10550 3650 10500
Connection ~ 3650 10500
Wire Wire Line
	3650 10500 4150 10500
Wire Wire Line
	3150 10550 3150 10500
Connection ~ 3150 10500
Wire Wire Line
	2650 10550 2650 10500
Connection ~ 2650 10500
Wire Wire Line
	2650 10500 3150 10500
Wire Wire Line
	2150 10550 2150 10500
Connection ~ 2150 10500
Wire Wire Line
	2150 10500 2650 10500
Wire Wire Line
	1650 10550 1650 10500
Connection ~ 1650 10500
Wire Wire Line
	1650 10500 2150 10500
Wire Wire Line
	1150 10550 1150 10500
Connection ~ 1150 10500
Wire Wire Line
	1150 10500 1650 10500
Wire Wire Line
	650  10850 650  10900
Wire Wire Line
	650  10900 1150 10900
Wire Wire Line
	6150 10900 6150 10850
Wire Wire Line
	5650 10850 5650 10900
Connection ~ 5650 10900
Wire Wire Line
	5650 10900 6150 10900
Wire Wire Line
	5150 10850 5150 10900
Connection ~ 5150 10900
Wire Wire Line
	5150 10900 5650 10900
Wire Wire Line
	4650 10850 4650 10900
Connection ~ 4650 10900
Wire Wire Line
	4650 10900 5150 10900
Wire Wire Line
	4150 10850 4150 10900
Connection ~ 4150 10900
Wire Wire Line
	4150 10900 4650 10900
Wire Wire Line
	3650 10850 3650 10900
Connection ~ 3650 10900
Wire Wire Line
	3150 10850 3150 10900
Connection ~ 3150 10900
Wire Wire Line
	2650 10850 2650 10900
Connection ~ 2650 10900
Wire Wire Line
	2650 10900 3150 10900
Wire Wire Line
	2150 10850 2150 10900
Connection ~ 2150 10900
Wire Wire Line
	2150 10900 2650 10900
Wire Wire Line
	1650 10850 1650 10900
Connection ~ 1650 10900
Wire Wire Line
	1650 10900 2150 10900
Wire Wire Line
	1150 10850 1150 10900
Connection ~ 1150 10900
Wire Wire Line
	1150 10900 1650 10900
$Comp
L power:GND #PWR01128
U 1 1 5DB438B1
P 3650 10950
F 0 "#PWR01128" H 3650 10700 50  0001 C CNN
F 1 "GND" H 3655 10777 50  0000 C CNN
F 2 "" H 3650 10950 50  0001 C CNN
F 3 "" H 3650 10950 50  0001 C CNN
	1    3650 10950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 10950 3650 10900
Wire Wire Line
	3650 10500 3650 10450
$Comp
L Device:Ferrite_Bead FB1101
U 1 1 5DB6CBFD
P 6850 10500
F 0 "FB1101" V 6576 10500 50  0000 C CNN
F 1 "742792031" V 6667 10500 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 10500 50  0001 C CNN
F 3 "~" H 6850 10500 50  0001 C CNN
	1    6850 10500
	0    1    1    0   
$EndComp
$Comp
L Device:C C1122
U 1 1 5DB6D4C6
P 7100 10700
F 0 "C1122" H 7215 10746 50  0000 L CNN
F 1 "1u" H 7215 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 7138 10550 50  0001 C CNN
F 3 "~" H 7100 10700 50  0001 C CNN
	1    7100 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 10500 7100 10550
$Comp
L power:GND #PWR01129
U 1 1 5DB72CF5
P 7100 10950
F 0 "#PWR01129" H 7100 10700 50  0001 C CNN
F 1 "GND" H 7105 10777 50  0000 C CNN
F 2 "" H 7100 10950 50  0001 C CNN
F 3 "" H 7100 10950 50  0001 C CNN
	1    7100 10950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 10950 7100 10850
Wire Wire Line
	6650 10500 6700 10500
Wire Wire Line
	7100 10500 7600 10500
Text Label 7600 10500 2    50   ~ 0
MCU_VDDA
$Comp
L Connector_Generic:Conn_02x01 J1101
U 1 1 5DB87F87
P 4650 9900
F 0 "J1101" V 4654 9980 50  0000 L CNN
F 1 "Conn_02x01" V 4745 9980 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 9900 50  0001 C CNN
F 3 "~" H 4650 9900 50  0001 C CNN
	1    4650 9900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR01121
U 1 1 5DB88AAB
P 4650 10200
F 0 "#PWR01121" H 4650 9950 50  0001 C CNN
F 1 "GND" H 4655 10027 50  0000 C CNN
F 2 "" H 4650 10200 50  0001 C CNN
F 3 "" H 4650 10200 50  0001 C CNN
	1    4650 10200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1106
U 1 1 5DB8FF79
P 4650 9450
F 0 "R1106" H 4580 9404 50  0000 R CNN
F 1 "10k" H 4580 9495 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 4580 9450 50  0001 C CNN
F 3 "~" H 4650 9450 50  0001 C CNN
	1    4650 9450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 9700 4650 9650
Wire Wire Line
	4650 9650 5200 9650
Connection ~ 4650 9650
Wire Wire Line
	4650 9650 4650 9600
Text Label 5200 9650 2    50   ~ 0
MCU_DEFAULT
$Comp
L Device:C C1104
U 1 1 5DBA6521
P 2900 8100
F 0 "C1104" H 3015 8146 50  0000 L CNN
F 1 "2u2" H 3015 8055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2938 7950 50  0001 C CNN
F 3 "~" H 2900 8100 50  0001 C CNN
	1    2900 8100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 7900 2900 7900
Wire Wire Line
	2900 7900 2900 7950
$Comp
L Device:C C1103
U 1 1 5DBADF01
P 2450 8100
F 0 "C1103" H 2565 8146 50  0000 L CNN
F 1 "2u2" H 2565 8055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2488 7950 50  0001 C CNN
F 3 "~" H 2450 8100 50  0001 C CNN
	1    2450 8100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 8250 2450 8300
Wire Wire Line
	2450 8300 2700 8300
Wire Wire Line
	2900 8300 2900 8250
Wire Wire Line
	2450 7700 3650 7700
Wire Wire Line
	2450 7700 2450 7950
$Comp
L power:GND #PWR01104
U 1 1 5DBC271D
P 2700 8350
F 0 "#PWR01104" H 2700 8100 50  0001 C CNN
F 1 "GND" H 2705 8177 50  0000 C CNN
F 2 "" H 2700 8350 50  0001 C CNN
F 3 "" H 2700 8350 50  0001 C CNN
	1    2700 8350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 8350 2700 8300
Connection ~ 2700 8300
Wire Wire Line
	2700 8300 2900 8300
Wire Wire Line
	3600 900  3600 1200
Wire Wire Line
	3600 1200 3650 1200
Wire Wire Line
	3650 4500 3200 4500
Text Label 3200 4500 0    50   ~ 0
TMS_SWDIO
Wire Wire Line
	3650 4600 3200 4600
Text Label 3200 4600 0    50   ~ 0
TCK_SWCLK
Wire Wire Line
	15050 2300 15100 2300
Wire Wire Line
	15100 2500 15050 2500
Wire Wire Line
	15050 2600 15100 2600
Text HLabel 15750 8700 2    50   BiDi ~ 0
NRST
Text HLabel 15100 1900 2    50   Output ~ 0
TRIG_EN
Text HLabel 15100 1800 2    50   Output ~ 0
TRIG_OUT
Text HLabel 15100 1500 2    50   Input ~ 0
TRIG_IN
Wire Wire Line
	15100 1500 15050 1500
Wire Wire Line
	15100 1800 15050 1800
Wire Wire Line
	15050 1900 15100 1900
NoConn ~ 15050 2400
$Comp
L Device:C C1121
U 1 1 5DF2F119
P 6650 10700
F 0 "C1121" H 6765 10746 50  0000 L CNN
F 1 "100n" H 6765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6688 10550 50  0001 C CNN
F 3 "~" H 6650 10700 50  0001 C CNN
	1    6650 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 10550 6650 10500
Wire Wire Line
	6650 10500 6150 10500
Connection ~ 6150 10500
Wire Wire Line
	6150 10900 6650 10900
Wire Wire Line
	6650 10900 6650 10850
Connection ~ 6150 10900
Wire Wire Line
	3150 10500 3650 10500
Wire Wire Line
	3150 10900 3650 10900
Wire Wire Line
	3650 10900 4150 10900
Wire Wire Line
	3650 3500 3100 3500
Text Label 3100 3500 0    50   ~ 0
MCU_DEFAULT
Connection ~ 11350 9950
Wire Wire Line
	11350 9900 11350 9950
Wire Wire Line
	11350 9950 11350 10000
Wire Wire Line
	10950 9950 11350 9950
Wire Wire Line
	10950 10000 10950 9950
Wire Wire Line
	11350 10450 11350 10300
Wire Wire Line
	10950 10350 10950 10300
$Comp
L Device:R R1110
U 1 1 5E0F3C03
P 11350 10150
F 0 "R1110" H 11420 10196 50  0000 L CNN
F 1 "4k7" H 11420 10105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 11280 10150 50  0001 C CNN
F 3 "~" H 11350 10150 50  0001 C CNN
	1    11350 10150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1109
U 1 1 5E0F3906
P 10950 10150
F 0 "R1109" H 11020 10196 50  0000 L CNN
F 1 "4k7" H 11020 10105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 10880 10150 50  0001 C CNN
F 3 "~" H 10950 10150 50  0001 C CNN
	1    10950 10150
	1    0    0    -1  
$EndComp
Text Label 10850 10350 2    50   ~ 0
EEPROM_SDA
Text Label 10850 10450 2    50   ~ 0
EEPROM_SCL
Text Label 10850 10550 2    50   ~ 0
EEPROM_WP
Wire Wire Line
	10350 10550 10850 10550
Wire Wire Line
	9500 10450 9500 10550
Connection ~ 9500 10450
Wire Wire Line
	9550 10450 9500 10450
Connection ~ 9500 10550
Wire Wire Line
	9500 10750 9500 10550
$Comp
L power:GND #PWR01126
U 1 1 5E096BB8
P 9500 10750
F 0 "#PWR01126" H 9500 10500 50  0001 C CNN
F 1 "GND" H 9505 10577 50  0000 C CNN
F 2 "" H 9500 10750 50  0001 C CNN
F 3 "" H 9500 10750 50  0001 C CNN
	1    9500 10750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 10550 9550 10550
Wire Wire Line
	9500 10350 9500 10450
Wire Wire Line
	9550 10350 9500 10350
$Comp
L power:GND #PWR01127
U 1 1 5E08CDE4
P 9950 10750
F 0 "#PWR01127" H 9950 10500 50  0001 C CNN
F 1 "GND" H 9955 10577 50  0000 C CNN
F 2 "" H 9950 10750 50  0001 C CNN
F 3 "" H 9950 10750 50  0001 C CNN
	1    9950 10750
	1    0    0    -1  
$EndComp
$Comp
L Memory_EEPROM:24LC08 U1103
U 1 1 5E082698
P 9950 10450
F 0 "U1103" H 10300 10800 50  0000 C CNN
F 1 "24LC08B-E/MS" H 10300 10700 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 9950 10450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21710J.pdf" H 9950 10450 50  0001 C CNN
	1    9950 10450
	1    0    0    -1  
$EndComp
Connection ~ 6650 10500
Wire Wire Line
	7100 10500 7000 10500
Connection ~ 7100 10500
$Comp
L Device:R R1101
U 1 1 5E648C3B
P 3250 6550
F 0 "R1101" V 3043 6550 50  0000 C CNN
F 1 "680" V 3134 6550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 3180 6550 50  0001 C CNN
F 3 "~" H 3250 6550 50  0001 C CNN
	1    3250 6550
	0    1    1    0   
$EndComp
$Comp
L Device:R R1102
U 1 1 5E64A32E
P 3250 6950
F 0 "R1102" V 3043 6950 50  0000 C CNN
F 1 "560" V 3134 6950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 3180 6950 50  0001 C CNN
F 3 "~" H 3250 6950 50  0001 C CNN
	1    3250 6950
	0    1    1    0   
$EndComp
$Comp
L Device:R R1103
U 1 1 5E64A698
P 3250 7350
F 0 "R1103" V 3043 7350 50  0000 C CNN
F 1 "680" V 3134 7350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 3180 7350 50  0001 C CNN
F 3 "~" H 3250 7350 50  0001 C CNN
	1    3250 7350
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1101
U 1 1 5E66EF29
P 2900 6550
F 0 "D1101" H 2893 6295 50  0000 C CNN
F 1 "RED" H 2893 6386 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2900 6550 50  0001 C CNN
F 3 "~" H 2900 6550 50  0001 C CNN
	1    2900 6550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1102
U 1 1 5E66FC1B
P 2900 6950
F 0 "D1102" H 2893 6695 50  0000 C CNN
F 1 "GREEN" H 2893 6786 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2900 6950 50  0001 C CNN
F 3 "~" H 2900 6950 50  0001 C CNN
	1    2900 6950
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1103
U 1 1 5E69BE69
P 2900 7350
F 0 "D1103" H 2893 7095 50  0000 C CNN
F 1 "BLUE" H 2893 7186 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2900 7350 50  0001 C CNN
F 3 "~" H 2900 7350 50  0001 C CNN
	1    2900 7350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3100 7350 3050 7350
Wire Wire Line
	2700 7350 2700 6950
Wire Wire Line
	2700 6550 2750 6550
Wire Wire Line
	2750 7350 2700 7350
Wire Wire Line
	2700 6950 2750 6950
Connection ~ 2700 6950
Wire Wire Line
	2700 6950 2700 6550
Wire Wire Line
	3050 6950 3100 6950
Wire Wire Line
	3050 6550 3100 6550
Wire Wire Line
	2650 6950 2700 6950
$Comp
L Sensor_Humidity:HDC1080 U1102
U 1 1 5EF9C579
P 1250 9900
F 0 "U1102" H 1450 10250 50  0000 R CNN
F 1 "HDC1080" H 1550 10150 50  0000 R CNN
F 2 "Package_SON:Texas_PWSON-N6" H 1200 9650 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/hdc1080.pdf" H 850 10150 50  0001 C CNN
	1    1250 9900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01120
U 1 1 5EF9F2A6
P 1150 10200
F 0 "#PWR01120" H 1150 9950 50  0001 C CNN
F 1 "GND" H 1155 10027 50  0000 C CNN
F 2 "" H 1150 10200 50  0001 C CNN
F 3 "" H 1150 10200 50  0001 C CNN
	1    1150 10200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1107
U 1 1 5E375F7B
P 1650 9600
F 0 "R1107" H 1720 9646 50  0000 L CNN
F 1 "4k7" H 1720 9555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1580 9600 50  0001 C CNN
F 3 "~" H 1650 9600 50  0001 C CNN
	1    1650 9600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1108
U 1 1 5E37B6AD
P 2050 9600
F 0 "R1108" H 2120 9646 50  0000 L CNN
F 1 "4k7" H 2120 9555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1980 9600 50  0001 C CNN
F 3 "~" H 2050 9600 50  0001 C CNN
	1    2050 9600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 9800 1650 9800
Wire Wire Line
	1650 9800 1650 9750
Wire Wire Line
	1550 9900 2050 9900
Wire Wire Line
	2050 9900 2050 9750
Wire Wire Line
	1650 9450 1650 9400
Wire Wire Line
	1650 9400 1850 9400
Wire Wire Line
	2050 9400 2050 9450
Wire Wire Line
	1150 9500 1150 9600
Wire Wire Line
	1850 9350 1850 9400
Wire Wire Line
	3650 5800 3200 5800
Wire Wire Line
	3650 4000 3200 4000
Text Label 2550 9800 2    50   ~ 0
SENS_SCL
Text Label 2550 9900 2    50   ~ 0
SENS_SDA
Text Label 3200 4000 0    50   ~ 0
SENS_SCL
Text Label 3200 5800 0    50   ~ 0
SENS_SDA
Wire Wire Line
	15050 4100 15550 4100
Wire Wire Line
	15050 4200 15550 4200
Text Label 15550 4200 2    50   ~ 0
EEPROM_SDA
Text Label 15550 4100 2    50   ~ 0
EEPROM_SCL
Text Label 15550 4000 2    50   ~ 0
EEPROM_WP
Wire Wire Line
	15050 4000 15550 4000
NoConn ~ 8850 10450
NoConn ~ 8850 10550
Wire Wire Line
	6150 10200 6150 10100
$Comp
L power:GND #PWR01123
U 1 1 5EFC3E57
P 6150 10200
F 0 "#PWR01123" H 6150 9950 50  0001 C CNN
F 1 "GND" H 6155 10027 50  0000 C CNN
F 2 "" H 6150 10200 50  0001 C CNN
F 3 "" H 6150 10200 50  0001 C CNN
	1    6150 10200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 9800 6150 9700
$Comp
L Device:C C1108
U 1 1 5EFA260C
P 6150 9950
F 0 "C1108" H 6265 9996 50  0000 L CNN
F 1 "100n" H 6265 9905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6188 9800 50  0001 C CNN
F 3 "~" H 6150 9950 50  0001 C CNN
	1    6150 9950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 9800 5650 9700
Wire Wire Line
	5650 10200 5650 10100
$Comp
L power:GND #PWR01122
U 1 1 5E1764D7
P 5650 10200
F 0 "#PWR01122" H 5650 9950 50  0001 C CNN
F 1 "GND" H 5655 10027 50  0000 C CNN
F 2 "" H 5650 10200 50  0001 C CNN
F 3 "" H 5650 10200 50  0001 C CNN
	1    5650 10200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1107
U 1 1 5E17592C
P 5650 9950
F 0 "C1107" H 5765 9996 50  0000 L CNN
F 1 "100n" H 5765 9905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5688 9800 50  0001 C CNN
F 3 "~" H 5650 9950 50  0001 C CNN
	1    5650 9950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6550 3450 6550
Wire Wire Line
	3450 6550 3450 6200
Wire Wire Line
	3450 6200 3650 6200
Wire Wire Line
	3400 6950 3500 6950
Wire Wire Line
	3500 6950 3500 6300
Wire Wire Line
	3500 6300 3650 6300
Wire Wire Line
	3550 7350 3550 6400
Wire Wire Line
	3550 6400 3650 6400
Wire Wire Line
	3400 7350 3550 7350
Wire Wire Line
	10350 10350 10950 10350
Wire Wire Line
	10350 10450 11350 10450
Wire Wire Line
	1650 9800 2550 9800
Connection ~ 1650 9800
Wire Wire Line
	2050 9900 2550 9900
Connection ~ 2050 9900
Wire Wire Line
	1850 9400 2050 9400
Connection ~ 1850 9400
NoConn ~ 15050 2200
NoConn ~ 15050 2100
NoConn ~ 15050 4900
$Comp
L power:+3.3V #PWR01118
U 1 1 605724BF
P 8100 10150
F 0 "#PWR01118" H 8100 10000 50  0001 C CNN
F 1 "+3.3V" H 8115 10323 50  0000 C CNN
F 2 "" H 8100 10150 50  0001 C CNN
F 3 "" H 8100 10150 50  0001 C CNN
	1    8100 10150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01117
U 1 1 60572EDC
P 11350 9900
F 0 "#PWR01117" H 11350 9750 50  0001 C CNN
F 1 "+3.3V" H 11365 10073 50  0000 C CNN
F 2 "" H 11350 9900 50  0001 C CNN
F 3 "" H 11350 9900 50  0001 C CNN
	1    11350 9900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01119
U 1 1 60573E5C
P 9950 10150
F 0 "#PWR01119" H 9950 10000 50  0001 C CNN
F 1 "+3.3V" H 9965 10323 50  0000 C CNN
F 2 "" H 9950 10150 50  0001 C CNN
F 3 "" H 9950 10150 50  0001 C CNN
	1    9950 10150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01115
U 1 1 60574D4E
P 5650 9700
F 0 "#PWR01115" H 5650 9550 50  0001 C CNN
F 1 "+3.3V" H 5665 9873 50  0000 C CNN
F 2 "" H 5650 9700 50  0001 C CNN
F 3 "" H 5650 9700 50  0001 C CNN
	1    5650 9700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01116
U 1 1 60576A4F
P 6150 9700
F 0 "#PWR01116" H 6150 9550 50  0001 C CNN
F 1 "+3.3V" H 6165 9873 50  0000 C CNN
F 2 "" H 6150 9700 50  0001 C CNN
F 3 "" H 6150 9700 50  0001 C CNN
	1    6150 9700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01112
U 1 1 60579750
P 4650 9300
F 0 "#PWR01112" H 4650 9150 50  0001 C CNN
F 1 "+3.3V" H 4665 9473 50  0000 C CNN
F 2 "" H 4650 9300 50  0001 C CNN
F 3 "" H 4650 9300 50  0001 C CNN
	1    4650 9300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01103
U 1 1 6057A4C1
P 2650 6950
F 0 "#PWR01103" H 2650 6800 50  0001 C CNN
F 1 "+3.3V" V 2650 7100 50  0000 L CNN
F 2 "" H 2650 6950 50  0001 C CNN
F 3 "" H 2650 6950 50  0001 C CNN
	1    2650 6950
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR01114
U 1 1 6057DD2A
P 1150 9500
F 0 "#PWR01114" H 1150 9350 50  0001 C CNN
F 1 "+3.3V" H 1165 9673 50  0000 C CNN
F 2 "" H 1150 9500 50  0001 C CNN
F 3 "" H 1150 9500 50  0001 C CNN
	1    1150 9500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01113
U 1 1 6057FA53
P 1850 9350
F 0 "#PWR01113" H 1850 9200 50  0001 C CNN
F 1 "+3.3V" H 1865 9523 50  0000 C CNN
F 2 "" H 1850 9350 50  0001 C CNN
F 3 "" H 1850 9350 50  0001 C CNN
	1    1850 9350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01101
U 1 1 6057FCAA
P 9350 800
F 0 "#PWR01101" H 9350 650 50  0001 C CNN
F 1 "+3.3V" H 9365 973 50  0000 C CNN
F 2 "" H 9350 800 50  0001 C CNN
F 3 "" H 9350 800 50  0001 C CNN
	1    9350 800 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01105
U 1 1 60583AF5
P 15500 8350
F 0 "#PWR01105" H 15500 8200 50  0001 C CNN
F 1 "+3.3V" H 15515 8523 50  0000 C CNN
F 2 "" H 15500 8350 50  0001 C CNN
F 3 "" H 15500 8350 50  0001 C CNN
	1    15500 8350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01107
U 1 1 60600C51
P 3550 8700
F 0 "#PWR01107" H 3550 8550 50  0001 C CNN
F 1 "+3.3V" V 3550 8950 50  0000 C CNN
F 2 "" H 3550 8700 50  0001 C CNN
F 3 "" H 3550 8700 50  0001 C CNN
	1    3550 8700
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR01124
U 1 1 6060C8E4
P 3650 10450
F 0 "#PWR01124" H 3650 10300 50  0001 C CNN
F 1 "+3.3V" H 3665 10623 50  0000 C CNN
F 2 "" H 3650 10450 50  0001 C CNN
F 3 "" H 3650 10450 50  0001 C CNN
	1    3650 10450
	1    0    0    -1  
$EndComp
Wire Wire Line
	15500 8700 15300 8700
Wire Wire Line
	15300 8300 15050 8300
Wire Wire Line
	15050 8750 15050 8700
Wire Wire Line
	15300 8700 15300 8300
Wire Wire Line
	2500 1700 2750 1700
Connection ~ 2500 1700
Wire Wire Line
	2500 1750 2500 1700
$Comp
L power:GND #PWR01102
U 1 1 5DC11C96
P 2500 1750
F 0 "#PWR01102" H 2500 1500 50  0001 C CNN
F 1 "GND" H 2505 1577 50  0000 C CNN
F 2 "" H 2500 1750 50  0001 C CNN
F 3 "" H 2500 1750 50  0001 C CNN
	1    2500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1700 2750 1650
Wire Wire Line
	2250 1700 2500 1700
Wire Wire Line
	2250 1650 2250 1700
Wire Wire Line
	2250 900  2250 1350
Wire Wire Line
	2750 900  2250 900 
$Comp
L Device:C C1101
U 1 1 5DBE0C2D
P 2250 1500
F 0 "C1101" H 2365 1546 50  0000 L CNN
F 1 "8p" H 2365 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2288 1350 50  0001 C CNN
F 3 "~" H 2250 1500 50  0001 C CNN
	1    2250 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1102
U 1 1 5DBE0849
P 2750 1500
F 0 "C1102" H 2865 1546 50  0000 L CNN
F 1 "8p" H 2865 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2788 1350 50  0001 C CNN
F 3 "~" H 2750 1500 50  0001 C CNN
	1    2750 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 950  2750 900 
$Comp
L Device:Crystal Y1101
U 1 1 5DBCE9A3
P 2750 1100
F 0 "Y1101" V 2704 1231 50  0000 L CNN
F 1 "NX3225GD-8MHZ" V 2795 1231 50  0000 L CNN
F 2 "ETH1CLCR2:NX3225GD" H 2750 1100 50  0001 C CNN
F 3 "~" H 2750 1100 50  0001 C CNN
	1    2750 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 1250 2750 1300
Wire Wire Line
	3650 1300 2750 1300
Connection ~ 2750 1300
Wire Wire Line
	2750 1300 2750 1350
Wire Wire Line
	3600 900  2750 900 
Connection ~ 2750 900 
Text HLabel 15100 7800 2    50   Output ~ 0
SPI2_MOSI
Wire Wire Line
	15100 7800 15050 7800
Text HLabel 15100 7500 2    50   Output ~ 0
SPI2_NSS
Wire Wire Line
	15050 7500 15100 7500
Text HLabel 15100 7600 2    50   Output ~ 0
SPI2_SCK
Wire Wire Line
	15050 7600 15100 7600
Text HLabel 3600 3600 0    50   Output ~ 0
SPI1_NSS
Wire Wire Line
	3600 3600 3650 3600
Text HLabel 3600 3700 0    50   Output ~ 0
SPI1_SCK
Wire Wire Line
	3600 3700 3650 3700
Text HLabel 15100 3600 2    50   Output ~ 0
SPI1_MOSI
Wire Wire Line
	15100 3600 15050 3600
Text HLabel 3600 6100 0    50   Output ~ 0
SPI3_MOSI
Wire Wire Line
	3600 6100 3650 6100
Text HLabel 3600 6000 0    50   Input ~ 0
SPI3_MISO
Wire Wire Line
	3600 6000 3650 6000
Text HLabel 3600 5900 0    50   Output ~ 0
SPI3_SCK
Wire Wire Line
	3600 5900 3650 5900
Text HLabel 3600 4700 0    50   Output ~ 0
SPI3_NSS
Wire Wire Line
	3600 4700 3650 4700
NoConn ~ 3650 2500
NoConn ~ 3650 3200
NoConn ~ 3650 5100
NoConn ~ 3650 5200
Text HLabel 15100 3100 2    50   Output ~ 0
CXN_REL5
Text HLabel 15100 3200 2    50   Output ~ 0
CXN_REL4
Text HLabel 15100 3300 2    50   Output ~ 0
CXN_REL3
Text HLabel 15100 3400 2    50   Output ~ 0
CXN_REL2
Text HLabel 15100 3500 2    50   Output ~ 0
CXN_REL1
Wire Wire Line
	15100 3100 15050 3100
Wire Wire Line
	15050 3200 15100 3200
Wire Wire Line
	15100 3300 15050 3300
Wire Wire Line
	15050 3400 15100 3400
Wire Wire Line
	15100 3500 15050 3500
Text HLabel 15100 6700 2    50   Output ~ 0
IRR1
Text HLabel 15100 6800 2    50   Output ~ 0
IRR2
Text HLabel 15100 6900 2    50   Output ~ 0
IRR3
Text HLabel 15100 7000 2    50   Output ~ 0
IRR4
Wire Wire Line
	15100 6900 15050 6900
Wire Wire Line
	15100 6800 15050 6800
Wire Wire Line
	15050 6700 15100 6700
Wire Wire Line
	15100 7000 15050 7000
Text HLabel 15100 6600 2    50   Output ~ 0
IRR0
Wire Wire Line
	15050 6600 15100 6600
Text HLabel 15100 6500 2    50   Output ~ 0
VDIFF2
Text HLabel 15100 6400 2    50   Output ~ 0
VDIFF1
Wire Wire Line
	15050 6500 15100 6500
Wire Wire Line
	15050 6400 15100 6400
Text HLabel 15100 6300 2    50   Output ~ 0
VDIFF0
Wire Wire Line
	15050 6300 15100 6300
$Comp
L ETH1CLCR2:STM32H743ZI U1101
U 1 1 60365EFD
P 9350 4950
F 0 "U1101" H 14050 8850 50  0000 C CNN
F 1 "STM32H743ZI" H 14550 8850 50  0000 C CNN
F 2 "ETH1CLCR2:TQFP-144_20x20mm_P0.5mm" H 25250 6450 50  0001 C CNN
F 3 "" H 25250 6450 50  0001 C CNN
	1    9350 4950
	1    0    0    -1  
$EndComp
Text HLabel 15100 7200 2    50   Output ~ 0
IDIFF1
Text HLabel 15100 7100 2    50   Output ~ 0
IDIFF0
Wire Wire Line
	15050 7100 15100 7100
Wire Wire Line
	15100 7200 15050 7200
NoConn ~ 15050 5300
NoConn ~ 15050 5400
NoConn ~ 15050 5500
NoConn ~ 15050 5600
NoConn ~ 15050 5700
NoConn ~ 15050 5800
NoConn ~ 15050 5900
NoConn ~ 15050 6000
NoConn ~ 15050 4700
NoConn ~ 15050 4600
NoConn ~ 15050 4400
NoConn ~ 15050 4300
NoConn ~ 15050 3900
NoConn ~ 15050 3800
NoConn ~ 15050 2700
NoConn ~ 15050 2000
NoConn ~ 15050 1700
NoConn ~ 15050 1600
NoConn ~ 15050 1400
NoConn ~ 15050 1300
NoConn ~ 15050 1200
NoConn ~ 3650 2600
NoConn ~ 3650 2000
NoConn ~ 3650 1900
NoConn ~ 3650 1700
NoConn ~ 3650 1800
NoConn ~ 3650 1600
NoConn ~ 3650 1500
NoConn ~ 3650 4100
NoConn ~ 3650 4200
NoConn ~ 3650 4300
NoConn ~ 3650 4400
NoConn ~ 3650 4900
NoConn ~ 3650 5500
NoConn ~ 3650 5600
NoConn ~ 3650 5700
Text HLabel 15100 2900 2    50   Input ~ 0
ADC1_RVS1
Text HLabel 15100 3000 2    50   Input ~ 0
ADC1_RVS2
Wire Wire Line
	15100 3000 15050 3000
Wire Wire Line
	15050 2900 15100 2900
NoConn ~ 3650 2100
NoConn ~ 3650 2200
NoConn ~ 3650 2300
NoConn ~ 3650 2400
NoConn ~ 15050 5000
NoConn ~ 15050 4800
NoConn ~ 15050 5100
NoConn ~ 15050 5200
NoConn ~ 15050 7700
Text HLabel 15100 3700 2    50   Output ~ 0
FGEN_SEL
Wire Wire Line
	15100 3700 15050 3700
Text HLabel 3600 3800 0    50   Input ~ 0
SPI1_MISO
Wire Wire Line
	3650 3800 3600 3800
NoConn ~ 15050 7400
NoConn ~ 15050 7300
NoConn ~ 15050 6100
Text HLabel 3600 2700 0    50   Output ~ 0
DDS_DIV2
Text HLabel 3600 2800 0    50   Output ~ 0
DDS_DIV4
Text HLabel 3600 2900 0    50   Output ~ 0
DDS_DIV8
Text HLabel 3600 3000 0    50   Output ~ 0
~DDS_DIV10
Wire Wire Line
	3650 2700 3600 2700
Wire Wire Line
	3600 2800 3650 2800
Wire Wire Line
	3650 2900 3600 2900
Wire Wire Line
	3600 3000 3650 3000
$EndSCHEMATC
