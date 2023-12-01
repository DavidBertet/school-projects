#include <iostream>
#include <string>
#include <sstream>
#include "mov_track.hh"
#include "fetchqueue.hh"

MovTrack::MovTrack (std::string name)
  : Instr (name)
{
}

std::string
MovTrack::text_get (ProcessorVector* proc)
{
  std::stringstream ss;

  Quartet q_rx = proc->queue_get ().quartet_get (1);
  Quartet q_ry = proc->queue_get ().quartet_get (2);

  short rx = q_rx.quartet_get ();
  short ry = q_ry.quartet_get ();

  ss << "mov" << " r" << rx << ", r" << ry;

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
MovTrack::exec (ProcessorVector* proc)
{
  //get init quartet
  Quartet q_rx = proc->queue_get ().quartet_get (1);
  Quartet q_ry = proc->queue_get ().quartet_get (2);

  //get value
  short ry = proc->registers_get (q_ry.quartet_get ());

  proc->registers_set (ry, q_rx.quartet_get ());
}
