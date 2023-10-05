#ifndef MODEL_H
# define MODEL_H
# define NOT_OPEN_FILE -1
# define ERROR_CODE 1
# define SUCCES_CODE 0

typedef struct s_size {
	int	x;
	int	y;
}		t_size;

typedef	struct	s_matrix {
	int	**matrix;
	int	col;
	int	row;
}		t_matrix;
#endif
