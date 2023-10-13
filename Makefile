CFLAGS = -g -std=c99

fdf : client.o report.o manager.o util.o data.o engine.o engine_draw_line.o
	cc -o fdf client.o  manager.o report.o util.o data.o engine.o engine_draw_line.o -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz
client.o : client/client.c client/client.h report/report.h
	cc $(CFLAGS) -c client/client.c

report.o : report/report.c report/report.h
	cc $(CFLAGS) -c report/report.c

manager.o : manager/manager.c manager/manager.h
	cc $(CFLAGS) -c manager/manager.c

util.o : model/util.c model/model.h
	cc $(CFLAGS) -c model/util.c

data.o : data/data.c data/data.h model/model.h
	cc $(CFLAGS) -c data/data.c

engine.o : engine/engine.c engine/engine_draw_line.c engine/engine.h
	cc $(CFLAGS) -c engine/engine.c engine/engine_draw_line.c

engine_draw_line.o : engine/engine_draw_line.c engine/engine.h
	cc $(CFLAGS) -c engine/engine_draw_line.c

clean :
	rm fdf client.o report.o
