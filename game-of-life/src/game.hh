/*!
**@file   game.hh
**@author david bertet
**@date   Thu Dec 18 23:25:31 2008
**
**@brief  Center of the game
**
**
*/

#ifndef GAME_HH_
# define GAME_HH_

# include <vector>
# include "team.hh"

/*!
** @class Game
**
** @brief Center of the game
*/
class Game
{
public:
/*!
** @brief Constructor of Game
**
*/
  Game ();
/*!
** @brief Return the team instance wanted
**
** @param number Number of the team
**
** @return Instance of Team wanted
*/
  Team* get_team (int number); // norme
/*!
** @brief Return the team instance wanted
**
** @param number Number of the team
**
** @return Instance of Team wanted
*/
  Team* team_get (int number) const;
/*!
** @brief Return the number of teams
**
** @return Return the number of teams
*/
  int	nb_teams () const;
/*!
** @brief Add a team on the team vector
**
** @return Return the number of the team created
*/
  int	add_team ();
/*!
** @brief Do a loop
**
*/
  void	do_loop ();
/*!
** @brief Return the number of cycle done
**
** @return Return the number of cycle done
*/
  int	cycle_get () const;
/*!
** @brief Increment the number of cycle
**
*/
  void	cycle_inc ();
private:
  int			cycle_;
  std::vector <Team*>	teams_;
};

#endif /* !GAME_HH_ */
