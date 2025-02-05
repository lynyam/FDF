/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:27:33 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:27:45 by ynyamets         ###   ########.fr       */
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
