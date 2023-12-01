#include "piece_move_visitor.hh"

#include "use_listener.hh"
#include "move_error.hh"
#include "move.hh"

#include "queen.hh"
#include "king.hh"
#include "pawn.hh"
#include "rook.hh"
#include "bishop.hh"
#include "knight.hh"

PieceMoveVisitor::PieceMoveVisitor (const Move& move)
  : move_ (move)
{
}

void
PieceMoveVisitor::visit (Queen& queen)
{
  if (!queen.is_valid_move (this->move_))
    throw error::MoveError ("queen move error");

  int file = queen.file_get ();
  int rank = queen.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  queen.board_get ().map_board_get ()[file - 1][rank - 1] = 0;

  queen.file_set (this->move_.end_get ().file_get ());
  queen.rank_set (this->move_.end_get ().rank_get ());

  file = queen.file_get ();
  rank = queen.rank_get ();

  if (queen.board_get ().map_board_get ()[file - 1][rank - 1])
  {
    //listener on_piece_taken
    on_piece_taken (queen.list_listener_get (),
		    queen.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());

    delete queen.board_get ().map_board_get ()[file - 1][rank - 1];
  }

  queen.board_get ().map_board_get ()[file - 1][rank - 1] = &queen;

  //listener on_piece_moved
  on_piece_moved (queen.list_listener_get (), QUEEN,
		  this->move_.start_get (), this->move_.end_get ());
}

void
PieceMoveVisitor::visit (King& king)
{
  if (this->move_.end_get ().file_get () -
      this->move_.start_get ().file_get () == 2)
  {
    king.castling_king ();
    return;
  }

  if (this->move_.start_get ().file_get () -
      this->move_.end_get ().file_get () == 2)
  {
    king.castling_queen ();
    return;
  }

  if (!king.is_valid_move (this->move_))
    throw error::MoveError ("king move error");

  king.has_move_set (true);

  int file = king.file_get ();
  int rank = king.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  king.board_get ().map_board_get ()[file - 1][rank- 1] = 0;

  king.file_set (this->move_.end_get ().file_get ());
  king.rank_set (this->move_.end_get ().rank_get ());

  file = king.file_get ();
  rank = king.rank_get ();

  if (king.board_get ().map_board_get ()[file - 1][rank - 1])
  {
    //listener on_piece_taken
    on_piece_taken (king.list_listener_get (),
		    king.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());

    delete king.board_get ().map_board_get ()[file - 1][rank - 1];
  }

  king.board_get ().map_board_get ()[file - 1][rank - 1] = &king;

  //listener on_piece_moved
  on_piece_moved (king.list_listener_get (), KING,
		  this->move_.start_get (), this->move_.end_get ());
}

void
PieceMoveVisitor::visit (Pawn& pawn)
{
  if (!pawn.is_valid_move (this->move_))
    throw new error::MoveError ("pawn move error");

  int file = pawn.file_get ();
  int rank = pawn.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  // clear the case
  pawn.board_get ().map_board_get ()[file - 1][rank - 1] = 0;

  // eat the enemy
  if (pawn.board_get ().map_board_get ()[file_end - 1][rank_end - 1])
  {
    //listener on_piece_taken
    on_piece_taken (pawn.list_listener_get (),
		    pawn.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());

    delete pawn.board_get ().map_board_get ()[file_end - 1][rank_end - 1];
  }

  pawn.file_set (file_end);
  pawn.rank_set (rank_end);

  // promoted pawn
  if (this->move_.promotion_get () != NONE && (rank == 7 || rank == 2))
  {
    //listener on_piece_promoted
    on_piece_promoted (pawn.list_listener_get (), this->move_.promotion_get(),
		       this->move_.end_get ());

    pawn.board_get ().map_board_get ()[file_end - 1][rank_end - 1]
      = pawn.good_piece (this->move_.promotion_get());

    return;
  }

  // normal movement
  file = pawn.file_get ();
  rank = pawn.rank_get ();

  //set en passant if needed
  //    int diff = this->move_.end_get ().rank_get () - pawn.rank_get ();
  //    if (diff == 2 || diff == -2)
  //      pawn.board_get ().en_passant_get()
  // [pawn.color_get ()] = pawn.file_get ();

  pawn.board_get ().map_board_get ()[file - 1][rank - 1] = &pawn;

  //listener on_piece_moved
  on_piece_moved (pawn.list_listener_get (), PAWN,
		  this->move_.start_get (), this->move_.end_get ());
}

void
PieceMoveVisitor::visit (Rook& rook)
{
  if (!rook.is_valid_move (this->move_))
    throw error::MoveError ("rook move error");

  rook.has_move_set (true);

  int file = rook.file_get ();
  int rank = rook.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  rook.board_get ().map_board_get ()[file - 1][rank- 1] = 0;

  rook.file_set (this->move_.end_get ().file_get ());
  rook.rank_set (this->move_.end_get ().rank_get ());

  file = rook.file_get ();
  rank = rook.rank_get ();

  if (rook.board_get ().map_board_get ()[file - 1][rank - 1])
  {
    //listener on_piece_taken
    on_piece_taken (rook.list_listener_get (),
		    rook.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());

    delete rook.board_get ().map_board_get ()[file - 1][rank - 1];
  }

  rook.board_get ().map_board_get ()[file - 1][rank - 1] = &rook;

  //listener on_piece_moved
  on_piece_moved (rook.list_listener_get (), ROOK,
		  this->move_.start_get (), this->move_.end_get ());
}

void
PieceMoveVisitor::visit (Bishop& bishop)
{
  if (!bishop.is_valid_move (this->move_))
    throw error::MoveError ("bishop move error");

  int file = bishop.file_get ();
  int rank = bishop.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  bishop.board_get ().map_board_get ()[file - 1][rank - 1] = 0;

  bishop.file_set (this->move_.end_get ().file_get ());
  bishop.rank_set (this->move_.end_get ().rank_get ());

  file = bishop.file_get ();
  rank = bishop.rank_get ();

  if (bishop.board_get ().map_board_get ()[file - 1][rank - 1])
  {
    //listener on_piece_taken
    on_piece_taken (bishop.list_listener_get (),
		    bishop.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());

    delete bishop.board_get ().map_board_get ()[file - 1][rank - 1];
  }

  bishop.board_get ().map_board_get ()[file - 1][rank - 1] = &bishop;

  //listener on_piece_moved
  on_piece_moved (bishop.list_listener_get (), BISHOP,
		  this->move_.start_get (), this->move_.end_get ());
}

void
PieceMoveVisitor::visit (Knight& knight)
{
  if (!knight.is_valid_move (this->move_))
    throw error::MoveError ("knight move error");

  int file = knight.file_get ();
  int rank = knight.rank_get ();
  Position::File file_end = this->move_.end_get ().file_get ();
  Position::Rank rank_end = this->move_.end_get ().rank_get ();

  knight.board_get ().map_board_get ()[file - 1][rank- 1] = 0;

  knight.file_set (this->move_.end_get ().file_get ());
  knight.rank_set (this->move_.end_get ().rank_get ());

  file = knight.file_get ();
  rank = knight.rank_get ();

  if (knight.board_get ().map_board_get ()[file - 1][rank - 1])
  {
    //listener on_piece_taken
    on_piece_taken (knight.list_listener_get (),
		    knight.board_get ().map_board_get ()
		    [file_end - 1][rank_end - 1]->piece_type_get (),
		    this->move_.end_get ());
    delete knight.board_get ().map_board_get ()[file - 1][rank - 1];
  }

  knight.board_get ().map_board_get ()[file - 1][rank - 1] = &knight;

  //listener on_piece_moved
  on_piece_moved (knight.list_listener_get (), KNIGHT,
		  this->move_.start_get (), this->move_.end_get ());
}
