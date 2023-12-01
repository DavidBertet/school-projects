#ifndef ROOK_HH_
# define ROOK_HH_

# include "piece.hh"

class Rook : public Piece
{
  public:
    Rook (Board& board,
	  Color color,
	  Position& position,
	  std::list <Listener*> list);
    virtual ~Rook ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    //--------//
    // GETTER //
    //--------//

    bool has_move_get ();

    //--------//
    // SETTER //
    //--------//

    void has_move_set (bool has_move);

    virtual Piece* clone (Board& board);
  private:
    bool move_high (int filed, int file,
		    int ranked, int rank);

    bool move_down (int filed, int file,
		    int ranked, int rank);

    bool move_right (int filed, int file,
		    int ranked, int rank);

    bool move_left (int filed, int file,
		    int ranked, int rank);
    bool has_move_;
};

#endif // !ROOK_HH_
