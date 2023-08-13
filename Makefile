fdf : client.o manager.o engine.o data.o report.o
	cc -o fdf client.o manager.o engine.o data.o report.o -lmlx -Lmlx -framework OpenGL -framework AppKit

client.o : client/client.c client/client.h report/report.h
	cc -c client/client.c
manager.o : manager/manager.c manager/manager.h
	cc -c manager/manager.c
engine.o : engine/engine.c engine/engine.h
	cc -c engine/engine.c
data.o : data/data.c data/data.h
	cc -c data/data.c
report.o : report/report.c report/report.h
	cc -c report/report.c
clean :
	rm fdf client.o manager.o engine.o data.o report.o

