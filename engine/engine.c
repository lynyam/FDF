/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:38:48 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 00:55:24 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_create_window(t_window *p_window)
{
	p_window->p_connection_id = mlx_init();
	report_connection_x_server(p_window->p_connection_id);
	mlx_get_screen_size(p_window->p_connection_id, &p_window->width,
		&p_window->height);
	p_window->p_window_id = mlx_new_window(p_window->p_connection_id,
			p_window->width, p_window->height, p_window->title);
	report_create_window(p_window);
}

void	draw_horizontal_lines(t_matrix *p_matrix, t_window *p_window)
{
	int		i;
	int		j;
	t_pair	pair;
	t_point	p1_xy;
	t_point	p2_xy;

	i = 0;
	while (i < p_matrix->row)
	{
		j = 0;
		while (j < p_matrix->col && j + 1 < p_matrix->col)
		{
			p1_xy.x = i;
			p1_xy.y = j;
			p2_xy.x = i;
			p2_xy.y = j + 1;
			pair = engine_espace_to_iso(p1_xy, p2_xy, p_matrix, p_window);
			engine_plot_line(&pair, p_window);
			j++;
		}
		i++;
	}
}

void	draw_vertical_lines(t_matrix *p_matrix, t_window *p_window)
{
	int		i;
	int		j;
	t_pair	pair;
	t_point	p1_xy;
	t_point	p2_xy;

	j = 0;
	while (j < p_matrix->col)
	{
		i = 0;
		while (i < p_matrix->row && i + 1 < p_matrix->row)
		{
			p1_xy.x = i;
			p1_xy.y = j;
			p2_xy.x = i + 1;
			p2_xy.y = j;
			pair = engine_espace_to_iso(p1_xy, p2_xy, p_matrix, p_window);
			engine_plot_line(&pair, p_window);
			i++;
		}
		j++;
	}
}

void	engine_draw(t_matrix *p_matrix, t_window *p_window)
{
	draw_horizontal_lines(p_matrix, p_window);
	draw_vertical_lines(p_matrix, p_window);
}

t_pair	engine_espace_to_iso(t_point p1_xy, t_point p2_xy, t_matrix *p_matrix,
t_window *p_window)
{
	t_pair	pair;
	int		scale;
	int		translation_x;
	int		translation_y;

	translation_y = p_window->height / 2;
	translation_x = p_window->width / 2;
	scale = 10;
	pair.p1.x = scale * (-p1_xy.x + p1_xy.y) + translation_x;
	pair.p1.y = scale * (p1_xy.x + p1_xy.y) * 0.5
		- p_matrix->matrix[p1_xy.x][p1_xy.y] + translation_y;
	pair.p2.x = scale * (-p2_xy.x + p2_xy.y) + translation_x;
	pair.p2.y = scale * (p2_xy.x + p2_xy.y) * 0.5
		- p_matrix->matrix[p2_xy.x][p2_xy.y] + translation_y;
	return (pair);
}
