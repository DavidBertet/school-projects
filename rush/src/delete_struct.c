#include "func.h"

static void	free_ship(s_ship	*ship)
{
  free(ship);

  return;
}

static void	free_bullet(s_bullet	*bullet)
{
  free(bullet);

  return;
}

void		remove_ship_friend(s_game	*game,
				   s_ship	*current)
{
  s_ship	*ship = NULL;
  s_ship	*ship_prec = NULL;

  if (current == game->friends)
    game->friends = current->next;
  else
  {
    ship_prec = game->friends;
    ship = game->friends;
    while (ship)
    {
      if (ship == current)
      {
	ship_prec->next = ship->next;
	break;
      }
      ship_prec = ship;
      ship = ship->next;
    }
  }
  free_ship(current);

  return;
}

void		remove_ship_hostile(s_game	*game,
				    s_ship	*current)
{
  s_ship	*ship = NULL;
  s_ship	*ship_prec = NULL;

  if (current == game->hostiles)
    game->hostiles = current->next;
  else
  {
    ship_prec = game->hostiles;
    ship = game->hostiles;
    while (ship)
    {
      if (ship == current)
      {
	ship_prec->next = ship->next;
	break;
      }
      ship_prec = ship;
      ship = ship->next;
    }
  }
  free_ship(current);

  return;
}

void		remove_bullet(s_game	*game,
			      s_bullet	*current)
{
  s_bullet	*bullet = NULL;
  s_bullet	*bullet_prec = NULL;

  if (current == game->bullets)
    game->bullets = current->next;
  else
  {
    bullet_prec = game->bullets;
    bullet = game->bullets;
    while (bullet)
    {
      if (bullet == current)
	bullet_prec->next = bullet->next;
      bullet_prec = bullet;
      bullet = bullet->next;
    }
  }
  free_bullet(current);

  return;
}
