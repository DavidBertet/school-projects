#include "func.h"

static void     draw_sun(s_game *game)
{
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[TEXT_SUN].texID);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(5, 30);
  glTexCoord2f(1, 1);
  glVertex2f(15, 30);
  glTexCoord2f(1, 0);
  glVertex2f(15, 20);
  glTexCoord2f(0, 0);
  glVertex2f(5, 20);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}

static void     draw_planet(s_game *game)
{
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[TEXT_PLANET].texID);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(15, 80);
  glTexCoord2f(1, 1);
  glVertex2f(30, 80);
  glTexCoord2f(1, 0);
  glVertex2f(30, 65);
  glTexCoord2f(0, 0);
  glVertex2f(15, 65);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}

void     draw_map(s_game *game)
{
  draw_sun(game);
  draw_planet(game);
  return;
}
