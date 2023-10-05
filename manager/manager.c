#include "manager.h"
int close_window(void *param)
{
    // Effectuez ici toutes les actions de nettoyage nécessaires
    // (par exemple, libérez les ressources, fermez les fichiers, etc.)
    
    // Puis quittez l'application
    exit(0);
}
int	manager_start_processing(char argv[])
{
	void *p_connection_id;
	void	*p_window_id;
	t_size	window_size;
	t_size	*p_window_size;
	t_window_config	window_config;
	t_window_config	*p_window_config;
	char *window_title;

	window_title = "fdf_1";
	p_window_size = &window_size;
	p_window_size->x = 720;
	p_window_size->y = 720;
	printf("%s\n", argv);
	int fd = data_open_file(argv);
//	data_read_file(fd);


	p_connection_id = engine_init_connection();
	report_connection_x_server(p_connection_id);
	p_window_config = init_window_config(p_connection_id, p_window_size, window_title);
	p_window_id = engine_create_window(p_window_config);
	report_create_window(p_window_id);

	void	*img;
	char	c = 48;
	char 	*p_c = &c;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_point point1 = {10, 10}, *p1 = &point1;
	t_point point2= {100, 100}, *p2 = &point2;

	red = 0;
	green = 0;
	blue = 0;

	t_color	color = {100, 27, 200}, *p_color = &color;
	t_point pp0 = {0, 0};
	t_param	parm = {p_connection_id, p_window_id, img, p_window_size->x, p_window_size->y, p_c, p_color, &pp0, 0};
	t_param	*param = &parm;



	mlx_key_hook(p_window_id, engine_key_event, param);
	mlx_mouse_hook(p_window_id, engine_mouse_event, param);
	
	//engine_check_endian();
	//engine_display_pixel(p_pixel);
	t_matrix *p_matrix;
	p_matrix = data_read_file(fd);
	//print_matrix(fran, 10, 10);
	engine_draw(p_matrix, param);
	mlx_hook(p_window_id, 17, 0, close_window, p_connection_id);
	mlx_loop(p_connection_id);
	return (0);

}                                                                                 

t_window_config	*init_window_config(void *p_connection_id, t_size *p_window_size, char *window_title)
{
	t_window_config	*p_window_config;
	t_window_config	window_config;

	p_window_config = &window_config;
	p_window_config->p_connection_id = p_connection_id;
	p_window_config->title = window_title;
	p_window_config->p_window_size = p_window_size;
	return (p_window_config);
}
