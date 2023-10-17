# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:39:14 by lnyamets          #+#    #+#              #
#    Updated: 2023/10/17 03:20:53 by lnyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -std=c99

fdf : client.o report.o manager.o util.o data.o engine.o engine_draw_line.o engine_callback.o model.o
	cc -o fdf client.o  manager.o report.o util.o data.o engine.o engine_draw_line.o engine_callback.o model.o -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz
client.o : client/client.c client/client.h report/report.h
	cc $(CFLAGS) -c client/client.c

report.o : report/report.c report/report.h
	cc $(CFLAGS) -c report/report.c

manager.o : manager/manager.c manager/manager.h
	cc $(CFLAGS) -c manager/manager.c

util.o : model/util.c model/model.h
	cc $(CFLAGS) -c model/util.c

model.o : model/model.c model/model.h
	cc $(CFLAGS) -c model/model.c

data.o : data/data.c data/data.h model/model.h
	cc $(CFLAGS) -c data/data.c

engine.o : engine/engine.c engine/engine_draw_line.c engine/engine.h
	cc $(CFLAGS) -c engine/engine.c engine/engine_draw_line.c

engine_draw_line.o : engine/engine_draw_line.c engine/engine.h
	cc $(CFLAGS) -c engine/engine_draw_line.c

engine_callback.o : engine/engine_callback.c engine/engine.h
	cc $(CFLAGS) -c engine/engine_callback.c

clean :
	rm fdf client.o report.o manager.o util.o data.o engine.o engine_draw_line.o model.o engine_callback.o
