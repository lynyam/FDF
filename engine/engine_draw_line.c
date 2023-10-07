#include "engine.h"

int	color_to_int(struct s_color *p_color)
{
	return ((p_color->red) << 16) | ((p_color->green) << 8) | (p_color->blue);
}

void	draw_horizontal_line(t_window *p_window, int x0, int x1, int y, int c, int incX)
{
	while (x0 != x1 + incX)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id, x0, y, c);
		x0 += incX;
	}
}

void	draw_slope(t_window *p_window, int x0, int y0, int x1, int y1, int dx, int dy, int incX, int incY) {
	int slope;
	int error;
	int errorInc;
	int y;

	slope = 2 * dy;
	error = -dx;
	errorInc = -2 * dx;
	y = y0;
	while (x0 != x1 + incX)
	{
		mlx_pixel_put(p_window->p_connection_id, p_window->p_window_id, x0, y, c);
		error += slope;
		if (error >= 0)
		{
			y += incY;
			error += errorInc;
		}
		x0 += incX;
	}
}

void	draw_line_horizontal(t_window *p_window, t_pair *p_pair, int incX)
{
	int c;

	c = color_to_int(p_window->p_color);
	draw_horizontal_line(p_window, p_pair->p1.x,p_pair->p2.x, p_pair->p1.y, c, incX);
}

void	draw_line_slope(t_window *p_window, t_pair *p_pair, int dx, int dy, int incX, int incY)
{
	int c;

	c = color_to_int(p_window->p_color);
	draw_slope(p_window, p_pair->p1.x, p_pair->p1.y, p_pair->p2.x, p_pair->p2.y, dx, dy, incX, incY);
}

void engine_plot_line(t_pair *p_pair, t_window *p_window)
{
	int dx;
	int dy;
	int incX;
	int incY;

	dx = p_pair->p2.x - p_pair->p1.x;
	dy = p_pair->p2.y - p_pair->p1.y;
	incX = SGN(dx);
	incY = SGN(dy);
	if (dy == 0)
		draw_line_horizontal(p_window, p_pair, incX);
	else if (dx == 0)
		draw_line_horizontal(p_window, p_pair, incY);
	else if (dx >= dy)
		draw_line_slope(p_window, p_pair, dx, dy, incX, incY);
	else
		draw_line_slope(p_window, p_pair, dy, dx, incY, incX);
}
