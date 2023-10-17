/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:39:50 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/16 22:39:49 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H
# include "../engine/engine.h"
# include "../data/data.h"
# include "../model/model.h"
# include "../report/report.h"
# include <stdio.h>

int	manager_start_processing(char **argv);
int	manager_read_arg(char **argv, t_file **pp_file);
int	manager_store_data(t_file *p_file, t_matrix **pp_matrix);
#endif
