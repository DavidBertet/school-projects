#include "piece.hh"
#include "assert.h"

#include "king.hh"

Piece::Piece (Board& board,
	      Color color,
	      Position& position,
	      std::list<Listener*> list)
  : board_ (board),
    color_ (color),
    file_ (position.file_get ()),
    rank_ (position.rank_get ()),
    list_ (list)

{
}

Piece::~Piece ()
{
}

bool
Piece::is_good_move (const Move& piece)
{

  if ((piece.end_get ().file_get () < Position::FILE_LAST) &&
  //the piece is in the board
      (piece.end_get ().rank_get () < Position::RANK_LAST) &&
      (piece.end_get ().file_get () > Position::FILE_FIRST) &&
      (piece.end_get ().rank_get () > Position::RANK_FIRST) &&
      ((piece.end_get ().file_get () != piece.start_get ().file_get ()) ||
 // the movement is not the initial pos
       (piece.end_get ().rank_get () != piece.start_get ().rank_get ())))
  {
    //test color
    if ((this->board_.map_board_get ()[piece.end_get ().file_get () - 1]
                                   [piece.end_get ().rank_get () - 1] &&
	 this->color_ ==
	 this->board_.map_board_get ()[piece.end_get ().file_get () - 1]
	 [piece.end_get ().rank_get () - 1]->color_get ()))
      return false;

    return true;
  }
  return false;
}

bool
Piece::no_check_after_move (Move& piece)
{
  King* king;
  (void) piece;
  Piece* p = board_.king_get (this->color_);
  king = dynamic_cast<King*> (p);
  assert (king != 0);

  // 1 premove this
  // 2 use king->is_echec_at_pos(current_pos_if the king);
  // 3 we un_premove this or premove with the opposite move.
  // 4 if it is_check then the move is wrong retrun false.
  // 5 else the move is ok return true

  return false;
}


//--------//
// GETTER //
//--------//

Color
Piece::color_get () const
{
  return this->color_;
}

PieceType
Piece::piece_type_get () const
{
  return this->piece_type_;
}

Position::File
Piece::file_get () const
{
  return this->file_;
}

Position::Rank
Piece::rank_get () const
{
  return this->rank_;
}

Board&
Piece::board_get () const
{
  return this->board_;
}

std::list<Listener*>&
Piece::list_listener_get ()
{
  return this->list_;
}

std::list<Move*>&
Piece::possibilities_get ()
{
  return this->possibilities_;
}

//--------//
// SETTER //
//--------//

void
Piece::file_set (Position::File file)
{
  this->file_ = file;
}

void
Piece::rank_set (Position::Rank rank)
{
  this->rank_ = rank;
}

void
Piece::possibilities_set (std::list<Move*>& l)
{
  this->possibilities_ = l;
}
