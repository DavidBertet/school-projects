#include <string>
#include <iostream>
#include "error.hh"

namespace error
{
  Error::Error (std::string str)
    : str_ (str)
  {
  }

  void
  Error::print (std::ostream& output)
  {
    output << this->str_ << std::endl;
  }
}
