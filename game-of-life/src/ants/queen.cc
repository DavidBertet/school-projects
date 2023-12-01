#include <iostream>
#include <sstream>
#include <assert.h>
#include "../map.hh"
#include "../team.hh"
#include "foodworker.hh"
#include "waterworker.hh"
#include "fighter.hh"
#include "queen.hh"

Queen::Queen (int x, int y, int team, Team* team_vector)
  : Ant (x, y, team)
{
  this->nb_food_ = 0;
  this->next_type_ant_ = 0;
  this->current_type_ = 0;
  this->team_vector_ = team_vector;
}

Team*
Queen::team_vector_get () const
{
  assert (this->team_vector_ != 0);

  return this->team_vector_;
}

int
Queen::nb_food_get () const
{
  return this->nb_food_;
}

void
Queen::add_food (int nb)
{
  this->nb_food_ += nb;;
}

void
Queen::sub_food (int nb)
{
  assert (this->nb_food_ - nb >= 0);

  this->nb_food_ -= nb;;
}

Ant*
Queen::lay (int x,  int y, int team, std::stringstream& ss)
{
  Ant* ant;
  Map& map = Map::get_instance ();

  if (map.is_water_presence ())
  {
    if (this->current_type_ == 0)
    {
      ant = new FoodWorker(x, y, team);
      ss << "          ant created: food worker";
    }
    if (this->current_type_ == 1)
    {
      ant = new WaterWorker(x, y, team);
      ss << "          ant created: water worker";
    }
    if (this->current_type_ == 2)
    {
      ant = new Fighter(x, y, team);
      ss << "          ant created: fighter";
    }
    ++this->current_type_;
    if (this->current_type_ > 2)
      this->current_type_ = 0;
  }
  else if (map.is_fighter_presence ())
  {
    if (this->current_type_ == 0)
    {
      ant = new FoodWorker(x, y, team);
      ss << "          ant created: food worker";
    }
    if (this->current_type_ == 1)
    {
      ant = new Fighter(x, y, team);
      ss << "          ant created: fighter";
    }
    ++this->current_type_;
    if (this->current_type_ > 1)
      this->current_type_ = 0;
  }
  else
  {
    if (this->current_type_ == 0)
    {
      ant = new FoodWorker(x, y, team);
      ss << "          ant created: food worker";
    }
  }

  return ant;
}
