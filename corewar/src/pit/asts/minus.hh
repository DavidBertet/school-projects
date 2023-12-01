#ifndef MINUS_HH_
# define MINUS_HH_

# include "ast.hh"

class Minus : public Ast
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

#endif // !MINUS_HH_
