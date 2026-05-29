#include <reg51.h>

#define seven_segment_data P1

sbit disp1_sel = P0^3;
sbit disp2_sel = P0^2;
sbit disp3_sel = P0^1;
sbit disp4_sel = P0^0;
sbit lcd_back_light = P0^7;

void delay_ms(unsigned int);

void main(void)
{
    unsigned char count0 = 0;
    unsigned char count1 = 0;
    unsigned char count2 = 0;
    unsigned char count3 = 0;
    unsigned char count4 = 0;

    unsigned char bcd_codes[] =
    {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7D, 0x07, 0x7F, 0x6F
    };

    while(1)
    {
        disp1_sel = 0;
        seven_segment_data = bcd_codes[count1];
        delay_ms(2);
        disp1_sel = 1;

        disp2_sel = 0;
        seven_segment_data = bcd_codes[count2];
        delay_ms(2);
        disp2_sel = 1;

        disp3_sel = 0;
        seven_segment_data = bcd_codes[count3];
        delay_ms(2);
        disp3_sel = 1;

        disp4_sel = 0;
        seven_segment_data = bcd_codes[count4];
        delay_ms(2);
        disp4_sel = 1;

        count0++;

        if(count0 > 25)
        {
            count0 = 0;
            count1++;
        }

        if(count1 > 9)
        {
            count1 = 0;
            count2++;
        }

        if(count2 > 9)
        {
            count2 = 0;
            count3++;
        }

        if(count3 > 9)
        {
            count3 = 0;
            count4++;
        }

        if(count4 > 9)
        {
            count4 = 0;
        }
    }
}

void delay_ms(unsigned int i)
{
    unsigned int j;

    while(i-- > 0)
    {
        for(j = 0; j < 500; j++)
        {
            ;
        }
    }
}


//===================================================================================
//HOPE
#include <reg51.h>

#define seven_segment_data P1

sbit disp1_sel = P0^3;
sbit disp2_sel = P0^2;
sbit disp3_sel = P0^1;
sbit disp4_sel = P0^0;

void delay_ms(unsigned int);

void main(void)
{
    while(1)
    {
        disp1_sel = 0;
        seven_segment_data = 0x76;   // H
        delay_ms(2);
        disp1_sel = 1;

        disp2_sel = 0;
        seven_segment_data = 0x3F;   // O
        delay_ms(2);
        disp2_sel = 1;

        disp3_sel = 0;
        seven_segment_data = 0x73;   // P
        delay_ms(2);
        disp3_sel = 1;

        disp4_sel = 0;
        seven_segment_data = 0x79;   // E
        delay_ms(2);
        disp4_sel = 1;
    }
}

void delay_ms(unsigned int i)
{
    unsigned int j;

    while(i-- > 0)
    {
        for(j = 0; j < 500; j++)
        {
            ;
        }
    }
}
