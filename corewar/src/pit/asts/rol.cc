#include "rol.hh"

void
Rol::accept (Visitor& v)
{
  v (*this);
}

int
Rol::rx_get ()
{
  return rx_;
}

Ast&
Rol::n_get ()
{
  return *n_;
}

int
Rol::n_eval_get ()
{
  return n_eval_;
}

void
Rol::rx_set (int rx)
{
  rx_ = rx;
}

void
Rol::n_set (Ast& n)
{
  n_ = &n;
}

void
Rol::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
