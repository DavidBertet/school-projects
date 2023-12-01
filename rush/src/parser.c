#include "func.h"

int		load_map(s_game		*game,
			 const char	*map)
{
  FILE		*fd = NULL;
  int		type;
  int		weapon;
  s_pos_ship	*pos_ship = NULL;

  if ((fd = fopen(map, "r")) == NULL)
  {
    perror("open");
    return (1);
  }

  while (!feof(fd))
    {
      pos_ship = build_pos_ship(0, 0, 0, -1);
      fscanf(fd, "%i:%f:%f:%i\n", &type, &pos_ship->posx,
	     &pos_ship->posy, &weapon);
      add_ship_hostile(game, type, pos_ship, weapon);
      free(pos_ship);
    }

  if (fclose(fd) == -1)
  {
    perror("close");
    return (1);
  }

  return (0);
}
