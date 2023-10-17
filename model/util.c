/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:24:57 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 03:14:20 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

int	is_valid_char(char c)
{
	if ((c >= '0' && c <= '9') || c == 32 || c == '\n' || c == '-')
		return (RETURN_CODE_ONE);
	return (RETURN_CODE_ZERO);
}

int	sgn(int x)
{
	if (x < 0)
	{
		return (-1);
	}
	else if (x > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	color_to_int(struct s_color *p_color)
{
	return (((p_color->red) << 16) | ((p_color->green) << 8) | (p_color->blue));
}

void	util_init_t_init(t_init_m *init)
{
	init->col = 0;
	init->row = 0;
	init->end = NULL;
	init->start = NULL;
}

void	util_increment(t_init_m *init, char **str)
{
	init->row++;
	init->col = 0;
	*str += 1;
}
