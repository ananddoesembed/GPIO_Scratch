/*
 * stm32g071xx_gpio.c
 *
 *  Created on: 17-Oct-2019
 *      Author: Ananda Padmanabhan
 */

#include "stm32g071xx_gpio.h"


void GPIO_Init(Gpio_Handle *PGpiox)
{
	uint32_t temp,temp1;
	if(PGpiox->GPIO_Config_Pin.pin_mod<=GPIO_ANALOG)  //non interrupt mode
		{
		PGpiox->GPIOx->MODER&=~(0x03<<PGpiox->GPIO_Config_Pin.pin_number);
		temp=(PGpiox->GPIO_Config_Pin.pin_mod <<(2*PGpiox->GPIO_Config_Pin.pin_number));
		PGpiox->GPIOx->MODER|=temp;

		}
	else												//interrupt mode
		{

		}
	  temp=0;
	  PGpiox->GPIOx->OSPEEDR&=~(0x03<<PGpiox->GPIO_Config_Pin.pin_number);
	  temp=(PGpiox->GPIO_Config_Pin.pin_speed<<(2*PGpiox->GPIO_Config_Pin.pin_speed));
	  PGpiox->GPIOx->OSPEEDR|=temp;
	  temp=0;
	  PGpiox->GPIOx->PUPDR&=~(0x03<<PGpiox->GPIO_Config_Pin.pin_number);
	  temp=(PGpiox->GPIO_Config_Pin.pin_pupd<<(2*PGpiox->GPIO_Config_Pin.pin_pupd));
	  PGpiox->GPIOx->PUPDR|=temp;
	  temp=0;
	  PGpiox->GPIOx->OTYPER&=~(0x01<<PGpiox->GPIO_Config_Pin.pin_number);
	  temp=(PGpiox->GPIO_Config_Pin.output_type<<(PGpiox->GPIO_Config_Pin.output_type));
	  PGpiox->GPIOx->OTYPER|=temp;
	  temp=0;
	  if(PGpiox->GPIO_Config_Pin.pin_mod==GPIO_ALT_FN)
	  {
		  if(PGpiox->GPIO_Config_Pin.pin_number<GPIO_PIN_8)
		  {
			  PGpiox->GPIOx->AFRL&=~(0x0F<<PGpiox->GPIO_Config_Pin.pin_number);
			  temp=PGpiox->GPIO_Config_Pin.pin_alt_mode<<(4*(PGpiox->GPIO_Config_Pin.pin_number));
			  PGpiox->GPIOx->AFRL|=temp;
		  }
		  else
		  {
			  PGpiox->GPIOx->AFRH&=~(0x0F<<PGpiox->GPIO_Config_Pin.pin_number);
			  temp1=(PGpiox->GPIO_Config_Pin.pin_number)%8;
			  temp=PGpiox->GPIO_Config_Pin.pin_alt_mode<<(4*temp1);
			  PGpiox->GPIOx->AFRH|=temp;
		  }
		  temp=0;
		  temp1=0;
	  }
}

void GPIO_Deinit(GPIO_REG_DEF *GPIOx)
	{
	if(GPIOx == GPIOA)
		{
			GPIOA_RESET();
		}
	else if(GPIOx == GPIOB)
		{
			GPIOB_RESET();
		}
	else if(GPIOx == GPIOC)
		{
			GPIOC_RESET();
		}
	else if(GPIOx == GPIOD)
		{
			GPIOD_RESET();
		}
	else
		{
			GPIOF_RESET();
		}
	}


void GPIO_Peri_clk_ctrl(GPIO_REG_DEF *GPIOx,uint8_t EnDi)
	{
		if(EnDi==ENABLE)
			{
			if(GPIOx == GPIOA)
				{
					GPIOA_CLK_EN();
				}
			else if(GPIOx == GPIOB)
				{
					GPIOB_CLK_EN();
				}
			else if(GPIOx == GPIOC)
				{
					GPIOC_CLK_EN();
				}
			else if(GPIOx == GPIOD)
				{
					GPIOD_CLK_EN();
				}
			else
				{
					GPIOF_CLK_EN();
				}
			}
		else
		{
			if(GPIOx == GPIOA)
				{
					GPIOA_CLK_DIS();
				}
			else if(GPIOx == GPIOB)
				{
					GPIOB_CLK_DIS();
				}
			else if(GPIOx == GPIOC)
				{
					GPIOC_CLK_DIS();
				}
			else if(GPIOx == GPIOD)
				{
					GPIOD_CLK_DIS();
				}
			else
				{
					GPIOF_CLK_DIS();
				}
		}
}

uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number)
{
	return (uint8_t)(GPIOx->IDR>>pin_number)&(0x01);
}

uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF *GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}
void GPIO_WriteToOutputPin(GPIO_REG_DEF *GPIOx,uint8_t pin_number,uint8_t val)
{
	if(val==SET)
	{
	GPIOx->ODR|=(1<<pin_number);
	}
	else
	{
	GPIOx->ODR&=~(1<<pin_number);
	}

}
void GPIO_WriteToOutputPort(GPIO_REG_DEF *GPIOx,uint8_t val)
{
	if(val==SET)
		{
		GPIOx->ODR=0xFFFF;
		}
		else
		{
		GPIOx->ODR=0x0000;
		}
}
void GPIO_TogglePin(GPIO_REG_DEF *GPIOx,uint8_t pin_number)
{
	GPIOx->ODR^=(1<<pin_number);
}
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnDi);
/*
 *@brief:
 *@param:
 *@retval:
 */
void GPIO_IRQHandling(uint8_t pin_number);
