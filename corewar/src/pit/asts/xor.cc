#include "xor.hh"

void
Xor::accept (Visitor& v)
{
  v (*this);
}

int
Xor::rx_get ()
{
  return rx_;
}

int
Xor::ry_get ()
{
  return ry_;
}

void
Xor::rx_set (int rx)
{
  rx_ = rx;
}

void
Xor::ry_set (int ry)
{
  ry_ = ry;
}
