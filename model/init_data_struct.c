/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:25:55 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:26:00 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void	init_s_point_color(t_point_color *p_point_color, int value, int all)
{
	if (all)
		p_point_color->z = value;
	p_point_color->color.red = value;
	p_point_color->color.green = value;
	p_point_color->color.blue = value;
}

void	init_t_init(t_init_m *init)
{
	init->col = 0;
	init->row = 0;
	init->end = NULL;
	init->start = NULL;
}
