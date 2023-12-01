#include "ll.hh"
#include <iostream>

void
Ll::accept (Visitor& v)
{
  v (*this);
}

int
Ll::rx_get ()
{
  return rx_;
}

Ast&
Ll::n_get ()
{
  return *n_;
}

int
Ll::n_eval_get ()
{
  return n_eval_;
}

void
Ll::rx_set (int rx)
{
  rx_ = rx;
}

void
Ll::n_set (Ast& n)
{
  n_ = &n;
}

void
Ll::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
