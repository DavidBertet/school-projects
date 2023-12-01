# include <iostream>
# include "evaluator.hh"
# include "crash.hh"
# include "nop.hh"
# include "and.hh"
# include "or.hh"
# include "xor.hh"
# include "not.hh"
# include "rol.hh"
# include "asr.hh"
# include "add.hh"
# include "sub.hh"
# include "cmp.hh"
# include "neg.hh"
# include "mov.hh"
# include "ldr.hh"
# include "str.hh"
# include "ldb.hh"
# include "stb.hh"
# include "lc.hh"
# include "ll.hh"
# include "swp.hh"
# include "addi.hh"
# include "cmpi.hh"
# include "b.hh"
# include "bz.hh"
# include "bnz.hh"
# include "bs.hh"
# include "stat.hh"
# include "check.hh"
# include "mode.hh"
# include "fork.hh"
# include "write.hh"
# include "value.hh"
# include "plus.hh"
# include "minus.hh"
# include "mult.hh"
# include "div.hh"
# include "modulo.hh"

Evaluator::Evaluator ()
{
}

Evaluator::~Evaluator ()
{
}

void
Evaluator::operator() (Crash&	input)
{
  (void) input;
}

void
Evaluator::operator() (Nop&	input)
{
  (void) input;
}

void
Evaluator::operator() (And&	input)
{
  (void) input;
}

void
Evaluator::operator() (Or&	input)
{
  (void) input;
}

void
Evaluator::operator() (Xor&	input)
{
  (void) input;
}

void
Evaluator::operator() (Not&	input)
{
  (void) input;
}

void
Evaluator::operator() (Rol&	input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
}

void
Evaluator::operator() (Asr&	input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
}

void
Evaluator::operator() (Add&	input)
{
  (void) input;
}

void
Evaluator::operator() (Sub&	input)
{
  (void) input;
}

void
Evaluator::operator() (Cmp&	input)
{
  (void) input;
}

void
Evaluator::operator() (Neg&	input)
{
  (void) input;
}

void
Evaluator::operator() (Mov&	input)
{
  (void) input;
}

void
Evaluator::operator() (Ldr&	input)
{
  (void) input;
}

void
Evaluator::operator() (Str&	input)
{
  (void) input;
}

void
Evaluator::operator() (Ldb&	input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
  input.m_get ().accept (*this);
  input.m_eval_set (res_);
}

void
Evaluator::operator() (Stb&	input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
  input.m_get ().accept (*this);
  input.m_eval_set (res_);
}

void
Evaluator::operator() (Lc&		input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
}

void
Evaluator::operator() (Ll&		input)
{
  input.n_get ().accept (*this);
  input.n_eval_set (res_);
}

void
Evaluator::operator() (Swp&	input)
{
  (void) input;
}

void
Evaluator::operator() (Addi&	input)
{
  input.n_get ().accept (*this);
  res_ = res_ % 16;
  //std::cout << "\tRES" << res_ << "=" << (res_ < 0 ? 16 + res_ : res_) << std::endl;
  input.n_eval_set (res_ < 0 ? 16 + res_ : res_);
}

void
Evaluator::operator() (Cmpi&	input)
{
  input.n_get ().accept (*this);
  res_ = res_ % 16;
  //std::cout << "\tRES" << res_ << "=" << (res_ < 0 ? 16 + res_ : res_) << std::endl;
  input.n_eval_set (res_ < 0 ? 16 + res_ : res_);
}

void
Evaluator::operator() (B&		input)
{
  (void) input;
}

void
Evaluator::operator() (Bz&		input)
{
  (void) input;
}

void
Evaluator::operator() (Bnz&	input)
{
  (void) input;
}

void
Evaluator::operator() (Bs&		input)
{
  (void) input;
}

void
Evaluator::operator() (Stat&	input)
{
  input.n_get ().accept (*this);
  res_ = res_ % 16;
  //std::cout << "\tRES" << res_ << "=" << (res_ < 0 ? 16 + res_ : res_) << std::endl;
  input.n_eval_set (res_ < 0 ? 16 + res_ : res_);
}

void
Evaluator::operator() (Check&	input)
{
  (void) input;
}

void
Evaluator::operator() (Mode&	input)
{
  input.m_get ().accept (*this);
  input.m_eval_set (res_);
}

void
Evaluator::operator() (Fork&	input)
{
  (void) input;
}

void
Evaluator::operator() (Write&	input)
{
  (void) input;
}

void
Evaluator::operator() (Plus&	input)
{
  int aux = 0;

  input.fg_get ().accept (*this);
  aux = res_;
  input.fd_get ().accept (*this);
  res_ = res_ + aux;
}

void
Evaluator::operator() (Minus&	input)
{
  int aux = 0;

  input.fg_get ().accept (*this);
  aux = res_;
  input.fd_get ().accept (*this);
  res_ = aux - res_;
}

void
Evaluator::operator() (Modulo&	input)
{
  int aux = 0;

  input.fg_get ().accept (*this);
  aux = res_;
  input.fd_get ().accept (*this);
  res_ = aux % res_;
}

void
Evaluator::operator() (Mult&	input)
{
  int aux = 0;

  input.fg_get ().accept (*this);
  aux = res_;
  input.fd_get ().accept (*this);
  res_ = res_ * aux;
}

void
Evaluator::operator() (Div&	input)
{
  int aux = 0;

  input.fg_get ().accept (*this);
  aux = res_;
  input.fd_get ().accept (*this);
  res_ = aux / res_;
}

void
Evaluator::operator() (Value&	input)
{
  res_ = input.value_get ();
}
