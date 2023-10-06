/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:42:04 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 02:51:06 by lnyamets         ###   ########.fr       */
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
	return fd;
}

void	count_line(char *buf, int *line)
{
	while (*buf != EOF && *buf != '\0')
	{
		if (*buf == '\n')
			*line += 1;
		else
			;
		buf++;
	}
}

int	count_row(char *buf, int *row)
{
	while (*buf != EOF && *buf != '\0' && *buf != '\n')
	{
		while (*buf != 32 && *buf != EOF && *buf != '\0' && *buf != '\n')
			buf++;
		if (*buf == 32)
			*row += 1;
		while (*buf == 32)
			buf++;
	}
	if (*buf == '\n')
	{
		*row += 1;
		return (-1);
	}
	return (0);
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
			(p_matrix->matrix)[i++] = (int *)malloc(p_matrix->col * sizeof(int));
		}
	}
	return;
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

int	put_str_to_int(char *start, char *end)
{
	int	nbr;
	int	len;
	char	*current;

	nbr = 0;
	len = end - start - 1;
	current = start;
	if (*start == '-')
	{
		len--;
		current = start - 1;
	}
	while (len >= 0)
	{
		nbr += (pow(10, len) * (*current - '0'));
		current++;
		len--;
	}
	if (*start == '-')
		nbr *= (-1);
	return nbr;
}

void	print_matrix(int **matrix, int n, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int	init_matrix_with_file(t_matrix *p_matrix, char *str)
{
	char	*start;
	char	*end;
	int	index_row;
	int	index_line;
	char	*curr;

	index_row = 0;
	index_line = 0;
	curr = str;
	while (*curr != '\0')
	{
		if (*curr != 32 && *curr != '\0')
		{
			start = curr;
		}
		while (*curr != 32 && *curr != '\0' && *curr != '\n')
		{
			curr++;
		}
		if (*curr == 32 || *curr == '\0' || *curr =='\n')
		{
			end = curr;
			if (index_line < p_matrix->row && index_row < p_matrix->col)
			{
				(p_matrix->matrix)[index_line][index_row] = put_str_to_int(start, end);
			}
			else
			{
				return (0);
			}
             		if (*curr == 32)
			{
				index_row++;
			}
			while (*curr == 32)
			{
				curr++;
			}
			if (*curr == '\n')
			{
				index_line++;
				index_row = 0;
				curr++;
			}
		}
	}
	return (1);
}

int	is_valid_char(char c)
{
	if ((c >= '0' && c <= '9') || c == 32 || c == '\n' || c == '-')
		return (1);
	return (0);
}

char	*ft_concat(char *s1, char *s2, int s1_len, int nbr_char_s2)
{
	char	*target;
	char	*rtn;

	rtn = (char *)malloc(sizeof(char) * (s1_len + nbr_char_s2 + 1));
	target = rtn;
	//if (target == NULL)
		//return NULL;
	target[s1_len + nbr_char_s2] = '\0';
	while (s1 && *s1 != '\0' && --s1_len >= 0)
	{
		if (is_valid_char(*s1) == 0)
			return NULL;
		*target++ = *s1++;
	}
	while (*s2 != '\0' && --nbr_char_s2 >= 0)
	{
		if (is_valid_char(*s2) == 0)
			return NULL;
		*target++ = *s2++;
	}
	return (rtn);
}

void	data_read_file(int fd, t_file *p_file)
{
	int		read_count;
	int		prev_read_count;

	p_file->file_str = NULL;
	prev_read_count = 0;
	p_file->first_line = 0;
	while ((read_count = read(fd, p_file->buf, BUFSIZE)) > 0)
	{
		p_file->file_str = ft_concat(p_file->file_str, p_file->buf,
										prev_read_count, read_count);
		prev_read_count = read_count;
		count_line(p_file->buf, &(p_file->row));
		if (p_file->col == 0 || p_file->first_line != -1)
			p_file->first_line = count_row(p_file->buf, &(p_file->col));
	}
	return;
}

void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix)
{
	p_matrix->row = p_file->row;
	p_matrix->col = p_file->col;
	allocate_matrix(p_matrix);
	if (p_matrix->matrix == NULL)
	{
		report_exit_program(ALLOCATED_ERROR);
		return;
	}
	if (init_matrix_with_file(p_matrix, p_file->file_str) != 1)
		report_exit_program(DATA_STRUCT_INIT_ERROR);
	return;
}
