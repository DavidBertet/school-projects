#include "plus.hh"

void
Plus::accept (Visitor& v)
{
  v (*this);
}

Ast&
Plus::fg_get ()
{
  return *fg_;
}


void
Plus::fg_set (Ast& n)
{
  fg_ = &n;
}

Ast&
Plus::fd_get ()
{
  return *fd_;
}


void
Plus::fd_set (Ast& n)
{
  fd_ = &n;
}
