/* ========================================
 *
 * SYSTEM STRINGS
 *
 * Copyright Gobee Srl 2018-2019
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Logic brainstorm
 *
 * ========================================
*/

// ### PRESENTATION ###
#define STR_FW_VERS "GoBee Director FW V.0.0B-T34 24/01/19 C3.0\r\n"
#define STR_COPY	"(c) 2017-2019 Gobee Srl (www.gobee.it)\r\n"
#define STR_AUTHOR1 "FW and HW Designed by Graziano G. Ravizza\r\n"
#define STR_AUTHOR2 "MECHA     Designed by Cy.Pag. Team and Davide Danielli\r\n"
#define STR_AUTHOR3 "CLUs      Designed by Gabriele Pisaneschi and Graziano G. Ravizza\r\n"
#define STR_AUTHOR4 "          Special Thanks to Fabio Allegreni, Claudio Palumbo and all Cy.Pag. Team!\r\n"


// ### SCANNER/PARSER ERRORS ###
#define STR_ERROR0  "#ERROR0: Syntax Error!"
#define STR_ERROR1	"#ERROR1: Too much parameters!"
#define STR_ERROR2  "#ERROR2: More parameters needed!"
#define STR_ERROR3  "#ERROR3: Bad parameter(s)!"
#define STR_ERROR4  "#ERROR4: Bad command!"
#define STR_ERROR5	"#ERROR5: Number not allowed!"
#define STR_ERROR6	"#ERROR6: Axis may be [pan,tilt]!"
#define STR_ERROR7	"#ERROR7: EEPROM row out of bounds!"


// ### WARNINGS ###
#define STR_WARN1	"#WARNING1: too much characters!"
#define STR_WARN2   "#WARNING2: command not applicable when USB IN!"

// ### FAULTS ###
#define STR_FULT0   "NONE: ALL OK!\r\n"
#define STR_FULT2   "@FAULT: LOW VCC! (VCC<11V)\r\n"
#define STR_FULTP   "@FAULT#01: PAN  AXIS HAS PROBLEMS!\r\n"
#define STR_FULTT   "@FAULT#02: TILT AXIS HAS PROBLEMS!\r\n"
#define STR_FULTI	"@FAULT#10: FEEDBACK ENCODER INVALID TRANSITIONS!\r\n"

// ### HELPS ###
#define STR_HELP_PRES1 "GoBee Director Console Commands:\r\n"
#define STR_HELP_PRES2 "  (type HELP <command> for detailed descriptions)\r\n"
#define STR_HELP_HELP0 "HELP Q: helps Q table codes\r\n"
#define STR_HELP_HELP1 "HELP,H,?: this help\r\n"
#define STR_HELP_PRES4 "=================================================\r\n"

#define STR_HELP_PROM1 "PROMPT: shows prompt flags\r\n"
#define STR_HELP_PROM2 "  PROMPT\r\n"

#define STR_HELP_BOOT1 "BOOT: starts FW Bootloading\r\n"
#define STR_HELP_BOOT2 "  BOOT\r\n"


#define STR_HELP_PRES5 "- Motor Control CMDs               -\r\n"
#define STR_HELP_PRES6 "------------------------------------\r\n"
#define STR_HELP_ENERG "  EN[ERGIZE]             (Energize motor)\r\n"
#define STR_HELP_DEENE "  DEEN[ERGIZE]           (Deenergize motor)\r\n"


#define STR_HELP_PRES7 "- System TEST CMDs                 -\r\n"
#define STR_HELP_PRES8 "------------------------------------\r\n"
#define STR_HELP_TBUZZ "  TBUZ                   (Tests Buzzer)\r\n"
#define STR_HELP_TLORA "  TLORA                  (Test LoRa HW)\r\n"
//#define STR_HELP_TMOTP "  TMOTP <speed>          (Tests Pan  Motor CW & CCW Rotation  -1024<=speed<=1024)\r\n"
//#define STR_HELP_TMOTT "  TMOTT <speed>          (Tests Tilt Motor CW & CCW Rotation  -1024<=speed<=1024)\r\n"
#define STR_HELP_TINV  "  T[ITG]3701             (Tests Invensense ITG-3701 3D Digital Gyro)\r\n"
#define STR_HELP_STSM  "  STOP[MAP]SM            (Stops the MAPPING STATE MACHINE (energize to restart))\r\n" 
#define STR_HELP_DMAP  "  VJ[OY]P                (Pan  Virtual Joystick a=cw d=ccw s=stop)\r\n"
#define STR_HELP_DMAT  "  VJ[OY]T                (Tilt Virtual Joystick w=cw z=ccw s=stop)\r\n" 
#define STR_HELP_DMPT  "  VJ[OY]                 (Pan+Tilt Virtual Joystick)\r\n"

#define STR_HELP_PRES9 "- CLU CMDs                         -\r\n"
#define STR_HELP_PRESA "------------------------------------\r\n"
#define STR_HELP_AGSTA "  CLUEXEC <clu_num>      (Start CLU   0 <= clu_num <= 49)\r\n"
#define STR_HELP_AGSTO "  CLUSEQ  <pause>        (Start CLU sequence with <pause> msec)\r\n"
//#define STR_HELP_AGSTO "  AGMSTOP:  Analog  Gyro Mean Calculation Stop\r\n"
//#define STR_HELP_DGSTA "  DGMSTART: Digital Gyro Mean Calculation Start\r\n"
//#define STR_HELP_DGSTO "  DGMSTOP:  Digital Gyro Mean Calculation Stop\r\n"
//#define STR_HELP_DGZER "  ZG:       SET ZERO Angle Integral and Estimation\r\n"
//#define STR_HELP_ANULL "  ANULL:    Analog Gyroscope Automatic NULL procedure\r\n"

//#define STR_HELP_DAS01 "- Digital Acquisition System CMDs  -\r\n"
//#define STR_HELP_DAS02 "------------------------------------\r\n"
//#define STR_HELP_DAS03 "  $DAS          : Reference Sawtooth Output Start\r\n"
//#define STR_HELP_DAS04 "  $DASC         : Control  Vars Output Start\r\n"
//#define STR_HELP_DAS05 "  $DASI         : Inertial Vars Output Start\r\n"
//#define STR_HELP_DAS06 "  $DASBUF1,  $B1: Control  Vars Buffering Start\r\n"
//#define STR_HELP_DAS07 "  $DASBUF2,  $B2: Inertial Vars Buffering Start\r\n"
//#define STR_HELP_DAS08 "  $DASDBUF1, $D1: Control  Vars Debuffering Start\r\n"
//#define STR_HELP_DAS09 "  $DASDBUF2, $D2: Inertial Vars Debuffering Start\r\n"
//#define STR_HELP_DAS0A "  $DKO,      $$ : DAS Stop\r\n"

#define STR_HELP_MOV01 "- Mover CMDs                       -\r\n"
#define STR_HELP_MOV02 "------------------------------------\r\n"
#define STR_HELP_MOV03 "  MOVP[ATH]     <n>      (Start Mover on Path 0..15)\r\n"
#define STR_HELP_MOV04 "  GOTOH[OME]             (Start Mover to Goto Home)\r\n"
#define STR_HELP_MOV05 "  G[OTOQ]       <n> <t>  (Start Mover to Goto Q number <n> in time <t> sec)\r\n"
//#define STR_HELP_MOV05 "  CIAK                   (Start Mover to make CIAK)\r\n"

#define STR_PROMPT0 "Prompt Flags:\r\n"
#define STR_PROMPT1 "  [F]                  --> GoBee FAULT\r\n"
#define STR_PROMPT2 "  [FBK=AGYRO_VEL]      --> Analog Gyroscope Feedback (Velocity - Direct LOS)\r\n"
#define STR_PROMPT3 "  [FBK=ENC_POS]        --> Digital Encoder Feedback (Position - Test Only)\r\n"
#define STR_PROMPT4 "  [FBK=OPEN]           --> No Feedback (Open Loop)\r\n"


#define STR_HELP_SETT1 "SET:  set GoBee parameters\r\n"
#define STR_HELP_SETT2  "  SET POL[ARITY]P   <polarity> (Sets Pan  Motor Polarity)\r\n"
#define STR_HELP_SETT2T "  SET POL[ARITY]T   <polarity> (Sets Tilt Motor Polarity)\r\n"
#define STR_HELP_SETT3  "  SET KPP           <kpvalue>  (Sets Pan  Motor PID Kp)\r\n"
#define STR_HELP_SETT3T "  SET KPT           <kpvalue>  (Sets Tilt Motor PID Kp)\r\n"
#define STR_HELP_SETT4  "  SET KDP           <kdvalue>  (Sets Pan  Motor PID Kd)\r\n"
#define STR_HELP_SETT4T "  SET KDT           <kdvalue>  (Sets Tilt Motor PID Kd)\r\n"
#define STR_HELP_SETT5  "  SET KIP           <kivalue>  (Sets Pan  Motor PID Ki)\r\n"
#define STR_HELP_SETT5T "  SET KIT           <kivalue>  (Sets Tilt Motor PID Ki)\r\n"
#define STR_HELP_SETT6  "  SET KSIP          <ksivalue> (Sets Pan  Motor PID Ksi)\r\n"
#define STR_HELP_SETT6T "  SET KSIT          <ksivalue> (Sets Tilt Motor PID Ksi)\r\n"

#define STR_HELP_SETT6U "  SET L[IMIT]CP     <onoff>    (Sets Pan  Motor Limit Control)\r\n"
#define STR_HELP_SETT6V "  SET L[IMIT]CT     <onoff>    (Sets Tilt Motor Limit Control)\r\n"

#define STR_HELP_SET61  "  SET INV[ABS]P     <onoff>    (Pan  Absolute Sensor Invertion)\r\n"
#define STR_HELP_SET62  "  SET RATIO[ABS]P   <ratio>    (Pan  Absolute Sensor over Encoder Ratio)\r\n"
#define STR_HELP_SET63  "  SET Z[EROABS]P               (Pan  Absolute Sensor Zero calc procedure)\r\n"
#define STR_HELP_SET64  "  SET L[IMIT]MINP              (Pan  Absolute Sensor Limit MIN calc procedure)\r\n"
#define STR_HELP_SET65  "  SET L[IMIT]MAXP              (Pan  Absolute Sensor Limit MAX calc procedure)\r\n"
#define STR_HELP_SET66  "  SET L[IMIT]HYSTP  <hyst>     (Pan  Absolute Sensor Limit Hysteresis)\r\n"
#define STR_HELP_SET67  "  SET INV[ABS]T     <onoff>    (Tilt Absolute Sensor Invertion)\r\n"
#define STR_HELP_SET68  "  SET RATIO[ABS]T   <ratio>    (Tilt Absolute Sensor over Encoder Ratio)\r\n"
#define STR_HELP_SET69  "  SET Z[EROABS]T               (Tilt Absolute Sensor Zero calc procedure)\r\n"
#define STR_HELP_SET70  "  SET L[IMIT]MINT              (Tilt Absolute Sensor Limit MIN calc procedure)\r\n"
#define STR_HELP_SET71  "  SET L[IMIT]MAXT              (Tilt Absolute Sensor Limit MAX calc procedure)\r\n"
#define STR_HELP_SET72  "  SET L[IMIT]HYSTT  <hyst>     (Tilt Absolute Sensor Limit Hysteresis)\r\n"
#define STR_HELP_SET73  "  SET Q|SHOT        <qn> <qm>  (Axis positions Q(SHOT) number <qn>  into memory <qm>)\r\n"

#define STR_HELP_SET80  "  SET A[NAOUT]AXIS  <axis>     (Analog Output Axis Select)\r\n"
#define STR_HELP_SET81  "  SET AS[TIM]TYPE   <astype>   (Motors Autostimolus Type: VOLATILE!)\r\n"
#define STR_HELP_SET82  "  SET ASTIMP        <onoff>    (Pan  Motor Autostimolous on-off: VOLATILE!)\r\n"
#define STR_HELP_SET83  "  SET KOPFP         <kofvalue> (Pan  Motor Autostimolus Input Gain)\r\n"
#define STR_HELP_SET84  "  SET AGAINP        <anagain>  (Pan  Motor Analog Output Gain)\r\n"
#define STR_HELP_SET85  "  SET COLORP        <color>    (Pan  Motor Analog Output Mux)\r\n"
#define STR_HELP_SET86  "  SET ASTIMT        <onoff>    (Tilt Motor Autostimolous on-off: VOLATILE!)\r\n"
#define STR_HELP_SET87  "  SET KOPFT         <kofvalue> (Tilt Motor Autostimolus Input Gain)\r\n"
#define STR_HELP_SET88  "  SET AGAINT        <anagain>  (Tilt Motor Analog Output Gain)\r\n"
#define STR_HELP_SET89  "  SET COLORT        <color>    (Tilt Motor Analog Output Mux)\r\n"

#define STR_HELP_SETTC  "  SET GAMMA         <avalue>   (IMU Euler Angles Low Pass Filter)\r\n"
#define STR_HELP_SETC1  "  SET IMU[INV]Y[AW] <onoff>    (IMU Yaw   Euler Angle Invertion)\r\n"
#define STR_HELP_SETC2  "  SET IMU[INV]P[ITCH]<onoff>   (IMU Pitch Euler Angle Invertion)\r\n"
#define STR_HELP_SETC3  "  SET IMU[INV]R[OLL] <onoff>   (IMU Roll  Euler Angle Invertion)\r\n"
#define STR_HELP_SETC4  "  SET PREX[CHANGE]  <onoff>    (IMU Pitch-Roll Euler Angle Exchange)\r\n"
#define STR_HELP_SETC5  "  SET BETA          <avalue>   (Analog Accelerometer Low Pass Filter)\r\n"

#define STR_HELP_SETTF  "  SET AACXOF[FSET]  <offset>   (Analog Accelerometer Axis X ADC Offset)\r\n"
#define STR_HELP_SETTG  "  SET AACYOF[FSET]  <offset>   (Analog Accelerometer Axis Y ADC Offset)\r\n"
#define STR_HELP_SETTH  "  SET AACZOF[FSET]  <offset>   (Analog Accelerometer Axis Z ADC Offset)\r\n"
#define STR_HELP_SETTI  "  SET JUMPTH        <avalue>   (EVENT PARAMETER: Jump G Threshold)\r\n"
#define STR_HELP_SETI1  "  SET ACCTH         <avalue>   (EVENT PARAMETER: Acceleration G Threshold)\r\n"
#define STR_HELP_SETTJ  "  SET DIR[ECTOR]    <director> (Director Style)\r\n"
#define STR_HELP_SETTK  "  SET MODE          <mode>     (Machine Mode)\r\n"

#define STR_HELP_polar "  <polarity>   = 0..1 [true | invert]\r\n"
#define STR_HELP_kpval "  <kpvalue>    = 0..100     (float n.m)\r\n"
#define STR_HELP_kdval "  <kdvalue>    = 0..1000    (float n.m)\r\n"
#define STR_HELP_kival "  <kivalue>    = 0..100     (float n.m)\r\n"
#define STR_HELP_ksivl "  <ksivalue>   = 0..1000000 (float n.m)\r\n"
#define STR_HELP_dbval "  <dbvalue>    = 0..1000    (float n.m)\r\n"
#define STR_HELP_kofvl "  <kofvalue>   = 0..10      (float n.m)\r\n"
#define STR_HELP_again "  <anagain>    = -1000..1000  (float n.m)\r\n"
#define STR_HELP_astyp "  <astype>     = 0(no astim), 1(sine), 2(triangle), 3(square)\r\n"
#define STR_HELP_color "  <color>      = 0(gyro rate), 1(enc pos), 2(enc vel), 3(astim), 4(e(t)), 5(d_e(t)/dt),\r\n"
#define STR_HELP_colo1 "                 6(int_e(t)), 7(Ki*int_e(t)), 8(cv(t))\r\n"
#define STR_HELP_axis  "  <axis>       = [PAN | TILT]\r\n"

#define STR_HELP_avalu "  <avalue>     = 0 .. 1 (float n.m)\r\n"
#define STR_HELP_onoff "  <onoff>      = 0 .. 1 [off | on]\r\n"
#define STR_HELP_dir   "  <director>   = 0(Kubrick), 1(Hitchcock), 2(De Palma), 3(Chaplin), 4(Linch), 5(Coppola)\r\n"
#define STR_HELP_dir1  "                 6(Scorsese), 7(Tarantino), 8(Scott), 9(Leone), 10(Spielberg), 11(Burton)\r\n"
#define STR_HELP_dir2  "                 12(Craven), 13(Fellini), 14(Ford), 15(Nolan), 16(Del Toro), 17(Lucas), 18(Abrams)\r\n"

#define STR_HELP_mode  "  <mode>       = 0(REMOTE CONTROL), 1(DIRECTOR)\r\n"

#define STR_HELP_qn    "  <qn>         = 0..99\r\n"
#define STR_HELP_qm    "  <qm>         = 0..32 (\"clear\" or \"c\" to clear Q memory)\r\n"


#define STR_HELP_SHOW1 "SHOW,S: shows parameters and realtime values\r\n"
#define STR_HELP_SHOW2 "  SHOW [P | PARAMS]      (All GoBee Parameters)\r\n"
#define STR_HELP_SHO21 "  FAULT[S]               (System Faults or Warnings)\r\n"
#define STR_HELP_SHOW3 "  SHOW BUT[TON]          (SW1 pushbutton state) \r\n"
#define STR_HELP_SHOW4 "  SHOW ANA[LOGS]         (Analog Inputs as sampled by ADC)\r\n"
#define STR_HELP_SHOW6 "  SHOW A[NALOG]ACC       (Bike Frame Analog Accelerometer Values)\r\n"

#if IMU_UM7_ENABLED
#define STR_HELP_SHW70 "  SHOW IMU               (Bike Frame Real time IMU Euler Angles)\r\n"
#define STR_HELP_SHW71 "  SHOW IMUSET[TINGS]     (IMU Internal Settings)\r\n"
#define STR_HELP_SHW72 "  SHOW IMUERR[ORS]       (IMU Serial errors)\r\n"
#endif
#define STR_HELP_SHW73 "  SHOW BIKE[ANGLES]      (BIKE Frame Euler Angles)\r\n"

#define STR_HELP_SHOW8 "  SHOW S[YS]DYN          (Real Time System Dynamic Scalar Value)\r\n"
#define STR_HELP_SHOW9 "  SHOW POS[ITION]        (Real Time relative and absolute position Values)\r\n"
#define STR_HELP_SHW90 "  SHOW ENCF[BK]          (Real Time Feedback Encoders)\r\n"
#define STR_HELP_SHW91 "  SHOW P[AN]LIM[ITS]     (Real Time Pan  Limits Elaboration)\r\n"
#define STR_HELP_SHW92 "  SHOW T[ILT]LIM[ITS]    (Real Time Tilt Limits Elaboration)\r\n"
#define STR_HELP_SHW93 "  SHOW RATIO[ABS]P       (Pan  Encoder-Absolute Sensor ratio r=reset; s=set; e=save)\r\n"
#define STR_HELP_SHW94 "  SHOW RATIO[ABS]T       (Tilt Encoder-Absolute Sensor ratio r=reset; s=set; e=save)\r\n"
#define STR_HELP_SHW95 "  SHOW PABS[STATS]       (Pan  Absolute Sensor Statistics results)\r\n"
#define STR_HELP_SHW96 "  SHOW TABS[STATS]       (Tilt Absolute Sensor Statistics results)\r\n"
#define STR_HELP_SHOWA "  SHOW MOT[ORSTATUS]     (Motor Status - Current OK or PEAK)\r\n"
#define STR_HELP_SHWA1 "  SHOW CURRENT|I         (Motor Currents [mA])\r\n"
#define STR_HELP_SHWA2 "  SHOW PMT[ORQUE]        (Real Time Pan  Motor  Torque Statistics)\r\n"
#define STR_HELP_SHWA3 "  SHOW POT[ORQUE]        (Real Time Pan  Output Torque Statistics)\r\n"
#define STR_HELP_SHWA4 "  SHOW PMP[OWER]         (Real Time Pan  Motor  Erogated Power Statistics)\r\n"
#define STR_HELP_SHWA5 "  SHOW TMT[ORQUE]        (Real Time Tilt Motor  Torque Statistics)\r\n"
#define STR_HELP_SHWA6 "  SHOW TOT[ORQUE]        (Real Time Tilt Output Torque Statistics)\r\n"
#define STR_HELP_SHWA7 "  SHOW TMP[OWER]         (Real Time Tilt Motor  Erogated Power Statistics)\r\n"
#define STR_HELP_SHOWB "  SHOW VCC               (Input Power Voltage)\r\n" 
#define STR_HELP_SHOWC "  SHOW [CONTROL|CTRL]    (Real Time Control Loop Values)\r\n"
#define STR_HELP_SHOWD "  SHOW ASTIM             (Real Time Autostimolus Values)\r\n"
#define STR_HELP_SHOWE "  SHOW PA[TH]  <n>       (Path Trapezoid Values [n=0..15])\r\n"
#define STR_HELP_SHOWF "  SHOW MOV[ER] <n>       (Rendering Values of Path n [n=0..15])\r\n"
#define STR_HELP_SHOF1 "  SHOW MOVERS            (Real time Pan and Tilt Movers Values)\r\n"
#define STR_HELP_SHOF2 "  SHOW CLU     <clu_num> (CLU GML definition [clu_num=0..49])\r\n"
#define STR_HELP_SHOF3 "  SHOW Q|SHOT  <n>       (Axis positions Q(SHOT) number <n> or <all>)\r\n"
#define STR_HELP_SHOWG "  SHOW CLUSM             (CLU Execution State Machine)\r\n"
#define STR_HELP_SHOWH "  SHOW [EVENTS|MAPSM]    (Events & Director's Mapping State Machine)\r\n"
#define STR_HELP_SHOWZ "  (press anykey to stop flushing)\r\n"


#define STR_HELP_VERS1 "VERSION,V: displays firmware version\r\n"
#define STR_HELP_VERS2 "  VERSION\r\n"
#define STR_HELP_VERS3 "  V\r\n"
#define STR_HELP_TDAC1 "TESTDAC: tests STEER DAC OUTPUT\r\n"
#define STR_HELP_TDAC2 "  TESTDAC\r\n"
#define STR_HELP_SYNTX "Syntax:\r\n"


//old
#define STR_HELP_kvalu "  <kvalue>     = 0..1000\r\n"
#define STR_HELP_thlev "  <vthlevel>   = 0..1000 [step/10^-1 sec]\r\n"
#define STR_HELP_kplow "  <kplow>      = 0..1 [OFF | ON]\r\n"


#define STR_ASTIMA   	"DANGER!!! THIS COMMAND MAY PRODUCE LARGE MOVEMENTS!!!\r\n"
#define STR_ASTIMB   	"Are you sure to apply auto-stimulus [Y/N]?"


// ### SHOW ENCF STRINGS ###
#define STR_SHOWENCFA  "DANGER!!! THIS COMMAND DISABLES MOTOR CONTROL AND MAY PRODUCE LARGE MOVEMENTS!!!\r\n"
#define STR_SHOWENCFB  "Are you sure to show feedback encoders [Y/N]?"
#define STR_SHOWENCFC  "Are you sure to show absolute sensor ratios [Y/N]?"


// ### REMS ###
#define STR_REM_SEDR	"* Gobee Director Number setted to %2u: "
#define STR_REM_SMOD	"* Gobee machine mode setted to %2u"
#define STR_REM_ASTP	"* Pan  Astim Type setted to %1u\r\n"
#define STR_REM_ASEP	"* Pan Astim Enable setted to %1u\r\n"
#define STR_REM_SETP	"* Pan Motor Polarity setted to %2u"
#define STR_REM_PMKP	"* Pan Motor Kp setted to %1.4f"
#define STR_REM_PMKD	"* Pan Motor Kd setted to %1.4f"
#define STR_REM_PMKI	"* Pan Motor Ki setted to %1.4f"
#define STR_REM_PMKS	"* Pan Motor Ksi setted to %1.4f"
#define STR_REM_STLP	"* Pan Motor Limit Control setted to %2u"
#define STR_REM_PKOF	"* Pan Motor Kopf setted to %1.4f"
#define STR_REM_PAGA	"* Pan Motor Analog Output Gain setted to %1.4f"
#define STR_REM_SCOL	"* Pan Motor Analog Output Color setted to "

#define STR_REM_ASTT	"* Tilt Astim Type setted to %1u\r\n"
#define STR_REM_ASET	"* Tilt Astim Enable setted to %1u\r\n"
#define STR_REM_SETPT	"* Tilt Motor Polarity setted to %2u"
#define STR_REM_TMKP	"* Tilt Motor Kp setted to %1.4f"
#define STR_REM_TMKD	"* Tilt Motor Kd setted to %1.4f"
#define STR_REM_TMKI	"* Tilt Motor Ki setted to %1.4f"
#define STR_REM_TMKS	"* Tilt Motor Ksi setted to %1.4f"
#define STR_REM_STLT	"* Tilt Motor Limit Control setted to %2u"
#define STR_REM_TKOF	"* Tilt Motor Kopf setted to %1.4f"
#define STR_REM_TAGA	"* Tilt Motor Analog Output Gain setted to %1.4f"
#define STR_REM_SCOLT	"* Tilt Motor Analog Output Color setted to "

#define STR_REM_ANAXP	"* Anaout Axis setted to PAN\r\n"
#define STR_REM_ANAXT	"* Anaout Axis setted to TILT\r\n"
#define STR_REM_ANAXR	"* Anaout Axis setted to ROLL\r\n"


#define STR_REM_SETO	"* Analog Gyro ADC Offset setted to %4i"
#define STR_REM_SEAX	"* Analog Accel. X Axis ADC Offset setted to %4i"
#define STR_REM_SEAY	"* Analog Accel. Y Axis ADC Offset setted to %4i"
#define STR_REM_SEAZ	"* Analog Accel. Z Axis ADC Offset setted to %4i"
#define STR_REM_STBT	"* beta (accelerometer LPF) setted to %+1.9f"
#define STR_REM_STGM	"* gamma (IMU LPF) setted to %+1.9f"
#define STR_REM_SEKL	"* KP Low Pass Filter setted to %2u"

#define STR_REM_SIVP	"* Pan Absolute Sensor Invertion setted to %2u\r\n"	
#define STR_REM_PASZ	"* Pan Absolute Sensor ZERO POSITION (HOME) setted to %+6d [adc raw]\r\n"
#define STR_REM_PMIN	"* Pan Absolute Sensor Limit MIN setted to %+6d [adc raw]\r\n"
#define STR_REM_PMAX	"* Pan Absolute Sensor Limit MAX setted to %+6d [adc raw]\r\n"
#define STR_REM_PLHY	"* Pan Absolute Sensor Limit Hysteresis setted to %+6d [adc raw]\r\n"
#define STR_REM_PEAR	"* Pan Encoder over Absolute Sensor ratio setted to %+2.6f [adc raw/step]\r\n"
#define STR_REM_SIVT	"* Tilt Absolute Sensor Invertion setted to %2u\r\n"	
#define STR_REM_TASZ	"* Tilt Absolute Sensor ZERO POSITION (HOME) setted to %+6d [adc raw]\r\n"
#define STR_REM_TMIN	"* Tilt Absolute Sensor Limit MIN setted to %+6d [adc raw]\r\n"
#define STR_REM_TMAX	"* Tilt Absolute Sensor Limit MAX setted to %+6d [adc raw]\r\n"
#define STR_REM_TLHY	"* Tilt Absolute Sensor Limit Hysteresis setted to %+6d [adc raw]\r\n"
#define STR_REM_TEAR	"* Tilt Encoder over Absolute Sensor ratio setted to %+2.6f [adc raw/step]\r\n"
#define STR_REM_SINY	"* Invertion Yaw setted to %1u\r\n"
#define STR_REM_SINP	"* Invertion Pitch setted to %1u\r\n"
#define STR_REM_SINR	"* Invertion Roll setted to %1u\r\n"
#define STR_REM_SPRX	"* Exchange Pitch Roll setted to %1u\r\n"	

// Event Identification Parameters REMs
#define STR_REM_STJG	"* Jump G Threshold setted to %+1.4f[g]"
#define STR_REM_STAG	"* Acceleration G Threshold setted to %+1.4f[g]"

#define STR_REM_DEFL   "\r\n*All parameters setted to factory DEFAULT!"
#define STR_REM_NODF   "\r\n*Parameters UNCHANGED!"

// ### Q (SHOTS) TABLE ###	

#define STR_QTAB0 "Q (shot) Table\r\n"
#define STR_QTAB1 "--------------\r\n"
#define STR_Q000  "Q00: origin\r\n"
#define STR_Q011  "Q11: face\r\n"
#define STR_Q013  "Q13: legs\r\n"
#define STR_Q014  "Q14: hand dx\r\n"
#define STR_Q015  "Q15: hand sx\r\n"
#define STR_Q016  "Q16: pedal dx\r\n"
#define STR_Q017  "Q17: pedal sx\r\n"
#define STR_Q021  "Q21: wheel\r\n"
#define STR_Q031  "Q31: road\r\n"
#define STR_Q033  "Q33: road side dx\r\n"
#define STR_Q034  "Q34: road side sx\r\n"
#define STR_Q040  "Q40: panorama front\r\n"
#define STR_Q041  "Q41: panorama dx\r\n"
#define STR_Q042  "Q42: panorama sx\r\n"
#define STR_Q043  "Q43: panorama dx rear\r\n"
#define STR_Q044  "Q44: panorama sx rear\r\n"
#define STR_Q051  "Q51: sky\r\n"
#define STR_Q052  "Q52: sky sx\r\n"
#define STR_Q053  "Q53: sky dx\r\n"

// ### INTERNAL JOKES COMMANDS ###

#define STR_JOKE0 "                       (#########) \r\n"
#define STR_JOKE1 "                      (#########) \r\n"      
#define STR_JOKE2 "                     (#########) \r\n" 
#define STR_JOKE3 "                    (#########) \r\n"
#define STR_JOKE4 "      __?__        (#########) \r\n"
#define STR_JOKE5 "     /     \\      (#########) |\\/\\/\\/|  /\\ /\\  /\\             /  \r\n"
#define STR_JOKE6 "    |       |    (#########)  |      |  | V  \\/  \\---.  .----/ \\----. \r\n"
#define STR_JOKE7 "    |  (o)(o)     (o)(o)(##)  |      |   \\_        /     \\          / \r\n"
#define STR_JOKE8 "    C   .---_)  ,_C     (##)  | (o)(o)    (o)(o)  ?__. .--\\ (o)(o) /__. \r\n"
#define STR_JOKE9 "     | |.___|  /____,   (##)  C      _)  _C         /   \\     ()    / \r\n"
#define STR_JOKEA "     |  \\__/     \\     (#)     | ,___|  /____,   )  \\    >   (C_)   ? \r\n"
#define STR_JOKEB "     /_____\\      |    |       |   /      \\     /----'  /___\\____/___\\  \r\n"
#define STR_JOKEC "    /_____/ \\     OOOOOO      /____\\       ooooo           /|    | \r\n"
#define STR_JOKED "   /         \\   /      \\    /      \\     /     \\           |    |  \r\n"


//[] END OF FILE
