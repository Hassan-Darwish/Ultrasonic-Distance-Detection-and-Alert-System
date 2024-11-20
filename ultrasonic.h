/*------------------------------------------------------------------------------
 *  Module      : ULTRASONIC SENSOR Driver
 *  File        : ultrasonic.h
 *  Description : Header file for the ultrasonic sensor driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

#include "stdtypes.h"

/*------------------------------------------------------------------------------
 *  Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

/* Define the port and pin for the ultrasonic sensor trigger signal */
#define ULTRASONIC_TRIGGER_PORT_ID     GPIO_PORTD
#define ULTRASONIC_TRIGGER_PIN_ID      GPIO_PIN7

/* Define the port and pin for the ultrasonic sensor echo signal */
#define ULTRASONIC_ECHO_PORT_ID        GPIO_PORTD
#define ULTRASONIC_ECHO_PIN_ID         GPIO_PIN6

/* Constant for distance calculation, assuming 16MHz clock */
#define ULTRASONIC_CALCULATION_16MHZ_CONST  117.6

/*------------------------------------------------------------------------------
 *  Function Prototypes
 *----------------------------------------------------------------------------*/

/* Function to initialize the ultrasonic sensor */
void ULTRASONIC_init(void);

/* Function to trigger the ultrasonic sensor */
void ULTRASONIC_trigger(void);

/* Function to read the distance measured by the ultrasonic sensor */
uint16 ULTRASONIC_readDistance(void);

/* Callback function for edge detection in the ultrasonic sensor */
void ULTRASONIC_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
