#include "func.h"

static void     print_int(s_game        *game,
                          int           data,
                          float         x,
                          float         y)
{
  char          buf[20];

  sprintf(buf, "%i", data);
  glColor3f(0.1, 0.8, 0.4);
  glRasterPos2f(x, y);
  print_my_string(buf, game->font);
  return;
}

static void     draw_mainweapon(s_game *game,
                                s_ship *ship)
{
  char          *name;
  int		text;

  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  text =  game->txt[all_weapons[ship->mainweapon].icone].texID;
  glBindTexture(GL_TEXTURE_2D, text);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(0, 11);
  glTexCoord2f(1, 1);
  glVertex2f(4, 11);
  glTexCoord2f(1, 0);
  glVertex2f(4, 7);
  glTexCoord2f(0, 0);
  glVertex2f(0, 7);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  name = all_weapons[ship->mainweapon].name;
  glColor3f(0, 0, 0);
  glRasterPos2f(4, 9);
  print_my_string(name, game->font);
  return;
}

static void     draw_bisweapon(s_game   *game,
			       s_ship   *ship)
{
  char          *name;
  int		text;

  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  text =  game->txt[all_weapons[ship->bisweapon].icone].texID;
  glBindTexture(GL_TEXTURE_2D, text);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(0, 7.5);
  glTexCoord2f(1, 1);
  glVertex2f(4, 7.5);
  glTexCoord2f(1, 0);
  glVertex2f(4, 3.5);
  glTexCoord2f(0, 0);
  glVertex2f(0, 3.5);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  name = all_weapons[ship->bisweapon].name;
  glColor3f(0, 0, 0);
  glRasterPos2f(4, 5.5);
  print_my_string(name, game->font);
  return;
}

static void	draw_hud_texture(s_game	*game)
{
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[TEXT_HUD].texID);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(0, 12);
  glTexCoord2f(1, 1);
  glVertex2f(18, 12);
  glTexCoord2f(1, 0);
  glVertex2f(18, 0);
  glTexCoord2f(0, 0);
  glVertex2f(0, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  return;
}

static void	draw_hud_alive(s_game	*game)
{
  float		pvs;

  draw_hud_texture(game);
  pvs = game->friends->pv * 15;
  pvs /= all_ships[game->friends->type].basepv;
  glColor3f(1, 0, 0);
  glBegin(GL_QUADS);
  glVertex2f(0.5, 1);
  glVertex2f(0.5, 3);
  glVertex2f(0.5 + pvs, 3);
  glVertex2f(0.5 + pvs, 1);
  glEnd();
  glColor3f(0, 0, 0);
  glRasterPos2f(2, 2);
  print_my_string("Structure", game->font);
  draw_mainweapon(game, game->friends);
  draw_bisweapon(game, game->friends);
  print_int(game, game->score, 1, 97.5);
  return;
}

static void     draw_hud_dead(s_game   *game)
{
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, game->txt[TEXT_GAMEOVER].texID);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex2f(35, 65);
  glTexCoord2f(1, 1);
  glVertex2f(65, 65);
  glTexCoord2f(1, 0);
  glVertex2f(65, 35);
  glTexCoord2f(0, 0);
  glVertex2f(35, 35);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  if (game->oldscore == -1)
    game->oldscore = game->score;
  print_int(game, game->oldscore, 1, 97.5);
  return;
}

void     draw_hud(s_game *game)
{
  if (game->friends != NULL)
    draw_hud_alive(game);
  else
    draw_hud_dead(game);
  glColor3f(0.1, 0.8, 0.4);
  glRasterPos2f(1, 99);
  print_my_string(level_tab[game->level].name, game->font);
  return;
}
