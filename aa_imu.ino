Adafruit_FXAS21002C gyro = Adafruit_FXAS21002C(0x0021002C);
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);

// Offsets applied to raw x/y/z mag values
float mag_offsets[3]            = { -1.28F, -39.23F, -1.78F };
// Soft iron error compensation matrix
float mag_softiron_matrix[3][3] = { {  0.940,  0.056,  0.012 },
  {  0.056,  0.932, -0.023 },
  {  0.012, -0.023,  1.146 }
};
float mag_field_strength        = 42.35F;
// Offsets applied to compensate for gyro zero-drift error for x/y/z
float gyro_zero_offsets[3]      = { 0.0F, 0.0F, 0.0F };
