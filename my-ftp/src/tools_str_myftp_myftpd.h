#ifndef TOOLS_STR_MYFTP_MYFTPD_H_
# define TOOLS_STR_MYFTP_MYFTPD_H_

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*
** Header : tools_str_myftp_myftpd.h
** Here are the exported basic string functions made for the FTP server
** and client.
*/

/*
** my_strlen() : returns the size of the string.
*/
int     my_strlen(const char    *str);

/*
** my_strcmp() : compares two strings.
*/
int     my_strcmp(char         *s,
		  char         *p);

/*
** my_strcpy() : copy the string s2 to the string s1
*/
char     *my_strcpy(char         *s1,
		    char         *s2);

/*
** my_atoi() : changes a string into a integer.
*/
int	 my_atoi(char		*s);

/*
** my_itoa() : changes an integerg into a string.
*/
char	*my_itoa(int	nb);

/*
** End of the header tools_str_myftp_myftpd.h
*/

#endif /* !TOOLS_STR_MYFTP_MYFTPD_H_ */
