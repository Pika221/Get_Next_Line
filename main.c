#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char *s;

	fd = open("t.txt", O_RDONLY);
	s = get_next_line(0);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	close(fd);
}