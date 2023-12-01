#include "func.h"

void		cyclone(s_game	*game,
			s_ship	*ship)
{
  s_pos_bul	pos_bullet;
  float		degree = 1;
  float		x;
  float		y;

  while (degree < 360)
  {
    x = cos(degree / 360 * 6.28);
    y = sin(degree / 360 * 6.28);
    pos_bullet.posx = ship->posx + all_ships[ship->type].radius * x * 2;
    pos_bullet.posy = ship->posy + all_ships[ship->type].radius * y * 2;
    pos_bullet.v.posx = x;
    pos_bullet.v.posy = y;
    pos_bullet.angle = degree;

    add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);

    degree += 10;
  }
}

void		triple_line(s_game	*game,
			    s_ship	*ship,
			    int		posy)
{
  s_pos_bul	pos_bullet;

  pos_bullet.posy = ship->posy + posy;
  pos_bullet.v.posx = 0;
  pos_bullet.v.posy = 1;

  pos_bullet.posx = ship->posx + 5;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);

  pos_bullet.posx = ship->posx;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);

  pos_bullet.posx = ship->posx - 5;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);
}

void		triple_angle(s_game	*game,
			     s_ship	*ship,
			     int	posy)
{
  s_pos_bul	pos_bullet;
  float		x;
  float		y;

  pos_bullet.posy = ship->posy + posy;

  x = cos(3.14 / 2 - 0.3);
  y = sin(3.14 / 2 - 0.3);
  pos_bullet.v.posx = x;
  pos_bullet.v.posy = y;
  pos_bullet.posx = ship->posx + 5;
  pos_bullet.angle = 0;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);

  pos_bullet.v.posx = 0;
  pos_bullet.v.posy = 1;
  pos_bullet.posx = ship->posx;
  pos_bullet.angle = 0;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);

  x = cos(3.14 / 2 + 0.3);
  y = sin(3.14 / 2 + 0.3);
  pos_bullet.v.posx = x;
  pos_bullet.v.posy = y;
  pos_bullet.posx = ship->posx - 5;
  pos_bullet.angle = -1;

  add_bullet(game, all_weapons[ship->mainweapon].bullet, &pos_bullet);
}
