/*!
**@file   killableant.hh
**@author david bertet
**@date   Thu Dec 18 22:48:21 2008
**
**@brief  Contain killable Ant
**
**
*/

#ifndef KILLABLEANT_HH_
# define KILLABLEANT_HH_

# include "ant.hh"

/*!
** @class KillableAnt
**
** @brief Contain a killable Ant
*/
class KillableAnt : public Ant
{
public:
/*!
** @brief Constructor of KillableAnt
**
** @param life Life of the Ant
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
**
*/
  KillableAnt (int life, int x, int y, int team);
/*!
** @brief Destructor of KillableAnt
**
*/
  virtual ~KillableAnt ();
/*!
** @brief Subtract life
**
** @param hit Number of life subtract
*/
  void sub_life (int hit);
/*!
** @brief Return the rest of life of the Ant
**
** @return Return the rest of life of the Ant
*/
  int life_get () const;
protected:
  int life_;
};

#endif /* !KILLABLEANT_HH_ */
