#ifndef ENGINE_H
# define ENGINE_H
# define ABS(X) ((X) >= 0 ? (X) : -(X))
# define SGN(X) ((X) < 0 ? -1 : ((X) > 0 ? 1 : 0))
# define PI 3.14


#include "../report/report.h"
#include "../model/model.h"
#include "../mlx/mlx.h"
#include <stdbool.h>
#include <math.h>
void	*engine_init_connection();
int**	convert_to_isometric(int **map_in_space);
int*	create_windows();
int	display_map();
int	engine_close_window(void *param);
#include <string.h>
#include <stdlib.h>

typedef struct		s_color {
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}			t_color;

typedef	struct	s_point {
	int	x;
	int	y;
}		t_point;


typedef struct	s_window_config {
	void	*p_connection_id;
	t_size	*p_window_size;
	char	*title;
	t_color	*p_color;
}		t_window_config;

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

void    *engine_create_window(t_window_config *p_window_config);
int     engine_expose_win(t_param *p);
int	engine_key_event(int key, t_window_config *p_window_config);
int	engine_mouse_event(int button, int x, int y, t_param *param);
int     engine_display_pixel(t_pixel *pixel);
int     engine_check_endian();
void	engine_plot_line(t_point *point1, t_point *point2, t_param *param);
void	engine_plot_line_opti(t_point *point1, t_point *point2, t_param *param);
void	engine_plot_line3(t_point *point1, t_point *point2, t_param *param);
t_point	engine_espace_to_iso(t_espace espace);
void    draw_isometric(t_espace *object, t_param *param, int nbr_node);
void    engine_draw(t_matrix *p_matrix, t_param *param);
#endif
