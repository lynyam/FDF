/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:28:11 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 03:07:01 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void	allocate_matrix(t_matrix *p_matrix)
{
	int	i;

	p_matrix->matrix = (int **)malloc(p_matrix->row * sizeof(int *));
	if (p_matrix->matrix != NULL)
	{
		i = 0;
		while (i < p_matrix->row)
		{
			(p_matrix->matrix)[i] = (int *)malloc(p_matrix->col * sizeof(int));
			i++;
		}
	}
	return ;
}

char	*ft_concat(t_file *p_file, int prev_buf_cnt, int buf_count)
{
	char	*target;
	char	*rtn;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (prev_buf_cnt + buf_count + 1));
	if (rtn == NULL)
		return (NULL);
	target = rtn;
	target[prev_buf_cnt + buf_count] = '\0';
	i = 0;
	while (p_file->file_str && *(p_file->file_str) != '\0' && i < prev_buf_cnt)
	{
		if (is_valid_char(*p_file->file_str) == 0)
			return (NULL);
		*target++ = p_file->file_str[i++];
	}
	i = 0;
	while (*p_file->buf != '\0' && i < buf_count)
	{
		if (is_valid_char(*(p_file->buf)) == 0)
			return (NULL);
		*target++ = p_file->buf[i++];
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
