/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:47:03 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/13 19:00:54 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define ABS(X) ((X) >= 0 ? (X) : -(X))
# define SGN(X) ((X) < 0 ? -1 : ((X) > 0 ? 1 : 0))
# define PI 3.14
# include "../report/report.h"
# include "../model/model.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct	s_window {
	void		*p_connection_id;
	void		*p_window_id;
	int			width;
	int			height;
	char		*title;
	t_color		*p_color;
}				t_window;

void	engine_connect_x_server(t_window *p_window);
void	engine_create_window(t_window *p_window);
t_pair engine_espace_to_iso(int p1_x, int p1_y, int p2_x, int p2_y, t_matrix *p_matrix, t_window *p_wndow);
void	engine_create_window(t_window *p_window);

int**	convert_to_isometric(int **map_in_space);
int*	create_windows();
int	display_map();
int	engine_close_window(void *param);
typedef	struct	s_param {
	void	*mlx;
	void	*win;
	void	*img;
	int	x;
	int	y;
	char	*ti;
	t_color	*p_color;
	t_point	*p0;
	int	compteur;
}		t_param;

typedef struct	s_pixel {
	void	*connection_id;
	void	*window_id;
	int	x;
	int	y;
	t_color	*p_color;
}		t_pixel;

typedef struct	s_espace {
	int	x;
	int	y;
	int	z;
}		t_espace;
void	engine_create_window(t_window *p_window);
void	engine_draw(t_matrix *p_matrix, t_window *p_window);
void engine_plot_line(t_pair *p_pair, t_window *p_window);
void	draw_line_slope(t_window *p_window, t_pair *p_pair, int dx, int dy, int incX, int incY);
void	draw_line_horizontal(t_window *p_window, t_pair *p_pair, int incX);
void	draw_slope(t_window *p_window, int x0, int y0, int x1, int y1, int dx, int dy, int incX, int incY);
void	draw_horizontal_line(t_window *p_window, int x0, int x1, int y, int c, int incX);
int	color_to_int(struct s_color *p_color);
int	engine_close_window(void *param);
void    engine_callback_hook(t_window *p_window);

void	draw_line_slope(t_window *p_window, t_pair *p_pair, int dx, int dy, int incX, int incY);
void	draw_line_horizontal(t_window *p_window, t_pair *p_pair, int incX);
void	draw_slope(t_window *p_window, int x0, int y0, int x1, int y1, int dx, int dy, int incX, int incY);
void	draw_horizontal_line(t_window *p_window, int x0, int x1, int y, int c, int incX);
int	color_to_int(struct s_color *p_color);
int	engine_close_window(void *param);
void    engine_callback_hook(t_window *p_window);


#endif
