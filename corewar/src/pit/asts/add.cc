#include "add.hh"

void
Add::accept (Visitor& v)
{
  v (*this);
}

int
Add::rx_get ()
{
  return rx_;
}

int
Add::ry_get ()
{
  return ry_;
}

void
Add::rx_set (int rx)
{
  rx_ = rx;
}

void
Add::ry_set (int ry)
{
  ry_ = ry;
}
