// read multiple values from string with : delimiter
String getValue(String data, char separator, double index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

double pwmtoRPM(double pwm) {
  // calculate RPM from range of 0.1v to 3v 12 bit
  double RPM = 8.53108 * pwm - 6594.5;
  double rads = 0.1047197551 * RPM;
  //  return RPM;
  return rads;
}

// convert Amps to PWM signal
double ampsToPWM(double sgnl) {
  double thing;
  thing = (((highPWM) - (lowPWM)) / 4.4) * sgnl + nullPWM;
  return thing;
}
int readMotor() { // for esp32 adc otherwise do not use
//  adc1_config_width(ADC_WIDTH_BIT_11);   //Range 0-2048
//  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); //ADC_ATTEN_DB_11 = 0-3,6V
  return adc1_get_raw( ADC1_CHANNEL_0 ); //Read analog pin A0
}
void Motor(double lqrSignal) {
  double pwm = ampsToPWM(lqrSignal);
  ledcWrite(ledChannel, pwm);
}
