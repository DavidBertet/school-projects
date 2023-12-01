#include "stb.hh"

void
Stb::accept (Visitor& v)
{
  v (*this);
}

int
Stb::rx_get ()
{
  return rx_;
}

int
Stb::ry_get ()
{
  return ry_;
}

void
Stb::rx_set (int rx)
{
  rx_ = rx;
}

void
Stb::ry_set (int ry)
{
  ry_ = ry;
}

Ast&
Stb::n_get ()
{
  return *n_;
}

int
Stb::n_eval_get ()
{
  return n_eval_;
}

Ast&
Stb::m_get ()
{
  return *m_;
}

int
Stb::m_eval_get ()
{
  return m_eval_;
}

void
Stb::n_set (Ast& n)
{
  n_ = &n;
}

void
Stb::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}

void
Stb::m_set (Ast& n)
{
  m_ = &n;
}

void
Stb::m_eval_set (int n_eval)
{
  m_eval_ = n_eval;
}
