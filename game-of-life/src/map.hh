/*!
**@file   map.hh
**@author david bertet
**@date   Thu Dec 18 23:26:16 2008
**
**@brief  Define the map
**
**
*/

#ifndef MAP_HH_
# define MAP_HH_

# include <vector>
# include "cells/cell.hh"
# include "cells/scenery.hh"

/*!
** @class Map
**
** @brief Define the map
*/
class Map
{
  public:
/*!
** @brief Static function which permit to get an instance of Map
**
** @return Return the instance of Map
*/
    static Map& get_instance ();
/*!
** @brief Initialise the map
**
** @param w Width of the map
** @param h Height of the map
*/
    void	create_map (int	w, int	h);
/*!
** @brief Return the Cell wanted
**
** @param w X pos of the Cell
** @param h Y pos of the Cell
**
** @return Return the Cell wanted
*/
    Cell*	cell_get (int	w, int	h);
/*!
** @brief Add content on the Cell
**
** @param w X pos of the Cell where is added content
** @param h Y pos of the Cell where is added content
** @param content Scenery which is add on the Cell
*/
    void	add_content (int w, int	h, Scenery* content);
/*!
** @brief Add empty ground on every empty Cell
**
*/
    void	complete_map ();
/*!
** @brief Set the width of the map
**
** @param w Width
*/
    void	w_set (int	w);
/*!
** @brief Set the height of the map
**
** @param h Height
*/
    void	h_set (int	h);
/*!
** @brief Set the seed for the random
**
** @param seed Seed
*/
    void	seed_set (int	seed);
/*!
** @brief Return the width of the map
**
** @return Return the width of the map
*/
    int	w_get () const;
/*!
** @brief Return the height of the map
**
** @return Return the height of the map
*/
    int	h_get () const;
/*!
** @brief Return the seed of the random
**
** @return Return the seed of the random
*/
    int	seed_get () const;
/*!
** @brief Active WaterWorker when a Queen lay
**
*/
    void	active_water ();
/*!
** @brief Active Fighter when a Queen lay
**
*/
    void	active_fighter ();
/*!
** @brief Is Active WaterWorker when a Queen lay
**
** @return Is Active WaterWorker when a Queen lay
*/
    bool	is_water_presence () const;
/*!
** @brief Is Active Fighter when a Queen lay
**
** @return Is Active Fighter when a Queen lay
*/
    bool	is_fighter_presence () const;
/*!
** @brief Set verbose_level
**
** @param verbose_level
*/
    void	verbose_set (int verbose_level);
/*!
** @brief Get verbose_level
**
** @return Return verbose_level
*/
    int		verbose_get () const;
  private:
    typedef std::vector <Cell*> cells_type;
    typedef std::vector <cells_type> map_type;

    Map ();
    int verbose_level_;
    int	w_;
    int	h_;
    int	seed_;
    map_type	map_;
    bool		water_presence_;
    bool		fighter_presence_;
    static Map*	instance_;
};

#endif /* !MAP_HH_ */
