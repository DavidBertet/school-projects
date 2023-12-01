/*!
**@file   fighter.hh
**@author david bertet
**@date   Thu Dec 18 22:49:12 2008
**
**@brief  Fighter type of Ant
**
**
*/

#ifndef FIGHTER_HH_
# define FIGHTER_HH_

# include "killableant.hh"

/*!
** @class Fighter
**
** @brief Fighter type of Ant
*/
class Fighter : public KillableAnt
{
public:
/*!
** @brief Constructor of Fighter
**
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
**
*/
  Fighter (int x, int y, int team);
private:
};

#endif /* !FIGHTER_HH_ */
