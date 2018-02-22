trout: trout.h trout.c util.c
	gcc -g -o trout trout.c util.c

util.o: util.c util.h
	gcc -c util.c

trout.o: trout.c trout.h
	gcc -c trout.c

trout: trout.o util.o
	gcc trout.o util.o -o trout
