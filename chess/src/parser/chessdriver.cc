#include "chessdriver.hh"
#include <sstream>
#include <iostream>


ChessDriver::ChessDriver ()
{
  char*		parse_opt = 0;
  char*		scan_opt = 0;

  trace_parsing = false;
  trace_scanning = false;

  parse_opt = getenv ("PARSE");
  scan_opt = getenv ("SCAN");

  if (parse_opt)
    trace_parsing = true;

  if (scan_opt)
    trace_scanning = true;

  vreturn = 0;
}

ChessDriver::~ChessDriver ()
{
}

void
ChessDriver::parse ()
{
  scan_begin ();

  yy::parser parser (*this);
  parser.set_debug_level (trace_parsing);

  parser.parse ();
  scan_end ();
}

void
ChessDriver::error (const yy::location&		l,
		     const std::string&		m)
{
  std::cerr << l << ":" << m << std::endl;
}

void
ChessDriver::error (const std::string		&m)
{
  std::cerr << m << std::endl;
}

std::vector <std::pair<MovePGN*, MovePGN*>*>*
ChessDriver::pgn_get ()
{
  return pgn_;
}

void
ChessDriver::pgn_set (std::vector <std::pair<MovePGN*, MovePGN*>*>* pgn)
{
  pgn_ = pgn;
}
