#include "bz.hh"

void
Bz::accept (Visitor& v)
{
  v (*this);
}

int
Bz::rx_get ()
{
  return rx_;
}

void
Bz::rx_set (int rx)
{
  rx_ = rx;
}
