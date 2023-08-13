#ifndef DATA_H
# define DATA_H
# include <stdbool.h>
# include "../report/report.h"

bool	data_validate_file_path(char *path);
int	data_open_file(char *file_name);
bool	data_validate_file(int fd);
int**	data_storage_position(int fd);
#endif
