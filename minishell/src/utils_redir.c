/*
** utils_redir.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:24:25 2008 david bertet
** Last update Sun Oct 19 04:24:32 2008 david bertet
*/

#include <stdlib.h>
#include "utils_redir.h"
#include "utils_app.h"
#include "utils_str.h"

struct	pos_type
{
  int	pos_min;
  int	type;
};

static void	find_redir(char			**argv,
			   char			*str,
			   int			type_cmd,
			   struct pos_type	*res)
{
  int		pos;

  if ((pos = find_tab(argv, str, 0)) && res->pos_min > pos)
    {
      res->type = type_cmd;
      res->pos_min = pos;
    }
}

void			treat_redir(char	**argv,
				    int		*pos_finish,
				    int		*type_finish)
{
  struct pos_type	res;

  res.pos_min = 1000000;
  res.type = NO_REDIR;

  find_redir(argv, "<", REDIR_IN, &res);

  find_redir(argv, ">", REDIR_OUT, &res);

  find_redir(argv, "1>", REDIR_OUT, &res);

  find_redir(argv, "2>", REDIR_OUT_ERR, &res);

  find_redir(argv, ">>", DOUBLE_REDIR_OUT, &res);

  *type_finish = res.type;
  *pos_finish = res.pos_min;
}

void	rm_redir(char	**argv, int	pos)
{
  int	i;

  free(argv[pos]);
  free(argv[pos + 1]);

  for (i = pos; argv[i + 2]; ++i)
    argv[i] = argv[i + 2];

  argv[i] = NULL;
}
