/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:54:49 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:55:00 by ynyamets         ###   ########.fr       */
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
