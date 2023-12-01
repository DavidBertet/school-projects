#include "const_myftpd.h"

static char	*build_line(s_client	*client,
			    char	*buf,
			    char	*line)
{
  int		slash = 0;
  int		test = 0;

  if (buf[(my_strlen(buf)) - 1] != '/')
    slash = 1;
  line = malloc(my_strlen(client->wd_path) + my_strlen(buf) + 1 + slash);
  for (test = 0; client->wd_path[test] != '\0'; test++)
    line[test] = client->wd_path[test];
  for (test = 0; buf[test] != '\0'; test++)
    line[test + my_strlen(client->wd_path)] = buf[test];
  if (slash == 1)
    line[test + my_strlen(client->wd_path)] = '/';
  line[test + my_strlen(client->wd_path) + slash] = '\0';
  return (line);
}

static char	*correction(char	*s)
{
  int		i = 0;
  int		j = 0;
  int		k = 0;
  int		l = 0;

  for (i = 0; i <= my_strlen(s) - 2; i++)
    {
      if ((s[i] == '/') && ((s[i + 1] == '.') && (s[i + 2] == '.')))
	{
	  for (j = i - 1; ((j >= 2) && (s[j] != '/')); j--)
	    ;
	  if (i <= 1)
	    s[0] = '\0';
	  for (k = 0, l = 0; s[k] != '\0'; k++)
	    {
	      if (!((k >= j + 1) && (k <= i + 3)))
		{
		  s[l] = s[k];
		  l++;
		}
	    }
	  s[l] = '\0';
	  s = correction(s);
	}
    }
  return (s);
}

static char     *correction2(char        *s)
{
  int           i = 0;
  int           k = 0;
  int           l = 0;

  for (i = 0; i <= my_strlen(s) - 1; i++)
    {
      if ((s[i] == '/') && (s[i + 1] == '.'))
        {
          for (k = 0, l = 0; s[k] != '\0'; k++)
            {
              if (!((k >= i) && (k <= i + 1)))
                {
                  s[l] = s[k];
                  l++;
                }
            }
          s[l] = '\0';
          s = correction2(s);
        }
    }
  return (s);
}

static int	path(s_client	*client,
		     char	*buf)
{
  struct stat	sb;
  char		*line = NULL;
  int		test = 0;

  line = build_line(client, buf, line);
  line = correction(line);
  line = correction2(line);
  test = stat(line, &sb);
  if ((!test) && (S_ISDIR(sb.st_mode)))
    {
      free(client->wd_path);
      client->wd_path = line;
      return (0);
    }
  else
    {
      free(line);
      return (1);
    }
}

void	cmd_cwd_myftpd(s_server	*server,
		       s_client	*client,
		       char	*buf)
{
  print_log(*server, " |_ Command : CWD\n");
  print_log(*server, "   |_");
  print_log(*server, buf);
  print_log(*server, "\n");
  if (my_strlen(buf) <= 4)
    {
      print_log(*server, "   |_ Name too short\n");
      answer(*server, client, 501, NO_IDENT);
    }
  else
    {
      if (verif_ident(*server, client, NEED_IDENT))
	{
	  if (path(client, buf + 4))
	    answer(*server, client, 553, NO_IDENT);
	  else
	    answer(*server, client, 250, NEED_IDENT);
	}
    }
  return;
}
