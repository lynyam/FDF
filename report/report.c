#include "report.h"

void	report_exit_program(char *message)
{
	printf("Message error: %s\n", message);
}

void	report_connection_x_server(void *p_connection_id)
{
	if (p_connection_id == NULL)
	{
		printf("connection is not etablished\n");
	}
	printf("connection is etablished with ID : %p \n", p_connection_id);
}

void	report_create_window(void *p_window_id)
{
	if (p_window_id == NULL)
	{
		printf("window create id not create\n");
	}
	printf("window create with ID : %p \n", p_window_id);
}
