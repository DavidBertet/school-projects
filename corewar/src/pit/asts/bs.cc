#include "bs.hh"

void
Bs::accept (Visitor& v)
{
  v (*this);
}

int
Bs::rx_get ()
{
  return rx_;
}

void
Bs::rx_set (int rx)
{
  rx_ = rx;
}
