/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:38:33 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 01:38:37 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new;

	new = (char *)s;
	while (*new != c)
	{
		if (*new == '\0')
			return (NULL);
		new++;
	}
	return (new);
}
