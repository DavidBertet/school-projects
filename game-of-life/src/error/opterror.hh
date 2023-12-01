/*!
**@file   opterror.hh
**@author david bertet
**@date   Fri Dec 19 14:10:40 2008
**
**@brief  Throw errors of option
**
**
*/

#ifndef OPTERROR_HH_
# define OPTERROR_HH_

namespace Error
{
/*!
** @class OptError
**
** @brief Throw errors of option
**
*/
  class OptError
  {
    public:
/*!
** @brief Constructor of OptError
**
** @param error Name of option unknown
*/
      OptError (char error);
/*!
** @brief Return the formated error
**
** @return Return the formated error
*/
      std::string get_error () const;
    private:
      char error_;
  };
}

#endif /* !OPTERROR_HH_ */
