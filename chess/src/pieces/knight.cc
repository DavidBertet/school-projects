#include <iostream>
#include <cmath>
#include "knight.hh"
#include "king.hh"
#include "move_error.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"

Knight::Knight (Board& board,
		Color color,
		Position& position,
		std::list <Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = KNIGHT;
}

Knight::~Knight ()
{
}

void
Knight::accept (PieceVisitor* v)
{
  v->visit (*this);
}

bool
Knight::is_valid_move (const Move& move, bool check)
{
  if (!is_good_move (move))
    return false;

  bool tmp;
  int file_begin = move.end_get ().file_get ();
  int rank_begin = move.end_get ().rank_get ();
  int file_end = move.start_get ().file_get ();
  int rank_end = move.start_get ().rank_get ();

  int diff_width = fabs (rank_begin - rank_end);
  int diff_height = fabs (file_begin - file_end);

  if (diff_width == 1)
    tmp = diff_height == 2;

  else if (diff_width == 2)
    tmp = diff_height == 1;

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
Knight::clone (Board& board)
{
  Position p = Position (this->file_, this->rank_);

  Knight* knight = new Knight (board,
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
  knight->possibilities_set (list);
  return knight;
}
