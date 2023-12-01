#include "b.hh"

void
B::accept (Visitor& v)
{
  v (*this);
}

int
B::rx_get ()
{
  return rx_;
}

void
B::rx_set (int rx)
{
  rx_ = rx;
}
