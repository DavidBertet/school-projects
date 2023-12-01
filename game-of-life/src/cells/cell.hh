/*!
**@file   cell.hh
**@author david bertet
**@date   Thu Dec 18 22:41:14 2008
**
**@brief  Cell on the map
**
**
*/

#ifndef CELL_HH_
# define CELL_HH_

# include "scenery.hh"

/*!
** @class Cell
**
** @brief Cell on the map
*/
class Cell
{
public:
/*!
** @brief Constructor of Cell
**
*/
  Cell ();
/*!
** @brief Set the content of the Cell
**
** @param content Scenery which will be add on the Cell
*/
  void		content_set (Scenery*	content);
/*!
** @brief Get the content of the Cell
**
** @return Return the Scenery contain on the Cell
*/
  Scenery*	content_get () const;
/*!
** @brief Return the status of the Cell
**
** @return Return 1 if the Cell is empty, 0 otherwise
*/
  bool		is_empty () const;
private:
  Scenery*	content_;
};

#endif /* !CELL_HH_ */
