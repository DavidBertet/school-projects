#include "mode.hh"

void
Mode::accept (Visitor& v)
{
  v (*this);
}

Ast&
Mode::m_get ()
{
  return *m_;
}

int
Mode::m_eval_get ()
{
  return m_eval_;
}

void
Mode::m_set (Ast& n)
{
  m_ = &n;
}

void
Mode::m_eval_set (int n_eval)
{
  m_eval_ = n_eval;
}

