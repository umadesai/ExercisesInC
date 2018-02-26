# trout: trout.h trout.c util.c
# 	gcc -g -o trout trout.c util.c


util: util.c util.h
	gcc -g -c $^

trout: trout.c trout.h util.h
	gcc -g -c $^

main.o: main.c trout.h util.h
	gcc -g -c $^

main: main.o trout.o util.o
	gcc -g -Wall $^
