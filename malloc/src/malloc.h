/*
** malloc.h for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Oct  7 16:14:42 2008 david bertet
** Last update Sun Oct 12 09:51:25 2008 david bertet
*/

#include <sys/types.h>
#include "utils.h"

void *malloc(int size);
void free(void *ptr_void);
void *realloc(void *ptr, int size);
void *calloc(size_t count, size_t size);
void my_show_mem(void);
