/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:24:57 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 17:32:07 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void	count_row(char *buf, int *row)
{
	while (*buf != EOF && *buf != '\0')
	{
		if (*buf == '\n')
			*row += 1;
		buf++;
	}
}

int	is_valid_char(char c)
{
	if ((c >= '0' && c <= '9') || c == 32 || c == '\n' || c == '-')
		return (RETURN_CODE_ONE);
	return (RETURN_CODE_ZERO);
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

int	ft_strlen(char	*start, char *end)
{
	int	len;

	len = 0;
	while (start < end)
	{
		len++;
	}
	return (len);
}

char	*ft_concat(t_file *p_file, int prev_buf_count, int buf_count)
{
	char	*target;
	char	*rtn;
	int		new_len;

	new_len = prev_buf_count + buf_count;
	rtn = (char *)malloc(sizeof(char) * (new_len + 1));
	if (rtn == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return NULL;
	}
	target = rtn;
	target[new_len] = '\0';
	while (p_file->file_str && *(p_file->file_str) != '\0' && --prev_buf_count >= 0)
	{
		if (is_valid_char(*p_file->file_str) == 0)
			return NULL;
		*target++ = *(p_file->file_str)++;
	}
	while (*p_file->buf != '\0' && --buf_count >= 0)
	{
		if (is_valid_char(*(p_file->buf)) == 0)
			return NULL;
		*target++ = (*p_file->buf)++;
	}
	return (rtn);
}
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
