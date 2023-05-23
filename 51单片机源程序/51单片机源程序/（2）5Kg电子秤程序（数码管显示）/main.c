
#include "main.h"
#include "HX711.h"
#define uchar unsigned char
#define uint unsigned int
sbit key0=P0^0;
sbit key1=P0^1;
sbit key2=P0^2;
sbit key3=P0^3;

sbit seg0=P0^7;
sbit seg1=P1^0;
sbit seg2=P1^1;
sbit seg3=P3^6;
sbit change=P1^7;
sbit io1=P0^4;
sbit io2=P0^5;
sbit io3=P0^6;
sbit yellow=P1^2;
sbit orange=P1^3;
sbit red=P1^4;
long Weight_Shiwu = 0;
//sbit led1=P2^0;
//sbit led2=P2^1;
//sbit led3=P2^2;
//sbit led4=P2^3;
//sbit led5=P2^4;
//sbit led6=P2^5;
//sbit led7=P2^6;
//sbit led8=P2^7;




sfr P4   = 0xC0;
sbit y_led1=P0^7;
sbit y_led2=P1^0;
sbit y_led3=P1^1;
sbit y_led4=P4^4;

sbit x_led1=P2^7;
sbit x_led2=P2^6;
sbit x_led3=P2^5;
sbit x_led4=P2^4;
sbit x_led5=P2^3;
sbit x_led6=P2^2;
sbit x_led7=P2^1;
sbit x_led8=P2^0;

//sbit le1=P0^0;
//sbit le2=P0^1;
//sbit le3=P0^2;
uchar code table[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0X00,0XFF,0x40};			//0,1,2,3,4,5,6,7,8,9,全暗，全亮,g,e,r,o,h,l			//共阴
uchar flag=0,s,m=12,h=21,week,flag1=0,beep,flag2;
uchar m1,h1,s1,clock;
void Scan_Key()
{
	if(key0 == 1)
	{
		Delay_ms(5);
		if(key0 == 1)
		{
			flag2=!flag2;
			while(key0==1);
		}	
	}

if(key1 == 1)
	{
		Delay_ms(5);
		if(key1 == 1)
		{if(flag2==0){m++;}
			if(flag2==1){m1++;}
			while(key1==1);
		}	
	}
	
	if(key2 == 1)
	{
		Delay_ms(5);
		if(key2 == 1)
		{
			if(flag2==0){h++;}
			if(flag2==1){h1++;}
			while(key2==1);
		}	
	}
	
	if(key3 == 1)
	{
		Delay_ms(5);
		if(key3 == 1)
		{
			week++;
			while(key3==1);
		}	
	}
	if(change==1)
	{
			Delay_ms(5);
		if(change == 1)
		{
			flag1++;if(flag1==3){flag1=0;}
			while(change==1);
			
		}	
	}
}
void display()
{
	if(flag2==0)
	{
	if(s%2==0)
	{			seg0=0;
		P2=table[h/10];
		Delay_ms(2);
		seg0=1;seg1=1;seg2=1;seg3=1;
	seg1=0;
		P2=table[h%10];
		Delay_ms(2);
	seg0=1;seg1=1;seg2=1;seg3=1;	
seg2=0;	
		P2=table[m/10];
		Delay_ms(2);
		seg0=1;seg1=1;seg2=1;seg3=1;
seg3=0;
		P2=table[m%10];
		Delay_ms(2);
		seg0=1;seg1=1;seg2=1;seg3=1;
	}else	{	seg0=0;seg1=0;seg2=0;seg3=0;P2=table[week+1];}
	
	}

//		if(flag2==1)
//	{
//				seg0=0;
//		P2=table[h1/10];
//		Delay_ms(2);
//		seg0=1;seg1=1;seg2=1;seg3=1;
//	seg1=0;
//		P2=table[h1%10];
//		Delay_ms(2);
//	seg0=1;seg1=1;seg2=1;seg3=1;	
//seg2=0;	
//		P2=table[m1/10];
//		Delay_ms(2);
//		seg0=1;seg1=1;seg2=1;seg3=1;
//seg3=0;
//		P2=table[m1%10];
//		Delay_ms(2);
//		seg0=1;seg1=1;seg2=1;seg3=1;
//		clock=1;
//	}

}
void led()
{
//y_led1=1;
//y_led2=1;
//y_led3=1;
//y_led4=1;
//	
	
y_led1=0;
y_led2=0;
y_led3=0;
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
}


void main()
{
		
	Delay_ms(1000);		 //延时,等待传感器稳定
	Init_Timer0();
	while(1)
	{ 	
		
	led();
//		display();
//	Get_Weight();			//称重
//		Scan_Key();
//	beep_();
		
	}
}


void Get_Weight()
{
//	Weight_Shiwu = HX711_Read();
//	if(Weight_Shiwu > 0)			
//	{																	
//		if(Weight_Shiwu > 10000)		//超重报警
//		{
//				beep=0;
//				red=0;orange=0;yellow=0;
				//Delay_ms(2000);
//		}else red=1;orange=1;yellow=1;

//	}

}


void Init_Timer0()
{
	TMOD = 0X01;			//T0, 工作模式1

	TH0 = (65536 - 25000)/256;
	TL0 = (65536 - 25000)%256;

	TR0 = 1;				//开启定时器
	ET0 = 1;			  //开启定时器中断
	EA = 1;					//开启总中断		
}


void int0() interrupt 1
{
	TH0 = (65536 - 25000)/256;
	TL0 = (65536 - 25000)%256;
	
  flag++;
	if(flag >= 20)
	{
		s++;flag=0;

		
	}
	if(s==60){m++;s=0;}
	if(m==60){h++;m=0;}
	if(h==24){week++;h=0;}
	if(week==7){week=0;}
  if(clock==1)
	{
		if(m==m1&&h==h1)
			{
				beep=1;
				clock=0;
			}
	}
	
	
}
void beep_()
{
	if(beep==0)
		{
			io1=0;io2=0;io3=0;
		}
		else
		{
			
		}if(flag==0){	io1=1;io2=0;io3=0;}
			if(flag==1){	io1=0;io2=1;io3=0;}
			if(flag==2){	io1=0;io2=0;io3=1;}
}

void Delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}