/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:26:25 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:26:32 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void	allocate_matrix(t_matrix *p_matrix)
{
	int	i;

	p_matrix->matrix = (t_point_color **)malloc(p_matrix->row
			* sizeof(t_point_color *));
	if (p_matrix->matrix != NULL)
	{
		i = 0;
		while (i < p_matrix->row)
		{
			(p_matrix->matrix)[i] = (t_point_color *)malloc(p_matrix->col
					* sizeof(t_point_color));
			i++;
		}
	}
	return ;
}

char	*ft_concat(t_file *p_file, int prev_buf_cnt, int buf_count)
{
	char	*rtn;
	int		i;
	int		j;

	rtn = (char *)malloc(sizeof(char) * (prev_buf_cnt + buf_count) + 2);
	if (rtn == NULL)
		return (rtn_null_free_charptr(rtn));
	i = 0;
	rtn[prev_buf_cnt + buf_count] = '\0';
	while (i < prev_buf_cnt)
	{
		rtn[i] = p_file->file_str[i];
		i++;
	}
	j = 0;
	while (j < buf_count)
	{
		if (is_valid_char(*(p_file->buf)) == 0)
			return (rtn_null_free_charptr(rtn));
		rtn[i + j] = p_file->buf[j];
		j++;
	}
	return (rtn);
}

int	count_col(char *buf, int *col)
{
	while (*buf != EOF && *buf != '\0' && *buf != '\n')
	{
		while (*buf != 32 && *buf != EOF && *buf != '\0' && *buf != '\n')
			buf++;
		if (*buf == 32)
			*col += 1;
		while (*buf == 32)
			buf++;
	}
	if (*buf == '\n')
	{
		*col += 1;
		return (-1);
	}
	return (0);
}

int	count_row(char *buf, int row)
{
	while (*buf != EOF && *buf != '\0')
	{
		if (*buf == '\n')
			row += 1;
		buf++;
	}
	return (row);
}

int	get_matrice_size(t_matrix	*p_matrix)
{
	if (p_matrix->col >= p_matrix->row)
	{
		return (p_matrix->col);
	}
	else
	{
		return (p_matrix->row);
	}
}
