Engineering materials
====

This repository contains engineering materials of a self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2023 (Team T.W.L).

## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members)
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom)
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements. If there is nothing to add to this location, the directory can be removed.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation how to connect to a SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions etc. If there is nothing to add to this location, the directory can be removed.


## Introduction

_Hello, Here Luis from Team T.W.L., and again I and my colleagues will expand a little in the operational elements present in the robotic solution for this 2023 season._

-------------------------------------------------------------------------------------------------------------------------------------  

  

_The designed robotic solution model this time consists on a modification of the original robot car we built, leaving only some parts for ease and costs savings. Again, this robot car is powered by ESP-32 and Raspberry Pi 4 and programmed in C++ (ARDUINO IDE) and Python._

_Now, we will expand in the main aspects used and incluided in the robot car's development (**Elements** and **Coding Environments**):_

  
     Elements
  

  -   _Motors: The robot has 1 direct current (DC) motor and 1 SG90 servomotor that allow it to move in different directions. Meanwhile the DC motor serves as rear wheel drive, the servomotor gives it the ability to turn left or right. The rear wheel drive motor provides the forward or backward motion of the robot, while the turning motor rotates the front wheels to change the orientation of the robot. By combining these two motions, the robot can move in any direction on a flat surface._  



   
  -   _ESP-32: Dual-Core SoC Chip (System on a Chip) of low cost and energy that uses a Tensilica Xtensa LX6 microprocessor (both in the one used here, and in its single or dual-core variants). This, along with the Raspberry Pi, being the main elements in the entire robot._





  -   _Raspberry Pi 4: The Raspberry Pi 4 is a single-board development board used for entry-level computing, being released the latest version (Raspberry Pi 4) in June 2019. The board is available in four RAM variants: 1 GB, 2 GB, 4 GB, and 8 GB. Model B (the one we are using) is the most common and comes with a Broadcom BCM2711 processor, which is a 1.5GHz 12 GHz quad-core ARM Cortex-A72 processor. Additionally, it has enhanced USB capability with two USB 2.0 ports and two USB 3.0 ports, enabling up to ten times faster data transfers. It also comes with Gigabit Ethernet connectivity, built-in wireless and Bluetooth._

  _Before, the ESP-32 did all the hard work in the entire robot, but in the tests we noticed that it wouldn't take it, so we looked for alternatives to something that could take all the functions the robot had to handle by itself, so Edilio had the idea to use a Raspberry Pi 4 because of the experience he had investigating about it, so we got one to take at least the camera and color recognition functions, leaving the rest to the ESP-32._




   -   _Ultrasonic board: The robot has an HC-SR04 ultrasonic board that works as a sonar. The HC-SR04 sensor has two transducers: a piezoelectric transmitter and receiver, in addition to the electronics necessary for its operation. The operation of the sensor is as follows: the piezoelectric transmitter emits 8 ultrasonic pulses (40KHz) after receiving the order on the TRIG pin, the sound waves travel in the air and bounce when meeting an object, the bounce sound is detected by the piezoelectric receiver, then the ECHO pin changes to High (5V) for a time equal to the time the wave took from when it was emitted to when it was detected, the time of the ECHO pulse is measured by the microcontroller and thus the distance can be calculated to the object. Sensor performance is not affected by sunlight or black-colored material (although acoustically soft materials such as cloth or wool can be difficult to detect). All of this in a range of 2 to 450 cm._
  

  

   -   _Camera: The robot has an OV2640 camera that can be connected to the ESP-32. Built by Omnivision back in 2005, the camera has a resolution of 2 megapixels and can capture images in color or grayscale. The camera is used to recognize objects, people or colors using artificial vision algorithms, and even when it was discontinued back in 2009, it still remains popular today._  




   -   _3.7V 18650 Lithium Batteries: The robot, due to its high energy consumption (yeh, still uses a lot of energy) uses this peculiar type of batteries to supply itself with energy. These batteries are rechargeable and have a capacity of between 1500 and 3500 mAh (ours supposedly have 9900 mAh but I highly doubt it). The batteries have a nominal voltage of 3.7V and a maximum voltage of 4.2V. The batteries are connected to the robot through a battery holder that has an on/off switch. The batteries can be charged with a special charger that has a protection circuit against overloads and short circuits._


    Coding Environments
_The previous time we didn't really expand in this point, but although it is not relevant in which programming environment you're developing this, it is relevant to clarify what the ARDUINO IDE is and why we use it in the development of the robot._

  -   _ARDUINO Integrated Development Environment (C++): The Arduino Integrated Development Environment (IDE) is a cross-platform software (for Windows, macOS, Linux) written in the Java programming language. It is used to write and upload code to Arduino-compatible boards, as well as other boards from different manufacturers with the help of additional cores._

_It can handle C and C++ languages with specific rules for organizing the code. It also provides a software library from the Wiring project that has many common I/O functions. The code written by users only needs two basic functions: one to start the sketch and one to run the main loop. These functions are compiled and linked with a main() function in a loop using the GNU toolchain, which is also part of the IDE. The Arduino IDE uses a program called avrdude to turn the executable code into a text file with hexadecimal encoding that is transferred to the Arduino board by a loader program in the board’s firmware._



  -   _Python: Python Integrated Development Environment (or Python for short) is a high-level interpreted programming language whose philosophy emphasizes the readability of its code, it is used to develop applications of all kinds, for example: Instagram, Netflix, Spotify, Panda3D, among others. It is a multi-paradigm programming language, since it partially supports object orientation, imperative programming and, to a lesser extent, functional programming. It is an interpreted, dynamic and cross-platform language. Created back in late 80s, Python consistently ranks as one of the most popular programming languages.
---------------------------------------------------------------------------------------------------------------------------------------

    HOW THE CAMERA WORKS

_The artificial vision algorithms that are used to recognize objects or colors are computer programs that process the images captured by the OV2640 camera and extract relevant information from them. For example, to recognize colors, We use an algorithm that converts color images to grayscale and then applies a red, green or blue color mask depending on the color we want to detect. Then, we calculate the percentage of pixels of the desired color in the image and compare it with a predefined threshold to determine whether or not there is presence of the color._

    HOW TO COMPILE THE CODE TO THE VEHICLE

_If you already finished the code that you are going to enter to ESP-32, the process of compiling it would be the following:_
- _Connect the ESP-32 to the computer through a Micro-USB cable_
- _Look for the button in the Programming Environment to transfer the code_
- _Wait for it to finish_

--------------------------------------------------------------------------------------------------------------------------------------

    OBJECTIVE OF THE ROBOTIC SOLUTION.

The objective of this robotic solution model is to demonstrate the capabilities of the ESP32 chip and its possible applications in the field of educational robotics. Despite not having the many functions it previously had, it continues to be an excellent example for future generations to learn a field as interesting as robotics.

--------------------------------------------------------------------------------------------------------------------------------------
_Thank You._
======================================================================================================================================
