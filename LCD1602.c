#include "reg51.h"
#define LCD_D P1 //定义数据口

typedef unsigned int u8; //定义无符号整型数据为 u8
typedef unsigned char u16; //16位

sbit RS = P2^2;
sbit RW = P2^1;
sbit E  = P2^3;

void dealy (u8 x){
	u8 j;
			for(;x!=0; x--)
	for (j=0;j<255;j++);
	
}

void write_COMMAND(u16 dat0){   
     
     RS=0;
	   RW=0;
	LCD_D=dat0;
		   dealy(5);
	   E=1;
		   dealy(5);
	   E=0;
}

void write_DATA(u16 dat1){
     RS   =1;
	   RW   =0;
	LCD_D=dat1;
	   E    =1;
	   dealy(5);
     E    =0;
	dealy(5);

}

			/* 
void read_MODE(u16 dat2){
					 RS   =0;
					 RW   =1;
					 E    =1;
				LCD_D=dat2;
					 dealy(1000);


			}

			void read_DATA(u16 dat4){
					 RS   =1;
					 RW   =1;
					 E    =1;
				LCD_D=dat4;
					 dealy(1000);
			}

void LCD_disply(u16 dat3){
    
	   write_DATA(dat3);
	   write_COMMAND(0x80);
	   dealy(5000);


}

*/

void print_string(char* str){
	u8 i;
	for(i=0;str[i]!=0;i++)
	{
		write_DATA(str[i]);
	}
}

void main(){
	RW=0;
	RS=0;
	write_COMMAND(0x36);
	write_COMMAND(0x0F);
  write_COMMAND(0x38);
	write_COMMAND(0x0c);
	write_COMMAND(0x06);
	write_COMMAND(0x01);
	write_COMMAND(0x80);
	write_COMMAND(0xc0);
  print_string("Yang lei xin");
	while(1);

}