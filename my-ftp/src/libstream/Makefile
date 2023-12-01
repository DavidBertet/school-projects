CC=gcc
SRC= src/lbs_utils.c src/lbs_fclose.c src/lbs_fopen.c src/lbs_fputc.c src/lbs_fgetc.c src/lbs_fflush.c src/lbs_fseek.c src/lbs_fseeko.c src/lbs_freopen.c src/lbs_fdopen.c src/lbs_fpurge.c src/lbs_ftell.c src/lbs_ftello.c src/lbs_rewind.c src/lbs_fsetpos.c	src/lbs_fgetpos.c src/lbs_fread.c src/lbs_fwrite.c src/lbs_fgets.c src/lbs_fputs.c src/lbs_getline.c src/lbs_getdelim.c

OBJ=$(SRC:.c=.o)

CFLAGS=-Wall -W -Werror -pedantic -ansi

all: libstream.a

libstream.a: $(OBJ)
	ar cr $@ $^

libstream.so: ${OBJ}
	$(CC) ${CFLAGS} -shared -o $@ ${OBJ}

%.o : %.c
	$(CC) $(CFLAGS) -g -ggdb -c $< -o $@
