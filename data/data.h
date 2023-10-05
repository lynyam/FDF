#ifndef DATA_H
# define DATA_H
# include <stdbool.h>
# include "../report/report.h"
# include "../model/model.h"
# include "fcntl.h"
# include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define BUFSIZE 1024
	

bool		data_validate_file_path(char *path);
int		data_open_file(char *file_name);
t_matrix	*data_read_file(int fd);

bool	data_validate_file(int fd);
void	print_matrix(int **matrix, int line, int row);
int**	data_storage_position(int fd);
#endif
