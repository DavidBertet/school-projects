#include "nop.hh"

void
Nop::accept (Visitor& v)
{
  v (*this);
}
