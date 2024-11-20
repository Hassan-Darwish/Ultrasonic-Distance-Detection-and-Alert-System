/*------------------------------------------------------------------------------
 *  Module      : GPIO Driver
 *  File        : gpio.c
 *  Description : Source file for the ATmega32 microcontroller GPIO driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

#include <util/delay.h>
#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"

/* Global variables for edge count, pulse time, and flag indicating high pulse */
volatile uint8 g_edgeCount = 0;
volatile uint16 g_pulseTimeEnd = 0; /* Change to uint16 for 16-bit Timer1 */
volatile uint8 g_highFlag = 0;

/* ICU configuration: 8x clock prescaler, initially detecting rising edges */
ICU_ConfigType icuConfiguration = {F_CPU_8, RAISING};

void ULTRASONIC_init(void)
{
    /* Initialize the ICU with the specified configuration */
    ICU_init(&icuConfiguration);

    /* Set the callback function for edge detection */
    ICU_setCallBack(ULTRASONIC_edgeProcessing);

    /* Set the trigger pin as output */
    GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, GPIO_PIN_OUTPUT);
}

void ULTRASONIC_trigger(void)
{
    /* Send the 10us trigger pulse to the ultrasonic sensor */
    GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);

    _delay_us(10); /* Delay for 10 microseconds */

    /* End the trigger pulse */
    GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 ULTRASONIC_readDistance(void)
{
    /* Trigger the ultrasonic sensor */
    ULTRASONIC_trigger();

	/* Reset the high pulse flag */
	g_highFlag = 0;

    /* Wait until the high pulse flag is set */
    while (!g_highFlag);

    /* Calculate the distance based on the pulse width */
    uint16 distance = ((uint16)((float)g_pulseTimeEnd) / ULTRASONIC_CALCULATION_16MHZ_CONST);

    /* Return the calculated distance (adding 1 to account for rounding) */
    return distance + 1;
}

void ULTRASONIC_edgeProcessing(void)
{
    /* Increment the edge count each time this function is called */
    g_edgeCount++;

    if (g_edgeCount == 1) /* Rising edge detected */
    {
        /* Clear the timer value at the rising edge */
        ICU_clearTimerValue();

        /* Set the ICU to detect the falling edge */
        ICU_setEdgeDetectionType(FALLING);
    }
    else if (g_edgeCount == 2) /* Falling edge detected */
    {
        /* Capture the pulse width at the falling edge */
        g_pulseTimeEnd = ICU_getInputCaptureValue();

		/* Set the high pulse flag */
    	g_highFlag = 1;

        /* Reset the ICU to detect the rising edge for the next measurement */
        ICU_setEdgeDetectionType(RAISING);

        /* Reset the edge count to start a new cycle */
        g_edgeCount = 0;
    }
}
