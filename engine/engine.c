#include "engine.h"


int	engine_close_window(void *param)
{
    // Effectuez ici toutes les actions de nettoyage nécessaires
    // (par exemple, libérez les ressources, fermez les fichiers, etc.)

    // Puis quittez l'application
    exit(0);
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
//	printf("expose x = %d, y = %d\n", p->x, p->y);
	//mlx_new_window(p->mlx, p->x, p->y, p->ti);
	mlx_new_window(p->mlx, 721, 721, p->ti);
	(p->x) -= 50;
	(p->y) -= 50;
//	printf("%c, %p, \n", *(p->ti), p->ti);
	*(p->ti) = *(p->ti) + 1;
	return 0;
}

int     engine_key_event(int key, t_window_config *p_window_config)
{
	printf("The key number %#X is press\n", key);
	if (key == 0x35 || key == 0XFF1B)
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
		if (param->compteur == 0)
		{
			param->p0->x = x;
			param->p0->y = y;
			param->compteur = 1;
		}
		else
		{
			t_point p;
			p.x = x;
			p.y = y;
			//engine_plot_line_opti(param->p0, &p, param);
			engine_plot_line(param->p0, &p, param);
			param->p0->x = p.x;
			param->p0->y = p.y;
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

void engine_plot_line(t_point *p1, t_point *p2, t_param *param)
{
	int	dx;
	int	dy;

	int	c = ((param->p_color->red) << 16) | ((param->p_color->green) << 8) | (param->p_color->blue);
	int x0 = p1->x;
	int y0 = p1->y;
	int x1 = p2->x;
	int y1 = p2->y;
	dx = x1 - x0;
	dy = y1 - y0;
	int incX = SGN(dx);
	int incY = SGN(dy);
	dx = ABS(dx);
	dy = ABS(dy);

	if (dy == 0)
	{
		for (int x = x0; x != x1 + incX; x += incX)
			mlx_pixel_put(param->mlx, param->win, x, y0, c);
	}
	else if (dx == 0)
	{
		for (int y = y0; y != y1 + incY; y += incY)
			mlx_pixel_put(param->mlx, param->win, x0, y, c);
	}
	else if (dx >= dy)
	{
		int slope = 2 * dy;
		int error = -dx;
		int errorInc = -2 * dx;
		int y = y0;

		for (int x = x0; x != x1 + incX; x += incX)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, c);
			error += slope;

			if (error >= 0)
			{
				y += incY;
				error += errorInc;
			}
		}
	}
	else
	{
		int slope = 2 * dx;
		int error = -dy;
		int errorInc = -2 * dy;
		int x = x0;

		for (int y = y0; y != y1 + incY; y += incY)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, c);
			error += slope;

			if (error >= 0)
			{
				x += incX;
				error += errorInc;
			}
		}
	}
}

t_point engine_espace_to_iso(t_espace espace)
{
	t_point	point;
//	point.x = ((720 / 2) + 50 * ((sqrt(2) / 2) * (espace.x - espace.y)));
	point.x = (720 / 2) + 10 * (-espace.x + espace.y);
	//point.x = (-espace.x + espace.y) * 20 + 720 / 2;
	//point.y = (((espace.x + espace.y) / 2) - espace.z) *20 + 720 / 2;
	point.y = (720 / 2) + ((espace.x + espace.y) * 10 / 2 - espace.z);
	//point.y = ((720 / 2) + 50 * (-(sqrt(2 / 3) * espace.z) + ((espace.x + espace.y) * (1 / sqrt(6)))));
	return point;
}

t_point engine_space_to_con(t_espace espace, int d)
{
	t_point	point;
	//point.x = (1920 / 2) + (sqrt(2) * 0.5 * (espace.x - espace.y));
	point.x = (int) (d * espace.x / espace.z);
	point.y = (int) (d * espace.y / espace.z);
//	point.y = (1080 / 2) + ((sqrt(2 / 3) * espace.z) - ((espace.x + espace.y) / sqrt(6)));
	return point;
}


void	engine_draw(t_matrix *p_matrix, t_param *param)
{
	int	row;
	int	col;
	int	i;
	int	j;
	t_point	pi;
	t_point	pii;
	t_espace	ei;
	t_espace	eii;
	int	**matrix;

	matrix = p_matrix->matrix;
	row = p_matrix->row; //strlen(matrix);
	col = p_matrix->col; //strlen(matrix[0];
	i = 0;
	printf("In Engine row = %d, col = %d, matrix = %p\n", row, col, matrix);
	while (i < row)
	{
//		printf("i = %d\n\n", i);
		j = 0;
		while (j < col && j + 1 < col)
		{
			ei.x = i;
			ei.y = j;
			ei.z = matrix[i][j];
			pi = engine_espace_to_iso(ei);
//			printf("vert x = %d y= %d \n", pi.x, pi.y);
			eii.x = i;
			eii.y = j + 1;
			eii.z = matrix[i][j + 1];
			pii = engine_espace_to_iso(eii);
//			printf("vert xi = %d yi= %d \n", pii.x, pii.y);
			engine_plot_line(&pi, &pii, param);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < col)
	{
		i = 0;
		while (i < row && i + 1 < row)
		{
			ei.x = i;
			ei.y = j;
			ei.z = matrix[i][j];
			pi = engine_espace_to_iso(ei);
			eii.x = i + 1;
			eii.y = j;
			eii.z = matrix[i + 1][j];
			pii = engine_espace_to_iso(eii);
			//printf("hor x = %d y= %d \n", pi.x, pi.y);
		//	printf("hor xi = %d yi= %d \n", pii.x, pii.y);
			engine_plot_line(&pi, &pii, param);
			i++;
		}
		j++;
	}

}

void	draw_isometric(t_espace *object, t_param *param, int nbr_node)
{
	//soit p ligne et q col
	// joindre les p ligne pi, pi+1. ex ; trace l0 => for (i < q; i++){p1=spc_iso(0, i, m[0,i]) p2 = spac_iso(0, i+1, m[0,i+1]); trac(p1,p2)} pour toute les ligne for j from 0 to p { for i from 0 to q {}}; juste inverse le for pour tracer les coll
	// joindre les q col qi, qi+1;
	// appliquer la projection sur i j z et obtenir x y a  donner
	int	i;

	i = 0;
	while (i < nbr_node)
	{

		t_point pt_i = engine_espace_to_iso(object[i]);
		//t_point pt_i = engine_espace_to_con(object[i], 2);
		mlx_pixel_put(param->mlx, param->win, pt_i.x, pt_i.y, 900);
		int j = i + 1;
		while (j < nbr_node)
		{
			t_point pt_j = engine_espace_to_iso(object[j]);
			//t_point pt_j = engine_espace_to_con(object[j], 2);
			printf("x0 = %d, y0 = %d, x1 = %d, y1 = %d\n", pt_i.x, pt_i.y, pt_j.x, pt_j.y);
			engine_plot_line(&pt_i, &pt_j, param);
			j++;
		}
		i++;
	}
}

