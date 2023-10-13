/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:13:45 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/13 19:22:16 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	manager_start_processing(char **argv)
{
	t_file		*p_file;
	t_matrix	*p_matrix;
	t_window	*p_window;

	p_file = (t_file *)malloc(sizeof(t_file));
	if (p_file == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	p_file->fd = data_open_file(argv[1]);
	if (p_file->fd == NOT_OPEN_FILE)
	{
		return ERROR_CODE;
	}
	data_read_file(p_file);
	printf("%s\n%d\n%d\n", p_file->file_str, p_file->row, p_file->col);
	if (p_file->file_str == NULL)
	{
		report_exit_program(INVALID_FILE_ERROR);
		return ERROR_CODE;
	}
	p_matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (p_matrix == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	data_store_file_in_matrix(p_file, p_matrix);
	if (p_matrix == NULL)
	{
		return ERROR_CODE;
	}

	afficherMatrice(p_matrix->matrix, p_matrix->row, p_matrix->col);
	p_window = (t_window *)malloc(sizeof(t_window));
	if (p_window == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	p_window->p_connection_id = NULL;
	engine_connect_x_server(p_window);
	p_window->title = argv[0];
	engine_create_window(p_window);
	engine_draw(p_matrix, p_window);
	//callback_hook(p_window);
	mlx_loop(p_window->p_connection_id);
	return (0);

}
