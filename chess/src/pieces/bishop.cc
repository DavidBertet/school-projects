#include <iostream>
#include <cmath>
#include "bishop.hh"
#include "king.hh"
#include "move_error.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"

Bishop::Bishop (Board& board,
		Color color,
		Position& position,
		std::list<Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = BISHOP;
}

Bishop::~Bishop ()
{
}

void
Bishop::accept (PieceVisitor* v)
{
  v->visit (*this);
}

bool
Bishop::move_left_high (int filed, int file,
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
Bishop::move_left_down (int filed, int file,
			int ranked, int rank)
{
  for (int i = filed + 1, j = ranked - 1;
       i < file && j > rank; ++i, --j)
  {
    if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
      return false;
  }
  return true;
}

bool
Bishop::move_right_high (int filed, int file,
			 int ranked, int rank)
{
  for (int i = filed - 1, j = ranked + 1;
       i > file && j < rank; --i, ++j)
      if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
	return false;
  return true;
}

bool
Bishop::move_right_down (int filed, int file,
			 int ranked, int rank)
{
  for (int i = filed - 1, j = ranked - 1;
       i > file && j > rank; --i, --j)
    if (this->board_.map_board_get ()[i - 1][j - 1] != 0)
      return false;
  return true;
}

bool
Bishop::is_valid_move (const Move& move, bool check)
{
  if (!is_good_move (move))
    return false;

  bool tmp;
  int file_end = move.end_get ().file_get ();
  int rank_end = move.end_get ().rank_get ();
  int file_begin = move.start_get ().file_get ();
  int rank_begin = move.start_get ().rank_get ();
  int diff_rank = rank_end - rank_begin;
  int diff_file = file_end - file_begin;

  if (fabs(diff_rank) != fabs(diff_file))
    tmp = false;
  else if (!is_good_move (move))
    tmp = false;

  else if (diff_file > 0)
  {
    if (diff_rank > 0)
      tmp = this->move_left_high (file_begin,
				   file_end,
				   rank_begin,
				   rank_end);
    else if (diff_rank < 0)
      tmp = this->move_left_down (file_begin,
				   file_end,
				   rank_begin,
				   rank_end);
    else
      tmp = false;
  }
  else if (diff_file < 0)
  {
    if (diff_rank > 0)
      tmp = this->move_right_high (file_begin,
				    file_end,
				    rank_begin,
				    rank_end);
    else if (diff_rank < 0)
      tmp = this->move_right_down (file_begin,
				    file_end,
				    rank_begin,
				    rank_end);
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

//--------//
// CLONER //
//--------//

Piece*
Bishop::clone (Board& board)
{
  Position p = Position (this->file_, this->rank_);

  Bishop* bishop = new Bishop (board,
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
  bishop->possibilities_set (list);
  return bishop;
}
