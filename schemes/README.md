Electromechanical diagrams
====

This directory must contain one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.

-------

Hi, Luis here, to quickly clarify what is connected to what:

- The car reads the voltage of the batteries through GPIO32 of ESP32. Because the battery 
voltage is not read frequently, this GPIO is also used to control the WS2812 LED.

The voltage acquisition range of GPIO32 on ESP32 is 0-3.3V, while the car is powered by two 18650 lithium 
batteries, whose voltage is 8.4V when they are fully charged, which exceeds the acquisition range of ESP32. 
Therefore, after passing through the voltage divider circuit composed of R3 and R4, the voltage at A0/WS2812 
will be about 1/4 of the battery voltage, 8.4/4=2.1V, which is within the voltage collection range of GPIO32.

- As can be seen from the figures "Ultrasonic" and "Esp-32", ESP32 uses GPIO12 and GPIO15 to control the 
"Trig" and "Echo" pins of the ultrasonic module.

- About the motors, As can be seen from the figure "motor controller", if we want to control the motor M1, we need to set the 14th and 15th 
channels of the PCA9685.

And as for the servos, channels 0-7 of PCA9685 are used to control servos.

- Although not illustrated correctly, the Raspberry Pi 4 gets its energy from a Power Bank via USB, connects to the Esp32 via USB and uses the Webcam via USB.
------------------------
