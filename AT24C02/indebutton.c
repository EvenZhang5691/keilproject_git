#include "indebutton.h"

bit scanbutton1(void)
{
    static unsigned int presstime_1 = 0;
    static bit state_1 = 0;

    if (P3_1 == 0)
    {
        if (presstime_1 == 0)
            presstime_1 = sys_tick;

        if (!state_1 && sys_tick - presstime_1 >= 20)
        {
            state_1 = 1;
            return 1;
        }
    }
    else
    {
        presstime_1 = 0;
        state_1 = 0;
    }
    return 0;
}

bit scanbutton2(void)
{
    static unsigned int presstime_2 = 0;
    static bit state_2 = 0;

    if (P3_0 == 0)
    {
        if (presstime_2 == 0)
            presstime_2 = sys_tick;

        if (!state_2 && sys_tick - presstime_2 >= 20)
        {
            state_2 = 1;
            return 1;
        }
    }
    else
    {
        presstime_2 = 0;
        state_2 = 0;
    }
    return 0;
}

bit scanbutton3(void)
{
    static unsigned int presstime_3 = 0;
    static bit state_3 = 0;

    if (P3_2 == 0)
    {
        if (presstime_3 == 0)
            presstime_3 = sys_tick;

        if (!state_3 && sys_tick - presstime_3 >= 20)
        {
            state_3 = 1;
            return 1;
        }
    }
    else
    {
        presstime_3 = 0;
        state_3 = 0;
    }
    return 0;
}

bit scanbutton4(void)
{
    static unsigned int presstime_4 = 0;
    static bit state_4 = 0;

    if (P3_3 == 0)
    {
        if (presstime_4 == 0)
            presstime_4 = sys_tick;

        if (!state_4 && sys_tick - presstime_4 >= 20)
        {
            state_4 = 1;
            return 1;
        }
    }
    else
    {
        presstime_4 = 0;
        state_4 = 0;
    }
    return 0;
}

