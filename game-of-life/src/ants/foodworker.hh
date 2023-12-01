/*!
**@file   foodworker.hh
**@author david bertet
**@date   Thu Dec 18 22:48:51 2008
**
**@brief  Food Worker type of Ant
**
**
*/

#ifndef FOODWORKER_HH_
# define FOODWORKER_HH_

# include "killableant.hh"

/*!
** @class FoodWorker
**
** @brief Food Worker type of Ant
*/
class FoodWorker : public KillableAnt
{
public:
/*!
** @brief Constructor of FoodWorker
**
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
**
*/
  FoodWorker (int x, int y, int team);
/*!
** @brief Charged the Ant
**
*/
  void	charged ();
/*!
** @brief Uncharged the Ant
**
*/
  void	uncharged ();
/*!
** @brief Return if the Ant is carrying food
**
** @return Return if the Ant is carrying food
*/
  bool	is_charged () const;
private:
  bool charged_;
};

#endif /* !FOODWORKER_HH_ */
