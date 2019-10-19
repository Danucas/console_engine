#include <stdio.h>
#include "englibs.h"

void *set_timer()
{
        clock_t start, timer;
        unsigned int left = 0;
        unsigned int seconds = 0;
        unsigned int milli = 0;
        unsigned int count_down = 100;
        unsigned int minutes = 0;
        unsigned int hour = 0;
        start = clock();
        left = count_down - milli;
        while (left > 0)
        {
                timer = clock();
                milli = (timer - start) / 100;
                seconds = (milli /(CLOCKS_PER_SEC))-(minutes*60);
                minutes = (milli /(CLOCKS_PER_SEC))/60;
                hour = minutes/60;
                left = count_down - milli;
                printf("\rleft: ..%u......%u", left, milli);
                if (left < 1000 && left > 0)
                {
                        set_timer();
                }
        }
}
