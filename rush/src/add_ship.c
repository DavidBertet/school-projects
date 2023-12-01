#include "func.h"

static s_ship	*create_ship(int	type,
			     s_pos_ship	*pos_ship,
			     int	weapon)
{
  s_ship	*ship;

  ship = malloc(sizeof (s_ship));

  ship->type = type;
  ship->pv = all_ships[type].basepv;
  ship->speed = all_ships[type].basespeed;
  ship->speed = 0.5;
  ship->game_speed = all_ships[type].basespeed;
  ship->posx = pos_ship->posx;
  ship->posy = pos_ship->posy;
  ship->vector.posx = pos_ship->v.posx * ship->speed;
  ship->vector.posy = pos_ship->v.posy * ship->speed;
  ship->action = 0;
  ship->isactive = 0;
  ship->lastshot = 0;
  ship->burst = 0;
  ship->nb_send_shot = 0;
  ship->next = NULL;
  ship->animation = all_ships[type].picture;
  ship->animdelay = 0;
  ship->mainweapon = weapon;
  ship->bisweapon = WEAPON_NONE;
  ship->fast_shot = 1;
  return (ship);
}

void		add_ship_friend(s_game		*game,
				int		type,
				s_pos_ship	*pos_ship,
				int		weapon)
{
  s_ship	*ship;

  ship = create_ship(type, pos_ship, weapon);
  ship->next = game->friends;
  game->friends = ship;

  return;
}

void		add_ship_hostile(s_game		*game,
				 int		type,
				 s_pos_ship	*pos_ship,
				 int		weapon)
{
  s_ship	*ship;

  ship = create_ship(type, pos_ship, weapon);
  ship->next = game->hostiles;
  game->hostiles = ship;

  return;
}
