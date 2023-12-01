#ifndef CONST_MYFTPD_H_
# define CONST_MYFTPD_H_

# include "func_myftpd.h"

/*
** Header : const_myftpd.h
** Here are the constants made for this tiny FTP server.
*/

/*
** Constants NO_IDENT, NEED_IDENT and ROOT_IDENT : for the identifications.
*/
# define NO_IDENT	0
# define NEED_IDENT	1
# define ROOT_IDENT	2

/*
** Constants CMD and DATA : for the different connections.
*/
# define CMD	0
# define DATA	1
/*
** Constants LOW_PORT and HIGH_PORT : lowest and highest ports available in
** PASV.
*/
# define LOW_PORT	30000
# define HIGH_PORT	40000

/*
** gopt : different options for the server.
*/
static const s_opt gopt[] =
{
  {"-h", 0, display_help, "Affiche l'aide du serveur"},
  {"-p", 1, get_port, "Port sur lequel ecoute le serveur"},
  {"-d", 0, become_a_daemon, "Demonise le serveur"},
  {"-l", 1, write_a_log, "Log les requetes effectuees sur le serveur"},
  {"-i", 1, display_help, "Adresse IP du serveur"},
  {"-P", 1, display_help, "Range de port disponible pour mode passif"},
  {"-a", 1, display_help, "Plugin d'authentification"},
  {NULL, 0, NULL, NULL}
};

/*
** ftp_asw : link between the client and the correct answer.
*/
static const s_asw ftp_asw[] =
  {
    {"USER", cmd_user_myftpd},
    {"PASS", cmd_pass_myftpd},
    {"HELP", cmd_help_myftpd},
    {"NOOP", cmd_noop_myftpd},
    {"CWD" , cmd_cwd_myftpd},
    {"PWD", cmd_pwd_myftpd},
    {"SYST", cmd_syst_myftpd},
    {"QUIT", cmd_quit_myftpd},
    {"TYPE ", cmd_type_myftpd},
    {"PORT ", cmd_port_myftpd},
    {"LIST", cmd_list_myftpd},
    {"RETR", cmd_retr_myftpd},
    {"STOR", cmd_stor_myftpd},
    {"PASV", cmd_pasv_myftpd},
    {"DELE", NULL},
    {"MKD", NULL},
    {"RMD", NULL},
    {NULL, cmd_unknown_myftpd}
  };

/*
** ftp_msg .number .text : link between the code and its text.
*/
static const s_msg ftp_msg[] =
  {
    {110, "110 MARK\r\n"},
    {120, "120 SERVICE AVAILABLE SOON\r\n"},
    {125, "125 ALREADY OPENED, TRANSFERING\r\n"},
    {150, "150 FILE OKAY, BEGINNING THE TRANSFER\r\n"},
    {200, "200 END OF THE COMMAND\r\n"},
    {202, "202 COMMAND NOT YET KNOWN\r\n"},
    {211, "211 SYSTEM\r\n"},
    {212, "212 DIRECTORY\r\n"},
    {213, "213 FILE\r\n"},
    {214, "214 END OF THE HELP\r\n"},
    {215, "215 UNIX-BSD\r\n"},
    {220, "220 READY\r\n"},
    {221, "221 STREAM CLOSED\r\n"},
    {225, "225 STREAM OPENED AND READY\r\n"},
    {226, "226 CLOSING THE STREAM\r\n"},
    {227, "227 PASSIVE MODE\r\n"},
    {230, "230 SESSION READY\r\n"},
    {250, "250 FILE SERVICE OKAY\r\n"},
    {257, "257 PATH CREATED\r\n"},
    {331, "331 NAME OKAY, GIMME YOUR PASSWORD (IF YOU'RE NOT ANON)\r\n"},
    {332, "332 WHO ARE YOU ?\r\n"},
    {350, "350 FILE SERVICE WAITING\r\n"},
    {421, "421 I'M GOING TO BE SHUT DOWN; PLEASE FLEE\r\n"},
    {425, "425 I CANNOT OPEN THE STREAM\r\n"},
    {426, "426 CONNECTION CLOSED, SORRY FOR YOUR TRANSFER :(\r\n"},
    {450, "450 FILE NOT AVAILABLE AT THE MOMENT\r\n"},
    {451, "451 LOCAL ERROR\r\n"},
    {452, "452 NOT ENOUGH SPACE\r\n"},
    {500, "500 SYNTAX ERROR OR LINE TOO LONG\r\n"},
    {501, "501 SYNTAX ERROR IN THE ARGUMENTS\r\n"},
    {502, "502 COMMAND TOO COMPLEX FOR ME :(\r\n"},
    {503, "503 COMMANDS IN THE WRONG ORDER\r\n"},
    {504, "504 ARGUMENT TOO COMPLEX FOR ME :(\r\n"},
    {530, "530 SESSION NOT OPENED; GTFO H4CK3R\r\n"},
    {532, "532 PLEASE GIMME A *GOOD* IDENTIFICATION\r\n"},
    {550, "550 CANNOT ACCESS TO THE FILE\r\n"},
    {551, "551 UNKNOWN PAGE\r\n"},
    {552, "552 EXCESS : QUOTA >8(\r\n"},
    {553, "553 WRONG FILE NAME\r\n"},
    {-1, "NO NUMBER : WARNING : INTERNAL ERROR. WTH IS GOING ON HERE ?\r\n"}
  };

/*
** End of the header const_myftpd.h
*/

#endif /* !CONST_MYFTPD_H_ */
