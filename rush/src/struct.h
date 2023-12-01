#ifndef STRUCT_H_
# define STRUCT_H_

# include "inc.h"

/*
** Header : struct.h
** Here are the structures made for the game.
*/
typedef struct		cst_bullet
{
  int			damages;
  int			picture;
  float			radius;
  float			basespeed;
  int			movement;
}			s_cst_bullet;

typedef struct		ss_pos
{
  float			posx;
  float			posy;
  int			radius;
}			s_pos;

typedef struct		vector
{
  float			posx;
  float			posy;
}			s_vector;

typedef struct		bul
{
  float			posx;
  float			posy;
  float			angle;
  s_vector		v;
}			s_pos_bul;

typedef struct		pos_ship
{
  float			posx;
  float			posy;
  s_vector		v;
}			s_pos_ship;

typedef struct		cst_weapon
{
  char			*name;
  int			latency;
  int			burst;
  int			nb_bul;
  int			bullet;
  int			icone;
}			s_cst_weapon;

typedef struct		cst_ship
{
  int			picture;
  int			basepv;
  float			basespeed;
  int			radius;
  int			quick;
  int			bonus_score;
  int			bonus;
}			s_cst_ship;

typedef struct		bullet
{
  int			type;
  float			posx;
  float			posy;
  float			angle;
  float			speed;
  s_vector		vector;
  struct bullet		*next;
}			s_bullet;

typedef struct		ship
{
  int			type;
  int			pv;
  float			speed;
  float			game_speed;
  float			posx;
  float			posy;
  s_vector		vector;
  int			action;
  int			isactive;
  int			mainweapon;
  int			bisweapon;
  int			lastshot;
  int			burst;
  int			nb_send_shot;
  int			animation;
  int			animdelay;
  float			fast_shot;
  struct ship		*next;
}			s_ship;

typedef struct  texture_image
{
  GLubyte       *imageData;
  GLuint        bpp;
  GLuint        width;
  GLuint        height;
  GLuint        texID;
}               s_texture_image;

typedef struct		game
{
  s_ship		*friends;
  s_ship		*hostiles;
  s_bullet		*bullets;
  int			level;
  int			score;
  int			oldscore;
  int			count;
  GLuint		font;
  s_texture_image	txt[50];
}			s_game;

typedef struct		level
{
  char			*name;
  char			*file;
}			s_level;

/*
** End of the header struct.h
*/

#endif /* !STRUCT_H_ */
