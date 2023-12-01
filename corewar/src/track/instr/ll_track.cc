#include <string>
#include <iostream>
#include <sstream>
#include "ll_track.hh"

LlTrack::LlTrack (std::string name)
  : Instr (name)
{
}

std::string
LlTrack::text_get (ProcessorVector * proc)
{
  std::stringstream ss;

  Quartet q_rx = proc->queue_get ().quartet_get (2);
  Quartet q_n0 = proc->queue_get ().quartet_get (3);
  Quartet q_n1 = proc->queue_get ().quartet_get (4);
  Quartet q_n2 = proc->queue_get ().quartet_get (5);
  Quartet q_n3 = proc->queue_get ().quartet_get (6);

  int rx = q_rx.quartet_get ();
  short n0 = q_n0.quartet_get ();
  short n1 = q_n1.quartet_get () << 4;
  short n2 = q_n2.quartet_get () << 8;
  short n3 = q_n3.quartet_get () << 12;

  short result = 0;

  result = result | n0 | n1 | n2 | n3;

  ss << "ll r" << rx << ", " << std::hex << result << std::dec;

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
LlTrack::exec (ProcessorVector* proc)
{
  Quartet q_rx = proc->queue_get ().quartet_get (2);
  Quartet q_n0 = proc->queue_get ().quartet_get (3);
  Quartet q_n1 = proc->queue_get ().quartet_get (4);
  Quartet q_n2 = proc->queue_get ().quartet_get (5);
  Quartet q_n3 = proc->queue_get ().quartet_get (6);

  short rx = q_rx.quartet_get ();
  short n0 = q_n0.quartet_get ();
  short n1 = q_n1.quartet_get () << 4;
  short n2 = q_n2.quartet_get () << 8;
  short n3 = q_n3.quartet_get () << 12;

  short result = 0;

  result = result | n0 | n1 | n2 | n3;

  proc->registers_set (result, rx);
}
