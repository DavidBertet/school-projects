#ifndef INC_MYFTP_MYFTPD_H_
# define INC_MYFTP_MYFTPD_H_

/*
** Header : inc_myftp_myftpd.h
** Here are the extern includes made for the FTP server and client.
*/

/*
** unistd.h : read(2), write(2), close(2), unlink(2), rmdir(2), setsid(2),
** getcwd(3), gethostname(3), fork(2), isatty(3).
*/
# include <unistd.h>

/*
** fcntl.h : open(2).
*/
# include <fcntl.h>

/*
** stdlib.h : exit(3), malloc(3), free(3), realloc(3).
*/
# include <stdlib.h>

/*
** sys/socket.h : socket(2), accept(2), bind(2), connect(2), listen(2),
** recv(2), send(2).
*/
# include <sys/socket.h>

/*
** arpa/inet.h : inet_addr(3), byteorder(3), htonl(3), htons(3), ntohl(3),
** ntohs(3).
*/
# include <arpa/inet.h>

/*
** netdb.h : gethostbyname(3).
*/
# include <netdb.h>

/*
** assert.h : assert(3).
*/
# include <assert.h>

/*
** stdio.h, readline/readline.h, readline/history.h : perror(3), readline(3).
*/
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** errno.h : errno(2).
*/
# include <errno.h>

/*
** string.h : memset(3).
*/
# include <string.h>

/*
** sys/stat.h : mkdir(2).
*/
# include <sys/stat.h>

/*
** dirent.h : opendir(3), closedir(3), readdir(3).
*/
# include <dirent.h>

/*
** pthread.h : all the functions.
*/
# include <pthread.h>

/*
** dlfcn.h : dlopen(3), dlerror(3), dlsym(3), dlclose(3).
*/
# include <dlfcn.h>

/*
** netinet/in.h : struct sockaddr_in.
*/
# include <netinet/in.h>

/*
** time.h : time(3), ctime_r(3), gmtime(3), localtime_r(3), asctime_r(3),
** strftime(3).
*/
# include <time.h>

/*
** libstream/include/libstream.h : libstream functions.
*/
# include "libstream/include/libstream.h"

/*
** End of the header inc_myftp_myftpd.h
*/

#endif /* !INC_MYFTP_MYFTPD_H_ */
