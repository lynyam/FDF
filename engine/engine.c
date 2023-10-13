#include "engine.h"

void	engine_connect_x_server(t_window *p_window)
{
	p_window->p_connection_id =  mlx_init();
	report_connection_x_server(p_window->p_connection_id);
}

void	engine_create_window(t_window *p_window)
{
    mlx_get_screen_size(p_window->p_connection_id, &p_window->width, &p_window->height);
	p_window->p_window_id = mlx_new_window(p_window->p_connection_id,
		p_window->width, p_window->height, p_window->title);
	report_create_window(p_window);
}

void	engine_draw(t_matrix *p_matrix, t_window *p_window)
{
	int	i;
	int	j;
	t_pair pair;

	i = 0;
	while (i < p_matrix->row)
	{
		j = 0;
		while (j < p_matrix->col && j + 1 < p_matrix->col)
		{
			pair = engine_espace_to_iso(i, j, i, j + 1, p_matrix, p_window);
			engine_plot_line(&pair, p_window);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < p_matrix->col)
	{
		i = 0;
		while (i < p_matrix->row && i + 1 < p_matrix->row)
		{
			pair = engine_espace_to_iso(i, j, i + 1, j, p_matrix, p_window);
			engine_plot_line(&pair, p_window);
			i++;
		}
		j++;
	}
}

t_pair engine_espace_to_iso(int p1_x, int p1_y, int p2_x, int p2_y, t_matrix *p_matrix, t_window *p_wndow)
{
	t_pair	pair;
	pair.p1.x = (p1_x - p1_y) * cos(0.5);
	pair.p1.y = (p1_x + p1_y) * sin(0.5) - p_matrix->matrix[p1_x][p1_y];
	pair.p2.x = (p2_x - p2_y) * cos(0.5);
	pair.p2.y = (p2_x + p2_y) * sin(0.5) - p_matrix->matrix[p2_x][p2_y];
	return pair;
}
