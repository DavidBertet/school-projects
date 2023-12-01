#include "../cells/ground.hh"
#include "../map.hh"
#include "ant.hh"

Ant::Ant (int x, int y, int team)
{
  this->x_ = x;
  this->y_ = y;
  this->team_ = team + 1;
}

Ant::~Ant ()
{
}

int
Ant::team_get () const
{
  return this->team_;
}

int
Ant::x_get () const
{
  return this->x_;
}

int
Ant::y_get () const
{
  return this->y_;
}

void
Ant::move (int x, int y)
{
  Ground* ground_src;
  Ground* ground_dst;

  Map& map = Map::get_instance ();

  if (map.cell_get (this->x_, this->y_) &&
      (ground_src = dynamic_cast <Ground*>
       (map.cell_get (this->x_, this->y_)->content_get ())) &&
      map.cell_get (x, y) &&
      (ground_dst = dynamic_cast <Ground*>
       (map.cell_get (x, y)->content_get ())))
  {
    ground_src->remove_ant ();
    ground_dst->add_ant (this);
  }

  this->x_ = x;
  this->y_ = y;
}
