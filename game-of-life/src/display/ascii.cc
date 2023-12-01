#include <iostream>
#include "ascii.hh"
#include "../cells/ground.hh"
#include "../cells/obstacles/stone.hh"
#include "../cells/resources/waterresource.hh"
#include "../cells/resources/foodresource.hh"
#include "../ants/foodworker.hh"
#include "../ants/waterworker.hh"
#include "../ants/queen.hh"
#include "../ants/fighter.hh"
#include "../map.hh"

void
print_header (std::ostream&	output,
	      int		width)
{
  int	i;
  int	print_number;

  output << "  |";

  for (i = 1; i < width; ++i)
  {
    print_number = i % 100;
    if (print_number < 10)
      output << "0";

    output << print_number << " ";
  }
  print_number = i % 100;
  if (print_number < 10)
    output << "0";
  output << print_number << "|" << std::endl;

  for (i = 1; i <= width + 1; ++i)
    output << "---";

  output << std::endl;
}

void
print_queen (std::ostream& output,
	     Queen* queen)
{
  if (queen->nb_food_get () > 0)
    output << "Q";
  else
    output << "q";
}

void
print_food_worker (std::ostream& output,
		   FoodWorker* foodworker)
{
  if (foodworker->is_charged ())
    output << "F";
  else
    output << "f";
}

void
print_water_worker (std::ostream& output,
		    WaterWorker* waterworker)
{
  if (waterworker->is_charged ())
    output << "W";
  else
    output << "w";
}

void
print_fighter (std::ostream& output,
	       Fighter* fighter)
{
  fighter = fighter;

  output << "b";
}

void
print_ant (std::ostream& output,
	   Ant* ant)
{
  Queen*	queen;
  FoodWorker*	foodworker;
  WaterWorker*	waterworker;
  Fighter*	fighter;

  if ((queen = dynamic_cast <Queen*> (ant)))
    print_queen (output, queen);
  else if ((foodworker = dynamic_cast <FoodWorker*> (ant)))
    print_food_worker (output, foodworker);
  else if ((waterworker = dynamic_cast <WaterWorker*> (ant)))
    print_water_worker (output, waterworker);
  else if ((fighter = dynamic_cast <Fighter*> (ant)))
    print_fighter (output, fighter);

  output << ant->team_get () << "|";
}

void
print_line (std::ostream& output,
	    int	h)
{
  Map& map = Map::get_instance ();
  Ground* ground;

  for (int i = 0; i < map.w_get (); ++i)
  {
    if (dynamic_cast <FoodResource*> (map.cell_get (i, h)->content_get ()))
      output << "F |";
    else if (dynamic_cast <WaterResource*>
	     (map.cell_get (i, h)->content_get ()))
      output << "W |";
    else if (dynamic_cast <Stone*> (map.cell_get (i, h)->content_get ()))
      output << "X |";
    else if ((ground = dynamic_cast <Ground*>
	      (map.cell_get (i, h)->content_get ()))
	     && !ground->is_empty ())
      print_ant (output, ground->ant_get ());
    else
      output << "  |";
  }
}

void
print_inside (std::ostream&	output,
	      int		width,
	      int		height)
{
  int	i;
  int	j;
  int	print_number;

  for (i = 1; i < height; ++i)
  {
    //print number
    print_number = i % 100;
    if (print_number < 10)
      output << "0";
    output << print_number << "|";

    print_line (output, i - 1);

    output << std::endl;

    //print separator
    output << "  -";
    for (j = 1; j <= width; ++j)
      output << "---";
    output << std::endl;
  }

  //print last line
  print_number = i % 100;
  if (print_number < 10)
    output << "0";
  output << print_number << "|";

  print_line (output, i - 1);
  output << std::endl;

  for (j = 1; j <= width + 1; ++j)
    output << "---";
  output << std::endl;
}

Ascii::Ascii (int verbose_level)
  : Display (verbose_level)
{
}

void
Ascii::print () const
{
  Map map = Map::get_instance ();

  print_header (std::cout, map.w_get ());
  print_inside (std::cout, map.w_get (), map.h_get ());
}

void
Ascii::print_verbose1 (std::string str)
{
  if (this->verbose_level_ > 0)
    std::cout << str << std::endl;
}

void
Ascii::print_verbose2 (std::string str)
{
  if (this->verbose_level_ > 1)
    std::cout << str << std::endl;
}

void
Ascii::print_verbose3 (std::string str)
{
  if (this->verbose_level_ > 2)
    std::cout << str << std::endl;
}
