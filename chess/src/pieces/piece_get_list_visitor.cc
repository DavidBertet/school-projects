#include <iostream>
#include <list>

#include "piece_get_list_visitor.hh"
#include "piece-type.hh"

#include "queen.hh"
#include "king.hh"
#include "pawn.hh"
#include "rook.hh"
#include "bishop.hh"
#include "knight.hh"
#include "position.hh"

void
PieceGetListVisitor::visit (Queen& queen)
{
  this->clear (queen.possibilities_get ());

  move_up (queen);
  move_down (queen);
  move_right (queen);
  move_left (queen);
  move_left_up (queen);
  move_left_down (queen);
  move_right_up (queen);
  move_right_down (queen);
}

void
PieceGetListVisitor::visit (King& king)
{
  this->clear (king.possibilities_get ());

  for (int i = -1; i < 2; ++i)
  {
    for (int j = -1; j < 2; ++j)
    {
      move_piece (king, i, j);
    }
  }

}

void
PieceGetListVisitor::move_piece (Piece& piece, int file_diff, int rank_diff,
				 PieceType type)
{
  Position::File file = piece.file_get ();
  Position::Rank rank = piece.rank_get ();

  Move* move = new Move (Position (file, rank),
			 Position ((Position::File) (file + file_diff),
				   (Position::Rank) (rank + rank_diff)),
			 type);

  if (piece.is_valid_move (*move))
    piece.possibilities_get ().push_back (move);
  else
    delete move;
}

void
PieceGetListVisitor::visit (Rook& rook)
{
  this->clear (rook.possibilities_get ());

  move_up (rook);
  move_down (rook);
  move_right (rook);
  move_left (rook);

//   // debug for print list of move of a piece.
//   print (rook, "rook");
}

void
PieceGetListVisitor::visit (Bishop& bishop)
{
  this->clear (bishop.possibilities_get ());

  move_left_up (bishop);
  move_left_down (bishop);
  move_right_up (bishop);
  move_right_down (bishop);

}

void
PieceGetListVisitor::visit (Pawn& pawn)
{
  this->clear (pawn.possibilities_get ());

  if (pawn.color_get () == WHITE)
  {
//     if (pawn.rank_get () + 1 == 8)
//     {
//       move_piece (pawn, 0, 1, QUEEN);
//       move_piece (pawn, 1, 1, QUEEN);
//       move_piece (pawn, -1, 1, QUEEN);
//     }
//     else
//     {
      move_piece (pawn, 0, 1, NONE);
      move_piece (pawn, 1, 1, NONE);
      move_piece (pawn, -1, 1, NONE);
//     }
//     if (pawn.rank_get () + 2 == 8)
//       move_piece (pawn, 0, 2, QUEEN);
//     else
      move_piece (pawn, 0, 2, NONE);
  }
  if (pawn.color_get () == BLACK)
  {
//     if (pawn.rank_get () - 1 == 1)
//     {
//       move_piece (pawn, 0, -1, QUEEN);
//       move_piece (pawn, 1, -1, QUEEN);
//       move_piece (pawn, -1, -1, QUEEN);
//     }
//     else
//     {
      move_piece (pawn, 0, -1, NONE);
      move_piece (pawn, 1, -1, NONE);
      move_piece (pawn, -1, -1, NONE);
//     }
//     if (pawn.rank_get () - 2 == 1)
//       move_piece (pawn, 0, -2, QUEEN);
//     else
      move_piece (pawn, 0, -2, NONE);
  }
}

void
PieceGetListVisitor::visit (Knight& knight)
{
  this->clear (knight.possibilities_get ());

  move_piece (knight, 1, 2);
  move_piece (knight, -1, 2);
  move_piece (knight, 1, -2);
  move_piece (knight, -1, -2);

  move_piece (knight, 2, 1);
  move_piece (knight, 2, -1);
  move_piece (knight, -2, 1);
  move_piece (knight, -2, -1);
}

//-------------------------------------//
// functiond for the 'line' movements  //
//-------------------------------------//

void
PieceGetListVisitor::move_up (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();
  for (int j = rank + 1; j <= 8; ++j)
  {
    Move* move = new Move(Position ((Position::File) file,
				    (Position::Rank) rank),
			  Position ((Position::File) file,
				    (Position::Rank) j));

    if (p.is_valid_move (*move))
    {
      p.possibilities_get ().push_back (move);
    }
    else
      delete move;
    if (p.board_get ().map_board_get ()[file - 1][j - 1])
      return;
  }
}

void
PieceGetListVisitor::move_down (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();
  for (int j = rank - 1; j >= 1 ; --j)
  {
    Move* move = new Move(Position ((Position::File) file,
				    (Position::Rank) rank),
			  Position ((Position::File) file,
				    (Position::Rank) j));

    if (p.is_valid_move (*move))
    {
      p.possibilities_get ().push_back (move);
    }
    else
      delete move;
    if (p.board_get ().map_board_get ()[file - 1][j - 1])
      return;
  }
}

void
PieceGetListVisitor::move_right (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();
  for (int i = file - 1; i >= 1; --i)
  {
    Move* move = new Move(Position ((Position::File) file,
				    (Position::Rank) rank),
			  Position ((Position::File) i,
				    (Position::Rank) rank));
    if (p.is_valid_move (*move))
    {
      p.possibilities_get ().push_back (move);
    }
    else
      delete move;
    if (p.board_get ().map_board_get ()[i - 1][rank - 1])
      return;
  }
}

void
PieceGetListVisitor::move_left (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();
  for (int i = file + 1; i <= 8; ++i)
  {
    Move* move = new Move(Position ((Position::File) file,
				    (Position::Rank) rank),
			  Position ((Position::File) i,
				    (Position::Rank) rank));
    if (p.is_valid_move (*move))
    {
      p.possibilities_get ().push_back (move);
    }
    else
      delete move;
    if (p.board_get ().map_board_get ()[i - 1][rank - 1])
      return;
  }
}

//-----------------------------------------//
// functiond for the 'diagonal' movements  //
//-----------------------------------------//

void
PieceGetListVisitor::move_left_up (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();

  for (int i = file + 1, j = rank + 1;
       i <= 8 && j <= 8; ++i, ++j)
    {
      Move* move = new Move(Position ((Position::File) file,
				      (Position::Rank) rank),
			    Position ((Position::File) i,
				      (Position::Rank) j));
      if (p.is_valid_move (*move))
      {
	p.possibilities_get ().push_back (move);
      }
      else
	delete move;
      if (p.board_get ().map_board_get ()[i - 1][j - 1])
	return;
    }
}

void
PieceGetListVisitor::move_left_down (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();

  for (int i = file + 1, j = rank - 1;
       i <= 8 && j >= 1; ++i, --j)
    {
      Move* move = new Move(Position ((Position::File) file,
				      (Position::Rank) rank),
			    Position ((Position::File) i,
				      (Position::Rank) j));
      if (p.is_valid_move (*move))
      {
	p.possibilities_get ().push_back (move);
      }
      else
	delete move;
      if (p.board_get ().map_board_get ()[i - 1][j - 1])
	return;
    }
}

void
PieceGetListVisitor::move_right_up (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();

  for (int i = file - 1, j = rank + 1;
       i >= 1 && j <= 8; --i, ++j)
    {
      Move* move = new Move(Position ((Position::File) file,
				      (Position::Rank) rank),
			    Position ((Position::File) i,
				      (Position::Rank) j));
      if (p.is_valid_move (*move))
      {
	p.possibilities_get ().push_back (move);
      }
      else
	delete move;
      if (p.board_get ().map_board_get ()[i - 1][j - 1])
	return;
    }
}

void
PieceGetListVisitor::move_right_down (Piece& p)
{
  int rank = p.rank_get ();
  int file = p.file_get ();

  for (int i = file - 1, j = rank - 1;
       i >= 1 && j >= 1; --i, --j)
    {
      Move* move = new Move(Position ((Position::File) file,
				      (Position::Rank) rank),
			    Position ((Position::File) i,
				      (Position::Rank) j));
      if (p.is_valid_move (*move))
	{
	  p.possibilities_get ().push_back (move);
	}
	else
	  delete move;
      if (p.board_get ().map_board_get ()[i - 1][j - 1])
	return;
    }
}

void
PieceGetListVisitor::clear (std::list<Move *>& list)
{
  list.erase (list.begin (), list.end ());
}

void
PieceGetListVisitor::print (Piece& p, std::string str)
{
  for (std::list<Move*>::iterator it = p.possibilities_get ().begin ();
       it != p.possibilities_get ().end (); ++it)
  {
    std::cout << "Move " << str << p.color_get () << ": " << std::endl
	      << "     Start file" << (*it)->start_get ().file_get ()
	      << " rank: " << (*it)->start_get ().rank_get ();
    std::cout << std::endl
	      << "     End file: " << (*it)->end_get ().file_get ()
	      << " rank: " << (*it)->end_get ().rank_get ();
    std::cout << std::endl;
  }
}
