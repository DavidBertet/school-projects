#include "exeption.hh"
#include <iostream>

Error::Error ()
{
}

Error::Error (std::string error, int ret):
  error_ (error),
  ret_ (ret)
{
}

void
Error::display_error () const
{
  std::cerr << "Exception : " << error_ << std::endl;
}

int
Error::ret_get ()
{
  return ret_;
}
