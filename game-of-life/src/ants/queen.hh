/*!
**@file   queen.hh
**@author david bertet
**@date   Thu Dec 18 22:48:12 2008
**
**@brief  Queen type of Ant
**
**
*/

#ifndef QUEEN_HH_
# define QUEEN_HH_

# include <sstream>
# include "../team.hh"
# include "ant.hh"

class Team;

/*!
** @class Queen
**
** @brief Queen type of Ant
*/
class Queen : public Ant
{
  public:
/*!
** @brief Constructor of Queen
**
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
** @param team_vector Vector of Team of the Ant
**
*/
    Queen (int x, int y, int team, Team* team_vector);
/*!
** @brief Return the number of food taken
**
** @return Return the number of food taken
*/
    int	nb_food_get () const;
/*!
** @brief Add food
**
** @param nb Number of food added
*/
    void	add_food (int nb);
/*!
** @brief Subtract food
**
** @param nb Number of food subtract
*/
    void	sub_food (int nb);
/*!
** @brief Lay an Ant
**
** @param x X of the new Ant
** @param y Y of the new Ant
** @param team Team of the new Ant
** @param ss Verbose
**
** @return Return the layed Ant
*/
    Ant*	lay (int x, int y, int team, std::stringstream& ss);
/*!
** @brief Return the Team Vector of the Ant
**
** @return Return the Team Vector of the Ant
*/
    Team* team_vector_get () const;
  private:
    Team* team_vector_;
    int nb_food_;
    int next_type_ant_;
    int current_type_;
};

#endif /* !QUEEN_HH_ */
