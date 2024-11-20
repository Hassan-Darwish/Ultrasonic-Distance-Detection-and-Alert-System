# Ultrasonic Distance Detection and Alert System

This project is an AVR microcontroller-based system designed to measure distances using an ultrasonic sensor and provide visual and auditory alerts based on predefined thresholds. It features real-time distance display on an LCD and dynamic signaling with LEDs and a buzzer.

---

## Features

### Distance Modes:
- **EXTREMELY_NEAR**: Activates all LEDs and buzzer with a flashing effect.
- **NEAR**: Activates all LEDs without the buzzer.
- **MODERATE**: Activates the red and green LEDs.
- **FAR**: Activates only the red LED.
- **VERY_FAR**: Turns off all LEDs and the buzzer.

### User Input Controls:
- Continuous distance measurement with real-time updates.
- Dynamic display adjustment for 1, 2, or 3-digit distances.

### Visual and Auditory Feedback:
- **LCD**: Displays the current distance in centimeters.
- **Buzzer**: Sounds an alert for close distances.
- **LEDs**:
  - RED LED for various distance ranges.
  - GREEN and BLUE LEDs for additional visual feedback.

---

## Components Required

### Microcontroller:
- ATmega32.

### Sensors:
- Ultrasonic sensor (e.g., HC-SR04).

### Display:
- 16x2 LCD.

### Outputs:
- **Buzzer** for audio feedback.
- **LEDs** (RED, GREEN, BLUE) for distance indication.

### Other:
- Supporting components for interfacing (e.g., resistors, capacitors).

---

## How It Works

### Initialization:
- Configures input/output pins for controlling the LCD, LEDs, and buzzer.
- Sets up interrupts and libraries for sensor interfacing.

### Modes of Operation:
1. **Distance Measurement**:
   - Continuously reads the distance from the ultrasonic sensor.
   - Displays the measured distance on the LCD.
2. **Alerting**:
   - Activates LEDs and the buzzer based on distance thresholds defined in `main.h`.

### Visual Feedback:
- The LCD displays "Distance= XX cm" with real-time updates.
- LEDs and buzzer provide additional feedback for user awareness.

---

## Code Overview

The code is written in C using AVR libraries:

### Timer and Interrupts:
- **Timer/Delays**: For stabilizing updates and visual signals.
- **Custom Functions**:
  - `LCD_displayStringRowColumn`: Displays text at specific LCD positions.
  - `LCD_integerToString`: Converts and displays integer values.

### Modules Used:
- **LCD Module**: Manages the LCD display.
- **Ultrasonic Module**: Handles distance measurement.
- **LED Module**: Controls LEDs based on distance ranges.
- **Buzzer Module**: Controls the buzzer for auditory alerts.

---

## Pin Configuration

| Port  | Pin  | Description                  |
|-------|------|------------------------------|
| PORTA | PA0  | Ultrasonic trigger pin       |
| PORTA | PA1  | Ultrasonic echo pin          |
| PORTC | PC0  | LCD control (RS)            |
| PORTC | PC1  | LCD control (RW)            |
| PORTC | PC2  | LCD control (EN)            |
| PORTD | PD0  | Buzzer output                |
| PORTD | PD4  | RED LED output               |
| PORTD | PD5  | BLUE LED output              |
| PORTD | PD6  | GREEN LED output             |

---

## How to Run

### Setup Hardware:
1. Assemble the circuit as per the pin configuration.
2. Connect the ultrasonic sensor, LCD, LEDs, and buzzer to the microcontroller.

### Load Code:
1. Use an AVR programmer to upload the code to the ATmega32 microcontroller.

### Power On:
1. The system will start measuring distances and displaying values on the LCD.
2. Observe LED and buzzer responses based on the distance thresholds.

---

## Circuit Diagram

Below is the Proteus simulation for the Ultrasonic Distance Detection and Alert System project:

<img width="1918" alt="Screenshot 2024-11-21 at 12 01 53 AM" src="https://github.com/user-attachments/assets/670bbfce-bd4e-4d27-a5c8-09e739cf21f3">

To explore or edit the circuit, open the included Proteus project file (`Proteus_Ultrasonic.pdsprj`) using Proteus Design Suite.

---

## Future Enhancements

- Replace the 16x2 LCD with an OLED or graphical LCD for better visualization.
- Add Bluetooth connectivity for distance monitoring on mobile devices.
- Expand to include multiple ultrasonic sensors for multi-directional distance measurement.

---

## License

This project is open-source under the MIT License. Feel free to modify and share.

---

## Author

Developed by Hassan Darwish.
