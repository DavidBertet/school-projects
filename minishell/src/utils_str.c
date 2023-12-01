/*
** utils_str.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sun Oct 19 03:58:14 2008 david bertet
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_string.h"
#include "utils.h"
#include "utils_str.h"

static int	my_nb_arg(char	*str, char	c)
{
  int		i = 0;

  while (*str != '\0')
    {
      if (*str == c)
	{
	  ++str;
	  continue;
	}
      ++i;
      while ((*str != '\0') && (*str != c))
	++str;
    }
  return (i);
}

static void	treat_env(char	**argv, int	last_status)
{
  int		i;
  char		*env = NULL;

for (i = 0; argv[i]; ++i)
  if (*argv[i] == '$')
    {
      if (*(argv[i] + 1) == '?')
	{
	  *(argv[i] + 1) = ' ';
	  env = my_atoi(last_status);
	}
      else
	env = getenv(argv[i] + 1);
      if (env)
	my_strncpy(argv[i], env, my_strlen(env));
    }
}

char	**my_split(char	*str, char	c, int	last_status)
{
  int	i = 0;
  int	k = 0;
  char	**res;

  res = malloc(my_nb_arg(str, c) + 1);
  while (*str != '\0')
    {
      if (*str == c)
	{
	  ++str;
	  continue;
	}
      res[i] = malloc(400); /* TODO */
      k = 0;
      while (*str != '\0' && *str != c)
	{
	  res[i][k++] = *str;
	  ++str;
	}
      ++i;
    }
  res[i] = 0;
  treat_env(res, last_status);

  return (res);
}

void	print_tab(char	**tab)
{
  int	i;

  write(STDOUT_FILENO, "|", 1);
  for (i = 0; tab[i]; ++i)
    {
      write(STDOUT_FILENO, tab[i], my_strlen(tab[i]));
      write(STDOUT_FILENO, "|", 1);
    }
  write(STDOUT_FILENO, "\n", 1);
}

int	size_tab(char	**argv)
{
  int	i;

  for (i = 0; argv[i]; ++i)
    ;

  return (i);
}

int	find_tab(char	**argv, char	*c, int	end)
{
  int	i;

  if (!end)
    {
      for (i = 0; argv[i]; ++i)
	if (!my_strncmp(c, argv[i], my_strlen(argv[i])))
	  return (i + 1);
    }
  else
    {
      for (i = size_tab(argv) - 1; i >= 0; --i)
	if (!my_strncmp(c, argv[i], my_strlen(argv[i])))
	  return (i + 1);
    }
  return (0);
}
