/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 06:27:08 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/07 17:13:25 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include "../report/report.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stddef.h>
# define NOT_OPEN_FILE -1
# define ERROR_CODE 1
# define SUCCES_CODE 0
# define RETURN_CODE_ZERO 0
# define RETURN_CODE_ONE 1
# define BUFSIZE 1080

typedef struct s_file {
	char		*file_str;
	char		buf[BUFSIZE];
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
	int		red;
	int		green;
	int		blue;
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
	int		z;
	t_color	color;
}			t_point_color;

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
void	free_charptr(char *rtn);
void	*rtn_null_free_charptr(char *rtn);
int		get_matrice_size(t_matrix	*p_matrix);
void	init_s_point_color(t_point_color *p_point_color, int value, int all);
void	init_t_init(t_init_m *init);
int		is_valid_char(char c);
int		sgn(int x);
void	util_increment(t_init_m *init, char **str);
char	*util_skip_whitespace(char *str);
char	*util_skip_to_next_token(char *str);

#endif
