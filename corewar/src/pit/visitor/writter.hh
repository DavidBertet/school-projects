#ifndef WRITER_HH_
# define WRITTER_HH_
# include "visitor.hh"
# include <vector>
# include <fstream>

class Writter : public Visitor
{
public:
  Writter ();
  ~Writter ();

  virtual void	operator() (Crash&	input);
  virtual void	operator() (Nop&	input);
  virtual void	operator() (And&	input);
  virtual void	operator() (Or&		input);
  virtual void	operator() (Xor&	input);
  virtual void	operator() (Not&	input);
  virtual void	operator() (Rol&	input);
  virtual void	operator() (Asr&	input);
  virtual void	operator() (Add&	input);
  virtual void	operator() (Sub&	input);
  virtual void	operator() (Cmp&	input);
  virtual void	operator() (Neg&	input);
  virtual void	operator() (Mov&	input);
  virtual void	operator() (Ldr&	input);
  virtual void	operator() (Str&	input);
  virtual void	operator() (Ldb&	input);
  virtual void	operator() (Stb&	input);
  virtual void	operator() (Lc&		input);
  virtual void	operator() (Ll&		input);
  virtual void	operator() (Swp&	input);
  virtual void	operator() (Addi&	input);
  virtual void	operator() (Cmpi&	input);
  virtual void	operator() (B&		input);
  virtual void	operator() (Bz&		input);
  virtual void	operator() (Bnz&	input);
  virtual void	operator() (Bs&		input);
  virtual void	operator() (Stat&	input);
  virtual void	operator() (Check&	input);
  virtual void	operator() (Mode&	input);
  virtual void	operator() (Fork&	input);
  virtual void	operator() (Write&	input);
  virtual void	operator() (Plus&	input);
  virtual void	operator() (Minus&	input);
  virtual void	operator() (Modulo&	input);
  virtual void	operator() (Mult&	input);
  virtual void	operator() (Div&	input);
  virtual void	operator() (Value&	input);
  void	write (std::ofstream& file, std::string name, std::string comment);
private:
  std::vector<int> vect_;
};
#endif // WRITTER_HH_
