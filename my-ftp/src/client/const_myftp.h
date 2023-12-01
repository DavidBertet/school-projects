#ifndef CONST_MYFTP_H_
# define CONST_MYFTP_H_

# include "func_myftp.h"

/*
** Header : const_myftp.h
** Here are the constants made for this tiny FTP client.
*/

/*
** INIT_PORT
*/
# define INIT_PORT 22

/*
** MIN_PORT
*/
# define MIN_PORT 2500

/*
** MAX_PORT
*/
# define  MAX_PORT 3000

/*
** ftp_cmd .cmd .nb_args .func : link cmd and functions.
*/
static const struct s_cmd	ftp_cmd[] =
  {
    {"USER", 1, func_user},
    {"PASS", 1, func_pass},
    {"PORT", 1, func_port},
    {"TYPE", 1, func_type},
    {"GET", 1, func_get},
    {"PUT", 1, func_put},
    {"CD", 1, func_cd},
    {"RMDIR", 1, func_rmdir},
    {"MKDIR", 1, func_mkdir},
    {"DELETE", 1, func_delete},
    {"PWD", 0, func_pwd},
    {"QUIT", 0, func_quit},
    {"EXIT", 0, func_quit},
    {"NOOP", 0, func_noop},
    {"SYSTEM", 0, func_syst},
    {"HELP", 0, func_help},
    {"PASV", 0, func_pasv},
    {"AUTO", 0, func_auto},
    {"LS", 0, func_ls},
    {"", 0, NULL}
  };

/*
** End of the header const_myftp.h
*/

#endif /* !CONST_MYFTP_H_ */
