#include <iostream>
#include <assert.h>
#include "quartet.hh"

Quartet::Quartet ()
{
  this->quartet_ = 100;
}

Quartet::Quartet (char quartet)
{
  assert(quartet >= 0 && quartet <= 15);

  this->quartet_ = quartet;
}

void
Quartet::quartet_set (char quartet)
{
  assert(quartet >= 0 && quartet <= 15);

  this->quartet_ = quartet;
}


char
Quartet::quartet_get () const
{
  return this->quartet_;
}

void
Quartet::print (std::ostream& o)
{
  assert (this->quartet_ != 100);

  char c;

  if (this->quartet_ < 10)
    c = '0' + this->quartet_;
  else
  {
    o << '1';
    c = '0' + this->quartet_ - 10;
  }

  o << c;
}

void
Quartet::print_hex (std::ostream& o)
{
  assert (this->quartet_ != 100);

  int i = this->quartet_;

  o << std::hex << i;
}
