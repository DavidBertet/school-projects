#ifndef COMMON_AI_HH_
# define COMMON_AI_HH_

# include <string>

/// Chess game includes



# include "player.hh"



/*!
** \brief Artificial Intelligence interface.
**
** Artificial Intelligence abstract class.
** Define the interface.
*/
class Ai: public Player
{
public:

  Ai (Color color);

  /*!
  ** \brief Destructor.
  */
  virtual
  ~Ai ();

  /*!
  ** \brief Return the AI author name.
  **
  ** @return the AI author name
  */
  virtual const std::string&
  name_get () const = 0;
};



# include "ai.hxx"

#endif // !AI_HH_

