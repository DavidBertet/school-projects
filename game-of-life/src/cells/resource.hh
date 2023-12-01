/*!
**@file   resource.hh
**@author david bertet
**@date   Thu Dec 18 22:19:55 2008
**
**@brief  Resource which can be eat by an Ant
**
**
*/
#ifndef RESOURCE_HH_
# define RESOURCE_HH_

# include "scenery.hh"

/*!
** @class Resource
**
** @brief Resource which can be eat by an Ant
*/
class Resource : public Scenery
{
public:
/*!
** @brief Destructor of Resource
**
*/
  virtual ~Resource ();
private:
};

#endif /* !RESOURCE_HH_ */
