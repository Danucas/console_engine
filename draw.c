#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <stdbool.h>
extern char **pixels;
extern bool drawing;

int draw(char **screen, char **pixels, int *dim)
{
	if (!drawing)
	{
		drawing = true;
 	printf("\e[0;0H");
	int offset_up = 2;
        int o = 0;
        while (o < offset_up)
          {
            o++;
          }
        printf("\e[0m\e[32mConsole Engine by Daniel Rodriguez\e[47m\n");
        for (int i = 0; i < dim[1]; i++)
          {
            for (int j = 0; j < dim[0]; j++)
              {
               	if (i == pixels[0][1] && j == pixels[0][0])
		{
                  printf("0");
		  j++;
		}
                else
		{
                 	printf(" ");
		}
              }
            putchar('\n');
          }
        printf("\e[0mScore 00000\e[32m");
	drawing = false;
	}
        return (0);
}
