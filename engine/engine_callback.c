/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:22:22 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 11:40:35 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_callback_hook(t_window *p_window)
{

	mlx_put_image_to_window(p_window->p_connection_id,
	 	p_window->p_window_id, p_window->p_img_id, 0, 0);
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

int			ft_loop_key_hook(t_window *p_window)
{
	p_window->pixel_str = mlx_get_data_addr(p_window->p_img_id,
		&(p_window->bits_per_pixel), &(p_window->row_size),
		&(p_window->endian));
	//mlx_put_image_to_window(p_window->p_connection_id,
		//p_window->p_window_id, p_window->p_img_id, 0, 0);
	//mlx_destroy_image(p_window->p_connection_id, p_window->p_img_id);
	//p_window->p_img_id = mlx_new_image(p_window->p_connection_id,
		//p_window->width, p_window->height);
	return (0);
}

int	ft_key_hook(int key, t_window *p_window)
{
	if (key == 0x35 || key == 0XFF1B)
	{
		exit(0);
	}
	return (0);
}
