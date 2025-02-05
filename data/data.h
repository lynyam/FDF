/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:54:07 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:54:11 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include <stdbool.h>
# include "../report/report.h"
# include "../model/model.h"
# include "../libft/libft.h"
# include "fcntl.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int		data_open_file(char *file_name);
void	data_read_file(t_file *p_file);
int		init_matrix_with_file(t_matrix *p_matrix, char *str);
int		put_str_to_int(t_init_m init_m, t_point_color *z_color);
void	increment(t_init_m *init, char **str);
void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix);
char	*data_process_token(t_init_m *init, t_matrix *p_matrix, char *str,
			t_point_color *point);
void	data_extract_rgb(int rgbValue, int *red, int *green, int *blue);

#endif
