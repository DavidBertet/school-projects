CC=gcc
SRC= utils.c free.c malloc.c realloc.c calloc.c

LIBNAME=libmalloc
LIBSTAT=.a
LIBDYN=.so
LIBLIST=${LIBNAME}${LIBSTAT} ${LIBNAME}${LIBDYN} 

OBJ=${SRC:%.c=%.o}

all: deps.mk ${OBJ} ${LIBLIST}

%.o: %.c
	${CC} -c $< -o $@

${LIBNAME}.a: ${OBJ}
	ar rcs $@ ${OBJ}

${LIBNAME}.so: ${OBJ}
	gcc -shared -o $@ ${OBJ}

deps.mk:
	gcc -MM ${SRC} > ../$@

-include ../deps.mk

clean:
	rm -f ${OBJ}
	rm -f ${LIBNAME}${LIBSTAT}
	rm -f ${LIBNAME}${LIBDYN}
	rm -f ../deps.mk