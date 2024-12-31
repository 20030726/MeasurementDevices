# KY-040 Rotary Encoder with Servo Motor Control

This document explains how to use the KY-040 rotary encoder to control a servo motor with an Arduino. The servo's position will be adjusted based on the encoder's rotation, and pressing the encoder button will reset the servo position.

---

## 1. Components
- **KY-040 Rotary Encoder**
- **Servo Motor**
- **Arduino Uno (or compatible board)**
- **Jumper Wires**
- **Breadboard (optional)**

---

## 2. Wiring
Connect the KY-040 rotary encoder and servo motor to the Arduino as follows:

| **KY-040 Pin**   | **Arduino Pin** | **Description**      |
|-------------------|-----------------|----------------------|
| CLK (Clock)       | 7               | Rotary encoder clock |
| DT (Data)         | 6               | Rotary encoder data  |
| SW (Switch)       | 5               | Button input         |
| + (VCC)           | 5V              | Power supply         |
| GND (Ground)      | GND             | Ground               |

| **Servo Pin**     | **Arduino Pin** | **Description**      |
|-------------------|-----------------|----------------------|
| Signal            | 9               | Servo control signal |
| VCC               | External 5V     | Servo power          |
| GND               | GND             | Servo ground         |

**Note:** Use an external power supply for the servo motor to avoid overloading the Arduino.
