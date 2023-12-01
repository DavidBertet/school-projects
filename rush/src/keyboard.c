#include "func.h"

static void     main_ship_left(s_game   *game,
                               s_ship   *ship)
{
  ship->posx -= ship->speed;
  if (ship->posx < BORDER)
    ship->posx = BORDER;
  if (ship->animdelay + all_ships[ship->type].quick < game->count)
    {
      if (ship->animation > 0)
        (ship->animation)--;
      ship->animdelay = game->count;
    }
  return;
}

static void     main_ship_right(s_game  *game,
                                s_ship   *ship)
{
  ship->posx += ship->speed;
  if (ship->posx > 100 - BORDER)
    ship->posx = 100 - BORDER;
  if (ship->animdelay + all_ships[ship->type].quick < game->count)
    {
      if (ship->animation < 4)
        (ship->animation)++;
      ship->animdelay = game->count;
    }
  return;
}

static void     main_ship_up(s_ship   *ship)
{
  ship->posy += ship->speed;
  if (ship->posy > 100 - BORDER)
    ship->posy = 100 - BORDER;
  return;
}

static void     main_ship_down(s_ship   *ship)
{
  ship->posy -= ship->speed;
  if (ship->posy < BORDER)
    ship->posy = BORDER;
  return;
}

static void     main_ship_stand(s_game  *game,
                                s_ship   *ship)
{
  if (ship->animdelay + all_ships[ship->type].quick < game->count)
    {
      if (ship->animation > 2)
        (ship->animation)--;
      if (ship->animation < 2)
        (ship->animation)++;
      ship->animdelay = game->count;
    }
  return;
}

static void	check_friend(s_game	*g,
			     Uint8	*keyState)
{
  if (keyState[SDLK_LEFT])
    main_ship_left(g, g->friends);
  if (keyState[SDLK_RIGHT])
    main_ship_right(g, g->friends);
  if ((!keyState[SDLK_RIGHT]) && (!keyState[SDLK_LEFT]))
    main_ship_stand(g, g->friends);
  if (keyState[SDLK_DOWN])
    main_ship_down(g->friends);
  if (keyState[SDLK_UP])
    main_ship_up(g->friends);
  if (keyState[SDLK_LCTRL])
    main_ship_fire(g, g->friends);
  if (keyState[SDLK_LALT])
    main_alt_fire(g, g->friends);
  return;
}

static int	check_fx(Uint8	*keyState)
{
  if (keyState[SDLK_F12])
    return (257);
  if (keyState[SDLK_F8])
    return (261);
  if (keyState[SDLK_F7])
    return (262);
  if (keyState[SDLK_F6])
    return (263);
  if (keyState[SDLK_F5])
    return (264);
  if (keyState[SDLK_F4])
    return (265);
  if (keyState[SDLK_F3])
    return (266);
  if (keyState[SDLK_F2])
    return (267);
  if (keyState[SDLK_F1])
    return (268);
  else
    return (0);
}

int		keyboard(s_game *g)
{
  Uint8         *keyState;

  SDL_PumpEvents();
  keyState = SDL_GetKeyState(NULL);
  if (keyState[SDLK_ESCAPE])
    return (255);
  if (keyState[SDLK_RETURN])
    return (256);
  if (keyState[SDLK_F12])
    return (257);
  if (keyState[SDLK_F11])
    return (258);
  if (keyState[SDLK_F10])
    return (259);
  if (keyState[SDLK_F9])
    return (260);
  if (g->friends != NULL)
    check_friend(g, keyState);
  return (check_fx(keyState));
}
