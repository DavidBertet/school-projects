#include "myai.hh"
#include "move.hh"
#include "position.hh"
#include "piece-type.hh"
#include "piece.hh"
#include "board.hh"
#include <iostream>

namespace myai
{
  MyAI::MyAI (Color color)
    : Ai (color), board_ (std::list<Listener*> ())
  {
  }

  MyAI::~MyAI ()
  {
  }

  const std::string&
  MyAI::name_get () const
  {
    static std::string name = "a small ai";
    std::cout << "info start game" << std::endl;
    return name;
  }


  Move*
  MyAI::deplace ()
  {
    Position::File i;
    Position::Rank j;

    for (i = Position::ANNA; i < Position::FILE_LAST; ++i)
    {
      for (j = Position::EINS; j < Position::RANK_LAST; ++j)
      {
	if (board_.map_board_get ()[i - 1][j - 1] &&
	    board_.map_board_get ()[i - 1][j - 1]->color_get () ==
	    this->color_ && board_.map_board_get ()[i - 1][j - 1]
	    ->possibilities_get ().size ())
	{
	  for (std::list<Move*>::iterator it = board_.map_board_get ()
		 [i - 1][j - 1]->possibilities_get ().begin ();
	       it != board_.map_board_get ()[i - 1][j - 1]
		 ->possibilities_get ().end ();
	       ++it)
	  {
	    if (!board_.map_board_get ()[(*it)->end_get ().file_get () - 1]
		[(*it)->end_get ().rank_get () - 1])
	    {
	      std::cout << "add_deplace_"
			<< (*it)->start_get ().file_get () << "_"
			<< (*it)->start_get ().rank_get () << "_to_"
			<< (*it)->end_get ().file_get () << "_"
			<< (*it)->end_get ().rank_get () << std::endl;

	      list_deplace_.push_back (*it);
	    }
	  }

// 	  list_deplace_.push_back (board_.map_board_get ()[i - 1][j - 1]
// 				  ->possibilities_get ().back ());
	}
      }
    }

    return 0;
  }

  Move
  MyAI::move_get ()
  {
    list_capture_.clear ();
    list_deplace_.clear ();

    std::cout << "info move_get" << std::endl;
    std::cout << "move_get" << std::endl;
    for (Position::File i = Position::ANNA; i < Position::FILE_LAST; ++i)
    {
      for (Position::Rank j = Position::EINS; j < Position::RANK_LAST; ++j)
      {
	Piece* piece = board_.map_board_get ()[i - 1][j - 1];

	if (piece && board_[Position (i,j)].second == this->color_get ())
	{
	  std::cout << "info move piece" << std::endl;
	  is_capturable (piece);
	}
      }
    }

    deplace ();
    if (list_capture_.size ())
    {
      random_shuffle (list_capture_.begin (), list_capture_.end ());
      std::cout << "capture_move_is"
		<< list_capture_.back ()->start_get ().file_get () << "_"
		<< list_capture_.back ()->start_get ().rank_get () << "_to_"
		<< list_capture_.back ()->end_get ().file_get () << "_"
		<< list_capture_.back ()->end_get ().rank_get () << std::endl;
      board_.move (*list_capture_.back ());

      std::cout << "capture_ok" << std::endl;
      return *list_capture_.back ();
    }
    else
    {
      if (list_deplace_.size () == 0)
      {
	std::cout << "jsuis mort..." << std::endl;
	exit (0);
      }

      std::cout << "deplace_move" << std::endl;

      random_shuffle (list_deplace_.begin (), list_deplace_.end ());
      board_.move (*list_deplace_.back ());

      std::cout << "deplace_ok_" << list_deplace_.size () << std::endl;
      return *list_deplace_.back ();
    }
  }

  Move*
  MyAI::is_capturable (Piece *piece)
  {
    Position dest;

    std::cout << "info a piece is capturable " << std::endl;

    for (std::list<Move*>::iterator it = piece->possibilities_get ().begin ();
	 it != piece->possibilities_get ().end ();
	 ++it)
    {
      if (board_.map_board_get ()[(*it)->end_get ().file_get () - 1]
	  [(*it)->end_get ().rank_get () - 1])
      {
      std::cout << "add_capture_"
		<< (*it)->start_get ().file_get () << "_"
		<< (*it)->start_get ().rank_get () << "_to_"
		<< (*it)->end_get ().file_get () << "_"
		<< (*it)->end_get ().rank_get () << std::endl;

	list_capture_.push_back (*it);
      }
    }

    return 0;
  }


  void
  MyAI::last_opponent_move_set (const Move& last_move)
  {
    std::cout << "opponent_move" << std::endl;
    last_move_ = &last_move;
    std::cout << "info opponentmove " << std::endl;

    lmove_ = Move (last_move.start_get (), last_move.end_get (),
		       last_move.promotion_get ());

    board_.move (last_move);
    std::cout << "opponent_move_end" << std::endl;
  }
}

/// This macro allows us to use your AI.
/// So do not forget to call this macro.
AI_EXPORT(myai::MyAI)
