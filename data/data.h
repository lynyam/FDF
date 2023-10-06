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
void	data_read_file(int fd, t_file *p_file);

bool	data_validate_file(int fd);
void	print_matrix(int **matrix, int line, int row);
void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix);
int**	data_storage_position(int fd);
#endif
