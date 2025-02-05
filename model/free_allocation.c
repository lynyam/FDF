/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:25:38 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:25:42 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void	*rtn_null_free_charptr(char *rtn)
{
	free(rtn);
	return (NULL);
}

void	free_charptr(char *rtn)
{
	free(rtn);
}
