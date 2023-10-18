/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:59:52 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 21:12:08 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "report.h"

void	report_exit_program(char *message)
{
	printf("Message error: %s\n", message);
}

int	report_log_error(char *message, char *dta_struct)
{
	printf("Message error: %s : %s\n", message, dta_struct);
	return (ERROR_CODE);
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

void	report_create_img(void *p_img_id)
{
	if (p_img_id == NULL)
	{
		printf("image not create\n");
	}
	printf("image create with ID : %p \n", p_img_id);
}
