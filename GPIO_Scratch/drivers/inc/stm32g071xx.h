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
/*************************************************RCC**************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR;						/*CLOCK CONTROL REGISTER				OFFSET	0x00*/
		_IO uint32_t ICSCR;						/*INTERNAL CLOCK SRC CALIB REG			OFFSET  0x04*/
		_IO uint32_t CFGR;						/*CLOCK CONFIG REGISTER					OFFSET	0x08*/
		_IO uint32_t PLL_CFGR;					/*PLL CONFIG REGISTER					OFFSET	0x0C*/
		_IO uint32_t RESERVED;					/*RESERVED								OFFSET	0x10*/
		_IO uint32_t RESERVED1;					/*RESERVED1								OFFSET	0x14*/
		_IO uint32_t CIER;						/*CLOCK INTERRUPT ENABLE REGISTER		OFFSET	0x18*/
		_IO uint32_t CIFR;						/*CLOCK INTERRUPT FLAG REGISTER			OFFSET	0x1C*/
		_IO uint32_t CICR;						/*CLOCK INTERRUPT CLEAR REGISTER		OFFSET	0x20*/
		_IO uint32_t IOPRSTR;					/*IOPORT RESET REGISTER					OFFSET	0x24*/
		_IO uint32_t AHBRSTR;					/*AHB PERIPHERAL RESET REGISTER			OFFSET  0x28*/
		_IO uint32_t APBRSTR1;					/*APB PERIPHERAL RESET REGISTER1		OFFSET  0x2C*/
		_IO uint32_t APBRSTR2;					/*APB PERIPHERAL RESET REGISTER2		OFFSET  0x30*/
		_IO uint32_t IOPENR;					/*IOPORT  ENABLE REGISTER				OFFSET  0x34*/
		_IO uint32_t AHBENR;					/*AHB PERIPHERAL ENABLE REGISTER		OFFSET  0x38*/
		_IO uint32_t APBENR1;					/*APB PERIPHERAL ENABLE REGISTER1		OFFSET  0x3C*/
		_IO uint32_t APBENR2;					/*APB PERIPHERAL ENABLE REGISTER2		OFFSET  0x40*/
		_IO uint32_t IOPSMENR;					/*IO PORT SLEEP MODE CLK EN REGISTER	OFFSET	0x44*/
		_IO uint32_t AHBSMENR;					/*AHB  SLEEP/STOP MODE CLK EN REGISTER	OFFSET	0x48*/
		_IO uint32_t APBSMENR1;					/*APB  SLEEP/STOP MODE CLK EN REGISTER	OFFSET	0x4C*/
		_IO uint32_t APBSMENR2;					/*APB  SLEEP/STOP MODE CLK EN REGISTER	OFFSET	0x50*/
		_IO uint32_t CCIPR;						/*INDEPENDENT CLOCK CONFIGURATION		OFFSET 	0x54*/
		_IO uint32_t RESERVED3;					/*RESERVED3								OFFSET	0x58*/
		_IO uint32_t BDCR;						/*RTC DOMAIN CONTROL REGISTER			OFFSET	0x5C*/
		_IO uint32_t CSR;						/*CONTROL STATUS REGISTER				OFFSET	0X60*/
		}RCC_REG_DEF;
/******************************************************************************************************************************************/
#define RCC									((RCC_REG_DEF*)RCC_BASE_ADDR)
/***************************************Peripheral Definitions **************************************************************************/

/**********************************************GPIO**************************************************************************************/
typedef struct
		{
	 	_IO uint32_t MODER;						/*MODE REGISTER 						OFFSET 0x00*/
	 	_IO uint32_t OTYPER;					/*OUTPUT TYPE REGISTER					OFFSET 0x04*/
	 	_IO uint32_t OSPEEDR;					/*OUTPUT SPEED REGISTER					OFFSET 0x08*/
	 	_IO uint32_t PUPDR;						/*PULLUP PULLDOWN REGISTER				OFFSET 0x0C*/
	 	_IO uint32_t IDR;						/*INPUT DATA REGISTER					OFFSET 0x10*/
	 	_IO uint32_t ODR;						/*OUTPUT DATA REGISTER					OFFSET 0x14*/
	 	_IO uint32_t BSRR;						/*BIT SET/RESET REGISTER				OFFSET 0x18*/
	 	_IO uint32_t LCKR;						/*CONFIGURATION LOCK REGISTER			OFFSET 0x1C*/
	 	_IO uint32_t AFRL;						/*ALTERNATE FUNCTION REGISTER LOW		OFFSET 0x20*/
	 	_IO uint32_t AFRH;						/*ALTERNATE FUNCTION REGISTER LOW		OFFSET 0x24*/
	 	_IO uint32_t BRR;						/*BIT RESET REGISTER					OFFSET 0x28*/
		}GPIO_REG_DEF;
/*******************************************************************************************************************************************/

#define GPIOA								 (GPIO_REG_DEF*)PORT_GPIOA
#define GPIOB								 (GPIO_REG_DEF*)PORT_GPIOB
#define GPIOC								 (GPIO_REG_DEF*)PORT_GPIOC
#define GPIOD								 (GPIO_REG_DEF*)PORT_GPIOD
#define GPIOF								 (GPIO_REG_DEF*)PORT_GPIOF


/************************************************SPI**************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 					OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2					OFFSET 0x04*/
		_IO uint32_t SR;						/*STATUS REGISTER						OFFSET 0x08*/
		_IO uint32_t DR;						/*DATA REGISTER							OFFSET 0x0C*/
		_IO uint32_t CRCPR;						/*CRC POLYNOMIAL REGISTER 				OFFSET 0x10*/
		_IO uint32_t RXCRCR;					/*RX CRC REGISTER						OFFSET 0x14*/
		_IO uint32_t TXCRCR;					/*TX CRC REGISTER						OFFSET 0x18*/
		_IO uint32_t I2SCFGR;					/*I2S CONFIGURATION REGISTER			OFFSET 0x1C*/
		_IO uint32_t I2SPR;						/*I2S PRESCALAR REGISTER				OFFSET 0x20*/
		}SPI_REF_DEF;
/****************************************************************************************************************************************/

#define	SPI1								(SPI_REF_DEF*)SPI1_BASE_ADDR
#define	SPI2								(SPI_REF_DEF*)SPI2_BASE_ADDR

/***********************************************I2C**************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 					OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2					OFFSET 0x04*/
		_IO uint32_t OAR1;						/*OWN ADDRESS REGISTER1					OFFSET 0x08*/
		_IO uint32_t OAR2;						/*OWN ADDRESS REGISTER2					OFFSET 0x0C*/
		_IO uint32_t TIMEINR;					/*TIMING REGISTER 						OFFSET 0x10*/
		_IO uint32_t TIMEOUTR;					/*TIMEOUT REGISTER						OFFSET 0x14*/
		_IO uint32_t ISR;						/*INTERRUPT STATUS REGISTER				OFFSET 0x18*/
		_IO uint32_t ICR;						/*INTERRUPT CLEAR REGISTER				OFFSET 0x1C*/
		_IO uint32_t PECR;						/*PACKET ERROR CHECKING REGISTER		OFFSET 0x20*/
		_IO uint32_t RXDR;						/*RX DATA REGISTER						OFFSET 0x24*/
		_IO uint32_t TXDR;						/*TX DATA REGISTER						OFFSET 0x28*/
		}I2C_REG_DEF;
/****************************************************************************************************************************************/

#define I2C1								(I2C_REG_DEF*)I2C1_BASE_ADDR
#define I2C2								(I2C_REG_DEF*)I2C2_BASE_ADDR

/**********************************************USART*************************************************************************************/
	typedef struct
		{
		_IO uint32_t CR1;						/*CONTROL REGISTER 1 					OFFSET 0x00*/
		_IO uint32_t CR2;						/*CONTROL REGISTER 2 					OFFSET 0x04*/
		_IO uint32_t CR3;						/*CONTROL REGISTER 3 					OFFSET 0x08*/
		_IO uint32_t BRR;						/*BAUD RATE REGISTER					OFFSET 0x0C*/
		_IO uint32_t GTPR;						/*GUARD TIME REGISTER					OFFSET 0x10*/
		_IO uint32_t RTOR;						/*RECIEVER TIMEOUT REGISTER				OFFSET 0x14*/
		_IO uint32_t RQR;						/*REQUEST REGISTER						OFFSET 0x18*/
		_IO uint32_t ISR;						/*INTERRUPT AND STATUS REGISTER			OFFSET 0x1C*/
		_IO uint32_t ICR;						/*INTERRUPT FLAG CLEAR REGISTER			OFFSET 0x20*/
		_IO uint32_t RDR;						/*RECIEVE DATA REGISTER					OFFSET 0x24*/
		_IO uint32_t TDR;						/*TRASNMIT DATA REGISTER				OFFSET 0x28*/
		_IO uint32_t PRESC;						/*PRESCALAR								OFFSET 0X2C*/
		}USART_REG_DEF;
/*****************************************************************************************************************************************/
#define USART1								(USART_REG_DEF*)USART1_BASE_ADDR
#define USART2								(USART_REG_DEF*)USART2_BASE_ADDR
#define USART3								(USART_REG_DEF*)USART3_BASE_ADDR
#define USART4								(USART_REG_DEF*)USART4_BASE_ADDR
/************************************************EXTI*************************************************************************************/
	typedef struct
		{
		_IO uint32_t RTSR;						/*RISING EDGE TRIGGER DECTECTION 		OFFSET	0x00*/
		_IO uint32_t FTSR1;						/*FALLING EDGE TRIGGER DECTECTION 		OFFSET	0x04*/
		_IO uint32_t SWIER1;					/*SOFTWARE INT EVENT REGISTER			OFFSET  0x08*/
		_IO uint32_t RPR1;						/*RISING EDGE PENDING REGISTER 			OFFSET  0x0C*/
		_IO uint32_t FPR1;						/*FALLING EDGE PENDING REGISTER 		OFFSET	0x10*/
		_IO uint32_t RESERVE1[19];				/*RESERVED1								OFFSET	0x14-0x5C*/
		_IO uint32_t EXTICR1;					/*INTERRUPT SELECTION REGISTER1			OFFSET  0x60*/
		_IO uint32_t EXTICR2;					/*INTERRUPT SELECTION REGISTER2			OFFSET  0x64*/
		_IO uint32_t EXTICR3;					/*INTERRUPT SELECTION REGISTER3			OFFSET  0x68*/
		_IO uint32_t EXTICR4;					/*INTERRUPT SELECTION REGISTER4			OFFSET  0x6C*/
		_IO uint32_t RESERVE2[4];				/*RESERVED2 							OFFSET 	0x70-0x7C*/
		_IO uint32_t IMR1;						/*WAKEUPWITH INTERRUPTMASK REGISTER1	OFFSET 	0x80*/
		_IO uint32_t EMR1;						/*WAKEUPWITH EVENTMASK REGISTER1		OFFSET 	0x84*/
		_IO uint32_t RESERVE3[2];				/*RESERVED3 							OFFSET	0x88-0x8*/
		_IO uint32_t IMR2;						/*WAKEUPWITH INTERRUPTMASK REGISTER2	OFFSET 	0x90*/
		_IO uint32_t EMR2;						/*WAKEUPWITH EVENTMASK REGISTER2		OFFSET 	0x94*/
		}EXTI_REG_DEF;
/****************************************************************************************************************************************/
#define EXTI								(EXTI_REG_DEF*)EXTI_BASE_ADDR

/************************************************SYSCGR**********************************************************************************/
	typedef struct
		{
		_IO uint32_t CFGR1;						/*CONFIGURATION REGISTER1				OFFSET	0x00*/
		_IO uint32_t RESERVED[5];				/*RESERVED								OFFSET	0x04-0x17*/
		_IO uint32_t CFGR2;						/*CONFIGURATION REGISTER2				OFFSET	0x18*/
		_IO uint32_t RESERVED2[25];				/*RESERVED								OFFSET	0x20-0x7C*/
		_IO uint32_t ITLINE0;					/*INTERRUPT LINE STATUS REGISTER0		OFFSET	0x80*/
		_IO uint32_t ITLINE1;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x84*/
		_IO uint32_t ITLINE2;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x88*/
		_IO uint32_t ITLINE3;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x8C*/
		_IO uint32_t ITLINE4;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x90*/
		_IO uint32_t ITLINE5;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x94*/
		_IO uint32_t ITLINE6;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x98*/
		_IO uint32_t ITLINE7;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0x9C*/
		_IO uint32_t ITLINE8;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xA0*/
		_IO uint32_t ITLINE9;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xA4*/
		_IO uint32_t ITLINE10;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xA8*/
		_IO uint32_t ITLINE11;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xAC*/
		_IO uint32_t ITLINE12;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xB0*/
		_IO uint32_t ITLINE13;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xB4*/
		_IO uint32_t ITLINE14;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xB8*/
		_IO uint32_t ITLINE15;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xBC*/
		_IO uint32_t ITLINE16;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xC0*/
		_IO uint32_t ITLINE17;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xC4*/
		_IO uint32_t ITLINE18;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xC8*/
		_IO uint32_t ITLINE19;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xCC*/
		_IO uint32_t ITLINE20;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xD0*/
		_IO uint32_t ITLINE21;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xD4*/
		_IO uint32_t ITLINE22; 					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xD8*/
		_IO uint32_t ITLINE23;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xDC*/
		_IO uint32_t ITLINE24;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xE0*/
		_IO uint32_t ITLINE25;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xE4*/
		_IO uint32_t ITLINE26;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xE8*/
		_IO uint32_t ITLINE27;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xEC*/
		_IO uint32_t ITLINE28;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xF0*/
		_IO uint32_t ITLINE29;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xF4*/
		_IO uint32_t ITLINE30;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xF8*/
		_IO uint32_t ITLINE31;					/*INTERRUPT LINE STATUS REGISTER1		OFFSET	0xFC*/
		}SYS_CFGR_REG_DEF;
/****************************************************************************************************************************************/
#define SYS_CFGR							(SYS_CFGR_REG_DEF*)SYS_CFG_BASE_ADDR



/******************************************************CLOCK EN/DIS FOR PERIPHERALS*******************************************************************/
void GPIOA_CLK_EN()					{RCC->IOPENR|=(1<<0);}
void GPIOB_CLK_EN()					{RCC->IOPENR|=(1<<1);}
void GPIOC_CLK_EN()					{RCC->IOPENR|=(1<<2);}
void GPIOD_CLK_EN()					{RCC->IOPENR|=(1<<3);}
void GPIOF_CLK_EN()					{RCC->IOPENR|=(1<<5);}

void GPIOA_CLK_DIS()				{RCC->IOPENR&=~(1<<0);}
void GPIOB_CLK_DIS()				{RCC->IOPENR&=~(1<<1);}
void GPIOC_CLK_DIS()				{RCC->IOPENR&=~(1<<2);}
void GPIOD_CLK_DIS()				{RCC->IOPENR&=~(1<<3);}
void GPIOF_CLK_DIS()				{RCC->IOPENR&=~(1<<5);}


void SPI1_CLK_EN()					{RCC->APBENR2|=(1<<12);}
void SPI2_CLK_EN()					{RCC->APBENR1|=(1<<14);}

void SPI1_CLK_DIS()					{RCC->APBENR2&=~(1<<12);}
void SPI2_CLK_DIS()					{RCC->APBENR1&=~(1<<14);}

void USART1_CLK_EN()				{RCC->APBENR2|=(1<<14);}
void USART2_CLK_EN()				{RCC->APBENR1|=(1<<17);}
void USART3_CLK_EN()				{RCC->APBENR1|=(1<<18);}
void USART4_CLK_EN()				{RCC->APBENR1|=(1<<19);}
void LPUART_CLK_EN()				{RCC->APBENR1|=(1<<20);}

void USART1_CLK_DIS()				{RCC->APBENR2&=~(1<<14);}
void USART2_CLK_DIS()				{RCC->APBENR1&=~(1<<17);}
void USART3_CLK_DIS()				{RCC->APBENR1&=~(1<<18);}
void USART4_CLK_DIS()				{RCC->APBENR1&=~(1<<19);}
void LPUART_CLK_DIS()				{RCC->APBENR1&=~(1<<20);}

void I2C1_CLK_EN()					{RCC->APBENR1|=(1<<21);}
void I2C2_CLK_EN()					{RCC->APBENR1|=(1<<22);}

void I2C1_CLK_DIS()					{RCC->APBENR1&=~(1<<21);}
void I2C2_CLK_DIS()					{RCC->APBENR1&=~(1<<22);}


void SYS_CFGR_CLK_EN()				{RCC->APBENR2|=(1<<0);}
void SYS_CFGR_CLK_DIS()				{RCC->APBENR2&=~(1<<0);}
/******************************************************************************************************************************************/
#endif /* INC_STM32G071XX_H_ */
