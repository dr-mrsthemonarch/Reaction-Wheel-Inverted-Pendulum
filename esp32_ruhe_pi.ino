#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <MadgwickAHRS.h>
//#define NXP_FXOS8700_FXAS21002
#include <Adafruit_FXAS21002C.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_ADS1015.h>
#include <driver/adc.h>
Madgwick filter;

//initialize classes
Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */
