#ifndef ENGINE_H
# define ENGINE_H
#include "../report/report.h"
#include "../model/model.h"
#include "../mlx/mlx.h"
#include <stdbool.h>
void	*engine_init_connection();
int**	convert_to_isometric(int **map_in_space);
int*	create_windows();
int	display_map();
#include <string.h>
#include <stdlib.h>

typedef struct s_color {
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
} t_color;

typedef struct s_window_config {
	void	*p_connection_id;
	t_size	*p_window_size;
	char	*title;
	t_color	*p_color;
} t_window_config;

typedef	struct s_param {
	void *mlx;
	void *win;
	void *img;
	int	x;
	int	y;
	char *ti;
	t_color	*p_color;
} t_param;

typedef struct	s_pixel {
	void	*connection_id;
	void	*window_id;
	int	x;
	int	y;
	t_color	*p_color;
}		t_pixel;



void    *engine_create_window(t_window_config *p_window_config);
int     engine_expose_win(t_param *p);
int	engine_key_event(int key, t_window_config *p_window_config);
int	engine_mouse_event(int button, int x, int y, t_param *param);
int     engine_display_pixel(t_pixel *pixel);
int     engine_check_endian();
#endif
