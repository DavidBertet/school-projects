#include <sstream>
#include <iostream>
#include "display/ascii.hh"
#include "random/random.hh"
#include "standardrules.hh"
#include "ants/foodworker.hh"
#include "ants/waterworker.hh"
#include "ants/queen.hh"
#include "ants/fighter.hh"
#include "ants/killableant.hh"
#include "map.hh"
#include "cells/ground.hh"
#include "cells/resources/foodresource.hh"
#include "cells/resources/waterresource.hh"
#include "game.hh"

StandardRules::StandardRules (Game& game)
  : Rules (game)
{
}

void print_verbose1 (std::stringstream& info)
{
  Map& map = Map::get_instance ();

  if (map.verbose_get () > 0)
    std::cout << info.str () << std::endl;
  info.str ("");
}

void print_verbose2 (std::stringstream& info)
{
  Map& map = Map::get_instance ();

  if (map.verbose_get () > 1)
    std::cout << info.str () << std::endl;
  info.str ("");
}

void print_verbose3 (std::stringstream& info)
{
  Map& map = Map::get_instance ();

  if (map.verbose_get () > 2)
    std::cout << info.str () << std::endl;
  info.str ("");
}

void
convert_rand (int rand, int* x, int* y)
{
  if (rand == 0)
    --(*y);
  else if (rand == 1)
  {
    ++(*x);
    --(*y);
  }
  if (rand == 2)
    ++(*x);
  else if (rand == 3)
  {
    ++(*x);
    ++(*y);
  }
  else if (rand == 4)
    ++(*y);
  else if (rand == 5)
  {
    --(*x);
    ++(*y);
  }
  else if (rand == 6)
    --(*x);
  else if (rand == 7)
  {
    --(*x);
    --(*y);
  }
}
int
find_score_fighter (int x, int y, int team)
{
  Ground* ground;
  int ret = 0;
  Map& map = Map::get_instance ();

  if (map.cell_get (x, y) &&
      (ground = dynamic_cast <Ground*>
       (map.cell_get (x, y)->content_get ())))
    if (ground->is_empty ())
    {
      for (int i = 1; i < 10; ++i)
      {
	if (i != team)
	  ret += ground->pheromone_get ("PB", i)->quantity_get ();
      }
      return ret;
    }

  return 0;
}

int
find_best_score_fighter (int x, int y, int team)
{
  int max_score = 0;
  int max_tmp_score = 0;
  int x_tmp;
  int y_tmp;

  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    max_tmp_score = find_score_fighter (x, y, team);
    max_score = max_score > max_tmp_score ? max_score : max_tmp_score;
  }

  return max_score;
}

int
find_score (std::string pheromone, int x, int y, int team)
{
  Ground* ground;
  Map& map = Map::get_instance ();

  if (map.cell_get (x, y) &&
      (ground = dynamic_cast <Ground*>
       (map.cell_get (x, y)->content_get ())))
    if (ground->is_empty ())
      return ground->pheromone_get (pheromone, team)->quantity_get () -
	find_score_fighter (x, y, team);

  return 0;
}

int
find_best_score (std::string pheromone, int x, int y, int team)
{
  int max_score = 0;
  int max_tmp_score = 0;
  int x_tmp;
  int y_tmp;

  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    max_tmp_score = find_score (pheromone, x, y, team);
    max_score = max_score > max_tmp_score ? max_score : max_tmp_score;
  }

  return max_score;
}

void
sub_pheromone (int quantity)
{
  Ground* ground;
  Map& map = Map::get_instance ();

  for (int y = 0; y < map.h_get (); ++y)
    for (int x = 0; x < map.w_get (); ++x)
    {
      if (map.cell_get (x, y) &&
	  (ground = dynamic_cast <Ground*>
	   (map.cell_get (x, y)->content_get ())))
      {
	for (int i = 1; i < 11; ++i)
	{
	  ground->pheromone_get ("PQ", i)->sub_quantity (quantity);
	  ground->pheromone_get ("PW", i)->sub_quantity (quantity);
	  ground->pheromone_get ("PF", i)->sub_quantity (quantity);
	  ground->pheromone_get ("PB", i)->sub_quantity (quantity);
	}
      }
    }
}

bool
check_food_before_lay (Queen* queen)
{
  std::stringstream ss;

  if (queen->nb_food_get () < 5)
  {
    ss << "      has " << queen->nb_food_get ()
       << " resources, cannot produce this turn";
    print_verbose2 (ss);
    return 1;
  }
  return 0;
}

void
lay (Queen* queen)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  int rand;
  Ground* ground;
  Map& map = Map::get_instance ();
  int i;
  std::stringstream ss;

  x = queen->x_get ();
  y = queen->y_get ();
  x_tmp = x;
  y_tmp = y;

  if (check_food_before_lay (queen))
    return;

  ss << "      has " << queen->nb_food_get ()
     << " resources, will try to produce an ant";
  print_verbose2 (ss);

  for (i = 0; i < 10; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    rand = my_rand () % 8;
    convert_rand (rand, &x, &y);

    ss << "        attempt " << i << ", r = " << rand;
    print_verbose3 (ss);

    if (map.cell_get (x, y) && (ground = dynamic_cast <Ground*>
				(map.cell_get (x, y)->content_get ())))
      if (ground->is_empty ())
      {
	ss << "        selected r = " << rand << ", creates an ant at "
	   << x + 1 << ", " << y + 1;
	print_verbose2 (ss);
	Ant* ant = queen->lay (x, y, queen->team_get () - 1, ss);
	print_verbose3 (ss);
	ground->add_ant (ant);
	queen->team_vector_get ()->add_ant (ant);
	sub_pheromone (1);
	queen->sub_food (5);
	break;
      }
  }

  if (i == 10)
  {
    ss << "        production failed, does nothing this turn";
    print_verbose3 (ss);
  }
}

void
put_pheromone (Ant* ant, std::string pheromone, int quantity)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Ground* ground;
  Map& map = Map::get_instance ();

  x = ant->x_get ();
  y = ant->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	(ground = dynamic_cast <Ground*>
	 (map.cell_get (x, y)->content_get ())))
      ground->pheromone_get (pheromone,
			     ant->team_get ())->add_quantity (quantity);
  }
}

int
find_food (FoodWorker* foodworker)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Map& map = Map::get_instance ();
  std::stringstream ss;

  x = foodworker->x_get ();
  y = foodworker->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	dynamic_cast <FoodResource*> (map.cell_get (x, y)->content_get ()))
    {
      foodworker->charged ();
      put_pheromone (foodworker, "PF", 5);
      ss << "      gather some resources";
      print_verbose3 (ss);
      return 1;
    }
  }

  return 0;
}

int
find_water (WaterWorker* waterworker)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Map& map = Map::get_instance ();
  std::stringstream ss;

  x = waterworker->x_get ();
  y = waterworker->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	dynamic_cast <WaterResource*> (map.cell_get (x, y)->content_get ()))
    {
      waterworker->charged ();
      put_pheromone (waterworker, "PW", 5);
      ss << "      gather some resources";
      print_verbose3 (ss);
      return 1;
    }
  }

  return 0;
}

int
checkattack_ant (Game* game, int rand, Fighter* fighter)
{
  int x = fighter->x_get ();;
  int y = fighter->y_get ();;
  Map& map = Map::get_instance ();
  std::stringstream ss;
  Ground* ground;
  KillableAnt* killableant;

  convert_rand (rand, &x, &y);
  if (map.cell_get (x, y) &&
      (ground = dynamic_cast <Ground*>
       (map.cell_get (x, y)->content_get ())))
    if (!ground->is_empty () &&
	(killableant = dynamic_cast <KillableAnt*> (ground->ant_get ())) &&
	killableant->team_get () != fighter->team_get ())
    {
      ss << "        selected r = " << rand << ", attack team "
	 << killableant->team_get () << "'s ant at "
	 << killableant->x_get () + 1 <<", " << killableant->y_get () + 1;
      print_verbose3 (ss);

      killableant->sub_life (1);

      if (killableant->life_get () < 1)
      {
	game->team_get (killableant->team_get () - 1)->
	  remove_ant (killableant);
	ground->remove_ant ();
	ss << "          ennemy ant is dead, remove from the map";
      }
      else
	ss << "          ennemy ant still have "
	   << killableant->life_get () << " life point(s)";
      print_verbose3 (ss);

      ss << "          drop 5 PB pheromone on each cell around";
      print_verbose3 (ss);
      put_pheromone (fighter, "PB", 5);

      return 1;
    }
  return 0;
}

int
StandardRules::attack_ant (Fighter* fighter)
{
  int i;
  int rand;
  std::stringstream ss;

  for (i = 0; i < 10; ++i)
  {
    rand = my_rand () % 8;

    ss << "        attempt " << i << ", r = " << rand;
    print_verbose3 (ss);

    if (checkattack_ant (this->game_, rand, fighter))
      return 1;
  }
  if (i == 10)
  {
    ss << "        attack failed, does nothing this turn";
    print_verbose2 (ss);
  }

  return 0;
}

int
StandardRules::find_attackable_ant (Fighter* fighter)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Ground* ground;
  KillableAnt* killableant;
  Map& map = Map::get_instance ();
  std::stringstream ss;

  x = fighter->x_get ();
  y = fighter->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	(ground = dynamic_cast <Ground*>
	 (map.cell_get (x, y)->content_get ())))
      if (!ground->is_empty () &&
	  (killableant = dynamic_cast <KillableAnt*> (ground->ant_get ())) &&
	  killableant->team_get () != fighter->team_get ())
      {
	ss << "      is near attackable ant, will try to attack";
	print_verbose2 (ss);
	attack_ant (fighter);
	return 1;
      }
  }

  return 0;
}

int
find_queen_for_food (FoodWorker* foodworker)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Ground* ground;
  Queen* queen;
  Map& map = Map::get_instance ();
  std::stringstream ss;

  x = foodworker->x_get ();
  y = foodworker->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	(ground = dynamic_cast <Ground*>
	 (map.cell_get (x, y)->content_get ())))
    {
      if (!ground->is_empty () &&
	  (queen = dynamic_cast <Queen*> (ground->ant_get ()))
	  && queen->team_get () == foodworker->team_get ())
      {
	queen->add_food (1);
	put_pheromone (foodworker, "PQ", 5);
	foodworker->uncharged ();
	ss << "      feeds queen at " << queen->x_get () + 1
	   << ", " << queen->y_get () + 1;
	print_verbose3 (ss);
	return 1;
      }
    }
  }

  return 0;
}

int
find_queen_for_water (WaterWorker* waterworker)
{
  int x;
  int y;
  int x_tmp;
  int y_tmp;
  Ground* ground;
  Queen* queen;
  Map& map = Map::get_instance ();
  std::stringstream ss;

  x = waterworker->x_get ();
  y = waterworker->y_get ();
  x_tmp = x;
  y_tmp = y;

  for (int i = 0; i < 8; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    convert_rand (i, &x, &y);

    if (map.cell_get (x, y) &&
	(ground = dynamic_cast <Ground*>
	 (map.cell_get (x, y)->content_get ())))
    {
      if (!ground->is_empty () &&
	  (queen = dynamic_cast <Queen*> (ground->ant_get ()))
	  && queen->team_get () == waterworker->team_get ())
      {
	queen->add_food (1);
	put_pheromone (waterworker, "PQ", 5);
	waterworker->uncharged ();
	ss << "      feeds queen at " << queen->x_get () + 1
	   << ", " << queen->y_get () + 1;
	print_verbose3 (ss);
	return 1;
      }
    }
  }

  return 0;
}

void
print_failed ()
{
  std::stringstream ss;

  ss << "        failed to move, does nothing this turn";
  print_verbose3 (ss);
}

int
get_best_score (std::string pheromone, Ant* ant, int x, int y)
{
  int best_score;
  std::stringstream ss;

  if (pheromone == "PB")
    best_score = find_best_score_fighter (x, y, ant->team_get ());
  else
    best_score = find_best_score (pheromone, x, y, ant->team_get ());

  if (pheromone == "PB")
    ss << "      no attackable ants, will try to move, max score = "
       << best_score;
  else
    ss << "      will try to move, max score = " << best_score;
  print_verbose2 (ss);

  return best_score;
}

void
place_pheromone (Ant* ant, std::string pheromone)
{
  std::stringstream ss;

  put_pheromone (ant, pheromone, 1);
  if (pheromone == "PB")
    ss << "          drop 1 PB pheromone on each cell around";
  else
    ss << "          drop 1 pheromone on each cell around";
  print_verbose3 (ss);
}

void
find_next_case (Ant* ant,
		std::string pheromone,
		int x,
		int y)
{
  int	i;
  Ground* ground;
  int rand;
  Map& map = Map::get_instance ();
  int best_score;
  int score;
  int x_tmp;
  int y_tmp;
  std::stringstream ss;

  best_score = get_best_score (pheromone, ant, x, y);

  x_tmp = x;
  y_tmp = y;
  for (i = 0; i < 10; ++i)
  {
    x = x_tmp;
    y = y_tmp;
    rand = my_rand () % 8;
    convert_rand (rand, &x, &y);
    if (pheromone == "PB")
      score = find_score_fighter (x, y, ant->team_get ());
    else
      score = find_score (pheromone, x, y, ant->team_get ());

    ss << "        attempt " << i << ", r = " << rand;
    if (pheromone != "PB")
      ss << ", score = " << score;
    print_verbose3 (ss);

    if (map.cell_get (x, y) && (ground = dynamic_cast <Ground*>
	 (map.cell_get (x, y)->content_get ())))
      if (ground->is_empty () && score == best_score)
      {
	ss << "        selected r = " << rand << ", move to "
	   << x + 1 << ", " << y + 1;
	print_verbose3 (ss);
	break;
      }
  }
  if (i == 10)
    print_failed ();
  else
  {
    ant->move (x, y);
    if (best_score > 0)
      place_pheromone (ant, pheromone);
  }
}

void
StandardRules::move (Ant* ant)
{
  Queen*	queen;
  FoodWorker*	foodworker;
  WaterWorker*	waterworker;
  Fighter*	fighter;
  std::stringstream ss;

  if ((queen = dynamic_cast <Queen*> (ant)))
  {
    ss << "    queen at " << ant->x_get () + 1
       << ", " << ant->y_get () + 1 << " is playing";
    print_verbose1 (ss);
    lay (queen);
  }
  else if ((foodworker = dynamic_cast <FoodWorker*> (ant)))
  {
    ss << "    worker at " << ant->x_get () + 1
       << ", " << ant->y_get () + 1 << " is playing";
    print_verbose1 (ss);
    if (foodworker->is_charged ())
    {
      if (!find_queen_for_food (foodworker))
	find_next_case (ant, "PQ", ant->x_get (), ant->y_get ());
    }
    else
      if (!find_food (foodworker))
	find_next_case (ant, "PF", ant->x_get (), ant->y_get ());
  }
  else if ((waterworker = dynamic_cast <WaterWorker*> (ant)))
  {
    ss << "    worker at " << ant->x_get () + 1
       << ", " << ant->y_get () + 1 << " is playing";
    print_verbose1 (ss);

    if (waterworker->is_charged ())
    {
      if (!find_queen_for_water (waterworker))
	find_next_case (ant, "PQ", ant->x_get (), ant->y_get ());
    }
    else
      if (!find_water (waterworker))
	find_next_case (ant, "PW", ant->x_get (), ant->y_get ());
  }
  else if ((fighter = dynamic_cast <Fighter*> (ant)))
  {
    ss << "    fighter at " << ant->x_get () + 1
       << ", " << ant->y_get () + 1 << " is playing";
    print_verbose1 (ss);
    if (!find_attackable_ant (fighter))
      find_next_case (ant, "PB", ant->x_get (), ant->y_get ());
  }
}

void
StandardRules::play ()
{
  Team* team;
  std::stringstream ss;

  for (int i = 0; i < this->game_->nb_teams (); ++i)
  {
    team = this->game_->team_get (i);

    ss << "  team " << (i + 1) << " is playing";
    print_verbose1 (ss);

    for (int j = 0; j < team->nb_ants (); ++j)
      this->move(team->ant_get (j));
  }
  this->game_->cycle_inc ();
}
