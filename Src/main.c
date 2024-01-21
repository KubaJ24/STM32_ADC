/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "main.h"

// ADC 1/3 -> PA3
// ADC 1 CHANNEL 3

int main(void)
{

	initialise_monitor_handles();
	printf("Semihosting rozpoczety\n");
	ADC_CONF();

	while(1){
		ADC_START;
		//WAIT UNTIL CONVERSION ENDS
		while(CONV_IN_PROG){
			//WAIT
		}
		uint16_t result = ADC1->DR;
		ADC_SR_CLEAR;
		printf("%d\n", result);
		Delay();
	}
}
