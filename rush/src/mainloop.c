#include "func.h"

void		minigun(s_game	*game,
			s_ship	*ship)
{
  s_pos_bul     *bul;
  float		tr = 0;
  int		x = 0;

  for (; x < 3; x++)
    {
      tr = ((random() / 1000) % 100);
      tr = ((tr - 50) / 300);
      bul = build_pos_bul(ship->posx, ship->posy + 4, tr, 1);
      add_bullet(game, all_weapons[ship->mainweapon].bullet, bul);
      free(bul);
    }
  return;
}

void		main_alt_fire(s_game   *game,
			      s_ship   *ship)
{
  if (ship->lastshot + all_weapons[ship->mainweapon].latency < game->count)
    {
      if (ship->bisweapon == WEAPON_TURBO)
	ship->speed += 0.5;
      if (ship->bisweapon == WEAPON_HEAL)
        ship->pv = all_ships[ship->type].basepv;
      if (ship->bisweapon == WEAPON_BURST)
        ship->fast_shot *= 0.8;
      if (ship->bisweapon == WEAPON_NEW)
	{
	  ship->mainweapon++;
	  ship->lastshot = 0;
	  ship->burst = 0;
	  ship->nb_send_shot = 0;
	  if (ship->mainweapon > 10)
	    ship->mainweapon = 0;
	}
      ship->bisweapon = WEAPON_NONE;
      ship->lastshot = game->count;
    }
  return;
}

static void	ship_fire_bis(s_game	*g,
			      s_ship	*s)
{
  int           radius;
  s_pos_bul     *bul;

  radius = all_ships[s->type].radius;
  if (s->mainweapon == WEAPON_CYCLONE1 || s->mainweapon == WEAPON_CYCLONE2 ||
      s->mainweapon == WEAPON_CYCLONE3)
    cyclone(g, s);
  else if (s->mainweapon == WEAPON_TRIPLELINE)
    triple_line(g, s, 4);
  else if (s->mainweapon == WEAPON_TRIPLEANGLE)
    triple_angle(g, s, 4);
  else if (s->mainweapon == WEAPON_MINIGUN1 || s->mainweapon == WEAPON_MINIGUN2
	   || s->mainweapon == WEAPON_MINIGUN3)
    minigun(g, s);
  else
    {
      bul = build_pos_bul(s->posx, s->posy + 3 + radius, 0, 1);
      add_bullet(g, all_weapons[s->mainweapon].bullet, bul);
      free(bul);
    }
  return;
}

void		main_ship_fire(s_game	*g,
			       s_ship   *s)
{
  int		max_shot;
  int		i;

  i = g->count;
  max_shot = all_weapons[s->mainweapon].nb_bul;
  if ((s->lastshot + all_weapons[s->mainweapon].latency * s->fast_shot < i)
      && (s->nb_send_shot < max_shot))
    {
      ship_fire_bis(g, s);
      s->nb_send_shot++;
      if (s->nb_send_shot >= max_shot)
	s->burst = g->count + all_weapons[s->mainweapon].burst;
      s->lastshot = g->count;
    }
  if ((s->burst != 0) && (s->burst < g->count))
    {
      s->nb_send_shot = 0;
      s->burst = 0;
    }
  return;
}

static void	give_pv(s_game	*game)
{
  s_ship        *friends;

  friends = game->friends;
  while (friends)
    {
      friends->pv = all_ships[friends->type].basepv;
      friends = friends->next;
    }
  return;
}

static void	clear_gun(s_ship	*ship)
{
  ship->lastshot = 0;
  ship->burst = 0;
  ship->nb_send_shot = 0;
}

static int	change_gun(s_game	*game)
{
  int		ok = 0;

  if (keyboard(game) == 261 && game->friends &&
      (game->friends->mainweapon = WEAPON_LASER1) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 262 && game->friends &&
	   (game->friends->mainweapon = WEAPON_LASER2) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 263 && game->friends &&
	   (game->friends->mainweapon = WEAPON_MINIGUN1) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 264 && game->friends &&
	   (game->friends->mainweapon = WEAPON_MINIGUN3) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 265 && game->friends &&
	   (game->friends->mainweapon = WEAPON_TRIPLELINE) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 266 && game->friends &&
	   (game->friends->mainweapon = WEAPON_TRIPLEANGLE) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 267 && game->friends &&
	   (game->friends->mainweapon = WEAPON_CYCLONE1) && (ok = 1))
    clear_gun(game->friends);
  else if (keyboard(game) == 268 && game->friends &&
	   (game->friends->mainweapon = WEAPON_CYCLONE2) && (ok = 1))
    clear_gun(game->friends);

  return (ok);
}

static int	test_end(s_game	*game)
{
  if (keyboard(game) == 257)
    {
      while (1)
	{
	  if (change_gun(game))
	    break;
	  if (keyboard(game) == 259)
	    return (game->level + 1);
	  if (keyboard(game) == 260)
	    {
	      give_pv(game);
	      break;
	    }
	  if (keyboard(game) == 258)
	    break;
	}
    }
  if ((game->hostiles == NULL && game->friends == NULL) ||
      (game->friends == NULL && keyboard(game) == 256))
    return (game->level);
  else if ((game->hostiles == NULL && game->friends != NULL))
    return (game->level + 1);
  else
    return (0);
}

void		main_loop(s_game	*game)
{
  int		level_tmp;

  while (keyboard(game) != 255)
    {
      game->count = SDL_GetTicks();
      test_game(game);
      move_bullets(game);
      move_ship(game);
      shooter_ship(game);
      ia_ship(game);
      draw_all(game);
      if ((level_tmp = test_end(game)) && (game->level = level_tmp))
	return;
      SDL_Delay (1);
    }
  game->level = 0;
  return;
}
