#include <stdlib.h>
#include "SDL/SDL.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL_image.h"

#include "init_sdl.hh"
#include "textures.hh"

int	init_sdl(void)
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

  SDL_WM_SetCaption("Chess", NULL);

  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 800/600, 0.1, 2000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  SDL_ShowCursor(SDL_DISABLE);
  SDL_EnableKeyRepeat(1, 1);
  glShadeModel(GL_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  return (0);
}

int		start_display()
{
  s_texture_image tab;

  init_sdl();

//  load_textures (&tab);

//  main_loop(&tab);

  SDL_Quit();
  return (0);
}
