/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:22:55 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:44:50 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc != 2)
	{
		report_exit_program(INCORRECT_ARGS_ERROR);
		return (SUCCES_CODE);
	}
	ret = manager_start_processing(argv);
	return (ret);
}
