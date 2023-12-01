#ifndef QUEEN_HH_
# define QUEEN_HH_

# include "piece.hh"

class Queen : public Piece
{
  public:
    Queen (Board& board,
	   Color color,
	   Position& position,
	   std::list <Listener*> list);
    virtual ~Queen ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    virtual  Piece* clone (Board& board);
  private:
    bool move_high (int filed, int file,
		    int ranked, int rank);

    bool move_down (int filed, int file,
		    int ranked, int rank);

    bool move_right (int filed, int file,
		    int ranked, int rank);

    bool move_left (int filed, int file,
		    int ranked, int rank);

    bool move_left_high (int filed, int file,
			 int ranked, int rank);

    bool move_left_down (int filed, int file,
			 int ranked, int rank);

    bool move_right_high (int filed, int file,
			  int ranked, int rank);

    bool move_right_down (int filed, int file,
			  int ranked, int rank);
};

#endif // !QUEEN_HH_
