#include "and.hh"

void
And::accept (Visitor& v)
{
  v (*this);
}

int
And::rx_get ()
{
  return rx_;
}

int
And::ry_get ()
{
  return ry_;
}

void
And::rx_set (int rx)
{
  rx_ = rx;
}

void
And::ry_set (int ry)
{
  ry_ = ry;
}
