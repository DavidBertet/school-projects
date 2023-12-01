#ifndef ERROR_HH_
# define ERROR_HH_

# include <string>
# include <iostream>

namespace error
{
  class Error
  {
    public:
      Error (std::string str);

      void print (std::ostream& output);

    protected:
      std::string str_;
  };
}

#endif /* !ERROR_HH_ */
