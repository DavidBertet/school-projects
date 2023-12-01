#include "const_myftp.h"

static void	recv_ls(struct s_user	*user)
{
  char		buf[1024];
  int		size;

  do
    {
      size = recv(user->data_sock, buf, 1023, 0);
      buf[size] = '\0';
      if (size > 0)
	print_string(buf, STDOUT_FILENO, 0);
     }
  while (size > 0);

  size = recv(user->data_sock, buf, 1023, 0);
  if (size > 0)
    buf[size] = '\0';
  close(user->data_sock);
  if (!user->pasv)
    close(user->data_sock_actif);
  read_socket(user->cmd_sock);
  return;
}

void		func_ls(char		*arg,
			struct s_user	*user)
{
  unsigned int	tmp = sizeof (struct sockaddr_in);

  arg =arg;

  if (user->pasv)
    func_pasv("PASV", user);
  else
    func_port(prep_port(user), user);
  if (user->last_state == 425)
    return;
  if (user->data_sock == -1 && user->data_sock_actif == -1)
    return;

  print_cmd("LIST");

  send_cmd(user->cmd_sock, "LIST");
  user->last_state = get_state(read_socket(user->cmd_sock));
  if (user->last_state != 150)
    {
      close(user->data_sock_actif);
      return;
    }
  if (!user->pasv)
    user->data_sock = accept(user->data_sock_actif, user->sockaddr, &tmp);
  recv_ls(user);
  free(user->sockaddr);
  user->data_sock_actif = -1;

  return;
}
