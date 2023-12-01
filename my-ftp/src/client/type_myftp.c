#include "const_myftp.h"

static char	*my_uppercase(char   *str)
{
  int		i;
  char		*ret;

  ret = malloc(my_strlen(str) + 1);

  for (i = 0; str[i]; ++i)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	ret[i] = str[i] + 'A' - 'a';
      else
	ret[i] = str[i];
    }
  ret[i] = '\0';
  return (ret);
}

void	func_type(char		*arg,
		  struct s_user	*user)
{
  if (!my_strcmp(my_uppercase(arg), "TYPE ASCII"))
    arg = "TYPE a";
  else if (!my_strcmp(my_uppercase(arg), "TYPE IMAGE") ||
	   !my_strcmp(my_uppercase(arg), "TYPE BINARY"))
    arg = "TYPE i";

  print_cmd(arg);

  send_cmd(user->cmd_sock, arg);

  user->last_state = get_state(read_socket(user->cmd_sock));

  if (user->last_state == 200)
    {
      free(user->type);
      user->type = malloc(my_strlen(arg));
      my_strcpy(user->type, arg);
    }

  return;
}
