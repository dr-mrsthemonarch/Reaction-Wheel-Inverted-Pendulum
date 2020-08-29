Adafruit_FXAS21002C gyro = Adafruit_FXAS21002C(0x0021002C);
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);
/*
// Offsets applied to raw x/y/z mag values
double mag_offsets[3]            = { -1.28F, -39.23F, -1.78F };
// Soft iron error compensation matrix
double mag_softiron_matrix[3][3] = { {  0.940,  0.056,  0.012 },{  0.056,  0.932, -0.023 },{  0.012, -0.023,  1.146 }
};
double mag_field_strength        = 42.35F;
// Offsets applied to compensate for gyro zero-drift error for x/y/z
double gyro_zero_offsets[3]      = { 0.0F, 0.0F, 0.0F };

*/


// Offsets applied to raw x/y/z mag values
double mag_offsets[3]            = { -13.69F, -15.64F, -46.93F };
// Soft iron error compensation matrix
double mag_softiron_matrix[3][3] = { {  0.953,  0.142,  0.02 },{  0.142,  0.997, -0.01 },{  0.02, -0.01,  1.064 }
};
double mag_field_strength        = 62.1F;



double gyro_zero_offsets[3]      = {-0.0427F, 0.0305F, 0.0049F};
