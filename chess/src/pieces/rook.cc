#include <iostream>
#include "rook.hh"
#include "king.hh"
#include "move_error.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"

Rook::Rook (Board& board,
	    Color color,
	    Position& position,
	    std::list <Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = ROOK;
  this->has_move_ = false;
}

Rook::~Rook ()
{
}

void
Rook::accept (PieceVisitor* v)
{
  v->visit (*this);
}

bool
Rook::is_valid_move (const Move& move, bool check)
{
  if (!is_good_move (move))
    return false;

  bool tmp;
  int file = move.end_get ().file_get ();
  int rank = move.end_get ().rank_get ();
  int filed = move.start_get ().file_get ();
  int ranked = move.start_get ().rank_get ();

  if (ranked == rank)
  {
    if (file > filed)
      tmp = this->move_right(filed, file, ranked, rank);
    else if (file < filed)
      tmp = this->move_left(filed, file, ranked, rank);
    else
      tmp = false;
  }
  else if (file == filed)
  {
    if (rank > ranked)
      tmp = this->move_high(filed, file, ranked, rank);
    else if (rank < ranked)
      tmp = this->move_down(filed, file, ranked, rank);
    else
      tmp = false;
  }
  else
    tmp = false;

  if (!check)
    return tmp;

   if (tmp)
     return !this->board_.king_get (this->color_)->is_echec_at_pos (move,
 			  Position (this->board_.king_get
			      (this->color_)->file_get (),
 			       this->board_.king_get
 	      	              (this->color_)->rank_get ()));
   else
     return false;
}

//-------------------------------------//
// functiond for the 'line' movements  //
//-------------------------------------//

bool
Rook::move_high (int filed, int file,
		 int ranked, int rank)
{
  file = file;
  for (int j = ranked + 1; j < rank; ++j)
    if (this->board_.map_board_get ()[filed - 1][j - 1] != 0)
      return false;
  return true;
}

bool
Rook::move_down (int filed, int file,
		 int ranked, int rank)
{
  file = file;
  for (int j = ranked - 1; j > rank; --j)
    if (this->board_.map_board_get ()[filed - 1][j - 1] != 0)
      return false;
  return true;
}

bool
Rook::move_right (int filed, int file,
		  int ranked, int rank)
{
  rank = rank;
  for (int i = filed + 1; i < file; ++i)
    if (this->board_.map_board_get ()[i - 1][ranked - 1] != 0)
      return false;
  return true;
}

bool
Rook::move_left (int filed, int file,
		 int ranked, int rank)
{
  rank = rank;
  for (int i = filed - 1; i > file; --i)
    if (this->board_.map_board_get ()[i - 1][ranked - 1] != 0)
      return false;
  return true;
}

//--------//
// GETTER //
//--------//

bool
Rook::has_move_get ()
{
  return this->has_move_;
}

//--------//
// SETTER //
//--------//

void
Rook::has_move_set (bool has_move)
{
  this->has_move_ = has_move;
}

//--------//
// CLONER //
//--------//

Piece*
Rook::clone (Board& board)
{
  Position p = Position (this->file_, this->rank_);

  Rook* rook = new Rook (board,
			 this->color_,
			 p,
			 this->list_);
  std::list<Move*>& list = *(new std::list<Move*>);
  for (std::list<Move*>::iterator it = this->possibilities_.begin ();
       it != this->possibilities_.end (); ++it)
  {
    Move* move = new Move ((*it)->start_get (),
			   (*it)->end_get (), QUEEN);
    list.push_back (move);
  }
  has_move_set (this->has_move_);
  rook->possibilities_set (list);
  return rook;
}
