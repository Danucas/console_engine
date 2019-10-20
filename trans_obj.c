#include <stdio.h>
#include "englibs.h"
extern int *dimensions;
void youlose();
void tick();
void print_coords(char *x, char *y);
int obj_trans(char **ob, int code)
{
	char *x;
	x = &ob[0][0];
	char *y;
	y = &ob[0][1];
	if (code == 65)    /* UP */
                {
			if (*y > 0)
			{
			       *y -= 1;
			       print_coords(x, y);
			}
			else
				youlose();
                }
                else if(code == 66)    /* DOWN */
                {
			if (*y  < (dimensions[1] - 1))
			{
				*y += 1;
				print_coords(x, y);
			}
			else
				youlose();
                }
                else if (code == 67)     /* RIGHT */
                {
			if (*x + 2 <  (dimensions[0] - 1))
			{
				*x += 2;
				print_coords(x, y);
			}
			else
				youlose();
                }
                else if (code == 68)    /* LEFT */
                {
			if (*x > 0)
			{
				if (*x == 1)
					*x -= 1;
				*x -= 2;
				print_coords(x, y);
			}
			else
				youlose();
                }

	return (0);
}

void print_coords(char *x, char *y)
{
	printf("%s\e[37mCoords: x: %d, y: %d\e[0m", mov_coord(_tostring((dimensions[0] / 2) - 12), _tostring(dimensions[1] + 3)), *x, *y);
}

void youlose()
{
	printf("%s\e[31m       Game over        \e[0m", mov_coord(_tostring((dimensions[0] / 2) - 12), _tostring(dimensions[1] + 3)));
}
void tick()
{
	printf("%s\e[37mkeep playing\e[0m", mov_coord(_tostring((dimensions[0] / 2) - 12), _tostring(dimensions[1] + 3)));
}
