/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:48 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/18 21:50:07 by lnyamets         ###   ########.fr       */
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
int	put_str_to_int(t_init_m init_m, t_point_color *z_color);
void	increment(t_init_m *init, char **str);
void	data_store_file_in_matrix(t_file *p_file, t_matrix *p_matrix);

#endif
