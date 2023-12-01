#ifndef COMMON_LISTENER_HH_
# define COMMON_LISTENER_HH_

// Standard include
# include <string>

// Chess game includes
# include "color.hh"
# include "piece-type.hh"
# include "position.hh"



// Call order:
// register_chessboard_adatper
// game_started
//
// (
//   (
//     on_piece_taken?
//     (
//       (
//         on_{queen,king}side_castling
//         on_piece_moved /* king move */
//         on_piece_moved /* rook */
//       )? |
//       on_piece_moved
//     )
//     on_piece_promoted?
//     (
//       on_player_mat |
//       on_player_check |
//       on_player_pat on_draw
//     )?
//   ) |
//   on_draw |
//   on_player_disqualified |
//   on_player_timeout
// )+
//
// on_game_finished


class ChessboardAdapter;

/*!
** \brief Listener interface
**
** Listener abstract class.
** Define the interface.
** A listener is a part of the Observer design pattern
*/
class Listener
{
public:

  /*!
  ** \brief Destructor.
  */
  virtual
  ~Listener ();

  /*!
  ** \brief Register the ChessboardAdapter for later use.
  ** Called once per game at the beginning
  **
  ** @param chessboard_adapter: The chessboard adapter
  */
  virtual void
  register_chessboard_adapter
  (const ChessboardAdapter& chessboard_adapter) = 0;

  /*!
  ** \brief Event when the game starts
  */
  virtual void
  on_game_started () = 0;

  /*!
  ** \brief Event when the game finishes
  ** No more event happens after it
  */
  virtual void
  on_game_finished () = 0;

  /*!
  ** \brief Event when a piece is moved
  ** @param piece: The moved piece
  ** @param from:  The initial position of the piece (before the move)
  ** @param to:    The final position of the piece (after the move)
  */
  virtual void
  on_piece_moved
  (const PieceType& piece, const Position& from, const Position& to) = 0;

  /*!
  ** \brief Event when a piece is taken
  ** Called before the associated move
  ** @param piece: The taken piece
  ** @param at:    The position where the piece is taken
  */
  virtual void
  on_piece_taken (const PieceType& piece, const Position& at) = 0;

  /*!
  ** \brief Event when a piece is promoted
  ** @param piece: The choosen promotion
  ** @param at:    The position of the piece promoted
  */
  virtual void
  on_piece_promoted (const PieceType& piece, const Position& at) = 0;

  /*!
  ** \brief Event when a kingside castling happens
  ** Called before the associated moves
  ** @param color: The color of the player concerned by the castling
  */
  virtual void
  on_kingside_castling (const Color& color) = 0;

  /*!
  ** \brief Event when a queenside castling happens
  ** Called before the associated moves
  ** @param color: The color of the player concerned by the castling
  */
  virtual void
  on_queenside_castling (const Color& color) = 0;

  /*!
  ** \brief Event when a king is in check
  ** Called after the move that made it in check
  ** @param color: The color of the player whose king is in check
  */
  virtual void
  on_player_check (const Color& color) = 0;

  /*!
  ** \brief Event when a king is checkmate
  ** Called after the move that made it checkmate
  ** @param color: The color of the player whose king is checkmate
  */
  virtual void
  on_player_mat (const Color& color) = 0;

  /*!
  ** \brief Event when a player is pat
  ** Called after the move that made it pat
  ** @param color: The color of the player who's pat
  */
  virtual void
  on_player_pat (const Color& color) = 0;

  /*!
  ** \brief Event when a player took too much time
  ** Call is not required
  ** @param color: The color of the player who took too much time
  */
  virtual void
  on_player_timeout (const Color& color) = 0;

  /*!
  ** \brief Event when a player is disqualified
  ** Call is not required
  ** @param color: The color of the player who is disqualified
  */
  virtual void
  on_player_disqualified (const Color& color) = 0;

  /*!
  ** \brief Event when there is a draw game
  */
  virtual void
  on_draw () = 0;
};

struct ListenerExport
{
  Listener* (*create) ();
  std::string name;
};





# define LISTENER_EXPORT(NAME, NEW)             \
  static Listener* listener_create ()	\
  {						\
    return NEW;					\
  }						\
                                                \
  ListenerExport listener_plugin =         \
  {	                                        \
    listener_create,				\
    NAME 					\
  }

#endif // !COMMON_LISTENER_HH_

