//#include "led.h"
//#include <reg51.h>
//sbit DIG1=P0^7;
//sbit DIG2=P1^0;
//sbit DIG3=P1^1;
//sbit DIG4=P3^6;

//sbit x_led1=P2^7;
//sbit x_led2=P2^6;
//sbit x_led3=P2^5;
//sbit x_led4=P2^4;
//sbit x_led5=P2^3;
//sbit x_led6=P2^2;
//sbit x_led7=P2^1;
//sbit x_led8=P2^0;


//void delay(unsigned int ms) {
//    unsigned int i, j;
//    for (i = ms; i > 0; i--)
//        for (j = 110; j > 0; j--);
//}
//unsigned char code digitCode[] = {
//    0xC0,  // 0
//    0xF9,  // 1
//    0xA4,  // 2
//    0xB0,  // 3
//    0x99,  // 4
//    0x92,  // 5
//    0x82,  // 6
//    0xF8,  // 7
//    0x80,  // 8
//    0x90   // 9
//};

//void display(unsigned char *digits) {
//    unsigned char i;
//    for (i = 0; i < 4; i++) {
//        switch (i) {
//            case 0:
//                DIG1 = 0;
//                break;
//            case 1:
//                DIG2 = 0;
//                break;
//            case 2:
//                DIG3 = 0;
//                break;
//            case 3:
//                DIG4 = 0;
//                break;
//        }
//        
//        P2 = digitCode[digits[i]];
//        delay(1);
//        P2 = 0x00;
//        
//        switch (i) {
//            case 0:
//                DIG1 = 1;
//                break;
//            case 1:
//                DIG2 = 1;
//                break;
//            case 2:
//                DIG3 = 1;
//                break;
//            case 3:
//                DIG4 = 1;
//                break;
//        }
//    }
//}


