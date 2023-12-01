/*!
**@file   maploader.hh
**@author david bertet
**@date   Thu Dec 18 20:24:39 2008
**
**@brief  Load the map
**
**
*/

#ifndef MAPLOADER_HH_
# define MAPLOADER_HH_

# include <string>
# include <fstream>
# include "../game.hh"

/*!
** @class MapLoader
**
** @brief Load the map from a file
**
*/
class MapLoader
{
public:
/*!
** @brief Constructor of MapLoader
**
** @param game Game where it will load the map
*/
  MapLoader (Game&	game);
/*!
** @brief Load the map passed by argument
**
** @param filename Name of the file
*/
  void loadmap(std::string filename);
/*!
** @brief Parse the file to find keyword
**
*/
  void find_case ();
/*!
** @brief Parse the obstacle bloc
**
*/
  void obstacle_bloc ();
/*!
** @brief Parse the resource bloc
**
*/
  void resource_bloc ();
/*!
** @brief Parse the team bloc
**
*/
  void team_bloc ();

/*!
** @brief Parse a food worker ant
**
** @param line_istream
** @param team
*/
  void	food_worker_case (std::istringstream& line_istream, int team);
/*!
** @brief Parse a water worker ant
**
** @param line_istream
** @param team
*/
  void	water_worker_case (std::istringstream& line_istream, int team);
/*!
** @brief Parse a queen ant
**
** @param line_istream
** @param team
*/
  void	queen_case (std::istringstream& line_istream, int team);
/*!
** @brief Parse a fighter ant
**
** @param line_istream
** @param team
*/
  void	fighter_case (std::istringstream& line_istream, int team);
private:
  std::fstream	fd_;
  std::string	line_;
  int		current_pos_;
  Game*		game_;
};

#endif /* !MAPLOADER_HH_ */
