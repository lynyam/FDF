#include "engine.h"

int	engine()
{
	printf("welcome to engine");
	return (0);
}

void	*engine_init_connection()
{
	return mlx_init();
}

void	*engine_create_window(t_window_config *p_window_config)

{
	void	*p_window_id = mlx_new_window(p_window_config->p_connection_id, p_window_config->p_window_size->x, 
				p_window_config->p_window_size->y, p_window_config->title);
	return p_window_id;
}

int	engine_expose_win(t_param *p)
{
	printf("expose x = %d, y = %d\n", p->x, p->y);
	//mlx_new_window(p->mlx, p->x, p->y, p->ti);
	mlx_new_window(p->mlx, 721, 721, p->ti);
	(p->x) -= 50;
	(p->y) -= 50;
	printf("%c, %p, \n", *(p->ti), p->ti);
	*(p->ti) = *(p->ti) + 1;
	return 0;
}

int     engine_key_event(int key, t_window_config *p_window_config)
{
	printf("The key number %#X is press\n", key);
	if (key == 7)
	{
		printf("key %d\n", key);
		exit(0);
	}
	return 0;
}

int     engine_mouse_event(int button, int x, int y, t_param *param)
{
	
	printf("The button number %d : %#X is press on x = %d; y = %d\n", button, button, x, y);
	if (button == 1 || button == 5)
	{
		int color = ((param->p_color->red) << 16) | ((param->p_color->green) << 8) | (param->p_color->blue);
		mlx_pixel_put(param->mlx, param->win, x, y, color);
		if (param->p_color->red < 255)
		{
			(param->p_color->red) += 1;
		}
		if (param->p_color->green < 255)
		{
			(param->p_color->green) += 2;
		}
		if (param->p_color->blue < 255)
		{
			(param->p_color->blue) += 3;
		}

	}
	return 0;
}
/*
int	engine_display_pixel(t_pixel *pixel)
{
	return mlx_pixel_put(pixel->connection_id, pixel->window_id, pixel->x, pixel->y, pixel->color);
}

int	engine_check_endian()
{
	int	num;
	char* ptr;

	num = 1;
	ptr = (char *)&num;
	if (*ptr == 1)
	{
		printf("Architecture Little-Endian\n");
		return (1);
	}
	else 
	{
		printf("Architecture Big-Endian\n");
	}
	return (0);
}*/
