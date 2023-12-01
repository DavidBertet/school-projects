#include <iostream>
#include "pawn.hh"
#include "move_error.hh"
#include "error.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"

#include "king.hh"
#include "queen.hh"
#include "rook.hh"
#include "knight.hh"
#include "bishop.hh"

Pawn::Pawn (Board& board,
	    Color color,
	    Position& position,
	    std::list <Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = PAWN;
}

Pawn::~Pawn ()
{
}

void
Pawn::accept (PieceVisitor* v)
{
  v->visit (*this);
}

Piece*
Pawn::good_piece (PieceType type)
{
  Position pos = Position (this->file_, this->rank_);

  if (type == QUEEN)
    return new Queen (board_, color_, pos, list_);
  if (type == ROOK)
    return new Rook (board_, color_, pos, list_);
  if (type == BISHOP)
    return new Bishop (board_, color_, pos, list_);
  if (type == KNIGHT)
     return new Knight (board_, color_, pos, list_);
  if (type == PAWN)
    return new Pawn (board_, color_, pos, list_);

  throw error::Error ("pawn promoted on an invalid type");
}

bool
Pawn::is_valid_move (const Move& move, bool check)
{
  if (!this->is_good_move (move))
    return false;

  bool tmp;
  int diff = move.end_get ().rank_get () - this->rank_;
  int file_end = move.end_get ().file_get ();
  int rank_end = move.end_get ().rank_get ();

  //test if there is a piece at the end and the diagonal
  if (this->board_.map_board_get ()[file_end - 1][rank_end - 1] &&
      this->file_ == move.end_get ().file_get ())
    tmp = false;

  else if (this->file_ != move.end_get ().file_get ())
  {
    // try if the diagonal movement is valid
    if ((this->file_ + 1 == move.end_get ().file_get () || // next column
	 this->file_ - 1 == move.end_get ().file_get ()) &&
	((diff == 1 && color_ == WHITE) ||
	 (diff == -1 && color_ == BLACK)) && //next line
	this->board_.map_board_get ()[file_end - 1][rank_end - 1] &&
	this->color_ !=
	this->board_.map_board_get ()[file_end - 1][rank_end - 1]
	->color_get ())
      tmp = true;
    else
      tmp = false;
  }

  else if ((this->rank_ == 2 && this->color_ == WHITE) ||
      (this->rank_ == 7 && this->color_ == BLACK))
  {
    if (this->board_.map_board_get ()[file_end - 1][rank_end - 1] == 0)
    {
      if (this->color_ == WHITE)
      {
	if (diff == 2)
	  tmp = this->board_.map_board_get ()[file_end - 1][rank_end - 2] == 0;
	else if (diff == 1)
	{
	  if (this->board_.map_board_get ()[file_end - 1][rank_end - 1] == 0)
	    tmp = true;
	  else
	    tmp = false;
	}
	else
	  tmp = false;
      }
      else
      {
	if (diff == -2)
	  tmp = this->board_.map_board_get ()
	    [file_end - 1][rank_end] == 0;
	else if (diff == -1)
	  tmp = true;
	else
	  tmp = false;
      }
    }
    else
      tmp = false;
  }
  else if (( diff == 1 && color_ == WHITE) ||
      (diff == -1 && color_ == BLACK))
  {
    if (this->board_.map_board_get ()[file_end - 1][rank_end - 1] == 0)
      tmp = true;
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
    Pawn::clone (Board& board)
  {
    Position p = Position (this->file_, this->rank_);

    Pawn* pawn = new Pawn (board,
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
    pawn->possibilities_set (list);
    return pawn;
  }
