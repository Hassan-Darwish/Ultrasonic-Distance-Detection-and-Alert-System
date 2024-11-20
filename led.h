/*------------------------------------------------------------------------------
 *  Module      : LED Driver
 *  File        : led.h
 *  Description : Header file for the ATmega32 microcontroller LED driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef LED_H_          // Include guard to prevent multiple inclusions
#define LED_H_

/*------------------------------------------------------------------------------
 *  Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

#define LED_PORT_ID                        GPIO_PORTC  // Define the port for the LEDs

#define LED_RED_PIN                        GPIO_PIN0   // Define the pin for the red LED
#define LED_GREEN_PIN                      GPIO_PIN1   // Define the pin for the green LED
#define LED_BLUE_PIN                       GPIO_PIN2   // Define the pin for the blue LED

// Define logic levels for the LED states
#define LED_NEGATIVE                       LOGIC_HIGH   // Logic level for negative logic
#define LED_POSITIVE                       LOGIC_LOW    // Logic level for positive logic
#define LED_LOGIC                          LED_POSITIVE // Set default LED logic

/*------------------------------------------------------------------------------
 *  Data Types Declarations
 *----------------------------------------------------------------------------*/

// Enumeration for LED identifiers
typedef enum
{
    LED_RED,                             // Red LED
    LED_GREEN,                           // Green LED
    LED_BLUE                             // Blue LED
} LED_ID;

/*------------------------------------------------------------------------------
 *  Function Declarations
 *----------------------------------------------------------------------------*/

void LED_init(void);                     // Function to initialize the LEDs
void LED_on(LED_ID id);                  // Function to turn on a specific LED
void LED_off(LED_ID id);                 // Function to turn off a specific LED

#endif /* LED_H_ */                       // End of include guard
