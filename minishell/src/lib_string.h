/*
** lib_string.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:26:45 2008 david bertet
** Last update Sun Oct 19 04:30:24 2008 david bertet
*/

#ifndef LIB_STRING_H_
# define LIB_STRING_H_

unsigned int	my_strlen(const char*	str);

int		my_strcmp(const char	*s1,
			  const char	*s2);

int		my_strncmp(const char	*s1,
			   const char	*s2,
			   int		size);

int		my_strchr(const char	*str, int	c);

char		*my_strncpy(char	*dest, const char	*src, int	size);

#endif /* !LIB_STRING_H_ */
