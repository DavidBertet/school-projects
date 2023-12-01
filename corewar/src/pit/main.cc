#include <iostream>
#include "parser.hh"
#include "token.hh"

#include "exeption.hh"

static void
exit_help ()
{
  std::cerr << "List of available options:" << std::endl
	    << "\t--no-write (-n) : Don't generate file: "
	    << "check only errors." << std::endl
	    << "\t--no-warn (-w)  : Inhibit all warning messages." << std::endl
	    << "\t-p              : Print pit parsed AST." << std::endl
	    << "\t-xml            : Print boost::spirit parsed xml AST."
	    << std::endl
	    << "\t--help (-h)     : Print this usage." << std::endl;
  exit (0);
}

int main (int argc,
	  char **argv)
{
  try
    {
      int	count_error = 0;
      bool	warning = true;
      bool	print = false;
      bool	print_xml = false;
      bool	write = true;

      for (int i = 1; i < argc; i++)
	{
	  std::string word (argv[i]);

	  if (!word.compare ("--help") or (!word.compare ("-h")))
	    exit_help ();
	  else if (!word.compare ("-p"))
	    print = true;
	  else if (!word.compare ("-xml"))
	    print_xml = true;
	  else if (!word.compare ("-w") || !word.compare ("--no-warn"))
	    warning = false;
	  else if (!word.compare ("-n") || !word.compare ("--no-write"))
	    write = false;
	  else if ('-' == word[0])
	    std::cerr << "Unknown option : " << word << std::endl;
	}

      for (int i = 1; i < argc; ++i)
	if (argv[i][0] != '-')
	  {
	    Parser	p (write, print, print_xml);

	    try
	      {
		p.parse (argv[i]);
		count_error += p.fault;

		if (p.fault)
		  std::cerr << "Parse Error on file : " << argv[i] << std::endl;

	      }  catch (Error	e)
	      {
		e.display_error ();
		++count_error;
	      }
	  }

      if (count_error > 127)
	count_error = 127;

      return count_error;
    }
  catch (...)
    {
      std::cerr << "Unknown error .... :P :[";
      return 1;
    }
}
