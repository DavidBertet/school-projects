/*
** lib_string.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:27:04 2008 david bertet
** Last update Sun Oct 19 04:27:10 2008 david bertet
*/

#include "lib_string.h"

unsigned int	my_strlen(const char*	str)
{
  unsigned int	i = 0;

  while (*str != '\0')
    {
      ++str;
      ++i;
    }
  return (i);
}

int	my_strcmp(const char	*s1,
		  const char	*s2)
{
  int	i;

  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i)
    {
      if (s1[i] != s2[i])
	break;
    }

  return (s1[i] - s2[i]);
}

int	my_strncmp(const char	*s1,
		   const char	*s2,
		   int		size)
{
  int	i;

  for (i = 0; i < size - 1 && s1[i] != '\0' && s2[i] != '\0'; ++i)
    {
      if (s1[i] != s2[i])
	break;
    }

  return (s1[i] - s2[i]);
}

int	my_strchr(const char	*str, int	c)
{
  for (; *str; str++)
      if (*str == c)
	return (1);

  return (0);
}

char	*my_strncpy(char	*dest, const char	*src, int	size)
{
  int	i;

  for (i = 0; src[i] && i < size; ++i)
    dest[i] = src[i];

  if (i < size)
    dest[i] = '\0';

  return (dest);
}
