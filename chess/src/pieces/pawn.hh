#ifndef PAWN_HH_
# define PAWN_HH_

# include "piece.hh"

class Pawn : public Piece
{
  public:
    Pawn (Board& board,
	  Color color,
	  Position& position,
	  std::list <Listener*> list);
    virtual ~Pawn ();

    virtual void accept (PieceVisitor* v);

    virtual bool is_valid_move (const Move& move, bool check = true);

    Piece* good_piece (PieceType type);
    virtual Piece* clone (Board& board);

  private:
};

#endif // !PAWN_HH_
