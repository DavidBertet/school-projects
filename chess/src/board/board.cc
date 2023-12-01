#include <utility>
#include <iostream>
#include <sstream>

#include "knight.hh"
#include "queen.hh"
#include "rook.hh"
#include "king.hh"
#include "pawn.hh"
#include "bishop.hh"

#include "piece_visitor.hh"
#include "piece_print_visitor.hh"
#include "piece_move_visitor.hh"
#include "piece_get_list_visitor.hh"

#include "use_listener.hh"

#include "board.hh"
#include "color.hh"
#include "piece-type.hh"
#include "position.hh"
#include "move_error.hh"
#include "error.hh"

Board::Board ()
{
}

Board::Board  (std::list<Listener*> list_listener)
{
  list_listener_ = list_listener;

  init_board (list_listener);

  refresh_list_move ();
}

Board::Board  (std::list<Listener*> list_listener,
	       bool nothing)
{
  list_listener_ = list_listener;
  (void) nothing;
}

Board::~Board ()
{
}

void
Board::init_board (std::list<Listener*> list)
{
  echec_[BLACK] = false;
  echec_[WHITE] = false;

  for (int i = 0; i < 8; ++i)
  {
    v_pieces_type* v_pieces = new v_pieces_type;
    for (int j = 0; j < 8; ++j)
    {
      v_pieces->push_back (0);
    }
    map_board_.push_back (*v_pieces);
  }

  map_board_[0][0] = new Rook (*this, WHITE,
			       *new Position (Position::ANNA,
					      Position::EINS), list);
  map_board_[1][0] = new Knight (*this, WHITE,
				 *new Position (Position::BELLA,
						Position::EINS), list);
  map_board_[2][0] = new Bishop (*this, WHITE,
				 *new Position (Position::CESAR,
						Position::EINS), list);
  map_board_[3][0] = new Queen (*this, WHITE,
				*new Position (Position::DAVID,
					       Position::EINS), list);
  map_board_[4][0] = new King (*this, WHITE,
			       *new Position (Position::EVA,
					      Position::EINS), list);
  king_[WHITE] = map_board_[4][0];
  map_board_[5][0] = new Bishop (*this, WHITE,
				 *new Position (Position::FELIX,
						Position::EINS), list);
  map_board_[6][0] = new Knight (*this, WHITE,
				 *new Position (Position::GUSTAV,
						Position::EINS), list);
  map_board_[7][0] = new Rook (*this, WHITE,
			       *new Position (Position::HECTOR,
					      Position::EINS), list);

  init_board2 (list);
  init_board3 (list);
}


void
Board::init_board2 (std::list<Listener*> list)
{
  map_board_[0][1] = new Pawn (*this, WHITE,
			       *new Position (Position::ANNA,
					      Position::ZWEI), list);
  map_board_[1][1] = new Pawn (*this, WHITE,
			       *new Position (Position::BELLA,
					      Position::ZWEI), list);
  map_board_[2][1] = new Pawn (*this, WHITE,
			       *new Position (Position::CESAR,
					      Position::ZWEI), list);
  map_board_[3][1] = new Pawn (*this, WHITE,
			       *new Position (Position::DAVID,
					      Position::ZWEI), list);
  map_board_[4][1] = new Pawn (*this, WHITE,
			       *new Position (Position::EVA,
					      Position::ZWEI), list);
  map_board_[5][1] = new Pawn (*this, WHITE,
			       *new Position (Position::FELIX,
					      Position::ZWEI), list);
  map_board_[6][1] = new Pawn (*this, WHITE,
			       *new Position (Position::GUSTAV,
					      Position::ZWEI), list);
  map_board_[7][1] = new Pawn (*this, WHITE,
			       *new Position (Position::HECTOR,
					      Position::ZWEI), list);
  map_board_[0][7] = new Rook (*this, BLACK,
			       *new Position (Position::ANNA,
					      Position::ACHT), list);
  map_board_[1][7] = new Knight (*this, BLACK,
				 *new Position (Position::BELLA,
						Position::ACHT), list);
}

void
Board::init_board3 (std::list<Listener*> list)
{
  map_board_[2][7] = new Bishop (*this, BLACK,
				 *new Position (Position::CESAR,
						Position::ACHT), list);
  map_board_[3][7] = new Queen (*this, BLACK,
				*new Position (Position::DAVID,
					       Position::ACHT), list);
  map_board_[4][7] = new King (*this, BLACK,
			       *new Position (Position::EVA,
					      Position::ACHT), list);
  king_[BLACK] = map_board_[4][7];
  map_board_[5][7] = new Bishop (*this, BLACK,
				 *new Position (Position::FELIX,
						Position::ACHT), list);
  map_board_[6][7] = new Knight (*this, BLACK,
				 *new Position (Position::GUSTAV,
						Position::ACHT), list);
  map_board_[7][7] = new Rook (*this, BLACK,
			       *new Position (Position::HECTOR,
					      Position::ACHT), list);

  map_board_[0][6] = new Pawn (*this, BLACK,
			       *new Position (Position::ANNA,
					      Position::SIEBEN), list);
  map_board_[1][6] = new Pawn (*this, BLACK,
			       *new Position (Position::BELLA,
					      Position::SIEBEN), list);
  map_board_[2][6] = new Pawn (*this, BLACK,
			       *new Position (Position::CESAR,
					      Position::SIEBEN), list);
  map_board_[3][6] = new Pawn (*this, BLACK,
			       *new Position (Position::DAVID,
					      Position::SIEBEN), list);
  map_board_[4][6] = new Pawn (*this, BLACK,
			       *new Position (Position::EVA,
					      Position::SIEBEN), list);
  map_board_[5][6] = new Pawn (*this, BLACK,
			       *new Position (Position::FELIX,
					      Position::SIEBEN), list);
  map_board_[6][6] = new Pawn (*this, BLACK,
			       *new Position (Position::GUSTAV,
					      Position::SIEBEN), list);
  map_board_[7][6] = new Pawn (*this, BLACK,
			       *new Position (Position::HECTOR,
					      Position::SIEBEN), list);
}

void
Board::castling_king (Color color)
{
  if (color == WHITE &&
      map_board_[4][0] != 0 &&
      map_board_[4][0]->piece_type_get () == KING)
  {
    King* king = dynamic_cast<King*> (map_board_[4][0]);
    assert (king != 0);
    king->castling_king ();
  }
  else if (color == BLACK &&
	   map_board_[4][7] != 0 &&
	   map_board_[4][7]->piece_type_get () == KING)
  {
    King* king = dynamic_cast<King*> (map_board_[4][7]);
    assert (king != 0);
    king->castling_king ();
  }
  else
    throw error::MoveError ("castling impossible");
}

void
Board::castling_queen (Color color)
{
  if (color == WHITE &&
      map_board_[4][0] != 0 &&
      map_board_[4][0]->piece_type_get () == KING)
  {
    King* king = dynamic_cast<King*> (map_board_[4][0]);
    assert (king != 0);
    king->castling_queen ();
  }
  else if (color == BLACK &&
	   map_board_[4][7] != 0 &&
	   map_board_[4][7]->piece_type_get () == KING)
  {
    King* king = dynamic_cast<King*> (map_board_[4][7]);
    assert (king != 0);
    king->castling_queen ();
  }
  else
    throw error::MoveError ("castling impossible");
}

bool
Board::test_echec (MovePGN& movepgn, Color color)
{
  Move move_echec (movepgn.dest_get (),
		   Position (king_[!color]->file_get (),
			     king_[!color]->rank_get ()));

  if (map_board_[movepgn.dest_get ().file_get () - 1]
      [movepgn.dest_get ().rank_get () - 1]->is_valid_move (move_echec))
  {
    King *king = dynamic_cast<King*> (king_[!color]);
    if (!king)
      throw error::Error ("Problem, king is not a king... board.cc");

    test_echec_mat (color, king);

    return true;
  }
  if (movepgn.echec_get ())
    throw error::Error ("There is a wrong echec in the file");

  return false;
}

bool
Board::test_echec_mat (Color color, King* king)
{
  king = king;

  int possibilities = 0;

  for (int i = Position::FILE_FIRST; i < Position::FILE_LAST - 1; ++i)
  {
    for (int j = Position::RANK_FIRST; j < Position::RANK_LAST - 1; ++j)
    {
      if (map_board_[i][j] && map_board_[i][j]->color_get () == color)
      {
	possibilities += map_board_[i][j]->possibilities_get ().size ();
      }
    }
  }


  if (!possibilities)
  {
    //listener on_player_mat
    on_player_mat (list_listener_, (Color) !color);

    return true;
  }
  else
  {
    //listener on_player_check
    on_player_check (list_listener_, (Color) !color);

    return false;
  }
}

void
Board::finish_on_error (MovePGN& movepgn, Color color)
{
  //listener on_player_disqualified
  on_player_disqualified (list_listener_, color);

  std::string type[6] = {"king", "queen", "rook", "bishop", "knight", "pawn"};
  std::string color_tab[2] = {"white", "black"};
  std::stringstream ss;
  ss << "invalid move inside pgn: " << type[movepgn.typepiece_get ()]
     << " of color " << color_tab[color] << " at pos file: "
     << movepgn.dest_get ().file_get () << " rank: "
     << movepgn.dest_get ().rank_get ();
  throw error::Error (ss.str ());
}

void
Board::move (const Move& move)
{
  Position::File start_file = move.start_get ().file_get ();
  Position::Rank start_rank = move.start_get ().rank_get ();

  if (map_board_[start_file - 1][start_rank - 1])
  {
    PieceMoveVisitor visitor(move);
    map_board_[start_file - 1][start_rank - 1]->accept (&visitor);

    refresh_list_move ();
  }
}

void
Board:: move_pgn (MovePGN& movepgn, Color color)
{
  // is it a kingside castling?
  if (movepgn.typemove_get () == ROQUE)
  {
    castling_king (color);
    return;
  }
  // is it a queenside castling?
  if (movepgn.typemove_get () == GROQUE)
  {
    castling_queen (color);
    return;
  }
  //for each case on the board
  for (int i = Position::FILE_FIRST; i < Position::FILE_LAST - 1; ++i)
  {
    for (int j = Position::RANK_FIRST; j < Position::RANK_LAST - 1; ++j)
    {
      //if there is a bad piece type on this case, continue to the next one
      if (!map_board_[i][j])
	continue;
      if (map_board_[i][j]->color_get () != color ||
          map_board_[i][j]->piece_type_get () != movepgn.typepiece_get ())
	continue;
      //ambigous move
      if (movepgn.ambRank_get () &&
	  movepgn.ambRank_get () != map_board_[i][j]->rank_get ())
	continue;
      if (movepgn.ambFile_get () &&
	  movepgn.ambFile_get () != map_board_[i][j]->file_get ())
	continue;

      Move move (Position (map_board_[i][j]->file_get (),
			   map_board_[i][j]->rank_get ()),
		 movepgn.dest_get ());
      try
      {
	this->move (move);
      }
      catch (...)
      {
	continue;
      }

      test_echec (movepgn, color);
      return;
    }
  }

  finish_on_error (movepgn, color);
}

std::pair<const PieceType, const Color>
Board::operator[] (const Position& position) const
{
  if (!map_board_[position.file_get () - 1][position.rank_get () - 1])
    return std::pair<const PieceType, const Color> (NONE, BLACK);

  PieceType type =
    map_board_[position.file_get () - 1][position.rank_get () - 1]->
    piece_type_get ();

  Color color =
    map_board_[position.file_get () - 1][position.rank_get () - 1]->
    color_get ();

  return std::pair<const PieceType, const Color> (type, color);
}

void
Board::refresh_list_move ()
{
  PieceGetListVisitor visit;

  for (int i = Position::FILE_FIRST; i < Position::FILE_LAST - 1; ++i)
  {
    for (int j = Position::RANK_FIRST; j < Position::RANK_LAST - 1; ++j)
    {
      if (map_board_[i][j])
	map_board_[i][j]->accept(&visit);
    }
  }
}

void
Board::print ()
{
  PiecePrintVisitor visitor;

  //Print header
  std::cout << "info  ";
  for (int i = 0; i < Position::FILE_LAST - 1; ++i)
  {
    char c = 'A' + i;
    std::cout << "| " << c;
  }
  std::cout << "|" << std::endl;

  //Print content
  for (int i = Position::FILE_LAST - 2; i >= 0; --i)
  {
    std::cout << "info ---------------------------" << std::endl;
    std::cout << "info " << i + 1;
    for (int j = 0;  j < Position::RANK_LAST - 1; ++j)
    {
      if (this->map_board_[j][i])
      {
	std::cout << "|";
	this->map_board_[j][i]->accept (&visitor);
      }
      else
	std::cout << "|" << "  ";
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "info ---------------------------" << std::endl;
}

Board*
Board::clone ()
{
  Board* b = new Board (this->list_listener_, true);
  b->echec_set (this->echec_[0],
		this->echec_[1]);
  for (int i = Position::FILE_FIRST; i < Position::FILE_LAST - 1; ++i)
  {
    for (int j = Position::RANK_FIRST; j < Position::RANK_LAST - 1; ++j)
    {
      if (map_board_[i][j])
      {
	b->map_board_get ()[i][j] = map_board_[i][j]->clone (*b);

	King* king = dynamic_cast<King*> (map_board_[i][j]);
	if (king)
	  b->king_set (b->map_board_get ()[i][j],
		       b->map_board_get ()[i][j]->color_get ());
      }
    }
  }
  b->refresh_list_move ();
  return b;
}

  ////////////
  // GETTER //
  ////////////

std::vector<v_pieces_type>&
Board::map_board_get ()
{
  return map_board_;
}

King*
Board::king_get (int color)
{
  return dynamic_cast<King*> (king_[color]);
}

////////////
// SETTER //
////////////
void
Board::echec_set (bool echec_white,
		  bool echec_black)
{
  this->echec_[0] = echec_white;
  this->echec_[1] = echec_black;
}

void
Board::king_set (Piece* p, Color color)
{
  this->king_[(int)color] = p;
}
