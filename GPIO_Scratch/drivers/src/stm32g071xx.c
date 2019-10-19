/*
 * stm32g071xx.c
 *
 *  Created on: 19-Oct-2019
 *      Author: Ananda Padmanabhan
 */

#include "stm32g071xx.h"

/******************************************************CLOCK EN/DIS FOR PERIPHERALS(parameter macro didn't work, so I wrote functions)*******************************************************************/
void GPIOA_CLK_EN()					{RCC->IOPENR|=(1<<0);}					/*Enabling peripheral clock of GPIOA*/
void GPIOB_CLK_EN()					{RCC->IOPENR|=(1<<1);}					/*Enabling peripheral clock of GPIOB*/
void GPIOC_CLK_EN()					{RCC->IOPENR|=(1<<2);}					/*Enabling peripheral clock of GPIOC*/
void GPIOD_CLK_EN()					{RCC->IOPENR|=(1<<3);}					/*Enabling peripheral clock of GPIOD*/
void GPIOF_CLK_EN()					{RCC->IOPENR|=(1<<5);}					/*Enabling peripheral clock of GPIOF*/

void GPIOA_CLK_DIS()				{RCC->IOPENR&=~(1<<0);}					/*Disabling peripheral clock of GPIOA*/
void GPIOB_CLK_DIS()				{RCC->IOPENR&=~(1<<1);}					/*Disabling peripheral clock of GPIOB*/
void GPIOC_CLK_DIS()				{RCC->IOPENR&=~(1<<2);}					/*Disabling peripheral clock of GPIOC*/
void GPIOD_CLK_DIS()				{RCC->IOPENR&=~(1<<3);}					/*Disabling peripheral clock of GPIOD*/
void GPIOF_CLK_DIS()				{RCC->IOPENR&=~(1<<5);}					/*Disabling peripheral clock of GPIOF*/

void GPIOA_RESET()					{do{RCC->IOPRSTR|=(1<<0);RCC->IOPRSTR&=~(1<<0);}while(0);}					/*Rests GPIOPORTA*/
void GPIOB_RESET()					{do{RCC->IOPRSTR|=(1<<1);RCC->IOPRSTR&=~(1<<1);}while(0);}					/*Rests GPIOPORTB*/
void GPIOC_RESET()					{do{RCC->IOPRSTR|=(1<<2);RCC->IOPRSTR&=~(1<<2);}while(0);}					/*Rests GPIOPORTC*/
void GPIOD_RESET()					{do{RCC->IOPRSTR|=(1<<3);RCC->IOPRSTR&=~(1<<3);}while(0);}					/*Rests GPIOPORTD*/
void GPIOF_RESET()					{do{RCC->IOPRSTR|=(1<<5);RCC->IOPRSTR&=~(1<<5);}while(0);}					/*Rests GPIOPORTF*/

void SPI1_CLK_EN()					{RCC->APBENR2|=(1<<12);}				/*Enabling peripheral clock of SPI1*/
void SPI2_CLK_EN()					{RCC->APBENR1|=(1<<14);}				/*Enabling peripheral clock of SPI2*/

void SPI1_CLK_DIS()					{RCC->APBENR2&=~(1<<12);}				/*Disabling peripheral clock of SPI1*/
void SPI2_CLK_DIS()					{RCC->APBENR1&=~(1<<14);}				/*Disabling peripheral clock of SPI2*/

void USART1_CLK_EN()				{RCC->APBENR2|=(1<<14);}				/*Enabling peripheral clock of USART1*/
void USART2_CLK_EN()				{RCC->APBENR1|=(1<<17);}				/*Enabling peripheral clock of USART2*/
void USART3_CLK_EN()				{RCC->APBENR1|=(1<<18);}				/*Enabling peripheral clock of USART3*/
void USART4_CLK_EN()				{RCC->APBENR1|=(1<<19);}				/*Enabling peripheral clock of USART4*/
void LPUART_CLK_EN()				{RCC->APBENR1|=(1<<20);}				/*Enabling peripheral clock of LPUART*/

void USART1_CLK_DIS()				{RCC->APBENR2&=~(1<<14);}				/*Disabling peripheral clock of USART1*/
void USART2_CLK_DIS()				{RCC->APBENR1&=~(1<<17);}				/*Disabling peripheral clock of USART2*/
void USART3_CLK_DIS()				{RCC->APBENR1&=~(1<<18);}				/*Disabling peripheral clock of USART3*/
void USART4_CLK_DIS()				{RCC->APBENR1&=~(1<<19);}				/*Disabling peripheral clock of USART4*/
void LPUART_CLK_DIS()				{RCC->APBENR1&=~(1<<20);}				/*Disabling peripheral clock of LPUART*/

void I2C1_CLK_EN()					{RCC->APBENR1|=(1<<21);}				/*Enabling peripheral clock of I2C1*/
void I2C2_CLK_EN()					{RCC->APBENR1|=(1<<22);}				/*Enabling peripheral clock of I2C2*/

void I2C1_CLK_DIS()					{RCC->APBENR1&=~(1<<21);}				/*Disabling peripheral clock of I2C1*/
void I2C2_CLK_DIS()					{RCC->APBENR1&=~(1<<22);}				/*Disabling peripheral clock of I2C2*/


void SYS_CFGR_CLK_EN()				{RCC->APBENR2|=(1<<0);}					/*Enabling peripheral clock of SYSCFGR*/
void SYS_CFGR_CLK_DIS()				{RCC->APBENR2&=~(1<<0);}				/*Disabling peripheral clock of SYSCFGR*/
