/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:34:05 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 08:47:07 by lnyamets         ###   ########.fr       */
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
