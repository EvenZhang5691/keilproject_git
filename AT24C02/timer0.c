#include "timer0.h"

idata volatile unsigned int sys_tick = 0;
void Timer0_Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TH0 = (65536 - 922) / 256;
    TL0 = (65536 - 922) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void Timer0_ISR(void) interrupt 1
{
    TH0 = (65536 - 922) / 256;
    TL0 = (65536 - 922) % 256;
    sys_tick++;
}