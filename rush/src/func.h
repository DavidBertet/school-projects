#ifndef FUNC_H_
# define FUNC_H_

# include "const.h"

/*
** Header : func.h
** Here are the extern functions made for the game.
*/

/*
** start_menu() : Starts the menu (YARLY).
*/
int		start_menu(s_game	*game);

GLuint		init_font(void);

void		print_my_string(char    *s,
				GLuint  offset);

int		init_sdl_opengl(void);

void		draw_all(s_game	*game);

void		main_loop(s_game	*game);

int		load_textures(s_game    *game);

void		move_bullets(s_game	*game);

void		move_ship(s_game	*game);

void		shooter_ship(s_game	*game);

void		ia_ship(s_game	*game);

void		test_game(s_game	*game);

s_pos_bul	*build_pos_bul(float	posx,
			       float	posy,
			       float	vx,
			       float	vy);

s_pos_ship	*build_pos_ship(float	posx,
				float	posy,
				float	vx,
				float	vy);
void		add_bullet(s_game	*game,
			   int		type,
			   s_pos_bul	*bul);

void		add_ship_hostile(s_game		*game,
				 int		type,
				 s_pos_ship	*pos_ship,
				 int		weapon);

void		add_ship_friend(s_game		*game,
				int		type,
				s_pos_ship	*pos_ship,
				int		weapon);

void		create_game(s_game	*game);

void		remove_ship_friend(s_game	*game,
				   s_ship	*current);

void		remove_ship_hostile(s_game	*game,
				    s_ship	*current);

void		remove_bullet(s_game	*game,
			      s_bullet	*current);

int		load_map(s_game		*game,
			 const char	*map);

void		cyclone(s_game	*game,
			s_ship	*ship);

void		triple_line(s_game	*game,
			    s_ship	*ship,
			    int		posy);

void		triple_angle(s_game	*game,
			     s_ship	*ship,
			     int	posy);

void		draw_hud(s_game	*game);
void		draw_map(s_game	*game);
int             keyboard(s_game *g);
void            minigun(s_game  *game,
                        s_ship  *ship);
void            main_alt_fire(s_game   *game,
                              s_ship   *ship);
void            main_ship_fire(s_game   *game,
                               s_ship   *ship);

/*
** End of the header func.h
*/

#endif /* !FUNC_H_ */
