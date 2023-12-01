/*!
**@file   ascii.hh
**@author david bertet
**@date   Thu Dec 18 22:07:27 2008
**
**@brief  Display the game in ascii type
**
**
*/

#ifndef ASCII_HH_
# define ASCII_HH_

# include "display.hh"

/*!
** @class Ascii
**
** @brief Display the game in ascii type
**
*/
class Ascii : public Display
{
public:
/*!
** @brief Constructor of Ascii
**
** @param verbose_level Fixed the verbose_level
**
** @return
*/
  Ascii (int verbose_level);
/*!
** @brief Lauch display of the game
**
*/
  void	print () const;
/*!
** @brief Print verbose of type 1
**
** @param msg Message to print
*/
  virtual void print_verbose1 (std::string msg);
/*!
** @brief Print verbose of type 2
**
** @param msg Message to print
*/
  virtual void print_verbose2 (std::string msg);
/*!
** @brief Print verbose of type 3
**
** @param msg Message to print
*/
  virtual void print_verbose3 (std::string msg);
private:
};

#endif /* !ASCII_HH_ */
