/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:52:12 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/05 06:52:17 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define PI 3.14
# include "../report/report.h"
# include "../model/model.h"
# include "../minilibx-linux/mlx.h"
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
	t_color		color;
	char		*pixel_str;
	int			bits_per_pixel;
	int			endian;
	int			row_size;
}				t_window;

void	engine_create_image(t_window *p_window);
void	draw_horizontal_lines(t_matrix *p_matrix, t_window *p_window);
void	draw_vertical_lines(t_matrix *p_matrix, t_window *p_window);
t_pair	engine_espace_to_iso(t_point p1_xy, t_point p2_xy, t_matrix *p_matrix,
			t_window *p_window);
void	engine_plot_line(t_pair *p_pair, t_window *p_window);
void	engine_draw(t_matrix *p_matrix, t_window *p_window);
void	engine_callback_hook(t_window *p_window);
int		engine_close_window(void);
int		engine_key_event(int key);
void	engine_pixel_put(t_window *p_window, int x, int y);
int		ft_key_hook(int key);

#endif
