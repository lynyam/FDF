CFLAGS = -g -std=c99

fdf : client.o manager.o engine.o data.o report.o
	cc -o fdf client.o manager.o engine.o data.o report.o -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz
client.o : client/client.c client/client.h report/report.h
	cc $(CFLAGS) -c client/client.c
manager.o : manager/manager.c manager/manager.h
	cc $(CFLAGS) -c manager/manager.c
engine.o : engine/engine.c engine/engine.h
	cc $(CFLAGS) -c engine/engine.c
data.o : data/data.c data/data.h
	cc $(CFLAGS) -c data/data.c
report.o : report/report.c report/report.h
	cc $(CFLAGS) -c report/report.c
clean :
	rm fdf client.o manager.o engine.o data.o report.o

