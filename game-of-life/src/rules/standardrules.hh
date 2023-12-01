/*!
**@file   standardrules.hh
**@author david bertet
**@date   Thu Dec 18 19:56:49 2008
**
**@brief  Rules for the standard game
**
*/

#ifndef STANDARDRULES_HH_
# define STANDARDRULES_HH_

# include "ant.hh"
# include "game.hh"
# include "rules.hh"
# include "fighter.hh"

/*!
** @class StandardRules
**
** @brief Rules for the standard game
**
*/
class StandardRules : public Rules
{
  public:
/*!
** @brief Constructor of StandardRules
**
** @param game
*/
    StandardRules (Game& game);
/*!
** Launch the game
**
*/
    virtual void play ();
/*!
** @brief Move the Ant passed by argument
**
** @param ant Movable Ant
*/
    void move (Ant* ant);
/*!
** @brief Search for an attackable Ant beside a Fighter
**
** @param fighter The Fighter who want to kill an Ant
**
** @return 1 if it found ant, 0 otherwise
*/
    int find_attackable_ant (Fighter *fighter);
/*!
** @brief Try to attack an Ant beside the Fighter passed by argument
**
** @param fighter The Fighter who want to kill an Ant
**
** @return 1 if it kill an Ant, 0 otherwise
*/
    int attack_ant (Fighter* fighter);
  private:
    int verbose_level_;
};

#endif /* !STANDARDRULES_HH_ */
