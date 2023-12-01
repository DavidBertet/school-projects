#include "use_listener.hh"

void register_chessboard_adapter (std::list<Listener*>& listener,
				  const ChessboardAdapter& chessboard_adapter)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->register_chessboard_adapter (chessboard_adapter);
}

void on_game_started (std::list<Listener*>& listener)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_game_started ();
}

void on_game_finished (std::list<Listener*>& listener)
{
  for (std::list<Listener*>::iterator i = listener.begin ();
       i != listener.end (); i++)
    (*i)->on_game_finished ();
}

void on_piece_moved (std::list<Listener*>& listener,
		     const PieceType& piece,
		     const Position& from,
		     const Position& to)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_piece_moved (piece, from, to);
}

void on_piece_taken (std::list<Listener*>& listener,
		     const PieceType& piece,
		     const Position& at)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_piece_taken (piece, at);
}

void on_piece_promoted (std::list<Listener*>& listener,
			const PieceType& piece,
			const Position& at)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_piece_promoted (piece, at);
}

void on_kingside_castling (std::list<Listener*>& listener,
			   const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_kingside_castling (color);
}

void on_queenside_castling (std::list<Listener*>& listener,
			    const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_queenside_castling (color);
}

void on_player_check (std::list<Listener*>& listener,
		      const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_player_check (color);
}

void on_player_mat (std::list<Listener*>& listener,
		    const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_player_mat (color);
}

void on_player_pat (std::list<Listener*>& listener,
		    const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin (); i != listener.end (); i++)
    (*i)->on_player_pat (color);
}

void on_player_timeout (std::list<Listener*>& listener,
			const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_player_timeout (color);
}

void on_player_disqualified (std::list<Listener*>& listener,
			     const Color& color)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_player_disqualified (color);
}

void on_draw (std::list<Listener*>& listener)
{
  for (std::list<Listener*>::iterator i =
	 listener.begin ();
       i != listener.end (); i++)
    (*i)->on_draw ();
}
