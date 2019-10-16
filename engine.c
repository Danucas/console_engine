#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
void draw(int width, int height, char **pixels);
char **screen(int width, int height, char **av);

int main(int argc, char **av)
{
	(void) argc;
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
	FILE *tysq;
	/* drawing screen*/
	while(1)
	{
		char c = getc(stdin);
		
			printf("char: %d ", c);
	}
	draw(width, height, av);
	return (0);
}
void draw(int width, int height, char **pixels)
{
	char **window;
	window = screen(width - 1, height, pixels);
        int clean = system("clear");
        for (int p = 0; p < height; p++)
        {
                printf("%s\n", window[p]);
                free(window[p]);
        }

        free(window);
}

char **screen(int width, int height, char **av)
{
	char **lines = malloc(sizeof(char *) * height);
	//printf("dimensions %d, %d\n", height, width);
	if(lines == NULL)
		return (NULL);
	for (int i = 0; i < height; i++)
	{
		lines[i] = malloc(width * sizeof(char));
		if (lines[i] == NULL)
		{
			for(i--; i >= 0; i--)
			{
				free(lines[i]);
			}
			free(lines);
		}
		for (int p = 0; p < width; p++)
		{
			if (i == _atoi(av[1]) && p == _atoi(av[2]))
				lines[i][p] = '*';
			else
				lines[i][p] = ' ';
		}
	}
	return (lines);
}
