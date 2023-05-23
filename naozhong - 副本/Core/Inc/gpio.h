/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
typedef struct
{
	GPIO_TypeDef * gpio;
	uint16_t pin;
}gpio_pack;

extern uint16_t i;
extern uint16_t j;
extern gpio_pack key_col[4];
extern gpio_pack key_row[4];
extern gpio_pack led[8];
extern gpio_pack led_4_B[4];
extern gpio_pack led_4_A[8];

extern int key_flag[4][4];

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
extern void all_init();
extern void clear();
extern void scan_key();
extern void display4(uint16_t x);
extern void display_x1(uint16_t i,uint16_t q);
extern void display_x4(uint16_t q, uint16_t w,uint16_t e, uint16_t r);
extern void display_xms(uint16_t m, uint16_t s);
extern void led_display(uint16_t time,uint16_t y);
extern void display_xwd(uint16_t m, uint16_t s);
extern void display_dian_x4(uint16_t q, uint16_t w,uint16_t e, uint16_t r);
extern void beep_open(uint16_t time);
extern void display_s_s(uint16_t x);

extern void clode_led(uint16_t i);
extern void led_display_plus(uint16_t time,uint16_t i);
extern void led_open(int x);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

