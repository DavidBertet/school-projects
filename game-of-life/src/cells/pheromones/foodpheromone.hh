/*!
**@file   foodpheromone.hh
**@author david bertet
**@date   Fri Dec 19 00:16:04 2008
**
**@brief  Food Pheromone for Ant
**
**
*/

#ifndef FOODPHEROMONE_HH_
# define FOODPHEROMONE_HH_

# include <string>
# include "pheromone.hh"

/*!
** @class FoodPheromone
**
** @brief Food Pheromone for Ant
*/
class FoodPheromone : public Pheromone
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

#endif /* !FOODPHEROMONE_HH_ */
