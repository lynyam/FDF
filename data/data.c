/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:42:04 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 18:08:25 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	data_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	return (fd);
}

void	data_read_file(t_file *p_file)
{
	int		read_count;
	int		prev_read_count;

	p_file->file_str = NULL;
	prev_read_count = 0;
	p_file->first_line = 0;
	p_file->row = 0;
	p_file->col = 0;
	read_count = 1;

	while (read_count != 0)
	{
		memset(p_file->buf, 0, BUFSIZE);
		read_count = read(p_file->fd, p_file->buf, BUFSIZE);
		if (read_count != 0)
		{
			p_file->file_str = ft_concat(p_file, prev_read_count, read_count);
			if (p_file->file_str == NULL)
				return ;
			prev_read_count += read_count;
			p_file->row = count_row(p_file->buf, p_file->row);
			if (p_file->col == 0 || p_file->first_line != -1)
				p_file->first_line = count_col(p_file->buf, &(p_file->col));
		}
	}
	return ;
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
		//todo free matrix
		p_matrix->matrix = NULL;
		return;
	}
}

int	init_matrix_with_file(t_matrix *p_matrix, char *str)
{
	t_init_m	init;

	util_init_t_init(&init);
	while (*str != '\0')
	{
		if (*str != 32 && *str != '\0')
			init.start = str;
		while (*str != 32 && *str != '\0' && *str != '\n')
			str++;
		if (*str == 32 || *str == '\0' || *str == '\n')
		{
			init.end = str;
			if (init.row < p_matrix->row && init.col < p_matrix->col)
				(p_matrix->matrix)[init.row][init.col] = put_str_to_int(init);
			else
				return (RETURN_CODE_ZERO);
			if (*str == 32)
				init.col++;
			while (*str == 32)
				str++;
			if (*str == '\n')
				util_increment(&init, &str);
		}
	}
	return (RETURN_CODE_ONE);
}

int	put_str_to_int(t_init_m init_m)
{
	int		len;
	char	current[init_m.end - init_m.start];

	len = init_m.end - init_m.start;
	return (ft_atoi(ft_strlencpy(current, init_m.start, len)));
}
