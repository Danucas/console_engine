#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>

int pressed = 0;
char **screen(int *dim);
char **get_pixels(int *dim, int lenght);
int *read_window();
void destroy(char **screen, int height);
int draw(char **screen, char **pixels, int *dim);
void *set_listener();
void *set_timer();
void key_pressed();
int init(char **screen, char **pixels, int *dim);

int init(char **screen, char **pixels, int *dim)
{
  pressed = 0;
  return (draw(screen, pixels, dim));
}

void *set_listener()
{
        int o = system("sudo cp read_input.sh /usr/local/bin/read_input.sh");
	FILE *key = popen("bash read_input.sh", "r");
	
	char keyco[4];

	fgets(keyco, 4, key);
	pclose(key);
	//printf("%d", keyco[2]);
	pressed =  keyco[2];
	set_listener();
}

void *set_timer()
{
 
  
  clock_t start, timer;
  unsigned int left = 0;
  unsigned int seconds = 0;
  unsigned int milli = 0;
  unsigned int count_down = 10000;
  unsigned int minutes = 0;
  unsigned int hour = 0;
  start = clock();
  left = count_down - milli;
      while (left > 0)
	{
      
	  timer = clock();
	  milli = timer - start;
	  seconds = (milli /(CLOCKS_PER_SEC))-(minutes*60);
	  minutes = (milli /(CLOCKS_PER_SEC))/60;
	  hour = minutes/60;
	  left = count_down - milli;
	      //start = clock();
	      // timer = clock();
	    // milli = timer - start;
	    // count_down = 1000000;
	  if (pressed != 0)
	    {
	      printf("pressed %d", pressed);
	      pressed = 0;
	      set_timer();
	    }
	  else{
	  
	    //	  if (left < 100)
	    //	    {
	      printf("\r....................");//   printf(":");
	      //     	      set_timer();
	    //	    goto reset;
	    //	    set_listener();
	      //	     }
	  }
	  
	}
      
      //      goto reset;
}
char **get_pixels(int *dim, int lenght)
{
  char **pixels = malloc(sizeof(char) * lenght);
  for (int i = 0; i < lenght; i++)
    {
      pixels[i] = malloc(sizeof(char) * 2);
      if (pixels[i] == NULL)
	{
	  for (i-- ; i >=0; i--)
	    {
	      free(pixels[i]);
	    }
	  free(pixels);
	  return (NULL);

	}
      pixels[i][0] = 1;
      pixels[i][1] = 1;
    }
  return(pixels);
}
int *read_window()
{
        FILE *wfile = popen("tput cols", "r");
	FILE *hfile = popen("tput lines", "r");
	char wid[4];
	char hei[4];
	char type[100];
	int width, height;
	fgets(wid, 4, wfile);
	fgets(hei, 4, hfile);
	pclose(wfile);
	pclose(hfile);
	width = _atoi(wid);
	height = _atoi(hei);
	int *dim = malloc(sizeof(int) * 2);
	if (dim == NULL)
	  {
	    printf("\e[32mError allocating space for dimensions\e[30m");
	    return(NULL);
	  }
	*dim = width - 1;
	*(dim + 1) = height -4;
	return (dim);
	  
}

int draw(char **screen, char **pixels, int *dim)
{
  
  	int clean = system("clear");
	int offset_up = 3;
	int o = 0;
	while (o < offset_up)
	  {
	    putchar('\n');
	    o++;
	  }
	printf("\e[37mConsole Engine by Daniel Rodriguez");
	for (int i = 0; i < dim[1]; i++)
	  {
	    for (int j = 0; j < dim[0]; j++)
	      {
		if (i == pixels[0][0] && j == pixels[0][1])
		  putchar('*');
		putchar(screen[i][j]);
	      }
	    putchar('\n');
	  }
	printf("Score 000000===============\n");
	return (0);
	
}

void destroy(char **screen, int height)
{
        for (int p = 0; p < height; p++)
        {
                printf("%s\n", screen[p]);
                free(screen[p]);
        }

        free(screen);
}

char **screen(int *dim)
{
	char **lines = malloc(sizeof(char *) * dim[1]);
	//printf("dimensions %d, %d\n", height, width);
	if(lines == NULL)
		return (NULL);
	for (int i = 0; i < dim[1]; i++)
	{
		lines[i] = malloc(dim[0] * sizeof(char));
		if (lines[i] == NULL)
		{
			for(i--; i >= 0; i--)
			{
				free(lines[i]);
			}
			free(lines);
		}
		for (int p = 0; p < dim[0]; p++)
		{
				lines[i][p] = ' ';
		}
	}
	return (lines);
}


int main(int argc, char **av)
{
	(void) argc;
	
	int *dimensions;
	dimensions = read_window();
	if (dimensions == NULL)
	  {
	    printf("\e[34mError reading console dimensions\e[97m");
	    return (1);
	  }
	printf("\e[32mStarting console engine jijiji\e[97m");
	//set_key_listener();
	char **wind;
	wind = screen(dimensions);
	char **pixels = get_pixels(dimensions, 1);
	pthread_t thread, t2;
	int st = init(wind, pixels, dimensions);

	int err, err2;
	printf("creating threads");
	err2 = 	pthread_create(&t2, NULL, set_listener, NULL);
	err = pthread_create(&thread, NULL, set_timer, NULL);
	if (err | err2)
	  {
	    printf("Error\n");    
	  }
	printf("\rThreads created");
	pthread_join(t2, NULL);
	pthread_join(thread, NULL);
	set_listener();
	//destroy(wind, dimensions[1]);
	return (st);
}
