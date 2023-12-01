/*!
**@file   pheromone.hh
**@author david bertet
**@date   Fri Dec 19 00:10:49 2008
**
**@brief  Abstract class of a pheromone
**
**
*/

#ifndef PHEROMONE_HH_
# define PHEROMONE_HH_

# include <string>

/*!
** @class Pheromone
**
** @brief Abstract class of a pheromone
*/
class Pheromone
{
public:
/*!
** @brief Constructor of Pheromone
**
*/
  Pheromone ();
/*!
** @brief Return the number of Pheromone
**
** @return Return the number of Pheromone
*/
  int quantity_get () const;
/*!
** @brief Set quantity of pheromone
**
** @param quantity Number of pheromone for init
*/
  void quantity_set (int quantity);
/*!
** @brief Add pheromone
**
** @param nb Number of pheromone(s) added
*/
  void add_quantity (int nb);
/*!
** @brief Subtract pheromone
**
** @param nb Number of pheromone(s) subtract
*/
  void sub_quantity (int nb);
/*!
** @brief Return the name of the pheromone
**
** @return Return the name of the pheromone
*/
  virtual std::string who_i_am () = 0;
private:
  int quantity_;
};

#endif /* !PHEROMONE_HH_ */
