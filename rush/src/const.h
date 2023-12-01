#ifndef CONST_H_
# define CONST_H_

# include "struct.h"

/*
** Header : const.h
** Here are the constants made for the game.
*/

# define NB_LEVEL		4

# define BORDER			3

# define TYPE_IDIOT		100
# define TYPE_GENIUS		101

# define ACTION_STAND		200
# define ACTION_MOVE_FORWARD	201

# define WEAPON_LASER1		0
# define WEAPON_LASER2		1
# define WEAPON_MINIGUN1	2
# define WEAPON_MINIGUN2	3
# define WEAPON_MINIGUN3	4
# define WEAPON_MISSILE1	5
# define WEAPON_CYCLONE1	6
# define WEAPON_CYCLONE2	7
# define WEAPON_CYCLONE3	8
# define WEAPON_TRIPLELINE	9
# define WEAPON_TRIPLEANGLE	10

# define WEAPON_NONE		11
# define WEAPON_TURBO		12
# define WEAPON_HEAL		13
# define WEAPON_BURST		14
# define WEAPON_NEW		15

# define BULLET_LASER1		0
# define BULLET_LASER2		1
# define BULLET_GUN		2
# define BULLET_MISSILE1	3
# define BULLET_CYCLONE1	4
# define BULLET_CYCLONE2	5
# define BULLET_CYCLONE3	6
# define BULLET_TRIPLELINE	7
# define BULLET_TRIPLEANGLE	8

# define MOVE_AHEAD_CST	0
# define MOVE_AHEAD_ACC	1
# define MOVE_CYCLONE	2

# define STANDARD_SHIP	0
# define MAIN_SHIP	1
# define SHIP_2		2
# define ASTE_1		3
# define ASTE_2		4
# define ASTE_3		5
# define SHIP_3		6
# define SHIP_4		7
# define SHIP_5		8
# define SHIP_6		9
# define SHIP_7		10
# define SHIP_8		11
# define SHIP_9		12
# define BOSS_1		13
# define BOSS_2		14

# define TEXT_MAINSHIP1	2
# define TEXT_SUN	5
# define TEXT_PLANET	6
# define TEXT_LASER1	7
# define TEXT_LASER2	8
# define ICO_LASER1	9
# define ICO_LASER2     10
# define ICO_GUN1	11
# define ICO_GUN2	12
# define ICO_GUN3	13
# define ICO_MISSILE1   14
# define TEXT_GUN	15
# define TEXT_MISSILE1	16
# define TEXT_CYCLONE1	17
# define ICO_CYCLONE1	18
# define TEXT_SHIP1	19
# define TEXT_ASTE_1	20
# define TEXT_ASTE_2	21
# define TEXT_ASTE_3	22
# define TEXT_BOSS_1	23
# define TEXT_BOSS_2	24
# define TEXT_MAINSHIP2	27
# define TEXT_SHIP2	30
# define TEXT_SHIP3     31
# define TEXT_SHIP4     32
# define TEXT_SHIP5     33
# define TEXT_SHIP6     34
# define TEXT_SHIP7     35
# define TEXT_SHIP8     36
# define TEXT_SHIP9     37
# define TEXT_HUD	38
# define TEXT_GAMEOVER  39
# define ICO_FAST_SHOT	40
# define ICO_HEAL	41
# define ICO_NONE	42
# define ICO_TRI	43
# define ICO_TURBO	44
# define ICO_NEW	45

/*
**  struct cst_bullet:
**  int			damages;
**  int			picture;
**  int			radius;
**  int			basespeed;
**  int			movement;
*/
static const s_cst_bullet	all_bullets[] =
  {
    {5, TEXT_LASER1, 0.7, 1.2, MOVE_AHEAD_CST},
    {10, TEXT_LASER2, 0.7, 0.8, MOVE_AHEAD_CST},
    {2, TEXT_GUN, 0.7, 1.4, MOVE_AHEAD_CST},
    {75, TEXT_MISSILE1, 1.5, 0.9, MOVE_AHEAD_CST},
    {4, TEXT_CYCLONE1, 0.7, 1, MOVE_AHEAD_CST},
    {4, TEXT_CYCLONE1, 0.7, 1, MOVE_AHEAD_CST},
    {4, TEXT_CYCLONE1, 0.7, 1, MOVE_AHEAD_CST},
    {5, TEXT_CYCLONE1, 0.7, 1, MOVE_AHEAD_CST},
    {5, TEXT_CYCLONE1, 0.7, 1, MOVE_AHEAD_CST}
  };

/*
**  struct s_cst_weapon:
**  char		*name;
**  int			latency;
**  int			burst;
**  int			nb_bul;
**  int			bullet;
**  int			icone;
*/
static const s_cst_weapon	all_weapons[] =
  {
    {"LASER1", 80, 1, 1, BULLET_LASER1, ICO_LASER1},
    {"LASER2", 80, 1000, 3, BULLET_LASER2, ICO_LASER2},
    {"MINIGUN1", 75, 400, 30, BULLET_GUN, ICO_GUN1},
    {"MINIGUN2", 50, 600, 35, BULLET_GUN, ICO_GUN2},
    {"MINIGUN3", 25, 1000, 40, BULLET_GUN, ICO_GUN3},
    {"MISSILE1", 400, 1, 1, BULLET_MISSILE1, ICO_MISSILE1},
    {"CYCLONE1", 200, 1, 1, BULLET_CYCLONE1, ICO_CYCLONE1},
    {"CYCLONE2", 200, 1, 1, BULLET_CYCLONE2, ICO_CYCLONE1},
    {"CYCLONE3", 200, 1, 1, BULLET_CYCLONE3, ICO_CYCLONE1},
    {"3xLINE", 300, 4, 1, BULLET_TRIPLELINE, ICO_TRI},
    {"3xANGLE", 200, 4, 1, BULLET_TRIPLEANGLE, ICO_TRI},
    {"NOTHING", 1, 1, 1, BULLET_GUN, ICO_NONE},
    {"TURBO", 100, 1, 1, BULLET_GUN, ICO_TURBO},
    {"REPARE", 100, 1, 1, BULLET_GUN, ICO_HEAL},
    {"FAST SHOT", 100, 1, 1, BULLET_GUN, ICO_FAST_SHOT},
    {"NEW WEAP.", 100, 1, 1, BULLET_GUN, ICO_NEW}
  };

/*
**  struct cst_ship:
**  int			picture;
**  int			basepv;
**  int			basespeed;
**  int			radius;
**  int			quick;
**  int			score;
**  int			bonus;
*/
static const s_cst_ship		all_ships[] =
{
  {TEXT_SHIP1, 20, 0.6, 3, 0, 15, WEAPON_NONE},
  {TEXT_MAINSHIP1, 100, 1.2, 3, 100, 100, WEAPON_NONE},
  {TEXT_SHIP2, 50, 0.7, 7, 0, 25, WEAPON_NONE},
  {TEXT_ASTE_1, 50, 0.4, 3, 0, 1, WEAPON_NONE},
  {TEXT_ASTE_2, 200, 0.4, 6, 0, 1, WEAPON_NONE},
  {TEXT_ASTE_3, 500, 0.4, 9, 0, 1, WEAPON_NONE},
  {TEXT_SHIP3, 50, 0.7, 2, 0, 15, WEAPON_NONE},
  {TEXT_SHIP4, 20, 1.2, 3, 0, 50, WEAPON_TURBO},
  {TEXT_SHIP5, 50, 0.7, 3, 0, 15, WEAPON_NONE},
  {TEXT_SHIP6, 50, 0.7, 3, 0, 15, WEAPON_NONE},
  {TEXT_SHIP7, 50, 0.7, 3, 0, 15, WEAPON_NONE},
  {TEXT_SHIP8, 300, 0.5, 7, 0, 500, WEAPON_BURST},
  {TEXT_SHIP9, 50, 0.7, 3, 0, 10, WEAPON_HEAL},
  {TEXT_BOSS_1, 2000, 0.5, 15, 0, 10000, WEAPON_NEW},
  {TEXT_BOSS_2, 2000, 0.5, 15, 0, 10000, WEAPON_NEW}
};

static const s_level	level_tab[] =
  {
    {NULL, NULL},
    {"Level 1 : First Blood ! (Piece of cake)", "./map/level1.map"},
    {"Level 2 : Beginner ?", "./map/level2.map"},
    {"Level 3 : Damn I'm good.", "./map/level3.map"},
    {"Level 4 : This is the/your end.", "./map/level4.map"},
  };

/*
** End of the header const.h
*/

#endif /* !CONST_H_ */
