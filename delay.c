#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "englibs.h"

int delay(float del)
{
//	printf("starting clock\n\n\n\n\n\n\n\n");
        clock_t start, timer, dif;
        unsigned int left = 0;
        unsigned int seconds = 0;
        unsigned int milli = 10;
        unsigned int count_down = (del * 500000);
        unsigned int minutes = 0;
        unsigned int hour = 0;
        start = clock();
	dif = start;
        left = count_down - milli;

	while (left > 0 && left < count_down)
        {
                timer = clock();
//		printf("\e[2K%d clock %lu\n", __LINE__, timer);
		dif = timer - dif;
//		printf("\e[2K%d dif %lu\n", __LINE__, dif);
		milli = (timer - start);
//		printf("\e[2K%d milli %lu\n", __LINE__, dif);
                left -= dif;
//		printf("\e[2K%d left %lu\n", __LINE__, left / CLOCKS_PER_SEC);
		dif  = timer;
//		printf("\e[2K%d countdown %d\n", __LINE__, count_down);
//		print_time();
        }
//	printf("\r                 \rFinished");
}
