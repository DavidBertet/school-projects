#ifndef B_HH_
# define B_HH_

# include "ast.hh"

class B : public Ast
{
  public:
    virtual void	accept (Visitor& input);
    int			rx_get ();
    int			ry_get ();
    Ast&		n_get ();
    int			n_eval_get ();
    Ast&		m_get ();
    int			m_eval_get ();
    void		rx_set (int rx);
    void		ry_set (int ry);
    void		n_set (Ast& n);
    void		n_eval_set (int n_eval);
    void		m_set (Ast& n);
    void		m_eval_set (int n_eval);

  private:
    int		rx_;
    int		ry_;
    Ast*	n_;
    Ast*	m_;
    int		m_eval_;
    int		n_eval_;
};

#endif // !B_HH_
