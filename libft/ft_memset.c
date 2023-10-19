/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:27:20 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/18 20:27:31 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	if (n == 0)
		return (s);
	new = s;
	while (i < n)
	{
		new[i++] = c;
	}
	return (s);
}
