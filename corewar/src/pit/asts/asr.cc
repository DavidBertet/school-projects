#include "asr.hh"

void
Asr::accept (Visitor& v)
{
  v (*this);
}

int
Asr::rx_get ()
{
  return rx_;
}

Ast&
Asr::n_get ()
{
  return *n_;
}

int
Asr::n_eval_get ()
{
  return n_eval_;
}

void
Asr::rx_set (int rx)
{
  rx_ = rx;
}

void
Asr::n_set (Ast& n)
{
  n_ = &n;
}

void
Asr::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}
