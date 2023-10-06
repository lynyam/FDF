/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:12:05 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 18:52:23 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int		return_code;

	return_code = 0;
	if (argc != 2)
	{
		report_exit_program(INCORRECT_ARGS_ERROR);
		exit(1);
	}
	return_code = manager_start_processing(argv);
	return (return_code);
}
