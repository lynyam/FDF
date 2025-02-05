/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:51:43 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:51:47 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_pixel_put(t_window *p_window, int x, int y)
{
	if ((x > 0 && y > 0 && x < p_window->width && y < p_window->height))
	{
		p_window->pixel_str[((x * 4 + (y * p_window->row_size)))]
			= p_window->color.blue;
		p_window->pixel_str[((x * 4 + (y * p_window->row_size))) + 1]
			= p_window->color.green;
		p_window->pixel_str[((x * 4 + (y * p_window->row_size))) + 2]
			= p_window->color.red;
	}
}
