#ifndef MULT_HH_
# define MULT_HH_

# include "ast.hh"

class Mult : public Ast
{
  public:
    virtual void	accept (Visitor& input);
    Ast&		fg_get ();
    Ast&		fd_get ();
    void		fg_set (Ast& n);
    void		fd_set (Ast& n);

  private:
    Ast*	fg_;
    Ast*	fd_;
};

#endif // !MULT_HH_
