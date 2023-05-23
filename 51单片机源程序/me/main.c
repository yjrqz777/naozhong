#include "main.h"
#include "led.h"


void delay(int n) {
    int i=0, j=0;
    for (i = n; i > 0; i--)
	{
        for (j = 110; j > 0; j--)
		{}
	}
}
void led()
{
//y_led1=1;
//y_led2=1;
//y_led3=1;
//y_led4=1;
//	
//					DIG1=1;
//					DIG2=1;
//					DIG3=1;
//					DIG4=1;
	
	
					DIG1=0;
					DIG2=0;
					DIG3=0;
					DIG4=0;
//y_led1=0;
//y_led2=0;
//y_led3=0;
//y_led4=0;
	
	
//x_led1=0;
//x_led2=0;
//x_led3=0;
//x_led4=0;
//x_led5=0;
//x_led6=0;
//x_led7=0;
//x_led8=0;

	
x_led1=1;
x_led2=1;
x_led3=1;
x_led4=1;
x_led5=1;
x_led6=1;
x_led7=1;
x_led8=1;
//clear();
}
unsigned int digitCode[] = {
    ~0xC0,  // 0
    ~0xF9,  // 1
    ~0xA4,  // 2
    ~0xB0,  // 3
    ~0x99,  // 4
    ~0x92,  // 5
    ~0x82,  // 6
    ~0xF8,  // 7
    ~0x80,  // 8
    ~0x90   // 9
};

void display(unsigned int *digits) {
    unsigned int i=0;
	            int x=0, j=0;
    for (i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                DIG1 = 0;
                break;
            case 1:
                DIG2 = 0;
                break;
            case 2:
                DIG3 = 0;
                break;
            case 3:
                DIG4 = 0;
                break;
        }
        
        P2 = digitCode[7];

//        P2 = 0x00;
        
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
    }
}

//////////////////////
void main() {
    unsigned int hour = 12;   // ?????,???0-23
    unsigned int minute = 34; // ?????,???0-59
    unsigned int digits[4];
	Init_Timer0();
//    		int i;
    while (1) {
//					DIG1=0;
//					DIG2=1;
//					DIG3=1;
//					DIG4=1;
//        digits[0] = 1;
//        digits[1] = 2;
//        digits[2] = 3;
//        digits[3] = 4;
//				P2 = digitCode[7];
        // ?????????????
//        display(digits);
        
        // ??1?
//        delay(1000);
//        
//        // ????
//        minute++;
//        if (minute >= 60) {
//            minute = 0;
//            hour++;
//            if (hour >= 24) {
//                hour = 0;
//            }
//        }
			led();
//P2 = digitCode[5];
//    for (i = 0; i < 8; i++) {
////			P2=digitCode[i];
//			delay(10);
////			P2=0x00;
//		}
    }
}

/////////////////////////////////////////////////////
void Init_Timer0()
{
	TMOD = 0X01;			//T0, 工作模式1

	TH0 = (65536 - 25000)/256;
	TL0 = (65536 - 25000)%256;

	TR0 = 1;				//开启定时器
	ET0 = 1;			  //开启定时器中断
	EA = 1;					//开启总中断		
}

//void int0() interrupt 1
//{
//	TH0 = (65536 - 25000)/256;
//	TL0 = (65536 - 25000)%256;
//	
////  flag++;
////	if(flag >= 20)
////	{
////		s++;flag=0;

////		
////	}
////	if(s==60){m++;s=0;}
////	if(m==60){h++;m=0;}
////	if(h==24){week++;h=0;}
////	if(week==7){week=0;}
////  if(clock==1)
////	{
////		if(m==m1&&h==h1)
////			{
////				beep=1;
////				clock=0;
////			}
////	}
//	
//	
//}


