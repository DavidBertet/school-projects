/*!
**@file   ground.hh
**@author david bertet
**@date   Thu Dec 18 22:29:09 2008
**
**@brief  Ground where an Ant can be placed
**
**
*/

#ifndef GROUND_HH_
# define GROUND_HH_

# include <vector>
# include <string>
# include "pheromones/pheromone.hh"
# include "scenery.hh"
# include "../ants/ant.hh"

/*!
** @class Ground
**
** @brief Ground where an Ant can be placed
**
*/
class Ground : public Scenery
{
public:
/*!
** @brief Constructor of Ground
**
**
*/
  Ground ();
/*!
** @brief Return the pheromone concerned
**
** @param type Type of the pheromone, can be PB PF PQ or PW
** @param team Team of the ant who search the pheromone
**
** @return Pheromone contain on the ground
*/
  Pheromone* pheromone_get (std::string type, int team) const;
/*!
** @brief Return the status of the ground
**
** @return Return 1 if there is no Ant on the ground, 0 otherwise.
*/
  bool	is_empty ();
/*!
** @brief Add an Ant on the ground
**
** @param ant The Ant whose been add on the ground
*/
  void	add_ant (Ant* ant);
/*!
** @brief Delete the Ant on the ground
**
*/
  void	remove_ant ();
/*!
** @brief Return the Ant on the ground
**
** @return Return the Ant on the ground
*/
  Ant*	ant_get () const;
private:
  bool empty_;
  Ant*	ant_;
  typedef std::vector <Pheromone*> vect_pher;
  std::vector <vect_pher> pheromones_;
};

#endif /* !GROUND_HH_ */
