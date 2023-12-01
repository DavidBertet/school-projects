#include <iostream>
#include <string>
#include <sstream>
#include "mode_track.hh"
#include "fetchqueue.hh"

ModeTrack::ModeTrack (std::string name)
  : Instr (name)
{
}

std::string
ModeTrack::text_get (ProcessorVector* proc)
{
  proc = proc;

  int ship_type = proc->queue_get ().quartet_get (2).quartet_get ();

  std::stringstream oss;
  oss << "mode " << ship_type;

  if (oss.str ().size () < 15)
  {
    std::stringstream ss1;

    for (unsigned int i = 0; i < 15 - oss.str ().size (); ++i)
    {
      ss1 << " ";
    }
    ss1 << oss.str ();

    return ss1.str ();
  }
  return oss.str ();
}

void
ModeTrack::exec (ProcessorVector* proc)
{
  int ship_type = proc->queue_get ().quartet_get (2).quartet_get ();

  proc->ship_type_set (ship_type);
}
