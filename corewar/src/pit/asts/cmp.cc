#include "cmp.hh"

void
Cmp::accept (Visitor& v)
{
  v (*this);
}

int
Cmp::rx_get ()
{
  return rx_;
}

int
Cmp::ry_get ()
{
  return ry_;
}

void
Cmp::rx_set (int rx)
{
  rx_ = rx;
}

void
Cmp::ry_set (int ry)
{
  ry_ = ry;
}
