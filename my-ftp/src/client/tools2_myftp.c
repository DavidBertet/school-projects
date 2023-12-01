#include "const_myftp.h"

int             read_line(char          **buf,
                          s_stream      *stream)
{
  size_t        size = 0;
  int           ret;

  ret = lbs_getdelim(buf, &size, '\n', stream);

  return (ret);
}

char            *read_socket(int        sock)
{
  char          *response = NULL;
  s_stream      *stream = NULL;
  int           ret;

  stream = lbs_fdopen(sock, "r");

  do
    {
      ret = read_line(&response, stream);
      if (ret > 0)
	{
	  print_string("<--- ", STDOUT_FILENO, 0);
	  print_string(response, STDOUT_FILENO, 0);
	}
    }
  while (!is_end_cmd(response));

  return (response);
}

void    print_cmd(char  *cmd)
{
  print_string("---> ", STDOUT_FILENO, 0);
  print_string(cmd, STDOUT_FILENO, 0);
  print_string("\n", STDOUT_FILENO, 0);

  return;
}

int     get_state(char  *response)
{
  int   ret;

  if (my_strlen(response) < 3)
    return (-1);

  ret = response[0] - '0';
  ret = ret * 10 + response[1] - '0';
  ret = ret * 10 + response[2] - '0';

  return (ret);
}

void             manage_arg(int                  argc,
			    char                 **argv,
			    struct s_user        *user)
{
  if (argc != 2 && argc != 3 && argc != 4)
    {
      print_string("Warning: Usage: ./myftp hostname [port]\n",
                   STDOUT_FILENO, 0);
      exit(1);
    }

  if (!my_strcmp(argv[1], "-p") && (user->pasv = 1))
    user->host = argv[2];
  else
    {
      user->host = argv[1];
      if (argc >= 3 && !my_strcmp(argv[2], "-p"))
        user->pasv = 1;
      else if (argc == 4 && !my_strcmp(argv[3], "-p") && (user->pasv = 1))
        user->port = my_atoi(argv[2]);
    }
  if (argc == 4 && user->port == INIT_PORT)
    user->port = my_atoi(argv[3]);
  else if (argc == 3 && user->pasv == 0)
    user->port = my_atoi(argv[2]);
}
