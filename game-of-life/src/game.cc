#include <iostream>
#include <assert.h>
#include "game.hh"
#include "error/maperror.hh"

Game::Game ()
{
  this->cycle_ = 0;
}

Team*
Game::get_team (int number)
{
  int size;

  size = this->teams_.size ();
  if (number >= size)
    return 0;

  if (size > 9)
    throw Error::MapError("Map Not Well Formed: Too much team", -1);

  return this->teams_[number];
}

Team*
Game::team_get (int number) const
{
  int size;

  size = this->teams_.size ();
  if (number >= size)
    return 0;

  if (size > 9)
    throw Error::MapError("Map Not Well Formed: Too much team", -1);

  return this->teams_[number];
}

int
Game::nb_teams () const
{
  return this->teams_.size ();
}

int
Game::add_team ()
{
  Team* team = new Team;

  this->teams_.push_back (team);

  return this->teams_.size () - 1;
}

int
Game::cycle_get () const
{
  return this->cycle_;
}

void
Game::cycle_inc ()
{
  ++this->cycle_;
}

void
Game::do_loop ()
{
  for (unsigned int i = 0; i < this->teams_.size (); ++i)
    {
      std::cout << "  team " << (i + 1) << " is playing" << std::endl;
      (*this->teams_[i]).move ();
    }
}
