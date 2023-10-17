/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:39:01 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 00:49:10 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_horizontal_line(t_pair pair0, int inc_x, t_window *p_window)
{
	int	x;

	x = pair0.p1.x;
	while (x != pair0.p2.x + inc_x)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id,
			x, pair0.p1.y, p_window->color);
		x += inc_x;
	}
}

void	draw_vertical_line(t_pair pair0, int inc_y, t_window *p_window)
{
	int	y;

	y = pair0.p1.y;
	while (y != pair0.p2.y + inc_y)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id,
			pair0.p1.x, y, p_window->color);
		y += inc_y;
	}
}

void	draw_steep_line(t_pair pair0, t_point inc_p, t_point dp,
	t_window *p_window)
{
	int	x;
	int	y;
	int	slope;
	int	error;
	int	error_inc;

	slope = 2 * dp.y;
	error = -dp.x;
	error_inc = -2 * dp.x;
	x = pair0.p1.x;
	y = pair0.p1.y;
	while (x != pair0.p2.x + inc_p.x)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id, x, y,
			p_window->color);
		error += slope;
		if (error >= 0)
		{
			y += inc_p.y;
			error += error_inc;
		}
		x += inc_p.x;
	}
}

void	draw_gentle_line(t_pair pair0, t_point inc_p, t_point dp,
	t_window *p_window)
{
	int	x;
	int	y;
	int	slope;
	int	error;
	int	error_inc;

	x = pair0.p1.x;
	y = pair0.p1.y;
	slope = 2 * dp.x;
	error = -dp.y;
	error_inc = -2 * dp.y;
	while (y != pair0.p2.y + inc_p.y)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id, x, y,
			p_window->color);
		error += slope;
		if (error >= 0)
		{
			x += inc_p.x;
			error += error_inc;
		}
		y += inc_p.y;
	}
}

void	engine_plot_line(t_pair *p_pair, t_window *p_window)
{
	t_point	dp;
	t_point	inc_p;
	t_pair	pair0;

	p_window->color = 900;
	pair0.p1.x = p_pair->p1.x;
	pair0.p1.y = p_pair->p1.y;
	pair0.p2.x = p_pair->p2.x;
	pair0.p2.y = p_pair->p2.y;
	dp.x = pair0.p2.x - pair0.p1.x;
	dp.y = pair0.p2.y - pair0.p1.y;
	inc_p.x = sgn(dp.x);
	inc_p.y = sgn(dp.y);
	dp.x = abs(dp.x);
	dp.y = abs(dp.y);
	if (dp.y == 0)
		draw_horizontal_line(pair0, inc_p.x, p_window);
	if (dp.x == 0)
		draw_vertical_line(pair0, inc_p.y, p_window);
	else if (dp.x >= dp.y)
		draw_steep_line(pair0, inc_p, dp, p_window);
	else
		draw_gentle_line(pair0, inc_p, dp, p_window);
}
