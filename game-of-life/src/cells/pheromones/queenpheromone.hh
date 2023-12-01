/*!
**@file   queenpheromone.hh
**@author david bertet
**@date   Fri Dec 19 00:09:47 2008
**
**@brief  Queen Pheromone for Ant
**
**
*/

#ifndef QUEENPHEROMONE_HH_
# define QUEENPHEROMONE_HH_

# include <string>
# include "pheromone.hh"

/*!
** @class QueenPheromone
**
** @brief Queen Pheromone for Ant
*/
class QueenPheromone : public Pheromone
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

#endif /* !QUEENPHEROMONE_HH_ */
