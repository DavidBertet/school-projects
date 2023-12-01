#include "tools_opt_myftp_myftpd.h"
#include "tools_str_myftp_myftpd.h"

int	is_option(char		**command,
		  const s_opt	*g_opt,
		  s_server	*server)
{
  int	i;
  int	j = 0;
  int	k = 0;
  int	result = 0;

  while (command[j] != NULL)
  {
    i = 0;
    while (g_opt[i].opt_name != NULL)
    {
      result = my_strcmp(g_opt[i].opt_name, command[j]);
      if (result == 0)
      {
	for (k = 1; k <= g_opt[i].nb_arg; k++)
	  if (command[j + k] == NULL)
	    return (-1);
	(*(g_opt[i].my_func))(command[j + 1], server);
	if (i == 0)
	  return (2);
      }
      i++;
    }
    j++;
  }
  return (-1);
}
