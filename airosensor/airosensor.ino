/**************************************************************************
 This is sensor consists of:
 arduino nano
 grove shield
 LCD
 
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "MHZ19.h"
#include <SoftwareSerial.h>  

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define RX_PIN_CO2 7                                          
#define TX_PIN_CO2 6 

String txt1, txt2, txt3, txt4;
float temperature, pressure, relhum;
int CO2;

MHZ19 myMHZ19;   
Adafruit_BME280 bme; // I2C
SoftwareSerial mySerial(RX_PIN_CO2, TX_PIN_CO2);                   // Uno example
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); 
  myMHZ19.begin(mySerial);
  bme.begin(0x76);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  CO2 = myMHZ19.getCO2();
  temperature = bme.readTemperature();
  pressure = (bme.readPressure() / 100); // hPa
  relhum = bme.readHumidity();
  txt1 = "T = "+String(temperature,1) + " *C";
  txt2 = "P = "+String(pressure,0) + "hPa";
  txt3 = "H = "+String(relhum,1) + "%";
  txt4 = " " + String(CO2) + "ppm";
  display.clearDisplay();
  display.setCursor(0, 0);     // Start at top-left corner
  display.println(txt1);
  display.setCursor(0, 10);
  display.println(txt2);
  display.setCursor(0, 20);
  display.println(txt3);
  display.drawLine(66, 0, 66, display.height()-1, SSD1306_WHITE);
  display.setCursor(68, 0);
  display.println(" CO2:");
  display.setCursor(68, 10);
  display.println(txt4);
  if (CO2>800){
    display.setCursor(68, 20);
    display.println(" WARNING");
  }
  display.display(); 
  delay(1000);
}
