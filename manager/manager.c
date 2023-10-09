/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:13:45 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 19:49:34 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	manager_start_processing(char **argv)
{
	t_matrix	*p_matrix;
	t_file		*p_file;
	t_window	*p_window;

	p_file = (t_file *)malloc(sizeof(t_file *));
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
	p_matrix = (t_matrix *)malloc(sizeof(t_matrix *));
	if (p_matrix == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	data_read_file(p_file);
	if (p_file->file_str == NULL)
	{
		report_exit_program(INVALID_FILE_ERROR);
		return ERROR_CODE;
	}
	data_store_file_in_matrix(p_file, p_matrix);
	if (p_matrix == NULL)
	{
		return ERROR_CODE;
	}
	p_window = (t_window *)malloc(sizeof(t_window *));
	if (p_window == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	engine_connect_x_server(p_window);
	p_window->title = argv[0];
	engine_create_window(p_window);
	engine_draw(p_matrix, p_window);
	callback_hook(p_window);



	mlx_hook(p_window_id, 17, 0, engine_close_window, p_connection_id);


	mlx_key_hook(p_window_id, engine_key_event, param);

	t_param	parm = {p_connection_id, p_window_id, img, p_window_size->x, p_window_size->y, p_c, p_color, &pp0, 0};
	t_param	*param = &parm;




	mlx_mouse_hook(p_window_id, engine_mouse_event, param);

	//engine_check_endian();
	//engine_display_pixel(p_pixel);

	//print_matrix(fran, 10, 10);
	engine_draw(p_matrix, param);
	mlx_hook(p_window_id, 17, 0, engine_close_window, p_connection_id);
	mlx_loop(p_connection_id);
	return (0);

}
