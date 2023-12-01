#include "parse_opt.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "data.h"
#include "delays.hh"

ParseOpt::ParseOpt ()
{
    help_ = false;
    debug_ = false;
    display_ = false;
    mode_ = -1;
    laps_number_ = LAPS_NUMBER;
    memory_size_ = MEMORY_SIZE;
    checkpoints_per_lap_ = CHECKPOINTS_PER_LAP;
    checkpoint_delay_ = CHECKPOINT_DELAY;
    verbose_ = 0;
}

void
ParseOpt::verif_mode (std::string& mode)
{
  if (!mode.compare ("venom"))
    mode_ = 1;
  else if (!mode.compare ("rapier"))
    mode_ = 2;
  else if (!mode.compare ("phantom"))
    mode_ = 3;
  else
    mode_ = 0;
}

void
ParseOpt::verif_lap_number (std::string& arg,
			    std::string& opt)
{
  int lap;
  std::stringstream oss;

  oss << arg;
  oss >> lap;
  if (oss.eof ())
  {
    if ((lap < 1) or (lap > 65535))
    {
      std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
      std::cerr << std::endl;
      exit (2);
    }
    else
    {
      laps_number_ = lap;
    }
  }
  else
  {
    std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
    std::cerr << arg  << "." << std::endl;
  }
}

void
ParseOpt::verif_memory_size (std::string& arg,
			     std::string& opt)
{
  int mem;
  std::stringstream oss;

  oss << arg;
  oss >> mem;
  if (oss.eof ())
  {
    if ((mem < 1) or (mem > 65536))
    {
      std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
      std::cerr << std::endl;
      exit (2);
    }
    else
    {
      memory_size_ = mem;
    }
  }
  else
  {
    std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
    std::cerr << arg  << "." << std::endl;
  }
}

void
ParseOpt::verif_checkpoints_per_lap (std::string& arg,
				     std::string& opt)
{
  int lap;
  std::stringstream oss;

  oss << arg;
  oss >> lap;
  if (oss.eof ())
  {
    if ((lap < 3) or (lap > 4096))
    {
      std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
      std::cerr << std::endl;
      exit (2);
    }
    else
    {
      checkpoints_per_lap_ = lap;
    }
  }
  else
  {
    std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
    std::cerr << arg  << "." << std::endl;
  }
}

void
ParseOpt::verif_checkpoint_delay (std::string& arg,
				  std::string& opt)
{
  int lap;
  std::stringstream oss;

  oss << arg;
  oss >> lap;
  if (oss.eof ())
  {
    if ((lap < 1) or (lap > 16777215))
    {
      std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
      std::cerr  << std::endl;
      exit (2);
    }
    else
    {
      checkpoint_delay_ = lap;
    }
  }
  else
  {
    std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
    std::cerr << arg  << "." << std::endl;
  }
}

void
ParseOpt::verif_verbose (std::string& arg, std::string& opt)
{
  int verb;
  std::stringstream oss;

  oss << arg;
  oss >> verb;
  if (oss.eof ())
  {
    if (verb < 0)
    {
      std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
      std::cerr << arg << "." << std::endl;
    }
    else
    {
      verbose_ = verb;
    }
  }
  else
  {
    std::cerr << "track : invalid argument for option \"" << opt <<"\" -- ";
    std::cerr << arg << "." << std::endl;
  }
}

bool
ParseOpt::test_option_double (std::string& word, std::string& arg)
{
    if (!word.compare ("-m"))
      verif_mode (arg);
    else if (!word.compare ("--mode"))
      verif_mode (arg);
    else if (!word.compare ("-l"))
    {
      std::string opt ("l");

      verif_lap_number (arg, opt);
      return true;
    }
    else if (!word.compare ("--laps-number"))
    {
      std::string opt("laps-number");
      verif_lap_number (arg, opt);
        return true;
    }
    else if (!word.compare ("-s"))
    {
      std::string opt ("s");
      verif_memory_size (arg, opt);
      return true;
    }
    else if  (!word.compare ("--memory-size"))
    {
      std::string opt ("memory-size");
      verif_memory_size (arg, opt);
      return true;
    }
    else if (!word.compare ("-n"))
    {
      std::string opt ("n");
      verif_checkpoints_per_lap (arg, opt);
      return true;
    }
    return test_option_double2 (word, arg);
}

bool
ParseOpt::test_option_double2 (std::string& word, std::string& arg)
{
    if (!word.compare ("--checkpoints_par_lap"))
    {
      std::string opt ("checkpoints_par_lap");
      verif_checkpoints_per_lap (arg, opt);
      return true;
    }
    else if (!word.compare ("-d"))
    {
      std::string opt ("d");
      verif_checkpoint_delay (arg, opt);
      return true;
    }
    else if (!word.compare ("--checkpoint_delay"))
    {
      std::string opt("checkpoint_delay");
      verif_checkpoint_delay (arg, opt);
      return true;
    }
    else if (!word.compare ("-v"))
    {
      std::string opt ("v");
      verif_verbose (arg, opt);
      return true;
    }
    else if (!word.compare ("--verbose"))
    {
      std::string opt("verbose");
      verif_verbose (arg, opt);
      return true;
    }
    return false;
}
void
ParseOpt::test_option_simple (std::string& word)
{
  size_t i = word.find_first_of ("=", 0);

  if (i != std::string::npos)
  {
    std::string w = word.substr(0, i);
    std::string arg = word.substr(i + 1, word.length ());
    test_option_double (w, arg);
  }
}

void
ParseOpt::add_file (std::string& word)
{
  Delays::get_instance ().file_add (word);
}

void
ParseOpt::parse (int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    std::string word (argv[i]);
    if (!word.compare ("--help") or (!word.compare ("-h")))
      help_ = true;
    else if (!word.compare ("--debug"))
      debug_ = true;
    else if (!word.compare ("--display"))
      display_ = true;
    else
    {
      std::string word (argv[i]);
      size_t p = word.find_first_not_of ("-", 0);
      if (p != 0)
      {
	if (i + 1 < argc)
	{
	  std::string arg (argv[i+1]);
	  if (test_option_double (word, arg))
	    i++;
	}
	test_option_simple (word);
      }
      else
	add_file (word);
    }
  }
}

void
ParseOpt::execute_opt ()
{
  if (help_)
    fct_help ();
  Delays& Delay = Delays::get_instance ();

  if (mode_ == -1)
  {
    if (verbose_ > 0)
      std::cout << "No mode explicitly selected : using vector mode."
		<< std::endl;

    mode_ = 0;
  }

  Delay.help_set (help_);
  Delay.debug_set (debug_);
  Delay.display_set (display_);
  Delay.mode_set (mode_);
  Delay.laps_number_set (laps_number_);
  Delay.memory_size_set (memory_size_);
  Delay.checkpoints_per_lap_set (checkpoints_per_lap_);
  Delay.checkpoint_delay_set (checkpoint_delay_);
  Delay.verbose_set (verbose_);

  if (debug_)
  {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "            TEST OPTIONS             " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "mode = " << mode_ << std::endl;
    std::cout << "laps_number = " << laps_number_ << std::endl;
    std::cout << "memory_size = " << memory_size_ << std::endl;
    std::cout << "checkpoints_per_lap = " << checkpoints_per_lap_ << std::endl;
    std::cout << "checkpoint_delay = " << checkpoint_delay_ << std::endl;
    std::cout << "verbose = " << verbose_ << std::endl;
    std::cout << "display = " << display_ << std::endl;
    std::cout << "debug = " << debug_ << std::endl;
    std::cout << "---------------------------------------" << std::endl;
  }
}

void
ParseOpt::fct_help ()
{
  std::cout << "F6100 Championship - Track simulator v1.0" << std::endl;
  std::cout << " 0. General options" << std::endl;
  std::cout << "  -h, --help                     Give this help list";
  std::cout << std::endl << std::endl;
  std::cout << " 1. Virtual machine execution parameters" << std::endl;
  std::cout << "  -v, --verbose=n                Enable verbosity mode n";
  std::cout << std::endl;
  std::cout << "      --debug                    Enable debug mode";
  std::cout << std::endl;
  std::cout << "  -m, --mode=n                   ";
  std::cout << "Set virtual machine level to <n>";
  std::cout << std::endl;
  std::cout << "                                 ";
  std::cout << "<n> may be vector, venom, rapier, phantom";
  std::cout << std::endl << std::endl;
  std::cout << " 2. Virtual machine environment parameters" << std::endl;
  std::cout << "  -s, --memory-size=n          Set memory size to <n> nibbles";
  std::cout << std::endl;
  std::cout << "  -l, --laps-number=n          Set number of laps to <n>";
  std::cout << std::endl;
  std::cout << "  -n, --checkpoints-per-lap=n  ";
  std::cout << "Set checkpoints to validate per lap to <n>";
  std::cout << std::endl;
  std::cout << "  -d, --checkpoint-delay=n     ";
  std::cout << "Set the delay of a checkpoint to";
  std::cout << std::endl;
  std::cout << "                                 <n> machine cycle";
  std::cout << std::endl << std::endl;

  exit (0);
}

int
ParseOpt::mode_get ()
{
  return mode_;
}
