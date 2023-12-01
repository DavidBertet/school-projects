#ifndef MODULO_HH_
# define MODULO_HH_

# include "ast.hh"

class Modulo : public Ast
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

#endif // !MODULO_HH_
