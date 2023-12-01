#include "bnz.hh"

void
Bnz::accept (Visitor& v)
{
  v (*this);
}

int
Bnz::rx_get ()
{
  return rx_;
}

void
Bnz::rx_set (int rx)
{
  rx_ = rx;
}
