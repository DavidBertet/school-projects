#include <iostream>
#include <string>
#include "instr.hh"

Instr::Instr (std::string name)
{
  this->name_ = name;
}

std::string
Instr::name_get ()
{
  return this->name_;
}

// void
// Instr::print ()
// {
//   std::cout << this->text_get () << std::endl;
// }
