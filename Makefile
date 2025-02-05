# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 07:01:02 by ynyamets          #+#    #+#              #
#    Updated: 2025/02/05 07:01:06 by ynyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	client/client.c \
		manager/manager.c \
		engine/engine.c \
		engine/engine_draw_line.c \
		engine/engine_callback.c \
		engine/engine_utils.c \
		data/data.c\
		data/data_util.c \
		model/model.c \
		model/util.c \
		model/init_data_struct.c \
		model/free_allocation.c \
		report/report.c \

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(CFLAGS) $(OBJ) -L./minilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz libft/libft.a
	echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
