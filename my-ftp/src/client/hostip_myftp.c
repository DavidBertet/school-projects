#include "const_myftp.h"

char			**get_host_ip(void)
{
  char			**ret;
  char			*hostname;
  struct hostent	*hp;
  int			i;

  ret = malloc(4);
  hostname = malloc(255);
  gethostname(hostname, 255);
  if ((hp = gethostbyname(hostname)) == NULL)
    {
      perror("gethostbyname on get_host_ip");
      return (NULL);
    }

  for (i = 0; i < 4; ++i)
    ret[i] = my_itoa(hp->h_addr_list[0][i]);

  return (ret);
}
