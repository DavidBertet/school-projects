#include "const_myftp.h"

int	is_valid_cmd(char	*str)
{
  int	i;

  my_uppercase_cmd(str);
  for (i = 0; *(ftp_cmd[i].cmd); ++i)
    {
      if (ftp_cmd[i].nb_args == 0)
	{
	  if (!strcmp(str, ftp_cmd[i].cmd))
	    return (i);
	}
      else
	{
	  if (!strncmp(str, ftp_cmd[i].cmd, my_strlen(ftp_cmd[i].cmd)))
	    return (i);
	}
    }

  return (-1);
}

void	send_cmd(int	sock,
		 char	*cmd)
{
  int	nb_read;
  char	*cmd_tmp;

  nb_read = my_strlen(cmd);
  cmd_tmp = malloc(nb_read + 2);
  my_strcpy(cmd_tmp, cmd);
  cmd_tmp[nb_read] = '\r';
  cmd_tmp[nb_read + 1] = '\n';
  cmd_tmp[nb_read + 2] = '\0';

  send(sock, cmd_tmp, my_strlen(cmd_tmp), 0);

  free(cmd_tmp);
  return;
}
