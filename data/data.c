/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:42:04 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/19 10:41:03 by lnyamets         ###   ########.fr       */
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
		//to do remplacer le memset
		ft_memset(p_file->buf, 0, BUFSIZE);
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
	t_point_color point;

	util_init_t_init(&init);
	while (*str != '\0')
	{
		while (*str == 32)
			str++;
		if (*str != 32 && *str != '\0')
			init.start = str;
		while (*str != 32 && *str != '\0' && *str != '\n')
			str++;
		if (*str == 32 || *str == '\0' || *str == '\n')
		{
			init.end = str;
			if (init.row < p_matrix->row && init.col < p_matrix->col)
			{
				point.z = 0;
				point.color.red = 0;
   				point.color.green = 0;
    			point.color.blue = 0;
				if (put_str_to_int(init, &point))
					(p_matrix->matrix)[init.row][init.col] = point;
			}
			else if (init.row == p_matrix->row && init.col == 0)
				return (RETURN_CODE_ONE);
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

unsigned int parseHexDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0; // Valeur par défaut si le caractère n'est pas hexadécimal
}

t_color	parse_color(const char *token)
{
    t_color color;
    color.red = 0;
    color.green = 0;
    color.blue = 0;
	if (token != NULL)
	{

        	color.red = (parseHexDigit(token[2]) << 4) | parseHexDigit(token[3]);
       		color.green = (parseHexDigit(token[4]) << 4) | parseHexDigit(token[5]);
        	color.blue = (parseHexDigit(token[6]) << 4) | parseHexDigit(token[7]);
   	 }
	 else
	{
		color.red = 255;
    	color.green = 255;
    	color.blue = 255;
	}
	printf("red = %d, green = %d, blue = %d,\n", color.red, color.green, color.blue);


    return color;
}
void extractRGB(int rgbValue, int *red, int *green, int *blue) {
    *red = (rgbValue >> 16) & 255;
    *green = (rgbValue >> 8) & 255;
    *blue = rgbValue & 255;
}

int	put_str_to_int(t_init_m init_m, t_point_color *z_color)
{
	int		len;
	char	current[(init_m.end - init_m.start) + 1];
	len = init_m.end - init_m.start;
	ft_strncpy(current, init_m.start, len);
	current[len] = '\0';
	char *token = ft_strtok(current, ",");
	if (token != NULL) {
		z_color->z = ft_atoi(token);
	}
	else
		return RETURN_CODE_ZERO;
	token = ft_strtok(NULL, ",");
	//z_color->color = parse_color(token);
	if (token != NULL){
		unsigned int val = (unsigned int)ft_strtol(token, NULL, 16);
		extractRGB(val, &(z_color->color.red), &(z_color->color.green), &(z_color->color.blue));
	}
	else{
		z_color->color.red = 255;
    	z_color->color.green = 255;
    	z_color->color.blue = 255;
	}
	return RETURN_CODE_ONE;
}
