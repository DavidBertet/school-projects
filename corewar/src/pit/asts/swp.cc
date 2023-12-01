#include "swp.hh"

void
Swp::accept (Visitor& v)
{
  v (*this);
}

int
Swp::rx_get ()
{
  return rx_;
}

int
Swp::ry_get ()
{
  return ry_;
}

void
Swp::rx_set (int rx)
{
  rx_ = rx;
}

void
Swp::ry_set (int ry)
{
  ry_ = ry;
}
