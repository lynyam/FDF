#include "engine.h"
#include "../mlx/mlx_int.h"

void	engine_connect_x_server(t_window *p_window)
{
	p_window->p_connection_id =  mlx_init();
	report_connection_x_server(p_window->p_connection_id);
}

void	engine_create_window(t_window *p_window)
{
	int screen_width;
	int	screen_height;

	//p_window->width =  mlx_screen_size(p_window->p_connection_id, 0);
	//p_window->height = mlx_screen_size(p_window->p_connection_id, 1);
	//printf("with = %d \nheight = %d\n", p_window->width, p_window->height);
	p_window->p_window_id = mlx_new_window(p_window->p_connection_id,
		0, 0, p_window->title);
		// Get the screen size
    mlx_get_screen_size(p_window->p_connection_id, &p_window->width, &p_window->height);

    mlx_destroy_window(p_window->p_connection_id, p_window->p_window_id);
	printf("with = %d \nheight = %d\n", p_window->width, p_window->height);
	//report_create_window(p_window);
}

/*void	engine_draw(t_matrix *p_matrix, t_window *p_window)
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
			pair = engine_espace_to_iso(i, j, i, j + 1, p_matrix);
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
			pair = engine_espace_to_iso(i, j, i + 1, j, p_matrix);
			engine_plot_line(&pair, p_window);
			i++;
		}
		j++;
	}
}

t_pair engine_espace_to_iso(int p1_x, int p1_y, int p2_x, int p2_y, t_matrix *p_matrix)
{
	t_pair	pair;
	pair.p1.x = (720 / 2) + 10 * (-p1_x + p1_y);
	pair.p1.y = (720 / 2) + ((p1_x + p1_y) * 10 / 2 - p_matrix->matrix[p1_x][p1_y]);
	pair.p2.x = (720 / 2) + 10 * (-p2_x + p2_y);
	pair.p2.y = (720 / 2) + ((p2_x + p2_y) * 10 / 2 - p_matrix->matrix[p2_x][p2_y]);
	return pair;
}
 */
