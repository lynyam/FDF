#ifndef REPORT_H
# define REPORT_H
# include <unistd.h>
# include <stdio.h>
	void	report_exit_program(char *message_type);
	void	report_connection_x_server(void *p_connection_id);
	void    report_create_window(void *p_window_id);
#endif
