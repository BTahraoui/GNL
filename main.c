

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("po.txt" , O_CREAT | O_RDWR, 0755);
	write(fd, "123456789", 10);
	printf("%d\n", fd);
	fd = open("po.txt" , O_RDONLY);
	printf("%d\n", fd);
	printf("%s\n", get_next_line(fd));
		fd = open("po.txt" , O_RDONLY);
	printf("%d\n", fd);
	printf("%s\n", get_next_line(fd));
}