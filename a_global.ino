// escon pins and motor vars
int motorPin = 21;  
int enablePin = 14; 
int lowPWM = 6554; // 10% from 65535 (16bit PWM)
int highPWM = 58982; // 90% from 65535 (16bit PWM)
int nullPWM = (highPWM + lowPWM) / 2;
int analogPin = 0; // green
int analogVal = 0;
float stromPWM;

// string vars
float setWrite = 0;
float ampPWM = nullPWM;
int incomingbyte = 0;
String stringRead;
int manualControl;

//body angle and flywheel speeds
float theta;
float lqrSignal;
int16_t adc0;
float omega;


// set ledc params
const int freq = 10000;
const int ledChannel = 0;
const int resolution = 16;
