#include "hx711.h"
#include "stdio.h"
//#include "stdint.h"
#include "gpio.h"
 
uint8_t ReceiveBuff[BUFFERSIZE]; //���ջ�����
uint8_t recv_end_flag = 0,Rx_len;//��������жϱ�־�����յ��ַ�����

uint32_t weight_first = 0;//�״�����
uint32_t weight_real = 0;//ÿ�ζ�ȡ��ʵ��ֵ


/***********************************************************************************************
*Name : ReadCount
*Function : ��ȡ��������ֵ��ͨ��A������128
*Parameter :    count ����ֵ
                i    24λ���ݼ������ı�i��ֵ��ѡ��ͬͨ��������24~26
***********************************************************************************************/
uint32_t ReadCount(void)
{
	uint32_t Count = 0;
	uint8_t i = 0;
	HAL_Delay(10);
	HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET);
	
	while(HAL_GPIO_ReadPin(DT_GPIO_Port, DT_Pin));//�ж�ADת�����Ƿ�׼���ã�DOUTӦΪ�͵�ƽ��
	for(i = 0; i <24; i++)//24
	{
	  HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET);
		Count = Count << 1;		
		if(HAL_GPIO_ReadPin(DT_GPIO_Port, DT_Pin))
		{
		    Count ++;
		}
		HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET);			
	}
	
	HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET);
	Count = Count ^ 0x800000;
	HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET);
	return Count;
}

/***********************************************************************************************
*Name : ReadWeight
*Function : ��ȡ����ֵ
*Parameter :   weight_real          ʵ������ֵ
               weight_first         �������״�����
***********************************************************************************************/
uint32_t WeightReal(void)
{
   weight_real = ReadCount();//ʵ����������
		if(weight_first>=weight_real)
		{
			weight_real = weight_first-weight_real;
			weight_real = weight_real/100;
			//printf("����Ϊ��%dg\n",weight_real);
		}
		else
		{
			weight_real = weight_real-weight_first;
			weight_real = weight_real/100;
			//printf("����Ϊ��-%dg\n",weight_real);
		}
		weight_real=weight_real-90064;
		return weight_real;
}
#define CPU_FREQUENCY_MHZ    72		// STM32��Ƶ

//��ʱ�洢����

//�ӳ�us����
void delay_us(uint32_t delay)
{
    int last, curr, val;
    int temp;

    while (delay != 0)
    {
        temp = delay > 900 ? 900 : delay;
        last = SysTick->VAL;
        curr = last - CPU_FREQUENCY_MHZ * temp;
        if (curr >= 0)
        {
            do
            {
                val = SysTick->VAL;
            }
            while ((val < last) && (val >= curr));
        }
        else
        {
            curr += CPU_FREQUENCY_MHZ * 1000;
            do
            {
                val = SysTick->VAL;
            }
            while ((val <= last) || (val > curr));
        }
        delay -= temp;
    }
}