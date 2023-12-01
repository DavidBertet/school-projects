#ifndef PIECE_HH_
# define PIECE_HH_

# include "board.hh"
# include "position.hh"
# include "color.hh"
# include "move.hh"
# include "piece-type.hh"
# include "listener.hh"

class PieceVisitor;

class Piece
{
  public:
    Piece (Board& board,
	   Color color,
	   Position& position,
	   std::list<Listener*> list);
    virtual ~Piece ();

    virtual void accept (PieceVisitor* v) = 0;

    virtual bool is_valid_move (const Move& move, bool check = true) = 0;

    bool is_good_move (const Move& piece);
    bool no_check_after_move (Move& piece);

    //--------//
    // GETTER //
    //--------//

    Color color_get () const;
    PieceType piece_type_get () const;
    Position::File file_get () const;
    Position::Rank rank_get () const;
    Board& board_get () const;
    std::list<Listener*>& list_listener_get ();
    std::list<Move*>& possibilities_get ();

    //--------//
    // SETTER //
    //--------//

    void file_set (Position::File file);
    void rank_set (Position::Rank rank);

    void possibilities_set (std::list<Move*>& l);

    virtual Piece* clone (Board& board) = 0;

  protected:
    Board& board_;
    Color color_;
    PieceType piece_type_;
    Position::File file_;
    Position::Rank rank_;
    std::list<Listener*> list_;
    std::list<Move*> possibilities_;
};

#endif // !PIECE_HH_
