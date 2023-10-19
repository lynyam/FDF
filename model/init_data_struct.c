/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:52:01 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 14:21:13 by lnyamets         ###   ########.fr       */
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
