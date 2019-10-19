#include <stdio.h>
#include "englibs.h"
#include <stdlib.h>
char **screen(int *dim)
{
        char **lines = malloc(sizeof(char *) * dim[1]);
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
