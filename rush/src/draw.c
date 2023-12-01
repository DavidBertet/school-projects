#include "func.h"

static void     draw_friendly_ships(s_game	*game,
				    s_ship	*ship)
{
  float		x;
  float		y;
  float		size;
  float		color;

  x = ship->posx;
  y = ship->posy;
  size = 1.5 * all_ships[ship->type].radius;
  color = ship->pv;
  color /= 2 * (all_ships[ship->type].basepv);
  glColor3f(1, 0.5 + color, 0.5 + color);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[ship->animation].texID);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 1);
  glVertex2f(x - size, y + size);
  glTexCoord2d(1, 1);
  glVertex2f(x + size, y + size);
  glTexCoord2d(1, 0);
  glVertex2f(x + size, y - size);
  glTexCoord2d(0, 0);
  glVertex2f(x - size, y - size);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}

static void     draw_opponent_ships(s_game	*game,
				    s_ship	*ship)
{
  float         x;
  float         y;
  float         size;
  float         color;

  x = ship->posx;
  y = ship->posy;
  size = 1.5 * all_ships[ship->type].radius;
  color = ship->pv;
  color /= 2 * (all_ships[ship->type].basepv);
  glColor3f(1, 0.5 + color, 0.5 + color);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[ship->animation].texID);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 1);
  glVertex2f(x - size, y + size);
  glTexCoord2d(1, 1);
  glVertex2f(x + size, y + size);
  glTexCoord2d(1, 0);
  glVertex2f(x + size, y - size);
  glTexCoord2d(0, 0);
  glVertex2f(x - size, y - size);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}

static void     draw_bullet(s_game	*game,
			    s_bullet	*b)
{
  float		x;
  float         y;
  float         size;

  x = b->posx;
  y = b->posy;
  size = 1.5 * all_bullets[b->type].radius;
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[all_bullets[b->type].picture].texID);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 1);
  glVertex2f(x - size, y + size);
  glTexCoord2d(1, 1);
  glVertex2f(x + size, y + size);
  glTexCoord2d(1, 0);
  glVertex2f(x + size, y - size);
  glTexCoord2d(0, 0);
  glVertex2f(x - size, y - size);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}


static void	draw_objects(s_game	*game)
{
  s_ship	*target = NULL;
  s_bullet	*bullet = NULL;

  target = game->friends;
  while (target != NULL)
  {
    draw_friendly_ships(game, target);
    target = target->next;
  }
  target = game->hostiles;
  while (target != NULL)
  {
    draw_opponent_ships(game, target);
    target = target->next;
  }
  bullet = game->bullets;
  while (bullet != NULL)
  {
    draw_bullet(game, bullet);
    bullet = bullet->next;
  }
  return;
}

void    draw_all(s_game	*game)
{
  glColor3f(1, 1, 1);
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  draw_map(game);
  draw_objects(game);
  draw_hud(game);
  SDL_GL_SwapBuffers();
  return;
}
