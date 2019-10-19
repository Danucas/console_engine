#include <stdio.h>
#include "englibs.h"
#include <stdlib.h>
char *mov_coord(char *x, char *y)
{
        int i, j, size;
	size = _strlen(x) + _strlen(y) + 5;
	char *index = malloc(size * sizeof(char));
	if (malloc == NULL)
		return (NULL);
	index[0] = '\e';
	index[1] = '[';
	i = 2;
	j = 0;
	while (y[j] != '\0')
	{
         	index[i] = y[j];
		i++;
		j++;
	}
        index[i] = ';';
        i++;
        j = 0;
        while (x[j] != '\0')
        {
                index[i] = x[j];
                i++;
                j++;
        }
        index[i] = 'H';
        index[i+1] = '\0';
        return (index);
}
