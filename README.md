# Embedded Systems Project on Intel 8051-based Pt-51 Microprocessor

This project involves programming the Intel 8051-based Pt-51 microprocessor in embedded C and assembly to implement two embedded systems: a Lab Management System and a password-protected locker. 

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- 
## Introduction

The project demonstrates the capabilities of the Intel 8051 microcontroller by implementing practical embedded systems. The Lab Management System is designed to manage and monitor various aspects of a laboratory, while the password-protected locker provides secure access control using a keypad interface.

## Features

### Lab Management System

- Monitoring lab equipment status.
- Logging usage data.
- Controlling access to equipment.
- Real-time alerts for anomalies.

### Password-Protected Locker

- Secure access control using a 4x4 keypad.
- Password entry and verification.
- Lock and unlock mechanism.
- Visual indicators for status (locked/unlocked).

## Hardware Requirements

- Intel 8051-based Pt-51 microprocessor.
- 4x4 keypad.
- LCD display.
- LEDs and buzzers for status indication.
- Relays or solenoids for the locking mechanism.
- Power supply and connecting wires.

## Software Requirements

- Keil uVision IDE or any other 8051 compiler.
- Programming software for uploading code to the 8051 microcontroller.
- Embedded C and Assembly knowledge.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/embedded-systems-8051.git
    ```
2. Open the project in Keil uVision IDE.
3. Connect the Pt-51 microcontroller to your computer using the appropriate programmer.
4. Compile and upload the code to the Pt-51 microcontroller.

## Usage

### Lab Management System

1. Power on the system.
2. Use the LCD display and keypad to navigate through the menu.
3. Monitor and control the lab equipment as needed.
4. Check the logs and status on the display.

### Password-Protected Locker

1. Power on the system.
2. Enter the password using the 4x4 keypad.
3. If the password is correct, the locker will unlock, and the LED will indicate the unlocked status.
4. If the password is incorrect, an alert will sound, and the LED will indicate a locked status.
5. The system will reset after a few seconds, ready for the next password entry.


