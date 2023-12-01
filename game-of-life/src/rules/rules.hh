/*!
**@file   rules.hh
**@author david bertet
**@date   Thu Dec 18 20:19:53 2008
**
**@brief  Abstract class for rules
**
**
*/

#ifndef RULES_HH_
# define RULES_HH_

# include "game.hh"

/*!
** @class Rules
**
** @brief Abstract class for rules
**
*/
class Rules
{
public:
/*!
** @brief Constructor of Rules
**
** @param game
*/
  Rules (Game& game);
/*!
** @brief Virtual function to launch the game
**
*/
  virtual void play () = 0;
protected:
  Game* game_;
};

#endif /* !RULES_HH_ */
