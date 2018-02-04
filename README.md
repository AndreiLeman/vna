# vna
A simple and cheap vector network analyzer, including support software.

As seen on kickstarter:
https://www.kickstarter.com/projects/1759352588/xavna-a-full-featured-low-cost-two-port-vna

# Directory layout
* Root directory: software; compile and run on any Linux based system
* pcb: schematics, pcb layouts, and simulation files
* vhdl: circuitry implemented on the fpga

# Specifications
* Frequency range: guaranteed **137MHz - 2500MHz**, typical **135MHz - 3500MHz**
* Measurement signal level (controlled using spi interface): **-20dBm to 10dBm, with 1dB increments**

# Interfacing
The main board connects to a PC through usb and communicates via a virtual serial port device; the PC software sets the frequency and other parameters by sending two-byte register write commands, and the device sends averaged vector values representing magnitude and phase of measured wave.

# Block diagram

##### Overall architecture
![block diagram](pictures/overall_diagram.png)

##### Receivers & interfacing
![block diagram](pictures/vna_main.png)

##### Signal generator
![block diagram](pictures/vna_tx.png)

##### FPGA logic
![block diagram](pictures/fpga_logic.png)



##### Calibration standards
(Short, Open, Load)

![calibration standards](pictures/calibration_standards.jpg)



# Screenshots

##### Open circuited stub

![screenshot](pictures/screenshot_open_stub.png)


##### Short circuited stub

![screenshot](pictures/screenshot_shorted_stub.png)


##### Antenna

![screenshot](pictures/screenshot_antenna.png)


# Parts selection
* fpga: XC6SLX9-2TQG144C 
* adc: AD9200
* mixer: AD8342
* synthesizers: ADF4350
* rf switches: BGS14GA14
* programmable attenuator: PE4312

# Pictures (~~iteration~~ release 2)
![vna board 2](pictures/main2_top.jpg)

# Pictures (~~iteration~~ release 1)

##### Complete assembly
![vna assembly](pictures/all.jpg)

##### Main board
![main board](pictures/main_top.png)

##### Signal generator
![signal generator board](pictures/tx_top.png)

##### Directional coupler
![directional coupler board](pictures/coupler_top.png)
