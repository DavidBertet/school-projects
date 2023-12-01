#include "addi.hh"

void
Addi::accept (Visitor& v)
{
  v (*this);
}

int
Addi::rx_get ()
{
  return rx_;
}

Ast&
Addi::n_get ()
{
  return *n_;
}

int
Addi::n_eval_get ()
{
  return n_eval_;
}

void
Addi::rx_set (int rx)
{
  rx_ = rx;
}

void
Addi::n_set (Ast& n)
{
  n_ = &n;
}

void
Addi::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
