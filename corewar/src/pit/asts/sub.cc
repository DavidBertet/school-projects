#include "sub.hh"

void
Sub::accept (Visitor& v)
{
  v (*this);
}

int
Sub::rx_get ()
{
  return rx_;
}

int
Sub::ry_get ()
{
  return ry_;
}

void
Sub::rx_set (int rx)
{
  rx_ = rx;
}

void
Sub::ry_set (int ry)
{
  ry_ = ry;
}
