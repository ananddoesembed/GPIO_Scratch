/*
 * led.c
 *
 *  Created on: 19-Oct-2019
 *      Author: Ananda Padmanabhan
 */


#include "stm32g071xx_gpio.h"
#include "stm32g071xx.h"


void delay()
	{
	for(int i=0;i<50000;i++);

	}
int main()
{
	Gpio_Handle led;
	led.GPIOx=GPIOA;
	led.GPIO_Config_Pin.pin_number=GPIO_PIN_5;
	led.GPIO_Config_Pin.output_type=OUTPUT_PUSHPULL;
	led.GPIO_Config_Pin.pin_speed=LOW_SPEED;
	led.GPIO_Config_Pin.pin_pupd=NO_PULL_UORD;
	led.GPIO_Config_Pin.pin_mod=GPIO_OUTPUT;

	GPIO_Peri_clk_ctrl(GPIOA, ENABLE);
	GPIO_Init(&led);
	while(1)
	{
		GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		delay();
	}
return 0;
}
