#ifndef COMMON_PLAYER_HH_
# define COMMON_PLAYER_HH_

/// Chess game includes



# include "piece-type.hh"
# include "move.hh"
# include "color.hh"



/*!
** \brief Player interface.
**
** Player abstract class.
** Define the interface.
*/
class Player
{
public:

  Player (Color color);

  /*!
  ** \brief Destructor.
  */
  virtual
  ~Player ();

  /*!
  ** Set the last move played by the opponent.
  ** This method must be called at each turn of the chess game.
  */
  virtual void
  last_opponent_move_set (const Move& last_opponent_move);

  /*!
  ** Return the next move played by the Player
  */
  virtual Move
  move_get () = 0;

  Color
  color_get () const;

protected:
  /// Player color
  Color color_;
  Move last_opponent_move_;
};



#endif // !PLAYER_HH_
