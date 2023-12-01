#include "ast.hh"
#include "assert.h"
#include <sstream>

Ast& eval_instruction (iter_t const& node)
{
  assert(this->instruction.id () == node->value.id ());
  iter_t child = i->children.begin ();

  if (child  == "crash")
  {
    ++child;
    Ast& crash = *(new Crash);
    return crash;
  }
  if (child == "nop")
  {
    ++child;
    Ast& nop = *(new Nop);
    return nop;
  }
  if (child  == "check")
  {
    ++child;
    Ast& crash = *(new Check);
    return crash;
  }
  if (child  == "fork")
  {
    ++child;
    Ast& crash = *(new Fork);
    return crash;
  }
  if (child == "and")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& And = *(new And);
    And.set_rx (rx);
    And.set_ry (ry);
    return And;
  }
  if (child == "or")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& Or = *(new Or);
    Or.set_rx (rx);
    Or.set_ry (ry);
    return Or;
  }
  if (child == "xor")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& Xor = *(new Xor);
    Xor.set_rx (rx);
    Xor.set_ry (ry);
    return Xor;
  }
  if (child == "not")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& Not = *(new Not);
    Not.set_rx (rx);
    Not.set_ry (ry);
    return Not;
  }
  if (child == "add")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& add = *(new Add);
    add.set_rx (rx);
    add.set_ry (ry);
    return add;
  }
  if (child == "sub")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& sub = *(new Sub);
    sub.set_rx (rx);
    sub.set_ry (ry);
    return sub;
  }
  if (child == "cmp")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& cmp = *(new Cmp);
    cmp.set_rx (rx);
    cmp.set_ry (ry);
    return cmp;
  }
  if (child == "neg")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& neg = *(new Neg);
    neg.set_rx (rx);
    neg.set_ry (ry);
    return neg;
  }
  if (child == "mov")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& mov = *(new Mov);
    mov.set_rx (rx);
    mov.set_ry (ry);
    return mov;
  }
  if (child == "ldr")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& ldr = *(new Ldr);
    ldr.set_rx (rx);
    ldr.set_ry (ry);
    return ldr;
  }
  if (child == "str")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& str = *(new Str);
    str.set_rx (rx);
    str.set_ry (ry);
    return str;
  }
  if (child == "swp")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    int ry = eval_reg (child);
    Ast& swp = *(new Swp);
    swp.set_rx (rx);
    swp.set_ry (ry);
    return swp;
  }
  if (child == "b")
  {
    ++child;
    int rx = eval_reg (child);
    Ast& ast = *(new B);
    ast.set_rx (rx);
    return ast;
  }
  if (child == "bz")
  {
    ++child;
    int rx = eval_reg (child);
    Ast& ast = *(new Bz);
    ast.set_rx (rx);
    return ast;
  }
  if (child == "bnz")
  {
    ++child;
    int rx = eval_reg (child);
    Ast& ast = *(new Bnz);
    ast.set_rx (rx);
    return ast;
  }
  if (child == "bs")
  {
    ++child;
    int rx = eval_reg (child);
    Ast& ast = *(new Bs);
    ast.set_rx (rx);
    return ast;
  }
  if (child == "write")
  {
    ++child;
    int rx = eval_reg (child);
    Ast& ast = *(new Write);
    ast.set_rx (rx);
    return ast;
  }
  if (child == "rol")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Rol);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "asr")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Asr);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "lc")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Lc);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "ll")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Ll);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "addi")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Addi);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "cmpi")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Cmpi);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "stat")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Stat);
    ast.set_rx (rx);
    ast.set_n (n);
    return ast;
  }
  if (child == "ldb")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    ++child;
    Ast& m = eval_exp (child);
    Ast& ast = *(new Rol);
    ast.set_rx (rx);
    ast.set_n (n);
    ast.set_m (m);
    return ast;
  }
  if (child == "stb")
  {
    ++child;
    int rx = eval_reg (child);
    ++child;
    Ast& n = eval_exp (child);
    ++child;
    Ast& m = eval_exp (child);
    Ast& ast = *(new Stb);
    ast.set_rx (rx);
    ast.set_n (n);
    ast.set_m (m);
    return ast;
  }
  if (child == "mode")
  {
    ++child;
    Ast& n = eval_exp (child);
    Ast& ast = *(new Rol);
    ast.set_n (n);
    return ast;
  }
}


int eval_reg (iter_t const& node)
{
  int res;
  std::string str (node->value.begin (), node->value.end ());
  std::istringstream iss (str);

  assert(this->reg.id () == node->value.id ());
  res << iss;
  return res;
}
