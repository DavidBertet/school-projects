#include "func.h"



static void		build_cyclone1(s_bullet	*b)
{
  b->angle += 1;
  b->vector.posx = cos(b->angle / 360 * 6.28);
  b->vector.posy = sin(b->angle / 360 * 6.28);
  b->speed += 0.01;

  b->posx += b->vector.posx * b->speed;
  b->posy += b->vector.posy * b->speed;
}

static void		build_cyclone2(s_bullet	*b)
{
  b->angle += 3;
  b->vector.posx = cos(b->angle / 360 * 6.28);
  b->vector.posx = sin(b->angle / 360 * 6.28);
  b->vector.posy -= 0.01;

  b->posx += b->vector.posx * b->speed;
  b->posy += b->vector.posy * b->speed;
}

void		move_bullets(s_game	*game)
{
  s_bullet	*b;

  b = game->bullets;
  while (b != NULL)
  {
    if (b->type == BULLET_CYCLONE1)
      build_cyclone1(b);
    else if (b->type == BULLET_CYCLONE2)
      build_cyclone2(b);
    else
    {
      b->posx += b->vector.posx * b->speed;
      b->posy += b->vector.posy * b->speed;
    }
    b = b->next;
  }
}

void		move_ship(s_game	*game)
{
  s_ship	*e = NULL;

  e = game->hostiles;
  while (e != NULL)
  {
    e->posx += e->vector.posx * e->speed;
    e->posy += e->vector.posy * e->speed;
    e = e->next;
  }
}


static void	change_boss_weapon(s_ship	*e)
{
  if ((e->type == BOSS_1)
      || (e->type == BOSS_2))
  {
    if ((e->posy < 95) && (e->posy >= 75))
      e->mainweapon = WEAPON_CYCLONE1;
    if ((e->posy < 75) && (e->posy >= 55))
      e->mainweapon = WEAPON_LASER2;
    if ((e->posy < 55) && (e->posy >= 0))
      e->mainweapon = WEAPON_CYCLONE3;
  }
}

static void	launched_bullet_mode(s_game	*game,
				     s_ship	*e)
{
  int		radius;
  s_pos_bul	*bul;

  radius = all_ships[e->type].radius;
  if (e->mainweapon == WEAPON_CYCLONE1 || e->mainweapon == WEAPON_CYCLONE2 ||
      e->mainweapon == WEAPON_CYCLONE3)
    cyclone(game, e);
  else if (e->mainweapon == WEAPON_TRIPLELINE)
    triple_line(game, e, -3 - radius);
  else if (e->mainweapon == WEAPON_TRIPLEANGLE)
    triple_angle(game, e, -3 - radius);
  else
  {
    bul = build_pos_bul(e->posx, e->posy - 3 - radius, 0, -1);
    add_bullet(game, all_weapons[e->mainweapon].bullet, bul);
    free(bul);
  }
}

static void	launched_bullets(s_game	*game,
				 s_ship	*e)
{
  int		max_shot;

  if (e->posy < 99)
  {
    max_shot = all_weapons[e->mainweapon].nb_bul;
    if ((e->lastshot + all_weapons[e->mainweapon].latency < game->count)
	&& (e->nb_send_shot < max_shot))
    {
      launched_bullet_mode(game, e);
      e->lastshot = game->count;
      e->nb_send_shot++;
      if (e->nb_send_shot >= max_shot)
	e->burst = game->count + all_weapons[e->mainweapon].burst;
    }

    if ((e->burst != 0) && (e->burst < game->count))
    {
      e->nb_send_shot = 0;
      e->burst = 0;
    }
  }
}

void		shooter_ship(s_game	*game)
{
  s_ship	*e;

  e = game->hostiles;
  while (e != NULL)
  {
    change_boss_weapon(e);
    if ((e->type != ASTE_1) && (e->type != ASTE_2) && (e->type != ASTE_3))
      launched_bullets(game, e);
    e = e->next;
  }
}




void	boss_up_n_down(s_ship	*e)
{
  float	r;

  if (e->posy < 30)
  {
    r = (random() / 1000 % 21);
    r = ((r - 10) / 15);
    e->vector.posx = r;
    r = (random() / 1000 % 10);
    r = (r / 15);
    e->vector.posy = r;
  }
  if (e->posy > 90)
  {
    r = (random() / 1000 % 21);
    r = ((r - 10) / 15);
    e->vector.posx = r;
    r = (random() / 1000 % 10);
    r = ((r - 10) / 15);
    e->vector.posy = r;
  }
}

void	boss_left_n_right(s_ship	*e)
{
  float	r;

  if (e->posx < 10)
  {
    r = (random() / 1000 % 10);
    r = (r / 15);
    e->vector.posx = r;
  }

  if (e->posx > 90)
  {
    r = (random() / 1000 % 10);
    r = ((r - 10) / 15);
    e->vector.posx = r;
  }
}

void	ship_direction(s_ship	*e)
{
  float	r;

  if ((e->posy < 99) && (e->posy > 98))
  {
    r = (random() / 1000 % 21);
    r = ((r - 10) / 10);
    e->vector.posx = r;
    r = (random() / 1000 % 10);
    r = ((r - 10) / 10);
    e->vector.posy = r;
  }

  if (e->posx < 1)
  {
    r = (random() / 1000 % 10);
    r = (r / 10);
    e->vector.posx = r;
  }

  if (e->posx > 99)
  {
    r = (random() / 1000 % 10);
    r = ((r - 10) / 10);
    e->vector.posx = r;
  }
}

void		ia_ship(s_game	*game)
{
  s_ship	*e;

  e = game->hostiles;
  while (e != NULL)
  {
    if ((e->posy < 110) && (e->posy > 105))
      e->speed = e->game_speed;
    if ((e->type == BOSS_1) || (e->type == BOSS_2))
    {
      boss_up_n_down(e);
      boss_left_n_right(e);
    }
    else
    {
      if ((e->type != ASTE_1) && (e->type != ASTE_2) && (e->type != ASTE_3)
	  && (e->type != BOSS_1) && (e->type != BOSS_2))
	ship_direction(e);
    }
    e = e->next;
  }
}

