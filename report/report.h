#ifndef REPORT_H
# define REPORT_H
# include <unistd.h>
# include <stdio.h>
# include "../model/model.h"
# define INCORRECT_ARGS_ERROR "Check Arguments. Only need processed absolute file path name"
# define OPEN_FILE_ERROR "Can\'t open file"

	void	report_exit_program(char *message_type);
	void	report_connection_x_server(void *p_connection_id);
	void    report_create_window(void *p_window_id);
#endif
