/*
** utils.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sat Oct 18 01:14:02 2008 david bertet
*/

#ifndef PARSE_CMD_H_
# define PARSE_CMD_H_

int	get_size_cmd(char	*str);

char	*get_cmd(char	*str, int	*i);

int	get_size_op(char	*str);

char	*get_op(char	*str, int	*i);

#endif /* !PARSE_CMD_H_ */
