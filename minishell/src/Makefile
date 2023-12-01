CC=gcc
SRC=lib_string.c utils.c utils_str.c builtin.c utils_builtin.c utils_redir.c utils_app.c parse_cmd.c
PROG=minishell.c

CFLAGS+= -W -Wall -Werror -pedantic -ansi
LDFLAGS+= libstream.a

EXE=../minishell

OBJ=${SRC:%.c=%.o}

all: deps.mk ${EXE}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${EXE}: ${OBJ} ${PROG}
	gcc ${CFLAGS} ${OBJ} -o ${EXE} ${PROG} ${LDFLAGS}

deps.mk:
	gcc -MM ${SRC} > ../$@

-include ../deps.mk

clean:
	rm -f ${OBJ}
	rm -f ${LIBNAME}${LIBSTAT}
	rm -f ${LIBNAME}${LIBDYN}
	rm -f ../deps.mk