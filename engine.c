#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>

int init(char **screen, char **pixels, int *dim);

int *dimensions;

char **scn, **pixels;
char ***obj;
int init(char **screen, char **pixels, int *dim)
{
  return (draw(screen, pixels, dim));
}

void destroy(char **screen, int height)
{
        for (int p = 0; p < height; p++)
        {
                free(screen[p]);
        }
	free(screen);
}


int main(int argc, char **av)
{
	(void) argc;
	system("clear");
	dimensions = read_window();
	if (dimensions == NULL)
	  {
	    printf("\e[34mError reading console dimensions\e[97m");
	    return (1);
	  }
	scn = screen(dimensions);
	obj = _obj(1);
	pixels = get_pixels(dimensions, 1);
	obj[0] = pixels;
	pthread_t thread, t2;
	int st = init(scn, pixels, dimensions);
	int err, err2;
	void *listener = set_listener();
	err2 = 	pthread_create(&t2, NULL, listener, NULL);
	if (err2)
	{
	    printf("Error\n");
	  }
	pthread_join(t2, NULL);
	destroy();
	fress(pixels[0]);
	free(pixels);
	free(obj);
	free(dimensions);
	return (st);
}
