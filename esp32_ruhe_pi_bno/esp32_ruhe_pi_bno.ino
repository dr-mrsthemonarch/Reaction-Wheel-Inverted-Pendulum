#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_ADS1015.h>
#include <driver/adc.h>
//Adafruit_Madgwick filter;

//initialize classes
Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);
