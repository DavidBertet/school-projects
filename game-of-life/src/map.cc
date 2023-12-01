#include <sstream>
#include <iostream>
#include <vector>
#include "error/maperror.hh"
#include "cells/scenery.hh"
#include "cells/ground.hh"
#include "map.hh"

Map* Map::instance_ = 0;

Map::Map ()
{
  this->w_ = 0;
  this->h_ = 0;
  this->water_presence_ = 0;
  this->fighter_presence_ = 0;
  this->verbose_level_ = 0;
}

Map&
Map::get_instance ()
{
  if (!instance_)
    instance_ = new Map ();

  return *instance_;
}

void
Map::w_set (int	w)
{
  this->w_ = w;
}

void
Map::h_set (int	h)
{
  this->h_ = h;
}

void
Map::seed_set (int	seed)
{
  this->seed_ = seed;
}

void
Map::verbose_set (int	verbose_level)
{
  this->verbose_level_ = verbose_level;
}

int
Map::w_get () const
{
  return this->w_;
}

int
Map::h_get () const
{
  return this->h_;
}

int
Map::verbose_get () const
{
  return this->verbose_level_;
}

int
Map::seed_get () const
{
  return this->seed_;
}

void
Map::create_map (int	w,
		 int	h)
{
  if (this->w_ != 0)
    throw Error::MapError("More than a map were defined", -1);

  if (w == 0)
    throw Error::MapError("Invalid size of map", -1);

  this->w_ = w;
  this->h_ = h;

  for (int i = 0; i < h; ++i)
  {
    cells_type* vect = new cells_type;
    for (int j = 0; j < w; ++j)
    {
      Cell* cell = new Cell;
      vect->push_back (cell);
    }
    this->map_.push_back (*vect);
  }
}

void
Map::add_content (int		w,
		  int		h,
		  Scenery*	content)
{
  std::stringstream ss;

  if (w - 1 < 0 || h - 1 < 0 || h > this->h_ || w > this->w_)
  {
    ss << "Invalid position : " << w << " " << h;
    throw Error::MapError(ss.str (), -1);
  }

  if (this->map_[h - 1][w - 1]->content_get ())
  {
    ss << "Cell isn't empty at " << w << " " << h;
    throw Error::MapError(ss.str (), -1);
  }

  this->map_[h - 1][w - 1]->content_set (content);
}

void
Map::complete_map ()
{
  for (int i = 0; i < this->h_; ++i)
    for (int j = 0; j < this->w_; ++j)
      if (this->map_[i][j]->is_empty ())
      {
	Ground* ground = new Ground;
	this->map_[i][j]->content_set (ground);
      }
}

Cell*
Map::cell_get (int	w, int	h)
{
  if (w < 0 || h < 0 || w > this->w_ - 1 || h > this->h_ - 1)
    return 0;

  return this->map_[h][w];
}

void
Map::active_water ()
{
  this->water_presence_ = 1;
}

void
Map::active_fighter ()
{
  this->fighter_presence_ = 1;
}

bool
Map::is_fighter_presence () const
{
  return this->fighter_presence_;
}

bool
Map::is_water_presence () const
{
  return this->water_presence_;
}
