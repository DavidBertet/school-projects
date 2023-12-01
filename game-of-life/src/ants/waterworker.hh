/*!
**@file   waterworker.hh
**@author david bertet
**@date   Thu Dec 18 22:47:44 2008
**
**@brief  Water Worker type of Ant
**
**
*/

#ifndef WATERWORKER_HH_
# define WATERWORKER_HH_

# include "killableant.hh"

/*!
** @class WaterWorker
**
** @brief Water Worker type of Ant
*/
class WaterWorker : public KillableAnt
{
public:
/*!
** @brief Constructor of WaterWorker
**
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
**
*/
  WaterWorker (int x, int y, int team);
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

#endif /* !WATERWORKER_HH_ */
