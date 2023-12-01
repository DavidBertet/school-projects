#ifndef PIECE_VISITOR_HH_
# define PIECE_VISITOR_HH_

class Queen;
class King;
class Pawn;
class Rook;
class Bishop;
class Knight;

class PieceVisitor
{
  public:
    virtual void visit (Queen& queen) = 0;
    virtual void visit (King& king) = 0;
    virtual void visit (Pawn& pawn) = 0;
    virtual void visit (Rook& rook) = 0;
    virtual void visit (Bishop& bishop) = 0;
    virtual void visit (Knight& knight) = 0;
};

#endif /* !PIECE_VISITOR_HH_ */
