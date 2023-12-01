#include "my_listdir.h"
#include "const_myftpd.h"

int		my_listdir(char	*dirname,
			   int	sock)
{
  DIR		*directory;
  s_dirent	*sdir;

  directory = opendir(dirname);
  while ((sdir = readdir(directory)) != NULL)
    {
      send(sock, sdir->d_name, sdir->d_namlen, 0);
      send(sock, "\n", 1, 0);
    }
  closedir(directory);
  return (0);
}

