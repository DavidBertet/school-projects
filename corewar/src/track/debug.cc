#include <iostream>
#include <string>
#include <sstream>
#include "debug.hh"
#include "delays.hh"

std::ostream&
Debug::verbose_output = std::cout;

void
Debug::print_verbose (std::string msg, int verb_mode)
{
  if (Delays::get_instance ().verbose_get () >= verb_mode)
    Debug::verbose_output << msg << std::endl;
}

void
Debug::print_verbose (std::stringstream& ss, int verb_mode)
{
  if (Delays::get_instance ().verbose_get () >= verb_mode)
    Debug::verbose_output << ss.str () << std::endl;

  ss.str ("");
}
