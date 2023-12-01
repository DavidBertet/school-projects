#ifndef BISHOP_HH_
# define BISHOP_HH_

# include "piece.hh"

class Bishop : public Piece
{
  public:
    Bishop (Board& board,
	    Color color,
	    Position& position,
	    std::list<Listener*> list);
    virtual ~Bishop ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    virtual Piece* clone (Board& board);
  private:
    bool move_left_high (int filed, int file,
			 int ranked, int rank);

    bool move_left_down (int filed, int file,
			 int ranked, int rank);

    bool move_right_high (int filed, int file,
			  int ranked, int rank);

    bool move_right_down (int filed, int file,
			  int ranked, int rank);

};

#endif // !BISHOP_HH_
