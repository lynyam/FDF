/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:03:57 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/18 21:32:28 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include "../report/report.h"
# include <stdlib.h>
# include <math.h>
# define NOT_OPEN_FILE -1
# define ERROR_CODE 1
# define SUCCES_CODE 0
# define RETURN_CODE_ZERO 0
# define RETURN_CODE_ONE 1
# define BUFSIZE 1080

typedef struct s_file {
	char		*file_str;
	char		buf[BUFSIZ];
	int			first_line;
	int			row;
	int			col;
	int			fd;
}				t_file;

typedef struct s_size {
	int	x;
	int	y;
}		t_size;

typedef struct s_color {
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}					t_color;

typedef struct s_point {
	int			x;
	int			y;
}				t_point;

typedef struct s_pair {
	t_point		p1;
	t_point		p2;
}				t_pair;

typedef struct s_point_color {
	int	z;
	int	color;
}		t_point_color;

typedef struct s_matrix {
	t_point_color	**matrix;
	int				col;
	int				row;
	int				size;
}					t_matrix;

typedef struct s_init_m
{
	char		*start;
	char		*end;
	int			col;
	int			row;
}				t_init_m;

int		count_row(char *buf, int row);
int		count_col(char *buf, int *col);
char	*ft_concat(t_file *p_file, int prev_buf_count, int buf_count);
void	allocate_matrix(t_matrix *p_matrix);
int		is_valid_char(char c);
int		sgn(int x);
int		color_to_int(struct s_color *p_color);
void	util_init_t_init(t_init_m *init);
void	util_increment(t_init_m *init, char **str);
void	free_charptr(char *rtn);
char	*rtn_null_free_charptr(char *rtn);
int		get_matrice_size(t_matrix	*p_matrix);

#endif
