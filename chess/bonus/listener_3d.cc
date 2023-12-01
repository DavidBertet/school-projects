#include "SDL/SDL.h"
#include "init_sdl.hh"
#include "draw.hh"
#include "textures.hh"
#include "listener_3d.hh"
#include "chessboard-adapter.hh"

// Standard include
#include <string>

// Chess game includes
#include "color.hh"
#include "piece-type.hh"
#include "position.hh"

/*!
** \brief Register the ChessboardAdapter for later use.
** Called once per game at the beginning
**
** @param chessboard_adapter: The chessboard adapter
*/
void
Listener3D::register_chessboard_adapter (const ChessboardAdapter&
    chessboard_adapter)
{
  this->chessboardAdapter_ = &chessboard_adapter;
}

/*!
** @brief on_game_started
** Event when the game starts
*/
void
Listener3D::on_game_started ()
{
  init_sdl();

  load_textures (tab_);

  /* IMPORTANT ! */
  draw_all(tab_, *chessboardAdapter_);
}

/*!
** \brief Event when the game finishes
** No more event happens after it
*/
void
Listener3D::on_game_finished ()
{
  SDL_Quit();
}

/*!
** \brief Event when a piece is moved
** @param piece: The moved piece
** @param from:  The initial position of the piece (before the move)
** @param to:    The final position of the piece (after the move)
*/
void
Listener3D::on_piece_moved (const PieceType& piece, const Position& from, const
    Position& to)
{
  (void) piece;
  (void) from;
  (void) to;

  /* IMPORTANT ! */
  draw_all(tab_, *chessboardAdapter_);
}

/*!
** \brief Event when a piece is taken
** Called before the associated move
** @param piece: The taken piece
** @param at:    The position where the piece is taken
*/
void
Listener3D::on_piece_taken (const PieceType& piece, const Position& at)
{
  (void) piece;
  (void) at;
}

/*!
** \brief Event when a piece is promoted
** @param piece: The choosen promotion
** @param at:    The position of the piece promoted
*/
void
Listener3D::on_piece_promoted (const PieceType& piece, const Position& at)
{
  (void) piece;
  (void) at;
}

/*!
** \brief Event when a kingside castling happens
** Called before the associated moves
** @param color: The color of the player concerned by the castling
*/
void
Listener3D::on_kingside_castling (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a queenside castling happens
** Called before the associated moves
** @param color: The color of the player concerned by the castling
*/
void
Listener3D::on_queenside_castling (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a king is in check
** Called after the move that made it in check
** @param color: The color of the player whose king is in check
*/
void
Listener3D::on_player_check (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a king is checkmate
** Called after the move that made it checkmate
** @param color: The color of the player whose king is checkmate
*/
void
Listener3D::on_player_mat (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a player is pat
** Called after the move that made it pat
** @param color: The color of the player who's pat
*/
void
Listener3D::on_player_pat (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a player took too much time
** Call is not required
** @param color: The color of the player who took too much time
*/
void
Listener3D::on_player_timeout (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when a player is disqualified
** Call is not required
** @param color: The color of the player who is disqualified
*/
void
Listener3D::on_player_disqualified (const Color& color)
{
  (void) color;
}

/*!
** \brief Event when there is a draw game
*/
void
Listener3D::on_draw ()
{
}
