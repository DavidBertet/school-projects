#ifndef COMMON_MOVE_HH_
# define COMMON_MOVE_HH_

# include "position.hh"
# include "piece-type.hh"



/*!
** \brief This class represents a piece move.
** A rock move is represented by the mouvement of the king.
** The move of the rook is implicit, it is bound to the king move.
*/
class Move
{
  public:
    Move ();

    /*!
    ** Constructor.
    */
    Move (const Position& initial, const Position& final,
          PieceType promotion = NONE);

    // Getter
    const Position&
    start_get () const;

    const Position&
    end_get () const;

    PieceType
    promotion_get () const;

    inline bool
    operator== (const Move& move) const;

  private:
    Position    initial_;
    Position    final_;
    PieceType   promotion_;
};

inline std::ostream&
operator << (std::ostream& ostr, const Move& move);



# include "move.hxx"

#endif // !COMMON_MOVE_HH_

