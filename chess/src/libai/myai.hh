#ifndef AI_DUMMY_HH_
# define AI_DUMMY_HH_

# include <vector>
# include "ai.hh"
# include "../board/board.hh"

namespace myai
{
  class MyAI : public Ai
  {

    public:

      /*!
      ** \brief Constructor.
      */
      MyAI (Color color = WHITE);

      /*!
      ** \brief Destructor.
      */
      virtual
      ~MyAI ();

      /*!
      ** \brief provides the last opponent move to the AI
      **
      */
      virtual void
      last_opponent_move_set (const Move& last_move);

      /*!
      ** \brief name getter
      ** @return Return the AI author name
      */
      virtual const std::string&
      name_get () const;

      /*!
      ** \brief Move getter.
      */
      virtual Move
      move_get ();
      Move* deplace ();
      Move* is_capturable (Piece* piece);
    protected:

      /// Last opponent move
      const Move *last_move_;
      Board	board_;
      Move lmove_;

      std::vector<Move*> list_capture_;
      std::vector<Move*> list_deplace_;
  };
}

#endif // !AI_DUMMY_HH_
