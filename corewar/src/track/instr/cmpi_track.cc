#include <iostream>
#include "cmpi_track.hh"
#include "fetchqueue.hh"
#include <string>
#include <sstream>

CmpiTrack::CmpiTrack (std::string name)
  : Instr (name)
{
}

std::string
CmpiTrack::text_get (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  Quartet q_n0 = queue.quartet_get (3);
  Quartet q_n1 = queue.quartet_get (4);

  int n_rx = q_rx.quartet_get ();
  char n0 = q_n0.quartet_get ();
  char n1 = q_n1.quartet_get ();
  char n = (n1 << 4) | n0;
  int n_int = n;

  std::stringstream ss;
  ss << "cmpi r" << n_rx << ", " << std::hex << n_int << std::dec;

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
CmpiTrack::exec (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  Quartet q_n0 = queue.quartet_get (3);
  Quartet q_n1 = queue.quartet_get (4);

  int n_rx = q_rx.quartet_get ();
  char n0 = q_n0.quartet_get ();
  char n1 = q_n1.quartet_get ();
  char n = (n1 << 4) | n0;
  int n_int = n;
  short rx = proc->registers_get (n_rx);

  rx -= n_int;
  proc->z_set (rx == 0);
  proc->s_set (rx < 0);
}
