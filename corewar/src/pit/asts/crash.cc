#include "crash.hh"

void
Crash::accept (Visitor& v)
{
  v (*this);
}
