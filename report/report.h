/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:55:15 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:55:17 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_H
# define REPORT_H
# include <unistd.h>
# include <stdio.h>
# include "../model/model.h"
# define INCORRECT_ARGS_ERROR "Check Arguments. Put absolute file path name"
# define OPEN_FILE_ERROR "Can\'t open file"
# define ALLOCATED_ERROR "Allocated Error"
# define INVALID_FILE_ERROR "Invalid file error"
# define DATA_STRUCT_INIT_ERROR "Initialisation of data Structure failed"
# define NOT_OPEN_FILE_ERROR ""

void	report_exit_program(char *message_type);
int		report_log_error(char *message, char *dta_struct);
void	report_connection_x_server(void *p_connection_id);
void	report_create_window(void *p_window_id);
void	report_create_img(void *p_img_id);

#endif
