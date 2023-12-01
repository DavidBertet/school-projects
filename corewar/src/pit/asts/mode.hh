#ifndef MODE_HH_
# define MODE_HH_

# include "ast.hh"

class Mode : public Ast
{
  public:
    virtual void	accept (Visitor& input);
    int			rx_get ();
    Ast&		m_get ();
    int			m_eval_get ();
    void		rx_set (int rx);
    void		m_set (Ast& n);
    void		m_eval_set (int n_eval);

  private:
    int		rx_;
    Ast*	m_;
    int		m_eval_;
};

#endif // !MODE_HH_
