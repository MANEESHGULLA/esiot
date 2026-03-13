#include <reg51.h>

#define seven_segment_data P2

sbit DISP1_SEL = P0^3;
sbit DISP2_SEL = P0^2;
sbit DISP3_SEL = P0^1;
sbit DISP4_SEL = P0^0;
sbit led_back_light = P0^2;

void delay_ms(unsigned int);

void main(void)
{
    unsigned char count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    unsigned char bcd_code[] = 
    {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

    do
    {

        DISP1_SEL = 0;
        seven_segment_data = bcd_code[count1];
        delay_ms(2);
        DISP1_SEL = 1;

        DISP2_SEL = 0;
        seven_segment_data = bcd_code[count2];
        delay_ms(2);
        DISP2_SEL = 1;

        DISP3_SEL = 0;
        seven_segment_data = bcd_code[count3];
        delay_ms(2);
        DISP3_SEL = 1;

        DISP4_SEL = 0;
        seven_segment_data = bcd_code[count4];
        delay_ms(2);
        DISP4_SEL = 1;

        count0 += 1;

        if(count0 >= 9)
        {
            count0 = 0;
            count1 += 1;
        }

        if(count1 >= 9)
        {
            count1 = 0;
            count2 += 1;
        }

        if(count2 >= 9)
        {
            count2 = 0;
            count3 += 1;
        }

        if(count3 >= 9)
        {
            count3 = 0;
            count4 += 1;
        }

        if(count4 >= 9)
        {
            count4 = 0;
        }

    } while(1);
}


void delay_ms(unsigned int time)
{
    unsigned int i, j;

    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 500; j++)
        {
        }
    }
}
