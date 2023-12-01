#include "lc.hh"

void
Lc::accept (Visitor& v)
{
  v (*this);
}

int
Lc::rx_get ()
{
  return rx_;
}

Ast&
Lc::n_get ()
{
  return *n_;
}

int
Lc::n_eval_get ()
{
  return n_eval_;
}

void
Lc::rx_set (int rx)
{
  rx_ = rx;
}

void
Lc::ry_set (int ry)
{
  ry_ = ry;
}

void
Lc::n_set (Ast& n)
{
  n_ = &n;
}

void
Lc::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
