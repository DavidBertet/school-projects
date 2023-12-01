#include "fork.hh"

void
Fork::accept (Visitor& v)
{
  v (*this);
}
