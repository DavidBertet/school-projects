#include <iostream>
#include <string>
#include <sstream>
#include "quartet.hh"
#include "track_vector.hh"
#include "ldb_track.hh"
#include "fetchqueue.hh"

LdbTrack::LdbTrack (std::string name)
  : Instr (name)
{
}

std::string
LdbTrack::text_get (ProcessorVector* proc)
{
  std::stringstream ss;

  Quartet q_size1 = proc->queue_get ().quartet_get (5);
  Quartet q_size2 = proc->queue_get ().quartet_get (6);

  char size1 = q_size1.quartet_get ();
  char size2 = q_size2.quartet_get ();

  char size = (size2 << 4) | size1;

  int size_int = size;

  Quartet q_jump = proc->queue_get ().quartet_get (2);
  Quartet q_pos1 = proc->queue_get ().quartet_get (3);
  Quartet q_pos2 = proc->queue_get ().quartet_get (4);

  short jump = q_jump.quartet_get ();

  char pos1 = q_pos1.quartet_get ();
  char pos2 = q_pos2.quartet_get ();

  char pos = (pos2 << 4) | pos1;

  int pos_int = pos;

  ss << "ldb [r" << jump << "], " << pos_int << ", " << size_int;

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
LdbTrack::exec (ProcessorVector* proc)
{
  Quartet q_size1 = proc->queue_get ().quartet_get (5);
  Quartet q_size2 = proc->queue_get ().quartet_get (6);

  char size1 = q_size1.quartet_get ();
  char size2 = q_size2.quartet_get ();

  char size = (size2 << 4) | size1;

  int size_int = size;

  if (size_int == 0)
  {
    //return to fetch mode
    proc->mode_set (0);

    //clear waiting cycle
    proc->waiting_cycles_set (0);

    //clear fetch queue
    proc->queue_get ().clear_queue ();

    return;
  }

  if (proc->reexecute_get () == -1)
  {
    proc->reexecute_set (size_int);
  }
  else
  {
    Quartet q_jump = proc->queue_get ().quartet_get (2);
    Quartet q_pos1 = proc->queue_get ().quartet_get (3);
    Quartet q_pos2 = proc->queue_get ().quartet_get (4);

    short jump = proc->registers_get (q_jump.quartet_get ()) %
      Delays::get_instance ().idx_mod_get (proc->ship_type_get ());
    jump += proc->pc_get ();
    jump += size_int - proc->reexecute_get ();

    char pos1 = q_pos1.quartet_get ();
    char pos2 = q_pos2.quartet_get ();

    char pos = (pos2 << 4) | pos1;

    int pos_int = (pos + size_int - proc->reexecute_get ());

    proc->buffer_set
      (proc->track_get ()->read_quartet (jump)->quartet_get (), pos_int % 64);
  }
}
