/*------------------------------------------------------------------------------
 *  Module      : LED Driver
 *  File        : led.c
 *  Description : Source file for the ATmega32 microcontroller LED driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

#include "led.h"     // Header file for LED driver
#include "gpio.h"    // Header file for GPIO driver


/*------------------------------------------------------------------------------
 *  Functions and ISR Definitions
 *----------------------------------------------------------------------------*/

/*
 * Function to initialize the LED pins as output
 */
void LED_init(void)
{
    // Set LED pins as output
    GPIO_setupPinDirection(LED_PORT_ID, LED_RED_PIN, GPIO_PIN_OUTPUT);
    GPIO_setupPinDirection(LED_PORT_ID, LED_GREEN_PIN, GPIO_PIN_OUTPUT);
    GPIO_setupPinDirection(LED_PORT_ID, LED_BLUE_PIN, GPIO_PIN_OUTPUT);

#if LED_LOGIC == LED_POSITIVE
    // Turn off LEDs for positive logic
    GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_LOW);
    GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_LOW);
    GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_LOW);

#elif LED_LOGIC == LED_NEGATIVE
    // Turn on LEDs for negative logic
    GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_HIGH);
    GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_HIGH);
    GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_HIGH);

#endif
}

/*
 * Function to turn on the specified LED
 */
void LED_on(LED_ID id)
{
#if LED_LOGIC == LED_POSITIVE
    // Turn on LED based on the logic level
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_HIGH);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_HIGH);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_HIGH);
        break;
    }
#elif LED_LOGIC == LED_NEGATIVE
    // Turn off LED based on the logic level
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_LOW);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_LOW);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_LOW);
        break;
    }
#endif
}

/*
 * Function to turn off the specified LED
 */
void LED_off(LED_ID id)
{
#if LED_LOGIC == LED_POSITIVE
    // Turn off LED based on the logic level
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_LOW);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_LOW);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_LOW);
        break;
    }
#elif LED_LOGIC == LED_NEGATIVE
    // Turn on LED based on the logic level
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_PORT_ID, LED_RED_PIN, LOGIC_HIGH);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN, LOGIC_HIGH);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN, LOGIC_HIGH);
        break;
    }
#endif
}
