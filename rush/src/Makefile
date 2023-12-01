include ../makefile.rules

all : ../bin/$(NAME_TARGET)

../bin/$(NAME_TARGET) : $(MAINO) inc.h const.h struct.h func.h
	$(CC) -o $@ $(MAINO) `sdl-config --libs` -I/usr/pkg/include/ -L/usr/pkg/lib/ -lGL -lglut -lSDL_image

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

hi :
	echo "Hi !"
