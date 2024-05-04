// ======================================================================
// GyroSens-00.v generated from TopDesign.cysch
// 12/17/2012 at 10:53
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PANTHER 2
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 1
`define CYDEV_CHIP_REV_EXPECT 3
`define CYDEV_CHIP_DIE_ACTUAL 1
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC5 2
`define CYDEV_CHIP_MEMBER_5A 2
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 1
`define CYDEV_CHIP_MEMBER_USED 1
`define CYDEV_CHIP_REVISION_USED 3
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: B_SPI_Master_v2_21
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibraryupdates\CyComponentLibraryUpdates.cylib\B_SPI_Master_v2_21"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibraryupdates\CyComponentLibraryUpdates.cylib\B_SPI_Master_v2_21\B_SPI_Master_v2_21.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibraryupdates\CyComponentLibraryUpdates.cylib\B_SPI_Master_v2_21"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibraryupdates\CyComponentLibraryUpdates.cylib\B_SPI_Master_v2_21\B_SPI_Master_v2_21.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// SPI_Master_v2_21(BidirectMode=false, ClockInternal=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DesiredBitRate=1000000, HighSpeedMode=false, InternalClockUsed=0, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=false, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=false, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=0, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=0, IntOnTXNotFull=0, Mode=1, ModeUseZero=1, NumberOfDataBits=16, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, RxBufferSize=4, ShiftDir=0, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR16, CY_COMPONENT_NAME=SPI_Master_v2_21, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=SPIM_EASYCAMS, CY_INSTANCE_SHORT_NAME=SPIM_EASYCAMS, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=21, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=SPIM_EASYCAMS, )
module SPI_Master_v2_21_0 (clock, reset, miso, sclk, mosi, ss, rx_interrupt, sdat, tx_interrupt);
    input   clock;
    input   reset;
    input   miso;
    output  sclk;
    output  mosi;
    output  ss;
    output  rx_interrupt;
    inout   sdat;
    output  tx_interrupt;

    parameter BidirectMode = 0;
    parameter HighSpeedMode = 0;
    parameter NumberOfDataBits = 16;
    parameter ShiftDir = 0;

    wire  Net_257;
    wire  Net_273;
    wire  Net_274;
    wire  Net_244;
    wire  Net_239;
    wire  Net_253;
    wire  Net_161;
    wire  Net_276;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_276 = clock;

    B_SPI_Master_v2_21 BSPIM (
        .sclk(sclk),
        .ss(ss),
        .miso(Net_244),
        .clock(Net_276),
        .reset(Net_273),
        .rx_interpt(rx_interrupt),
        .tx_enable(Net_253),
        .mosi(mosi),
        .tx_interpt(tx_interrupt));
    defparam BSPIM.BidirectMode = 0;
    defparam BSPIM.HighSpeedMode = 0;
    defparam BSPIM.ModeCPHA = 0;
    defparam BSPIM.ModePOL = 0;
    defparam BSPIM.NumberOfDataBits = 16;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = reset;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_274));



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// ADC_DelSig_v2_20(ADC_Charge_Pump_Clock=false, ADC_Clock=1, ADC_CLOCK_FREQUENCY=208000, ADC_Input_Mode=0, ADC_Input_Range=5, ADC_Input_Range_Config2=4, ADC_Input_Range_Config3=4, ADC_Input_Range_Config4=4, ADC_Power=1, ADC_Reference=5, ADC_Reference_Config2=0, ADC_Reference_Config3=0, ADC_Reference_Config4=0, ADC_Resolution=12, ADC_Resolution_Config2=16, ADC_Resolution_Config3=16, ADC_Resolution_Config4=16, Clock_Frequency=64000, Comment_Config1=Default Config, Comment_Config2=Second Config, Comment_Config3=Third Config, Comment_Config4=Fourth Config, Config1_Name=CFG1, Config2_Name=CFG2, Config3_Name=CFG3, Config4_Name=CFG4, Configs=1, Conversion_Mode=2, Conversion_Mode_Config2=2, Conversion_Mode_Config3=2, Conversion_Mode_Config4=2, Debug=false, DsmName=DSM4, Enable_Vref_Vss=false, Input_Buffer_Gain=1, Input_Buffer_Gain_Config2=1, Input_Buffer_Gain_Config3=1, Input_Buffer_Gain_Config4=1, Input_Buffer_Mode=1, Input_Buffer_Mode_Config2=1, Input_Buffer_Mode_Config3=1, Input_Buffer_Mode_Config4=1, Ref_Voltage=1.25, Ref_Voltage_Config2=1.024, Ref_Voltage_Config3=1.024, Ref_Voltage_Config4=1.024, Sample_Rate=6500, Sample_Rate_Config2=10000, Sample_Rate_Config3=10000, Sample_Rate_Config4=10000, Start_of_Conversion=0, Vdda_Value=5, CY_COMPONENT_NAME=ADC_DelSig_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=ADC, CY_INSTANCE_SHORT_NAME=ADC, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=ADC, )
module ADC_DelSig_v2_20_1 (vplus, vminus, soc, eoc, aclk, nVref);
    inout   vplus;
    electrical   vplus;
    inout   vminus;
    electrical   vminus;
    input   soc;
    output  eoc;
    input   aclk;
    inout   nVref;
    electrical   nVref;


    wire  aclock;
    wire [3:0] mod_dat;
    wire  mod_reset;
    wire  Net_370;
    electrical  Net_333;
    electrical  Net_348;
    wire  Net_372;
    wire [7:0] Net_436;
    wire  Net_437;
    wire  Net_485;
    wire  Net_486;
    wire [7:0] Net_621;
    wire  Net_622;
    electrical  Net_680;
    electrical  Net_682;
    electrical  Net_687;
    electrical  Net_690;
    electrical  Net_686;
    electrical  Net_681;
    electrical  Net_677;
    electrical  Net_570;
    electrical  Net_573;
    electrical  Net_580;
    wire  Net_488;
    wire  Net_487;
    wire  Net_482;
    wire  Net_481;
    wire  Net_478;
    wire  Net_438;
    wire [3:0] Net_471;
    wire [3:0] Net_470;
    electrical  Net_352;
    electrical  Net_349;
    electrical  Net_257;
    electrical  Net_520;
    wire  Net_40;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_349));


	cy_clock_v1_0
		#(.id("d4ba298c-68cb-4b7e-b9e7-f0a3d2bfafb6/b7604721-db56-4477-98c2-8fae77869066"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("1000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Ext_CP_Clk
		 (.clock_out(Net_487));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_257));

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_573, Net_257);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_580, Net_349);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_520, vminus);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


	// Clock_VirtualMux (cy_virtualmux_v1_0)
	assign Net_488 = Net_40;


	cy_clock_v1_0
		#(.id("d4ba298c-68cb-4b7e-b9e7-f0a3d2bfafb6/edd15f43-b66b-457b-be3a-5342345270c8"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("4807692307.69231"),
		  .is_direct(0),
		  .is_digital(0))
		theACLK
		 (.clock_out(Net_40));


    ZeroTerminal ZeroTerminal_2 (
        .z(Net_482));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_481));

    cy_psoc3_decimator_v1_0 DEC (
        .aclock(aclock),
        .mod_dat(mod_dat[3:0]),
        .ext_start(soc),
        .mod_reset(mod_reset),
        .interrupt(eoc));

	// cy_analog_virtualmux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_5_connect(Net_570, Net_352);
	defparam cy_analog_virtualmux_5_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_352));

    cy_psoc3_ds_mod_v4_0 DSM4 (
        .vplus(vplus),
        .vminus(Net_520),
        .modbit(Net_485),
        .reset_udb(Net_486),
        .aclock(Net_488),
        .mod_dat(Net_471[3:0]),
        .dout_udb(Net_621[7:0]),
        .reset_dec(mod_reset),
        .dec_clock(Net_478),
        .extclk_cp_udb(Net_487),
        .clk_udb(1'b0),
        .ext_pin_1(Net_580),
        .ext_pin_2(Net_573),
        .ext_vssa(Net_570),
        .qtz_ref(Net_677));
    defparam DSM4.resolution = 12;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_485));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_486));

	// Clock_VirtualMux_2 (cy_virtualmux_v1_0)
	assign mod_dat[3:0] = Net_471[3:0];

	// Clock_VirtualMux_3 (cy_virtualmux_v1_0)
	assign aclock = Net_478;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_680));

	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_677, Net_680);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

	// cy_analog_virtualmux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_6_connect(Net_690, Net_687);
	defparam cy_analog_virtualmux_6_connect.sig_width = 1;



endmodule

// Component: B_UART_v2_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_10"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_10\B_UART_v2_10.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_10"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_10\B_UART_v2_10.v"
`endif

// UART_v2_10(Address1=0, Address2=0, BaudRate=57600, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, CtrlModeReplacementString=SyncCtl, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=true, InternalClock=true, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=460800, RXAddressMode=0, RXBufferSize=1, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=1, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_COMPONENT_NAME=UART_v2_10, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=UART_USB, CY_INSTANCE_SHORT_NAME=UART_USB, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=UART_USB, )
module UART_v2_10_2 (rx_clk, rx_data, tx_clk, tx_data, rx_interrupt, tx_interrupt, tx, tx_en, rts_n, reset, cts_n, clock, rx);
    output  rx_clk;
    output  rx_data;
    output  tx_clk;
    output  tx_data;
    output  rx_interrupt;
    output  tx_interrupt;
    output  tx;
    output  tx_en;
    output  rts_n;
    input   reset;
    input   cts_n;
    input   clock;
    input   rx;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 1;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

    wire  Net_289;
    wire  Net_9;
    wire  Net_61;


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

    B_UART_v2_10 BUART (
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
    defparam BUART.HwTXEnSignal = 1;
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
    defparam BUART.Use23Polling = 1;



endmodule

// SPI_Master_v2_21(BidirectMode=false, ClockInternal=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DesiredBitRate=1000000, HighSpeedMode=false, InternalClockUsed=0, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=false, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=false, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=0, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=0, IntOnTXNotFull=0, Mode=1, ModeUseZero=1, NumberOfDataBits=16, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, RxBufferSize=4, ShiftDir=0, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR16, CY_COMPONENT_NAME=SPI_Master_v2_21, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=SPIM_ADXRS, CY_INSTANCE_SHORT_NAME=SPIM_ADXRS, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=21, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=SPIM_ADXRS, )
module SPI_Master_v2_21_3 (clock, reset, miso, sclk, mosi, ss, rx_interrupt, sdat, tx_interrupt);
    input   clock;
    input   reset;
    input   miso;
    output  sclk;
    output  mosi;
    output  ss;
    output  rx_interrupt;
    inout   sdat;
    output  tx_interrupt;

    parameter BidirectMode = 0;
    parameter HighSpeedMode = 0;
    parameter NumberOfDataBits = 16;
    parameter ShiftDir = 0;

    wire  Net_257;
    wire  Net_273;
    wire  Net_274;
    wire  Net_244;
    wire  Net_239;
    wire  Net_253;
    wire  Net_161;
    wire  Net_276;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_276 = clock;

    B_SPI_Master_v2_21 BSPIM (
        .sclk(sclk),
        .ss(ss),
        .miso(Net_244),
        .clock(Net_276),
        .reset(Net_273),
        .rx_interpt(rx_interrupt),
        .tx_enable(Net_253),
        .mosi(mosi),
        .tx_interpt(tx_interrupt));
    defparam BSPIM.BidirectMode = 0;
    defparam BSPIM.HighSpeedMode = 0;
    defparam BSPIM.ModeCPHA = 0;
    defparam BSPIM.ModePOL = 0;
    defparam BSPIM.NumberOfDataBits = 16;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = reset;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_274));



endmodule

// VDAC8_v1_70(Data_Source=0, Initial_Value=100, Strobe_Mode=0, UseWorkaround=false, VDAC_Range=4, VDAC_Speed=2, Voltage=1600, CY_COMPONENT_NAME=VDAC8_v1_70, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=VDAC8_GYRO, CY_INSTANCE_SHORT_NAME=VDAC8_GYRO, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=70, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=VDAC8_GYRO, )
module VDAC8_v1_70_4 (strobe, data, vOut);
    input   strobe;
    input  [7:0] data;
    inout   vOut;
    electrical   vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 100;
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

// Component: CyControlReg_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_60"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_60\CyControlReg_v1_60.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_60"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_60\CyControlReg_v1_60.v"
`endif

// Component: AMuxSeq_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_50\AMuxSeq_v1_50.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_50"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxSeq_v1_50\AMuxSeq_v1_50.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: B_Counter_v2_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_0"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_0\B_Counter_v2_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_0\B_Counter_v2_0.v"
`endif

// Counter_v2_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=1, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=32768, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=32768, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=32768, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_COMPONENT_NAME=Counter_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Cnt16, CY_INSTANCE_SHORT_NAME=Cnt16, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec_Cnt16, )
module Counter_v2_0_5 (clock, comp, tc, reset, interrupt, enable, capture, upCnt, downCnt, up_ndown, count);
    input   clock;
    output  comp;
    output  tc;
    input   reset;
    output  interrupt;
    input   enable;
    input   capture;
    input   upCnt;
    input   downCnt;
    input   up_ndown;
    input   count;

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

    wire  Net_54;
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

    B_Counter_v2_0 CounterUDB (
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

// Component: bQuadDec_v2_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_0"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_0\bQuadDec_v2_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v2_0\bQuadDec_v2_0.v"
`endif

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// QuadDec_v2_0(Counter8bit=false, CounterResolution=1, CounterSize=16, CounterSizeReplacementString=int16, CounterSizeReplacementStringUnsigned=uint16, UsingGlitchFiltering=true, UsingIndexInput=false, CY_COMPONENT_NAME=QuadDec_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=QuadDec, CY_INSTANCE_SHORT_NAME=QuadDec, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=QuadDec, )
module QuadDec_v2_0_6 (quad_A, quad_B, index, clock, interrupt);
    input   quad_A;
    input   quad_B;
    input   index;
    input   clock;
    output  interrupt;

    parameter CounterResolution = 1;
    parameter UsingGlitchFiltering = 1;
    parameter UsingIndexInput = 0;

    wire  Net_1127;
    wire  Net_1129;
    wire  Net_1243;
    wire  Net_1130;
    wire  Net_1131;
    wire  Net_1132;
    wire  Net_1121;
    wire  Net_1123;
    wire  Net_1241;
    wire  Net_1124;
    wire  Net_1125;
    wire  Net_1126;
    wire  Net_1203;
    wire  Net_1260;
    wire  Net_1232;
    wire  Net_1229;
    wire  Net_1251;
    wire  Net_283;
    wire  Net_1210;
    wire  Net_611;
    wire  Net_1151;
    wire  Net_1248;
    wire  Net_530;

    Counter_v2_0_5 Cnt16 (
        .reset(Net_1260),
        .tc(Net_1210),
        .comp(Net_1127),
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
	assign Net_1248 = Net_1210;

    bQuadDec_v2_0 bQuadDec (
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
    defparam bQuadDec.CounterResolution = 1;
    defparam bQuadDec.UsingGlitchFiltering = 1;
    defparam bQuadDec.UsingIndexInput = 0;


    assign Net_1151 = ~Net_1251;


    assign Net_530 = Net_1251 & Net_1248;


    assign Net_611 = Net_1151 & Net_1248;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1232 = Net_1229;

    OneTerminal OneTerminal_1 (
        .o(Net_1229));



endmodule

// IDAC8_v1_80(Current=1024, Data_Source=0, Hardware_Enable=false, IDAC_Range=8, IDAC_Speed=2, Initial_Value=128, Polarity=0, Strobe_Mode=0, UseWorkaround=false, CY_COMPONENT_NAME=IDAC8_v1_80, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=IDAC8_ANGLE, CY_INSTANCE_SHORT_NAME=IDAC8_ANGLE, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=80, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=IDAC8_ANGLE, )
module IDAC8_v1_80_7 (iOut, data, strobe, en, ipolarity);
    inout   iOut;
    electrical   iOut;
    input  [7:0] data;
    input   strobe;
    input   en;
    input   ipolarity;

    parameter Data_Source = 0;
    parameter Initial_Value = 128;
    parameter Strobe_Mode = 0;

    electrical  Net_124;
    wire  Net_194;
    wire  Net_195;
    wire  Net_158;
    wire  Net_157;
    wire  Net_123;
    wire  Net_125;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_125),
        .idir(Net_158),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(Net_124),
        .iout(iOut),
        .ioff(Net_123),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;


    assign Net_157 = ~en;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_125));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_124));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_123 = Net_194;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_158 = Net_195;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_194));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_195));



endmodule

// IDAC8_v1_80(Current=0, Data_Source=0, Hardware_Enable=false, IDAC_Range=8, IDAC_Speed=0, Initial_Value=0, Polarity=0, Strobe_Mode=0, UseWorkaround=false, CY_COMPONENT_NAME=IDAC8_v1_80, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=IDAC8_ANGLE_OFFSET, CY_INSTANCE_SHORT_NAME=IDAC8_ANGLE_OFFSET, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=80, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=IDAC8_ANGLE_OFFSET, )
module IDAC8_v1_80_8 (iOut, data, strobe, en, ipolarity);
    inout   iOut;
    electrical   iOut;
    input  [7:0] data;
    input   strobe;
    input   en;
    input   ipolarity;

    parameter Data_Source = 0;
    parameter Initial_Value = 0;
    parameter Strobe_Mode = 0;

    wire  Net_195;
    wire  Net_194;
    electrical  Net_124;
    wire  Net_158;
    wire  Net_157;
    wire  Net_123;
    wire  Net_125;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_125),
        .idir(Net_158),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(Net_124),
        .iout(iOut),
        .ioff(Net_123),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;


    assign Net_157 = ~en;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_125));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_124));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_123 = Net_194;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_158 = Net_195;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_194));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_195));



endmodule

// Counter_v2_10(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=10, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=10, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_COMPONENT_NAME=Counter_v2_10, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Counter_LED, CY_INSTANCE_SHORT_NAME=Counter_LED, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Counter_LED, )
module Counter_v2_10_9 (clock, comp, tc, reset, interrupt, enable, capture, upCnt, downCnt, up_ndown, count);
    input   clock;
    output  comp;
    output  tc;
    input   reset;
    output  interrupt;
    input   enable;
    input   capture;
    input   upCnt;
    input   downCnt;
    input   up_ndown;
    input   count;

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

    wire  Net_54;
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
        .compare(Net_54),
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

// Component: cydff_v1_20
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_20"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_20\cydff_v1_20.v"
`else
`define CY_BLK_DIR "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_20"
`include "C:\Programmi\Cypress\PSoC Creator\2.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_20\cydff_v1_20.v"
`endif

// top
module top ;

    wire  CLK_150Hz;
    wire  Net_333;
    wire  Net_332;
    wire  Net_331;
    wire  Net_330;
    wire  Net_342;
    wire  Net_341;
    wire  Net_340;
    wire  Net_339;
    wire  Net_338;
    wire  Net_337;
    wire  Net_336;
    wire  Net_335;
    wire  Net_334;
    wire  Net_473;
    wire  Net_393;
    wire  Net_401;
    wire  Net_400;
    wire [7:0] Net_399;
    wire  Net_398;
    wire  Net_397;
    wire  Net_396;
    wire [7:0] Net_395;
    wire  Net_394;
    wire  Net_392;
    wire  Net_355;
    wire  Net_354;
    wire  Net_403;
    wire  Net_391;
    wire  Net_404;
    wire  Net_434;
    wire  Net_433;
    wire  Net_432;
    wire  Net_431;
    wire  Net_430;
    wire  Net_429;
    wire  Net_428;
    wire  Net_427;
    wire  Net_426;
    wire [7:0] Net_415;
    wire  Net_414;
    wire  Net_462;
    wire  Net_461;
    wire  Net_460;
    wire  Net_447;
    wire  Net_440;
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
    wire  Net_375;
    wire  Net_377;
    electrical  Net_390;
    wire  Net_389;
    wire  Net_388;
    wire  Net_387;
    wire  Net_476;
    wire  Net_475;
    wire  Net_474;
    wire  Net_468;
    wire  Net_465;
    wire  Net_464;
    wire  Net_463;
    wire  Net_466;
    wire  Net_467;
    wire  Net_459;
    wire  Net_457;
    wire  Net_456;
    wire  Net_451;
    wire  Net_439;
    wire  Net_492;
    wire  Net_204;
    wire  Net_294;
    wire  Net_295;
    wire  Net_402;
    wire  Net_663;
    wire  Net_659;
    wire  Net_502;
    electrical  Net_216;
    electrical  Net_188;
    electrical  Net_181;
    wire  Net_424;
    electrical  Net_61;
    electrical  Net_50;
    electrical  Net_44;
    electrical  Net_43;
    electrical  Net_42;
    electrical  Net_41;
    electrical  Net_40;
    electrical  Net_39;
    electrical  Net_7;

	wire [0:0] tmpOE__ADXRS_RATE_net;
	wire [0:0] tmpFB_0__ADXRS_RATE_net;
	wire [0:0] tmpIO_0__ADXRS_RATE_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_RATE_net;
	electrical [0:0] tmpSIOVREF__ADXRS_RATE_net;

	cy_psoc3_pins_v1_10
		#(.id("cc3bcd7e-5dc0-48ea-9bf6-6aa082be1ada"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		ADXRS_RATE
		 (.oe(tmpOE__ADXRS_RATE_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXRS_RATE_net[0:0]}),
		  .analog({Net_7}),
		  .io({tmpIO_0__ADXRS_RATE_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_RATE_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_RATE_net[0:0]}));

	assign tmpOE__ADXRS_RATE_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXRS_TEMP_net;
	wire [0:0] tmpFB_0__ADXRS_TEMP_net;
	wire [0:0] tmpIO_0__ADXRS_TEMP_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_TEMP_net;
	electrical [0:0] tmpSIOVREF__ADXRS_TEMP_net;

	cy_psoc3_pins_v1_10
		#(.id("feaa0bc1-9ba8-4654-89ac-b6885d763459"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		ADXRS_TEMP
		 (.oe(tmpOE__ADXRS_TEMP_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXRS_TEMP_net[0:0]}),
		  .analog({Net_39}),
		  .io({tmpIO_0__ADXRS_TEMP_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_TEMP_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_TEMP_net[0:0]}));

	assign tmpOE__ADXRS_TEMP_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_X
		 (.oe(tmpOE__ADXL_X_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXL_X_net[0:0]}),
		  .analog({Net_40}),
		  .io({tmpIO_0__ADXL_X_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_X_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_X_net[0:0]}));

	assign tmpOE__ADXL_X_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		ADXL_Y
		 (.oe(tmpOE__ADXL_Y_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ADXL_Y_net[0:0]}),
		  .analog({Net_41}),
		  .io({tmpIO_0__ADXL_Y_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXL_Y_net),
		  .interrupt({tmpINTERRUPT_0__ADXL_Y_net[0:0]}));

	assign tmpOE__ADXL_Y_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__POT_ALPHA_net;
	wire [0:0] tmpFB_0__POT_ALPHA_net;
	wire [0:0] tmpIO_0__POT_ALPHA_net;
	wire [0:0] tmpINTERRUPT_0__POT_ALPHA_net;
	electrical [0:0] tmpSIOVREF__POT_ALPHA_net;

	cy_psoc3_pins_v1_10
		#(.id("6341a624-052e-4c70-a145-e43c9c015a34"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		POT_ALPHA
		 (.oe(tmpOE__POT_ALPHA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__POT_ALPHA_net[0:0]}),
		  .analog({Net_42}),
		  .io({tmpIO_0__POT_ALPHA_net[0:0]}),
		  .siovref(tmpSIOVREF__POT_ALPHA_net),
		  .interrupt({tmpINTERRUPT_0__POT_ALPHA_net[0:0]}));

	assign tmpOE__POT_ALPHA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__POT_GAIN_net;
	wire [0:0] tmpFB_0__POT_GAIN_net;
	wire [0:0] tmpIO_0__POT_GAIN_net;
	wire [0:0] tmpINTERRUPT_0__POT_GAIN_net;
	electrical [0:0] tmpSIOVREF__POT_GAIN_net;

	cy_psoc3_pins_v1_10
		#(.id("3895f09a-397e-445c-818f-a3e79cb719c7"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		POT_GAIN
		 (.oe(tmpOE__POT_GAIN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__POT_GAIN_net[0:0]}),
		  .analog({Net_43}),
		  .io({tmpIO_0__POT_GAIN_net[0:0]}),
		  .siovref(tmpSIOVREF__POT_GAIN_net),
		  .interrupt({tmpINTERRUPT_0__POT_GAIN_net[0:0]}));

	assign tmpOE__POT_GAIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__POT_NULL_net;
	wire [0:0] tmpFB_0__POT_NULL_net;
	wire [0:0] tmpIO_0__POT_NULL_net;
	wire [0:0] tmpINTERRUPT_0__POT_NULL_net;
	electrical [0:0] tmpSIOVREF__POT_NULL_net;

	cy_psoc3_pins_v1_10
		#(.id("9ae6c18c-ad39-414b-88e6-4a548da1eec7"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		POT_NULL
		 (.oe(tmpOE__POT_NULL_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__POT_NULL_net[0:0]}),
		  .analog({Net_44}),
		  .io({tmpIO_0__POT_NULL_net[0:0]}),
		  .siovref(tmpSIOVREF__POT_NULL_net),
		  .interrupt({tmpINTERRUPT_0__POT_NULL_net[0:0]}));

	assign tmpOE__POT_NULL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__POT_TEST_net;
	wire [0:0] tmpFB_0__POT_TEST_net;
	wire [0:0] tmpIO_0__POT_TEST_net;
	wire [0:0] tmpINTERRUPT_0__POT_TEST_net;
	electrical [0:0] tmpSIOVREF__POT_TEST_net;

	cy_psoc3_pins_v1_10
		#(.id("00752a00-0804-4967-ad5f-4046ed18be09"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		POT_TEST
		 (.oe(tmpOE__POT_TEST_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__POT_TEST_net[0:0]}),
		  .analog({Net_50}),
		  .io({tmpIO_0__POT_TEST_net[0:0]}),
		  .siovref(tmpSIOVREF__POT_TEST_net),
		  .interrupt({tmpINTERRUPT_0__POT_TEST_net[0:0]}));

	assign tmpOE__POT_TEST_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SPI_Master_v2_21_0 SPIM_EASYCAMS (
        .mosi(Net_463),
        .sclk(Net_464),
        .ss(Net_465),
        .miso(Net_466),
        .clock(Net_467),
        .reset(Net_468),
        .rx_interrupt(Net_474),
        .sdat(Net_475),
        .tx_interrupt(Net_476));
    defparam SPIM_EASYCAMS.BidirectMode = 0;
    defparam SPIM_EASYCAMS.HighSpeedMode = 0;
    defparam SPIM_EASYCAMS.NumberOfDataBits = 16;
    defparam SPIM_EASYCAMS.ShiftDir = 0;

	wire [0:0] tmpOE__ADXRS_CS_net;
	wire [0:0] tmpFB_0__ADXRS_CS_net;
	wire [0:0] tmpIO_0__ADXRS_CS_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_CS_net;
	electrical [0:0] tmpSIOVREF__ADXRS_CS_net;

	cy_psoc3_pins_v1_10
		#(.id("8c8a886a-fc73-40da-a712-753a4714b453"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ADXRS_CS
		 (.oe(tmpOE__ADXRS_CS_net),
		  .y({Net_459}),
		  .fb({tmpFB_0__ADXRS_CS_net[0:0]}),
		  .io({tmpIO_0__ADXRS_CS_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_CS_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_CS_net[0:0]}));

	assign tmpOE__ADXRS_CS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXRS_CLK_net;
	wire [0:0] tmpFB_0__ADXRS_CLK_net;
	wire [0:0] tmpIO_0__ADXRS_CLK_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_CLK_net;
	electrical [0:0] tmpSIOVREF__ADXRS_CLK_net;

	cy_psoc3_pins_v1_10
		#(.id("6f9be2c4-6aab-4059-9f33-39b9e08e3f79"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ADXRS_CLK
		 (.oe(tmpOE__ADXRS_CLK_net),
		  .y({Net_457}),
		  .fb({tmpFB_0__ADXRS_CLK_net[0:0]}),
		  .io({tmpIO_0__ADXRS_CLK_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_CLK_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_CLK_net[0:0]}));

	assign tmpOE__ADXRS_CLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_DelSig_v2_20_1 ADC (
        .vplus(Net_216),
        .vminus(Net_181),
        .soc(1'b1),
        .eoc(Net_388),
        .aclk(1'b0),
        .nVref(Net_390));

    UART_v2_10_2 UART_USB (
        .cts_n(1'b0),
        .tx(Net_375),
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
    defparam UART_USB.HwTXEnSignal = 1;
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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PSOC_RX
		 (.oe(tmpOE__PSOC_RX_net),
		  .y({1'b0}),
		  .fb({Net_376}),
		  .io({tmpIO_0__PSOC_RX_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_RX_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_RX_net[0:0]}));

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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_TX
		 (.oe(tmpOE__PSOC_TX_net),
		  .y({Net_375}),
		  .fb({tmpFB_0__PSOC_TX_net[0:0]}),
		  .io({tmpIO_0__PSOC_TX_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_TX_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_TX_net[0:0]}));

	assign tmpOE__PSOC_TX_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_424));

	wire [0:0] tmpOE__ANGLE_DAC_net;
	wire [0:0] tmpFB_0__ANGLE_DAC_net;
	wire [0:0] tmpIO_0__ANGLE_DAC_net;
	wire [0:0] tmpINTERRUPT_0__ANGLE_DAC_net;
	electrical [0:0] tmpSIOVREF__ANGLE_DAC_net;

	cy_psoc3_pins_v1_10
		#(.id("92cdac67-64a6-4ffb-b852-f1ded845f44d"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		ANGLE_DAC
		 (.oe(tmpOE__ANGLE_DAC_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ANGLE_DAC_net[0:0]}),
		  .analog({Net_61}),
		  .io({tmpIO_0__ANGLE_DAC_net[0:0]}),
		  .siovref(tmpSIOVREF__ANGLE_DAC_net),
		  .interrupt({tmpINTERRUPT_0__ANGLE_DAC_net[0:0]}));

	assign tmpOE__ANGLE_DAC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_440));


	cy_clock_v1_0
		#(.id("29133c7f-5793-4b3b-b451-0cd37df3f20b"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("250000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_ENC_1
		 (.clock_out(Net_439));


    SPI_Master_v2_21_3 SPIM_ADXRS (
        .mosi(Net_456),
        .sclk(Net_457),
        .ss(Net_459),
        .miso(Net_451),
        .clock(Net_439),
        .reset(Net_440),
        .rx_interrupt(Net_460),
        .sdat(Net_461),
        .tx_interrupt(Net_462));
    defparam SPIM_ADXRS.BidirectMode = 0;
    defparam SPIM_ADXRS.HighSpeedMode = 0;
    defparam SPIM_ADXRS.NumberOfDataBits = 16;
    defparam SPIM_ADXRS.ShiftDir = 0;

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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		VREF
		 (.oe(tmpOE__VREF_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__VREF_net[0:0]}),
		  .analog({Net_181}),
		  .io({tmpIO_0__VREF_net[0:0]}),
		  .siovref(tmpSIOVREF__VREF_net),
		  .interrupt({tmpINTERRUPT_0__VREF_net[0:0]}));

	assign tmpOE__VREF_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    VDAC8_v1_70_4 VDAC8_GYRO (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_188));
    defparam VDAC8_GYRO.Data_Source = 0;
    defparam VDAC8_GYRO.Initial_Value = 100;
    defparam VDAC8_GYRO.Strobe_Mode = 0;

	wire [0:0] tmpOE__GYRO_DAC_net;
	wire [0:0] tmpFB_0__GYRO_DAC_net;
	wire [0:0] tmpIO_0__GYRO_DAC_net;
	wire [0:0] tmpINTERRUPT_0__GYRO_DAC_net;
	electrical [0:0] tmpSIOVREF__GYRO_DAC_net;

	cy_psoc3_pins_v1_10
		#(.id("7ca8779d-9641-4bfe-be27-8dcaf49f1350"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		GYRO_DAC
		 (.oe(tmpOE__GYRO_DAC_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__GYRO_DAC_net[0:0]}),
		  .analog({Net_188}),
		  .io({tmpIO_0__GYRO_DAC_net[0:0]}),
		  .siovref(tmpSIOVREF__GYRO_DAC_net),
		  .interrupt({tmpINTERRUPT_0__GYRO_DAC_net[0:0]}));

	assign tmpOE__GYRO_DAC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ECSPI_CLK_net;
	wire [0:0] tmpFB_0__ECSPI_CLK_net;
	wire [0:0] tmpIO_0__ECSPI_CLK_net;
	wire [0:0] tmpINTERRUPT_0__ECSPI_CLK_net;
	electrical [0:0] tmpSIOVREF__ECSPI_CLK_net;

	cy_psoc3_pins_v1_10
		#(.id("ef5d5f2f-5b65-4bea-a052-1c5de4d3978a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ECSPI_CLK
		 (.oe(tmpOE__ECSPI_CLK_net),
		  .y({Net_464}),
		  .fb({tmpFB_0__ECSPI_CLK_net[0:0]}),
		  .io({tmpIO_0__ECSPI_CLK_net[0:0]}),
		  .siovref(tmpSIOVREF__ECSPI_CLK_net),
		  .interrupt({tmpINTERRUPT_0__ECSPI_CLK_net[0:0]}));

	assign tmpOE__ECSPI_CLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_60 Control_Reg_LED (
        .control_1(Net_426),
        .control_2(Net_427),
        .control_3(Net_428),
        .control_0(Net_492),
        .control_4(Net_429),
        .control_5(Net_430),
        .control_6(Net_431),
        .control_7(Net_432),
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
    defparam Control_Reg_LED.DeviceFamily = "PSoC3";
    defparam Control_Reg_LED.ExtrReset = 0;
    defparam Control_Reg_LED.NumOutputs = 1;
    defparam Control_Reg_LED.SiliconRevision = "3  ";

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
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		LED_OK
		 (.oe(tmpOE__LED_OK_net),
		  .y({Net_404}),
		  .fb({tmpFB_0__LED_OK_net[0:0]}),
		  .io({tmpIO_0__LED_OK_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_OK_net),
		  .interrupt({tmpINTERRUPT_0__LED_OK_net[0:0]}));

	assign tmpOE__LED_OK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXRS_MOSI_net;
	wire [0:0] tmpFB_0__ADXRS_MOSI_net;
	wire [0:0] tmpIO_0__ADXRS_MOSI_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_MOSI_net;
	electrical [0:0] tmpSIOVREF__ADXRS_MOSI_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ADXRS_MOSI
		 (.oe(tmpOE__ADXRS_MOSI_net),
		  .y({Net_456}),
		  .fb({tmpFB_0__ADXRS_MOSI_net[0:0]}),
		  .io({tmpIO_0__ADXRS_MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_MOSI_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_MOSI_net[0:0]}));

	assign tmpOE__ADXRS_MOSI_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ADXRS_MISO_net;
	wire [0:0] tmpIO_0__ADXRS_MISO_net;
	wire [0:0] tmpINTERRUPT_0__ADXRS_MISO_net;
	electrical [0:0] tmpSIOVREF__ADXRS_MISO_net;

	cy_psoc3_pins_v1_10
		#(.id("4c15b41e-e284-4978-99e7-5aaee19bd0ce"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		ADXRS_MISO
		 (.oe(tmpOE__ADXRS_MISO_net),
		  .y({1'b0}),
		  .fb({Net_451}),
		  .io({tmpIO_0__ADXRS_MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__ADXRS_MISO_net),
		  .interrupt({tmpINTERRUPT_0__ADXRS_MISO_net[0:0]}));

	assign tmpOE__ADXRS_MISO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- AMux AMuxSeq start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMuxSeq(
        .muxin({
            Net_50,
            Net_50,
            Net_50,
            Net_50,
            Net_50,
            Net_50,
            Net_44,
            Net_43,
            Net_42,
            Net_41,
            Net_40,
            Net_39,
            Net_7
            }),
        .vout(Net_216)
        );
    
    defparam AMuxSeq.muxin_width = 13;
    defparam AMuxSeq.init_mux_sel = 13'h0;
    defparam AMuxSeq.api_type = 1'b1;
    defparam AMuxSeq.one_active = 1;
    
    // -- AMux AMuxSeq end --


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_CTRL
		 (.int_signal(CLK_150Hz));



	cy_clock_v1_0
		#(.id("96809c05-31ec-4e83-9db7-a625d499011f"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("6666666666666.67"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_CTRL
		 (.clock_out(CLK_150Hz));



    assign Net_404 = ~Net_403;

    QuadDec_v2_0_6 QuadDec (
        .quad_A(Net_294),
        .quad_B(Net_295),
        .index(1'b0),
        .clock(Net_204),
        .interrupt(Net_355));
    defparam QuadDec.CounterResolution = 1;
    defparam QuadDec.UsingGlitchFiltering = 1;
    defparam QuadDec.UsingIndexInput = 0;

	wire [0:0] tmpOE__ENC_A_net;
	wire [0:0] tmpIO_0__ENC_A_net;
	wire [0:0] tmpINTERRUPT_0__ENC_A_net;
	electrical [0:0] tmpSIOVREF__ENC_A_net;

	cy_psoc3_pins_v1_10
		#(.id("e309cd54-1641-4501-81a6-23a1819e4247"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		ENC_A
		 (.oe(tmpOE__ENC_A_net),
		  .y({1'b0}),
		  .fb({Net_294}),
		  .io({tmpIO_0__ENC_A_net[0:0]}),
		  .siovref(tmpSIOVREF__ENC_A_net),
		  .interrupt({tmpINTERRUPT_0__ENC_A_net[0:0]}));

	assign tmpOE__ENC_A_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ENC_B_net;
	wire [0:0] tmpIO_0__ENC_B_net;
	wire [0:0] tmpINTERRUPT_0__ENC_B_net;
	electrical [0:0] tmpSIOVREF__ENC_B_net;

	cy_psoc3_pins_v1_10
		#(.id("d015eaaf-b827-4a08-b22d-e69c34fb5685"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		ENC_B
		 (.oe(tmpOE__ENC_B_net),
		  .y({1'b0}),
		  .fb({Net_295}),
		  .io({tmpIO_0__ENC_B_net[0:0]}),
		  .siovref(tmpSIOVREF__ENC_B_net),
		  .interrupt({tmpINTERRUPT_0__ENC_B_net[0:0]}));

	assign tmpOE__ENC_B_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("0e8f8c41-0472-48ce-b234-e169a2133d2a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("41666666.6666667"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_ENC
		 (.clock_out(Net_204));


	wire [0:0] tmpOE__ECSPI_CS_net;
	wire [0:0] tmpFB_0__ECSPI_CS_net;
	wire [0:0] tmpIO_0__ECSPI_CS_net;
	wire [0:0] tmpINTERRUPT_0__ECSPI_CS_net;
	electrical [0:0] tmpSIOVREF__ECSPI_CS_net;

	cy_psoc3_pins_v1_10
		#(.id("a6e60ed8-aadf-4b23-85b0-55ca78cb057a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ECSPI_CS
		 (.oe(tmpOE__ECSPI_CS_net),
		  .y({Net_465}),
		  .fb({tmpFB_0__ECSPI_CS_net[0:0]}),
		  .io({tmpIO_0__ECSPI_CS_net[0:0]}),
		  .siovref(tmpSIOVREF__ECSPI_CS_net),
		  .interrupt({tmpINTERRUPT_0__ECSPI_CS_net[0:0]}));

	assign tmpOE__ECSPI_CS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    IDAC8_v1_80_7 IDAC8_ANGLE (
        .strobe(1'b0),
        .data(8'b00000000),
        .iOut(Net_61),
        .en(1'b0),
        .ipolarity(1'b0));
    defparam IDAC8_ANGLE.Data_Source = 0;
    defparam IDAC8_ANGLE.Initial_Value = 128;
    defparam IDAC8_ANGLE.Strobe_Mode = 0;

    IDAC8_v1_80_8 IDAC8_ANGLE_OFFSET (
        .strobe(1'b0),
        .data(8'b00000000),
        .iOut(Net_61),
        .en(1'b0),
        .ipolarity(1'b0));
    defparam IDAC8_ANGLE_OFFSET.Data_Source = 0;
    defparam IDAC8_ANGLE_OFFSET.Initial_Value = 0;
    defparam IDAC8_ANGLE_OFFSET.Strobe_Mode = 0;


	cy_clock_v1_0
		#(.id("70af4b74-01f9-4648-894b-b16bb9fe1089"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("5000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_LED
		 (.clock_out(Net_502));


	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_403 = Net_402;

	wire [0:0] tmpOE__ECSPI_MOSI_net;
	wire [0:0] tmpFB_0__ECSPI_MOSI_net;
	wire [0:0] tmpIO_0__ECSPI_MOSI_net;
	wire [0:0] tmpINTERRUPT_0__ECSPI_MOSI_net;
	electrical [0:0] tmpSIOVREF__ECSPI_MOSI_net;

	cy_psoc3_pins_v1_10
		#(.id("25ab0ca5-2afb-4c20-a531-993a60bbf859"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		ECSPI_MOSI
		 (.oe(tmpOE__ECSPI_MOSI_net),
		  .y({Net_463}),
		  .fb({tmpFB_0__ECSPI_MOSI_net[0:0]}),
		  .io({tmpIO_0__ECSPI_MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__ECSPI_MOSI_net),
		  .interrupt({tmpINTERRUPT_0__ECSPI_MOSI_net[0:0]}));

	assign tmpOE__ECSPI_MOSI_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ECSPI_MISO_net;
	wire [0:0] tmpIO_0__ECSPI_MISO_net;
	wire [0:0] tmpINTERRUPT_0__ECSPI_MISO_net;
	electrical [0:0] tmpSIOVREF__ECSPI_MISO_net;

	cy_psoc3_pins_v1_10
		#(.id("b9e812da-72f1-4b3c-b3f2-1943660e4a21"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		ECSPI_MISO
		 (.oe(tmpOE__ECSPI_MISO_net),
		  .y({1'b0}),
		  .fb({Net_466}),
		  .io({tmpIO_0__ECSPI_MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__ECSPI_MISO_net),
		  .interrupt({tmpINTERRUPT_0__ECSPI_MISO_net[0:0]}));

	assign tmpOE__ECSPI_MISO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_468));


	cy_clock_v1_0
		#(.id("db03ef75-4cc3-44dd-89eb-6cbe40ca9e11"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("250000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_ENC_2
		 (.clock_out(Net_467));


    Counter_v2_10_9 Counter_LED (
        .reset(Net_334),
        .tc(Net_659),
        .comp(Net_335),
        .clock(Net_502),
        .interrupt(Net_336),
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

    // -- DFF Start --
    reg  tmp__cydff_2_reg;
    wire  tmp__cydff_2_clk;
    assign tmp__cydff_2_clk = Net_659;
    always @(posedge tmp__cydff_2_clk)
    begin
        tmp__cydff_2_reg = Net_663;
    end
    assign Net_402 = tmp__cydff_2_reg;
    // -- DFF End --


    assign Net_663 = ~Net_402;



endmodule

