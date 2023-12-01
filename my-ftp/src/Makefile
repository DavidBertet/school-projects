include ../makefile.rules

all : ../$(NAME_TARGET_DAEMON) ../$(NAME_TARGET_DAEMON)

../$(NAME_TARGET_DAEMON) : $(MAINO_DAEMON) libstream/libstream.a inc_myftp_myftpd.h tools_str_myftp_myftpd.h daemon/const_myftpd.h  daemon/func_myftpd.h   daemon/struct_myftpd.h
	$(CC) -o $@ $(MAINO_DAEMON) -lpthread -L libstream -l stream

../$(NAME_TARGET_CLIENT) : $(MAINO_CLIENT) libstream/libstream.a inc_myftp_myftpd.h tools_str_myftp_myftpd.h client/const_myftp.h client/func_myftp.h client/struct_myftp.h
	$(CC) -o $@ $(MAINO_CLIENT) -lpthread -lreadline -L libstream -l stream

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libstream/libstream.a :
	cd libstream; $(MAKE) libstream.a

hi :
	echo "Hi !"
