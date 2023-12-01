#ifndef PIECE_PRINT_VISITOR_HH_
# define PIECE_PRINT_VISITOR_HH_

# include "piece_visitor.hh"

class Queen;
class King;
class Pawn;
class Rook;
class Bishop;
class Knight;

class PiecePrintVisitor : public PieceVisitor
{
  public:
    virtual void visit (Queen& queen);
    virtual void visit (King& king);
    virtual void visit (Pawn& pawn);
    virtual void visit (Rook& rook);
    virtual void visit (Bishop& bishop);
    virtual void visit (Knight& knight);
};

#endif /* !PIECE_PRINT_VISITOR_HH_ */
