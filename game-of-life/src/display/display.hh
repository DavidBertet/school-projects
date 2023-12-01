/*!
**@file   display.hh
**@author david bertet
**@date   Thu Dec 18 22:04:21 2008
**
**@brief  Used to display the game
**
**
*/

#ifndef DISPLAY_HH_
# define DISPLAY_HH_

# include <string>

/*!
** @class Display
**
** @brief Used to display the game
**
*/
class Display
{
public:
/*!
** @brief Constructor of Display
**
** @param verbose_level Fixed the verbose_level
*/
    Display (int verbose_level);
/*!
** @brief Print verbose of type 1
**
** @param msg Message to print
*/
  virtual void print_verbose1 (std::string msg) = 0;
/*!
** @brief Print verbose of type 2
**
** @param msg Message to print
*/
  virtual void print_verbose2 (std::string msg) = 0;
/*!
** @brief Print verbose of type 3
**
** @param msg Message to print
*/
  virtual void print_verbose3 (std::string msg) = 0;
protected:
    int verbose_level_;
};

#endif /* !DISPLAY_HH_ */
