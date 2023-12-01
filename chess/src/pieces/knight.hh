#ifndef KNIGHT_HH_
# define KNIGHT_HH_

# include "piece.hh"

class Knight : public Piece
{
  public:
    Knight (Board& board,
	    Color color,
	    Position& position,
	    std::list <Listener*> list);
    virtual ~Knight ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    virtual Piece* clone (Board& board);
  private:
};

#endif // !KNIGHT_HH_
