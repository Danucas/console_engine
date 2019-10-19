#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "englibs.h"

void *set_timer(int delay)
{
        clock_t start, timer;
        unsigned int left = 0;
        unsigned int seconds = 0;
        unsigned int milli = 0;
        unsigned int count_down = (delay * 1000);
        unsigned int minutes = 0;
        unsigned int hour = 0;
        start = clock();
        left = count_down - milli;
        while (left > 0)
        {
                timer = clock();
                milli = (timer - start);
                seconds = (milli /(CLOCKS_PER_SEC))-(minutes*60);
                minutes = (milli /(CLOCKS_PER_SEC))/60;
                hour = minutes/60;
                left -= milli;
		char *coo = mov_coord(0, dimensions[1] + 4);
                printf("%s\t\t\tleft: ..%u...mill:...%u", coo ,left, milli);
                if (left < 10 && left > 0)
                {
                        set_timer(delay);
                }
        }
}
