#include "cell.hh"
#include "scenery.hh"

Cell::Cell ()
{
  this->content_ = 0;
}

void
Cell::content_set (Scenery*	content)
{
  this->content_ = content;
}

Scenery*
Cell::content_get () const
{
  return this->content_;
}

bool
Cell::is_empty () const
{
  return this->content_ == 0 ? 1 : 0;
}
