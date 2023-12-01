#include <iostream>
#include "bs_track.hh"
#include "fetchqueue.hh"
#include <string>
#include <sstream>
#include "delays.hh"

BsTrack::BsTrack (std::string name)
  : Instr (name)
{
}

std::string
BsTrack::text_get (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  int rx = q_rx.quartet_get ();

  std::stringstream ss;
  ss << "bs r" << rx;
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
BsTrack::exec (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  int n_rx = q_rx.quartet_get ();
  int pc = proc->pc_get ();

  unsigned short rx = proc->registers_get (n_rx);
  int mode = proc->ship_type_get ();
  unsigned short idx_mod = Delays::get_instance ().idx_mod_get (mode);

  if (proc->s_get ())
  {
    if (rx > idx_mod)
    {
      rx = rx % idx_mod;
      rx = rx - idx_mod;
    }
    pc = (pc + rx);
    proc->pc_set (pc);
    proc->w0_set (proc->w0_get () + rx);
  }
}
