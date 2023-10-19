/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:13:45 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 11:40:18 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	manager_start_processing(char **argv)
{
	t_file		*p_file;
	t_matrix	*p_matrix;
	t_window	*p_window;

	if (manager_read_arg(argv, &p_file) == ERROR_CODE)
		return (ERROR_CODE);
	if (manager_store_data(p_file, &p_matrix) == ERROR_CODE)
		return (ERROR_CODE);
	p_window = (t_window *)malloc(sizeof(t_window));
	if (p_window == NULL)
	{
		free(p_window);
		return (report_log_error(ALLOCATED_ERROR, "p_window"));
	}
	manager_init_p_window(p_window, argv);
	engine_create_window(p_window);
	ft_loop_key_hook(p_window);
	engine_draw(p_matrix, p_window);
	engine_callback_hook(p_window);
	return (0);
}

void	manager_init_p_window(t_window *p_window, char **argv)
{
	p_window->p_connection_id = NULL;
	p_window->title = argv[0];
	p_window->color.blue = 255;
	p_window->color.green = 255;
	p_window->color.red = 255;
}

int	manager_store_data(t_file *p_file, t_matrix **pp_matrix)
{
	t_matrix	*p_matrix;

	p_matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (p_matrix == NULL)
		return (report_log_error(ALLOCATED_ERROR, "p_matrix"));
	data_store_file_in_matrix(p_file, p_matrix);
	if (p_matrix->matrix == NULL)
	{
		free(p_matrix);
		return (ERROR_CODE);
	}
	*pp_matrix = p_matrix;
	return (0);
}

int	manager_read_arg(char **argv, t_file **pp_file)
{
	t_file	*p_file;

	p_file = (t_file *)malloc(sizeof(t_file));
	if (p_file == NULL)
		return (report_log_error(ALLOCATED_ERROR, "p_file"));
	p_file->fd = data_open_file(argv[1]);
	if (p_file->fd == NOT_OPEN_FILE)
		return (report_log_error(OPEN_FILE_ERROR, argv[1]));
	data_read_file(p_file);
	close(p_file->fd);
	if (p_file->file_str == NULL)
		return (report_log_error(INVALID_FILE_ERROR, "file_str"));
	*pp_file = p_file;
	return (0);
}
