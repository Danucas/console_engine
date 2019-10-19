#include "englibs.h"
#include <stdio.h>
#include <stdlib.h>

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
      pixels[i][0] = dim[0] / 2;
      pixels[i][1] = dim[1] / 2;
    }
  return(pixels);
}
