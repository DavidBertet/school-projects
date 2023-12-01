#include "div.hh"

void
Div::accept (Visitor& v)
{
  v (*this);
}

Ast&
Div::fg_get ()
{
  return *fg_;
}


void
Div::fg_set (Ast& n)
{
  fg_ = &n;
}

Ast&
Div::fd_get ()
{
  return *fd_;
}


void
Div::fd_set (Ast& n)
{
  fd_ = &n;
}
