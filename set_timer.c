#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "englibs.h"
#include <stdbool.h>
extern bool stop;
extern int *dimensions;
void *set_timer()
{
	float watch = 0;
	while(!stop)
	{
		if ( (int) watch > 15)
			break;
		int time = delay(0.0025);
		watch += 0.00125;
		printf("\e[0;40H\e[42m\e[37m      TIMER ON %.5f       \e[40m",  watch);
	}
	return(NULL);
}
