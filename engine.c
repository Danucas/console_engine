#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>

int init(char **screen, char **pixels, int *dim);

int *dimensions;
bool stop = false;
bool drawing = false;
char **scn, **pixels;
char ***obj;
int init(char **screen, char **pixels, int *dim)
{
  return (draw(screen, pixels, dim));
}

int destroy(char **screen, int height)
{
        for (int p = 0; p < height - 2; p++)
        {
                free(screen[p]);
        }
	free(screen);
	return (0);
}


int main(int argc, char **av)
{
	(void) argc;
	//printf("\e[8;36;73t");
	printf("\n\n\n");

	int t = delay(3);
	dimensions = read_window();
	if (dimensions == NULL)
	  {
	    printf("\e[34mError reading console dimensions\e[97m");
	    return (0);
	  }
	scn = screen(dimensions);
	if (scn == NULL)
		return (0);
	obj = _obj(1);
	if (scn == NULL)
		return (0);
	pixels = get_pixels(dimensions, 1);
	if (pixels == NULL)
		return (0);
	obj[0] = pixels;
	pthread_t t2, screen_animation;
	int st = init(scn, pixels, dimensions);
//	printf("\n\n\ndibujado\n");
	int err2, err;

//	void *listener = set_listener();

	err2 = 	pthread_create(&t2, NULL, set_listener, NULL);
	err  = pthread_create(&screen_animation, NULL, set_timer, NULL);
	if (err2)
	{
	    printf("Error\n");
	}
//	printf("\n\n\ncerrando la cosa\n");
//	if (err2 != NULL)
	pthread_join(t2, NULL);
	pthread_join(screen_animation, NULL);
//	printf("\n\n\n%ldalgo paso\n", t2);
	
	system("clear");
	printf("\e[0m");
	st = destroy(scn, dimensions[1]);
	free(pixels[0]);
	free(pixels);
	free(obj);
	free(dimensions);
	return (0);
}
