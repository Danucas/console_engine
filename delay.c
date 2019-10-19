#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "englibs.h"

int delay(int del)
{
        clock_t start, timer, dif;
        unsigned int left = 0;
        unsigned int seconds = 0;
        unsigned int milli = 0;
        unsigned int count_down = (del * 1000);
        unsigned int minutes = 0;
        unsigned int hour = 0;
        start = clock();
	dif = start;
        left = count_down - milli;
	char *coo = mov_coord("0" , "3");
	printf("\r%scount: %u start:%u", coo, count_down, (unsigned int)start);
        while (left > 0 && left < ((del * 1000) + 10))
        {
                timer = clock();
		dif = timer - dif;
                milli = (timer - start);
                left -= dif;
//		if ()
                coo = mov_coord("0" , "0");
                printf("%s                     \rleft: %u, timer: %u", coo ,(unsigned int)left,(unsigned int) timer);
		free(coo);
		dif  = timer;
        }
	printf("\r                 \rFinished");
}
