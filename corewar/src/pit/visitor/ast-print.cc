# include <iostream>
# include "ast-print.hh"
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

AstPrint::AstPrint ()
  : level_ (0)
{
}

AstPrint::~AstPrint ()
{
}

void
AstPrint::operator() (Crash&)
{
  std::cout << "\033[31mCrash\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Nop&)
{
  std::cout << "\033[31mNop\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (And&	input)
{
  std::cout << "\033[31mAnd\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Or&	input)
{
  std::cout << "\033[31mOr\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Xor&	input)
{
  std::cout << "\033[31mXor\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Not&	input)
{
  std::cout << "\033[31mNot\t" << input.rx_get () << "\033[0m, \033[31m"
	    <<input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Rol&	input)
{
  std::cout << "\033[31mRol\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Asr&	input)
{
  std::cout << "\033[31mAsr\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Add&	input)
{
  std::cout << "\033[31mAdd\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Sub&	input)
{
  std::cout << "\033[31mSub\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Cmp&	input)
{
  std::cout << "\033[31mCmp\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Neg&	input)
{
  std::cout << "\033[31mNeg\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Mov&	input)
{
  std::cout << "\033[31mMov\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Ldr&	input)
{
  std::cout << "\033[31mLdr\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get ()<< "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Str&	input)
{
  std::cout << "\033[31mStr\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get ()<< "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Ldb&	input)
{
  std::cout << "\033[31mLdb\t" << input.rx_get () << "\033[0m, \033[31m" 
	    << input.ry_get () << "\033[0m, \033[31m" << input.n_eval_get ()
	    << "\033[0m, \033[31m" << input.m_eval_get () << "\033[0m"
            << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Stb&	input)
{
  std::cout << "\033[31mStb\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m, \033[31m" << input.m_eval_get ()
	    << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Lc&		input)
{
  std::cout << "\033[31mLc\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Ll&		input)
{
  std::cout << "\033[31mLl\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  input.n_get ().accept (*this);
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Swp&	input)
{
  std::cout << "\033[31mSwp\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.ry_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Addi&	input)
{
  std::cout << "\033[31mAddi\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Cmpi&	input)
{
  std::cout << "\033[31mCmpi\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (B&		input)
{
  std::cout << "\033[31mB\t" << input.rx_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Bz&		input)
{
  std::cout << "\033[31mBz\t" << input.rx_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Bnz&	input)
{
  std::cout << "\033[31mBnz\t" << input.rx_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Bs&		input)
{
  std::cout << "\033[31mBs\t" << input.rx_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Stat&	input)
{
  std::cout << "\033[31mStat\t" << input.rx_get () << "\033[0m, \033[31m"
	    << input.n_eval_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Check&)
{
  std::cout << "\033[31mCheck\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

 void
AstPrint::operator() (Mode&	input)
{
  std::cout << "\033[31mMode\t" << input.m_eval_get () << "\033[0m"
	    << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Fork&)
{
  std::cout << "\033[31mFork\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Write&	input)
{
  std::cout << "\033[31mWrite\t" << input.rx_get () << "\033[0m" << std::endl;
  std::cout << "\033[31m______________________\033[0m" << std::endl;
}

void
AstPrint::operator() (Plus&	input)
{
  ++level_;
  std::string	space (level_ * 3, ' ');

  std::cout << space << "\033[33mPlus\033[0m" << std::endl;
  input.fg_get ().accept (*this);
  input.fd_get ().accept (*this);
  --level_;
}

void
AstPrint::operator() (Minus&	input)
{
  ++level_;
  std::string space (level_ * 3, ' ');

  std::cout << space << "\033[33mMinus\033[0m" << std::endl;
  input.fg_get ().accept (*this);
  input.fd_get ().accept (*this);
  --level_;
}

void
AstPrint::operator() (Modulo&	input)
{
  ++level_;
  std::string space (level_ * 3, ' ');

  std::cout << space << "\033[33mModulo\033[0m" << std::endl;
  input.fg_get ().accept (*this);
  input.fd_get ().accept (*this);
  --level_;
}

void
AstPrint::operator() (Mult&	input)
{
  ++level_;
  std::string space (level_ * 3, ' ');

  std::cout << space << "\033[33mMult\033[0m" << std::endl;
  input.fg_get ().accept (*this);
  input.fd_get ().accept (*this);
  --level_;
}

void
AstPrint::operator() (Div&	input)
{
  ++level_;
  std::string space (level_ * 3, ' ');

  std::cout << space << "\033[33mDiv\033[0m" << std::endl;
  input.fg_get ().accept (*this);
  input.fd_get ().accept (*this);
  --level_;
}

void
AstPrint::operator() (Value&	input)
{
  ++level_;
  std::string space (level_ * 3, ' ');

  std::cout << space << input << std::endl;
  --level_;
}
