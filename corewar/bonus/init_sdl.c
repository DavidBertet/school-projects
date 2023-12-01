#include <stdlib.h>
#include "SDL/SDL.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL_image.h"
#include "mainloop.h"
#include "init_sdl.h"

static int	init_sdl(void)
{
  SDL_Surface	*screen = NULL;
  int           width = 800;
  int           height = 800;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
    exit(1);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);

  if (!screen)
    exit(2);

  SDL_WM_SetCaption("Corewar", NULL);

  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 800/600, 0.1, 2000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
/*   gluLookAt(-50, 0, -250, 100, 0, 0, 0.0, -1.0 ,0.0); */

  SDL_ShowCursor(SDL_DISABLE);
  SDL_EnableKeyRepeat(1, 1);
  glShadeModel(GL_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  return (0);
}

int		start_display()
{
  init_sdl();

  main_loop();

  SDL_Quit();
  return (0);
}
