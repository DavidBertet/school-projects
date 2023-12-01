/*!
**@file   ant.hh
**@author david bertet
**@date   Thu Dec 18 22:49:25 2008
**
**@brief  Base of an Ant
**
**
*/

#ifndef ANT_HH_
# define ANT_HH_

/*!
** @class Ant
**
** @brief Base of an Ant
*/
class Ant
{
public:
/*!
** @brief Constructor of Ant
**
** @param x X pos of the Ant
** @param y Y pos of the Ant
** @param team Team of the Ant
*/
  Ant (int x, int y, int team);
/*!
** @brief Return the Team of the Ant
**
** @return Return the Team of the Ant
*/
  int	team_get () const;
/*!
** @brief Return the X pos of the Ant
**
** @return Return the X pos of the Ant
*/
  int	x_get () const;
/*!
** @brief Return the Y pos of the Ant
**
** @return Return the Y pos of the Ant
*/
  int	y_get () const;
/*!
** @brief Move the Ant
**
** @param x New x pos
** @param y New y pos
*/
  void	move (int x, int y);
/*!
** @brief Destructor of Ant
**
*/
  virtual ~Ant ();
private:
  int x_;
  int y_;
  int team_;
};

#endif /* !ANT_HH_ */
