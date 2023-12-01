#include <iostream>
#include <string>
#include <sstream>
#include "swp_track.hh"
#include "fetchqueue.hh"

SwpTrack::SwpTrack (std::string name)
  : Instr (name)
{
}

std::string
SwpTrack::text_get (ProcessorVector* proc)
{
  std::stringstream ss;

  Quartet q_rx = proc->queue_get ().quartet_get (2);
  Quartet q_ry = proc->queue_get ().quartet_get (3);

  short rx = q_rx.quartet_get ();
  short ry = q_ry.quartet_get ();

  ss << "swp" << " r" << rx << ", r" << ry;

  if (ss.str ().size () < 15)
  {
    std::stringstream ss1;

    for (unsigned int i = 0; i < 15 - ss.str ().size (); ++i)
    {
      ss1 << " ";
    }
    ss1 << ss.str ();

    return ss1.str ();
  }

  return ss.str ();
}

void
SwpTrack::exec (ProcessorVector* proc)
{
  Quartet q_rx = proc->queue_get ().quartet_get (2);
  Quartet q_ry = proc->queue_get ().quartet_get (3);

  short rx = proc->registers_get (q_rx.quartet_get ());
  short ry = proc->registers_get (q_ry.quartet_get ());

  proc->registers_set (rx, q_ry.quartet_get ());
  proc->registers_set (ry, q_rx.quartet_get ());
}
