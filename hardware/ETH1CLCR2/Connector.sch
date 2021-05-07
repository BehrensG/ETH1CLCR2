EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 13
Title "Connector"
Date "2020-03-07"
Rev "1.00"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 4350 5900
NoConn ~ 4350 5800
NoConn ~ 4350 5700
NoConn ~ 4350 5600
NoConn ~ 4350 5500
NoConn ~ 4350 5400
NoConn ~ 4350 5300
NoConn ~ 4350 5200
Text HLabel 4050 4900 0    50   BiDi ~ 0
TX-
Text HLabel 4050 4800 0    50   BiDi ~ 0
RX-
Text HLabel 4050 4700 0    50   BiDi ~ 0
TX+
Text HLabel 4050 4600 0    50   BiDi ~ 0
RX+
Text Label 4100 4900 0    50   ~ 0
TX-
Text Label 4100 4700 0    50   ~ 0
TX+
Text Label 4100 4800 0    50   ~ 0
RX-
Text Label 4100 4600 0    50   ~ 0
RX+
NoConn ~ 4350 4100
NoConn ~ 4350 4000
NoConn ~ 4350 3700
NoConn ~ 4350 3600
NoConn ~ 4350 3500
NoConn ~ 4350 3400
NoConn ~ 4350 4500
NoConn ~ 4350 4400
Wire Wire Line
	4300 5050 4300 5100
Connection ~ 4300 5050
Wire Wire Line
	4250 5050 4300 5050
$Comp
L power:Earth #PWR0409
U 1 1 5DECE77F
P 4250 5050
F 0 "#PWR0409" H 4250 4800 50  0001 C CNN
F 1 "Earth" H 4250 4900 50  0001 C CNN
F 2 "" H 4250 5050 50  0001 C CNN
F 3 "~" H 4250 5050 50  0001 C CNN
	1    4250 5050
	0    1    1    0   
$EndComp
Wire Wire Line
	4300 5100 4350 5100
Wire Wire Line
	4300 5000 4300 5050
Wire Wire Line
	4350 5000 4300 5000
NoConn ~ 4350 900 
NoConn ~ 4350 800 
Wire Wire Line
	4350 4900 4050 4900
Wire Wire Line
	4350 4800 4050 4800
Wire Wire Line
	4350 4700 4050 4700
Wire Wire Line
	4350 4600 4050 4600
Wire Wire Line
	4300 6150 4300 6100
Connection ~ 4300 6150
Wire Wire Line
	4250 6150 4300 6150
Wire Wire Line
	4300 6200 4300 6150
Connection ~ 4300 6200
Wire Wire Line
	4350 6200 4300 6200
Wire Wire Line
	4300 6100 4300 6000
Connection ~ 4300 6100
Wire Wire Line
	4350 6100 4300 6100
Wire Wire Line
	4300 6000 4350 6000
Wire Wire Line
	4300 6300 4300 6200
Wire Wire Line
	4350 6300 4300 6300
NoConn ~ 4350 6400
NoConn ~ 4350 6500
NoConn ~ 4350 6600
NoConn ~ 4350 6700
Wire Wire Line
	4300 6950 4300 6900
Connection ~ 4300 6950
Wire Wire Line
	4250 6950 4300 6950
Wire Wire Line
	4300 7000 4300 6950
Connection ~ 4300 7000
Wire Wire Line
	4350 7000 4300 7000
Wire Wire Line
	4300 6900 4300 6800
Connection ~ 4300 6900
Wire Wire Line
	4350 6900 4300 6900
Wire Wire Line
	4300 6800 4350 6800
Wire Wire Line
	4300 7100 4300 7000
Wire Wire Line
	4350 7100 4300 7100
$Comp
L Connector:C64AC J401
U 1 1 5DE8758D
P 4650 4000
F 0 "J401" H 4830 4096 50  0000 L CNN
F 1 "C64AC" H 4830 4005 50  0000 L CNN
F 2 "ETH1CLCR2:Socket_DIN41612-CaseC1-AC-Male-64Pin-2rows" H 4650 4050 50  0001 C CNN
F 3 " ~" H 4650 4050 50  0001 C CNN
	1    4650 4000
	1    0    0    -1  
$EndComp
NoConn ~ 4350 2200
NoConn ~ 4350 2300
NoConn ~ 4350 2400
NoConn ~ 4350 2500
NoConn ~ 4350 2600
NoConn ~ 4350 2700
NoConn ~ 4350 2800
NoConn ~ 4350 2900
NoConn ~ 4350 3000
NoConn ~ 4350 3100
NoConn ~ 4350 3200
NoConn ~ 4350 3300
Wire Wire Line
	4350 4200 4300 4200
Wire Wire Line
	4300 4200 4300 4250
Wire Wire Line
	4300 4300 4350 4300
$Comp
L power:Earth #PWR0408
U 1 1 5DED2C4C
P 4250 4250
F 0 "#PWR0408" H 4250 4000 50  0001 C CNN
F 1 "Earth" H 4250 4100 50  0001 C CNN
F 2 "" H 4250 4250 50  0001 C CNN
F 3 "~" H 4250 4250 50  0001 C CNN
	1    4250 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 4250 4300 4250
Connection ~ 4300 4250
Wire Wire Line
	4300 4250 4300 4300
$Comp
L power:GNDPWR #PWR0410
U 1 1 607E4852
P 4250 6150
F 0 "#PWR0410" H 4250 5950 50  0001 C CNN
F 1 "GNDPWR" V 4254 6041 50  0000 R CNN
F 2 "" H 4250 6100 50  0001 C CNN
F 3 "" H 4250 6100 50  0001 C CNN
	1    4250 6150
	0    1    1    0   
$EndComp
$Comp
L power:+24V #PWR0411
U 1 1 607E51D3
P 4250 6950
F 0 "#PWR0411" H 4250 6800 50  0001 C CNN
F 1 "+24V" V 4265 7078 50  0000 L CNN
F 2 "" H 4250 6950 50  0001 C CNN
F 3 "" H 4250 6950 50  0001 C CNN
	1    4250 6950
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:GND_TRIG #PWR0407
U 1 1 607EBE86
P 4300 3900
F 0 "#PWR0407" H 4300 3650 50  0001 C CNN
F 1 "GND_TRIG" V 4305 3772 50  0000 R CNN
F 2 "" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	4300 3900 4350 3900
Text HLabel 4250 3800 0    50   BiDi ~ 0
EXT_TRIG
Wire Wire Line
	4250 3800 4350 3800
Wire Wire Line
	2700 1050 2400 1050
Wire Wire Line
	2700 1750 2400 1750
Wire Wire Line
	2700 1400 2400 1400
Wire Wire Line
	2700 2100 2400 2100
Wire Wire Line
	2700 2450 2400 2450
Wire Wire Line
	4350 1000 4300 1000
Wire Wire Line
	4300 1000 4300 1050
Wire Wire Line
	4300 1100 4350 1100
Wire Wire Line
	4350 1200 4300 1200
Wire Wire Line
	4300 1200 4300 1250
Wire Wire Line
	4300 1300 4350 1300
Wire Wire Line
	4350 1400 4300 1400
Wire Wire Line
	4300 1400 4300 1450
Wire Wire Line
	4300 1500 4350 1500
Wire Wire Line
	4350 1600 4300 1600
Wire Wire Line
	4300 1600 4300 1650
Wire Wire Line
	4300 1700 4350 1700
Wire Wire Line
	4350 1800 4300 1800
Wire Wire Line
	4300 1800 4300 1850
Wire Wire Line
	4300 1900 4350 1900
Wire Wire Line
	4350 2000 4300 2000
Wire Wire Line
	4300 2000 4300 2050
Wire Wire Line
	4300 2100 4350 2100
$Comp
L ETH1CLCR2:HE3621A0510 K401
U 1 1 624DD31E
P 2850 1050
F 0 "K401" V 3065 1050 50  0000 C CNN
F 1 "HE3621A0510" V 2974 1050 50  0000 C CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 3100 1000 50  0001 C CNN
F 3 "" H 3100 1000 50  0001 C CNN
	1    2850 1050
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K401
U 2 1 624DE370
P 5200 1600
F 0 "K401" H 5278 1646 50  0000 L CNN
F 1 "HE3621A0510" H 5278 1555 50  0000 L CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 5450 1550 50  0001 C CNN
F 3 "" H 5450 1550 50  0001 C CNN
	2    5200 1600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K402
U 1 1 624E3116
P 2850 1400
F 0 "K402" V 3065 1400 50  0000 C CNN
F 1 "HE3621A0510" V 2974 1400 50  0000 C CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 3100 1350 50  0001 C CNN
F 3 "" H 3100 1350 50  0001 C CNN
	1    2850 1400
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K402
U 2 1 624E311C
P 5900 1600
F 0 "K402" H 5978 1646 50  0000 L CNN
F 1 "HE3621A0510" H 5978 1555 50  0000 L CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 6150 1550 50  0001 C CNN
F 3 "" H 6150 1550 50  0001 C CNN
	2    5900 1600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K403
U 1 1 624E50C0
P 2850 1750
F 0 "K403" V 3065 1750 50  0000 C CNN
F 1 "HE3621A0510" V 2974 1750 50  0000 C CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 3100 1700 50  0001 C CNN
F 3 "" H 3100 1700 50  0001 C CNN
	1    2850 1750
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K403
U 2 1 624E50C6
P 6600 1600
F 0 "K403" H 6678 1646 50  0000 L CNN
F 1 "HE3621A0510" H 6678 1555 50  0000 L CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 6850 1550 50  0001 C CNN
F 3 "" H 6850 1550 50  0001 C CNN
	2    6600 1600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K404
U 1 1 624E7466
P 2850 2100
F 0 "K404" V 3065 2100 50  0000 C CNN
F 1 "HE3621A0510" V 2974 2100 50  0000 C CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 3100 2050 50  0001 C CNN
F 3 "" H 3100 2050 50  0001 C CNN
	1    2850 2100
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K404
U 2 1 624E746C
P 7300 1600
F 0 "K404" H 7378 1646 50  0000 L CNN
F 1 "HE3621A0510" H 7378 1555 50  0000 L CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 7550 1550 50  0001 C CNN
F 3 "" H 7550 1550 50  0001 C CNN
	2    7300 1600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K405
U 1 1 624E9C1A
P 2850 2450
F 0 "K405" V 3065 2450 50  0000 C CNN
F 1 "HE3621A0510" V 2974 2450 50  0000 C CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 3100 2400 50  0001 C CNN
F 3 "" H 3100 2400 50  0001 C CNN
	1    2850 2450
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR2:HE3621A0510 K405
U 2 1 624E9C20
P 8000 1600
F 0 "K405" H 8078 1646 50  0000 L CNN
F 1 "HE3621A0510" H 8078 1555 50  0000 L CNN
F 2 "ETH1CLCR2:HE360_x-5050462-8" H 8250 1550 50  0001 C CNN
F 3 "" H 8250 1550 50  0001 C CNN
	2    8000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1050 4050 1050
Connection ~ 4300 1050
Wire Wire Line
	4300 1050 4300 1100
Text Label 4050 1050 0    50   ~ 0
A
Wire Wire Line
	4300 1250 4050 1250
Text Label 4050 1250 0    50   ~ 0
B
Connection ~ 4300 1250
Wire Wire Line
	4300 1250 4300 1300
Wire Wire Line
	4300 1450 4050 1450
Text Label 4050 1450 0    50   ~ 0
C
Connection ~ 4300 1450
Wire Wire Line
	4300 1450 4300 1500
Wire Wire Line
	4300 1650 4050 1650
Text Label 4050 1650 0    50   ~ 0
D
Connection ~ 4300 1650
Wire Wire Line
	4300 1650 4300 1700
Wire Wire Line
	4300 1850 4050 1850
Text Label 4050 1850 0    50   ~ 0
E
Connection ~ 4300 1850
Wire Wire Line
	4300 1850 4300 1900
Wire Wire Line
	4300 2050 4050 2050
Text Label 4050 2050 0    50   ~ 0
F
Connection ~ 4300 2050
Wire Wire Line
	4300 2050 4300 2100
Wire Wire Line
	3000 1050 3250 1050
Text Label 3250 1050 2    50   ~ 0
A
Wire Wire Line
	3000 1400 3250 1400
Text Label 3250 1400 2    50   ~ 0
B
Wire Wire Line
	3000 1750 3250 1750
Text Label 3250 1750 2    50   ~ 0
C
Wire Wire Line
	3000 2100 3250 2100
Text Label 3250 2100 2    50   ~ 0
E
Wire Wire Line
	3000 2450 3250 2450
Text Label 3250 2450 2    50   ~ 0
F
Wire Wire Line
	5200 1450 5200 1400
Wire Wire Line
	8000 1400 8000 1450
Wire Wire Line
	7300 1450 7300 1400
Wire Wire Line
	5200 1400 5900 1400
Connection ~ 7300 1400
Wire Wire Line
	7300 1400 8000 1400
Wire Wire Line
	6600 1450 6600 1400
Connection ~ 6600 1400
Wire Wire Line
	6600 1400 7300 1400
Wire Wire Line
	5900 1400 5900 1450
Connection ~ 5900 1400
Wire Wire Line
	5900 1400 6600 1400
$Comp
L power:+5V #PWR0401
U 1 1 6259093E
P 6600 1350
F 0 "#PWR0401" H 6600 1200 50  0001 C CNN
F 1 "+5V" H 6615 1523 50  0000 C CNN
F 2 "" H 6600 1350 50  0001 C CNN
F 3 "" H 6600 1350 50  0001 C CNN
	1    6600 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1350 6600 1400
$Comp
L Transistor_Array:ULN2003A U401
U 1 1 625968E5
P 9400 2000
F 0 "U401" H 9400 2667 50  0000 C CNN
F 1 "ULN2003A" H 9400 2576 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 9450 1450 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2003a.pdf" H 9500 1800 50  0001 C CNN
	1    9400 2000
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0402
U 1 1 6259B37C
P 9000 1600
F 0 "#PWR0402" H 9000 1450 50  0001 C CNN
F 1 "+5V" V 9000 1750 50  0000 L CNN
F 2 "" H 9000 1600 50  0001 C CNN
F 3 "" H 9000 1600 50  0001 C CNN
	1    9000 1600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0406
U 1 1 625A0234
P 9400 2600
F 0 "#PWR0406" H 9400 2350 50  0001 C CNN
F 1 "GND" H 9405 2427 50  0000 C CNN
F 2 "" H 9400 2600 50  0001 C CNN
F 3 "" H 9400 2600 50  0001 C CNN
	1    9400 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1800 8000 1800
Wire Wire Line
	8000 1800 8000 1750
Wire Wire Line
	9000 1900 7300 1900
Wire Wire Line
	7300 1900 7300 1750
Wire Wire Line
	9000 2000 6600 2000
Wire Wire Line
	6600 2000 6600 1750
Wire Wire Line
	9000 2100 5900 2100
Wire Wire Line
	5900 2100 5900 1750
Wire Wire Line
	9000 2200 5200 2200
Wire Wire Line
	5200 2200 5200 1750
NoConn ~ 9000 2300
NoConn ~ 9000 2400
NoConn ~ 9800 2400
NoConn ~ 9800 2300
Text HLabel 9850 1800 2    50   Input ~ 0
CXN_REL5
Wire Wire Line
	9850 1800 9800 1800
Text HLabel 9850 1900 2    50   Input ~ 0
CXN_REL4
Wire Wire Line
	9850 1900 9800 1900
Text HLabel 9850 2000 2    50   Input ~ 0
CXN_REL3
Wire Wire Line
	9850 2000 9800 2000
Text HLabel 9850 2100 2    50   Input ~ 0
CXN_REL2
Wire Wire Line
	9850 2100 9800 2100
Text HLabel 9850 2200 2    50   Input ~ 0
CXN_REL1
Wire Wire Line
	9850 2200 9800 2200
$Comp
L power:GND #PWR0405
U 1 1 626006E6
P 10700 2100
F 0 "#PWR0405" H 10700 1850 50  0001 C CNN
F 1 "GND" H 10705 1927 50  0000 C CNN
F 2 "" H 10700 2100 50  0001 C CNN
F 3 "" H 10700 2100 50  0001 C CNN
	1    10700 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C401
U 1 1 626011D0
P 10700 1950
F 0 "C401" H 10815 1996 50  0000 L CNN
F 1 "1u" H 10815 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 10738 1800 50  0001 C CNN
F 3 "~" H 10700 1950 50  0001 C CNN
	1    10700 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0404
U 1 1 626034E9
P 10700 1800
F 0 "#PWR0404" H 10700 1650 50  0001 C CNN
F 1 "+5V" H 10715 1973 50  0000 C CNN
F 2 "" H 10700 1800 50  0001 C CNN
F 3 "" H 10700 1800 50  0001 C CNN
	1    10700 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0403
U 1 1 61964568
P 2400 1750
F 0 "#PWR0403" H 2400 1500 50  0001 C CNN
F 1 "GND" V 2405 1622 50  0000 R CNN
F 2 "" H 2400 1750 50  0001 C CNN
F 3 "" H 2400 1750 50  0001 C CNN
	1    2400 1750
	0    1    1    0   
$EndComp
Text HLabel 2400 1050 0    50   Input ~ 0
H_CUR
Text HLabel 2400 1400 0    50   Input ~ 0
L_CUR
Text HLabel 2400 2100 0    50   Input ~ 0
H_POT
Text HLabel 2400 2450 0    50   Input ~ 0
L_POT
$EndSCHEMATC
