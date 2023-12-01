#include "const_myftp.h"

static void	send_file(struct s_user	*user,
			  char		*filename)
{
  s_stream	*stream;
  char		buf[128];
  int		size;
  int		cpt;
  int		end = 1;

  if (filename[0] == '\0')
    return;
  stream = lbs_fopen(filename, "r");
  print_string("Start transfert", STDOUT_FILENO, 0);
  while (end > 0)
    {
      size = lbs_fread(buf, 1, 128, stream);
      end = send(user->data_sock, buf, size, 0);

      if (cpt++ == 1024 * 1024 / 128 && !(cpt = 0))
	print_string(".", STDOUT_FILENO, 0);
    }
  print_string("\n", STDOUT_FILENO, 0);
  lbs_fclose(stream);
  if (!user->pasv)
    close(user->data_sock_actif);
  close(user->data_sock);
  user->data_sock = -1;
  read_socket(user->cmd_sock);
  return;
}

void		func_put(char		*arg,
			 struct s_user	*user)
{
  unsigned int	tmp = sizeof (struct sockaddr_in);

  func_type("TYPE i", user);

  if (user->pasv)
    func_pasv("PASV", user);
  else
    func_port(prep_port(user), user);

  if (user->data_sock == -1 && user->data_sock_actif == -1)
    return;

  func_stor(arg, user);

  if (user->last_state != 150)
    {
      close(user->data_sock_actif);
      return;
    }

  if (!user->pasv)
    user->data_sock = accept(user->data_sock_actif, user->sockaddr, &tmp);

  send_file(user, get_filename(arg));

  return;
}
