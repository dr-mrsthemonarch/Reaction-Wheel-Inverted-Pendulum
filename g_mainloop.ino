void loop(void)
{
  sensors_event_t gyro_event;
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  gyro.getEvent(&gyro_event);
  accelmag.getEvent(&accel_event, &mag_event);

  float axraw = accelmag.accel_raw.x;
  float ax = (1.0007329 * (axraw / 4096) - 0.025653) * 9.81; //nxp cal method ai == w *raw/4096 + v

  float ayraw = accelmag.accel_raw.y;
  float ay = (0.9944161 * (ayraw / 4096) + 0.037144) * 9.81;

  float azraw = accelmag.accel_raw.z;
  float az = (1.0185 * (azraw / 4096) - 0.0481) * 9.81;


  // Apply mag offset compensation (base values in uTesla)
  float x = mag_event.magnetic.x - mag_offsets[0];
  float y = mag_event.magnetic.y - mag_offsets[1];
  float z = mag_event.magnetic.z - mag_offsets[2];

  // Apply mag soft iron error compensation
  float mx = x * mag_softiron_matrix[0][0] + y * mag_softiron_matrix[0][1] + z * mag_softiron_matrix[0][2];
  float my = x * mag_softiron_matrix[1][0] + y * mag_softiron_matrix[1][1] + z * mag_softiron_matrix[1][2];
  float mz = x * mag_softiron_matrix[2][0] + y * mag_softiron_matrix[2][1] + z * mag_softiron_matrix[2][2];

  // Apply gyro zero-rate error compensation
  float gx = gyro_event.gyro.x ;
  float gy = gyro_event.gyro.y ;
  float gz = gyro_event.gyro.z ;

  // The filter library expects gyro data in degrees/s, but adafruit sensor
  // uses rad/s so we need to convert them first (or adapt the filter lib
  // where they are being converted)
  gx *= 57.2958F;
  gy *= 57.2958F;
  float gzz = gz * 57.2958F;

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

  lqrSignal = update_nssm3(u);
  lqrMotor(lqrSignal);

  Serial.print(theta - PI); // print in degrees
  Serial.print(",");
  Serial.print(omega / 100);
  Serial.print(",");
  Serial.println(lqrSignal);
  delayMicroseconds(150);
}
