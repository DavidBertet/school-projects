#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../random/random.hh"
#include "maploader.hh"
#include "../ants/foodworker.hh"
#include "../ants/waterworker.hh"
#include "../ants/queen.hh"
#include "../ants/fighter.hh"
#include "../error/maperror.hh"
#include "../game.hh"
#include "../map.hh"
#include "../cells/resources/foodresource.hh"
#include "../cells/resources/waterresource.hh"
#include "../cells/obstacles/stone.hh"
#include "../cells/ground.hh"

MapLoader::MapLoader (Game&	game)
{
  this->game_ = &game;
}

bool	get_x_y (std::istringstream&	line_istream,
		 int&			x,
		 int&			y)
{
  if (line_istream.eof ())
    return 0;

  line_istream >> x;
  if (line_istream.eof ())
    return 0;

  line_istream >> y;
  if (!line_istream.eof ())
    return 0;

  return 1;
}

void	seed_case (std::istringstream& line_istream, int current_pos)
{
  int	seed;

  if (line_istream.eof ())
    throw Error::MapError("Map Not Well Formed: seed form unknown",
			  current_pos);
  line_istream >> seed;
  if (!line_istream.eof ())
    throw Error::MapError("Map Not Well Formed: seed form unknown",
			  current_pos);

  Map& map = Map::get_instance ();

  map.seed_set (seed);
  my_srand (seed);
}

void	map_case (std::istringstream& line_istream, int current_pos)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y))
    throw Error::MapError("Map Not Well Formed: Map form unknown",
			  current_pos);

  if (x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Map x or y negative or null",
			  current_pos);

  Map& map = Map::get_instance ();

  map.create_map (x, y);
}

void
MapLoader::queen_case (std::istringstream&	line_istream,
		       int			team)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Queen form unknown",
			  this->current_pos_);

  Queen* queen = new Queen(x - 1, y - 1, team, this->game_->get_team(team));

  this->game_->get_team(team)->add_ant (queen);

  Map& map = Map::get_instance ();
  Ground* ground = new Ground;

  ground->add_ant (queen);
  map.add_content (x, y, ground);
}

void
MapLoader::food_worker_case (std::istringstream&	line_istream,
			     int			team)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Food worker form unknown",
			  this->current_pos_);

  FoodWorker* worker = new FoodWorker(x - 1, y - 1, team);

  this->game_->get_team(team)->add_ant (worker);

  Map& map = Map::get_instance ();
  Ground* ground = new Ground;

  ground->add_ant (worker);
  map.add_content (x, y, ground);
}

void
MapLoader::fighter_case (std::istringstream&	line_istream,
			 int			team)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Fighter form unknown",
			  this->current_pos_);

  Fighter* fighter = new Fighter(x - 1, y - 1, team);

  this->game_->get_team(team)->add_ant (fighter);

  Map& map = Map::get_instance ();
  Ground* ground = new Ground;

  ground->add_ant (fighter);
  map.active_fighter ();
  map.add_content (x, y, ground);
}

void
MapLoader::water_worker_case (std::istringstream&	line_istream,
			      int			team)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Water worker form unknown",
			  this->current_pos_);

  WaterWorker* worker = new WaterWorker(x - 1, y - 1, team);

  this->game_->get_team(team)->add_ant (worker);

  Map& map = Map::get_instance ();
  Ground* ground = new Ground;

  ground->add_ant (worker);
  map.active_water ();
  map.add_content (x, y, ground);
}

void	obstacle_case (std::istringstream& line_istream, int current_pos)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Obstacle form unknown",
			  current_pos);

  Map& map = Map::get_instance ();
  Stone* stone = new Stone;

  map.add_content (x, y, stone);
}

void	food_case (std::istringstream& line_istream, int current_pos)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Food form unknown",
			  current_pos);

  Map& map = Map::get_instance ();
  FoodResource* foodresource = new FoodResource;

  map.add_content (x, y, foodresource);
}

void	water_case (std::istringstream& line_istream, int current_pos)
{
  int	x;
  int	y;

  if (!get_x_y (line_istream, x, y) || x < 1 || y < 1)
    throw Error::MapError("Map Not Well Formed: Water form unknown",
			  current_pos);

  Map& map = Map::get_instance ();
  WaterResource* waterresource = new WaterResource;

  map.add_content (x, y, waterresource);
}

void
MapLoader::obstacle_bloc ()
{
  std::string	name;
  int		end = 0;

  while (std::getline (this->fd_, this->line_) && ++this->current_pos_)
  {
    if (this->line_.empty ())
      continue;

    std::istringstream	line_istream(this->line_, std::ios_base::in);

    line_istream >> name;

    if (name == "obstacle")
      obstacle_case (line_istream, this->current_pos_);
    else if (name == "end" && ++end)
      break;
    else
      throw Error::MapError("Map Not Well Formed: Entry unknown \"" +
			    this->line_ + "\"", this->current_pos_);
  }
  if (end != 1)
    throw Error::MapError("Map Not Well Formed: End needed",
			  this->current_pos_);
}

void
MapLoader::resource_bloc ()
{
  std::string	name;
  int		end = 0;

  while (std::getline (this->fd_, this->line_) && ++this->current_pos_)
  {
    if (this->line_.empty ())
      continue;

    std::istringstream	line_istream(this->line_, std::ios_base::in);

    line_istream >> name;

    if (name == "food")
      food_case (line_istream, this->current_pos_);
    else if (name == "water")
      water_case (line_istream, this->current_pos_);
    else if (name == "end" && ++end)
      break;
    else
      throw Error::MapError("Map Not Well Formed: Entry unknown \"" +
			    this->line_ + "\"", this->current_pos_);
  }
  if (end != 1)
    throw Error::MapError("Map Not Well Formed: End needed",
			  this->current_pos_);
}

void
MapLoader::team_bloc ()
{
  std::string	name;
  int		nb_queen = 0;
  int		team;
  int		end = 0;

  team = this->game_->add_team();

  while (std::getline (this->fd_, this->line_) && ++this->current_pos_)
  {
    if (this->line_.empty ())
      continue;

    std::istringstream	line_istream(this->line_, std::ios_base::in);

    line_istream >> name;

    if (name == "queen")
    {
      queen_case (line_istream, team);
      nb_queen++;
    }
    else if (name == "food_worker")
      food_worker_case (line_istream, team);
    else if (name == "water_worker")
      water_worker_case (line_istream, team);
    else if (name == "fighter")
      fighter_case (line_istream, team);
    else if (name == "end" && ++end)
      break;
    else
      throw Error::MapError("Map Not Well Formed: Entry unknown \"" +
			    this->line_ + "\"", this->current_pos_);
  }

  if (nb_queen != 1)
    throw Error::MapError("Map Not Well Formed: Need 1 queen by team",
			  this->current_pos_);
  if (end != 1)
    throw Error::MapError("Map Not Well Formed: End needed",
			  this->current_pos_);
}

void
MapLoader::find_case ()
{
  std::string		name;
  std::istringstream	line_istream(this->line_, std::ios_base::in);

  if (this->line_.empty ())
    return;

  line_istream >> name;
  if (name == "seed")
    seed_case (line_istream, this->current_pos_);
  else if (name == "map")
    map_case (line_istream, this->current_pos_);
  else if (name == "resource")
    this->resource_bloc ();
  else if (name == "obstacle")
    this->obstacle_bloc ();
  else if (name == "team")
    this->team_bloc ();
  else
    throw Error::MapError("Map Not Well Formed: Entry unknown \"" +
			  this->line_ + "\"", this->current_pos_);
}

void
MapLoader::loadmap (std::string filename)
{
  this->current_pos_ = 0;
  this->fd_.open (filename.c_str ());

  if (!this->fd_.is_open())
    throw Error::MapError("File not found: " + filename, -1);

  while (std::getline (this->fd_, this->line_) && ++this->current_pos_)
    find_case ();

  this->fd_.close();

  if (!this->game_->get_team (0))
    throw Error::MapError("No team defined", -1);

  Map& map = Map::get_instance ();

  map.complete_map ();
}
