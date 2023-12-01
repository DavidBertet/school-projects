#include "cmpi.hh"

void
Cmpi::accept (Visitor& v)
{
  v (*this);
}

int
Cmpi::rx_get ()
{
  return rx_;
}

Ast&
Cmpi::n_get ()
{
  return *n_;
}

int
Cmpi::n_eval_get ()
{
  return n_eval_;
}

void
Cmpi::rx_set (int rx)
{
  rx_ = rx;
}


void
Cmpi::n_set (Ast& n)
{
  n_ = &n;
}

void
Cmpi::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
