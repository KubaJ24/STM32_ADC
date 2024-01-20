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

#define CONV_IN_PROG	!(ADC_SR_EOC)
#define ADC_START		ADC1->CR2 |= ADC_CR2_SWSTART;

void ADC_CONF(void);
void Delay(void);

void ADC_CONF(void){
	//GPIOA CLOCK ENABLE
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//ADC1 CLOCK ENABLE
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	//PA3 ANALOG INPUT MODE
	GPIOA->MODER |= GPIO_MODER_MODER3_0 | GPIO_MODER_MODER3_1;

	//ADC PRESCALLER -> 8
	//FREQUENCY OF PCLK2 / 8 = 16MHZ / 8 = 2MHZ
	ADC->CCR |= ADC_CCR_ADCPRE_0 | ADC_CCR_ADCPRE_1;
	//10 BIT RESOLUTION (0 - 1024)
	ADC1->CR1 |= ADC_CR1_RES_0;
	//EOC ENABLED (END OF CONVERSION)
	ADC1->CR2 |= ADC_CR2_EOCS;
	//RIGHT DATA ALIGNMENT
	ADC1->CR2 &= ~(ADC_CR2_ALIGN);
	//SCAN MODE
	ADC1->CR1 |= ADC_CR1_SCAN;
	//SEQUENCE OF ONE CHANNEL
	ADC1->SQR3 |= 4;
	//CONTINUOUS MODE
	ADC1->CR2 |= ADC_CR2_CONT;
	//28 CYCLES SAMPLE TIME
	ADC1->SMPR2 |= ADC_SMPR2_SMP4_1;

	//ADC ON
	ADC1->CR2 |= ADC_CR2_ADON;
}

void Delay(void){
	uint32_t time;
	for(time = 0; time < 99999; time++){}
}

#endif /* MAIN_H_ */
