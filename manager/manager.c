/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:13:45 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 02:28:30 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	manager_start_processing(char *argv)
{
	t_matrix	*p_matrix;
	t_file		*p_file;
	int			fd;

	fd = data_open_file(argv);
	if (fd == NOT_OPEN_FILE)
	{
		return ERROR_CODE;
	}
	p_matrix = (t_matrix *)malloc(sizeof(t_matrix *));
	if (p_matrix == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	p_file = (t_file *)malloc(sizeof(t_file *));
	if (p_file == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ERROR_CODE;
	}
	data_read_file(fd, p_file);
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

	void *p_connection_id;
	void	*p_window_id;
	t_size	window_size;
	t_size	*p_window_size;
	t_window_config	window_config;
	t_window_config	*p_window_config;
	char *window_title;

	window_title = "fdf_1";
	p_window_size = &window_size;
	p_window_size->x = 720;
	p_window_size->y = 720;







	report_connection_x_server(p_connection_id);



	p_connection_id = engine_init_connection();
//	engine_get_screen_size();




	p_window_config = init_window_config(p_connection_id, p_window_size, window_title);
	p_window_id = engine_create_window(p_window_config);
	report_create_window(p_window_id);

	void	*img;
	char	c = 48;
	char 	*p_c = &c;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_point point1 = {10, 10}, *p1 = &point1;
	t_point point2= {100, 100}, *p2 = &point2;

	red = 0;
	green = 0;
	blue = 0;

	t_color	color = {100, 27, 200}, *p_color = &color;
	t_point pp0 = {0, 0};
	t_param	parm = {p_connection_id, p_window_id, img, p_window_size->x, p_window_size->y, p_c, p_color, &pp0, 0};
	t_param	*param = &parm;



	mlx_key_hook(p_window_id, engine_key_event, param);
	mlx_mouse_hook(p_window_id, engine_mouse_event, param);

	//engine_check_endian();
	//engine_display_pixel(p_pixel);

	//print_matrix(fran, 10, 10);
	engine_draw(p_matrix, param);
	mlx_hook(p_window_id, 17, 0, engine_close_window, p_connection_id);
	mlx_loop(p_connection_id);
	return (0);

}

t_window_config	*init_window_config(void *p_connection_id, t_size *p_window_size, char *window_title)
{
	t_window_config	*p_window_config;
	t_window_config	window_config;

	p_window_config = &window_config;
	p_window_config->p_connection_id = p_connection_id;
	p_window_config->title = window_title;
	p_window_config->p_window_size = p_window_size;
	return (p_window_config);
}
