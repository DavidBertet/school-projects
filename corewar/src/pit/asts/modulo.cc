#include "modulo.hh"

void
Modulo::accept (Visitor& v)
{
  v (*this);
}

Ast&
Modulo::fg_get ()
{
  return *fg_;
}


void
Modulo::fg_set (Ast& n)
{
  fg_ = &n;
}

Ast&
Modulo::fd_get ()
{
  return *fd_;
}


void
Modulo::fd_set (Ast& n)
{
  fd_ = &n;
}
