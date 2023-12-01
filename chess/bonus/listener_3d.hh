#ifndef D_LISTENER_HH_
# define D_LISTENER_HH_

// Standard include
# include <string>
# include <vector>

// Chess game includes
# include "listener.hh"
# include "color.hh"
# include "piece-type.hh"
# include "position.hh"
// 3D include
# include "textures.hh"

class ChessboardAdapter;

class Listener3D : public Listener
{
  public:
    /*!
    ** \brief Register the ChessboardAdapter for later use.
    ** Called once per game at the beginning
    **
    ** @param chessboard_adapter: The chessboard adapter
    */
    void register_chessboard_adapter (const ChessboardAdapter& chessboard_adapter);

    /*!
    ** \brief Event when the game starts
    */
    void on_game_started ();

    /*!
    ** \brief Event when the game finishes
    ** No more event happens after it
    */
    void on_game_finished ();

    /*!
    ** \brief Event when a piece is moved
    ** @param piece: The moved piece
    ** @param from:  The initial position of the piece (before the move)
    ** @param to:    The final position of the piece (after the move)
    */
    void on_piece_moved (const PieceType& piece, const Position& from, const Position& to);

    /*!
    ** \brief Event when a piece is taken
    ** Called before the associated move
    ** @param piece: The taken piece
    ** @param at:    The position where the piece is taken
    */
    void on_piece_taken (const PieceType& piece, const Position& at);

    /*!
    ** \brief Event when a piece is promoted
    ** @param piece: The choosen promotion
    ** @param at:    The position of the piece promoted
    */
    void on_piece_promoted (const PieceType& piece, const Position& at);

    /*!
    ** \brief Event when a kingside castling happens
    ** Called before the associated moves
    ** @param color: The color of the player concerned by the castling
    */
    void on_kingside_castling (const Color& color);

    /*!
    ** \brief Event when a queenside castling happens
    ** Called before the associated moves
    ** @param color: The color of the player concerned by the castling
    */
    void on_queenside_castling (const Color& color);

    /*!
    ** \brief Event when a king is in check
    ** Called after the move that made it in check
    ** @param color: The color of the player whose king is in check
    */
    void on_player_check (const Color& color);

    /*!
    ** \brief Event when a king is checkmate
    ** Called after the move that made it checkmate
    ** @param color: The color of the player whose king is checkmate
    */
    void on_player_mat (const Color& color);

    /*!
    ** \brief Event when a player is pat
    ** Called after the move that made it pat
    ** @param color: The color of the player who's pat
    */
    void on_player_pat (const Color& color);

    /*!
    ** \brief Event when a player took too much time
    ** Call is not required
    ** @param color: The color of the player who took too much time
    */
    void on_player_timeout (const Color& color);

    /*!
    ** \brief Event when a player is disqualified
    ** Call is not required
    ** @param color: The color of the player who is disqualified
    */
    void on_player_disqualified (const Color& color);

    /*!
    ** \brief Event when there is a draw game
    */
    void on_draw ();

    const ChessboardAdapter* chessboardAdapter_;
    std::vector<s_texture_image*> tab_;
};

#endif /* !D_LISTENER_HH_ */
