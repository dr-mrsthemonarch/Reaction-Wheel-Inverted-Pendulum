# The Reaction Wheel Inverted Pendulum

This is my arduino/esp32 code used to control an inverted Pendulum controlled via the LQR Optimum controller. 

It is seperated between what I would consider more readable code via different pages. 90% of the code is hand written so don't expect to be good in any form, however some vectorized code (namely the LQR control scheme) was generated via Mathematica v12 Microcontrollerkit, and should be half decent.

This code could be easily used to build ones own machine, assuming the same sensors and mechanics were used gains for the LQR controller and the angle being measured will unlikely fit, but this code would probably provide a nice starting point.

<iframe width="560" height="315" src="https://www.youtube.com/embed/Lzw3ZGTuMUU" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
