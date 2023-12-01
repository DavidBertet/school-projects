#ifndef PIECE_MOVE_VISITOR_HH_
# define PIECE_MOVE_VISITOR_HH_

# include "piece_visitor.hh"

class Move;
class Queen;
class King;
class Pawn;
class Rook;
class Bishop;
class Knight;

class PieceMoveVisitor : public PieceVisitor
{
  public:
    PieceMoveVisitor (const Move& move);

    virtual void visit (Queen& queen);
    virtual void visit (King& king);
    virtual void visit (Pawn& pawn);
    virtual void visit (Rook& rook);
    virtual void visit (Bishop& bishop);
    virtual void visit (Knight& knight);

  private:
    const Move& move_;
};

#endif /* !PIECE_MOVE_VISITOR_HH_ */
