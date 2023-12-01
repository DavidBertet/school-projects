/*
** utils_app.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sat Oct 18 19:31:26 2008 david bertet
*/

#ifndef UTILS_STR_H_
# define UTILS_STR_H_

char	**my_split(char	*str, char	c, int	last_status);

void	print_tab(char	**tab);

int	size_tab(char	**argv);

int	find_tab(char	**argv, char	*c, int	end);

#endif /* !UTILS_STR_H_ */
