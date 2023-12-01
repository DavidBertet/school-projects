#include "ldr.hh"

void
Ldr::accept (Visitor& v)
{
  v (*this);
}

int
Ldr::rx_get ()
{
  return rx_;
}

int
Ldr::ry_get ()
{
  return ry_;
}

void
Ldr::rx_set (int rx)
{
  rx_ = rx;
}

void
Ldr::ry_set (int ry)
{
  ry_ = ry;
}
