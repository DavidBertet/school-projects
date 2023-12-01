#include "minus.hh"

void
Minus::accept (Visitor& v)
{
  v (*this);
}

Ast&
Minus::fg_get ()
{
  return *fg_;
}


void
Minus::fg_set (Ast& n)
{
  fg_ = &n;
}

Ast&
Minus::fd_get ()
{
  return *fd_;
}


void
Minus::fd_set (Ast& n)
{
  fd_ = &n;
}
