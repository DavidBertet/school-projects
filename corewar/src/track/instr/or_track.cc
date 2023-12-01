#include <iostream>
#include "or_track.hh"
#include "fetchqueue.hh"
#include <string>
#include <sstream>

OrTrack::OrTrack (std::string name)
  : Instr (name)
{
}

std::string
OrTrack::text_get (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (1);
  Quartet q_ry = queue.quartet_get (2);

  int n_rx = q_rx.quartet_get ();
  int n_ry = q_ry.quartet_get ();

  std::stringstream ss;
  ss << "or r" << n_rx << ", r" << n_ry;
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
OrTrack::exec (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (1);
  Quartet q_ry = queue.quartet_get (2);

  int n_rx = q_rx.quartet_get ();
  int n_ry = q_ry.quartet_get ();
  short rx = proc->registers_get (n_rx);
  short ry = proc->registers_get (n_ry);

  rx |= ry;
  proc->z_set (rx == 0);
  proc->s_set (rx < 0);
  proc->registers_set (rx, n_rx);
}
