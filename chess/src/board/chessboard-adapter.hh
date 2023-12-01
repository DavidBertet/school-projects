#ifndef COMMON_CHESSBOARD_ADAPTER_HH_
# define COMMON_CHESSBOARD_ADAPTER_HH_

# include <utility>

# include "piece-type.hh"
# include "color.hh"



/// Forward declaration.
class Position;

/*!
** \brief Interface of the chessboard
*/
class ChessboardAdapter
{
public:
  /*!
  ** Destructor
  **
  */
  virtual
  ~ChessboardAdapter();

  /*!
  ** Acces operator
  **
  ** @param position Position accessed on the chessboard
  */
  virtual std::pair<const PieceType, const Color>
  operator[] (const Position& position) const = 0;
};



#endif // !COMMON_CHESSBOARD_ADAPTER_HH_
