# Embedded Systems - a SUPAERO elective project, supervised by DISC

This repository contains the work I completed during an elective focused on low-level programming in C, applied to controlling a small robot and its embedded hardware.

## Objective : 
The goal of the elective was to learn how to interface directly with a robot’s components through C programming — writing low-level code to communicate with sensors, actuators, and output devices.
Through this project, I explored how software interacts with hardware at a detailed level, developing a solid understanding of embedded systems and real-time control.

## Features implemented :
During this course, I developed code to :
* Turn lights on and off (LED control) : `led_yellow.c` `led_yellow.h` `TP_D1.c` `TP_D2.c`
* Read and process data from various sensors (in this case, light sensor) : `TP_D3.c`
* Generate sound output
* Display text and information on a digital screen : `SH1106.c` `SH1106.h`
* Control motor functions to drive straight using feedback control : `TP_D4.c` `rouler_blanc.c`

The functions `projet_avance.c` and `projet.c` aimed to realize the project : have the robot follow a black line using its sensors, and stay on the loop without deviating. The project was a success.

## Technical focus :
* Language : C
* Concepts : memory management, hardware registers, I/O manipulation, feedback control
* Tools : embedded development environment provided during the course (microcontroller-specific)
* Emphasis on low-level programming and real-time system behavior

## Learning outcomes :
* Understanding of the way software interacts with hardware
* Gained practical experience in C programming for embedded systems
* Applied control theory to achieve stable and accurate robot motion
* Improved debugging and testing skills in a hardware-constrained environment.
