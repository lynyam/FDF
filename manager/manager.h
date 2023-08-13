#ifndef MANAGER_H
# define MANAGER_H
#include "../engine/engine.h"
#include "../report/report.h"
#include <stdio.h>

int	manager_start_processing(char argv[]);
t_window_config	*init_window_config(void *p_connection_id, t_size *p_window_size, char *window_title);
#endif
