#ifndef __MAIN_H__
#define __MAIN_H__

#include <reg51.h>


//IO设置

#define SEG_DATA P0	

sbit DIG1=P0^7;
sbit DIG2=P1^0;
sbit DIG3=P1^1;
sbit DIG4=P3^6;
//sfr P0    = 0x80;
//sbit y_led1=P0^7;
//sbit y_led2=P1^0;
//sbit y_led3=P1^1;
//sbit y_led4=P3^6;

sbit x_led1=P2^7;
sbit x_led2=P2^6;
sbit x_led3=P2^5;
sbit x_led4=P2^4;
sbit x_led5=P2^3;
sbit x_led6=P2^2;
sbit x_led7=P2^1;
sbit x_led8=P2^0;

//sbit x_led9=P3^6;

//sbit KEY1 = P3^2;

//sbit KEY2 = P3^3;
//sbit KEY3 = P3^4;


////函数或者变量声明
extern void delay(int n);
//extern void Get_Maopi();
//extern void Get_Weight();
extern void Init_Timer0();
//extern void Scan_Key();
//extern void beep_();
//extern void display();

#endif