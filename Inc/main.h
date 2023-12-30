/*
 * main.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ahadz
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include "stm32f746xx.h"

void ADC_CONF(void);

void ADC_CONF(void){
	//GPIOA CLOCK ENABLE
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//ADC1 CLOCK ENABLE
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	//ADC PRESCALLER -> 8
	//FREQUENCY OF PCLK2 / 8 = 16MHZ / 8 = 2MHZ
	ADC->CCR |= ADC_CCR_ADCPRE_0 | ADC_CCR_ADCPRE_1;
	//SCAN MODE
	ADC1->CR1 |= ADC_CR1_SCAN;
	//10 BIT RESOLUTION (0 - 1024)
	ADC1->CR1 |= ADC_CR1_RES_0;
}

#endif /* MAIN_H_ */
