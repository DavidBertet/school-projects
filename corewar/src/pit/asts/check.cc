#include "check.hh"

void
Check::accept (Visitor& v)
{
  v (*this);
}
