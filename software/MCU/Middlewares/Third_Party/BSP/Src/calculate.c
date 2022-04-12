/*
 * calculate.c
 *
 *  Created on: Apr 12, 2022
 *      Author: grzegorz
 */


#include "calculate.h"



double sin_l(double sin_arg)
{
    int x;
    double pi_to_2pi;

    x = (int)(sin_arg / (PI / 2) * SIN_LUT_LEN);

    while(x >= 4 * SIN_LUT_LEN)
        x = x - 4 * SIN_LUT_LEN;    //subtract full period (SIN_LUT_LEN is only 1/4 of period)
    while(x < 0)
        x = x + 4 * SIN_LUT_LEN;

    if(x > 2 * SIN_LUT_LEN)
    {
        x = x - 2 * SIN_LUT_LEN;
        pi_to_2pi = -1;
    }
    else
    {
        pi_to_2pi = 1;
    }

    if(x <= 1 * SIN_LUT_LEN)
    {
        if(     x < 1 * SIN_LUT_LEN / SIN_LUT_PARTS)    //0 to 499
            return sin_lut1[x - 0 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 2 * SIN_LUT_LEN / SIN_LUT_PARTS)    //500 to 999
            return sin_lut2[x - 1 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 3 * SIN_LUT_LEN / SIN_LUT_PARTS)    //1000 to 1499
            return sin_lut3[x - 2 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 4 * SIN_LUT_LEN / SIN_LUT_PARTS)    //1500 to 1999
            return sin_lut4[x - 3 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 5 * SIN_LUT_LEN / SIN_LUT_PARTS)    //2000 to 2499
            return sin_lut5[x - 4 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 6 * SIN_LUT_LEN / SIN_LUT_PARTS)    //2500 to 2999
            return sin_lut6[x - 5 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 7 * SIN_LUT_LEN / SIN_LUT_PARTS)    //3000 to 3499
            return sin_lut7[x - 6 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(x < 8 * SIN_LUT_LEN / SIN_LUT_PARTS)    //3500 to 3999
            return sin_lut8[x - 7 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else                                            //4000 is exact pi/2 - return closest value (from x=3999)
            return sin_lut8[(SIN_LUT_LEN - 1) - 7 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
    }
    else if(x <= 2 * SIN_LUT_LEN)
    {
        if(     2 * SIN_LUT_LEN - x < 1 * SIN_LUT_LEN / SIN_LUT_PARTS)    //0 to 499
            return sin_lut1[(2 * SIN_LUT_LEN - x) - 0 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;   //for sin_arg==pi x==8000 so sin_lut1(8000-8000)==0
        else if(2 * SIN_LUT_LEN - x < 2 * SIN_LUT_LEN / SIN_LUT_PARTS)    //500 to 999
            return sin_lut2[(2 * SIN_LUT_LEN - x) - 1 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 3 * SIN_LUT_LEN / SIN_LUT_PARTS)    //1000 to 1499
            return sin_lut3[(2 * SIN_LUT_LEN - x) - 2 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 4 * SIN_LUT_LEN / SIN_LUT_PARTS)    //1500 to 1999
            return sin_lut4[(2 * SIN_LUT_LEN - x) - 3 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 5 * SIN_LUT_LEN / SIN_LUT_PARTS)    //2000 to 2499
            return sin_lut5[(2 * SIN_LUT_LEN - x) - 4 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 6 * SIN_LUT_LEN / SIN_LUT_PARTS)    //2500 to 2999
            return sin_lut6[(2 * SIN_LUT_LEN - x) - 5 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 7 * SIN_LUT_LEN / SIN_LUT_PARTS)    //3000 to 3499
            return sin_lut7[(2 * SIN_LUT_LEN - x) - 6 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;
        else if(2 * SIN_LUT_LEN - x < 8 * SIN_LUT_LEN / SIN_LUT_PARTS)    //3500 to 3999
            return sin_lut8[(2 * SIN_LUT_LEN - x) - 7 * SIN_LUT_LEN / SIN_LUT_PARTS] * pi_to_2pi;   //x=4001
    }
}

double cos_l(double cos_arg)
{
    return sin_l(cos_arg + PI / 2.0);
}
