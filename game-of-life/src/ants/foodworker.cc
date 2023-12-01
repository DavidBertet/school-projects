#include <iostream>
#include "foodworker.hh"

FoodWorker::FoodWorker (int x, int y, int team)
  : KillableAnt (5, x, y, team)
{
  this->charged_ = 0;
}

void
FoodWorker::charged ()
{
  this->charged_ = 1;
}

void
FoodWorker::uncharged ()
{
  this->charged_ = 0;
}

bool
FoodWorker::is_charged () const
{
  return this->charged_;
}
