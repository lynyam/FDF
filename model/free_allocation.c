/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:34:05 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 12:48:59 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

char	*rtn_null_free_charptr(char *rtn)
{
	free(rtn);
	return (NULL);
}

void	free_charptr(char *rtn)
{
	free(rtn);
}
