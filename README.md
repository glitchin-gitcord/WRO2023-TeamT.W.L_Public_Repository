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

  

_The designed robotic solution model this time consists of a robot car, being built from scratch with some 3d printed elements, and powered by an ESP-32 once again, but this time with the addition of an expansion module, in wich we will expand later on._

_Anyways, the robot car possesses the following main elements:_

  

  

  -   _Motors: The robot has two direct current (DC) motors that allow it to move in different directions. procede a enseñar que hace cada motor cuando tengas la info_  



   
  -   _ESP-32: Dual-Core SoC Chip (System on a Chip) of low cost and energy that uses a Tensilica Xtensa LX6 microprocessor (both in the one used here, and in its single or dual-core variants). This being the principal element on the entire robot (because, well, it is the one thing that powers the robot and makes possible all of its functions)._

 


   -   _Expansion Module: The expansion module for ESP32 is a device that connects to the ESP32 microcontroller to provide more input/output pins. This one is generic so I can't really expand much in exact model and so, but I do have this details about the power ports on the expansion module:_
     
  _DC power connector: 6.5 - 16 V_, 
  _* Micro USB: 5V (power only)_, 
  _* USB Type-C: 5V (power only)_

  _Those are the only details I could found for this specific expansion module._




   -   _Ultrasonic board: The robot has an HC-SR04 ultrasonic board that works as a sonar. The HC-SR04 sensor has two transducers: a piezoelectric transmitter and receiver, in addition to the electronics necessary for its operation. The operation of the sensor is as follows: the piezoelectric transmitter emits 8 ultrasonic pulses (40KHz) after receiving the order on the TRIG pin, the sound waves travel in the air and bounce when meeting an object, the bounce sound is detected by the piezoelectric receiver, then the ECHO pin changes to High (5V) for a time equal to the time the wave took from when it was emitted to when it was detected, the time of the ECO pulse is measured by the microcontroller and thus the distance can be calculated to the object. Sensor performance is not affected by sunlight or black-colored material (although acoustically soft materials such as cloth or wool can be difficult to detect). All of this in a range of 2 to 450 cm._
  

  

   -   _Camera: The robot has an OV2640 camera that can be connected to the ESP32. Built by Omnivision back in 2005, the camera has a resolution of 2 megapixels and can capture images in color or grayscale. The camera is used to recognize objects, people or colors using artificial vision algorithms, and even when it was discontinued back in 2009, it is still remains popular today._  

  
  

   -   _Custom Chassis: The custom chassis was made almost from scratch, so we had to recreate some (if not all) of the pieces. We used cardboard and other easy-to-find materials to create most of the case. However, the chassis and other small parts that had to be very resistant were 3D printed. This allowed us to create a custom design that was both functional and aesthetically pleasing._  

  


   -   _1.5v AA Batteries: Guess I don't need to explain what a AA battery is. Previously we used a "peculiar" type of battery called "18650 rechargeable lithium batteries" because of the high energy comsumption, but in this remake of the robot, we didn't need to use them and it was more easy en the mayority of aspects, so we kept going with the traditional AA batteries._


  

---------------------------------------------------------------------------------------------------------------------------------------

HOW THE CAMERA WORKS

_The artificial vision algorithms that are used to recognize objects or colors are computer programs that process the images captured by the OV2640 camera and extract relevant information from them. For example, to recognize colors, We use an algorithm that converts color images to grayscale and then applies a red, green or blue color mask depending on the color we want to detect. Then, we calculate the percentage of pixels of the desired color in the image and compare it with a predefined threshold to determine whether or not there is presence of the color. The way to load the code would be to connect a Micro-USB cable to the USB port of the ESP32, start loading the code from the programming environment and wait for the process to finish._

OBJECTIVE OF THE ROBOTIC SOLUTION

The objective of this robotic solution model is to demonstrate the capabilities of the ESP32 chip and its possible applications in the field of educational robotics. The robot can perform different tasks such as following a line, avoiding obstacles, recognizing colors or expressing emotions.

--------------------------------------------------------------------------------------------------------------------------------------
HOW TO COMPILE THE CODE TO THE VEHICLE

ta ta ta que todavia no tengo el como

--------------------------------------------------------------------------------------------------------------------------------------
_Thank You._
