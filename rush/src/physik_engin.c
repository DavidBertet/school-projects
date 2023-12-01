#include "func.h"

s_pos		*build_pos(float	posx,
			   float	posy,
			   float	radius)
{
  s_pos		*position = NULL;

  position = malloc(sizeof (s_pos));
  position->posx = posx;
  position->posy = posy;
  position->radius = radius;

  return (position);
}

static int	test_choc(s_pos	*obj1,
			  s_pos	*obj2)
{
  float		dist;
  float		x;
  float		y;
  float		r1;
  float		r2;

  x = obj2->posx - obj1->posx;
  y = obj2->posy - obj1->posy;
  dist = sqrt(x * x + y * y);
  r1 = obj1->radius;
  r2 = obj2->radius;
  free(obj1);
  free(obj2);

  return (dist <= (r1 + r2));
}

static void		test_enn_vs_friends(s_game	*game)
{
  s_ship		*f = NULL;
  s_ship		*e = NULL;
  s_pos			*pos_e = NULL;
  s_pos			*pos_f = NULL;

  f = game->friends;
  e = game->hostiles;
  while (f != NULL)
  {
    e = game->hostiles;
    while (e != NULL)
    {
      pos_e = build_pos(e->posx, e->posy, all_ships[e->type].radius);
      pos_f = build_pos(f->posx, f->posy, all_ships[f->type].radius);
      if (test_choc(pos_e, pos_f))
      {
	remove_ship_hostile(game, e);
	remove_ship_friend(game, f);
	return;
      }
      e = e->next;
    }
    f = f->next;
  }
}

static s_ship	*less_pv_friend(s_game	*game,
				s_ship	*friend,
				int	type)
{
  s_ship	*tmp = NULL;

  friend->pv = friend->pv - all_bullets[type].damages;
  if (friend->pv <= 0)
  {
    tmp = friend->next;
    remove_ship_friend(game, friend);
    return (tmp);
  }
  return (friend);
}

static s_ship	*less_pv_hostile(s_game	*game,
				 s_ship	*hostile,
				 int	type)
{
  s_ship	*tmp = NULL;

  hostile->pv = hostile->pv - all_bullets[type].damages;
  if ((game->friends != NULL) && (game->friends->bisweapon == WEAPON_NONE))
    game->friends->bisweapon = all_ships[hostile->type].bonus;
  if (hostile->pv <= 0)
  {
    game->score += all_ships[hostile->type].bonus_score;
    tmp = hostile->next;
    remove_ship_hostile(game, hostile);
    return (tmp);
  }
  return (hostile);
}

static void	tst_bul_ship_pos(s_ship		*f,
				 s_bullet	*b,
				 s_pos		**pos_b,
				 s_pos		**pos_f)
{
  *pos_b = build_pos(b->posx, b->posy, all_bullets[b->type].radius);
  *pos_f = build_pos(f->posx, f->posy, all_ships[f->type].radius);

}

static void		test_bullets_vs_friends(s_game		*game)
{
  s_ship		*f = NULL;
  s_bullet		*b = NULL;
  s_bullet		*b_tmp = NULL;
  s_pos			*pos_b = NULL;
  s_pos			*pos_f = NULL;

  f = game->friends;
  b = game->bullets;
  while (f != NULL && ((b = game->bullets) || 1))
  {
    while (b != NULL)
    {
      tst_bul_ship_pos(f, b, &pos_b, &pos_f);
      if (test_choc(pos_b, pos_f))
      {
	if ((f = less_pv_friend(game, f, b->type)) == NULL)
	  return;
	b_tmp = b;
	b = b->next;
	remove_bullet(game, b_tmp);
	continue;
      }
      b = b->next;
    }
    f = f->next;
  }
}

static void		test_bullets_vs_enn(s_game	*game)
{
  s_ship		*e = NULL;
  s_bullet		*b = NULL;
  s_bullet		*b_tmp = NULL;
  s_pos			*pos_b = NULL;
  s_pos			*pos_e = NULL;

  e = game->hostiles;
  b = game->bullets;
  while (e != NULL && ((b = game->bullets) || 1))
  {
    while (b != NULL)
    {
      tst_bul_ship_pos(e, b, &pos_b, &pos_e);
      if (test_choc(pos_b, pos_e))
      {
	if ((e = less_pv_hostile(game, e, b->type)) == NULL)
	  return;
	b_tmp = b;
	b = b->next;
	remove_bullet(game, b_tmp);
	continue;
      }
      b = b->next;
    }
    e = e->next;
  }
}

static void		test_all_vs_border(s_game	*game)
{
  s_bullet		*b = NULL;
  s_bullet		*b_tmp = NULL;
  s_ship		*e = NULL;
  s_ship		*e_tmp = NULL;

  b = game->bullets;
  while (b != NULL)
  {
    if (((b->posy > 110) || (b->posy < -10)) && ((b_tmp = b) || 1))
    {
      b = b->next;
      remove_bullet(game, b_tmp);
      continue;
    }
    b = b->next;
  }
  e = game->hostiles;
  while (e != NULL)
  {
    if ((e->posy < -10) && ((e_tmp = e) || 1) && ((e = e->next) || 1))
    {
      remove_ship_hostile(game, e_tmp);
      continue;
    }
    e = e->next;
  }
}

void		test_game(s_game	*game)
{
  test_enn_vs_friends(game);
  test_bullets_vs_friends(game);
  test_bullets_vs_enn(game);
  test_all_vs_border(game);
}
