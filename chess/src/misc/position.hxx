#include <cassert>



# define ASSERT_VALID_FILE(FILE)                \
  assert (Position::FILE_FIRST < FILE &&	\
          Position::FILE_LAST  > FILE)

# define ASSERT_VALID_RANK(RANK)		\
  assert (Position::RANK_FIRST < RANK &&	\
          Position::RANK_LAST  > RANK)

# define ASSERT_VALID_POSITION(POSITION)	\
  do                                            \
  {						\
    ASSERT_VALID_FILE(POSITION.file_get ());	\
    ASSERT_VALID_RANK(POSITION.rank_get ());	\
  } while (0)

inline
Position::Position (File file, Rank rank)
  : file_ (file),
    rank_ (rank)
{
}

inline
Position::Position ()
{
}

inline Position&
Position::operator= (const Position& position)
{
  ASSERT_VALID_FILE (position.file_);
  ASSERT_VALID_RANK (position.rank_);

  file_ = position.file_;
  rank_ = position.rank_;

  return *this;
}

inline bool
Position::operator== (const Position& position) const
{
  ASSERT_VALID_FILE (file_);
  ASSERT_VALID_RANK (rank_);
  ASSERT_VALID_FILE (position.file_);
  ASSERT_VALID_RANK (position.rank_);

  return file_ == position.file_ && rank_ == position.rank_;
}

inline bool
Position::operator!= (const Position& position) const
{
  return !operator== (position);
}

inline Position::File
Position::file_get () const
{
  ASSERT_VALID_FILE (file_);

  return file_;
}

inline Position::Rank
Position::rank_get () const
{
  ASSERT_VALID_RANK (rank_);
  return rank_;
}

inline Position::File
operator++ (Position::File& file)
{
  ASSERT_VALID_FILE (file);
  return file = static_cast<Position::File> (file + 1);
}

inline Position::File
operator-- (Position::File& file)
{
  ASSERT_VALID_FILE (file);
  return file = static_cast<Position::File> (file - 1);
}

inline Position::Rank
operator++ (Position::Rank& rank)
{
  ASSERT_VALID_RANK (rank);
  return rank = static_cast<Position::Rank> (rank + 1);
}

inline Position::Rank
operator-- (Position::Rank& rank)
{
  ASSERT_VALID_RANK (rank);
  return rank = static_cast<Position::Rank> (rank - 1);
}

inline std::ostream&
operator<< (std::ostream& ostr, const Position& position)
{
  return ostr << static_cast<char> ('a' - 1 + position.file_get ())
	      << position.rank_get ();
}



