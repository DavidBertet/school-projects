#include <limits>
#include <iostream>
#include <sstream>
#include "maploader.hh"
#include "maperror.hh"
#include "opterror.hh"
#include "game.hh"
#include "ascii.hh"
#include "standardrules.hh"
#include "map.hh"

int
check_opt (int argc,
	   char** argv)

{
  int i;
  int j;
  std::stringstream ss;
  char c;

  if (argc < 2)
    throw Error::OptError ('\0');
  for (i = 1; i < argc; ++i)
  {
    ss.clear ();
    ss << argv[i];
    ss >> c;
    if (c != '-')
      break;

    while (ss >> c)
    {
      if (c != 'v' && c != 'i' && c != 'p' && c != 'a')
	throw Error::OptError (c);
    }
  }
  for (j = i; j < argc; ++j)
  {
    ss.str ("");
    ss << argv[j];
    ss >> c;
    if (c == '-')
      throw Error::OptError (c);
  }
  return i;
}

int
count_print (int argc,
	     char** argv)

{
  int i;
  std::stringstream ss;
  char c;

  for (i = 1; i < argc; ++i)
  {
    ss.str ("");
    ss << argv[i];
    ss >> c;
    if (c != '-')
      break;

    while (ss >> c)
    {
      if (c == 'p')
	return 1;
    }
  }

  return 0;
}

int
count_interactive (int argc,
		   char** argv)

{
  int i;
  std::stringstream ss;
  char c;

  for (i = 1; i < argc; ++i)
  {
    ss.str ("");
    ss << argv[i];
    ss >> c;
    if (c != '-')
      break;

    while (ss >> c)
    {
      if (c == 'i')
	return 1;
    }
  }

  return 0;
}

int
count_verbose (int argc,
	       char** argv)
{
  int i;
  int verbose = 0;
  std::stringstream ss;
  char c;

  for (i = 1; i < argc; ++i)
  {
    ss.clear ();
    ss << argv[i];
    ss >> c;
    if (c != '-')
      break;

    while (ss >> c)
    {
      if (c == 'v')
	verbose += 1;
    }
  }

  return verbose;
}

int
get_nb_cycle (int argc, int pos_opt, Ascii& print, char** argv)
{
  std::stringstream ss;
  int nb_cycle = 0;

  if (pos_opt + 2 > argc)
  {
    print.print ();
    exit (0);
  }
  else
  {
    ss << argv[pos_opt + 1];
    ss >> nb_cycle;
  }

  return nb_cycle;
}

int
main (int	argc,
      char**	argv)
{
  int pos_opt;
  Game		game;
  MapLoader	maploader (game);
  Ascii		print (1);
  StandardRules rules (game);
  int print_opt;
  int interactive_opt = 1;
  int nb_iteration;

  try
  {
    pos_opt = check_opt (argc, argv);
  }
  catch (Error::OptError e)
  {
    std::cerr << e.get_error () << std::endl;
    return 1;
  }

  print_opt = count_print (argc, argv);
  interactive_opt = count_interactive (argc, argv);

  try
  {
    maploader.loadmap (argv[pos_opt]);

    nb_iteration = get_nb_cycle (argc, pos_opt, print, argv);

    Map& map = Map::get_instance ();
    map.verbose_set (count_verbose (argc, argv));

    for (int i = 0; i < nb_iteration; ++i)
    {
      if (map.verbose_get ())
	std::cout << "starting new cycle " << i << std::endl;
      if (print_opt)
      {
	print.print ();
	std::cout << std::endl;
      }
      rules.play();
      if (print_opt)
	if (interactive_opt)
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    print.print ();
  }
  catch (Error::MapError e)
  {
    std::cerr << e.get_error () << std::endl;
    return 1;
  }
}
