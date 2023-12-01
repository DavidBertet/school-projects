#ifndef EXEPTION_HH_
# define EXEPTION_HH_
# include <string>

class Error
{
public:
  Error ();
  Error (std::string error, int ret = 1);
  void	display_error () const;
  int	ret_get ();
private:
  std::string error_;
  int ret_;
};

#endif //! EXEPTION_HH_
