# Automatic Vehicle Headlight System

## Overview
A smart headlight system using Arduino that automatically turns headlights on or off depending on surrounding light conditions, and adjusts brightness based on proximity to oncoming objects. Designed for road safety by preventing glare and ensuring visibility.

## Features
- Photoresistor to detect ambient light and toggle headlights
- Ultrasonic sensor to measure distance from oncoming vehicles
- PWM-controlled LED simulating headlight brightness adjustment
- Fully automated system with no manual controls

## Technologies
- Arduino UNO
- Photoresistor
- Ultrasonic distance sensor
- PWM-enabled LED
- Arduino IDE

## How It Works
1. A photoresistor constantly checks ambient lighting.
2. When it's dark, the system turns on the headlights.
3. An ultrasonic sensor measures distance to nearby objects.
4. If an object is within a close range, the system dims the light to reduce glare.
5. Brightness increases when the road is clear.

## Project Context
Developed as part of Engineering and Cyber Projects II at Houston Christian University. Focus was on simulating real-world automotive systems using embedded components.

## Setup
Upload the Arduino sketch via the Arduino IDE. Use a breadboard to wire:

- Photoresistor to analog input
- Ultrasonic sensor to digital I/O pins
- LED to PWM pin

Adjust sensitivity thresholds in the code as needed.
