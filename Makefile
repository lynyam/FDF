# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:39:14 by lnyamets          #+#    #+#              #
#    Updated: 2023/10/17 12:40:08 by lnyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	client/client.c \
		manager/manager.c \
		engine/engine.c \
		engine/engine_draw_line.c \
		engine/engine_callback.c \
		data/data.c\
		model/model.c \
		model/util.c \
		model/free_allocation.c \
		report/report.c \

CFLAGS = -Wall

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz libft/libft.a
	echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
