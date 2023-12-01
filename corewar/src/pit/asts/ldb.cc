#include "ldb.hh"

void
Ldb::accept (Visitor& v)
{
  v (*this);
}

int
Ldb::rx_get ()
{
  return rx_;
}

int
Ldb::ry_get ()
{
  return ry_;
}

Ast&
Ldb::n_get ()
{
  return *n_;
}

int
Ldb::n_eval_get ()
{
  return n_eval_;
}

Ast&
Ldb::m_get ()
{
  return *m_;
}

int
Ldb::m_eval_get ()
{
  return m_eval_;
}

void
Ldb::rx_set (int rx)
{
  rx_ = rx;
}

void
Ldb::ry_set (int ry)
{
  ry_ = ry;
}

void
Ldb::n_set (Ast& n)
{
  n_ = &n;
}

void
Ldb::n_eval_set (int n_eval)
{
  n_eval_ = n_eval;
}

void
Ldb::m_set (Ast& n)
{
  m_ = &n;
}

void
Ldb::m_eval_set (int n_eval)
{
  m_eval_ = n_eval;
}
