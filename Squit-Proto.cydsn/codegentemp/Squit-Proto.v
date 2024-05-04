// ======================================================================
// Squit-Proto.v generated from TopDesign.cysch
// 02/08/2019 at 12:26
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC4A 2
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PANTHER 3
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4A 2
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4D 3
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4D_ES0 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5A 4
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_5B 5
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 5
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// ADC_DelSig_v3_10(ADC_Alignment=0, ADC_Alignment_Config2=0, ADC_Alignment_Config3=0, ADC_Alignment_Config4=0, ADC_Charge_Pump_Clock=false, ADC_Clock=1, ADC_CLOCK_FREQUENCY=3600000, ADC_Input_Mode=0, ADC_Input_Range=5, ADC_Input_Range_Config2=4, ADC_Input_Range_Config3=4, ADC_Input_Range_Config4=4, ADC_Power=1, ADC_Reference=5, ADC_Reference_Config2=0, ADC_Reference_Config3=0, ADC_Reference_Config4=0, ADC_Resolution=12, ADC_Resolution_Config2=16, ADC_Resolution_Config3=16, ADC_Resolution_Config4=16, Clock_Frequency=64000, Comment_Config1=Default Config, Comment_Config2=Second Config, Comment_Config3=Third Config, Comment_Config4=Fourth Config, Config1_Name=CFG1, Config2_Name=CFG2, Config3_Name=CFG3, Config4_Name=CFG4, Configs=1, Conversion_Mode=0, Conversion_Mode_Config2=2, Conversion_Mode_Config3=2, Conversion_Mode_Config4=2, Enable_Vref_Vss=false, EnableModulatorInput=false, Input_Buffer_Gain=1, Input_Buffer_Gain_Config2=1, Input_Buffer_Gain_Config3=1, Input_Buffer_Gain_Config4=1, Input_Buffer_Mode=1, Input_Buffer_Mode_Config2=1, Input_Buffer_Mode_Config3=1, Input_Buffer_Mode_Config4=1, Ref_Voltage=1.25, Ref_Voltage_Config2=1.024, Ref_Voltage_Config3=1.024, Ref_Voltage_Config4=1.024, rm_int=false, Sample_Rate=24000, Sample_Rate_Config2=10000, Sample_Rate_Config3=10000, Sample_Rate_Config4=10000, Start_of_Conversion=0, Vdda_Value=5, CY_COMPONENT_NAME=ADC_DelSig_v3_10, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=ADC, CY_INSTANCE_SHORT_NAME=ADC, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=ADC, )
module ADC_DelSig_v3_10_0 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    nVref,
    mi);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       nVref;
    electrical  nVref;
    input       mi;


          wire  Net_268;
          wire  Net_270;
          wire  Net_252;
          wire  Net_275;
          wire  Net_250;
    electrical  Net_249;
    electrical  Net_257;
    electrical  Net_248;
    electrical  Net_23;
          wire  Net_247;
          wire  aclock;
          wire [3:0] mod_dat;
          wire  mod_reset;
    electrical  Net_352;
          wire  Net_246;
          wire [7:0] Net_245;
          wire  Net_482;
    electrical  Net_34;
    electrical  Net_35;
    electrical  Net_244;
          wire  Net_93;
    electrical  Net_20;
    electrical  Net_690;
    electrical  Net_686;
    electrical  Net_520;
          wire  Net_481;
    electrical  Net_677;
    electrical  Net_41;
    electrical  Net_573;
    electrical  Net_109;
          wire  Net_488;

	// cy_analog_virtualmux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_6_connect(Net_690, Net_35);
	defparam cy_analog_virtualmux_6_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_34));

	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_677, Net_34);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_psoc3_ds_mod_v4_0 DSM (
        .vplus(vplus),
        .vminus(Net_520),
        .modbit(Net_481),
        .reset_udb(Net_482),
        .aclock(Net_488),
        .mod_dat(mod_dat[3:0]),
        .dout_udb(Net_245[7:0]),
        .reset_dec(mod_reset),
        .dec_clock(aclock),
        .extclk_cp_udb(Net_93),
        .clk_udb(1'b0),
        .ext_pin_1(Net_573),
        .ext_pin_2(Net_41),
        .ext_vssa(Net_109),
        .qtz_ref(Net_677));
    defparam DSM.resolution = 12;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_352));

	// cy_analog_virtualmux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_5_connect(Net_109, Net_352);
	defparam cy_analog_virtualmux_5_connect.sig_width = 1;


	cy_clock_v1_0
		#(.id("d4ba298c-68cb-4b7e-b9e7-f0a3d2bfafb6/b7604721-db56-4477-98c2-8fae77869066"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(1),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Ext_CP_Clk
		 (.clock_out(Net_93));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_257));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_249));

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_41, Net_257);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_573, Net_249);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_520, vminus);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


	// Clock_VirtualMux (cy_virtualmux_v1_0)
	assign Net_488 = Net_250;


	cy_clock_v1_0
		#(.id("d4ba298c-68cb-4b7e-b9e7-f0a3d2bfafb6/edd15f43-b66b-457b-be3a-5342345270c8"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("277777777.777778"),
		  .is_direct(0),
		  .is_digital(0))
		theACLK
		 (.clock_out(Net_250));


    ZeroTerminal ZeroTerminal_2 (
        .z(Net_482));

	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_481 = Net_252;

    cy_psoc3_decimator_v1_0 DEC (
        .aclock(aclock),
        .mod_dat(mod_dat[3:0]),
        .ext_start(soc),
        .mod_reset(mod_reset),
        .interrupt(eoc));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_252));


    assign Net_268 = Net_93 | Net_270;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_270));



endmodule

// Component: B_UART_v2_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30\B_UART_v2_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30\B_UART_v2_30.v"
`endif

// UART_v2_30(Address1=0, Address2=0, BaudRate=57600, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, CtrlModeReplacementString=SyncCtl, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=false, InternalClock=true, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=460800, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=false, CY_COMPONENT_NAME=UART_v2_30, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=UART_USB, CY_INSTANCE_SHORT_NAME=UART_USB, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=UART_USB, )
module UART_v2_30_1 (
    rx_clk,
    rx_data,
    tx_clk,
    tx_data,
    rx_interrupt,
    tx_interrupt,
    tx,
    tx_en,
    rts_n,
    reset,
    cts_n,
    clock,
    rx);
    output      rx_clk;
    output      rx_data;
    output      tx_clk;
    output      tx_data;
    output      rx_interrupt;
    output      tx_interrupt;
    output      tx;
    output      tx_en;
    output      rts_n;
    input       reset;
    input       cts_n;
    input       clock;
    input       rx;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 0;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("2170138888.88889"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_30 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 0;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 0;



endmodule

// Component: CyControlReg_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`endif

// Component: AMuxSeq_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_80"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_80\AMuxSeq_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_80\AMuxSeq_v1_80.v"
`endif

// Component: CyStatusReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80\CyStatusReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80\CyStatusReg_v1_80.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Counter_v2_40(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=20, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=20, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_COMPONENT_NAME=Counter_v2_40, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Counter_LED, CY_INSTANCE_SHORT_NAME=Counter_LED, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Counter_LED, )
module Counter_v2_40_2 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_47),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// I2C_v3_30(Address_Decode=1, BusSpeed_kHz=50, ClockInputVisibility=false, CtlModeReplacementString=SyncCtl, EnableWakeup=false, ExternalBuffer=false, Externi2cIntrHandler=false, ExternTmoutIntrHandler=false, FF=true, Hex=false, I2C_Mode=2, I2cBusPort=1, Implementation=1, InternalUdbClockToleranceMinus=25, InternalUdbClockTolerancePlus=5, NotSlaveClockMinusTolerance=25, NotSlaveClockPlusTolerance=5, PrescalerEnabled=false, PrescalerPeriod=3, Psoc3ffSelected=false, Psoc5AffSelected=false, Psoc5lpffSelected=true, RemoveI2cff=false, RemoveI2cUdb=true, RemoveIntClock=true, RemoveTimeoutTimer=true, SclTimeoutEnabled=false, SdaTimeoutEnabled=false, Slave_Address=8, SlaveClockMinusTolerance=5, SlaveClockPlusTolerance=50, TimeoutEnabled=false, TimeoutImplementation=0, TimeOutms=25, TimeoutPeriodff=39999, TimeoutPeriodUdb=39999, UDB_MSTR=false, UDB_MULTI_MASTER_SLAVE=false, UDB_SLV=false, UdbInternalClock=false, UdbRequiredClock=800, UdbSlaveFixedPlacementEnable=false, CY_COMPONENT_NAME=I2C_v3_30, CY_CONTROL_FILE=I2C_Slave_DefaultPlacement.ctl, CY_FITTER_NAME=I2C_COULOMB, CY_INSTANCE_SHORT_NAME=I2C_COULOMB, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=I2C_COULOMB, )
module I2C_v3_30_3 (
    sda_o,
    scl_o,
    sda_i,
    scl_i,
    iclk,
    bclk,
    reset,
    clock,
    scl,
    sda,
    itclk);
    output      sda_o;
    output      scl_o;
    input       sda_i;
    input       scl_i;
    output      iclk;
    output      bclk;
    input       reset;
    input       clock;
    inout       scl;
    inout       sda;
    output      itclk;


          wire  sda_x_wire;
          wire  sda_yfb;
          wire  udb_clk;
          wire  Net_975;
          wire  Net_974;
          wire  Net_973;
          wire  bus_clk;
          wire  Net_972;
          wire  Net_968;
          wire  scl_yfb;
          wire  Net_969;
          wire  Net_971;
          wire  Net_970;
          wire  timeout_clk;
          wire  Net_697;
          wire  Net_1045;
          wire [1:0] Net_1109;
          wire [5:0] Net_643;
          wire  scl_x_wire;

	// Vmux_sda_out (cy_virtualmux_v1_0)
	assign sda_x_wire = Net_643[1];


	cy_isr_v1_0
		#(.int_type(2'b00))
		I2C_IRQ
		 (.int_signal(Net_697));


    cy_psoc3_i2c_v1_0 I2C_FF (
        .clock(bus_clk),
        .scl_in(Net_1109[0]),
        .sda_in(Net_1109[1]),
        .scl_out(Net_643[0]),
        .sda_out(Net_643[1]),
        .interrupt(Net_643[2]));
    defparam I2C_FF.use_wakeup = 0;

	// Vmux_interrupt (cy_virtualmux_v1_0)
	assign Net_697 = Net_643[2];

	// Vmux_scl_out (cy_virtualmux_v1_0)
	assign scl_x_wire = Net_643[0];

    OneTerminal OneTerminal_1 (
        .o(Net_969));

    OneTerminal OneTerminal_2 (
        .o(Net_968));

	// Vmux_clock (cy_virtualmux_v1_0)
	assign udb_clk = clock;


	cy_clock_v1_0
		#(.id("686852b0-cd21-4c1d-8741-3e259a68f961/5ece924d-20ba-480e-9102-bc082dcdd926"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BusClock
		 (.clock_out(bus_clk));



    assign bclk = bus_clk | Net_973;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_973));


    assign iclk = udb_clk | Net_974;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_974));

	// Vmux_scl_in (cy_virtualmux_v1_0)
	assign Net_1109[0] = scl_yfb;

	// Vmux_sda_in (cy_virtualmux_v1_0)
	assign Net_1109[1] = sda_yfb;

	wire [0:0] tmpOE__Bufoe_scl_net;

	cy_bufoe
		Bufoe_scl
		 (.x(scl_x_wire),
		  .y(scl),
		  .oe(tmpOE__Bufoe_scl_net),
		  .yfb(scl_yfb));

	assign tmpOE__Bufoe_scl_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_969} : {Net_969};

	wire [0:0] tmpOE__Bufoe_sda_net;

	cy_bufoe
		Bufoe_sda
		 (.x(sda_x_wire),
		  .y(sda),
		  .oe(tmpOE__Bufoe_sda_net),
		  .yfb(sda_yfb));

	assign tmpOE__Bufoe_sda_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_968} : {Net_968};

	// Vmux_timeout_clock (cy_virtualmux_v1_0)
	assign timeout_clk = clock;


    assign itclk = timeout_clk | Net_975;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_975));


    assign scl_o = scl_x_wire;

    assign sda_o = sda_x_wire;


endmodule

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// PWM_v3_0(CaptureMode=0, Compare1_16=false, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=512, CompareValue2=63, CONTROL3=1, ControlReg=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=1, DeadBand2_4=1, DeadBand256=0, DeadBandUsed=1, DeadTime=3, DitherOffset=0, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=1, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=1024, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TriggerMode=0, UDB16=false, UDB8=false, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v3_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PWM_MOTOR_PAN, CY_INSTANCE_SHORT_NAME=PWM_MOTOR_PAN, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PWM_MOTOR_PAN, )
module PWM_v3_0_4 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    cy_psoc3_timer_v1_0 PWMHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_113),
        .kill(Net_107),
        .clock(clock),
        .tc(Net_63),
        .compare(Net_57),
        .interrupt(Net_54));

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_57;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_54;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_63;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = kill;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: B_Counter_v2_40
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_40"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_40\B_Counter_v2_40.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_40"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_40\B_Counter_v2_40.v"
`endif

// Counter_v2_40(CaptureMode=0, CaptureModeSoftware=0, ClockMode=1, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=32768, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=32768, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=32768, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_COMPONENT_NAME=Counter_v2_40, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=QuadDec_PAN:Cnt16, CY_INSTANCE_SHORT_NAME=Cnt16, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec_PAN_Cnt16, )
module Counter_v2_40_5 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 1;
    parameter CompareMode = 0;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v2_40 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 1;
    defparam CounterUDB.CompareMode = 0;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 16;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: bQuadDec_v2_40
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_40"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_40\bQuadDec_v2_40.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_40"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_40\bQuadDec_v2_40.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// QuadDec_v2_40(Counter8bit=false, CounterResolution=4, CounterSize=32, CounterSizeReplacementString=int32, CounterSizeReplacementStringUnsigned=uint16, TypeCastReplacementString=int32, UsingGlitchFiltering=false, UsingIndexInput=false, CY_COMPONENT_NAME=QuadDec_v2_40, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=QuadDec_PAN, CY_INSTANCE_SHORT_NAME=QuadDec_PAN, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec_PAN, )
module QuadDec_v2_40_6 (
    quad_A,
    quad_B,
    index,
    clock,
    interrupt);
    input       quad_A;
    input       quad_B;
    input       index;
    input       clock;
    output      interrupt;

    parameter CounterResolution = 4;
    parameter UsingGlitchFiltering = 0;
    parameter UsingIndexInput = 0;

          wire  Net_1126;
          wire  Net_1125;
          wire  Net_1124;
          wire  Net_1241;
          wire  Net_1123;
          wire  Net_1132;
          wire  Net_1131;
          wire  Net_1130;
          wire  Net_1243;
          wire  Net_1129;
          wire  Net_1287;
          wire  Net_1272;
          wire  Net_1290;
          wire  Net_1269;
          wire  Net_1264;
          wire  Net_1275;
          wire  Net_1276;
          wire  Net_1203;
          wire  Net_1260;
          wire  Net_1232;
          wire  Net_1229;
          wire  Net_1251;
          wire  Net_611;
          wire  Net_1151;
          wire  Net_1248;
          wire  Net_530;


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr
		 (.int_signal(interrupt));


    Counter_v2_40_5 Cnt16 (
        .reset(Net_1260),
        .tc(Net_1275),
        .comp(Net_1264),
        .clock(clock),
        .interrupt(Net_1129),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(Net_1251),
        .count(Net_1203));
    defparam Cnt16.CaptureMode = 0;
    defparam Cnt16.ClockMode = 1;
    defparam Cnt16.CompareMode = 0;
    defparam Cnt16.CompareStatusEdgeSense = 1;
    defparam Cnt16.EnableMode = 0;
    defparam Cnt16.ReloadOnCapture = 0;
    defparam Cnt16.ReloadOnCompare = 0;
    defparam Cnt16.ReloadOnOverUnder = 1;
    defparam Cnt16.ReloadOnReset = 1;
    defparam Cnt16.Resolution = 16;
    defparam Cnt16.RunMode = 0;
    defparam Cnt16.UseInterrupt = 1;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_1290 = Net_1275;

    bQuadDec_v2_40 bQuadDec (
        .quad_A(quad_A),
        .quad_B(quad_B),
        .index(Net_1232),
        .clock(clock),
        .dir(Net_1251),
        .reset(Net_1260),
        .enable(Net_1203),
        .overflow(Net_530),
        .underflow(Net_611),
        .interrupt(interrupt));
    defparam bQuadDec.CounterResolution = 4;
    defparam bQuadDec.UsingGlitchFiltering = 0;
    defparam bQuadDec.UsingIndexInput = 0;


    assign Net_1151 = ~Net_1251;


    assign Net_530 = Net_1251 & Net_1248;


    assign Net_611 = Net_1151 & Net_1248;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1232 = Net_1229;

    OneTerminal OneTerminal_1 (
        .o(Net_1229));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_1272 = Net_1264;


    assign Net_1287 = ~Net_1272;


    assign Net_1248 = Net_1290 & Net_1287;



endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: demux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`endif

// VDAC8_v1_90(Data_Source=0, Initial_Value=100, Strobe_Mode=1, VDAC_Range=0, VDAC_Speed=2, Voltage=400, CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=WaveDAC8:VDAC8, CY_INSTANCE_SHORT_NAME=VDAC8, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=WaveDAC8_VDAC8, )
module VDAC8_v1_90_7 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 100;
    parameter Strobe_Mode = 1;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// OpAmp_v1_90(Mode=1, Power=2, CY_COMPONENT_NAME=OpAmp_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=WaveDAC8:BuffAmp, CY_INSTANCE_SHORT_NAME=BuffAmp, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=WaveDAC8_BuffAmp, )
module OpAmp_v1_90_8 (
    Vplus,
    Vout,
    Vminus);
    inout       Vplus;
    electrical  Vplus;
    inout       Vout;
    electrical  Vout;
    inout       Vminus;
    electrical  Vminus;

    parameter Mode = 1;

    electrical  Net_29;

    cy_psoc3_abuf_v1_0 ABuf (
        .vplus(Vplus),
        .vminus(Net_29),
        .vout(Vout));

	// abuf_negInput_mux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 abuf_negInput_mux_connect(Net_29, Vout);
	defparam abuf_negInput_mux_connect.sig_width = 1;



endmodule

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// WaveDAC8_v2_0(Clock_SRC=1, DAC_Range=17, DacModeReplString=VDAC8, Sample_Clock_Freq=10000, Wave1_Amplitude=4, Wave1_Data=128u,128u,128u,128u,128u,129u,129u,129u,129u,130u,130u,130u,130u,131u,131u,131u,131u,132u,132u,132u,132u,132u,133u,133u,133u,133u,134u,134u,134u,134u,135u,135u,135u,135u,136u,136u,136u,136u,136u,137u,137u,137u,137u,138u,138u,138u,138u,139u,139u,139u,139u,139u,140u,140u,140u,140u,141u,141u,141u,141u,142u,142u,142u,142u,143u,143u,143u,143u,143u,144u,144u,144u,144u,145u,145u,145u,145u,146u,146u,146u,146u,147u,147u,147u,147u,147u,148u,148u,148u,148u,149u,149u,149u,149u,150u,150u,150u,150u,150u,151u,151u,151u,151u,152u,152u,152u,152u,153u,153u,153u,153u,153u,154u,154u,154u,154u,155u,155u,155u,155u,156u,156u,156u,156u,156u,157u,157u,157u,157u,158u,158u,158u,158u,159u,159u,159u,159u,159u,160u,160u,160u,160u,161u,161u,161u,161u,161u,162u,162u,162u,162u,163u,163u,163u,163u,164u,164u,164u,164u,164u,165u,165u,165u,165u,166u,166u,166u,166u,166u,167u,167u,167u,167u,168u,168u,168u,168u,168u,169u,169u,169u,169u,170u,170u,170u,170u,170u,171u,171u,171u,171u,172u,172u,172u,172u,172u,173u,173u,173u,173u,174u,174u,174u,174u,174u,175u,175u,175u,175u,175u,176u,176u,176u,176u,177u,177u,177u,177u,177u,178u,178u,178u,178u,179u,179u,179u,179u,179u,180u,180u,180u,180u,180u,181u,181u,181u,181u,182u,182u,182u,182u,182u,183u,183u,183u,183u,183u,184u,184u,184u,184u,184u,185u,185u,185u,185u,186u,186u,186u,186u,186u,187u,187u,187u,187u,187u,188u,188u,188u,188u,188u,189u,189u,189u,189u,189u,190u,190u,190u,190u,190u,191u,191u,191u,191u,191u,192u,192u,192u,192u,192u,193u,193u,193u,193u,193u,194u,194u,194u,194u,194u,195u,195u,195u,195u,195u,196u,196u,196u,196u,196u,197u,197u,197u,197u,197u,198u,198u,198u,198u,198u,199u,199u,199u,199u,199u,200u,200u,200u,200u,200u,201u,201u,201u,201u,201u,201u,202u,202u,202u,202u,202u,203u,203u,203u,203u,203u,204u,204u,204u,204u,204u,204u,205u,205u,205u,205u,205u,206u,206u,206u,206u,206u,207u,207u,207u,207u,207u,207u,208u,208u,208u,208u,208u,209u,209u,209u,209u,209u,209u,210u,210u,210u,210u,210u,210u,211u,211u,211u,211u,211u,212u,212u,212u,212u,212u,212u,213u,213u,213u,213u,213u,213u,214u,214u,214u,214u,214u,214u,215u,215u,215u,215u,215u,215u,216u,216u,216u,216u,216u,216u,217u,217u,217u,217u,217u,217u,218u,218u,218u,218u,218u,218u,219u,219u,219u,219u,219u,219u,220u,220u,220u,220u,220u,220u,220u,221u,221u,221u,221u,221u,221u,222u,222u,222u,222u,222u,222u,223u,223u,223u,223u,223u,223u,223u,224u,224u,224u,224u,224u,224u,224u,225u,225u,225u,225u,225u,225u,226u,226u,226u,226u,226u,226u,226u,227u,227u,227u,227u,227u,227u,227u,228u,228u,228u,228u,228u,228u,228u,228u,229u,229u,229u,229u,229u,229u,229u,230u,230u,230u,230u,230u,230u,230u,231u,231u,231u,231u,231u,231u,231u,231u,232u,232u,232u,232u,232u,232u,232u,232u,233u,233u,233u,233u,233u,233u,233u,234u,234u,234u,234u,234u,234u,234u,234u,234u,235u,235u,235u,235u,235u,235u,235u,235u,236u,236u,236u,236u,236u,236u,236u,236u,237u,237u,237u,237u,237u,237u,237u,237u,237u,238u,238u,238u,238u,238u,238u,238u,238u,238u,239u,239u,239u,239u,239u,239u,239u,239u,239u,239u,240u,240u,240u,240u,240u,240u,240u,240u,240u,241u,241u,241u,241u,241u,241u,241u,241u,241u,241u,241u,242u,242u,242u,242u,242u,242u,242u,242u,242u,242u,243u,243u,243u,243u,243u,243u,243u,243u,243u,243u,243u,244u,244u,244u,244u,244u,244u,244u,244u,244u,244u,244u,244u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,251u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,250u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,249u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,248u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,247u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,246u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,245u,244u,244u,244u,244u,244u,244u,244u,244u,244u,244u,244u,243u,243u,243u,243u,243u,243u,243u,243u,243u,243u,243u,242u,242u,242u,242u,242u,242u,242u,242u,242u,242u,242u,241u,241u,241u,241u,241u,241u,241u,241u,241u,241u,240u,240u,240u,240u,240u,240u,240u,240u,240u,240u,239u,239u,239u,239u,239u,239u,239u,239u,239u,238u,238u,238u,238u,238u,238u,238u,238u,238u,237u,237u,237u,237u,237u,237u,237u,237u,237u,236u,236u,236u,236u,236u,236u,236u,236u,236u,235u,235u,235u,235u,235u,235u,235u,235u,234u,234u,234u,234u,234u,234u,234u,234u,233u,233u,233u,233u,233u,233u,233u,233u,232u,232u,232u,232u,232u,232u,232u,232u,231u,231u,231u,231u,231u,231u,231u,230u,230u,230u,230u,230u,230u,230u,230u,229u,229u,229u,229u,229u,229u,229u,228u,228u,228u,228u,228u,228u,228u,227u,227u,227u,227u,227u,227u,227u,226u,226u,226u,226u,226u,226u,226u,225u,225u,225u,225u,225u,225u,225u,224u,224u,224u,224u,224u,224u,223u,223u,223u,223u,223u,223u,223u,222u,222u,222u,222u,222u,222u,222u,221u,221u,221u,221u,221u,221u,220u,220u,220u,220u,220u,220u,219u,219u,219u,219u,219u,219u,218u,218u,218u,218u,218u,218u,218u,217u,217u,217u,217u,217u,217u,216u,216u,216u,216u,216u,216u,215u,215u,215u,215u,215u,215u,214u,214u,214u,214u,214u,214u,213u,213u,213u,213u,213u,212u,212u,212u,212u,212u,212u,211u,211u,211u,211u,211u,211u,210u,210u,210u,210u,210u,209u,209u,209u,209u,209u,209u,208u,208u,208u,208u,208u,208u,207u,207u,207u,207u,207u,206u,206u,206u,206u,206u,206u,205u,205u,205u,205u,205u,204u,204u,204u,204u,204u,203u,203u,203u,203u,203u,203u,202u,202u,202u,202u,202u,201u,201u,201u,201u,201u,200u,200u,200u,200u,200u,199u,199u,199u,199u,199u,199u,198u,198u,198u,198u,198u,197u,197u,197u,197u,197u,196u,196u,196u,196u,196u,195u,195u,195u,195u,195u,194u,194u,194u,194u,194u,193u,193u,193u,193u,193u,192u,192u,192u,192u,192u,191u,191u,191u,191u,191u,190u,190u,190u,190u,190u,189u,189u,189u,189u,189u,188u,188u,188u,188u,187u,187u,187u,187u,187u,186u,186u,186u,186u,186u,185u,185u,185u,185u,185u,184u,184u,184u,184u,184u,183u,183u,183u,183u,182u,182u,182u,182u,182u,181u,181u,181u,181u,181u,180u,180u,180u,180u,179u,179u,179u,179u,179u,178u,178u,178u,178u,178u,177u,177u,177u,177u,176u,176u,176u,176u,176u,175u,175u,175u,175u,175u,174u,174u,174u,174u,173u,173u,173u,173u,173u,172u,172u,172u,172u,171u,171u,171u,171u,171u,170u,170u,170u,170u,169u,169u,169u,169u,169u,168u,168u,168u,168u,167u,167u,167u,167u,167u,166u,166u,166u,166u,165u,165u,165u,165u,165u,164u,164u,164u,164u,163u,163u,163u,163u,162u,162u,162u,162u,162u,161u,161u,161u,161u,160u,160u,160u,160u,160u,159u,159u,159u,159u,158u,158u,158u,158u,157u,157u,157u,157u,157u,156u,156u,156u,156u,155u,155u,155u,155u,155u,154u,154u,154u,154u,153u,153u,153u,153u,152u,152u,152u,152u,152u,151u,151u,151u,151u,150u,150u,150u,150u,149u,149u,149u,149u,148u,148u,148u,148u,148u,147u,147u,147u,147u,146u,146u,146u,146u,145u,145u,145u,145u,145u,144u,144u,144u,144u,143u,143u,143u,143u,142u,142u,142u,142u,141u,141u,141u,141u,141u,140u,140u,140u,140u,139u,139u,139u,139u,138u,138u,138u,138u,138u,137u,137u,137u,137u,136u,136u,136u,136u,135u,135u,135u,135u,134u,134u,134u,134u,134u,133u,133u,133u,133u,132u,132u,132u,132u,131u,131u,131u,131u,130u,130u,130u,130u,130u,129u,129u,129u,129u,128u,128u,128u,128u,127u,127u,127u,127u,126u,126u,126u,126u,125u,125u,125u,125u,125u,124u,124u,124u,124u,123u,123u,123u,123u,122u,122u,122u,122u,121u,121u,121u,121u,121u,120u,120u,120u,120u,119u,119u,119u,119u,118u,118u,118u,118u,117u,117u,117u,117u,117u,116u,116u,116u,116u,115u,115u,115u,115u,114u,114u,114u,114u,114u,113u,113u,113u,113u,112u,112u,112u,112u,111u,111u,111u,111u,110u,110u,110u,110u,110u,109u,109u,109u,109u,108u,108u,108u,108u,107u,107u,107u,107u,107u,106u,106u,106u,106u,105u,105u,105u,105u,104u,104u,104u,104u,103u,103u,103u,103u,103u,102u,102u,102u,102u,101u,101u,101u,101u,100u,100u,100u,100u,100u,99u,99u,99u,99u,98u,98u,98u,98u,98u,97u,97u,97u,97u,96u,96u,96u,96u,95u,95u,95u,95u,95u,94u,94u,94u,94u,93u,93u,93u,93u,93u,92u,92u,92u,92u,91u,91u,91u,91u,90u,90u,90u,90u,90u,89u,89u,89u,89u,88u,88u,88u,88u,88u,87u,87u,87u,87u,86u,86u,86u,86u,86u,85u,85u,85u,85u,84u,84u,84u,84u,84u,83u,83u,83u,83u,82u,82u,82u,82u,82u,81u,81u,81u,81u,80u,80u,80u,80u,80u,79u,79u,79u,79u,79u,78u,78u,78u,78u,77u,77u,77u,77u,77u,76u,76u,76u,76u,76u,75u,75u,75u,75u,74u,74u,74u,74u,74u,73u,73u,73u,73u,73u,72u,72u,72u,72u,71u,71u,71u,71u,71u,70u,70u,70u,70u,70u,69u,69u,69u,69u,69u,68u,68u,68u,68u,68u,67u,67u,67u,67u,66u,66u,66u,66u,66u,65u,65u,65u,65u,65u,64u,64u,64u,64u,64u,63u,63u,63u,63u,63u,62u,62u,62u,62u,62u,61u,61u,61u,61u,61u,60u,60u,60u,60u,60u,59u,59u,59u,59u,59u,58u,58u,58u,58u,58u,57u,57u,57u,57u,57u,56u,56u,56u,56u,56u,56u,55u,55u,55u,55u,55u,54u,54u,54u,54u,54u,53u,53u,53u,53u,53u,52u,52u,52u,52u,52u,52u,51u,51u,51u,51u,51u,50u,50u,50u,50u,50u,49u,49u,49u,49u,49u,49u,48u,48u,48u,48u,48u,47u,47u,47u,47u,47u,47u,46u,46u,46u,46u,46u,46u,45u,45u,45u,45u,45u,44u,44u,44u,44u,44u,44u,43u,43u,43u,43u,43u,43u,42u,42u,42u,42u,42u,41u,41u,41u,41u,41u,41u,40u,40u,40u,40u,40u,40u,39u,39u,39u,39u,39u,39u,38u,38u,38u,38u,38u,38u,37u,37u,37u,37u,37u,37u,37u,36u,36u,36u,36u,36u,36u,35u,35u,35u,35u,35u,35u,34u,34u,34u,34u,34u,34u,33u,33u,33u,33u,33u,33u,33u,32u,32u,32u,32u,32u,32u,32u,31u,31u,31u,31u,31u,31u,30u,30u,30u,30u,30u,30u,30u,29u,29u,29u,29u,29u,29u,29u,28u,28u,28u,28u,28u,28u,28u,27u,27u,27u,27u,27u,27u,27u,26u,26u,26u,26u,26u,26u,26u,25u,25u,25u,25u,25u,25u,25u,25u,24u,24u,24u,24u,24u,24u,24u,23u,23u,23u,23u,23u,23u,23u,23u,22u,22u,22u,22u,22u,22u,22u,22u,21u,21u,21u,21u,21u,21u,21u,21u,20u,20u,20u,20u,20u,20u,20u,20u,19u,19u,19u,19u,19u,19u,19u,19u,19u,18u,18u,18u,18u,18u,18u,18u,18u,18u,17u,17u,17u,17u,17u,17u,17u,17u,17u,16u,16u,16u,16u,16u,16u,16u,16u,16u,15u,15u,15u,15u,15u,15u,15u,15u,15u,15u,14u,14u,14u,14u,14u,14u,14u,14u,14u,14u,13u,13u,13u,13u,13u,13u,13u,13u,13u,13u,13u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,4u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,5u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,6u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,7u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,8u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,9u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,10u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,11u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,12u,13u,13u,13u,13u,13u,13u,13u,13u,13u,13u,14u,14u,14u,14u,14u,14u,14u,14u,14u,14u,14u,15u,15u,15u,15u,15u,15u,15u,15u,15u,16u,16u,16u,16u,16u,16u,16u,16u,16u,16u,17u,17u,17u,17u,17u,17u,17u,17u,17u,18u,18u,18u,18u,18u,18u,18u,18u,18u,19u,19u,19u,19u,19u,19u,19u,19u,20u,20u,20u,20u,20u,20u,20u,20u,21u,21u,21u,21u,21u,21u,21u,21u,21u,22u,22u,22u,22u,22u,22u,22u,23u,23u,23u,23u,23u,23u,23u,23u,24u,24u,24u,24u,24u,24u,24u,24u,25u,25u,25u,25u,25u,25u,25u,26u,26u,26u,26u,26u,26u,26u,27u,27u,27u,27u,27u,27u,27u,27u,28u,28u,28u,28u,28u,28u,28u,29u,29u,29u,29u,29u,29u,29u,30u,30u,30u,30u,30u,30u,31u,31u,31u,31u,31u,31u,31u,32u,32u,32u,32u,32u,32u,32u,33u,33u,33u,33u,33u,33u,34u,34u,34u,34u,34u,34u,35u,35u,35u,35u,35u,35u,35u,36u,36u,36u,36u,36u,36u,37u,37u,37u,37u,37u,37u,38u,38u,38u,38u,38u,38u,39u,39u,39u,39u,39u,39u,40u,40u,40u,40u,40u,40u,41u,41u,41u,41u,41u,41u,42u,42u,42u,42u,42u,42u,43u,43u,43u,43u,43u,43u,44u,44u,44u,44u,44u,45u,45u,45u,45u,45u,45u,46u,46u,46u,46u,46u,46u,47u,47u,47u,47u,47u,48u,48u,48u,48u,48u,48u,49u,49u,49u,49u,49u,50u,50u,50u,50u,50u,51u,51u,51u,51u,51u,51u,52u,52u,52u,52u,52u,53u,53u,53u,53u,53u,54u,54u,54u,54u,54u,54u,55u,55u,55u,55u,55u,56u,56u,56u,56u,56u,57u,57u,57u,57u,57u,58u,58u,58u,58u,58u,59u,59u,59u,59u,59u,60u,60u,60u,60u,60u,61u,61u,61u,61u,61u,62u,62u,62u,62u,62u,63u,63u,63u,63u,63u,64u,64u,64u,64u,64u,65u,65u,65u,65u,65u,66u,66u,66u,66u,66u,67u,67u,67u,67u,67u,68u,68u,68u,68u,68u,69u,69u,69u,69u,69u,70u,70u,70u,70u,71u,71u,71u,71u,71u,72u,72u,72u,72u,72u,73u,73u,73u,73u,73u,74u,74u,74u,74u,75u,75u,75u,75u,75u,76u,76u,76u,76u,76u,77u,77u,77u,77u,78u,78u,78u,78u,78u,79u,79u,79u,79u,80u,80u,80u,80u,80u,81u,81u,81u,81u,81u,82u,82u,82u,82u,83u,83u,83u,83u,83u,84u,84u,84u,84u,85u,85u,85u,85u,85u,86u,86u,86u,86u,87u,87u,87u,87u,87u,88u,88u,88u,88u,89u,89u,89u,89u,89u,90u,90u,90u,90u,91u,91u,91u,91u,91u,92u,92u,92u,92u,93u,93u,93u,93u,94u,94u,94u,94u,94u,95u,95u,95u,95u,96u,96u,96u,96u,96u,97u,97u,97u,97u,98u,98u,98u,98u,99u,99u,99u,99u,99u,100u,100u,100u,100u,101u,101u,101u,101u,102u,102u,102u,102u,102u,103u,103u,103u,103u,104u,104u,104u,104u,105u,105u,105u,105u,105u,106u,106u,106u,106u,107u,107u,107u,107u,108u,108u,108u,108u,108u,109u,109u,109u,109u,110u,110u,110u,110u,111u,111u,111u,111u,112u,112u,112u,112u,112u,113u,113u,113u,113u,114u,114u,114u,114u,115u,115u,115u,115u,116u,116u,116u,116u,116u,117u,117u,117u,117u,118u,118u,118u,118u,119u,119u,119u,119u,119u,120u,120u,120u,120u,121u,121u,121u,121u,122u,122u,122u,122u,123u,123u,123u,123u,123u,124u,124u,124u,124u,125u,125u,125u,125u,126u,126u,126u,126u,127u,127u,127u,127u, Wave1_DCOffset=2.04, Wave1_Length=3333, Wave1_PhaseShift=0, Wave1_Type=0, Wave2_Amplitude=4, Wave2_Data=252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u, Wave2_DCOffset=2.04, Wave2_Length=3333, Wave2_PhaseShift=0, Wave2_Type=1, CY_COMPONENT_NAME=WaveDAC8_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=WaveDAC8, CY_INSTANCE_SHORT_NAME=WaveDAC8, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=WaveDAC8, )
module WaveDAC8_v2_0_9 (
    Wave,
    ws,
    clock,
    wc1,
    wc2);
    inout       Wave;
    electrical  Wave;
    input       ws;
    input       clock;
    output      wc1;
    output      wc2;


          wire  Net_280;
    electrical  Net_273;
          wire  Net_202;
          wire  Net_201;
          wire [7:0] Net_171;
          wire [7:0] Net_170;
          wire  Net_339;
          wire  Net_341;
          wire  Net_153;
    electrical  Net_211;
          wire  Net_134;
          wire  Net_107;
          wire  Net_183;
          wire  Net_336;
          wire  Net_279;
          wire  Net_80;
    electrical  Net_247;
    electrical  Net_254;
    electrical  Net_256;
    electrical  Net_190;
    electrical  Net_189;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_211));


	cy_clock_v1_0
		#(.id("c54d9b1a-bf5f-4dce-befc-b7660f6d96ef/77086516-855e-4b7b-abbe-47b22f8543de"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("100000000000"),
		  .is_direct(0),
		  .is_digital(1))
		DacClk
		 (.clock_out(Net_279));


	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_189, Net_256);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_190, Net_211);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_254));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave1_DMA
		 (.drq(Net_183),
		  .trq(1'b0),
		  .nrq(wc1));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		Wave2_DMA
		 (.drq(Net_107),
		  .trq(1'b0),
		  .nrq(wc2));


    // -- De Mux start --
    if (1)
    begin : demux
        reg  tmp__demux_0_reg;
        reg  tmp__demux_1_reg;
        always @(Net_336 or Net_134)
        begin
            case (Net_134)
                1'b0:
                begin
                    tmp__demux_0_reg = Net_336;
                    tmp__demux_1_reg = 1'b0;
                end
                1'b1:
                begin
                    tmp__demux_0_reg = 1'b0;
                    tmp__demux_1_reg = Net_336;
                end
            endcase
        end
        assign Net_183 = tmp__demux_0_reg;
        assign Net_107 = tmp__demux_1_reg;
    end
    // -- De Mux end --

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_336 = Net_279;

    VDAC8_v1_90_7 VDAC8 (
        .strobe(Net_336),
        .data(8'b00000000),
        .vOut(Net_189));
    defparam VDAC8.Data_Source = 0;
    defparam VDAC8.Initial_Value = 100;
    defparam VDAC8.Strobe_Mode = 1;

    OpAmp_v1_90_8 BuffAmp (
        .Vplus(Net_256),
        .Vout(Net_247),
        .Vminus(Net_273));
    defparam BuffAmp.Mode = 1;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Wave, Net_247);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


    assign Net_280 = Net_279 | Net_80;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_80));

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_336)
    begin
        cydff_1 <= ws;
    end
    assign Net_134 = cydff_1;
    // -- DFF End --



endmodule

// Counter_v2_40(CaptureMode=0, CaptureModeSoftware=0, ClockMode=1, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=32768, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=32768, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=32768, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_COMPONENT_NAME=Counter_v2_40, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=QuadDec_TILT:Cnt16, CY_INSTANCE_SHORT_NAME=Cnt16, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec_TILT_Cnt16, )
module Counter_v2_40_10 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 1;
    parameter CompareMode = 0;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v2_40 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 1;
    defparam CounterUDB.CompareMode = 0;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 16;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// QuadDec_v2_40(Counter8bit=false, CounterResolution=4, CounterSize=32, CounterSizeReplacementString=int32, CounterSizeReplacementStringUnsigned=uint16, TypeCastReplacementString=int32, UsingGlitchFiltering=true, UsingIndexInput=false, CY_COMPONENT_NAME=QuadDec_v2_40, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=QuadDec_TILT, CY_INSTANCE_SHORT_NAME=QuadDec_TILT, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec_TILT, )
module QuadDec_v2_40_11 (
    quad_A,
    quad_B,
    index,
    clock,
    interrupt);
    input       quad_A;
    input       quad_B;
    input       index;
    input       clock;
    output      interrupt;

    parameter CounterResolution = 4;
    parameter UsingGlitchFiltering = 1;
    parameter UsingIndexInput = 0;

          wire  Net_1126;
          wire  Net_1125;
          wire  Net_1124;
          wire  Net_1241;
          wire  Net_1123;
          wire  Net_1132;
          wire  Net_1131;
          wire  Net_1130;
          wire  Net_1243;
          wire  Net_1129;
          wire  Net_1287;
          wire  Net_1272;
          wire  Net_1290;
          wire  Net_1269;
          wire  Net_1264;
          wire  Net_1275;
          wire  Net_1276;
          wire  Net_1203;
          wire  Net_1260;
          wire  Net_1232;
          wire  Net_1229;
          wire  Net_1251;
          wire  Net_611;
          wire  Net_1151;
          wire  Net_1248;
          wire  Net_530;


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr
		 (.int_signal(interrupt));


    Counter_v2_40_10 Cnt16 (
        .reset(Net_1260),
        .tc(Net_1275),
        .comp(Net_1264),
        .clock(clock),
        .interrupt(Net_1129),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(Net_1251),
        .count(Net_1203));
    defparam Cnt16.CaptureMode = 0;
    defparam Cnt16.ClockMode = 1;
    defparam Cnt16.CompareMode = 0;
    defparam Cnt16.CompareStatusEdgeSense = 1;
    defparam Cnt16.EnableMode = 0;
    defparam Cnt16.ReloadOnCapture = 0;
    defparam Cnt16.ReloadOnCompare = 0;
    defparam Cnt16.ReloadOnOverUnder = 1;
    defparam Cnt16.ReloadOnReset = 1;
    defparam Cnt16.Resolution = 16;
    defparam Cnt16.RunMode = 0;
    defparam Cnt16.UseInterrupt = 1;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_1290 = Net_1275;

    bQuadDec_v2_40 bQuadDec (
        .quad_A(quad_A),
        .quad_B(quad_B),
        .index(Net_1232),
        .clock(clock),
        .dir(Net_1251),
        .reset(Net_1260),
        .enable(Net_1203),
        .overflow(Net_530),
        .underflow(Net_611),
        .interrupt(interrupt));
    defparam bQuadDec.CounterResolution = 4;
    defparam bQuadDec.UsingGlitchFiltering = 1;
    defparam bQuadDec.UsingIndexInput = 0;


    assign Net_1151 = ~Net_1251;


    assign Net_530 = Net_1251 & Net_1248;


    assign Net_611 = Net_1151 & Net_1248;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1232 = Net_1229;

    OneTerminal OneTerminal_1 (
        .o(Net_1229));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_1272 = Net_1264;


    assign Net_1287 = ~Net_1272;


    assign Net_1248 = Net_1290 & Net_1287;



endmodule

// VDAC8_v1_90(Data_Source=0, Initial_Value=128, Strobe_Mode=0, VDAC_Range=4, VDAC_Speed=2, Voltage=2048, CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=VDAC8_ANAPOS, CY_INSTANCE_SHORT_NAME=VDAC8_ANAPOS, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=VDAC8_ANAPOS, )
module VDAC8_v1_90_12 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 128;
    parameter Strobe_Mode = 0;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// PGA_v2_0(Gain=0, Power=0, VddaValue=5, Vref_Input=1, CY_COMPONENT_NAME=PGA_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PGA_ASTIM, CY_INSTANCE_SHORT_NAME=PGA_ASTIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PGA_ASTIM, )
module PGA_v2_0_13 (
    Vin,
    Vref,
    Vout);
    inout       Vin;
    electrical  Vin;
    inout       Vref;
    electrical  Vref;
    inout       Vout;
    electrical  Vout;


    electrical  Net_75;
          wire  Net_41;
          wire  Net_40;
    electrical  Net_17;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;

    cy_psoc3_scblock_v1_0 SC (
        .vin(Vin),
        .vref(Net_17),
        .vout(Vout),
        .modout_sync(Net_41),
        .aclk(Net_37),
        .clk_udb(Net_38),
        .dyn_cntl(Net_39),
        .bst_clk(Net_40));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_37));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_38));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_39));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_40));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_17, Vref);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_75));



endmodule

// PWM_v3_0(CaptureMode=0, Compare1_16=false, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=512, CompareValue2=63, CONTROL3=1, ControlReg=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=1, DeadBand2_4=1, DeadBand256=0, DeadBandUsed=1, DeadTime=3, DitherOffset=0, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=1, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=1024, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TriggerMode=0, UDB16=false, UDB8=false, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v3_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PWM_MOTOR_TILT, CY_INSTANCE_SHORT_NAME=PWM_MOTOR_TILT, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PWM_MOTOR_TILT, )
module PWM_v3_0_14 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    cy_psoc3_timer_v1_0 PWMHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_113),
        .kill(Net_107),
        .clock(clock),
        .tc(Net_63),
        .compare(Net_57),
        .interrupt(Net_54));

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_57;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_54;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_63;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = kill;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: FreqDiv_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\FreqDiv_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\FreqDiv_v1_0\FreqDiv_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\FreqDiv_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\FreqDiv_v1_0\FreqDiv_v1_0.v"
`endif

// top
module top ;

          wire  Net_2789;
          wire  Net_2788;
          wire  Net_2785;
          wire  Net_2778;
          wire  Net_2777;
          wire  Net_2776;
          wire  Net_2775;
          wire  Net_2774;
          wire  Net_2773;
          wire  Net_2772;
          wire  Net_2771;
          wire  Net_2770;
          wire  Net_2751;
    electrical  HOME_TILT_ABSV;
    electrical  VREF_sig;
          wire  Net_2698;
          wire  Net_2794;
          wire  Net_2795;
          wire  Net_2839;
          wire  Net_2514;
          wire  Net_2759;
          wire  Net_2758;
          wire  Net_2757;
          wire  Net_2756;
          wire  Net_2755;
          wire  Net_2754;
          wire  Net_2753;
          wire  Net_2752;
          wire  Net_2760;
          wire  Net_2530;
          wire  Net_2487;
          wire  Net_2482;
          wire  Net_2338;
          wire [7:0] Net_2275;
          wire  Net_2274;
          wire  Net_2273;
          wire  Net_2272;
          wire  Net_2271;
          wire  Net_2270;
          wire  Net_2632;
          wire  Net_2631;
          wire  Net_2196;
          wire  Net_2237;
          wire  CLK_20MHz;
          wire  Net_1801;
          wire  Net_1813;
          wire  Net_1812;
          wire  Net_1811;
          wire  Net_1810;
          wire  Net_1809;
          wire  Net_1808;
          wire  Net_1807;
          wire  Net_1806;
          wire  Net_1805;
          wire  Net_1789;
          wire [7:0] Net_1456;
          wire  Net_1455;
          wire  Net_1826;
          wire  Net_1788;
          wire  Net_1787;
          wire  Net_2836;
          wire  Net_2826;
          wire  Net_2825;
          wire  Net_2824;
          wire  Net_2823;
          wire  Net_2822;
          wire  Net_2821;
          wire  Net_2819;
          wire  Net_2817;
          wire  Net_2816;
          wire  Net_2646;
          wire  Net_2645;
          wire  Net_2644;
          wire  Net_1353;
          wire [7:0] Net_2375;
          wire  Net_2374;
          wire  Net_2373;
          wire  Net_2372;
          wire  Net_2371;
          wire  Net_2370;
          wire  Net_2726;
          wire  Net_1171;
          wire  Net_1170;
          wire  Net_2204;
          wire  Net_2203;
          wire  Net_1156;
          wire  Net_1155;
          wire  CLK_100Hz;
          wire  Net_1154;
          wire  Net_1153;
          wire  Net_1152;
          wire  Net_1151;
          wire  Net_1352;
          wire  Net_1103;
          wire  Net_1150;
          wire  Net_1149;
          wire  Net_2265;
          wire  Net_1139;
          wire  Net_1138;
          wire  Net_1137;
          wire  Net_1136;
          wire  Net_1135;
          wire  Net_1134;
          wire  Net_1133;
          wire  Net_1132;
          wire  Net_1131;
          wire  Net_1020;
          wire  Net_1130;
          wire  Net_1129;
          wire  Net_1128;
          wire  Net_1127;
          wire  Net_1126;
          wire  Net_1125;
          wire  Net_1124;
          wire  Net_1123;
          wire  Net_1122;
    electrical  Net_921;
    electrical  Net_920;
    electrical  Net_919;
          wire  Net_2195;
          wire  Net_2266;
    electrical  Net_923;
    electrical  Net_922;
    electrical  Net_905;
    electrical  Net_2849;
    electrical  Net_903;
          wire  Net_1297;
          wire  Net_2701;
          wire  Net_1754;
          wire  Net_1753;
          wire  Net_1752;
          wire  Net_1751;
          wire  Net_1750;
          wire  Net_1749;
          wire  Net_1748;
          wire  Net_1747;
          wire  Net_1746;
          wire  Net_1726;
          wire  Net_1727;
          wire  Net_2194;
    electrical  Net_907;
    electrical  Net_906;
    electrical  Net_893;
    electrical  Net_692;
    electrical  Net_894;
    electrical  Net_609;
    electrical  Net_608;
          wire  Net_601;
          wire  Net_600;
          wire  Net_599;
          wire  Net_598;
          wire  Net_597;
          wire  Net_596;
          wire  Net_603;
          wire  Net_1412;
          wire  Net_1411;
          wire  Net_1410;
          wire  Net_1409;
          wire  Net_1408;
          wire  Net_1407;
          wire  Net_1406;
          wire  Net_1405;
          wire  Net_334;
          wire [7:0] Net_1290;
          wire  Net_1289;
          wire  Net_1288;
          wire  Net_1287;
          wire  Net_1286;
          wire  Net_1285;
          wire  Net_1283;
          wire  Net_391;
          wire  Net_1121;
          wire  Net_1120;
          wire  Net_1119;
          wire  Net_1118;
          wire  Net_1117;
          wire  CLK_1500Hz;
          wire  Net_1116;
          wire  Net_386;
          wire  Net_385;
          wire  Net_384;
          wire  Net_383;
          wire  Net_382;
          wire  Net_381;
          wire  Net_376;
          wire  Net_380;
          wire  Net_379;
          wire  Net_378;
          wire  Net_1861;
    electrical  HOME_PAN_ABSV;
          wire  Net_377;
          wire  Net_1264;
    electrical  Net_390;
          wire  Net_389;
          wire  Net_388;
          wire  Net_387;
          wire  Net_989;
          wire  Net_1368;
          wire  Net_1284;
          wire  Net_677;
          wire  Net_678;
          wire  Net_2832;
          wire  Net_2829;
          wire  Net_2830;
          wire  Net_2643;
          wire  Net_492;
    electrical  Net_40;
    electrical  Net_785;
    electrical  Net_43;
    electrical  Net_42;
    electrical  Net_41;
    electrical  Net_786;
    electrical  Net_2353;
    electrical  Net_1386;
          wire  Net_2472;
          wire  Net_1251;
          wire  Net_1252;
          wire  Net_1253;
          wire  Net_2138;
          wire  Net_1255;
    electrical  Net_216;
          wire  Net_2239;
          wire  Net_2269;
          wire  Net_2206;
          wire  Net_1105;
          wire  Net_2199;
          wire  Net_1802;
          wire  Net_404;
          wire  Net_1790;
          wire  Net_1314;
          wire  Net_1783;
          wire  Net_1782;
    electrical  Net_1463;
          wire  Net_547;
          wire  Net_1169;
          wire  Net_1168;
          wire  Net_693;
          wire  Net_1266;
          wire  Net_535;
          wire  Net_533;
          wire  Net_426;
          wire  Net_2324;
          wire  CLK_25Hz;
          wire  Net_424;

	wire [0:0] tmpOE__SENSE_IPAN_net;
	wire [0:0] tmpFB_0__SENSE_IPAN_net;
	wire [0:0] tmpIO_0__SENSE_IPAN_net;
	wire [0:0] tmpINTERRUPT_0__SENSE_IPAN_net;
	electrical [0:0] tmpSIOVREF__SENSE_IPAN_net;

	cy_psoc3_pins_v1_10
		#(.id("cc3bcd7e-5dc0-48ea-9bf6-6aa082be1ada"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		SENSE_IPAN
		 (.oe(tmpOE__SENSE_IPAN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SENSE_IPAN_net[0:0]}),
		  .analog({Net_786}),
		  .io({tmpIO_0__SENSE_IPAN_net[0:0]}),
		  .siovref(tmpSIOVREF__SENSE_IPAN_net),
		  .interrupt({tmpINTERRUPT_0__SENSE_IPAN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SENSE_IPAN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SENSE_VCC_net;
	wire [0:0] tmpFB_0__SENSE_VCC_net;
	wire [0:0] tmpIO_0__SENSE_VCC_net;
	wire [0:0] tmpINTERRUPT_0__SENSE_VCC_net;
	electrical [0:0] tmpSIOVREF__SENSE_VCC_net;

	cy_psoc3_pins_v1_10
		#(.id("1e4f20c8-114d-4239-9366-1a6542bf55db"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		SENSE_VCC
		 (.oe(tmpOE__SENSE_VCC_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SENSE_VCC_net[0:0]}),
		  .analog({Net_40}),
		  .io({tmpIO_0__SENSE_VCC_net[0:0]}),
		  .siovref(tmpSIOVREF__SENSE_VCC_net),
		  .interrupt({tmpINTERRUPT_0__SENSE_VCC_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SENSE_VCC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXL_Z_net;
	wire [0:0] tmpFB_0__ADXL_Z_net;
	wire [0:0] tmpIO_0__ADXL_Z_net;
	wire [0:0] tmpINTERRUPT_0__ADXL_Z_net;
	electrical [0:0] tmpSIOVREF__ADXL_Z_net;

	cy_psoc3_pins_v1_10
		#(.id("7b23f3a3-4c8a-4d43-89ae-d03a5fe6ebaf"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_Z
		 (.oe(tmpOE__ADXL_Z_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXL_Z_net[0:0]}),
		  .analog({Net_43}),
		  .io({tmpIO_0__ADXL_Z_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_Z_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_Z_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ADXL_Z_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXL_Y_net;
	wire [0:0] tmpFB_0__ADXL_Y_net;
	wire [0:0] tmpIO_0__ADXL_Y_net;
	wire [0:0] tmpINTERRUPT_0__ADXL_Y_net;
	electrical [0:0] tmpSIOVREF__ADXL_Y_net;

	cy_psoc3_pins_v1_10
		#(.id("b497c8ab-c4f8-4c07-a28a-293e34843a0c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_Y
		 (.oe(tmpOE__ADXL_Y_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXL_Y_net[0:0]}),
		  .analog({Net_42}),
		  .io({tmpIO_0__ADXL_Y_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_Y_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_Y_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ADXL_Y_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXL_X_net;
	wire [0:0] tmpFB_0__ADXL_X_net;
	wire [0:0] tmpIO_0__ADXL_X_net;
	wire [0:0] tmpINTERRUPT_0__ADXL_X_net;
	electrical [0:0] tmpSIOVREF__ADXL_X_net;

	cy_psoc3_pins_v1_10
		#(.id("d7b2b2c9-e238-4959-91a0-18330834a962"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_X
		 (.oe(tmpOE__ADXL_X_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXL_X_net[0:0]}),
		  .analog({Net_41}),
		  .io({tmpIO_0__ADXL_X_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_X_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_X_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ADXL_X_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ANAPOS_OUTPUT_net;
	wire [0:0] tmpFB_0__ANAPOS_OUTPUT_net;
	wire [0:0] tmpIO_0__ANAPOS_OUTPUT_net;
	wire [0:0] tmpINTERRUPT_0__ANAPOS_OUTPUT_net;
	electrical [0:0] tmpSIOVREF__ANAPOS_OUTPUT_net;

	cy_psoc3_pins_v1_10
		#(.id("8c8a886a-fc73-40da-a712-753a4714b453"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ANAPOS_OUTPUT
		 (.oe(tmpOE__ANAPOS_OUTPUT_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ANAPOS_OUTPUT_net[0:0]}),
		  .analog({Net_1463}),
		  .io({tmpIO_0__ANAPOS_OUTPUT_net[0:0]}),
		  .siovref(tmpSIOVREF__ANAPOS_OUTPUT_net),
		  .interrupt({tmpINTERRUPT_0__ANAPOS_OUTPUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ANAPOS_OUTPUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_DelSig_v3_10_0 ADC (
        .vplus(Net_216),
        .vminus(VREF_sig),
        .soc(1'b1),
        .eoc(Net_388),
        .aclk(1'b0),
        .nVref(Net_390),
        .mi(1'b0));

    UART_v2_30_1 UART_USB (
        .cts_n(1'b0),
        .tx(Net_1861),
        .rts_n(Net_378),
        .tx_en(Net_379),
        .clock(1'b0),
        .reset(Net_424),
        .rx(Net_376),
        .tx_interrupt(Net_381),
        .rx_interrupt(Net_382),
        .tx_data(Net_383),
        .tx_clk(Net_384),
        .rx_data(Net_385),
        .rx_clk(Net_386));
    defparam UART_USB.Address1 = 0;
    defparam UART_USB.Address2 = 0;
    defparam UART_USB.EnIntRXInterrupt = 0;
    defparam UART_USB.EnIntTXInterrupt = 0;
    defparam UART_USB.FlowControl = 0;
    defparam UART_USB.HalfDuplexEn = 0;
    defparam UART_USB.HwTXEnSignal = 0;
    defparam UART_USB.NumDataBits = 8;
    defparam UART_USB.NumStopBits = 1;
    defparam UART_USB.ParityType = 0;
    defparam UART_USB.RXEnable = 1;
    defparam UART_USB.TXEnable = 1;

	wire [0:0] tmpOE__PSOC_RX_net;
	wire [0:0] tmpIO_0__PSOC_RX_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_RX_net;
	electrical [0:0] tmpSIOVREF__PSOC_RX_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		PSOC_RX
		 (.oe(tmpOE__PSOC_RX_net),
		  .y({1'b0}),
		  .fb({Net_376}),
		  .io({tmpIO_0__PSOC_RX_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_RX_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_RX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_RX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PSOC_TX_net;
	wire [0:0] tmpFB_0__PSOC_TX_net;
	wire [0:0] tmpIO_0__PSOC_TX_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_TX_net;
	electrical [0:0] tmpSIOVREF__PSOC_TX_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_TX
		 (.oe(tmpOE__PSOC_TX_net),
		  .y({Net_1861}),
		  .fb({tmpFB_0__PSOC_TX_net[0:0]}),
		  .io({tmpIO_0__PSOC_TX_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_TX_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_TX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_TX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_424));

	wire [0:0] tmpOE__VREF_net;
	wire [0:0] tmpFB_0__VREF_net;
	wire [0:0] tmpIO_0__VREF_net;
	wire [0:0] tmpINTERRUPT_0__VREF_net;
	electrical [0:0] tmpSIOVREF__VREF_net;

	cy_psoc3_pins_v1_10
		#(.id("3151ed63-901f-40ac-ab1f-c99b56eb2dcd"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		VREF
		 (.oe(tmpOE__VREF_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__VREF_net[0:0]}),
		  .analog({VREF_sig}),
		  .io({tmpIO_0__VREF_net[0:0]}),
		  .siovref(tmpSIOVREF__VREF_net),
		  .interrupt({tmpINTERRUPT_0__VREF_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__VREF_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_70 Control_Reg_LED (
        .control_1(Net_426),
        .control_2(Net_1266),
        .control_3(Net_693),
        .control_0(Net_492),
        .control_4(Net_1116),
        .control_5(Net_1117),
        .control_6(Net_1118),
        .control_7(Net_1119),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_LED.Bit0Mode = 0;
    defparam Control_Reg_LED.Bit1Mode = 0;
    defparam Control_Reg_LED.Bit2Mode = 0;
    defparam Control_Reg_LED.Bit3Mode = 0;
    defparam Control_Reg_LED.Bit4Mode = 0;
    defparam Control_Reg_LED.Bit5Mode = 0;
    defparam Control_Reg_LED.Bit6Mode = 0;
    defparam Control_Reg_LED.Bit7Mode = 0;
    defparam Control_Reg_LED.BitValue = 0;
    defparam Control_Reg_LED.BusDisplay = 0;
    defparam Control_Reg_LED.ExtrReset = 0;
    defparam Control_Reg_LED.NumOutputs = 4;

	wire [0:0] tmpOE__LED_OK_net;
	wire [0:0] tmpFB_0__LED_OK_net;
	wire [0:0] tmpIO_0__LED_OK_net;
	wire [0:0] tmpINTERRUPT_0__LED_OK_net;
	electrical [0:0] tmpSIOVREF__LED_OK_net;

	cy_psoc3_pins_v1_10
		#(.id("8585c6d0-1afb-4de8-a49b-a51e5062b18f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LED_OK
		 (.oe(tmpOE__LED_OK_net),
		  .y({Net_404}),
		  .fb({tmpFB_0__LED_OK_net[0:0]}),
		  .io({tmpIO_0__LED_OK_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_OK_net),
		  .interrupt({tmpINTERRUPT_0__LED_OK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_OK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- AMux AMuxSeq start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMuxSeq(
        .muxin({
            Net_2353,
            HOME_TILT_ABSV,
            HOME_PAN_ABSV,
            Net_43,
            Net_42,
            Net_41,
            Net_40,
            Net_785,
            Net_786
            }),
        .vout(Net_216)
        );
    
    defparam AMuxSeq.muxin_width = 9;
    defparam AMuxSeq.init_mux_sel = 9'h0;
    defparam AMuxSeq.api_type = 1'b1;
    defparam AMuxSeq.one_active = 1;
    defparam AMuxSeq.connect_mode = 1;
    
    // -- AMux AMuxSeq end --


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_CTRL
		 (.int_signal(CLK_1500Hz));



	cy_clock_v1_0
		#(.id("96809c05-31ec-4e83-9db7-a625d499011f"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("666666666666.667"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_CTRL
		 (.clock_out(CLK_1500Hz),
		  .dig_domain_out(Net_391));


	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_404 = Net_2324;

    CyStatusReg_v1_80 Status_Reg_BUTTON (
        .status_0(Net_1368),
        .status_1(Net_677),
        .status_2(Net_678),
        .status_3(1'b0),
        .clock(Net_1284),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_1289),
        .status_bus(8'b0));
    defparam Status_Reg_BUTTON.Bit0Mode = 0;
    defparam Status_Reg_BUTTON.Bit1Mode = 0;
    defparam Status_Reg_BUTTON.Bit2Mode = 0;
    defparam Status_Reg_BUTTON.Bit3Mode = 0;
    defparam Status_Reg_BUTTON.Bit4Mode = 0;
    defparam Status_Reg_BUTTON.Bit5Mode = 0;
    defparam Status_Reg_BUTTON.Bit6Mode = 0;
    defparam Status_Reg_BUTTON.Bit7Mode = 0;
    defparam Status_Reg_BUTTON.BusDisplay = 0;
    defparam Status_Reg_BUTTON.Interrupt = 0;
    defparam Status_Reg_BUTTON.MaskValue = 0;
    defparam Status_Reg_BUTTON.NumInputs = 3;

    Counter_v2_40_2 Counter_LED (
        .reset(Net_334),
        .tc(Net_2472),
        .comp(Net_1405),
        .clock(CLK_100Hz),
        .interrupt(Net_1406),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Counter_LED.CaptureMode = 0;
    defparam Counter_LED.ClockMode = 3;
    defparam Counter_LED.CompareMode = 1;
    defparam Counter_LED.CompareStatusEdgeSense = 1;
    defparam Counter_LED.EnableMode = 0;
    defparam Counter_LED.ReloadOnCapture = 0;
    defparam Counter_LED.ReloadOnCompare = 0;
    defparam Counter_LED.ReloadOnOverUnder = 1;
    defparam Counter_LED.ReloadOnReset = 1;
    defparam Counter_LED.Resolution = 8;
    defparam Counter_LED.RunMode = 0;
    defparam Counter_LED.UseInterrupt = 1;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_334));

	wire [0:0] tmpOE__LED_FAULT_net;
	wire [0:0] tmpFB_0__LED_FAULT_net;
	wire [0:0] tmpIO_0__LED_FAULT_net;
	wire [0:0] tmpINTERRUPT_0__LED_FAULT_net;
	electrical [0:0] tmpSIOVREF__LED_FAULT_net;

	cy_psoc3_pins_v1_10
		#(.id("d6c92319-8134-4712-b790-874f01999c96"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LED_FAULT
		 (.oe(tmpOE__LED_FAULT_net),
		  .y({Net_426}),
		  .fb({tmpFB_0__LED_FAULT_net[0:0]}),
		  .io({tmpIO_0__LED_FAULT_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_FAULT_net),
		  .interrupt({tmpINTERRUPT_0__LED_FAULT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_FAULT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_70 Control_Reg_SYS (
        .control_1(Net_535),
        .control_2(Net_547),
        .control_3(Net_603),
        .control_0(Net_533),
        .control_4(Net_596),
        .control_5(Net_597),
        .control_6(Net_598),
        .control_7(Net_599),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_SYS.Bit0Mode = 0;
    defparam Control_Reg_SYS.Bit1Mode = 0;
    defparam Control_Reg_SYS.Bit2Mode = 0;
    defparam Control_Reg_SYS.Bit3Mode = 0;
    defparam Control_Reg_SYS.Bit4Mode = 0;
    defparam Control_Reg_SYS.Bit5Mode = 0;
    defparam Control_Reg_SYS.Bit6Mode = 0;
    defparam Control_Reg_SYS.Bit7Mode = 0;
    defparam Control_Reg_SYS.BitValue = 0;
    defparam Control_Reg_SYS.BusDisplay = 0;
    defparam Control_Reg_SYS.ExtrReset = 0;
    defparam Control_Reg_SYS.NumOutputs = 3;

	wire [0:0] tmpOE__V5_PHER_nSHDN_net;
	wire [0:0] tmpFB_0__V5_PHER_nSHDN_net;
	wire [0:0] tmpIO_0__V5_PHER_nSHDN_net;
	wire [0:0] tmpINTERRUPT_0__V5_PHER_nSHDN_net;
	electrical [0:0] tmpSIOVREF__V5_PHER_nSHDN_net;

	cy_psoc3_pins_v1_10
		#(.id("6dc464ef-8a8c-4844-b749-902ca620a40c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		V5_PHER_nSHDN
		 (.oe(tmpOE__V5_PHER_nSHDN_net),
		  .y({Net_533}),
		  .fb({tmpFB_0__V5_PHER_nSHDN_net[0:0]}),
		  .io({tmpIO_0__V5_PHER_nSHDN_net[0:0]}),
		  .siovref(tmpSIOVREF__V5_PHER_nSHDN_net),
		  .interrupt({tmpINTERRUPT_0__V5_PHER_nSHDN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__V5_PHER_nSHDN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__V3_nSHDN_net;
	wire [0:0] tmpFB_0__V3_nSHDN_net;
	wire [0:0] tmpIO_0__V3_nSHDN_net;
	wire [0:0] tmpINTERRUPT_0__V3_nSHDN_net;
	electrical [0:0] tmpSIOVREF__V3_nSHDN_net;

	cy_psoc3_pins_v1_10
		#(.id("dc29294b-f8d3-4bb6-aabf-514e7b773c40"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		V3_nSHDN
		 (.oe(tmpOE__V3_nSHDN_net),
		  .y({Net_535}),
		  .fb({tmpFB_0__V3_nSHDN_net[0:0]}),
		  .io({tmpIO_0__V3_nSHDN_net[0:0]}),
		  .siovref(tmpSIOVREF__V3_nSHDN_net),
		  .interrupt({tmpINTERRUPT_0__V3_nSHDN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__V3_nSHDN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LED_WIFI_OK_net;
	wire [0:0] tmpFB_0__LED_WIFI_OK_net;
	wire [0:0] tmpIO_0__LED_WIFI_OK_net;
	wire [0:0] tmpINTERRUPT_0__LED_WIFI_OK_net;
	electrical [0:0] tmpSIOVREF__LED_WIFI_OK_net;

	cy_psoc3_pins_v1_10
		#(.id("31ee5473-bcee-4a3c-b6ca-8601ef9b6b4e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LED_WIFI_OK
		 (.oe(tmpOE__LED_WIFI_OK_net),
		  .y({Net_1266}),
		  .fb({tmpFB_0__LED_WIFI_OK_net[0:0]}),
		  .io({tmpIO_0__LED_WIFI_OK_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_WIFI_OK_net),
		  .interrupt({tmpINTERRUPT_0__LED_WIFI_OK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_WIFI_OK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LED_WIFI_FAULT_net;
	wire [0:0] tmpFB_0__LED_WIFI_FAULT_net;
	wire [0:0] tmpIO_0__LED_WIFI_FAULT_net;
	wire [0:0] tmpINTERRUPT_0__LED_WIFI_FAULT_net;
	electrical [0:0] tmpSIOVREF__LED_WIFI_FAULT_net;

	cy_psoc3_pins_v1_10
		#(.id("e8b7ce7d-db8f-45c2-9744-04f92f9ebb38"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LED_WIFI_FAULT
		 (.oe(tmpOE__LED_WIFI_FAULT_net),
		  .y({Net_693}),
		  .fb({tmpFB_0__LED_WIFI_FAULT_net[0:0]}),
		  .io({tmpIO_0__LED_WIFI_FAULT_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_WIFI_FAULT_net),
		  .interrupt({tmpINTERRUPT_0__LED_WIFI_FAULT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_WIFI_FAULT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SENSE_ITILT_net;
	wire [0:0] tmpFB_0__SENSE_ITILT_net;
	wire [0:0] tmpIO_0__SENSE_ITILT_net;
	wire [0:0] tmpINTERRUPT_0__SENSE_ITILT_net;
	electrical [0:0] tmpSIOVREF__SENSE_ITILT_net;

	cy_psoc3_pins_v1_10
		#(.id("f86de07f-e47d-45fd-85c7-4412185ce01b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		SENSE_ITILT
		 (.oe(tmpOE__SENSE_ITILT_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SENSE_ITILT_net[0:0]}),
		  .analog({Net_785}),
		  .io({tmpIO_0__SENSE_ITILT_net[0:0]}),
		  .siovref(tmpSIOVREF__SENSE_ITILT_net),
		  .interrupt({tmpINTERRUPT_0__SENSE_ITILT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SENSE_ITILT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__HOME_PAN_net;
	wire [0:0] tmpFB_0__HOME_PAN_net;
	wire [0:0] tmpIO_0__HOME_PAN_net;
	wire [0:0] tmpINTERRUPT_0__HOME_PAN_net;
	electrical [0:0] tmpSIOVREF__HOME_PAN_net;

	cy_psoc3_pins_v1_10
		#(.id("d4b42c1c-dbd0-4215-ac50-ce5814d58140"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		HOME_PAN
		 (.oe(tmpOE__HOME_PAN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__HOME_PAN_net[0:0]}),
		  .analog({HOME_PAN_ABSV}),
		  .io({tmpIO_0__HOME_PAN_net[0:0]}),
		  .siovref(tmpSIOVREF__HOME_PAN_net),
		  .interrupt({tmpINTERRUPT_0__HOME_PAN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__HOME_PAN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXL_ST_net;
	wire [0:0] tmpFB_0__ADXL_ST_net;
	wire [0:0] tmpIO_0__ADXL_ST_net;
	wire [0:0] tmpINTERRUPT_0__ADXL_ST_net;
	electrical [0:0] tmpSIOVREF__ADXL_ST_net;

	cy_psoc3_pins_v1_10
		#(.id("1b6546c6-9b0f-46df-9222-08a17bf84adb"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_ST
		 (.oe(tmpOE__ADXL_ST_net),
		  .y({Net_547}),
		  .fb({tmpFB_0__ADXL_ST_net[0:0]}),
		  .io({tmpIO_0__ADXL_ST_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_ST_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_ST_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ADXL_ST_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__nBUTTON_PUSH_net;
	wire [0:0] tmpIO_0__nBUTTON_PUSH_net;
	wire [0:0] tmpINTERRUPT_0__nBUTTON_PUSH_net;
	electrical [0:0] tmpSIOVREF__nBUTTON_PUSH_net;

	cy_psoc3_pins_v1_10
		#(.id("5d2c3560-86fd-457e-9ff6-08d703fb68be"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b01),
		  .width(1))
		nBUTTON_PUSH
		 (.oe(tmpOE__nBUTTON_PUSH_net),
		  .y({1'b0}),
		  .fb({Net_1368}),
		  .io({tmpIO_0__nBUTTON_PUSH_net[0:0]}),
		  .siovref(tmpSIOVREF__nBUTTON_PUSH_net),
		  .interrupt({tmpINTERRUPT_0__nBUTTON_PUSH_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__nBUTTON_PUSH_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_PUSH (
        .connect({
            Net_608,
            Net_609
        })
    );
    defparam SW_PUSH.comp_name = "SwitchSPST_v1_0";
    defparam SW_PUSH.port_names = "T1, T2";
    defparam SW_PUSH.width = 2;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_894
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 R (
        .connect({
            Net_692,
            Net_893
        })
    );
    defparam R.comp_name = "Resistor_v1_0";
    defparam R.port_names = "T1, T2";
    defparam R.width = 2;

    cy_annotation_universal_v1_0 VDD (
        .connect({
            Net_893
        })
    );
    defparam VDD.comp_name = "Power_v1_0";
    defparam VDD.port_names = "T1";
    defparam VDD.width = 1;

    cy_annotation_universal_v1_0 SW_CW (
        .connect({
            Net_906,
            Net_907
        })
    );
    defparam SW_CW.comp_name = "SwitchSPST_v1_0";
    defparam SW_CW.port_names = "T1, T2";
    defparam SW_CW.width = 2;

	wire [0:0] tmpOE__nBUTTON_CW_net;
	wire [0:0] tmpIO_0__nBUTTON_CW_net;
	wire [0:0] tmpINTERRUPT_0__nBUTTON_CW_net;
	electrical [0:0] tmpSIOVREF__nBUTTON_CW_net;

	cy_psoc3_pins_v1_10
		#(.id("0025a344-f123-4259-8def-63d1d4896827"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b01),
		  .width(1))
		nBUTTON_CW
		 (.oe(tmpOE__nBUTTON_CW_net),
		  .y({1'b0}),
		  .fb({Net_677}),
		  .io({tmpIO_0__nBUTTON_CW_net[0:0]}),
		  .siovref(tmpSIOVREF__nBUTTON_CW_net),
		  .interrupt({tmpINTERRUPT_0__nBUTTON_CW_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__nBUTTON_CW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("29133c7f-5793-4b3b-b451-0cd37df3f20b"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_SPI
		 (.clock_out(Net_1255));


    I2C_v3_30_3 I2C_COULOMB (
        .sda(Net_1727),
        .scl(Net_1726),
        .clock(1'b0),
        .reset(1'b0),
        .bclk(Net_1748),
        .iclk(Net_1749),
        .scl_i(1'b0),
        .sda_i(1'b0),
        .scl_o(Net_1752),
        .sda_o(Net_1753),
        .itclk(Net_1754));

	wire [0:0] tmpOE__CC_SDA_net;
	wire [0:0] tmpFB_0__CC_SDA_net;
	wire [0:0] tmpINTERRUPT_0__CC_SDA_net;
	electrical [0:0] tmpSIOVREF__CC_SDA_net;

	cy_psoc3_pins_v1_10
		#(.id("8ed24c43-4747-4b72-8fd1-4a8f71fe234f"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		CC_SDA
		 (.oe(tmpOE__CC_SDA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__CC_SDA_net[0:0]}),
		  .io({Net_1727}),
		  .siovref(tmpSIOVREF__CC_SDA_net),
		  .interrupt({tmpINTERRUPT_0__CC_SDA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CC_SDA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LORA_SETA_net;
	wire [0:0] tmpFB_0__LORA_SETA_net;
	wire [0:0] tmpIO_0__LORA_SETA_net;
	wire [0:0] tmpINTERRUPT_0__LORA_SETA_net;
	electrical [0:0] tmpSIOVREF__LORA_SETA_net;

	cy_psoc3_pins_v1_10
		#(.id("4717cb34-7940-4003-9f44-04bd662d4ed7"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LORA_SETA
		 (.oe(tmpOE__LORA_SETA_net),
		  .y({Net_2701}),
		  .fb({tmpFB_0__LORA_SETA_net[0:0]}),
		  .io({tmpIO_0__LORA_SETA_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_SETA_net),
		  .interrupt({tmpINTERRUPT_0__LORA_SETA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_SETA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_1297 = CLK_1500Hz & Net_989;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_903,
            Net_2849
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 VDD_1 (
        .connect({
            Net_2849
        })
    );
    defparam VDD_1.comp_name = "Power_v1_0";
    defparam VDD_1.port_names = "T1";
    defparam VDD_1.width = 1;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_905
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

	wire [0:0] tmpOE__nBUTTON_CCW_net;
	wire [0:0] tmpIO_0__nBUTTON_CCW_net;
	wire [0:0] tmpINTERRUPT_0__nBUTTON_CCW_net;
	electrical [0:0] tmpSIOVREF__nBUTTON_CCW_net;

	cy_psoc3_pins_v1_10
		#(.id("f299cea4-eae8-44f1-9f96-9f818cb3852e"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b01),
		  .width(1))
		nBUTTON_CCW
		 (.oe(tmpOE__nBUTTON_CCW_net),
		  .y({1'b0}),
		  .fb({Net_678}),
		  .io({tmpIO_0__nBUTTON_CCW_net[0:0]}),
		  .siovref(tmpSIOVREF__nBUTTON_CCW_net),
		  .interrupt({tmpINTERRUPT_0__nBUTTON_CCW_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__nBUTTON_CCW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_CCW (
        .connect({
            Net_922,
            Net_923
        })
    );
    defparam SW_CCW.comp_name = "SwitchSPST_v1_0";
    defparam SW_CCW.port_names = "T1, T2";
    defparam SW_CCW.width = 2;

	wire [0:0] tmpOE__TILT_MOT_FL_net;
	wire [0:0] tmpIO_0__TILT_MOT_FL_net;
	wire [0:0] tmpINTERRUPT_0__TILT_MOT_FL_net;
	electrical [0:0] tmpSIOVREF__TILT_MOT_FL_net;

	cy_psoc3_pins_v1_10
		#(.id("f9c9b793-303b-47a5-bc35-ce6ffc05f3e5"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		TILT_MOT_FL
		 (.oe(tmpOE__TILT_MOT_FL_net),
		  .y({1'b0}),
		  .fb({Net_2266}),
		  .io({tmpIO_0__TILT_MOT_FL_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_MOT_FL_net),
		  .interrupt({tmpINTERRUPT_0__TILT_MOT_FL_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_MOT_FL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("043d393f-b255-4ffd-9061-583ca33f01a5"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_5
		 (.clock_out(Net_1284));


    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_919,
            Net_920
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 VDD_2 (
        .connect({
            Net_920
        })
    );
    defparam VDD_2.comp_name = "Power_v1_0";
    defparam VDD_2.port_names = "T1";
    defparam VDD_2.width = 1;

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_921
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

    CyControlReg_v1_70 Control_Reg_BUZ (
        .control_1(Net_1122),
        .control_2(Net_1123),
        .control_3(Net_1124),
        .control_0(Net_989),
        .control_4(Net_1125),
        .control_5(Net_1126),
        .control_6(Net_1127),
        .control_7(Net_1128),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_BUZ.Bit0Mode = 0;
    defparam Control_Reg_BUZ.Bit1Mode = 0;
    defparam Control_Reg_BUZ.Bit2Mode = 0;
    defparam Control_Reg_BUZ.Bit3Mode = 0;
    defparam Control_Reg_BUZ.Bit4Mode = 0;
    defparam Control_Reg_BUZ.Bit5Mode = 0;
    defparam Control_Reg_BUZ.Bit6Mode = 0;
    defparam Control_Reg_BUZ.Bit7Mode = 0;
    defparam Control_Reg_BUZ.BitValue = 0;
    defparam Control_Reg_BUZ.BusDisplay = 0;
    defparam Control_Reg_BUZ.ExtrReset = 0;
    defparam Control_Reg_BUZ.NumOutputs = 1;

	wire [0:0] tmpOE__BUZ_net;
	wire [0:0] tmpFB_0__BUZ_net;
	wire [0:0] tmpIO_0__BUZ_net;
	wire [0:0] tmpINTERRUPT_0__BUZ_net;
	electrical [0:0] tmpSIOVREF__BUZ_net;

	cy_psoc3_pins_v1_10
		#(.id("04f5d8ab-78ba-4565-9107-ddc62a4fb5d9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		BUZ
		 (.oe(tmpOE__BUZ_net),
		  .y({Net_1297}),
		  .fb({tmpFB_0__BUZ_net[0:0]}),
		  .io({tmpIO_0__BUZ_net[0:0]}),
		  .siovref(tmpSIOVREF__BUZ_net),
		  .interrupt({tmpINTERRUPT_0__BUZ_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BUZ_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MOT_SLEEPn_net;
	wire [0:0] tmpFB_0__MOT_SLEEPn_net;
	wire [0:0] tmpIO_0__MOT_SLEEPn_net;
	wire [0:0] tmpINTERRUPT_0__MOT_SLEEPn_net;
	electrical [0:0] tmpSIOVREF__MOT_SLEEPn_net;

	cy_psoc3_pins_v1_10
		#(.id("8613fe86-8921-4b48-b9e2-225dbe5147b1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		MOT_SLEEPn
		 (.oe(tmpOE__MOT_SLEEPn_net),
		  .y({Net_1020}),
		  .fb({tmpFB_0__MOT_SLEEPn_net[0:0]}),
		  .io({tmpIO_0__MOT_SLEEPn_net[0:0]}),
		  .siovref(tmpSIOVREF__MOT_SLEEPn_net),
		  .interrupt({tmpINTERRUPT_0__MOT_SLEEPn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MOT_SLEEPn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_70 Control_Reg_MOTOR (
        .control_1(Net_1131),
        .control_2(Net_1132),
        .control_3(Net_1133),
        .control_0(Net_1020),
        .control_4(Net_1134),
        .control_5(Net_1135),
        .control_6(Net_1136),
        .control_7(Net_1137),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_MOTOR.Bit0Mode = 0;
    defparam Control_Reg_MOTOR.Bit1Mode = 0;
    defparam Control_Reg_MOTOR.Bit2Mode = 0;
    defparam Control_Reg_MOTOR.Bit3Mode = 0;
    defparam Control_Reg_MOTOR.Bit4Mode = 0;
    defparam Control_Reg_MOTOR.Bit5Mode = 0;
    defparam Control_Reg_MOTOR.Bit6Mode = 0;
    defparam Control_Reg_MOTOR.Bit7Mode = 0;
    defparam Control_Reg_MOTOR.BitValue = 0;
    defparam Control_Reg_MOTOR.BusDisplay = 0;
    defparam Control_Reg_MOTOR.ExtrReset = 0;
    defparam Control_Reg_MOTOR.NumOutputs = 1;

	wire [0:0] tmpOE__PAN_MOT_FL_net;
	wire [0:0] tmpIO_0__PAN_MOT_FL_net;
	wire [0:0] tmpINTERRUPT_0__PAN_MOT_FL_net;
	electrical [0:0] tmpSIOVREF__PAN_MOT_FL_net;

	cy_psoc3_pins_v1_10
		#(.id("5a38e5d2-a357-4855-911c-b52b5874fd3b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		PAN_MOT_FL
		 (.oe(tmpOE__PAN_MOT_FL_net),
		  .y({1'b0}),
		  .fb({Net_2265}),
		  .io({tmpIO_0__PAN_MOT_FL_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_MOT_FL_net),
		  .interrupt({tmpINTERRUPT_0__PAN_MOT_FL_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_MOT_FL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v3_0_4 PWM_MOTOR_PAN (
        .reset(Net_1149),
        .clock(Net_1314),
        .tc(Net_1150),
        .pwm1(Net_1103),
        .pwm2(Net_1352),
        .interrupt(Net_1151),
        .capture(1'b0),
        .kill(Net_1153),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_2206),
        .ph1(Net_2203),
        .ph2(Net_2204));
    defparam PWM_MOTOR_PAN.Resolution = 16;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1149));

	wire [0:0] tmpOE__PAN_MOT_IN1_net;
	wire [0:0] tmpFB_0__PAN_MOT_IN1_net;
	wire [0:0] tmpIO_0__PAN_MOT_IN1_net;
	wire [0:0] tmpINTERRUPT_0__PAN_MOT_IN1_net;
	electrical [0:0] tmpSIOVREF__PAN_MOT_IN1_net;

	cy_psoc3_pins_v1_10
		#(.id("b7dac4dc-21e8-49c0-902c-bf60c2f1af48"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		PAN_MOT_IN1
		 (.oe(tmpOE__PAN_MOT_IN1_net),
		  .y({Net_2206}),
		  .fb({tmpFB_0__PAN_MOT_IN1_net[0:0]}),
		  .io({tmpIO_0__PAN_MOT_IN1_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_MOT_IN1_net),
		  .interrupt({tmpINTERRUPT_0__PAN_MOT_IN1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_MOT_IN1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PAN_MOT_IN2_net;
	wire [0:0] tmpFB_0__PAN_MOT_IN2_net;
	wire [0:0] tmpIO_0__PAN_MOT_IN2_net;
	wire [0:0] tmpINTERRUPT_0__PAN_MOT_IN2_net;
	electrical [0:0] tmpSIOVREF__PAN_MOT_IN2_net;

	cy_psoc3_pins_v1_10
		#(.id("a33835fc-7964-4430-8251-a3c77976448c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		PAN_MOT_IN2
		 (.oe(tmpOE__PAN_MOT_IN2_net),
		  .y({Net_1105}),
		  .fb({tmpFB_0__PAN_MOT_IN2_net[0:0]}),
		  .io({tmpIO_0__PAN_MOT_IN2_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_MOT_IN2_net),
		  .interrupt({tmpINTERRUPT_0__PAN_MOT_IN2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_MOT_IN2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    QuadDec_v2_40_6 QuadDec_PAN (
        .quad_A(Net_1168),
        .quad_B(Net_1169),
        .index(1'b0),
        .clock(CLK_20MHz),
        .interrupt(Net_1171));
    defparam QuadDec_PAN.CounterResolution = 4;
    defparam QuadDec_PAN.UsingGlitchFiltering = 0;
    defparam QuadDec_PAN.UsingIndexInput = 0;

	wire [0:0] tmpOE__PAN_ENCA_net;
	wire [0:0] tmpIO_0__PAN_ENCA_net;
	wire [0:0] tmpINTERRUPT_0__PAN_ENCA_net;
	electrical [0:0] tmpSIOVREF__PAN_ENCA_net;

	cy_psoc3_pins_v1_10
		#(.id("3a05c507-5472-484c-b046-f8c3864f508a"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		PAN_ENCA
		 (.oe(tmpOE__PAN_ENCA_net),
		  .y({1'b0}),
		  .fb({Net_1168}),
		  .io({tmpIO_0__PAN_ENCA_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_ENCA_net),
		  .interrupt({tmpINTERRUPT_0__PAN_ENCA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_ENCA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PAN_ENCB_net;
	wire [0:0] tmpIO_0__PAN_ENCB_net;
	wire [0:0] tmpINTERRUPT_0__PAN_ENCB_net;
	electrical [0:0] tmpSIOVREF__PAN_ENCB_net;

	cy_psoc3_pins_v1_10
		#(.id("db4a77ba-74d9-4cd9-a623-ea74c1d68034"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		PAN_ENCB
		 (.oe(tmpOE__PAN_ENCB_net),
		  .y({1'b0}),
		  .fb({Net_1169}),
		  .io({tmpIO_0__PAN_ENCB_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_ENCB_net),
		  .interrupt({tmpINTERRUPT_0__PAN_ENCB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_ENCB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_2726 = 1'h0;

	wire [0:0] tmpOE__ITG_INT_net;
	wire [0:0] tmpIO_0__ITG_INT_net;
	wire [0:0] tmpINTERRUPT_0__ITG_INT_net;
	electrical [0:0] tmpSIOVREF__ITG_INT_net;

	cy_psoc3_pins_v1_10
		#(.id("5f659609-eb63-477c-809d-2552d9d04dbf"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		ITG_INT
		 (.oe(tmpOE__ITG_INT_net),
		  .y({1'b0}),
		  .fb({Net_2138}),
		  .io({tmpIO_0__ITG_INT_net[0:0]}),
		  .siovref(tmpSIOVREF__ITG_INT_net),
		  .interrupt({tmpINTERRUPT_0__ITG_INT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ITG_INT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyStatusReg_v1_80 Status_Reg_SYS (
        .status_0(Net_1251),
        .status_1(Net_1252),
        .status_2(Net_1253),
        .status_3(Net_2138),
        .clock(Net_1255),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_2374),
        .status_bus(8'b0));
    defparam Status_Reg_SYS.Bit0Mode = 0;
    defparam Status_Reg_SYS.Bit1Mode = 0;
    defparam Status_Reg_SYS.Bit2Mode = 0;
    defparam Status_Reg_SYS.Bit3Mode = 0;
    defparam Status_Reg_SYS.Bit4Mode = 0;
    defparam Status_Reg_SYS.Bit5Mode = 0;
    defparam Status_Reg_SYS.Bit6Mode = 0;
    defparam Status_Reg_SYS.Bit7Mode = 0;
    defparam Status_Reg_SYS.BusDisplay = 0;
    defparam Status_Reg_SYS.Interrupt = 0;
    defparam Status_Reg_SYS.MaskValue = 0;
    defparam Status_Reg_SYS.NumInputs = 4;

	wire [0:0] tmpOE__BAT_FAULTn_net;
	wire [0:0] tmpIO_0__BAT_FAULTn_net;
	wire [0:0] tmpINTERRUPT_0__BAT_FAULTn_net;
	electrical [0:0] tmpSIOVREF__BAT_FAULTn_net;

	cy_psoc3_pins_v1_10
		#(.id("33a62370-3e45-4b43-9e70-6cd0170c189e"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		BAT_FAULTn
		 (.oe(tmpOE__BAT_FAULTn_net),
		  .y({1'b0}),
		  .fb({Net_1251}),
		  .io({tmpIO_0__BAT_FAULTn_net[0:0]}),
		  .siovref(tmpSIOVREF__BAT_FAULTn_net),
		  .interrupt({tmpINTERRUPT_0__BAT_FAULTn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BAT_FAULTn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__BAT_CHRGn_net;
	wire [0:0] tmpIO_0__BAT_CHRGn_net;
	wire [0:0] tmpINTERRUPT_0__BAT_CHRGn_net;
	electrical [0:0] tmpSIOVREF__BAT_CHRGn_net;

	cy_psoc3_pins_v1_10
		#(.id("0a329f56-250e-4e20-8bb3-77e4f3b9be95"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		BAT_CHRGn
		 (.oe(tmpOE__BAT_CHRGn_net),
		  .y({1'b0}),
		  .fb({Net_1252}),
		  .io({tmpIO_0__BAT_CHRGn_net[0:0]}),
		  .siovref(tmpSIOVREF__BAT_CHRGn_net),
		  .interrupt({tmpINTERRUPT_0__BAT_CHRGn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BAT_CHRGn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("be7a34f5-60c6-4a6c-ab21-8cc17ddb114a"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_1314));


	wire [0:0] tmpOE__TILT_ENCA_net;
	wire [0:0] tmpIO_0__TILT_ENCA_net;
	wire [0:0] tmpINTERRUPT_0__TILT_ENCA_net;
	electrical [0:0] tmpSIOVREF__TILT_ENCA_net;

	cy_psoc3_pins_v1_10
		#(.id("e4847169-dc83-4b1b-a195-979f30f61fa7"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		TILT_ENCA
		 (.oe(tmpOE__TILT_ENCA_net),
		  .y({1'b0}),
		  .fb({Net_1782}),
		  .io({tmpIO_0__TILT_ENCA_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_ENCA_net),
		  .interrupt({tmpINTERRUPT_0__TILT_ENCA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_ENCA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		isr_BUTTON
		 (.int_signal(Net_1368));


    WaveDAC8_v2_0_9 WaveDAC8 (
        .Wave(Net_2353),
        .ws(Net_2643),
        .clock(1'b0),
        .wc1(Net_2645),
        .wc2(Net_2646));

    CyControlReg_v1_70 Control_Reg_WS (
        .control_1(Net_2816),
        .control_2(Net_2817),
        .control_3(Net_2819),
        .control_0(Net_2643),
        .control_4(Net_2821),
        .control_5(Net_2822),
        .control_6(Net_2823),
        .control_7(Net_2824),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_WS.Bit0Mode = 0;
    defparam Control_Reg_WS.Bit1Mode = 0;
    defparam Control_Reg_WS.Bit2Mode = 0;
    defparam Control_Reg_WS.Bit3Mode = 0;
    defparam Control_Reg_WS.Bit4Mode = 0;
    defparam Control_Reg_WS.Bit5Mode = 0;
    defparam Control_Reg_WS.Bit6Mode = 0;
    defparam Control_Reg_WS.Bit7Mode = 0;
    defparam Control_Reg_WS.BitValue = 0;
    defparam Control_Reg_WS.BusDisplay = 0;
    defparam Control_Reg_WS.ExtrReset = 0;
    defparam Control_Reg_WS.NumOutputs = 1;


	cy_clock_v1_0
		#(.id("a1481aa1-1fbc-4819-a33f-f92dd9f179c6"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_SYS
		 (.clock_out(CLK_100Hz));


    QuadDec_v2_40_11 QuadDec_TILT (
        .quad_A(Net_1782),
        .quad_B(Net_1783),
        .index(1'b0),
        .clock(CLK_20MHz),
        .interrupt(Net_1788));
    defparam QuadDec_TILT.CounterResolution = 4;
    defparam QuadDec_TILT.UsingGlitchFiltering = 1;
    defparam QuadDec_TILT.UsingIndexInput = 0;


	cy_clock_v1_0
		#(.id("da6d57a6-4d17-4e78-b04d-bc18691ad367"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("50000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_2
		 (.clock_out(CLK_20MHz));


    VDAC8_v1_90_12 VDAC8_ANAPOS (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_1463));
    defparam VDAC8_ANAPOS.Data_Source = 0;
    defparam VDAC8_ANAPOS.Initial_Value = 128;
    defparam VDAC8_ANAPOS.Strobe_Mode = 0;

    PGA_v2_0_13 PGA_ASTIM (
        .Vin(Net_2353),
        .Vref(VREF_sig),
        .Vout(Net_1386));

	wire [0:0] tmpOE__ASTIM_OUTPUT_net;
	wire [0:0] tmpFB_0__ASTIM_OUTPUT_net;
	wire [0:0] tmpIO_0__ASTIM_OUTPUT_net;
	wire [0:0] tmpINTERRUPT_0__ASTIM_OUTPUT_net;
	electrical [0:0] tmpSIOVREF__ASTIM_OUTPUT_net;

	cy_psoc3_pins_v1_10
		#(.id("45b0931c-d7a4-49b5-8bf5-e26d2044f8bb"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ASTIM_OUTPUT
		 (.oe(tmpOE__ASTIM_OUTPUT_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ASTIM_OUTPUT_net[0:0]}),
		  .analog({Net_1386}),
		  .io({tmpIO_0__ASTIM_OUTPUT_net[0:0]}),
		  .siovref(tmpSIOVREF__ASTIM_OUTPUT_net),
		  .interrupt({tmpINTERRUPT_0__ASTIM_OUTPUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ASTIM_OUTPUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DEBUG_LED_net;
	wire [0:0] tmpFB_0__DEBUG_LED_net;
	wire [0:0] tmpIO_0__DEBUG_LED_net;
	wire [0:0] tmpINTERRUPT_0__DEBUG_LED_net;
	electrical [0:0] tmpSIOVREF__DEBUG_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("ab582a80-b28e-4294-bed8-07d30ca3289d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		DEBUG_LED
		 (.oe(tmpOE__DEBUG_LED_net),
		  .y({Net_492}),
		  .fb({tmpFB_0__DEBUG_LED_net[0:0]}),
		  .io({tmpIO_0__DEBUG_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__DEBUG_LED_net),
		  .interrupt({tmpINTERRUPT_0__DEBUG_LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DEBUG_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_Ticks
		 (.int_signal(CLK_100Hz));


	wire [0:0] tmpOE__CC_SCL_net;
	wire [0:0] tmpFB_0__CC_SCL_net;
	wire [0:0] tmpINTERRUPT_0__CC_SCL_net;
	electrical [0:0] tmpSIOVREF__CC_SCL_net;

	cy_psoc3_pins_v1_10
		#(.id("48e26532-c6bf-45ff-bfea-929beed66bf5"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		CC_SCL
		 (.oe(tmpOE__CC_SCL_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__CC_SCL_net[0:0]}),
		  .io({Net_1726}),
		  .siovref(tmpSIOVREF__CC_SCL_net),
		  .interrupt({tmpINTERRUPT_0__CC_SCL_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CC_SCL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__CC_nALCC_net;
	wire [0:0] tmpIO_0__CC_nALCC_net;
	wire [0:0] tmpINTERRUPT_0__CC_nALCC_net;
	electrical [0:0] tmpSIOVREF__CC_nALCC_net;

	cy_psoc3_pins_v1_10
		#(.id("2b6af813-2074-43b2-97b2-1938a6e03fd4"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		CC_nALCC
		 (.oe(tmpOE__CC_nALCC_net),
		  .y({1'b0}),
		  .fb({Net_1253}),
		  .io({tmpIO_0__CC_nALCC_net[0:0]}),
		  .siovref(tmpSIOVREF__CC_nALCC_net),
		  .interrupt({tmpINTERRUPT_0__CC_nALCC_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CC_nALCC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__TILT_ENCB_net;
	wire [0:0] tmpIO_0__TILT_ENCB_net;
	wire [0:0] tmpINTERRUPT_0__TILT_ENCB_net;
	electrical [0:0] tmpSIOVREF__TILT_ENCB_net;

	cy_psoc3_pins_v1_10
		#(.id("a7df3e1e-69c7-44ea-b8f9-79fde383af7f"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		TILT_ENCB
		 (.oe(tmpOE__TILT_ENCB_net),
		  .y({1'b0}),
		  .fb({Net_1783}),
		  .io({tmpIO_0__TILT_ENCB_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_ENCB_net),
		  .interrupt({tmpINTERRUPT_0__TILT_ENCB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_ENCB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v3_0_14 PWM_MOTOR_TILT (
        .reset(Net_1789),
        .clock(Net_1790),
        .tc(Net_1805),
        .pwm1(Net_1806),
        .pwm2(Net_1807),
        .interrupt(Net_1808),
        .capture(1'b0),
        .kill(Net_1810),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_2199),
        .ph1(Net_1801),
        .ph2(Net_2237));
    defparam PWM_MOTOR_TILT.Resolution = 16;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1789));

	wire [0:0] tmpOE__TILT_MOT_IN1_net;
	wire [0:0] tmpFB_0__TILT_MOT_IN1_net;
	wire [0:0] tmpIO_0__TILT_MOT_IN1_net;
	wire [0:0] tmpINTERRUPT_0__TILT_MOT_IN1_net;
	electrical [0:0] tmpSIOVREF__TILT_MOT_IN1_net;

	cy_psoc3_pins_v1_10
		#(.id("efa35816-ed01-4320-a52e-fd845aaf0ea7"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		TILT_MOT_IN1
		 (.oe(tmpOE__TILT_MOT_IN1_net),
		  .y({Net_2199}),
		  .fb({tmpFB_0__TILT_MOT_IN1_net[0:0]}),
		  .io({tmpIO_0__TILT_MOT_IN1_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_MOT_IN1_net),
		  .interrupt({tmpINTERRUPT_0__TILT_MOT_IN1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_MOT_IN1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__TILT_MOT_IN2_net;
	wire [0:0] tmpFB_0__TILT_MOT_IN2_net;
	wire [0:0] tmpIO_0__TILT_MOT_IN2_net;
	wire [0:0] tmpINTERRUPT_0__TILT_MOT_IN2_net;
	electrical [0:0] tmpSIOVREF__TILT_MOT_IN2_net;

	cy_psoc3_pins_v1_10
		#(.id("3a681e77-ed1d-41ac-b9a2-8d4fcfa8f1b7"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		TILT_MOT_IN2
		 (.oe(tmpOE__TILT_MOT_IN2_net),
		  .y({Net_1802}),
		  .fb({tmpFB_0__TILT_MOT_IN2_net[0:0]}),
		  .io({tmpIO_0__TILT_MOT_IN2_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_MOT_IN2_net),
		  .interrupt({tmpINTERRUPT_0__TILT_MOT_IN2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_MOT_IN2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("2a21f85d-1bc2-4911-9fb8-047a8bb7a220"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_3
		 (.clock_out(Net_1790));



    assign Net_1802 = ~Net_2199;


    assign Net_1105 = ~Net_2206;

    assign Net_1810 = 1'h0;

    assign Net_1153 = 1'h0;

    // -- DFF Start --
    reg  cydff_2;
    always @(posedge Net_2472)
    begin
        cydff_2 <= Net_2239;
    end
    assign Net_2324 = cydff_2;
    // -- DFF End --


    assign Net_2239 = ~Net_2324;

    CyStatusReg_v1_80 Status_Reg_MOTORS (
        .status_0(Net_2265),
        .status_1(Net_2266),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_2269),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_2274),
        .status_bus(8'b0));
    defparam Status_Reg_MOTORS.Bit0Mode = 0;
    defparam Status_Reg_MOTORS.Bit1Mode = 0;
    defparam Status_Reg_MOTORS.Bit2Mode = 0;
    defparam Status_Reg_MOTORS.Bit3Mode = 0;
    defparam Status_Reg_MOTORS.Bit4Mode = 0;
    defparam Status_Reg_MOTORS.Bit5Mode = 0;
    defparam Status_Reg_MOTORS.Bit6Mode = 0;
    defparam Status_Reg_MOTORS.Bit7Mode = 0;
    defparam Status_Reg_MOTORS.BusDisplay = 0;
    defparam Status_Reg_MOTORS.Interrupt = 0;
    defparam Status_Reg_MOTORS.MaskValue = 0;
    defparam Status_Reg_MOTORS.NumInputs = 2;


	cy_clock_v1_0
		#(.id("009ab3d0-80ae-4232-a552-83312ea6af5c"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_4
		 (.clock_out(Net_2269));



	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_EVENTS_IDENTIF
		 (.int_signal(CLK_100Hz));


    ZeroTerminal ZeroTerminal_6 (
        .z(Net_2482));

	wire [0:0] tmpOE__LORA_RX_net;
	wire [0:0] tmpIO_0__LORA_RX_net;
	wire [0:0] tmpINTERRUPT_0__LORA_RX_net;
	electrical [0:0] tmpSIOVREF__LORA_RX_net;

	cy_psoc3_pins_v1_10
		#(.id("85a763ee-eec0-4962-9c60-ea7a255f05c0"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		LORA_RX
		 (.oe(tmpOE__LORA_RX_net),
		  .y({1'b0}),
		  .fb({Net_2487}),
		  .io({tmpIO_0__LORA_RX_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_RX_net),
		  .interrupt({tmpINTERRUPT_0__LORA_RX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_RX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LORA_TX_net;
	wire [0:0] tmpFB_0__LORA_TX_net;
	wire [0:0] tmpIO_0__LORA_TX_net;
	wire [0:0] tmpINTERRUPT_0__LORA_TX_net;
	electrical [0:0] tmpSIOVREF__LORA_TX_net;

	cy_psoc3_pins_v1_10
		#(.id("7e507874-0336-41f6-b62c-304f5d80055a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LORA_TX
		 (.oe(tmpOE__LORA_TX_net),
		  .y({Net_2482}),
		  .fb({tmpFB_0__LORA_TX_net[0:0]}),
		  .io({tmpIO_0__LORA_TX_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_TX_net),
		  .interrupt({tmpINTERRUPT_0__LORA_TX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_TX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__HOME_TILT_net;
	wire [0:0] tmpFB_0__HOME_TILT_net;
	wire [0:0] tmpIO_0__HOME_TILT_net;
	wire [0:0] tmpINTERRUPT_0__HOME_TILT_net;
	electrical [0:0] tmpSIOVREF__HOME_TILT_net;

	cy_psoc3_pins_v1_10
		#(.id("642e8355-88c2-4785-b15a-42a32f9a7bd6"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		HOME_TILT
		 (.oe(tmpOE__HOME_TILT_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__HOME_TILT_net[0:0]}),
		  .analog({HOME_TILT_ABSV}),
		  .io({tmpIO_0__HOME_TILT_net[0:0]}),
		  .siovref(tmpSIOVREF__HOME_TILT_net),
		  .interrupt({tmpINTERRUPT_0__HOME_TILT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__HOME_TILT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_CLU_EXEC
		 (.int_signal(CLK_100Hz));


	wire [0:0] tmpOE__OLED_4D_RX_net;
	wire [0:0] tmpFB_0__OLED_4D_RX_net;
	wire [0:0] tmpIO_0__OLED_4D_RX_net;
	wire [0:0] tmpINTERRUPT_0__OLED_4D_RX_net;
	electrical [0:0] tmpSIOVREF__OLED_4D_RX_net;

	cy_psoc3_pins_v1_10
		#(.id("3639e5ac-cecd-42ff-bcaa-12620bb047f4"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		OLED_4D_RX
		 (.oe(tmpOE__OLED_4D_RX_net),
		  .y({Net_2726}),
		  .fb({tmpFB_0__OLED_4D_RX_net[0:0]}),
		  .io({tmpIO_0__OLED_4D_RX_net[0:0]}),
		  .siovref(tmpSIOVREF__OLED_4D_RX_net),
		  .interrupt({tmpINTERRUPT_0__OLED_4D_RX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__OLED_4D_RX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__OLED_4D_TX_net;
	wire [0:0] tmpIO_0__OLED_4D_TX_net;
	wire [0:0] tmpINTERRUPT_0__OLED_4D_TX_net;
	electrical [0:0] tmpSIOVREF__OLED_4D_TX_net;

	cy_psoc3_pins_v1_10
		#(.id("04b8d679-6a5e-4da3-bb54-e95ceffd8230"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		OLED_4D_TX
		 (.oe(tmpOE__OLED_4D_TX_net),
		  .y({1'b0}),
		  .fb({Net_2530}),
		  .io({tmpIO_0__OLED_4D_TX_net[0:0]}),
		  .siovref(tmpSIOVREF__OLED_4D_TX_net),
		  .interrupt({tmpINTERRUPT_0__OLED_4D_TX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__OLED_4D_TX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_70 Control_Reg_LORA (
        .control_1(Net_2760),
        .control_2(Net_2752),
        .control_3(Net_2753),
        .control_0(Net_2701),
        .control_4(Net_2754),
        .control_5(Net_2755),
        .control_6(Net_2756),
        .control_7(Net_2757),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_LORA.Bit0Mode = 0;
    defparam Control_Reg_LORA.Bit1Mode = 0;
    defparam Control_Reg_LORA.Bit2Mode = 0;
    defparam Control_Reg_LORA.Bit3Mode = 0;
    defparam Control_Reg_LORA.Bit4Mode = 0;
    defparam Control_Reg_LORA.Bit5Mode = 0;
    defparam Control_Reg_LORA.Bit6Mode = 0;
    defparam Control_Reg_LORA.Bit7Mode = 0;
    defparam Control_Reg_LORA.BitValue = 0;
    defparam Control_Reg_LORA.BusDisplay = 0;
    defparam Control_Reg_LORA.ExtrReset = 0;
    defparam Control_Reg_LORA.NumOutputs = 1;

	wire [0:0] tmpOE__LORA_CTSn_net;
	wire [0:0] tmpIO_0__LORA_CTSn_net;
	wire [0:0] tmpINTERRUPT_0__LORA_CTSn_net;
	electrical [0:0] tmpSIOVREF__LORA_CTSn_net;

	cy_psoc3_pins_v1_10
		#(.id("34a8b019-417d-4531-9fe8-bd1a2ee191c2"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b01),
		  .width(1))
		LORA_CTSn
		 (.oe(tmpOE__LORA_CTSn_net),
		  .y({1'b0}),
		  .fb({Net_2514}),
		  .io({tmpIO_0__LORA_CTSn_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_CTSn_net),
		  .interrupt({tmpINTERRUPT_0__LORA_CTSn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_CTSn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LORA_RTSn_net;
	wire [0:0] tmpFB_0__LORA_RTSn_net;
	wire [0:0] tmpIO_0__LORA_RTSn_net;
	wire [0:0] tmpINTERRUPT_0__LORA_RTSn_net;
	electrical [0:0] tmpSIOVREF__LORA_RTSn_net;

	cy_psoc3_pins_v1_10
		#(.id("05c90d7a-4a83-498d-a37b-6271834b110d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LORA_RTSn
		 (.oe(tmpOE__LORA_RTSn_net),
		  .y({Net_2839}),
		  .fb({tmpFB_0__LORA_RTSn_net[0:0]}),
		  .io({tmpIO_0__LORA_RTSn_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_RTSn_net),
		  .interrupt({tmpINTERRUPT_0__LORA_RTSn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_RTSn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_2795 = 1'h0;

	wire [0:0] tmpOE__IMU_UM7_RX_net;
	wire [0:0] tmpFB_0__IMU_UM7_RX_net;
	wire [0:0] tmpIO_0__IMU_UM7_RX_net;
	wire [0:0] tmpINTERRUPT_0__IMU_UM7_RX_net;
	electrical [0:0] tmpSIOVREF__IMU_UM7_RX_net;

	cy_psoc3_pins_v1_10
		#(.id("17330419-c534-4d80-ad88-64c02684dc79"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		IMU_UM7_RX
		 (.oe(tmpOE__IMU_UM7_RX_net),
		  .y({Net_2795}),
		  .fb({tmpFB_0__IMU_UM7_RX_net[0:0]}),
		  .io({tmpIO_0__IMU_UM7_RX_net[0:0]}),
		  .siovref(tmpSIOVREF__IMU_UM7_RX_net),
		  .interrupt({tmpINTERRUPT_0__IMU_UM7_RX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__IMU_UM7_RX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__IMU_UM7_TX_net;
	wire [0:0] tmpIO_0__IMU_UM7_TX_net;
	wire [0:0] tmpINTERRUPT_0__IMU_UM7_TX_net;
	electrical [0:0] tmpSIOVREF__IMU_UM7_TX_net;

	cy_psoc3_pins_v1_10
		#(.id("d139b22b-91c5-436b-b6c0-2a6a4792d560"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1))
		IMU_UM7_TX
		 (.oe(tmpOE__IMU_UM7_TX_net),
		  .y({1'b0}),
		  .fb({Net_2794}),
		  .io({tmpIO_0__IMU_UM7_TX_net[0:0]}),
		  .siovref(tmpSIOVREF__IMU_UM7_TX_net),
		  .interrupt({tmpINTERRUPT_0__IMU_UM7_TX_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__IMU_UM7_TX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LORA_RESET_SETB_net;
	wire [0:0] tmpFB_0__LORA_RESET_SETB_net;
	wire [0:0] tmpIO_0__LORA_RESET_SETB_net;
	wire [0:0] tmpINTERRUPT_0__LORA_RESET_SETB_net;
	electrical [0:0] tmpSIOVREF__LORA_RESET_SETB_net;

	cy_psoc3_pins_v1_10
		#(.id("9af850f6-65cd-416c-882e-0818e3231893"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		LORA_RESET_SETB
		 (.oe(tmpOE__LORA_RESET_SETB_net),
		  .y({Net_2698}),
		  .fb({tmpFB_0__LORA_RESET_SETB_net[0:0]}),
		  .io({tmpIO_0__LORA_RESET_SETB_net[0:0]}),
		  .siovref(tmpSIOVREF__LORA_RESET_SETB_net),
		  .interrupt({tmpINTERRUPT_0__LORA_RESET_SETB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LORA_RESET_SETB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ITG_CS_NEW_net;
	wire [0:0] tmpFB_0__ITG_CS_NEW_net;
	wire [0:0] tmpIO_0__ITG_CS_NEW_net;
	wire [0:0] tmpINTERRUPT_0__ITG_CS_NEW_net;
	electrical [0:0] tmpSIOVREF__ITG_CS_NEW_net;

	cy_psoc3_pins_v1_10
		#(.id("80deeed4-537a-411d-8e12-9d1a4da4ba1d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1))
		ITG_CS_NEW
		 (.oe(tmpOE__ITG_CS_NEW_net),
		  .y({Net_2751}),
		  .fb({tmpFB_0__ITG_CS_NEW_net[0:0]}),
		  .io({tmpIO_0__ITG_CS_NEW_net[0:0]}),
		  .siovref(tmpSIOVREF__ITG_CS_NEW_net),
		  .interrupt({tmpINTERRUPT_0__ITG_CS_NEW_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ITG_CS_NEW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_2751 = 1'h1;

    CyControlReg_v1_70 Control_Reg_LORA_RESET (
        .control_1(Net_2770),
        .control_2(Net_2771),
        .control_3(Net_2772),
        .control_0(Net_2698),
        .control_4(Net_2773),
        .control_5(Net_2774),
        .control_6(Net_2775),
        .control_7(Net_2776),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_LORA_RESET.Bit0Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit1Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit2Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit3Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit4Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit5Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit6Mode = 0;
    defparam Control_Reg_LORA_RESET.Bit7Mode = 0;
    defparam Control_Reg_LORA_RESET.BitValue = 0;
    defparam Control_Reg_LORA_RESET.BusDisplay = 0;
    defparam Control_Reg_LORA_RESET.ExtrReset = 0;
    defparam Control_Reg_LORA_RESET.NumOutputs = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_TORQUESTAT
		 (.int_signal(Net_2785));


    FreqDiv_v1_0 FreqDiv_TORQUESTAT (
        .en(Net_2788),
        .div(Net_2785),
        .reset(Net_2789),
        .clock(CLK_100Hz));
    defparam FreqDiv_TORQUESTAT.Divider = 32;
    defparam FreqDiv_TORQUESTAT.highPulse = 16;
    defparam FreqDiv_TORQUESTAT.numBits = 5;

    assign Net_2788 = 1'h1;

    assign Net_2789 = 1'h0;


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_LIMIT_CTRL
		 (.int_signal(CLK_100Hz));



	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_FAULT_CTRL
		 (.int_signal(CLK_25Hz));


    assign Net_2839 = 1'h1;

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge CLK_100Hz)
    begin
        cydff_1 <= Net_2829;
    end
    assign Net_2830 = cydff_1;
    // -- DFF End --


    assign Net_2829 = ~Net_2830;

    // -- DFF Start --
    reg  cydff_4;
    always @(posedge Net_2830)
    begin
        cydff_4 <= Net_2832;
    end
    assign CLK_25Hz = cydff_4;
    // -- DFF End --


    assign Net_2832 = ~CLK_25Hz;



endmodule

