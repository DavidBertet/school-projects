#ifndef BOARD_HH_
# define BOARD_HH_

# include <vector>
# include <list>
# include "chessboard-adapter.hh"
# include "movepgn.hh"
# include "move.hh"
# include "../listener/loadlistener.hh"

// Forward declaration.
class King;

class Piece;
typedef std::vector<Piece*> v_pieces_type;

class Board : public ChessboardAdapter
{
  public:

    /////////////////
    // Ctor & Dtor //
    /////////////////

    Board (std::list<Listener*> list);
    Board (std::list<Listener*> list, bool nothing);
    Board ();
    ~Board ();

    /////////////
    // METHODE //
    /////////////

    /// @brief move
    /// move a piece
    void move (const Move& move);

    /// @brief init_board initialize the map.
    void init_board (std::list<Listener*> list);

    /// @brief init_board2 initialize the map.
    void init_board2 (std::list<Listener*> list);
    /// @brief init_board2 initialize the map.
    void init_board3 (std::list<Listener*> list);
    /*!
    ** @brief move_pgn Movement for png file
    ** @param movepgn A movement contain inside the PGN file
    ** @param color It is the color of the piece moved.
    */
    void move_pgn (MovePGN& movepgn, Color color);

    /// @brief castling_king call a castling.
    /// @param color of the king.
    void castling_king (Color color);

    /// @brief castling_queen call a castling.
    /// @param color of the king.
    void castling_queen (Color color);

    ///
    /// Acces operator
    ///
    /// @param position Position accessed on the chessboard
    ///
    virtual std::pair<const PieceType, const Color>
    operator[] (const Position& position) const;


    /*!
    ** @brief test_echec test echec
    **
    ** @param movepgn
    ** @param color
    **
    ** @return bool
    */
    bool test_echec (MovePGN& movepgn, Color color);

    /*!
    ** @brief test_echec_mat test echec and mat
    **
    ** @param color
    ** @param king
    **
    ** @return bool
    */
    bool test_echec_mat (Color color, King* king);

    void finish_on_error (MovePGN& movepgn, Color color);

    void refresh_list_move ();

    /*!
    ** Print the board for debug
    **
    */
    void print ();

    Board* clone ();
    ////////////
    // GETTER //
    ////////////
    King* king_get (int color);

    std::vector<v_pieces_type>& map_board_get ();

    ////////////
    // SETTER //
    ////////////
    void echec_set (bool echec_white,
		    bool echec_black);
    void king_set (Piece* p, Color color);

  private:
    std::vector<v_pieces_type> map_board_;
    std::list<Listener*> list_listener_;

    Piece* king_[2];
    bool echec_[2];
};

#endif /* !BOARD_HH_ */
