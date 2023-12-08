 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Zeyad El-banna
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include<util/delay.h>


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(const ADC_ReferenceVolatge ref_volt)
{
	uint8 temp_value = 0;
    uint16 adc_read = 0;
    float32 max_ref_volt ;
    switch(ref_volt)
    {
      case 1 :  max_ref_volt = 5 ;
               break ;
      case 3 : max_ref_volt = 2.56 ;
               break ;
      default : max_ref_volt = 5;
    }

	/* Read ADC channel where the temperature sensor is connected */
	adc_read =  ADC_readChannel(SENSOR_CHANNEL_ID);
    _delay_ms(5);
	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_read*SENSOR_MAX_TEMPERATURE*max_ref_volt)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

