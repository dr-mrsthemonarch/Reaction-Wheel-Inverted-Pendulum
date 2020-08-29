void setup()
{
  Serial.begin(256000);
  /* Initialise the sensor */
  Serial.println(F("Adafruit AHRS Fusion Example")); Serial.println("");
  // Initialize the sensors.
  if (!gyro.begin())
  {
    /* There was a problem detecting the gyro ... check your connections */
    Serial.println("Ooops, no gyro detected ... Check your wiring!");
    while (1);
  }
  if (!accelmag.begin(ACCEL_RANGE_2G))
  {
    Serial.println("Ooops, no FXOS8700 detected ... Check your wiring!");
    while (1);
  }
  filter.begin(300);
  delay(300);
  ledcSetup(ledChannel, freq, resolution);   // configure LED PWM functionalitites
  ledcAttachPin(motorPin, ledChannel);   // attach the channel to the GPIO to be controlled
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // initialize controller off
  ledcWrite(ledChannel, nullPWM); // escon requires 10% PWM signal to activate
}
