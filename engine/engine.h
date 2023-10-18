/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:47:03 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/17 20:58:13 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define PI 3.14
# include "../report/report.h"
# include "../model/model.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_window
{
	void		*p_connection_id;
	void		*p_window_id;
	void		*p_img_id;
	int			width;
	int			height;
	char		*title;
	int			color;
}				t_window;

void	engine_create_window(t_window *p_window);
void	draw_horizontal_lines(t_matrix *p_matrix, t_window *p_window);
void	draw_vertical_lines(t_matrix *p_matrix, t_window *p_window);
t_pair	engine_espace_to_iso(t_point p1_xy, t_point p2_xy, t_matrix *p_matrix,
			t_window *p_window);
void	engine_plot_line(t_pair *p_pair, t_window *p_window);
void	engine_draw(t_matrix *p_matrix, t_window *p_window);
void	engine_callback_hook(t_window *p_window);
int		engine_close_window(void *param);
int		engine_key_event(int key, t_window *p_window);
int		engine_mouse_event(int button, int x, int y, t_window *p_window);
int		color_to_int(struct s_color *p_color);
void	engine_plot_line(t_pair *p_pair, t_window *p_window);

#endif
