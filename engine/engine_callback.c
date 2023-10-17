/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:22:22 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/16 22:37:04 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_callback_hook(t_window *p_window)
{
	mlx_hook(p_window->p_window_id, 17, 0, engine_close_window,
		p_window->p_connection_id);
	mlx_key_hook(p_window->p_window_id, engine_key_event, (void *)p_window);
	mlx_mouse_hook(p_window->p_window_id, engine_mouse_event, (void *)p_window);
	mlx_loop(p_window->p_connection_id);
}

int	engine_close_window(void *param)
{
	exit(0);
}

int	engine_expose_win(t_window *p)
{
	mlx_new_window(p->p_window_id, p->width, p->height, p->title);
	return (0);
}

int	engine_key_event(int key, t_window *p_window)
{
	if (key == 0x35 || key == 0XFF1B)
	{
		exit(0);
	}
	return (0);
}

int	engine_mouse_event(int button, int x, int y, t_window *p_window)
{
	return (0);
}
