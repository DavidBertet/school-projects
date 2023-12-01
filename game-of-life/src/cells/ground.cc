#include <string>
#include <assert.h>
#include "pheromones/foodpheromone.hh"
#include "pheromones/waterpheromone.hh"
#include "pheromones/fighterpheromone.hh"
#include "pheromones/queenpheromone.hh"
#include "ground.hh"

Ground::Ground ()
{
  for (int i = 0; i < 10; ++i)
    {
      WaterPheromone* waterpheromone = new WaterPheromone;
      QueenPheromone* queenpheromone = new QueenPheromone;
      FoodPheromone* foodpheromone = new FoodPheromone;
      FighterPheromone* fighterpheromone = new FighterPheromone;

      vect_pher vect_tmp;
      vect_tmp.push_back (fighterpheromone);
      vect_tmp.push_back (foodpheromone);
      vect_tmp.push_back (waterpheromone);
      vect_tmp.push_back (queenpheromone);

      this->pheromones_.push_back (vect_tmp);
    }
  this->empty_ = 1;
}

void
Ground::add_ant (Ant* ant)
{
  this->empty_ = 0;
  this->ant_ = ant;
}

void
Ground::remove_ant ()
{
  this->empty_ = 1;
  this->ant_ = 0;
}

bool
Ground::is_empty ()
{
  return this->empty_;
}

Ant*
Ground::ant_get () const
{
  return this->ant_;
}

Pheromone*
Ground::pheromone_get (std::string type, int team) const
{
  assert (team - 1 >= 0);

  if (type == "PW")
    return this->pheromones_[team - 1][0];
  if (type == "PQ")
    return this->pheromones_[team - 1][1];
  if (type == "PF")
    return this->pheromones_[team - 1][2];
  if (type == "PB")
    return this->pheromones_[team - 1][3];

  assert (0);
  return 0;
}
