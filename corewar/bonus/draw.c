#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "draw.h"

/* void     draw_pict(s_tree	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 0.3; */

/*   glColor3f(-z / 255, -z / 255, -z / 255); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void     draw_point_yellow(s_tree	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 2; */

/*   glColor3f(255, 255, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void		 draw_mat_pict(s_env	*env_global) */
/* { */
/*   int		i; */
/*   int		j; */
/*   float		z; */
/*   float		size; */
/*   unsigned char	c; */

/*   for (i = 0; i < env_global->height_pict; ++i) */
/*     { */
/*       for (j = 0; j < env_global->width_pict; ++j) */
/* 	{ */
/* 	  c = env_global->mat_pict[i][j]; */
/* 	  z = -c; */
/* 	  size = 0.3; */

/* 	  glColor3f(-z / 255, -z / 255, -z / 255); */
/* 	  glBegin(GL_QUADS); */
/* 	  glVertex3f(j - size, i + size, z / 10); */
/* 	  glVertex3f(j + size, i + size, z / 10); */
/* 	  glVertex3f(j + size, i - size, z / 10); */
/* 	  glVertex3f(j - size, i - size, z / 10); */
/* 	  glEnd(); */
/* 	} */
/*     } */
/* } */

/* void     draw_rec_pict(s_tree	*tree) */
/* { */
/*   draw_pict(tree); */
/*   if (tree->fg != NULL) */
/*     draw_rec_pict(tree->fg); */
/*   if (tree->fd != NULL) */
/*     draw_rec_pict(tree->fd); */

/*   return; */
/* } */

/* void     draw_parcour_pict(s_tree	*tree, */
/* 			   int		i) */
/* { */
/*   float		search_x; */
/*   float		search_y; */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   search_x = 100; */
/*   search_y = 90; */

/*   x = tree->x; */
/*   y = tree->y; */
/*   z = -tree->z; */
/*   size = 1; */

/*   if (i == 1) */
/*     glColor3f(255, 0, 0); */
/*   else */
/*     glColor3f(0, 255, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   draw_pict(tree); */
/*   if (i == 0) */
/*     { */
/*       if (tree->fg != NULL && search_x < tree->x) */
/* 	draw_parcour_pict(tree->fg, 1); */
/*       else if (tree->fd != NULL) */
/* 	draw_parcour_pict(tree->fd, 1); */
/*       else */
/* 	draw_point_yellow(tree); */
/*     } */
/*   if (i == 1) */
/*     { */
/*       if (tree->fg != NULL && search_y < tree->y) */
/* 	draw_parcour_pict(tree->fg, 0); */
/*       else if (tree->fd != NULL) */
/* 	draw_parcour_pict(tree->fd, 0); */
/*       else */
/* 	draw_point_yellow(tree); */
/*     } */

/*   return; */
/* } */

/* void     draw_cloud(s_point	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 0.3; */

/*   glColor3f(1, 0, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void     draw_red(s_point	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 0.3; */

/*   glColor3f(1, 0, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void     draw_green(s_point	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 0.3; */

/*   glColor3f(0, 1, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void     draw_large_blue(s_point	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 1; */

/*   glColor3f(0, 0, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void     draw_point(s_point	*point) */
/* { */
/*   float		x; */
/*   float		y; */
/*   float		z; */
/*   float		size; */

/*   x = point->x; */
/*   y = point->y; */
/*   z = -point->z; */
/*   size = 1; */

/*   glColor3f(1, 0, 0); */
/*   glBegin(GL_QUADS); */
/*   glVertex3f(x - size, y + size, z / 10); */
/*   glVertex3f(x + size, y + size, z / 10); */
/*   glVertex3f(x + size, y - size, z / 10); */
/*   glVertex3f(x - size, y - size, z / 10); */
/*   glEnd(); */

/*   return; */
/* } */

/* void	draw_objects(s_env	*env_global) */
/* { */
/*   s_point	*point = NULL; */

/*   draw_mat_pict(env_global); */

/*   point = env_global->cloud; */
/*   while (point != NULL) */
/*   { */
/* /\*     draw_cloud(point); *\/ */
/*     point = point->next; */
/*   } */

/*   point = env_global->pict_tmp; */
/*   while (point != NULL) */
/*   { */
/*     draw_red(point); */
/*     point = point->next; */
/*   } */

/*   point = env_global->cloud_tmp; */
/*   while (point != NULL) */
/*   { */
/*     draw_green(point); */
/*     point = point->next; */
/*   } */

/*   return; */
/* } */

void    draw_all()
{
/*   static int ok = 0; */

  glLoadIdentity();
  gluLookAt(100, /*posx*/
	    50, /*posz*/
	    100, /*posy*/
	    100, 50, 0, 0.0, -1.0 ,0.0);
  glColor3f(1, 1, 1);
  glClearColor(0.2, 0.2, 0.9, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /*draw_objects(env_global);*/

  /*draw_large_blue(env_global->Up);*/

/*   if (ok++ < 10) */
/*     finition_algo(env_global); */
  SDL_Delay(1);

  SDL_GL_SwapBuffers();
  return;
}
