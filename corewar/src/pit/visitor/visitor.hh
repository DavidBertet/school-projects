#ifndef VISITOR_HH_
# define VISITOR_HH_

class Crash;
class Nop;
class And;
class Or;
class Xor;
class Not;
class Rol;
class Asr;
class Add;
class Sub;
class Cmp;
class Neg;
class Mov;
class Ldr;
class Str;
class Ldb;
class Stb;
class Lc;
class Ll;
class Swp;
class Addi;
class Cmpi;
class B;
class Bz;
class Bnz;
class Bs;
class Stat;
class Check;
class Mode;
class Fork;
class Write;
class Plus;
class Minus;
class Modulo;
class Mult;
class Div;
class Value;


class Visitor
{
public:
  virtual void	operator() (Crash&	input) = 0;
  virtual void	operator() (Nop&	input) = 0;
  virtual void	operator() (And&	input) = 0;
  virtual void	operator() (Or&		input) = 0;
  virtual void	operator() (Xor&	input) = 0;
  virtual void	operator() (Not&	input) = 0;
  virtual void	operator() (Rol&	input) = 0;
  virtual void	operator() (Asr&	input) = 0;
  virtual void	operator() (Add&	input) = 0;
  virtual void	operator() (Sub&	input) = 0;
  virtual void	operator() (Cmp&	input) = 0;
  virtual void	operator() (Neg&	input) = 0;
  virtual void	operator() (Mov&	input) = 0;
  virtual void	operator() (Ldr&	input) = 0;
  virtual void	operator() (Str&	input) = 0;
  virtual void	operator() (Ldb&	input) = 0;
  virtual void	operator() (Stb&	input) = 0;
  virtual void	operator() (Lc&		input) = 0;
  virtual void	operator() (Ll&		input) = 0;
  virtual void	operator() (Swp&	input) = 0;
  virtual void	operator() (Addi&	input) = 0;
  virtual void	operator() (Cmpi&	input) = 0;
  virtual void	operator() (B&		input) = 0;
  virtual void	operator() (Bz&		input) = 0;
  virtual void	operator() (Bnz&	input) = 0;
  virtual void	operator() (Bs&		input) = 0;
  virtual void	operator() (Stat&	input) = 0;
  virtual void	operator() (Check&	input) = 0;
  virtual void	operator() (Mode&	input) = 0;
  virtual void	operator() (Fork&	input) = 0;
  virtual void	operator() (Write&	input) = 0;
  virtual void	operator() (Plus&	input) = 0;
  virtual void	operator() (Minus&	input) = 0;
  virtual void	operator() (Modulo&	input) = 0;
  virtual void	operator() (Mult&	input) = 0;
  virtual void	operator() (Div&	input) = 0;
  virtual void	operator() (Value&	input) = 0;
private:
};

#endif	// !VISITOR_HH_
