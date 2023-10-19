/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:24:57 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 14:48:33 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

int	is_valid_char(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F') || c == 'x' || c == ','
		|| c == 32 || c == '\n' || c == '-')
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

void	util_increment(t_init_m *init, char **str)
{
	init->row++;
	init->col = 0;
	*str += 1;
}

char	*util_skip_whitespace(char *str)
{
	while (*str == 32)
		str++;
	return (str);
}

char	*util_skip_to_next_token(char *str)
{
	while (*str != 32 && *str != '\0' && *str != '\n')
		str++;
	return (str);
}
