#include "ai-dummy.hh"
#include "move.hh"
#include "position.hh"

namespace dummy
{

  AiDummy::AiDummy (Color color)
    : Ai (color)
  {
    this->color_ = color;
    this->turn_ = 0;
  }

  AiDummy::~AiDummy ()
  {
  }

  const std::string&
  AiDummy::name_get () const
  {
    static std::string name = "creff_n";
    return name;
  }

  Move
  AiDummy::move_get ()
  {
    Position* start;
    Position* end;

    if (this->color_ == WHITE)
    {
      if (this->turn_ == 0)
      {
	start = new Position (Position::GUSTAV, Position::ZWEI);
	end = new Position (Position::GUSTAV, Position::DREI);
      }
      else if (this->turn_ == 1)
      {
	start = new Position (Position::GUSTAV, Position::EINS);
	end = new Position (Position::FELIX, Position::DREI);
      }
      else if (this->turn_ == 2)
      {
	start = new Position (Position::DAVID, Position::ZWEI);
	end = new Position (Position::DAVID, Position::DREI);
      }
      else if (this->turn_ == 3)
      {
	start = new Position (Position::DAVID, Position::EINS);
	end = new Position (Position::DAVID, Position::ZWEI);
      }
      else if (this->turn_ == 4)
      {
	start = new Position (Position::BELLA, Position::ZWEI);
	end = new Position (Position::BELLA, Position::DREI);
      }
    }
    else
    {
      if (this->turn_ == 0)
      {
	start = new Position (Position::GUSTAV, Position::SIEBEN);
	end = new Position (Position::GUSTAV, Position::SECHS);
      }
      else if (this->turn_ == 1)
      {
	start = new Position (Position::GUSTAV, Position::ACHT);
	end = new Position (Position::FELIX, Position::SECHS);
      }
      else if (this->turn_ == 2)
      {
	start = new Position (Position::DAVID, Position::SIEBEN);
	end = new Position (Position::DAVID, Position::SECHS);
      }
      else if (this->turn_ == 3)
      {
	start = new Position (Position::DAVID, Position::ACHT);
	end = new Position (Position::DAVID, Position::SIEBEN);
      }
      else if (this->turn_ == 4)
      {
	start = new Position (Position::BELLA, Position::SIEBEN);
	end = new Position (Position::BELLA, Position::SECHS);
      }
    }

    this->turn_++;
    Move move (*start, *end);

    return move;
  }

  void
  AiDummy::last_opponent_move_set (const Move& last_move)
  {
    last_move_ = &last_move;
  }

}

/// This macro allows us to use your AI.
/// So do not forget to call this macro.
AI_EXPORT(dummy::AiDummy)
