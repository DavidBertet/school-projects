#include "tools_str_myftp_myftpd.h"

int	my_strlen(const char	*str)
{
  int	i = 0;

  for (; str[i]; ++i)
    ;
  return (i);
}

int     my_strcmp(char         *s,
		  char         *p)
{
  int   i = 0;

  while ((s[i] == p[i]) && (s[i] != '\0') && (p[i] != '\0'))
    i++;
  if ((s[i] == '\0') || (p[i] == '\0'))
    return (0);
  if (s[i] < p[i])
    return (-1);
  else
    return (1);
}

char	*my_strcpy(char	*s1,
		   char	*s2)
{
  int	i = 0;

  while (s2[i] != '\0')
  {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
  return (s1);
}

int	my_atoi(char	*s)
{
  int	nb = 0;

  while (*s != '\0')
    {
      nb = nb * 10;
      nb = nb + (*s - '0');
      s++;
    }
  return (nb);
}

char	*my_itoa(int	nb)
{
  int	i;
  char	*res;
  int	tmp;
  int	size;

  for (size = 0, tmp = nb; tmp != 0; ++size, tmp /= 10)
    continue;

  res = malloc(size + 1);
  res[size] = '\0';
  for (i = size - 1, tmp = nb; i >= 0; --i, tmp /= 10)
    res[i] = tmp % 10 + '0';

  return (res);
}
