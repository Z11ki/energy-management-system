**component breakdown**



\#1 ESP8266

reads data from the sensor

sends data to the cloud or app

controls outputs(like on and off)

\*key pins

-analog pin A0:reads current sensor

-Digital pin D1: control relay



\#2 ACS712 current sensor

it is current measuring component.

it detects how much current flows.

outputs an analog voltage signal to the ESP8266.

used to calculate Real-time current usage in amps.



\#3 relay module

an electrically controlled switch.

turns the connected appliance ON or Off based on ESP8266 commands.

acts like a remote-controlled  power switch for device.

Isolated from LOw-voltage control for safety.



\#4 Ac plug and Ac Socket

lets high voltage flow in to the system.

the relay sits between the plug and socket to control the power flow.



\#5 smartphone with BLynk App

UI for remote control and monitoring.

shows real time current readings.

has remote to control the relay



