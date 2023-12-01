#include <assert.h>
#include "pheromone.hh"

Pheromone::Pheromone ()
{
  this->quantity_ = 0;
}

int
Pheromone::quantity_get () const
{
  return this->quantity_;
}

void
Pheromone::quantity_set (int quantity)
{
  this->quantity_ = quantity;
}

void
Pheromone::add_quantity (int nb)
{
  this->quantity_ += nb;
}

void
Pheromone::sub_quantity (int nb)
{
  if (this->quantity_ - nb >= 0)
    this->quantity_ -= nb;
}
