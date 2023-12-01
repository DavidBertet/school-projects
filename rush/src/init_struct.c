#include "func.h"

s_pos_bul	*build_pos_bul(float	posx,
			       float	posy,
			       float	vx,
			       float	vy)
{
  s_pos_bul	*position = NULL;

  position = malloc(sizeof (s_pos_bul));
  position->posx = posx;
  position->posy = posy;
  position->angle = 0;
  position->v.posx = vx;
  position->v.posy = vy;

  return (position);
}

s_pos_ship	*build_pos_ship(float	posx,
				float	posy,
				float	vx,
				float	vy)
{
  s_pos_ship	*position = NULL;

  position = malloc(sizeof (s_pos_ship));
  position->posx = posx;
  position->posy = posy;
  position->v.posx = vx;
  position->v.posy = vy;

  return (position);
}

void	create_game(s_game	*game)
{
  game->friends = NULL;
  game->hostiles = NULL;
  game->bullets = NULL;
  game->score = 0;
  game->oldscore = -1;
  game->count = SDL_GetTicks();

  return;
}
