#linclude ../makefile.rules

all : ../bin/$(NAME_TARGET)

../$(NAME_TARGET) : $(MAINO) const.h struct.h
	$(CC) -o $@ $(MAINO) `sdl-config --libs` -I/usr/pkg/include/ -L/usr/pkg/lib/ -lGL -lglut -lSDL_image

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

hi :
	echo "Hi !"
