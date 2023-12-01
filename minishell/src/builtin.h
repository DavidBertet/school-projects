/*
** builtin.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:27:29 2008 david bertet
** Last update Sun Oct 19 04:27:44 2008 david bertet
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

int	my_pwd(char	**str);

int	my_echo(char	**str);

int	my_cd(char	**str, int	brother);

int	my_export(char	**str);

void	my_exit(char	**str);

#endif /* !BUILTIN_H_ */
