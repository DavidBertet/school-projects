/*
** libstream.h for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Sep 29 14:34:32 2008 david bertet
** Last update Sun Oct 26 07:52:34 2008 david bertet
*/

#ifndef LIBSTREAM_H_
# define LIBSTREAM_H_

# include <sys/types.h>
# include "defines.h"

typedef struct	s_sbuf
{
  char		*content;
  int		size;
}		s_buf;

typedef struct	s_sstream
{
  short		fd;
  int		mode;
  const char	*path;
  int		pos_wr;
  int		pos_rd;
  int		size_rd;
  unsigned char	buf_wr[LBS_WRITE_SIZE];
  unsigned char	buf_rd[LBS_READ_SIZE];
}		s_stream;

typedef	struct	s_sg
{
  struct s_sg	*next;
  s_stream	*stream;
}		s_g;

typedef	long	t_offset;
typedef	long	t_fpos;

extern	s_g	*g_s;

int     lbs_fgetc(s_stream      *stream);

int	lbs_fgetc_str(s_stream	*stream);

s_stream *lbs_fopen(const char	*path,
		    const char	*mode);

int	lbs_fclose(s_stream	*stream);

int	lbs_fputc(int		c,
		  s_stream	*stream);

int	lbs_fflush(s_stream	*stream);

int	lbs_fpurge(s_stream	*stream);

s_stream	*lbs_fdopen(int		fildes,
			    const char	*mode);

s_stream	*lbs_freopen(const char	*path,
			     const char	*mode,
			     s_stream	*stream);

int	lbs_fseek(s_stream	*stream,
		  long		offset,
		  int		whence);

int	lbs_fseeko(s_stream	*stream,
		   t_offset	offset,
		   int		whence);

long	lbs_ftell(s_stream	*stream);

t_offset	lbs_ftello(s_stream	*stream);

int	lbs_fsetpos(s_stream		*stream,
		    const t_fpos	*pos);

int	lbs_fgetpos(s_stream	*stream,
		    t_fpos	*pos);

size_t	lbs_fread(void		*ptr,
		  size_t	size,
		  size_t	nmemb,
		  s_stream	*stream);

size_t	lbs_fwrite(const void	*ptr,
		   size_t	size,
		   size_t	nmemb,
		   s_stream	*stream);

char	*lbs_fgets(char		*str,
                   int		size,
                   s_stream	*stream);

ssize_t		lbs_getdelim(char	**lineptr,
			     size_t	*n,
			     int	delimiter,
			     s_stream	*stream);

ssize_t		lbs_getdelim_str(char		**lineptr,
				 size_t		*n,
				 int		delimiter,
				 s_stream	*stream);

ssize_t	lbs_getline(char	**lineptr,
		    size_t	*n,
		    s_stream	*stream);

#endif /* !LIBSTREAM_H_ */
