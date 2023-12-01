/*
** utils_app.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sat Oct 18 20:00:44 2008 david bertet
*/

#ifndef UTILS_APP_H_
# define UTILS_APP_H_

int	treat_app(char	*argv, int	wait_bool, int	last_status);

int	launch_app(char	**argv, int	wait_bool);

#endif /* !UTILS_APP_H_ */
