/*
 * stm32g071xx_gpio.c
 *
 *  Created on: 17-Oct-2019
 *      Author: Ananda Padmanabhan
 */
#include "stm32g071xx_gpio.h"


void GPIO_Init(Gpio_Handle *PGpiox);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_Deinit(GPIO_REG_DEF *GPIOx);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_Peri_clk_ctrl(GPIO_REG_DEF *GPIOx,uint8_t EnDi);
/*
 *@brief:
 *@param:
 *@retval:
 */
uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number);
/*
 *@brief:
 *@param:
 *@retval:
 */
uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF *GPIOx);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_WriteToOutputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number,uint8_t val);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_WriteToOutputPort(GPIO_REG_DEF *GPIOx,uint8_t val);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_TogglePin(GPIO_REG_DEF *GPIOx,uint8_t pin_number);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnDi);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_IRQHandling(uint8_t pin_number);
