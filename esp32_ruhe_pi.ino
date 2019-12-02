#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Madgwick.h>
//#define NXP_FXOS8700_FXAS21002
#include <Adafruit_FXAS21002C.h>
#include <Adafruit_FXOS8700.h>
#include <SimpleKalmanFilter.h>
#include <Adafruit_ADS1015.h>
#include <driver/adc.h>
Madgwick filter;

//initialize classes
Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

float K1, K2, K3;
float offsetAngle, offsetOmega, winkel_measured;
String  v1, v2, v3, enable;
float u[3] = {0,0,0};
float yr[1] = {0};
