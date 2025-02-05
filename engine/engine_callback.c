/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:49:37 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:50:06 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_callback_hook(t_window *p_window)
{
	mlx_put_image_to_window(p_window->p_connection_id,
		p_window->p_window_id, p_window->p_img_id, 0, 0);
	mlx_hook(p_window->p_window_id, 17, 0, engine_close_window,
		(void *)p_window);
	mlx_key_hook(p_window->p_window_id, engine_key_event, (void *)p_window);
	mlx_loop(p_window->p_connection_id);
}

int	engine_close_window(void)
{
	exit(0);
}

int	engine_expose_win(t_window *p)
{
	mlx_new_window(p->p_window_id, p->width, p->height, p->title);
	return (0);
}

int	engine_key_event(int key)
{
	if (key == 0x35 || key == 0XFF1B)
	{
		exit(0);
	}
	return (0);
}

int	ft_key_hook(int key)
{
	if (key == 0x35 || key == 0XFF1B)
	{
		exit(0);
	}
	return (0);
}
