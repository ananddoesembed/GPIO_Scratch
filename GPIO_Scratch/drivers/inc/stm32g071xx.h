/*
 * stm32g071xx.h
 *
 *  Created on: 10-Oct-2019
 *      Author: Ananda Padmanabhan
 */

#ifndef INC_STM32G071XX_H_
#define INC_STM32G071XX_H_

#include <stdint.h>

#define _IO volatile

/************************************Controller memories ******************************************************************************/
#define FLASH_BASE_ADDR						0x08000000U  /*If a number is written without U compiler will treat it as a signed number*/
#define SRAM_BASE_ADDR						0x20000000U
#define ROM_BASE_ADDR						0x1FFF0000U	 /*ROM is also called system memory which is in the section of FLASH*/
/**************************************************************************************************************************************/

/*********************************************Controller busses************************************************************************/
#define IOPORT_BASE_ADDR					0x50000000U
#define AHB_BASE_ADDR						0x40020000U
#define APB_BASE_ADDR						0x40000000U
/**************************************************************************************************************************************/

/*********************************************IOPORTS***********************************************************************************/
#define PORT_GPIOA							IOPORT_BASE_ADDR
#define PORT_GPIOB							IOPORT_BASE_ADDR+0x0400
#define PORT_GPIOC							IOPORT_BASE_ADDR+0x0800
#define PORT_GPIOD							IOPORT_BASE_ADDR+0x0C00
#define PORT_GPIOF							IOPORT_BASE_ADDR+0x1400
/***************************************************************************************************************************************/

/**************************************Communication Peripherals************************************************************************/
#define SPI1_BASE_ADDR						APB_BASE_ADDR+0x13000
#define SPI2_BASE_ADDR						APB_BASE_ADDR+0x3800
#define LPUART1_BASE_ADDR					APB_BASE_ADDR+0x8000
#define USART1_BASE_ADDR					APB_BASE_ADDR+0x13800
#define USART2_BASE_ADDR					APB_BASE_ADDR+0x4400
#define USART3_BASE_ADDR					APB_BASE_ADDR+0x4800
#define USART4_BASE_ADDR					APB_BASE_ADDR+0x4C00
#define I2C1_BASE_ADDR						APB_BASE_ADDR+0x5400
#define I2C2_BASE_ADDR						APB_BASE_ADDR+0x5800
#define SYS_CFG_BASE_ADDR					APB_BASE_ADDR+0x10000
/***************************************************************************************************************************************/

/****************************************EXTENDED INTERRUPRT****************************************************************************/
#define EXTI_BASE_ADDR						AHB_BASE_ADDR+0x1800
/***************************************************************************************************************************************/

/****************************************RESET AND CLOCK CONTROL****************************************************************************/
#define RCC_BASE_ADDR						AHB_BASE_ADDR+0x1000
/***************************************************************************************************************************************/

/***************************************Peripheral Definitions **************************************************************************/

/**********************************************GPIO**************************************************************************************/
typedef struct
		{
	 	_IO uint32_t MODER;						/*MODE REGISTER 					OFFSET 0x00*/
	 	_IO uint32_t OTYPER;					/*OUTPUT TYPE REGISTER				OFFSET 0x04*/
	 	_IO uint32_t OSPEEDR;					/*OUTPUT SPEED REGISTER				OFFSET 0x08*/
	 	_IO uint32_t PUPDR;						/*PULLUP PULLDOWN REGISTER			OFFSET 0x0C*/
	 	_IO uint32_t IDR;						/*INPUT DATA REGISTER				OFFSET 0x10*/
	 	_IO uint32_t ODR;						/*OUTPUT DATA REGISTER				OFFSET 0x14*/
	 	_IO uint32_t BSRR;						/*BIT SET/RESET REGISTER			OFFSET 0x18*/
	 	_IO uint32_t LCKR;						/*CONFIGURATION LOCK REGISTER		OFFSET 0x1C*/
	 	_IO uint32_t AFRL;						/*ALTERNATE FUNCTION REGISTER LOW	OFFSET 0x20*/
	 	_IO uint32_t AFRH;						/*ALTERNATE FUNCTION REGISTER LOW	OFFSET 0x24*/
	 	_IO uint32_t BRR;						/*BIT RESET REGISTER				OFFSET 0x28*/
		}GPIO_REG_DEF;
/*******************************************************************************************************************************************/
/*************************************************SPI***************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 				OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2				OFFSET 0x04*/
		_IO uint32_t SR;						/*STATUS REGISTER					OFFSET 0x08*/
		_IO uint32_t DR;						/*DATA REGISTER						OFFSET 0x0C*/
		_IO uint32_t CRCPR;						/*CRC POLYNOMIAL REGISTER 			OFFSET 0x10*/
		_IO uint32_t RXCRCR;					/*RX CRC REGISTER					OFFSET 0x14*/
		_IO uint32_t TXCRCR;					/*TX CRC REGISTER					OFFSET 0x18*/
		_IO uint32_t I2SCFGR;					/*I2S CONFIGURATION REGISTER		OFFSET 0x1C*/
		_IO uint32_t I2SPR;						/*I2S PRESCALAR REGISTER			OFFSET 0x20*/
		}SPI_REF_DEF;
/******************************************************************************************************************************************/
/************************************************I2C*************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 				OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2				OFFSET 0x04*/
		_IO uint32_t OAR1;						/*OWN ADDRESS REGISTER1				OFFSET 0x08*/
		_IO uint32_t OAR2;						/*OWN ADDRESS REGISTER2				OFFSET 0x0C*/
		_IO uint32_t TIMEINR;					/*TIMING REGISTER 					OFFSET 0x10*/
		_IO uint32_t TIMEOUTR;					/*TIMEOUT REGISTER					OFFSET 0x14*/
		_IO uint32_t ISR;						/*INTERRUPT STATUS REGISTER			OFFSET 0x18*/
		_IO uint32_t ICR;						/*INTERRUPT CLEAR REGISTER			OFFSET 0x1C*/
		_IO uint32_t PECR;						/*PACKET ERROR CHECKING REGISTER	OFFSET 0x20*/
		_IO uint32_t RXDR;						/*RX DATA REGISTER					OFFSET 0x24*/
		_IO uint32_t TXDR;						/*TX DATA REGISTER					OFFSET 0x28*/
		}I2C_REG_DEF;
/******************************************************************************************************************************************/
/***********************************************USART**************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 				OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2 				OFFSET 0x04*/
		_IO uint32_t CR3;						/*CONTROL REGISTER 3 				OFFSET 0x08*/
		_IO uint32_t BRR;						/*BAUD RATE REGISTER				OFFSET 0x0C*/
		_IO uint32_t GTPR;						/*GUARD TIME REGISTER				OFFSET 0x10*/
		_IO uint32_t RTOR;						/*RECIEVER TIMEOUT REGISTER			OFFSET 0x14*/
		_IO uint32_t RQR;						/*REQUEST REGISTER					OFFSET 0x18*/
		_IO uint32_t ISR;						/*INTERRUPT AND STATUS REGISTER		OFFSET 0x1C*/
		_IO uint32_t ICR;						/*INTERRUPT FLAG CLEAR REGISTER		OFFSET 0x20*/
		_IO uint32_t RDR;						/*RECIEVE DATA REGISTER				OFFSET 0x24*/
		_IO uint32_t TDR;						/*TRASNMIT DATA REGISTER			OFFSET 0x28*/
		_IO uint32_t PRESC;						/*PRESCALAR							OFFSET 0X2C*/
		}USART_REG_DEF;
/*******************************************************************************************************************************************/
/*************************************************EXTI**************************************************************************************/
	typedef struct
		{
		_IO uint32_t RTSR;						/*RISING EDGE TRIGGER DECTECTION 	OFFSET	0x00*/
		_IO uint32_t FTSR1;						/*FALLING EDGE TRIGGER DECTECTION 	OFFSET	0x04*/
		_IO uint32_t SWIER1;					/*SOFTWARE INT EVENT REGISTER		OFFSET  0x08*/
		_IO uint32_t RPR1;						/*RISING EDGE PENDING REGISTER 		OFFSET  0x0C*/
		_IO uint32_t FPR1;						/*FALLING EDGE PENDING REGISTER 	OFFSET	0x10*/
		_IO uint32_t RESERVE1[19];				/*RESERVED1							OFFSET	0x14-0x5C*/
		_IO uint32_t EXTICR1;					/*INTERRUPT SELECTION REGISTER1		OFFSET  0x60*/
		_IO uint32_t EXTICR2;					/*INTERRUPT SELECTION REGISTER2		OFFSET  0x64*/
		_IO uint32_t EXTICR3;					/*INTERRUPT SELECTION REGISTER3		OFFSET  0x68*/
		_IO uint32_t EXTICR4;					/*INTERRUPT SELECTION REGISTER4		OFFSET  0x6C*/
		_IO uint32_t RESERVE2[4];				/*RESERVED2 						OFFSET 	0x70-0x7C*/
		_IO uint32_t IMR1;						/*WAKEUPWITH INTERRUPTMASK REGISTER1OFFSET 	0x80*/
		_IO uint32_t EMR1;						/*WAKEUPWITH EVENTMASK REGISTER1		OFFSET 	0x84*/
		_IO uint32_t RESERVE3[2];				/*RESERVED3 						OFFSET	0x88-0x8C*/
		_IO uint32_t IMR2;						/*WAKEUPWITH INTERRUPTMASK REGISTER2OFFSET 	0x90*/
		_IO uint32_t EMR2;						/**WAKEUPWITH EVENTMASK REGISTER2	OFFSET 	0x94*/
		};
/******************************************************************************************************************************************/
/*************************************************RCC**************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR;						/*CLOCK CONTROL REGISTER			OFFSET	0x00*/
		_IO uint32_t ICSCR;						/**/
		_IO uint32_t CFGR;
		_IO uint32_t PLL_CFGR;
		_IO uint32_t RESERVED;
		_IO uint32_t RESERVED;
		_IO uint32_t CIER;
		_IO uint32_t CIFR;
		_IO uint32_t CICR;
		_IO uint32_t IOPRSTR;
		_IO uint32_t AHBRSTR;
		_IO uint32_t APBRSTR1;
		_IO uint32_t APBRSTR2;
		_IO uint32_t APBRSTR2;
		_IO uint32_t IOPENR;
		_IO uint32_t AHBENR;
		_IO uint32_t APBENR1;
		_IO uint32_t APBENR2;
		_IO uint32_t IOPSMENR;
		_IO uint32_t AHBSMENR;
		_IO uint32_t APBSMENR1;
		_IO uint32_t APBSMENR2;
		_IO uint32_t CCIPR;
		_IO uint32_t BDCR;
		_IO uint32_t CSR;
		};
/******************************************************************************************************************************************/
/*************************************************SYSCGR***********************************************************************************/

/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
#endif /* INC_STM32G071XX_H_ */
