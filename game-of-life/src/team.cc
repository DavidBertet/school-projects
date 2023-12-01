#include <iostream>
#include <assert.h>
#include "ants/ant.hh"
#include "ants/queen.hh"
#include "error/maperror.hh"
#include "rules/standardrules.hh"
#include "team.hh"

Team::Team ()
{
  this->queen_defined_ = 0;
}

void
Team::move ()
{
//   StandardRules rules;

//   for (unsigned int i = 0; i < this->ants_.size (); ++i)
//     rules.move(this->ants_[i]);
}

int
Team::nb_ants () const
{
  return this->ants_.size ();
}

Ant*
Team::ant_get (int pos) const
{
  return this->ants_[pos];
}

void
Team::add_ant (Ant* ant)
{
  Queen* queen;

  if ((queen = dynamic_cast<Queen*> (ant)))
  {
    if (this->queen_defined_ != 0)
      throw Error::MapError("Map Not Well Formed: More than 1 queen found",
			    -1);

    this->queen_defined_ = queen;
  }

  this->ants_.push_back (ant);
}

void
Team::remove_ant (Ant* ant)
{
  unsigned int i;

  for (i = 0; i < this->ants_.size (); ++i)
    if (ant == this->ants_[i])
      break;

  assert (i != this->ants_.size ());

  this->ants_.erase (this->ants_.begin () + i);
}
