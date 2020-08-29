// manual variables and string read
double K1, K2, K3;
double offsetAngle, offsetOmega, winkel_measured;
String  v1, v2, v3, enable;

// escon pins and motor vars
int motorPin = 21;  
int enablePin = 14; 
int lowPWM = 6554; // 10% from 65535 (16bit PWM)
int highPWM = 58982; // 90% from 65535 (16bit PWM)
int nullPWM = (highPWM + lowPWM) / 2;
int analogPin = 0; // green
int analogVal = 0;
double stromPWM;

// string vars
double setWrite = 0;
double ampPWM = nullPWM;
int incomingbyte = 0;
String stringRead;
int manualControl;

//body angle and flywheel speeds
double theta;
double lqrSignal,lqrSignal2,PIDSignal;
int16_t adc0;
double omega;


// set ledc params
const int freq = 10000;
const int ledChannel = 0;
const int resolution = 16;
