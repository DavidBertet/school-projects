#include <iostream>

#include "piece_print_visitor.hh"

#include "queen.hh"
#include "king.hh"
#include "pawn.hh"
#include "rook.hh"
#include "bishop.hh"
#include "knight.hh"

void
PiecePrintVisitor::visit (Queen& queen)
{
  if (queen.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "Q"/*\033[37m"*/;
}

void
PiecePrintVisitor::visit (King& king)
{
  if (king.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "K"/*\033[37m"*/;
}

void
PiecePrintVisitor::visit (Pawn& pawn)
{
  if (pawn.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "P"/*\033[37m"*/;
}

void
PiecePrintVisitor::visit (Rook& rook)
{
  if (rook.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "R"/*\033[37m"*/;
}

void
PiecePrintVisitor::visit (Bishop& bishop)
{
  if (bishop.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "B"/*\033[37m"*/;
}

void
PiecePrintVisitor::visit (Knight& knight)
{
  if (knight.color_get () == WHITE)
    std::cout << /*"\033[33m*/"w";
  else
    std::cout << /*"\033[32m*/"b";
  std::cout << "N"/*\033[37m"*/;
}
