# include <iostream>
# include "writter.hh"
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
# include "plus.hh"
# include "minus.hh"
# include "modulo.hh"
# include "mult.hh"
# include "div.hh"
# include "value.hh"
# include "data.h"

Writter::Writter ()
{
}

Writter::~Writter ()
{
}

void
Writter::operator() (Crash&	input)
{
  (void) input;
  vect_.push_back (0); //0000
}

void
Writter::operator() (Nop&	input)
{
  (void) input;
  vect_.push_back (1); //0001
}

void
Writter::operator() (And&	input)
{
  vect_.push_back (2); //0010
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Or&	input)
{
  vect_.push_back (3); //0011
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Xor&	input)
{
  vect_.push_back (4); //0100
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Not&	input)
{
  vect_.push_back (5); //0101
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Rol&	input)
{
  vect_.push_back (6); //0110
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.n_eval_get ());
}

void
Writter::operator() (Asr&	input)
{
  vect_.push_back (7); //0111
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.n_eval_get ());
}

void
Writter::operator() (Add&	input)
{
  vect_.push_back (8); //1000
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Sub&	input)
{
  vect_.push_back (9); //1001
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Cmp&	input)
{
  vect_.push_back (10); //1010
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Neg&	input)
{
  vect_.push_back (11); //1011
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Mov&	input)
{
  vect_.push_back (12); //1100
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Ldr&	input)
{
  vect_.push_back (13); //1101
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Str&	input)
{
  vect_.push_back (14); //1110
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Ldb&	input)
{
  int i0;
  int i1;

  vect_.push_back (15); //1111
  vect_.push_back (0); //0000
  vect_.push_back (input.rx_get ());
  i0 = input.n_eval_get () / 16;
  i1 = input.n_eval_get () % 16;
  vect_.push_back (i1);
  vect_.push_back (i0);
  i0 = input.m_eval_get () / 16;
  i1 = input.m_eval_get () % 16;
  vect_.push_back (i1);
  vect_.push_back (i0);
}

void
Writter::operator() (Stb&	input)
{
  int i0;
  int i1;

  vect_.push_back (15); //1111
  vect_.push_back (1); //0001
  vect_.push_back (input.rx_get ());
  i0 = input.n_eval_get () / 16;
  i1 = input.n_eval_get () % 16;
  vect_.push_back (i1);
  vect_.push_back (i0);
  i0 = input.m_eval_get () / 16;
  i1 = input.m_eval_get () % 16;
  vect_.push_back (i1);
  vect_.push_back (i0);
}

void
Writter::operator() (Lc&		input)
{
  int i0;
  int i1;

  vect_.push_back (15); //1111
  vect_.push_back (2); //0010
  vect_.push_back (input.rx_get ());
  i0 = input.n_eval_get () / 16;
  i1 = input.n_eval_get () % 16;
  vect_.push_back (i1);
  vect_.push_back (i0);
}

void
Writter::operator() (Ll&		input)
{
  int i0;
  int i1;
  int i2;
  int i3;

  vect_.push_back (15); //1111
  vect_.push_back (3); //0011
  vect_.push_back (input.rx_get ());
  i0 = input.n_eval_get () / (16 * 16 * 16);
  i1 = (input.n_eval_get () / (16 * 16)) % 16;
  i2 = (input.n_eval_get () / 16) % 16;
  i3 = input.n_eval_get () % 16;
  vect_.push_back (i3);
  vect_.push_back (i2);
  vect_.push_back (i1);
  vect_.push_back (i0);
}

void
Writter::operator() (Swp&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (4); //0100
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.ry_get ());
}

void
Writter::operator() (Addi&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (5); //0101
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.n_eval_get ());
}

void
Writter::operator() (Cmpi&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (6); //0110
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.n_eval_get ());
}

void
Writter::operator() (B&		input)
{
  vect_.push_back (15); //1111
  vect_.push_back (7); //0111
  vect_.push_back (input.rx_get ());
}

void
Writter::operator() (Bz&		input)
{
  vect_.push_back (15); //1111
  vect_.push_back (8); //1000
  vect_.push_back (input.rx_get ());
}

void
Writter::operator() (Bnz&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (9); //1001
  vect_.push_back (input.rx_get ());
}

void
Writter::operator() (Bs&		input)
{
  vect_.push_back (15); //1111
  vect_.push_back (10);//1001
  vect_.push_back (input.rx_get ());
}

void
Writter::operator() (Stat&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (11); //1011
  vect_.push_back (input.rx_get ());
  vect_.push_back (input.n_eval_get ());
}

void
Writter::operator() (Check&	input)
{
  (void) input;
  vect_.push_back (15); //1111
  vect_.push_back (12); //1100
}

void
Writter::operator() (Mode&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (13); //1101
  vect_.push_back (input.m_eval_get ());
}

void
Writter::operator() (Fork&	input)
{
  (void) input;
  vect_.push_back (15); //1111
  vect_.push_back (14); //1110
}

void
Writter::operator() (Write&	input)
{
  vect_.push_back (15); //1111
  vect_.push_back (15); //1111
  vect_.push_back (input.rx_get ());
}

void
Writter::operator() (Plus&	input)
{
  (void) input;
}

void
Writter::operator() (Minus&	input)
{
  (void) input;
}

void
Writter::operator() (Modulo&	input)
{
  (void) input;
}

void
Writter::operator() (Value&	input)
{
  (void) input;
}

void

Writter::operator() (Mult&	input)
{
  (void) input;
}

void
Writter::operator() (Div&	input)
{
  (void) input;
}

void
Writter::write (std::ofstream& file, std::string name, std::string comment)
{
  unsigned short res;
  char res_char;
  int magic = MAGIC_NUMBER;
  int size = vect_.size ();
  int min;
  int i;

  file.write((char *)&magic, sizeof(int));
  file.write((char *)&size, sizeof(int));

  if  (name.size () < NAME_LENGTH)
    min = name.size ();
  else
    min = NAME_LENGTH;

  for (i=0; i < min; i++)
  {
    file.write((char *)&name[i], sizeof(char));
  }

  for (i = 0; i < (NAME_LENGTH - min); ++i)
  {
    res_char = 0;
    file.write(&res_char, sizeof(char));
  }

  //comment

  if  (comment.size () < COMMENT_LENGTH)
    min = comment.size ();
  else
    min = COMMENT_LENGTH;

  for (i = 0; i < min; i++)
  {
    file.write((char *)&comment[i], sizeof(char));
  }

  for (i = 0; i < (COMMENT_LENGTH - min); ++i)
  {
    res_char = 0;
    file.write(&res_char, sizeof(char));
  }

  if ((vect_.size () % 2) != 0)
  {
    vect_.push_back (0);
  }

  for (unsigned int i = 0; i <= vect_.size () - 1; i += 2)
  {
    res = vect_[i];
    res *= 16;
    res += vect_[i + 1];
    res_char = res;
    file.write(&res_char, sizeof(char));
  }
}
