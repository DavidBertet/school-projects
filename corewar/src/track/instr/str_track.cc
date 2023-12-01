#include <iostream>
#include <string>
#include <sstream>
#include "quartet.hh"
#include "track_vector.hh"
#include "str_track.hh"
#include "fetchqueue.hh"

StrTrack::StrTrack (std::string name)
  : Instr (name)
{
}

std::string
StrTrack::text_get (ProcessorVector* proc)
{
  std::stringstream ss;

  Quartet q_rx = proc->queue_get ().quartet_get (1);
  Quartet q_ry = proc->queue_get ().quartet_get (2);

  short rx = q_rx.quartet_get ();
  short ry = q_ry.quartet_get ();

  ss << "   str [r" << rx << "], r" << ry;

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
StrTrack::exec (ProcessorVector* proc)
{
  if (proc->reexecute_get () == -1)
  {
    proc->reexecute_set (4);
  }
  else
  {
    Quartet q_pos = proc->queue_get ().quartet_get (1);
    Quartet q_data = proc->queue_get ().quartet_get (2);

    int pos = proc->registers_get (q_pos.quartet_get ());
    int idx = Delays::get_instance ().idx_mod_get (proc->ship_type_get ());

    pos = (pos + idx) % (2 * idx);

    pos -= idx;

    pos += proc->pc_get ();

    short data = proc->registers_get (q_data.quartet_get ());

    char c[4];

    c[3] = (data & 0xf000) >> 12;
    c[2] = (data & 0xf00) >> 8;
    c[1] = (data & 0xf0) >> 4;
    c[0] = data & 0xf;

    proc->track_get ()->write_quartet_buff (c[4 - proc->reexecute_get ()],
					    (pos + 4 - proc->reexecute_get ())
	 % Delays::get_instance ().memory_size_get ());
  }
}
