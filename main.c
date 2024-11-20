#include "modules.h"
#include "main.h"

int main(void)
{
	/* Enable global interrupts by setting the I-bit in the status register (SREG) */
	SET_BIT(SREG,7);

    /* Initialize the modules */
    LCD_init();
    BUZZER_init();
    LED_init();
    ULTRASONIC_init();

    /* Variable to store the distance result from the ultrasonic sensor */
    uint16 distance_result = 0;

    /* Display static text "Distance=" at row 0, column 0 */
    LCD_displayStringRowColumn(0, 0, "Distance=");

    /* Clear the space where the distance value will be displayed */
    LCD_displayStringRowColumn(0, 10, "    ");

    /* Display static text "cm" for the unit of distance */
    LCD_displayStringRowColumn(0, 14, "cm");

    /* Infinite loop to keep reading and displaying the distance */
    for(;;)
    {
        /* Update the distance reading in every loop */
        distance_result = ULTRASONIC_readDistance();

        /* Move the cursor to the position where the distance value will be displayed */
        LCD_moveCursor(0, 10);
        LCD_integerToString(distance_result);  /* Ensure this function works properly */

        /* Handle formatting for distance display when the value is 3 digits */
        if(distance_result >= 100)
        {
            LCD_moveCursor(0, 10);
            LCD_integerToString(distance_result);  /* Ensure this function works properly */
        }
        /* Handle formatting for distance display when the value is 2 digits */
        else if (distance_result >= 10)
        {
            LCD_moveCursor(0, 10);
            LCD_integerToString(distance_result);  /* Ensure this function works properly */
            LCD_displayStringRowColumn(0,12,"  ");  /* Clear any remaining digits from previous display */
        }
        /* Handle formatting for distance display when the value is 1 digit */
        else
        {
            LCD_moveCursor(0, 10);
            LCD_integerToString(distance_result);  /* Ensure this function works properly */
            LCD_displayStringRowColumn(0,11,"  ");  /* Clear any remaining digits from previous display */
        }

        /* Process distance and take actions based on the reading */

        /* If the object is extremely near */
        if(distance_result <= ULTRASONIC_EXTREMELY_NEAR)
        {
            LCD_displayStringRowColumn(1, 5, "STOP");  /* Display "STOP" message */
            BUZZER_on();  /* Turn on the buzzer */
            LED_on(LED_RED);  /* Turn on the red LED */
            LED_on(LED_BLUE);  /* Turn on the blue LED */
            LED_on(LED_GREEN);  /* Turn on the green LED */
            _delay_ms(200);  /* Delay for 200ms */
            BUZZER_off();  /* Turn off the buzzer */
            LED_off(LED_RED);  /* Turn off the red LED */
            LED_off(LED_BLUE);  /* Turn off the blue LED */
            LED_off(LED_GREEN);  /* Turn off the green LED */
            _delay_ms(200);  /* Delay for 200ms */
        }
        /* If the object is near but not extremely near */
        else if(distance_result <= ULTRASONIC_NEAR && distance_result > ULTRASONIC_EXTREMELY_NEAR)
        {
            LCD_displayStringRowColumn(1, 5, "    ");  /* Clear the "STOP" message */
            BUZZER_off();  /* Turn off the buzzer */
            LED_on(LED_RED);  /* Turn on the red LED */
            LED_on(LED_BLUE);  /* Turn on the blue LED */
            LED_on(LED_GREEN);  /* Turn on the green LED */
        }
        /* If the object is at a moderate distance */
        else if(distance_result <= ULTRASONIC_MODERATE && distance_result > ULTRASONIC_NEAR)
        {
            LED_on(LED_RED);  /* Turn on the red LED */
            LED_off(LED_BLUE);  /* Turn off the blue LED */
            LED_on(LED_GREEN);  /* Turn on the green LED */
        }
        /* If the object is far */
        else if(distance_result <= ULTRASONIC_FAR && distance_result > ULTRASONIC_MODERATE)
        {
            LED_on(LED_RED);  /* Turn on the red LED */
            LED_off(LED_BLUE);  /* Turn off the blue LED */
            LED_off(LED_GREEN);  /* Turn off the green LED */
        }
        /* If the object is very far */
        else if(distance_result > ULTRASONIC_FAR)
        {
            LED_off(LED_RED);  /* Turn off the red LED */
            LED_off(LED_BLUE);  /* Turn off the blue LED */
            LED_off(LED_GREEN);  /* Turn off the green LED */
        }

        /* Add a small delay to give time for the LCD to update */
        _delay_ms(100);  /* Adjust the delay as needed */
    }
}
