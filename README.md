# HWheel
This is open source force feedback wheel base on Arduino

The code use some libraries and files from other projects like:
- adapt-ffb-joy 
- ForceFeedback-core-library
- kaskus forums
- microchip forums
- filter

https://github.com/MartinBloedorn/libFilter

Usage:
- pin0,1 for encoder
- pin 2 for hall effect sensor.
- pin 9, 10 for Pulse/dir; PWM+-
- Modify WheelConfig to match your hardware setup

I have modified this code for use with a wheel i have design (link to 3d printable files to be included) 

Added features are a soft stop for wheel limits, as setting the force straight to 255 was causing vibrations
as i am using a cheaper 2 output encoder, i have added a hall effect sensor and a magnet to the main drive wheel which the encoder is attached to, when the magnet passes the sensor the Zpin is triggered, i have modified the code to correctly set the position to 0 the first time this happens.
