#include <stdio.h>
#include "englibs.h"
#include <stdlib.h>
#include <stdbool.h>

extern int *dimensions;
extern char ***obj;
extern bool stop;
void *set_listener()
{
        system ("/bin/stty raw");
        char c[2];
//	printf("\n\n\niniciando key listener\n");
	char *width = _tostring(dimensions[0]);
//	printf("\n\n\ngetting width\n");
	char *height = _tostring(dimensions[1] + 4);
//	printf("\n\n\ngetting height\n");
	int i, j;
	char *code_display;
	code_display = mov_coord("0", height);
	free(width);
	free(height);
//	printf("\n\n\ngetting code\n");
	if(code_display == NULL)
		return(NULL);
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
			stop = true;
                        system("/bin/stty cooked");
			free(code_display);
			return(NULL);
                }
                else
                        system("/bin/stty raw");

        }
}
