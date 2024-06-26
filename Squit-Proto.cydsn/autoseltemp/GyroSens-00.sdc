# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Documents and Settings\user\Documenti\PSoC Creator\GYROSENS\Vers.0.0-T00 2012-1213 (creator 2.1 - verify pinout)\GyroSens-00\GyroSens-00.cydsn\GyroSens-00.cyprj
# Date: Mon, 17 Dec 2012 09:53:38 GMT
#set_units -time ns
create_clock -name {ClockBlock/clk_bus} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus}]
create_clock -name {ClockBlock/dclk_0} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/dclk_0}]
create_clock -name {ClockBlock/dclk_1} -period 250 -waveform {0 125} [get_pins {ClockBlock/dclk_1}]
create_clock -name {ClockBlock/dclk_2} -period 250 -waveform {0 125} [get_pins {ClockBlock/dclk_2}]
create_clock -name {ClockBlock/dclk_3} -period 1000 -waveform {0 500} [get_pins {ClockBlock/dclk_3}]
create_clock -name {ClockBlock/dclk_4} -period 2166.6666666666665 -waveform {0 1083.33333333333} [get_pins {ClockBlock/dclk_4}]
create_clock -name {ClockBlock/aclk_0} -period 4791.6666666666661 -waveform {0 2395.83333333333} [get_pins {ClockBlock/aclk_0}]
create_clock -name {ClockBlock/dclk_5} -period 5000000 -waveform {0 2500000} [get_pins {ClockBlock/dclk_5}]
create_clock -name {ClockBlock/dclk_6} -period 6666666.666666666 -waveform {0 3333333.33333333} [get_pins {ClockBlock/dclk_6}]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {Clock_ENC} -source [get_pins {ClockBlock/clk_sync}] -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_ENC_1} -source [get_pins {ClockBlock/clk_sync}] -divide_by 6 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_ENC_2} -source [get_pins {ClockBlock/clk_sync}] -divide_by 6 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {ADC_Ext_CP_Clk} -source [get_pins {ClockBlock/clk_sync}] -divide_by 24 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {UART_USB_IntClock} -source [get_pins {ClockBlock/clk_sync}] -divide_by 52 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 115 231} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {Clock_LED} -source [get_pins {ClockBlock/clk_sync}] -divide_by 120000 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_5}]]
create_generated_clock -name {Clock_CTRL} -source [get_pins {ClockBlock/clk_sync}] -divide_by 160000 -duty_cycle 50 -nominal_period 6666666.666666666 [list [get_pins {ClockBlock/dclk_glb_6}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -duty_cycle 50 [list [get_pins {ClockBlock/clk_bus_glb}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Documents and Settings\user\Documenti\PSoC Creator\GYROSENS\Vers.0.0-T00 2012-1213 (creator 2.1 - verify pinout)\GyroSens-00\GyroSens-00.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Documents and Settings\user\Documenti\PSoC Creator\GYROSENS\Vers.0.0-T00 2012-1213 (creator 2.1 - verify pinout)\GyroSens-00\GyroSens-00.cydsn\GyroSens-00.cyprj
# Date: Mon, 17 Dec 2012 09:53:17 GMT
