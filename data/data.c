/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:53:06 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/07 22:29:51 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static int	process_buffer(t_file *p_file, int *prev_read_count)
{
	int		read_count;
	char	*temp;

	ft_memset(p_file->buf, 0, BUFSIZE);
	read_count = read(p_file->fd, p_file->buf, BUFSIZE);
	if (read_count < 0)
		return (-1);
	if (read_count != 0)
	{
		temp = ft_concat(p_file, *prev_read_count, read_count);
		if (temp == NULL)
			return (-1);
		if (p_file->file_str != NULL)
			free(p_file->file_str);
		p_file->file_str = temp;
		*prev_read_count += read_count;
		p_file->row = count_row(p_file->buf, p_file->row);
		if (p_file->col == 0 || p_file->first_line != -1)
			p_file->first_line = count_col(p_file->buf, &(p_file->col));
	}
	return (read_count);
}

void	data_read_file(t_file *p_file)
{
	int	read_count;
	int	prev_read_count;

	p_file->file_str = NULL;
	prev_read_count = 0;
	p_file->first_line = 0;
	p_file->row = 0;
	p_file->col = 0;
	read_count = 1;
	while (read_count != 0)
	{
		read_count = process_buffer(p_file, &prev_read_count);
		if (read_count == -1)
			return ;
	}
}

void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix)
{
	p_matrix->row = p_file->row;
	p_matrix->col = p_file->col;
	allocate_matrix(p_matrix);
	if (p_matrix->matrix == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return ;
	}
	if (init_matrix_with_file(p_matrix, p_file->file_str) != 1)
	{
		report_exit_program(DATA_STRUCT_INIT_ERROR);
		p_matrix->matrix = NULL;
		return ;
	}
}

int	init_matrix_with_file(t_matrix *p_matrix, char *str)
{
	t_init_m		init;
	t_point_color	point;

	init_t_init(&init);
	init_s_point_color(&point, 0, 1);
	while (*str != '\0')
	{
		str = data_process_token(&init, p_matrix, str, &point);
		if (str == NULL)
			return (RETURN_CODE_ZERO);
	}
	return (RETURN_CODE_ONE);
}

int	put_str_to_int(t_init_m init_m, t_point_color *z_color)
{
	char			*current;
	char			*token;

	current = (char *)malloc(1 + init_m.end - init_m.start);
	ft_strncpy(current, init_m.start, init_m.end - init_m.start);
	current[init_m.end - init_m.start] = '\0';
	token = ft_strtok(current, ",");
	if (token != NULL)
		z_color->z = ft_atoi(token);
	else
	{
		free(current);
		return (RETURN_CODE_ZERO);
	}
	token = ft_strtok(NULL, ",");
	if (token != NULL)
		data_extract_rgb(ft_strtol(token, NULL, 16), &(z_color->color.red),
			&(z_color->color.green), &(z_color->color.blue));
	else
		init_s_point_color(z_color, 255, 0);
	free(current);
	return (RETURN_CODE_ONE);
}
