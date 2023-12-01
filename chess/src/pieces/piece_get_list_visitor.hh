#ifndef PIECE_GET_LIST_VISITOR_HH_
# define PIECE_GET_LIST_VISITOR_HH_

# include <list>
# include "move.hh"
# include "piece_visitor.hh"
# include "piece-type.hh"
# include "piece.hh"

class Piece;
class Queen;
class King;
class Pawn;
class Rook;
class Bishop;
class Knight;

class PieceGetListVisitor : public PieceVisitor
{
  public:
    virtual void visit (Queen& queen);
    virtual void visit (King& king);
    virtual void visit (Pawn& pawn);
    virtual void visit (Rook& rook);
    virtual void visit (Bishop& bishop);
    virtual void visit (Knight& knight);
  private:
    void move_up (Piece& p);
    void move_down (Piece& p);
    void move_right (Piece& p);
    void move_left (Piece& p);
    void move_left_up (Piece& p);
    void move_left_down (Piece& p);
    void move_right_up (Piece& p);
    void move_right_down (Piece& p);
    void move_piece (Piece& piece, int file_diff, int rank_diff,
		     PieceType type = NONE);
    void clear (std::list<Move *>& list);
    void print (Piece& p, std::string str);
};

#endif /* !PIECE_GET_LIST_VISITOR_HH_ */
