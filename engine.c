#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>
char **scn, **pixels;
int *dimensions;
int pressed = 0;
bool press = false;
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
	press = false;
  return (draw(screen, pixels, dim));
}

void *set_listener()
{
	system ("/bin/stty raw");
//        char *c;
	char c[4];
	char *pl = "\e[4F";
	char *nl = "\e[4E";
        while ((fgets(c, 4, stdin)))
	{
		int pos = 0;
		if (c[2] == 66)
                        printf("%s", pl);
                else if(c[2] == 65)
                        printf("%s", nl);

		printf("\rpressed...................");
		while(c[pos] != '\0')
		{
			printf("%d", c[pos]);
			pos++;
		}
	       
		
		if(c[0] == 13)
		{
			system("/bin/stty cooked");
			return (NULL);
		}
	      
	}
}

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
	  //t g = draw(scn, pixels, dimensions)
	  if (left < 1000 && left > 0)
	  {
		  printf("\r..................................pressed: %d", pressed );
//		  pixels[0][1] += 1;
//		  int sc = draw(scn, pixels, dimensions);
		  //printf("\r....................");
                  //printf("pressed %d", pressed);
		  set_timer();
	  }
	}
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
	int offset_up = 2;
	int o = 0;
	while (o < offset_up)
	  {
	    putchar('\n');
	    o++;
	  }
	printf("\e[36mConsole Engine by Daniel Rodriguez\e[32m");
	for (int i = 0; i < dim[1]; i++)
	  {
	    for (int j = 0; j < dim[0]; j++)
	      {
		if (i == pixels[0][0] && j == pixels[0][1])
		  printf("\e[40m \e[49m");
		putchar(screen[i][j]);
	      }
	    putchar('\n');
	  }
	printf("Score 000000===============\n\e[30m");
	printf("blank space");
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
	
	dimensions = read_window();
	if (dimensions == NULL)
	  {
	    printf("\e[34mError reading console dimensions\e[97m");
	    return (1);
	  }
	printf("\e[32mStarting console engine jijiji\e[97m");
	//set_key_listener();
	scn = screen(dimensions);
	pixels = get_pixels(dimensions, 1);
	pthread_t thread, t2;
	int st = init(scn, pixels, dimensions);

	int err, err2;
	printf("\rcreating threads");
	err2 = 	pthread_create(&t2, NULL, set_listener, NULL);
//	err = pthread_create(&thread, NULL, set_timer, NULL);
	if (err2)
	  {
	    printf("Error\n");    
	  }
	printf("\rThreads created");
	pthread_join(t2, NULL);
//	pthread_join(thread, NULL);
	//destroy(wind, dimensions[1]);
	return (st);
}
