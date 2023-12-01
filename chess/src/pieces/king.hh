#ifndef KING_HH_
# define KING_HH_

# include "piece.hh"

class King : public Piece
{
  public:
    King (Board& board,
	  Color color,
	  Position& position,
	  std::list <Listener*> list);
    virtual ~King ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    bool is_echec_at_pos (Move move, Position pos);
    void castling_king ();
    void castling_queen ();
    void mov_cast_white_king ();
    void mov_cast_black_king ();
    void mov_cast_white_queen ();
    void mov_cast_black_queen ();

    virtual Piece* clone (Board& board);
    //--------//
    // GETTER //
    //--------//

    bool has_move_get ();

    //--------//
    // SETTER //
    //--------//

    void has_move_set (bool has_move);

  private:
    bool has_move_;
};

#endif // !KING_HH_
