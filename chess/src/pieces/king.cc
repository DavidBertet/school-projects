#include <iostream>
#include "king.hh"
#include "move_error.hh"
#include "rook.hh"

#include "use_listener.hh"
#include "piece_visitor.hh"
#include "piece_move_visitor.hh"

King::King (Board& board,
	    Color color,
	    Position& position,
	    std::list <Listener*> list)
  : Piece (board, color, position, list)
{
  piece_type_ = KING;
  this->has_move_ = false;
}

King::~King ()
{
}

void
King::accept (PieceVisitor* v)
{
  v->visit (*this);
}

bool
King::is_valid_move (const Move& move, bool check)
{
  Position::File file = move.end_get ().file_get ();
  Position::Rank rank = move.end_get ().rank_get ();
  bool tmp;

  if (!is_good_move (move))
    return false;

  if (file == this->file_ - 1)
  {
    if (rank == this->rank_ - 1 ||
	rank == this->rank_ ||
	rank == this->rank_ + 1)
      tmp = true;
    else
      tmp = false;
  }
  else if (file == this->file_)
  {
    if (rank == this->rank_ - 1 ||
	rank == this->rank_ + 1)
      tmp = true;
    else
      tmp = false;
  }
  else if (file == this->file_ + 1)
  {
    if (rank == this->rank_ - 1 ||
	rank == this->rank_ ||
	rank == this->rank_ + 1)
      tmp = true;
    else
      tmp = false;
  }
  else
    tmp = false;

  if (!check)
    return tmp;

  if (tmp)
    return !is_echec_at_pos (move, Position (file, rank));
  else
    return false;
}

//Move the piece, and test if king at pos "pos" can be eat
bool
King::is_echec_at_pos (Move move, Position pos)
{
  if (this->board_.map_board_get ()[move.end_get ().file_get () - 1]
      [move.end_get ().rank_get () - 1] == this)
    return true;

  bool tmp = true;

  //remove piece
  Piece* start = this->board_.map_board_get ()
    [move.start_get ().file_get () - 1][move.start_get ().rank_get () - 1];
  Piece* end = this->board_.map_board_get ()
    [move.end_get ().file_get () - 1][move.end_get ().rank_get () - 1];

  this->board_.map_board_get ()
    [move.end_get ().file_get () - 1][move.end_get ().rank_get () - 1] = start;

  this->board_.map_board_get ()[move.start_get ().file_get () - 1]
    [move.start_get ().rank_get () - 1] = 0;

  int i;
  for (i = Position::FILE_FIRST; tmp && i < Position::FILE_LAST - 1; ++i)
  {
    for (int j = Position::RANK_FIRST; tmp && j < Position::RANK_LAST - 1; ++j)
    {
      if (this->board_.map_board_get ()[i][j] &&
	  this->board_.map_board_get ()[i][j]->color_get () != this->color_)
      {
Move move (Position ((Position::File) (i + 1), (Position::Rank) (j + 1)),
		   pos);

	if (this->board_.map_board_get ()[i][j]->is_valid_move (move, false))
	  tmp = false;
      }
    }
  }

  //reput piece
  this->board_.map_board_get ()
    [move.end_get ().file_get () - 1][move.end_get ().rank_get () - 1] = end;

  this->board_.map_board_get ()[move.start_get ().file_get () -	1]
    [move.start_get ().rank_get () - 1] = start;

//   std::cout << "info echec =" << !tmp << " for "
// 	    << move.start_get ().file_get () << " "
// 	    << move.start_get ().rank_get () << " to "
// 	    << move.end_get ().file_get () << " "
// 	    << move.end_get ().rank_get () << std::endl;
  return !tmp;
}

void
King::mov_cast_white_king ()
{
  // 4. check if the rook has move.
  Rook* rook = dynamic_cast<Rook*> (this->board_.map_board_get ()[7][0]);
  assert (rook != 0);
  if (rook->has_move_get ())
    throw error::MoveError ("rook has move castling impossible");

  // 5. check if the way is free.
  if (this->board_.map_board_get ()[6][0] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[5][0] != 0)
    throw error::MoveError ("way not free castling impossible");

  // 6. check if the way is safe.
//   if (is_echec_at_pos (Position (Position::FELIX, Position::EINS)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::GUSTAV, Position::EINS)))
//     throw error::MoveError ("way not safe castling impossible");

  // 7. move the king and the rook
  Move move (Position (Position::HECTOR, Position::EINS),
	     Position (Position::FELIX, Position::EINS));

  // listener on_kingside_castling
  on_kingside_castling (list_, WHITE);
  // listener on_piece_moved
  on_piece_moved (list_, KING,
		  Position (Position::EVA, Position::EINS),
		  Position (Position::GUSTAV, Position::EINS));

  PieceMoveVisitor visitor(move);
  rook->accept (&visitor);

  this->board_.map_board_get ()[6][0] = this->board_.map_board_get ()[4][0];
  this->board_.map_board_get ()[4][0] = 0;
  this->file_ = Position::GUSTAV;
  has_move_ = true;
}

void
King::mov_cast_black_king ()
{
  // 4. check if the rook has move.
  Rook* rook = dynamic_cast<Rook*> (this->board_.map_board_get ()[7][7]);
  assert (rook != 0);
  if (rook->has_move_get ())
    throw error::MoveError ("rook has move castling impossible");

  // 5. check if the way is free.
  if (this->board_.map_board_get ()[6][7] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[5][7] != 0)
    throw error::MoveError ("way not free castling impossible");

  // 6. check if the way is safe.
//   if (is_echec_at_pos (Position (Position::FELIX, Position::ACHT)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::GUSTAV, Position::ACHT)))
//     throw error::MoveError ("way not safe castling impossible");
   // 7. move the king and the rook
   Move move (Position (Position::HECTOR, Position::ACHT),
 	     Position (Position::FELIX, Position::ACHT));

    //listener on_king_side_castling
    on_kingside_castling (list_, BLACK);
    //listener on_piece_moved
    on_piece_moved (list_, KING,
		    Position (Position::EVA, Position::ACHT),
		    Position (Position::GUSTAV, Position::ACHT));

  PieceMoveVisitor visitor(move);
  rook->accept (&visitor);

  this->board_.map_board_get ()[6][7] = this->board_.map_board_get ()[4][7];
  this->board_.map_board_get ()[4][7] = 0;
  this->file_ = Position::GUSTAV;
  has_move_ = true;
}

void
King::mov_cast_white_queen ()
{
  // 4. check if the rook has move.
  Rook* rook = dynamic_cast<Rook*> (this->board_.map_board_get ()[0][0]);
  assert (rook != 0);
  if (rook->has_move_get ())
    throw error::MoveError ("rook has move castling impossible");

  // 5. check if the way is free.
  if (this->board_.map_board_get ()[1][0] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[2][0] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[3][0] != 0)
    throw error::MoveError ("way not free castling impossible");

  // 6. check if the way is safe.
//   if (is_echec_at_pos (Position (Position::BELLA, Position::EINS)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::CESAR, Position::EINS)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::DAVID, Position::EINS)))
//     throw error::MoveError ("way not safe castling impossible");
  // 7. move the king and the rook
  Move move (Position (Position::ANNA, Position::EINS),
	     Position (Position::DAVID, Position::EINS));

  // listener on_queenside_castling
  on_queenside_castling (list_, WHITE);
  // listener on_piece_moved
  on_piece_moved (list_, KING,
		  Position (Position::EVA, Position::EINS),
		  Position (Position::CESAR, Position::EINS));

  PieceMoveVisitor visitor(move);
  rook->accept (&visitor);

  this->board_.map_board_get ()[2][0] = this->board_.map_board_get ()[4][0];
  this->board_.map_board_get ()[4][0] = 0;
  this->file_ = Position::CESAR;
  has_move_ = true;
}

void
King::mov_cast_black_queen ()
{
  // 4. check if the rook has move.
  Rook* rook = dynamic_cast<Rook*> (this->board_.map_board_get ()[0][7]);
  assert (rook != 0);
  if (rook->has_move_get ())
    throw error::MoveError ("rook has move castling impossible");

  // 5. check if the way is free.
  if (this->board_.map_board_get ()[1][7] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[2][7] != 0)
    throw error::MoveError ("way not free castling impossible");
  if (this->board_.map_board_get ()[3][7] != 0)
    throw error::MoveError ("way not free castling impossible");

  // 6. check if the way is safe.
//   if (is_echec_at_pos (Position (Position::BELLA, Position::ACHT)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::CESAR, Position::ACHT)))
//     throw error::MoveError ("way not safe castling impossible");
//   if (is_echec_at_pos (Position (Position::DAVID, Position::ACHT)))
//     throw error::MoveError ("way not safe castling impossible");
  // 7. move the king and the rook
  Move move (Position (Position::ANNA, Position::ACHT),
	     Position (Position::DAVID, Position::ACHT));

  // listener on_queenside_castling
  on_queenside_castling (list_, BLACK);
  // listener on_piece_moved
  on_piece_moved (list_, KING,
		    Position (Position::EVA, Position::ACHT),
		    Position (Position::CESAR, Position::ACHT));
  PieceMoveVisitor visitor(move);
  rook->accept (&visitor);

  this->board_.map_board_get ()[2][7] = this->board_.map_board_get ()[4][7];
  this->board_.map_board_get ()[4][7] = 0;
  this->file_ = Position::CESAR;
  has_move_ = true;
}

void
King::castling_king ()
{
  // 1. check if the king has move.
  if (this->has_move_)
    throw error::MoveError ("king has move castling impossible");

  // 2. check if the king is in check.
//   if (is_echec_at_pos (Position (this->file_get (),
// 				 this->rank_get ())))
//     throw error::MoveError ("king echec castling impossible");

  // 3. check if the rook is at the good position.
  if (this->color_ == WHITE &&
      this->board_.map_board_get ()[7][0] != 0 &&
      this->board_.map_board_get ()[7][0]->piece_type_get () == ROOK)
  {
    mov_cast_white_king ();
  }
  else if (this->color_ == BLACK &&
	   this->board_.map_board_get ()[7][7] != 0 &&
	   this->board_.map_board_get ()[7][7]->piece_type_get () == ROOK)
  {
    mov_cast_black_king ();
  }
  else
    throw error::MoveError ("king castling impossible");
}

void
King::castling_queen ()
{
  // 1. check if the king has move.
  if (this->has_move_)
    throw error::MoveError ("king has move castling impossible");

  // 2. check if the king is in check.
//   if (is_echec_at_pos (Position (this->file_get (),
// 				 this->rank_get ())))
//     throw error::MoveError ("king echec castling impossible");

  // 3. check if the rook is at the good position.
  if (this->color_ == WHITE &&
      this->board_.map_board_get ()[0][0] != 0 &&
      this->board_.map_board_get ()[0][0]->piece_type_get () == ROOK)
  {
    mov_cast_white_queen ();
  }
  else if (this->color_ == BLACK &&
	   this->board_.map_board_get ()[0][7] != 0 &&
	   this->board_.map_board_get ()[0][7]->piece_type_get () == ROOK)
  {
    mov_cast_black_queen ();
  }
  else
    throw error::MoveError ("king castling impossible");
}

//--------//
// GETTER //
//--------//

bool
King::has_move_get ()
{
  return this->has_move_;
}

//--------//
// SETTER //
//--------//

void
King::has_move_set (bool has_move)
{
  this->has_move_ = has_move;
}

//--------//
// CLONER //
//--------//

Piece*
King::clone (Board& board)
{
  Position p = Position (this->file_, this->rank_);

  King* king = new King (board,
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
  king->possibilities_set (list);
  return king;
}
