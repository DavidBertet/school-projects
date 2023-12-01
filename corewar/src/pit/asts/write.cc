#include "write.hh"

void
Write::accept (Visitor& v)
{
  v (*this);
}

int
Write::rx_get ()
{
  return rx_;
}

void
Write::rx_set (int rx)
{
  rx_ = rx;
}
