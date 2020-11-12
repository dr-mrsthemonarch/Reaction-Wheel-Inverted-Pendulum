void setup()
{
  Serial.begin(256000);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(true);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  //  filter.begin(300);
  ledcSetup(ledChannel, freq, resolution);   // configure LED PWM functionalitites
  ledcAttachPin(motorPin, ledChannel);   // attach the channel to the GPIO to be controlled
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // initialize controller off
  ledcWrite(ledChannel, nullPWM); // escon requires 10% PWM signal to activate
  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads.begin();
  adc1_config_width(ADC_WIDTH_BIT_11);   //Range 0-2048
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); //ADC_ATTEN_DB_11 = 0-3,6V
}
