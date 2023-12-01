#ifndef MOVE_ERROR_HH_
# define MOVE_ERROR_HH_

# include <string>
# include <iostream>
# include "error.hh"

namespace error
{
  class MoveError : public Error
  {
    public:
      MoveError (std::string str);
  };
}

#endif /* !MOVE_ERROR_HH_ */
