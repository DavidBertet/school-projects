#include <list>

#include "board.hh"
#include "move.hh"
#include "piece.hh"
#include "error.hh"
#include "parser/chessdriver.hh"
#include "listener/loadlistener.hh"
#include "use_listener.hh"

#ifdef BONUS
# include "listener_3d.hh"
#endif

int
main (int argc, char *argv[])
{
  argc = argc;
  ChessDriver driver;
  std::list <Listener*> list_listener;

  try
  {
    // increment argv then you don't need to use argc
    for (++argv; argv[0]; ++argv)
      if (*argv == std::string ("-p"))
	driver.trace_parsing = true;
      else if (*argv == std::string ("-s"))
	driver.trace_scanning = true;
      else
      {
	std::string filename = std::string(*argv);
	if (filename.substr (filename.length () - 3 ,
			     filename.length ()) == ".so")
	{
	  LoaderListener *loader;
	  loader = new LoaderListener (filename);
	  list_listener.push_back (loader->load ());
	  continue;
	}
      }
    driver.parse ();
#ifdef BONUS
    Listener3D* listener = new Listener3D;
    list_listener.push_back (listener);
#endif

    std::string str;
    Board board (list_listener);

    //listener register_chessboard_adapter
    register_chessboard_adapter (list_listener, board);

    //listener on_game_started
    on_game_started (list_listener);

    for (std::vector<std::pair<MovePGN*, MovePGN*>*>::iterator i =
	   (*driver.pgn_get ()).begin ();
	 i != (*driver.pgn_get ()).end (); i++)
    {
      if (*i && (**i).first)
	board.move_pgn (*(**i).first, WHITE);

      if (*i && (**i).second)
	board.move_pgn (*(**i).second, BLACK);

      //print board
      //board.print ();
    }
  }

  catch (error::Error e)
  {
    e.print (std::cerr);

    //listener on_game_finished
    on_game_finished (list_listener);

    return 2;
  }
  //listener on_game_finished
  on_game_finished (list_listener);
}
