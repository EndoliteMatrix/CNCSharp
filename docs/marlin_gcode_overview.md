# Marlin G-code Overview

This document summarizes many of the common G-code (`Gxx` commands) and M-code (`Mxx` commands) supported by the Marlin firmware. These commands control movement, units, homing, leveling, temperature, fan and power functions, and file operations on 3D printers and CNC devices. For the complete list see the official Marlin documentation.

## Linear and arc motion
- **G0/G1** – Linear move: command the machine to move in a straight line to the specified X, Y, Z (and E for extrusion) coordinates, optionally with a feed rate (F)【236066925561375†L86-L139】.
- **G2/G3** – Arc move: command a clockwise or counter‑clockwise arc to a target with specified I and J offsets【236066925561375†L86-L139】.
- **G4** – Dwell: pause the machine for a specified number of milliseconds【236066925561375†L86-L139】.

## Homing and bed leveling
- **G28** – Auto home: move axes to their home positions【236066925561375†L86-L139】.
- **G29** – Bed leveling: run a bed leveling routine (e.g., ABL, UBL)【236066925561375†L86-L139】.
- **G30** – Single probe: probe the bed at the current XY position【236066925561375†L86-L139】.

## Units and positioning
- **G20** – Set units to inches【236066925561375†L86-L139】.
- **G21** – Set units to millimeters (the default)【236066925561375†L86-L139】.
- **G90** – Use absolute positioning for X/Y/Z/E axes【236066925561375†L86-L139】.
- **G91** – Use relative positioning for X/Y/Z/E axes【236066925561375†L86-L139】.
- **G92** – Set current position without moving the machine【236066925561375†L86-L139】.

## Temperature control
- **M104** – Set hotend temperature (non‑blocking)【236066925561375†L86-L139】.
- **M109** – Set hotend temperature and wait for it to reach the target【236066925561375†L86-L139】.
- **M140** – Set bed temperature (non‑blocking)【236066925561375†L86-L139】.
- **M190** – Set bed temperature and wait for it to reach the target【236066925561375†L86-L139】.
- **M105** – Report current temperatures【236066925561375†L86-L139】.

## Motor and fan control
- **M17** – Enable steppers (motors)【236066925561375†L86-L139】.
- **M18/M84** – Disable steppers after an optional idle time【236066925561375†L86-L139】.
- **M106** – Set fan speed (PWM)【236066925561375†L86-L139】.
- **M107** – Turn off fans【236066925561375†L86-L139】.
- **M80** – Turn on the power supply (if controllable)【236066925561375†L86-L139】.
- **M81** – Turn off the power supply【236066925561375†L86-L139】.

## Filament and extrusion
- **M600** – Filament change: pause and wait for the user to change filament.
- **G10/G11** – Retract and recover (if firmware retract is enabled).

## Communication and file operations
- **M20** – List files on the SD card【236066925561375†L86-L139】.
- **M23** – Select a file from the SD card【236066925561375†L86-L139】.
- **M24** – Start/resume SD card print【236066925561375†L86-L139】.
- **M25** – Pause SD card print【236066925561375†L86-L139】.
- **M26** – Set SD print file position【236066925561375†L86-L139】.
- **M27** – Report SD print status【236066925561375†L86-L139】.
- **M28** – Begin writing to SD card【236066925561375†L86-L139】.
- **M29** – Stop writing to SD card【236066925561375†L86-L139】.
- **M30–M33** – Miscellaneous SD card operations such as delete file, open file, list long directory names【236066925561375†L86-L139】.

## Notes
- Marlin also implements many other `M` codes for advanced features like EEPROM storage, stepper tuning, filament sensors, servo control, thermal protection, and more.
- This overview is intended to capture the broad categories and the most frequently used commands. See the Marlin G‑code reference for complete details【236066925561375†L86-L139】.
