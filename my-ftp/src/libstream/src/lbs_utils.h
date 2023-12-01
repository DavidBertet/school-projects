/*
** lbs_utils.h for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 15:31:10 2008 david bertet
** Last update Sun Oct  5 07:46:57 2008 david bertet
*/

enum e_smode{SREAD = 'r', SWRITE ='w', SAPPEND = 'a'};
enum e_smodeplus{SPLUS = '+', SBINARY ='b', SEOF = '\0'};

int	find_mode_sec(const char	*flag, int	res);

int	find_mode_princ(const char	*flag);
