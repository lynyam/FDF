# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 05:00:29 by lnyamets          #+#    #+#              #
#    Updated: 2023/10/19 02:20:22 by lnyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_strlencpy.c \
		ft_strlen.c \
		ft_memset.c \
		ft_strncpy.c \
		ft_strchr.c \
		ft_strtok.c \
		ft_strtol.c \

OBJECT = ft_atoi.o \
		ft_strlencpy.o \
		ft_strlen.o \
		ft_memset.o \
		ft_strncpy.o \
		ft_strchr.o \
		ft_strtok.o \
		ft_strtol.o \

FLAG = -Wall -Wextra -Wall -g

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
