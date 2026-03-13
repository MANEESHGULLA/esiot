// 20 to 0

#include <reg51.h>

#define seven_segment_data P2

sbit DISP1 = P0^1;   // Tens digit
sbit DISP2 = P0^0;   // Units digit

void delay_ms(unsigned int time);

void main()
{
unsigned char tens = 2, units = 0;

unsigned char bcd_code[] =
{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

while(1)
{

DISP1 = 0;
seven_segment_data = bcd_code[tens];
delay_ms(2);
DISP1 = 1;

DISP2 = 0;
seven_segment_data = bcd_code[units];
delay_ms(2);
DISP2 = 1;

if(units == 0)
{
units = 9;
tens--;
}
else
{
units--;
}

if(tens == 255)
{
tens = 2;
units = 0;
}

}
}

void delay_ms(unsigned int time)
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<500;j++);
}










// 0 to 20
#include <reg51.h>

#define seven_segment_data P2

sbit DISP1 = P0^1;
sbit DISP2 = P0^0;

void delay_ms(unsigned int time);

void main()
{
unsigned char tens = 0, units = 0;

unsigned char bcd_code[] =
{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

while(1)
{

DISP1 = 0;
seven_segment_data = bcd_code[tens];
delay_ms(2);
DISP1 = 1;

DISP2 = 0;
seven_segment_data = bcd_code[units];
delay_ms(2);
DISP2 = 1;

units++;

if(units > 9)
{
units = 0;
tens++;
}

if(tens == 2 && units == 1)
{
tens = 0;
units = 0;
}

}
}

void delay_ms(unsigned int time)
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<500;j++);
}

