#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
char **screen(int *dim);
char **get_pixels(int *dim, int lenght);
int *read_window();
void destroy(char **screen, int height);
void draw(char **screen, char **pixels, int *dim);
void set_listener();
void key_pressed();

void key_pressed()
{
  
}

void set_listener()
{
 
  // printf("Timer on:");
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
	  if (left < 100){
	    printf("\rTimer: ..");
	    break;
	    //	    goto reset;
	    //	    set_listener();
	
	  }
	  
	}
      set_listener();
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

void draw(char **screen, char **pixels, int *dim)
{

  	int clean = system("clear");
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
	printf("\nScore 000000================\n");
	return;
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
	draw(wind, pixels, dimensions);
	int o = system("sudo cp read_input.sh /usr/local/bin/read_input.sh");
	FILE *key = popen("bash read_input.sh", "r");
	char keyco[4];
	fgets(keyco, 4, key);

	//for (int i = 0; i < 3; i++)
	int i = 0;
	while (keyco[i] != '\0')
	  {
	    printf("%d", keyco[i]);
	    i++;
	  }

	//	set_listener();
	return (0);
}
