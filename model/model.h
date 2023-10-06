/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:03:57 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/06 02:13:00 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			**matrix;
	int			col;
	int			row;
}				t_matrix;

typedef	struct	s_file {
	char 		*file_str;
	char		buf[BUFSIZ];
	int			first_line;
	int			row;
	int			col;
}				t_file;
#endif
