#include "stat.hh"

void
Stat::accept (Visitor& v)
{
  v (*this);
}

int
Stat::rx_get ()
{
  return rx_;
}

Ast&
Stat::n_get ()
{
  return *n_;
}

int
Stat::n_eval_get ()
{
  return n_eval_;
}

void
Stat::rx_set (int rx)
{
  rx_ = rx;
}

void
Stat::n_set (Ast& n)
{
  n_ = &n;
}

void
Stat::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
