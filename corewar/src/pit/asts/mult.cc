#include "mult.hh"

void
Mult::accept (Visitor& v)
{
  v (*this);
}

Ast&
Mult::fg_get ()
{
  return *fg_;
}


void
Mult::fg_set (Ast& n)
{
  fg_ = &n;
}

Ast&
Mult::fd_get ()
{
  return *fd_;
}


void
Mult::fd_set (Ast& n)
{
  fd_ = &n;
}
