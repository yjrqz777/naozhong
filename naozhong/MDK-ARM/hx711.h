
#ifndef HX711
#define HX711
#include "stdint.h"

#define BUFFERSIZE 255           //可以接收的最大字符个数    
#define SCK_GPIO_Port GPIOB
#define SCK_Pin GPIO_PIN_12

#define DT_GPIO_Port GPIOB
#define DT_Pin GPIO_PIN_13
extern uint32_t ReadCount(void);
extern uint32_t ReadWeight(void);
extern void delay_us(uint32_t delay);
#endif


