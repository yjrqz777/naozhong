/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

	uint16_t i=0;
	uint16_t j=0;

		gpio_pack led_4_B[4]=
	{
		GPIOA,GPIO_PIN_0,
		GPIOA,GPIO_PIN_7,
		GPIOB,GPIO_PIN_0,
		GPIOB,GPIO_PIN_11,


	};
		gpio_pack led_4_A[8]=
	{
		GPIOB,GPIO_PIN_10,
		GPIOA,GPIO_PIN_6,
		GPIOA,GPIO_PIN_2,
		GPIOA,GPIO_PIN_4,
		GPIOA,GPIO_PIN_5,
		GPIOB,GPIO_PIN_1,
		GPIOA,GPIO_PIN_1,
		GPIOA,GPIO_PIN_3,
	};
uint16_t shumaguan[][8]=
{
	{1,1,1,1,1,1,0,0},  //0
	{0,1,1,0,0,0,0,0},  //1
	{1,1,0,1,1,0,1,0},  //2
	{1,1,1,1,0,0,1,0},  //3
	{0,1,1,0,0,1,1,0},  //4
	{1,0,1,1,0,1,1,0},  //5
	{1,0,1,1,1,1,1,0},  //6
	{1,1,1,0,0,0,0,0},  //7
	{1,1,1,1,1,1,1,0},  //8
	{1,1,1,1,0,1,1,0},  //9
	{1,1,1,0,1,1,1,0},  //A
	{0,0,1,1,1,1,1,0},  //b
	{1,0,0,1,1,1,0,0},  //C
	{0,1,1,1,1,0,1,0},  //d
	{1,0,0,1,1,1,1,0},  //E
	{1,0,0,0,1,1,1,0},  //F
};
void led_open(int x)
{
	if(x==1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,0);
	}
		if(x==2)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,1);
	}
	if(x==3)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,1);
	}
		if(x==0)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,0);
	}
}
void clear()
{
		for(j=0;j<8;j++)
		{
			HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,0);		
		}
}
void display_dian_x4(uint16_t q, uint16_t w,uint16_t e, uint16_t r)
{
	for(i=0;i<4;i++)
		{
			HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(led_4_A[7].gpio,led_4_A[7].pin,1);
			delay_us(500); HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_SET);clear();
		}
}
void display_s_s(uint16_t r)
{
	if(r==1)
	for(i=0;i<2;i++)
		{
			HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(led_4_A[7].gpio,led_4_A[7].pin,1);
			delay_us(500);
			
			HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_SET);clear();
		}
		if(r==0)
		{
			HAL_GPIO_WritePin(led_4_B[1].gpio,led_4_B[1].pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(led_4_B[0].gpio,led_4_B[0].pin,GPIO_PIN_SET);clear();
		}
}
void display_x4(uint16_t q, uint16_t w,uint16_t e, uint16_t r)
{
	for(i=0;i<4;i++)
		{
			HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_RESET);
			for(j=0;j<8;j++)
			{
				
				if(i==3){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[q][j]);}
				if(i==2){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[w][j]);}
				if(i==1){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[e][j]);}
				if(i==0){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[r][j]);}	
			}delay_us(500); HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_SET);
			clear();
		}
}
void display_xms(uint16_t m, uint16_t s)
{
	uint16_t q,w,e,r;
	q=m/10;w=m%10;e=s/10;r=s%10;
	for(i=0;i<4;i++)
		{
			HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_RESET);
			for(j=0;j<8;j++)
			{
				if(i==3){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[q][j]);}
				if(i==2){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[w][j]);}
				if(i==1){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[e][j]);}
				if(i==0){HAL_GPIO_WritePin(led_4_A[j].gpio,led_4_A[j].pin,shumaguan[r][j]);}
			}
			delay_us(500); HAL_GPIO_WritePin(led_4_B[i].gpio,led_4_B[i].pin,GPIO_PIN_SET);clear();
		}
}
void display4(uint16_t x)
{
		uint16_t q,w,e,r;
	q=x/1000%10;
	w=x/100%10;
	e=x/10%10;
	r=x%10;
	display_x4(q,w,e,r);
}

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB11
                           PB12 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
