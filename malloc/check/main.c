/*
** main.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 12 11:24:58 2008 david bertet
*/

#include <stdio.h>
#include <unistd.h>
#include "../src/malloc.h"

int	main(void)
{
  char	*tmp;
  char	*tmp1;
  char	*tmp2;
  int	i;

  printf("DEBUT DU TEST\n\n");
  printf("NIVEAU 1 et 2 ---------------------\n");
  printf("BEGIN:   %p\n", sbrk(0));

  i = 4;
  tmp = malloc(i);
  printf("MALLOC de %d alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp);
  printf ("END:     %p\n\n", sbrk(0));

  printf("Etat de la memoire\n");
  my_show_mem();

  printf("\nNIVEAU 3 ---------------------------\n");
  free(tmp);
  printf("FREE ptr, new content: %p\n", *(char **)tmp);
  printf("Nouvelle tete pour free_list[%d]: %p\n\n", log2i(i + 4),
	 g_free_list[log2i(i + 4)]);

  printf("Etat de la memoire\n");
  my_show_mem();

  i = 9;
  tmp1 = malloc(i);
  printf("\nMALLOC de %d alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp1);
  printf("END:     %p\n", sbrk(0));

  i = 9;
  tmp2 = malloc(i);
  printf("\nMALLOC de %d alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp2);
  printf("END:     %p\n", sbrk(0));

  i = 4;
  tmp = malloc(i);
  printf("MALLOC de %d alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp);
  
  free(tmp1);
  printf("FREE le malloc de 9, new content: %p\n", *(char **)tmp1);
  printf("Nouvelle tete pour free_list[%d]: %p\n\n", log2i(9 + 4),
	 g_free_list[log2i(9 + 4)]);

  free(tmp2);
  printf("FREE le malloc de 9, new content: %p\n", *(char **)tmp2);
  printf("Nouvelle tete pour free_list[%d]: %p\n\n", log2i(9 + 4),
	 g_free_list[log2i(9 + 4)]);

  i = 9;
  tmp = malloc(i);
  printf("MALLOC de %d alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp);

  printf("\nNIVEAU 4 --------------------------\n");
  i = 4;
  tmp = calloc(i, 1);
  printf("CALLOC de %d x 1 alloue %d  -->  pointeur: %p\n", i,
	 1 << (log2i(i + 4) + 2), tmp);

  printf("\nNIVEAU 5 --------------------------\n");

  printf("Etat de la memoire\n");
  my_show_mem();

  printf("\nNIVEAU 6 -------------------------\n");
  printf("FREE de %p\n", sbrk(0) + 150);
  free(sbrk(0) + 150);
  printf("\nNIVEAU 7 -------------------------\n");
  printf("FREE de %p\n", g_free_list[0] - 150);
  free(g_free_list[0] - 150);

  printf("\nNIVEAU 9 --------------------------\n");
  *tmp = 'a';
  printf("content of ptr %c\n", *tmp);
  printf("REALLOC de 4 en 1\n");
  tmp = realloc(tmp, 1);
  printf("content of ptr after realloc %c\n", *tmp);
  printf("tmp: %p\n", tmp);

  return (0);
}
