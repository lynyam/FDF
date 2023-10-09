/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:22:22 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/09 21:51:19 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void    engine_callback_hook(t_window *p_window)
{

	mlx_hook(p_window->p_window_id, 17, 0, engine_close_window, p_window->p_connection_id);
	mlx_key_hook(p_window->p_window_idp_window_id, engine_key_event, param);
    mlx_mouse_hook(p_window_id, engine_mouse_event, param);

}

int	engine_close_window(void *param)
{
    exit(0);
}


int	engine_expose_win(t_param *p)
{
//	printf("expose x = %d, y = %d\n", p->x, p->y);
	//mlx_new_window(p->mlx, p->x, p->y, p->ti);
	mlx_new_window(p->mlx, 721, 721, p->ti);
	(p->x) -= 50;
	(p->y) -= 50;
	*(p->ti) = *(p->ti) + 1;
	return 0;
}

int     engine_key_event(int key, t_window_config *p_window_config)
{
	if (key == 0x35 || key == 0XFF1B)
	{
		exit(0);
	}
	return 0;
}
//test
int     engine_mouse_event(int button, int x, int y, t_param *param)
{
	if (button == 1 || button == 5)
	{
		int color = ((param->p_color->red) << 16) | ((param->p_color->green) << 8) | (param->p_color->blue);
		mlx_pixel_put(param->mlx, param->win, x, y, color);
		if (param->p_color->red < 255)
		{
			(param->p_color->red) += 1;
		}
		if (param->p_color->green < 255)
		{
			(param->p_color->green) += 2;
		}
		if (param->p_color->blue < 255)
		{
			(param->p_color->blue) += 3;
		}
		if (param->compteur == 0)
		{
			param->p0->x = x;
			param->p0->y = y;
			param->compteur = 1;
		}
		else
		{
			t_point p;
			p.x = x;
			p.y = y;
			//engine_plot_line_opti(param->p0, &p, param);
			engine_plot_line(param->p0, &p, param);
			param->p0->x = p.x;
			param->p0->y = p.y;
		}
	}
	return 0;
}