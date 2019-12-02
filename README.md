# The Reaction Wheel Inverted Pendulum

This is my arduino/esp32 code used to control an inverted Pendulum controlled via the LQR Optimum controller. 

It is seperated between what I would consider more readable code via different pages. 90% of the code is hand written, however some vectorized code (namely the LQR control scheme) was generated via Mathematica v12 Microcontrollerkit.

Eventually all code including Mathematica code will be uploaded for public use and optmization. This code could be easily used to build ones own R.W.I.P, however the gainss for the LQR and subsequent interia matrices would have to be found one owns own to solve the Racatti equation to solve LQR gains. 
