#include <stdio.h>
#include "englibs.h"
#include <stdlib.h>

extern int *dimensions;
extern char ***obj;

void *set_listener()
{
        system ("/bin/stty raw");
        char c[2];

	char *width = _tostring(dimensions[0]);
	char *height = _tostring(dimensions[1] + 4);
	int i, j;
	char *code_display = mov_coord("0", height);
        while ((fgets(c, 2, stdin)))
        {
                int pos = 0;
                system("/bin/stty cooked");
                printf("%s", code_display);
		int n = obj_trans(obj[0], c[0]);
	        n = draw(scn, pixels, dimensions);
		printf("%d  ", c[0]);
                if(c[0] == 122)
                {
                        system("/bin/stty cooked");
			free(code_display);
                        return (NULL);
                }
                else
                        system("/bin/stty raw");

        }
}
