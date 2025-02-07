/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:04:51 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/07 22:34:29 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	free_matrix(t_matrix *p_matrix)
{
	int	i;

	if (p_matrix && p_matrix->matrix)
	{
		i = 0;
		while (i < p_matrix->row)
		{
			free(p_matrix->matrix[i]);
			i++;
		}
		free(p_matrix->matrix);
	}
	free(p_matrix);
}

void	engine_cleanup(t_window *p_window)
{
	if (!p_window)
		return ;
	if (p_window->p_img_id)
		mlx_destroy_image(p_window->p_connection_id, p_window->p_img_id);
	if (p_window->p_window_id)
		mlx_destroy_window(p_window->p_connection_id,
			p_window->p_window_id);
	if (p_window->p_matrix)
		free_matrix(p_window->p_matrix);
	if (p_window->p_file)
	{
		if (p_window->p_file->file_str)
			free(p_window->p_file->file_str);
		free(p_window->p_file);
	}
	if (p_window->p_connection_id)
	{
		mlx_destroy_display(p_window->p_connection_id);
		free(p_window->p_connection_id);
		p_window->p_connection_id = NULL;
	}
	free(p_window);
}
