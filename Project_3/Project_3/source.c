/*
 * source.c
 *
 *  Created on: 13 Oct 2023
 *      Author: Zeyad El-banna
 */
#include"lcd.h"
#include"adc.h"
#include"DC_Motor.h"
#include"lm35_sensor.h"
#include<util/delay.h>
int main(void)
{
	/* decleration variable to hold temperature value */
	uint8 temp = 0 ;
	/* initializition of lcd and dc motor */
	LCD_init();
	DcMotor_Init();
	/* set configration of adc */
	ADC_ConfigType init_config = {internal_ref_volt , F_CPU_8};
	/* initialize adc */
	ADC_init(&init_config);
	while(1)
	{
		temp = LM35_getTemperature( init_config.ref_volt ) ;
		if(temp < 30)
		{
			LCD_moveCursor(0,4);
			LCD_displayString("FAN IS OFF");
			DcMotor_Rotate(stop_motor,0);

		}
		else if (temp >= 30 && temp < 60)
		{
			LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON ");
		    DcMotor_Rotate(clock_wise,25);
		    _delay_ms(5);
		}
		else if (temp >= 60 && temp < 90)
		{
			LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON");
		    DcMotor_Rotate(clock_wise,50);
		    _delay_ms(5);
		}
		else if (temp >= 90 && temp < 120)
		{
			LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON");
		    DcMotor_Rotate(clock_wise,75);
		    _delay_ms(5);
		}
		else if (temp >= 120)
		{
			LCD_moveCursor(0,4);
	        LCD_displayString("FAN IS ON");
	        DcMotor_Rotate(clock_wise,100);
	        _delay_ms(5);
		}
		LCD_moveCursor(1,3);
		LCD_displayString("TEMP = ");
		if(temp > 100)
		{
			LCD_intgerToString(temp);
		}
		else if (temp < 100)
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		LCD_displayString("C");
	}
	return 0 ;
}

