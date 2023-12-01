#include "func.h"

static int      draw_menu(GLuint        id_text)
{
  glBindTexture(GL_TEXTURE_2D, id_text);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2d(0, 100);
  glTexCoord2d(1, 0); glVertex2d(100, 100);
  glTexCoord2d(1, 1); glVertex2d(100, 0);
  glTexCoord2d(0, 1); glVertex2d(0, 0);
  glEnd();
  return (0);
}

static int      load_text(char  *name)
{
  SDL_Surface   *pImage = NULL;
  GLuint        texture;

  pImage = IMG_Load(name);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pImage->w, pImage->h, 0,
               GL_RGB, GL_UNSIGNED_BYTE, pImage->pixels);
  return (texture);
}

static int	init_sdl(void)
{
  SDL_Surface	*screen = NULL;
  int           width = 800;
  int           height = 800;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
    exit(1);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
  if (!screen)
    exit(2);
  SDL_WM_SetCaption("RUSH JV 2042", NULL);
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(0, 100, 0, 100);
  SDL_ShowCursor(SDL_DISABLE);
  SDL_EnableKeyRepeat(1, 1);
  glShadeModel(GL_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  return (0);
}

static int	draw_target(GLuint	id_text,
			    double	x,
			    double	y)
{
  glBindTexture(GL_TEXTURE_2D, id_text);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex2d(x, y);
  glTexCoord2d(1, 0);
  glVertex2d(x + 4, y);
  glTexCoord2d(1, 1);
  glVertex2d(x + 4, y + 4);
  glTexCoord2d(0, 1);
  glVertex2d(x, y + 4);
  glEnd();
  return (0);
}

static int	check_events_menu(void)
{
  SDL_Event	event;
  int		val = 0;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_KEYDOWN :
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_UP :
	      val = 1;
	      break;
	    case SDLK_DOWN :
              val = 1;
              break;
	    case SDLK_RETURN :
	      val = 3;
	      break;
	    default :
	      val = 0;
	      break;
	    }
	  break;
	case SDL_QUIT :
	  SDL_Quit();
	  exit(0);
	  break;
	}
    }
  return (val);
}

static void	loop_menu(int		*pos,
			  int		*input,
			  GLuint	*text_menu,
			  GLuint	*text_target)
{
  draw_menu(*text_menu);
  if (*pos == 1)
    draw_target(*text_target, 20, 88.5);
  if (*pos == 2)
    draw_target(*text_target, 20, 81);
  SDL_GL_SwapBuffers();
  *input = 0;
  while (*input == 0)
  {
    *input = check_events_menu();
    SDL_Delay (100);
  }
  if (*input == 1)
  {
    if (*pos == 1)
      *pos = 2;
    else
      *pos = 1;
  }
  return;
}

static int	wait_menu(void)
{
  int		pos = 1;
  int		input = 0;
  GLuint        text_menu;
  GLuint        text_target;

  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  text_menu = load_text("pic/menu.jpg");
  draw_menu(text_menu);
  text_target = load_text("pic/arrow.jpg");
  while (input != 3)
    loop_menu(&pos, &input, &text_menu, &text_target);
  glDisable(GL_TEXTURE_2D);
  if (pos == 2)
  {
    SDL_Quit();
    exit(0);
  }
  return (0);
}

int		start_menu(s_game	*game)
{
  s_pos_ship	*pos_ship = NULL;

  init_sdl();
  game->font = init_font();
  srandom(23);
  load_textures(game);
  while (wait_menu() == 0)
  {
    game->level = 1;
    while (game->level && game->level <= NB_LEVEL)
    {
      create_game(game);
      load_map(game, level_tab[game->level].file);
      pos_ship = build_pos_ship(50, 30, 0, -1);
      add_ship_friend(game, MAIN_SHIP, pos_ship, WEAPON_MINIGUN1);
      free(pos_ship);
      main_loop(game);
    }
  }
  SDL_Quit();
  return (0);
}
