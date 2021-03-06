# Simple Air Sensor
A simple arduino based sensor for measuring CO2 concentration, temperature, humidity and airpressure.
![Assembled Sensor](img/final_sensor.jpg?raw=true "Assembled Sensor")

## Components
* [Winsen MH-Z19B NDIR CO2 Module](img/MH-Z19B_k.jpg) ([specifications](doc/MH-Z19B.pdf))
* 0.91-inch-oled-display (128*32-pixels)
* bme280-digital-presure-temperature-humidity-sensor-module
* seeed-studio-seeeduino-nano
* seeed-studio-grove-shield
* 2x m5stack-grove-cabel-20cm

## Build Instructions
* Desolder the pinheader from the OLED display
* Cut one m5stack grove cable in two and strip the wire ends
* Solder one to the BME280
* Solder the other to the OLED display
* Cut the other m5stack grove cable in two and strip the wire ends
* Solder to the MH-Z19B
* Plug the MHZ19B in port D6, the MBE280 in one of the I2C ports and the OLED in the other I2C port.
* Upload the code to the arduino

## Usage
Simply connect to a usb-c phone charger.
By connecting pin 4 to the ground the device can be put in calibration-mode. It needs 20 minutes in clean outside air to determine the signal at a concentration of 400 ppm CO2. 

The device can ofcourse be made portable with a powerbank and a usb-c cable.
