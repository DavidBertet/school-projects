#include <vector>
#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "draw.hh"
#include "textures.hh"

#include "chessboard-adapter.hh"
#include "position.hh"
#include "piece-type.hh"

int		keyboard()
{
  Uint8			*keyState;

  SDL_PumpEvents();
  keyState = SDL_GetKeyState(NULL);
  if (keyState[SDLK_RETURN])
    return (255);
   if (keyState[SDLK_ESCAPE])
     exit (0);
/*   if (keyState[SDLK_LEFT]) */
/*     env_global->info3d.posx += SPEED; */
/*   if (keyState[SDLK_RIGHT]) */
/*     env_global->info3d.posx -= SPEED; */
/*   if (keyState[SDLK_UP]) */
/*     env_global->info3d.posz += SPEED; */
/*   if (keyState[SDLK_DOWN]) */
/*     env_global->info3d.posz -= SPEED; */
  return (0);
}
void draw_piece (int i, int j, int color, int type,
		 std::vector <s_texture_image*>& tab)
{
  float y = -1;
  float size = 4;

  float x = (i - 1) * 10;
  float z = (j - 1) * 10;

  glColor3f(1, 1, 1);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, tab[type]->texID);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex3f(x - size, y, z + size);
  glTexCoord2f(1, 1);
  glVertex3f(x + size, y, z + size);
  glTexCoord2f(1, 0);
  glVertex3f(x + size, y, z - size);
  glTexCoord2f(0, 0);
  glVertex3f(x - size, y, z - size);
  glEnd();

  glDisable(GL_TEXTURE_2D);
}

void draw_board ()
{
  float		x;
  float		y;
  float		z;
  float		size;
  int		i;
  int		j;

  y = 0;
  size = 5;

  for (i = 0; i < 8; ++i)
  {
    for (j = 0; j < 8; ++j)
    {
      if ((i + j) % 2)
	glColor3f(0.1, 0.3, 0.1);
      else
	glColor3f(1, 1, 1);

      x = i * 10;
      z = j * 10;

      glBegin(GL_QUADS);
      glVertex3f(x - size, y, z + size);
      glVertex3f(x + size, y, z + size);
      glVertex3f(x + size, y, z - size);
      glVertex3f(x - size, y, z - size);
      glEnd();
    }
  }

  glColor3f(0.6, 0.2, 0.1);
  glBegin(GL_QUADS);
  glVertex3f(-4, 0, 75);
  glVertex3f(75, 0, 75);
  glVertex3f(75, 10, 75);
  glVertex3f(-4, 10, 75);
  glEnd();

  glBegin(GL_QUADS);
  glVertex3f(75, 0, -4);
  glVertex3f(75, 0, 75);
  glVertex3f(75, 10, 75);
  glVertex3f(75, 10, -4);
  glEnd();
}

void    draw_all(std::vector <s_texture_image*>& tab,
		 const ChessboardAdapter& chessboard)
{
  SDL_Delay (100);

  glLoadIdentity();
  gluLookAt(80, /*posx*/
	    -60, /*posz*/
	    80, /*posy*/
	    50, 0, 50, 0.0, -1.0 ,0.0);
  glColor3f(1, 1, 1);
  glClearColor(0.3, 0.1, 0.05, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  draw_board ();

  for (Position::File i = Position::ANNA; i < Position::FILE_LAST; ++i)
  {
    for (Position::Rank j = Position::EINS; j < Position::RANK_LAST; ++j)
    {
      if (chessboard[Position(i, j)].first != NONE)
      {
	draw_piece (i, j, chessboard[Position(i, j)].second,
		    chessboard[Position(i, j)].first +
		    (6 * (chessboard[Position(i, j)].second)),
		    tab);
      }
    }
  }

  while (keyboard() != 255)
    SDL_Delay (10);

  SDL_GL_SwapBuffers();
  return;
}
