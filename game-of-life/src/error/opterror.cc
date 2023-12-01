#include <sstream>
#include <string>
#include "opterror.hh"

Error::OptError::OptError (char error)
{
  this->error_ = error;
}

std::string
Error::OptError::get_error () const
{
  std::stringstream ss;

  ss << "Error: unknown option " << this->error_ << std::endl;

  ss << "usage:" << std::endl
     << "   ./jdv [options] <file> [cycle #]" << std::endl
     << "options:" << std::endl
     << "-i      Interactive mode" << std::endl
     << "-p      Display all steps" << std::endl
     << "-v      Increase verbose" << std::endl
     << "-a      Enhanced algorithme for ant organisation";

  return ss.str ();
}
