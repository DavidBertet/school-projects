#define ASSERT_VALID_MOVE(MOVE)                 \
  do                                            \
  {                                             \
    ASSERT_VALID_POSITION((MOVE).start_get ()); \
    ASSERT_VALID_POSITION((MOVE).end_get ());   \
  } while (0)



inline bool
Move::operator== (const Move& move) const
{
  return initial_ == move.start_get () && final_ == move.end_get ();
}

inline std::ostream&
operator<< (std::ostream& ostr, const Move& move)
{
  return ostr << "[" << move.start_get () << " -> " << move.end_get () << "]";
}


