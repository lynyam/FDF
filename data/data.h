/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:48 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 18:25:42 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include <stdbool.h>
# include "../report/report.h"
# include "../model/model.h"
# include "fcntl.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define BUFSIZE 1024

typedef struct s_init_m
{
	char		*start;
	char		*end;
	int			col;
	int			row;
}				t_init_m;

bool	data_validate_file_path(char *path);
int		data_open_file(char *file_name);
void	data_read_file(t_file *p_file);
bool	data_validate_file(int fd);
void	print_matrix(int **matrix, int line, int row);
void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix);
int		**data_storage_position(int fd);
#endif
