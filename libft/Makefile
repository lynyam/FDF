# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 05:00:29 by lnyamets          #+#    #+#              #
#    Updated: 2023/10/17 05:49:45 by lnyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_strlencpy.c \
		ft_strlen.c

OBJECT = ft_atoi.o \
		ft_strlencpy.o \
		ft_strlen.o

FLAG = -Wall -Wextra -Wall

HEADER = includes

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) -I$(HEADER) && ar rc $(NAME) $(OBJECT)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(OBJECT)

re: fclean all
