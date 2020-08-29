void loop(void)
{
  unsigned long previousMillis = 0;
  const long interval = 3; // prime number
  unsigned long currentMillis = millis();
  sensors_event_t gyro_event;
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  gyro.getEvent(&gyro_event);
  accelmag.getEvent(&accel_event, &mag_event);

  double axraw = accelmag.accel_raw.x;
  double ax = (1.0007329 * (axraw / 4096) - 0.025653) * 9.81; //nxp cal method ai == w *raw/4096 + v

  double ayraw = accelmag.accel_raw.y;
  double ay = (0.9944161 * (ayraw / 4096) + 0.037144) * 9.81;

  double azraw = accelmag.accel_raw.z;
  double az = (1.0185 * (azraw / 4096) - 0.0481) * 9.81;


  // Apply mag offset compensation (base values in uTesla)
  double x = mag_event.magnetic.x - mag_offsets[0];
  double yy = mag_event.magnetic.y - mag_offsets[1];
  double z = mag_event.magnetic.z - mag_offsets[2];

  // Apply mag soft iron error compensation
  double mx = x * mag_softiron_matrix[0][0] + yy * mag_softiron_matrix[0][1] + z * mag_softiron_matrix[0][2];
  double my = x * mag_softiron_matrix[1][0] + yy * mag_softiron_matrix[1][1] + z * mag_softiron_matrix[1][2];
  double mz = x * mag_softiron_matrix[2][0] + yy * mag_softiron_matrix[2][1] + z * mag_softiron_matrix[2][2];

  // Apply gyro zero-rate error compensation
  double gx = gyro_event.gyro.x ;
  double gy = gyro_event.gyro.y ;
  double gz = gyro_event.gyro.z ;

  // The filter library expects gyro data in degrees/s, but adafruit sensor
  // uses rad/s so we need to convert them first (or adapt the filter lib
  // where they are being converted)
  gx *= 57.2958F;
  gy *= 57.2958F;
  double gzz = gz * 57.2958F;

  //===================================================================================================================================================================


  filter.update(gx, gy, gzz, ax, ay, az, mx, my, mz);
  theta = 1 * (((filter.getPitch() * (PI / 180)) + 3 * PI / 4) + offsetAngle);
  adc0 = ads.readADC_SingleEnded(0);
  omega = pwmtoRPM(adc0);


  //============================ read serial for manual control
  if (Serial.available() > 0) {
    stringRead = Serial.readString();
  }
  enable = getValue(stringRead, ':', 0);
  v1 = getValue(stringRead, ':', 1);
  v2 = getValue(stringRead, ':', 2);
  v3 = getValue(stringRead, ':', 3);
  manualControl = enable.toInt();
  manual(manualControl, v1, v2, v3);
  //============================ read serial for manual control

  u[0] = theta;
  u[1] = -1 * gz;
  u[2] = omega;


  lqrSignal = update_LQR(u);
  update_scm(u, y);
  double nssm1 = y[0];
  double nssm2 = y[1];
  //Motor(y[0]);
  Motor(lqrSignal);


  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    //   Serial.print(currentMillis); // print in degrees
    //   Serial.print(",");
    Serial.print(theta); // print in degrees
    Serial.print(",");
    Serial.print(lqrSignal);
    Serial.print(",");
    Serial.print(nssm1);
    Serial.print(",");
    Serial.println(nssm2);
  }
  delayMicroseconds(151);// prime number
}
