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

/**************************************************************************************************************************************/

#endif /* INC_STM32G071XX_H_ */
