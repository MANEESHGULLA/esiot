// 0 to 20
#include <reg51.h>

#define seven_segment_data P1

sbit disp1_sel = P0^3;
sbit disp2_sel = P0^2;
sbit disp3_sel = P0^1;
sbit disp4_sel = P0^0;

void delay_ms(unsigned int);

void main(void)
{
    unsigned char count0 = 0;   // Delay counter
    unsigned char count1 = 0;   // Units digit
    unsigned char count2 = 0;   // Tens digit

    unsigned char bcd_codes[] =
    {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7D, 0x07, 0x7F, 0x6F
    };

    while(1)
    {
        /* Units Digit */
        disp1_sel = 0;
        seven_segment_data = bcd_codes[count1];
        delay_ms(2);
        disp1_sel = 1;

        /* Tens Digit */
        disp2_sel = 0;
        seven_segment_data = bcd_codes[count2];
        delay_ms(2);
        disp2_sel = 1;

        /* Hundreds Digit = 0 */
        disp3_sel = 0;
        seven_segment_data = bcd_codes[0];
        delay_ms(2);
        disp3_sel = 1;

        /* Thousands Digit = 0 */
        disp4_sel = 0;
        seven_segment_data = bcd_codes[0];
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

        /* Stop at 20 */

        if(count2 == 2 && count1 == 1)
        {
            count1 = 0;
            while(1);
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



//==========================================================================================
