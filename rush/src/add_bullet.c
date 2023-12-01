#include "func.h"

static s_bullet	*create_bullet(int		type,
			       s_pos_bul	*bul)
{
  s_bullet	*bullet;

  bullet = malloc(sizeof (s_bullet));

  bullet->type = type;
  bullet->posx = bul->posx;
  bullet->posy = bul->posy;
  bullet->angle = bul->angle;
  bullet->speed = all_bullets[type].basespeed;
  bullet->vector.posx = bul->v.posx * bullet->speed;
  bullet->vector.posy = bul->v.posy * bullet->speed;
  bullet->next = NULL;

  return (bullet);
}

void		add_bullet(s_game	*game,
			   int		type,
			   s_pos_bul	*bul)
{
  s_bullet	*bullet;

  bullet = create_bullet(type, bul);
  bullet->next = game->bullets;
  game->bullets = bullet;

  return;
}
