#include <iostream>
#include <string>
#include <sstream>
#include "write_track.hh"
#include "fetchqueue.hh"

WriteTrack::WriteTrack (std::string name)
  : Instr (name)
{
}

std::string
WriteTrack::text_get (ProcessorVector* proc)
{
  proc = proc;
  Quartet q_rx = proc->queue_get ().quartet_get (2);
  int n_rx = q_rx.quartet_get ();

  std::stringstream ss;
  ss << "write r" << n_rx;

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
WriteTrack::exec (ProcessorVector* proc)
{
  Quartet q_rx = proc->queue_get ().quartet_get (2);

  char rx = proc->registers_get (q_rx.quartet_get ());

  std::cout << rx;
}
