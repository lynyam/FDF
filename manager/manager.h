/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:24:17 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:24:21 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H
# include "../engine/engine.h"
# include "../data/data.h"
# include "../model/model.h"
# include "../report/report.h"
# include <stdio.h>

int		manager_start_processing(char **argv);
int		manager_read_arg(char **argv, t_file **pp_file);
int		manager_store_data(t_file *p_file, t_matrix **pp_matrix);
void	manager_init_p_window(t_window *p_window, char **argv);

#endif
