#include <sstream>
#include <string>
#include "maperror.hh"

Error::MapError::MapError (std::string error, int line)
{
  this->error_ = error;
  this->line_ = line;
}

std::string
Error::MapError::get_error () const
{
  std::stringstream ss;

  ss << "MapError: " << this->error_;

  if (this->line_ != -1)
    ss << " at line " << this->line_;

  return ss.str ();
}
