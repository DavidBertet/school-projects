#include <iostream>
#include "waterworker.hh"

WaterWorker::WaterWorker (int x, int y, int team)
  : KillableAnt (5, x, y, team)
{
  this->charged_ = 0;
}

void
WaterWorker::charged ()
{
  this->charged_ = 1;
}

void
WaterWorker::uncharged ()
{
  this->charged_ = 0;
}

bool
WaterWorker::is_charged () const
{
  return this->charged_;
}
