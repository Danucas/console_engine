#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
char *_getchar(void)
{
	char c[6];
	char *buf;
	int n = 0;
	if (n == 0)
	{
		n = read(0, c, sizeof(c));
		buf = c;
	}
	return (--n >= 0 ) ?
}
