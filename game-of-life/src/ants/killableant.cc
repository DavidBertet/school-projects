#include <iostream>
#include "killableant.hh"

KillableAnt::KillableAnt (int life, int x, int y, int team)
  : Ant (x, y, team)
{
  this->life_ = life;
}

KillableAnt::~KillableAnt ()
{
}

void
KillableAnt::sub_life (int hit)
{
  if (this->life_ - hit < 1)
    std::cout << "";     //she is dead

  this->life_ -= hit;
}

int
KillableAnt::life_get () const
{
  return this->life_;
}
