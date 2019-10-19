/*
 * stm32g071xx_gpio.h
 *
 *  Created on: 17-Oct-2019
 *      Author: Ananda Padmanabhan
 */

#ifndef INC_STM32G071XX_GPIO_H_
#define INC_STM32G071XX_GPIO_H_

#include "stm32g071xx.h"

typedef struct
{
	uint8_t pin_number;
	uint8_t pin_speed;
	uint8_t pin_pupd;
	uint8_t pin_mod;
	uint8_t pin_alt_mode;
	uint8_t output_type;

}GPIO_Config_Pin_s;
typedef struct
{
	GPIO_REG_DEF *GPIOx;
	GPIO_Config_Pin_s  GPIO_Config_Pin;
}Gpio_Handle;
/*
 *@brief:Initializing GPIO pins
 *@param:GPIO Handler
 *@retval:none
 */
void GPIO_Init(Gpio_Handle *PGpiox);
/*
 *@brief:Deinitializing GPIO pins
 *@param:GPIO Poet
 *@retval:none
 */
void GPIO_Deinit(GPIO_REG_DEF *GPIOx);
/*
 *@brief:Enabling/Doabling  clock of GPIO
 *@param:GPIO port
 *@param:Enable/Disable
 *@retval:none
 */
void GPIO_Peri_clk_ctrl(GPIO_REG_DEF *GPIOx,uint8_t EnDi);
/*
 *@brief:Reads Pin state
 *@param:GPIO Base address
 *@param:Pin number
 *@retval:Pin state
 */
uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number);
/*
 *@brief:Read from port
 *@param:GPIO Base address
 *@retval:Port state
 */
uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF *GPIOx);
/*
 *@brief:Write value to pin
 *@param:GPIO Port
 *@param:GPIO Pin number
 *@param:GPIO value
 *@retval:none
 */
void GPIO_WriteToOutputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number,uint8_t val);
/*
 *@brief:Write value to port
 *@param:GPIO Port
 *@param:GPIO value
 *@retval:none
 */
void GPIO_WriteToOutputPort(GPIO_REG_DEF *GPIOx,uint8_t val);
/*
 *@brief:Toggles value at pin
 *@param:Gpio Port
 *@param:Gpio Pin
 *@retval:none
 */
void GPIO_TogglePin(GPIO_REG_DEF *GPIOx,uint8_t pin_number);
/*
 *@brief:Configuring EXTI
 *@param:IRQ number
 *@param:IRQ Priority
 *@param:IRQ Enable/Disable
 *@retval:none
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnDi);
/*
 *@brief:Interrunt handler
 *@param:Pin number
 *@retval:none
 */
void GPIO_IRQHandling(uint8_t pin_number);

#define 			SET					1
#define 			RESET				0
#define 			ENABLE				SET
#define 			DISABLE				RESET


#endif /* INC_STM32G071XX_GPIO_H_ */
