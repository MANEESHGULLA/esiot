/* To interface relay  */

#include<reg51.h>
#define relay P0

void delay_ms(unsigned int);
void main(void)
  {
    while(1)
      {
        relay=0x16;   // Relay ON, LED 2 & LED 3 ON
        delay_ms(500);
        relay=0x09;		// Relay OFF, LED 1 & LED 4 ON
        delay_ms(500);
      }
  }
void delay_ms(unsigned int i)
{
unsigned int j;
while(i-->0)
{
for(j=0;j<500;j++)
{
;
}
}
}
