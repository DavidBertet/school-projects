#ifndef AST_HH_
# define AST_HH_

#include "visitor.hh"

class Ast
{
public:
  virtual void accept(Visitor& input) = 0;
};

#endif // AST_HH_
