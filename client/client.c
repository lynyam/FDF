#include "client.h"

int	main(int argc, char **argv)
{
	int return_code;
	char *message_error = "INCORRECT_ARGS";

	if (argc != 2)
	{
		report_exit_program(message_error);
		//printf("%s\n",message_error);
	}
	
	return_code = manager_start_processing(argv[1]);
	return(return_code);
}
