/*
 * stm32g071xx.h
 *
 *  Created on: 10-Oct-2019
 *      Author: Ananda Padmanabhan
 */

#ifndef INC_STM32G071XX_H_
#define INC_STM32G071XX_H_


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
#define PORT_GPIOA							0x50000000U
#define PORT_GPIOB							PORT_GPIOA+0x0400
#define PORT_GPIOC							PORT_GPIOA+0x0800
#define PORT_GPIOD							PORT_GPIOA+0x0C00
#define PORT_GPIOF							PORT_GPIOA+0x1400
/***************************************************************************************************************************************/


#endif /* INC_STM32G071XX_H_ */
