# Corrupt Core
## Overview

This device induces corruptions (glitches) inside of retro videogame console hardware. It is controlled with an AVR ATMEGA328p running the Arduino bootloader and using various Arduino libraries. It is designed to run off of 5V, a voltage level that can be commonly found inside of retro videogame consoles.

## Inducing a Corruption

To create a corruption, the corrupt core forces a bus line inside of the videogame console to always read as logic low. It does this by using a darlington transistor to sink the bus line to ground. This changes the data being transmitted inside the videogame console, and corrupts the game.

## User Input

A 4x4 matrix of 16 buttons are hooked up to the AVR to allow for general purpose user input. Users will be able to program each of these buttons to perform whatever kind of corruption they want.

Pinouts are also provided for 3 potentiometers to be hooked up to the analog input pins of the AVR. This enables users to create dials that can specify different levels of corruption for various groups of bus lines.

## Connecting to the Videogame Console

28 individually addressable pins are provided to the user to connect to various bus lines inside the videogame console. 

24 of these pins are addressed through a bank of 3 serial in - parallel out shift registers, and are designed for general purpose use.

4 pins are labeled as Quick Corrupt Pins. This is to address a problem with sensitive bus lines inside the videogame console. If a bus line is held low for too long, there's a possibility that it will always induce a crash. However, if a bus line can be pulled low very quickly (for only a couple of clock cycles of the game console) it can result in a much more stable and interesting corruption. These pins are hooked directly to the AVR and implement special code in order to induce a logic low pulse as fast as possible.

## Programming the Corrupt Core

The corrupt core is currently designed to hook up to an empty Arduino programmer for programming. The TX, RX, RESET, 5V, and GND lines are plugged into the appropriate pins on the programmer, and the program can be uploaded just like a regular Arduino.

I realize this is obtuse and a little wierd, and there will be a future revision of the Corrupt Core that works like an Arduino Shield. I'm building it like this as a prototype, and because it makes the corrupt core easy to integrate into the videogame console.
