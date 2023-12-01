#include "not.hh"

void
Not::accept (Visitor& v)
{
  v (*this);
}

int
Not::rx_get ()
{
  return rx_;
}

int
Not::ry_get ()
{
  return ry_;
}

void
Not::rx_set (int rx)
{
  rx_ = rx;
}

void
Not::ry_set (int ry)
{
  ry_ = ry;
}
