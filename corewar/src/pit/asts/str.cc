#include "str.hh"

void
Str::accept (Visitor& v)
{
  v (*this);
}

int
Str::rx_get ()
{
  return rx_;
}

int
Str::ry_get ()
{
  return ry_;
}

void
Str::rx_set (int rx)
{
  rx_ = rx;
}

void
Str::ry_set (int ry)
{
  ry_ = ry;
}
