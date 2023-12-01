/*!
**@file   fighterpheromone.hh
**@author david bertet
**@date   Fri Dec 19 00:17:17 2008
**
**@brief  Fighter Pheromone for Ant
**
**
*/

#ifndef FIGHTERPHEROMONE_HH_
# define FIGHTERPHEROMONE_HH_

# include <string>
# include "pheromone.hh"

/*!
** @class FighterPheromone
**
** @brief Figther Pheromone for Ant
*/
class FighterPheromone : public Pheromone
{
public:
/*!
** @brief Return the name of the pheromone
**
** @return Return the name of the pheromone
*/
  virtual std::string who_i_am ();
private:

};

#endif /* !FIGHTERPHEROMONE_HH_ */
