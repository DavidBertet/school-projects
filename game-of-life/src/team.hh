/*!
**@file   team.hh
**@author david bertet
**@date   Thu Dec 18 23:19:35 2008
**
**@brief  A team of Ant
**
**
*/

#ifndef TEAM_HH_
# define TEAM_HH_

# include <vector>
# include "ants/ant.hh"
# include "ants/queen.hh"

class Queen;

/*!
** @class Team
**
** @brief A team of Ant
*/
class Team
{
public:
/*!
** @brief Constructor of Team
**
*/
  Team ();
/*!
** @brief Add an Ant on the team vector
**
** @param ant Pointeur to the Ant to add
*/
  void	add_ant (Ant* ant);
/*!
** @brief Move every Ant of the team
**
*/
  void	move ();
/*!
** @brief Return the number of Ant on the team
**
** @return Return the number of Ant on the team
*/
  int	nb_ants () const;
/*!
** @brief Return the Ant at the position
**
** @param pos Number of the Ant of the team vector
**
** @return Return the Ant at the postion
*/
  Ant*	ant_get (int pos) const;
/*!
** @brief Remove an Ant on the team vector
**
** @param ant Pointeur to the Ant to delete.
*/
  void  remove_ant (Ant* ant);
private:
  Queen*		queen_defined_;
  std::vector <Ant*>	ants_;
};

#endif /* !TEAM_HH_ */
