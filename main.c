#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("a.txt", O_RDONLY);
	char *s = get_next_line(fd);

	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);

	close(fd);

	return (0);
}