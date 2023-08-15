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

  

_The designed robotic solution model this time consists on a modification of the original robot car we built, leaving only some parts for ease and costs savings. Again, this robot car is powered by ESP-32 and programmed in the ARDUINO IDE._

_Now, we will expand in the main aspects used and incluided in the robot car's development (Elements and ARDUINO IDE):_

  

  

  -   _Motors: The robot has two direct current (DC) motors that allow it to move in different directions. Meanwhile one of the motors serves as rear wheel drive, the other gives it the ability to turn left or right. The rear wheel drive motor provides the forward or backward motion of the robot, while the turning motor rotates the front wheels to change the orientation of the robot. By combining these two motions, the robot can move in any direction on a flat surface._  



   
  -   _ESP-32: Dual-Core SoC Chip (System on a Chip) of low cost and energy that uses a Tensilica Xtensa LX6 microprocessor (both in the one used here, and in its single or dual-core variants). This being the principal element on the entire robot (because, well, it is the one thing that powers the robot and makes possible all of its functions)._

 


   -   _ARDUINO Integrated Development Environment (IDE): The previous time we didn't really expand in this point, but although it is not relevant in which programming environment you're developing this, it is relevant to clarify what the ARDUINO IDE is and why we use it in the development of the robot._

 **= WHAT IS ARDUINO IDE?**
     
_The Arduino Integrated Development Environment (IDE) is a cross-platform software (for Windows, macOS, Linux) written in the Java programming language. It is used to write and upload code to Arduino-compatible boards, as well as other boards from different manufacturers with the help of additional cores._

_It can handle C and C++ languages with specific rules for organizing the code. It also provides a software library from the Wiring project that has many common I/O functions. The code written by users only needs two basic functions: one to start the sketch and one to run the main loop. These functions are compiled and linked with a main() function in a loop using the GNU toolchain, which is also part of the IDE.4 The Arduino IDE uses a program called avrdude to turn the executable code into a text file with hexadecimal encoding that is transferred to the Arduino board by a loader program in the board’s firmware._

  **= WHY WE USED IT?**
    
_We used this development environment due to its accessibility and ease of use, which were very important factors during the development of the project._


   -   _Ultrasonic board: The robot has an HC-SR04 ultrasonic board that works as a sonar. The HC-SR04 sensor has two transducers: a piezoelectric transmitter and receiver, in addition to the electronics necessary for its operation. The operation of the sensor is as follows: the piezoelectric transmitter emits 8 ultrasonic pulses (40KHz) after receiving the order on the TRIG pin, the sound waves travel in the air and bounce when meeting an object, the bounce sound is detected by the piezoelectric receiver, then the ECHO pin changes to High (5V) for a time equal to the time the wave took from when it was emitted to when it was detected, the time of the ECHO pulse is measured by the microcontroller and thus the distance can be calculated to the object. Sensor performance is not affected by sunlight or black-colored material (although acoustically soft materials such as cloth or wool can be difficult to detect). All of this in a range of 2 to 450 cm._
  

  

   -   _Camera: The robot has an OV2640 camera that can be connected to the ESP-32. Built by Omnivision back in 2005, the camera has a resolution of 2 megapixels and can capture images in color or grayscale. The camera is used to recognize objects, people or colors using artificial vision algorithms, and even when it was discontinued back in 2009, it still remains popular today._  

  
  

   -   _Custom Chassis: The robot was made almost from scratch, so we had to recreate some (if not all) of the pieces. We used cardboard and other easy-to-find materials to create most of the case. However, the chassis and other small parts that had to be very resistant were 3D printed. This allowed us to create a custom design that was both functional and aesthetically pleasing._  

  


   -   _1.5v AA Batteries: Guess I don't need to explain what a AA battery is. Previously we used a "peculiar" type of battery called "18650 rechargeable lithium batteries" because of the high energy comsumption, but in this remake of the robot, we didn't need to use them and it was more easy en the mayority of aspects, so we kept going with the traditional AA batteries._


  

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
