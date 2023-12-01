#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "draw.h"
#include "mainloop.h"

int		keyboard()
{
  Uint8			*keyState;

  SDL_PumpEvents();
  keyState = SDL_GetKeyState(NULL);
  if (keyState[SDLK_ESCAPE])
    return (255);
/*   if (keyState[SDLK_RETURN]) */
/*     return (256); */
/*   if (keyState[SDLK_LEFT]) */
/*     env_global->info3d.posx += SPEED; */
/*   if (keyState[SDLK_RIGHT]) */
/*     env_global->info3d.posx -= SPEED; */
/*   if (keyState[SDLK_UP]) */
/*     env_global->info3d.posz += SPEED; */
/*   if (keyState[SDLK_DOWN]) */
/*     env_global->info3d.posz -= SPEED; */
  return (0);
}

void		main_loop(s_texture_image *tab)
{
  while (keyboard() != 255)
    {
      /* IMPORTANT ! */
      draw_all(tab);

      SDL_Delay (1);
    }

  return;
}
