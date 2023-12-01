/*!
**@file   waterpheromone.hh
**@author david bertet
**@date   Fri Dec 19 00:08:44 2008
**
**@brief  Water Pheromone for Ant
**
**
*/

#ifndef WATERPHEROMONE_HH_
# define WATERPHEROMONE_HH_

# include <string>
# include "pheromone.hh"

/*!
** @class WaterPheromone
**
** @brief Water Pheromone for Ant
*/
class WaterPheromone : public Pheromone
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

#endif /* !WATERPHEROMONE_HH_ */
