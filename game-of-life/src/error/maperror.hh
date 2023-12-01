/*!
**@file   maperror.hh
**@author david bertet
**@date   Thu Dec 18 20:33:59 2008
**
**@brief  Throw errors of map
**
*/
#ifndef MAPERROR_HH_
# define MAPERROR_HH_

# include <string>

namespace Error
{
/*!
** @class MapError
**
** @brief Throw errors of map
**
*/
  class MapError
  {
  public:
/*!
** @brief Constructor of MapError
**
** @param error String of error
** @param line Line of error
*/
    MapError (std::string error, int line);
/*!
** @brief Return the formated error
**
** @return Return the formated error
*/
    std::string get_error () const;
  private:
    std::string error_;
    int line_;
  };
}

#endif /* !MAPERROR_HH_ */
