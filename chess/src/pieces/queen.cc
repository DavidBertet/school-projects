#include <iostream>
#include <cmath>
#include "queen.hh"
#include "king.hh"
#include "move_error.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"

Queen::Queen (Board& board,
	      Color color,
	      Position& position,
	      std::list <Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = QUEEN;
}

Queen::~Queen ()
{
}

void
Queen::accept (PieceVisitor* v)
{
  v->visit (*this);
}

bool
Queen::is_valid_move (const Move& move, bool check)
{
  if (!is_good_move (move))
    return false;

  bool tmp;
  int file = move.end_get ().file_get ();
  int rank = move.end_get ().rank_get ();
  int filed = move.start_get ().file_get ();
  int ranked = move.start_get ().rank_get ();

  int diff_rank = rank - ranked;
  int diff_file = file - filed;

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
  else if (fabs(diff_rank) != fabs(diff_file))
    tmp = false;
  else if (diff_file > 0)
  {
    if (diff_rank > 0)
      tmp = this->move_left_high (filed, file, ranked, rank);
    else if (diff_rank < 0)
      tmp = this->move_left_down (filed, file, ranked, rank);
    else
      tmp = false;
  }
  else if (diff_file < 0)
  {
    if (diff_rank > 0)
      tmp = this->move_right_high (filed, file, ranked, rank);
    else if (diff_rank < 0)
      tmp = this->move_right_down (filed, file, ranked, rank);
    else
      tmp = false;
  }
  else
    tmp = false;

  if (!check)
    return tmp;

   if (tmp)
     return !this->board_.king_get (this->color_)->is_echec_at_pos (move,
					  Position
					     (this->board_.king_get
					      (this->color_)->file_get (),
					      this->board_.king_get
					      (this->color_)->rank_get ()));
   else
     return false;
}

//--------------------------------------//
// functions for the diagonal movements //
//--------------------------------------//

bool
Queen::move_left_high (int filed, int file,
		       int ranked, int rank)
{
  for (int i = filed + 1, j = ranked + 1;
       i < file && j < rank; ++i, ++j)
    {
      if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
	return false;
    }
  return true;
}

bool
Queen::move_left_down (int filed, int file,
		       int ranked, int rank)
{
  for (int i = filed + 1, j = ranked - 1;
       i < file && j > rank; ++i, --j)
      if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
	return false;
  return true;
}

bool
Queen::move_right_high (int filed, int file,
			int ranked, int rank)
{
  for (int i = filed - 1, j = ranked + 1;
       i > file && j < rank; --i, ++j)
      if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
	return false;
  return true;
}

bool
Queen::move_right_down (int filed, int file,
			int ranked, int rank)
{
  for (int i = filed - 1, j = ranked - 1;
       i > file && j > rank; --i, --j)
    if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
      return false;
  return true;
}

//-------------------------------------//
// functiond for the 'line' movements  //
//-------------------------------------//

bool
Queen::move_high (int filed, int file,
		  int ranked, int rank)
{
  file = file;

  for (int j = ranked + 1; j < rank; ++j)
    if (this->board_.map_board_get ()[filed - 1][j - 1] != 0)
      return false;
  return true;
}

bool
Queen::move_down (int filed, int file,
		  int ranked, int rank)
{
  file = file;
  for (int j = ranked - 1; j > rank; --j)
    if (this->board_.map_board_get ()[filed - 1][j - 1] != 0)
      return false;
  return true;
}

bool
Queen::move_right (int filed, int file,
		   int ranked, int rank)
{
  rank = rank;
  for (int i = filed + 1; i < file; ++i)
    if (this->board_.map_board_get ()[i - 1][ranked - 1] != 0)
      return false;
  return true;
}

bool
Queen::move_left (int filed, int file,
		  int ranked, int rank)
{
  rank = rank;
  for (int i = filed - 1; i > file; --i)
    if (this->board_.map_board_get ()[i - 1][ranked - 1] != 0)
      return false;
  return true;
}

//--------//
// CLONER //
//--------//

Piece*
Queen::clone (Board& board)
{
  Position p = Position (this->file_, this->rank_);

  Queen* queen = new Queen (board,
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
  queen->possibilities_set (list);
  return queen;
}
