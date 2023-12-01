#include "const_myftp.h"

static void	recv_file(struct s_user	*user,
			  char		*filename)
{
  char		buf[128];
  int		cpt = 0;
  s_stream	*stream;
  int		size;

  if (filename[0] == '\0')
    return;
  stream = lbs_fopen(filename, "w");
  print_string("Start transfert", STDOUT_FILENO, 0);
  do
    {
      size = recv(user->data_sock, buf, 128, 0);
      if (size > 0)
	lbs_fwrite(buf, 1, size, stream);
      if (cpt++ == 1024 * 1024 / 128 && !(cpt = 0))
	print_string(".", STDOUT_FILENO, 0);
    }
  while (size > 0);
  print_string("\n", STDOUT_FILENO, 1);

  lbs_fclose(stream);

  close(user->data_sock);

  if (!user->pasv)
    close(user->data_sock_actif);

  read_socket(user->cmd_sock);
  return;
}

void		func_get(char		*arg,
			 struct s_user	*user)
{
  unsigned int	tmp = sizeof (struct sockaddr_in);

  func_type(user->type, user);

  if (user->pasv)
    func_pasv("PASV", user);
  else
    func_port("PORT", user);

  if (user->data_sock == -1 && user->data_sock_actif == -1)
    return;

  func_retr(arg, user);

  if (user->last_state != 150)
    {
      close(user->data_sock_actif);
      return;
    }

  if (!user->pasv)
    user->data_sock = accept(user->data_sock_actif, user->sockaddr, &tmp);

  recv_file(user, get_filename(arg));

  user->data_sock_actif = -1;
  return;
}
