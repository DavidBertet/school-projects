CC=gcc
SRC= main.c

OBJ=${SRC:%.c= %.o}

all: main

%.o: %.c
	${CC} -c $< -o $@

main:
	gcc -o main main.c ../src/libmalloc.a

clean:
	rm -f main

.PHONY: main