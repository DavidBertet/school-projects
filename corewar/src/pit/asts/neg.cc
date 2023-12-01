#include "neg.hh"

void
Neg::accept (Visitor& v)
{
  v (*this);
}

int
Neg::rx_get ()
{
  return rx_;
}

int
Neg::ry_get ()
{
  return ry_;
}

void
Neg::rx_set (int rx)
{
  rx_ = rx;
}

void
Neg::ry_set (int ry)
{
  ry_ = ry;
}
