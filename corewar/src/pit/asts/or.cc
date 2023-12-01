#include "or.hh"

void
Or::accept (Visitor& v)
{
  v (*this);
}

int
Or::rx_get ()
{
  return rx_;
}

int
Or::ry_get ()
{
  return ry_;
}

void
Or::rx_set (int rx)
{
  rx_ = rx;
}

void
Or::ry_set (int ry)
{
  ry_ = ry;
}
