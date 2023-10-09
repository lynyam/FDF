/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:42:04 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 18:25:17 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	data_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		report_exit_program("OPEN_FILE_ERROR");
	}
	return (fd);
}

int	put_str_to_int(t_init_m init_m)
{
	int		nbr;
	int		len;
	char	*current;

	nbr = 0;
	len = init_m.end - init_m.start - 1;
	current = init_m.start;
	if (*init_m.start == '-')
	{
		len--;
		current = init_m.start - 1;
	}
	while (len >= 0)
	{
		nbr += (pow(10, len) * (*current - '0'));
		current++;
		len--;
	}
	if (*init_m.start == '-')
		nbr *= (-1);
	return (nbr);
}

void	increment(t_init_m *init, char *str)
{
	init->row++;
	init->col = 0;
	str++;
}

int	init_matrix_with_file(t_matrix *p_matrix, char *str)
{
	t_init_m	init;

	init.col = 0;
	init.row = 0;
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
				increment(&init, str);
		}
	}
	return (RETURN_CODE_ONE);
}

void	data_read_file(t_file *p_file)
{
	int		read_count;
	int		prev_read_count;

	p_file->file_str = NULL;
	prev_read_count = 0;
	p_file->first_line = 0;
	read_count = read(p_file->fd, p_file->buf, BUFSIZE);
	while (read_count > 0)
	{
		p_file->file_str = ft_concat(p_file, prev_read_count, read_count);
		prev_read_count = read_count;
		count_row(p_file->buf, &(p_file->col));
		if (p_file->col == 0 || p_file->first_line != -1)
			p_file->first_line = count_col(p_file->buf, &(p_file->col));
		read_count = read(p_file->fd, p_file->buf, BUFSIZE);
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
		report_exit_program(DATA_STRUCT_INIT_ERROR);
	return ;
}
