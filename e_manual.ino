// Manual control breaks, speeds, disable and enable driver or other functions
float manual(int manualControl, String v1, String v2, String v3) {
  switch (manualControl) {

    case 7001: // Omega offset
      offsetOmega = v3.toFloat();
      break;

    case 7002: // Angle offset
      offsetAngle = v3.toFloat();
      break;

//    case 7003: // Angle offset
//      interval = v3.toInt();
//      break;

    case 8000: // enable driver, apply pwm
      digitalWrite(enablePin, HIGH);
      ampPWM = v3.toFloat();
      stromPWM = atp(ampPWM); // used in manual control
      ledcWrite(ledChannel, stromPWM);
      break;

    case 9000: // disable driver set pwm to lowPWM
      digitalWrite(enablePin, LOW);
      ledcWrite(ledChannel, nullPWM);
      break;

    case 9001: // enable driver, speed a direction, set pwm to lowPWM
      digitalWrite(enablePin, HIGH);
//      ledcWrite(ledChannel, nullPWM);
      break;

    case 0000: // change lqr gains
      K1 = v1.toFloat();
      K2 = v2.toFloat();
      K3 = v3.toFloat();
      break;
  }
}
