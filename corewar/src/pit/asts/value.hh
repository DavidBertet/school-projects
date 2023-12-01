#ifndef VALUE_HH_
# define VALUE_HH_

# include <string>
# include <iostream>
# include "ast.hh"

class Value : public Ast
{
public:
  Value (int	val, std::string	str = "");
  ~Value ();

  virtual void	accept (Visitor& input);
  int		value_get ();
  void		value_set (int n);

private:
  int		value_;
  std::string	str_;
  friend std::ostream&	operator<< (std::ostream& output, const Value& val);

};

std::ostream&	operator<< (std::ostream& output, const Value& val);

#endif // !VALUE_HH_
