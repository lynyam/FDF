/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:51:21 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 02:19:15 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_digit(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c < '0' + base);
	else
		return ((c >= '0' && c <= '9') || (c >= 'a' && c < 'a' + base - 10)
			|| (c >= 'A' && c < 'A' + base - 10));
}

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long		result;
	const char	*p;
	int			digit;

	p = str;
	result = 0;
	p += 2;
	while (is_digit(*p, base))
	{
		digit = char_to_digit(*p);
		if (digit < 0 || digit >= base)
			break ;
		result = result * base + digit;
		++p;
	}
	if (endptr)
		*endptr = (char *)p;
	return (result);
}
