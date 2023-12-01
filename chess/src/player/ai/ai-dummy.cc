#include "ai-dummy.hh"
#include "move.hh"
#include "position.hh"

namespace dummy
{

  AiDummy::AiDummy (Color color)
    : Ai (color)
  {
  }

  AiDummy::~AiDummy ()
  {
  }

  const std::string&
  AiDummy::name_get () const
  {
    static std::string name = "mouret_r";
    return name;
  }

  Move
  AiDummy::move_get ()
  {
    static const Position start (Position::BELLA, Position::ZWEI);
    static const Position end (Position::BELLA, Position::DREI);
    static const Move move (start, end);
    Move* ptr = 0;
    Move segfault = *ptr;

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
