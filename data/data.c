//open, close, read, write,
//malloc, free, perror,
//strerror, exit

#include "data.h"

int     data_open_file(char *file_name)
{
	int	fd;

	printf("%s\n", file_name);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		report_exit_program("Can't open file");
	} 
	return fd;
}

void	data_read_file(int fd)
{
	int	n;
	char	c;
	char	buf[BUFSIZE];
	while ((n = read(fd, buf, BUFSIZE)) >  0)
	{
		printf("%s", buf);
	} 
}

