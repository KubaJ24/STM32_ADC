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
uint16_t result = 0;

int main(void)
{

	ADC_CONF();
	ADC_START();

	while(1){
		//WAIT UNTIL CONVERSION ENDS
		while(CONV_IN_PROG){
			//WAIT
		}
		result = ADC1->DR;
	}
}
