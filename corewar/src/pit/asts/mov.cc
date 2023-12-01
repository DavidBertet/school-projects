#include "mov.hh"

void
Mov::accept (Visitor& v)
{
  v (*this);
}

int
Mov::rx_get ()
{
  return rx_;
}

int
Mov::ry_get ()
{
  return ry_;
}

void
Mov::rx_set (int rx)
{
  rx_ = rx;
}

void
Mov::ry_set (int ry)
{
  ry_ = ry;
}
