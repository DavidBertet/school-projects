#include "const_myftpd.h"

int      open_log(s_server       s,
		  char           *file)
{
  if (s.is_log)
    return (open(file, O_CREAT | O_WRONLY | O_APPEND, 0644));
  else
    return (0);
}

void     close_log(s_server      s)
{
  if (s.is_log)
    close(s.fd_log);
  return;
}

void		print_date_log(s_server	s)
{
  char		line[26];
  time_t	tloc;

  if (s.is_log)
    {
      time(&tloc);
      ctime_r(&tloc, line);
      write(s.fd_log, line, my_strlen(line));
    }
  return;
}

void     print_log(s_server      s,
		   char          *text)
{
  if (s.is_log)
    write(s.fd_log, text, my_strlen(text));
  return;
}

void		print_int_log(s_server  s,
			      int       i)
{
  char          out[20];
  int           size = 1;
  int           count = 0;
  int           neg = 0;

  if (!s.is_log)
    return;
  if (i < 0)
    {
      neg = 1;
      i = -i;
    }
  for (; (size <= i) || (count == 0); size *= 10)
    count++;
  for (size = count + neg - 1; size >= neg; size--)
    {
      out[size] = (i - ((i / 10) * 10)) + '0';
      i /= 10;
    }
  if (neg == 1)
    out[0] = '-';
  out[count + neg] = '\0';
  write(s.fd_log, out, count + neg);
  return;
}
