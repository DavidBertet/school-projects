/*
** utils_redir.h for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:24:02 2008 david bertet
** Last update Sun Oct 19 04:24:10 2008 david bertet
*/

#ifndef UTILS_REDIR_H_

# define UTILS_REDIR_H_

# define NO_REDIR 0
# define REDIR_IN 1
# define REDIR_OUT 2
# define REDIR_OUT_ERR 3
# define DOUBLE_REDIR_OUT 4

void	treat_redir(char	**argv,
		    int		*pos_finish,
		    int		*type_finish);

void	rm_redir(char	**argv, int	pos);

#endif /* !UTILS_REDIR_H_ */
