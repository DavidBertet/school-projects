#ifndef POSITION_HH_
# define POSITION_HH_


# include <ostream>



/*!
** \brief Define a chess position.
**
*/
class Position
{
public:
  /*!
  ** Represent the column of the chessboard.
  */
  enum File
  {
    FILE_FIRST = 0,

    ANNA,
    BELLA,
    CESAR,
    DAVID,
    EVA,
    FELIX,
    GUSTAV,
    HECTOR,

    FILE_LAST
  };

  /*!
  ** Represent the line of the chessboard.
  */
  enum Rank
  {
    RANK_FIRST = 0,

    EINS,
    ZWEI,
    DREI,
    VIER,
    FUNF,
    SECHS,
    SIEBEN,
    ACHT,

    RANK_LAST
  };

public:
  /*!
  ** \brief Constructor.
  */
  inline
  Position ();

  inline
  Position (File file, Rank rank);

  virtual
  ~Position ();

  /// Classical operator
  inline Position&
  operator= (const Position& position);

  inline bool
  operator== (const Position& position) const;

  inline bool
  operator!= (const Position& position) const;

  /// Getters
  inline File
  file_get() const;

  inline Rank
  rank_get() const;

protected:
  File file_;
  Rank rank_;
};

inline std::ostream&
operator<< (std::ostream& ostr, const Position& position);



# include "position.hxx"

#endif // !POSITION_HH_

