#include <iostream>
#include "stat_track.hh"
#include "fetchqueue.hh"
#include <string>
#include <sstream>
#include "delays.hh"

StatTrack::StatTrack (std::string name)
  : Instr (name)
{
}

std::string
StatTrack::text_get (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  Quartet q_n = queue.quartet_get (3);

  int n = q_n.quartet_get ();
  int n_rx = q_rx.quartet_get ();

  std::stringstream ss;
  ss << "stat r" << n_rx << ", " << n;

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
StatTrack::exec (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  Quartet q_n = queue.quartet_get (3);
  int n = q_n.quartet_get ();
  int n_rx = q_rx.quartet_get ();

  int rx;

  if (n == 0)
    rx = 0;
  else if (n == 1)
    rx = Delays::get_instance ().mode_get  ();
  else if (n == 2)
    rx = proc->pc_get ();
  else if (n == 3)
    rx = proc->w0_get ();
  else if (n == 4)
    rx = proc->last_zone_check_get ();
  else if (n == 5)
    rx = proc->start_address_get ();
  else if (n == 6)
    rx = Delays::get_instance ().memory_size_get ();
  else if (n == 7)
    rx = Delays::get_instance ().laps_number_get ();
  else if (n == 8)
    rx = Delays::get_instance ().checkpoints_per_lap_get ();
  else if (n == 9)
    stat_9 (proc);
  else if (n == 10)
    rx = Delays::get_instance ().checkpoint_delay_get ();
  else if (n == 11)
    rx = proc->cycles_left_check_get ();
  else if (n == 12)
    stat_12 (proc);
  else if (n == 13)
    stat_13 (proc);
  else if (n == 14)
    stat_14 (proc);
  else
    stat_15 (proc);
  proc->registers_set (rx, n_rx);
}

void
StatTrack::stat_5 (ProcessorVector* proc)
{
  proc = proc;
}

void
StatTrack::stat_9 (ProcessorVector* proc)
{
  int lap = Delays::get_instance ().checkpoints_per_lap_get ();
  int mem = Delays::get_instance ().memory_size_get ();
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  int n_rx = q_rx.quartet_get ();

  int rx = lap / mem;
  proc->registers_set (rx, n_rx);
}

void
StatTrack::stat_12 (ProcessorVector* proc)
{
  proc = proc;
}

void
StatTrack::stat_13 (ProcessorVector* proc)
{
  proc = proc;
}

void
StatTrack::stat_14 (ProcessorVector* proc)
{
  proc = proc;
}

void
StatTrack::stat_15 (ProcessorVector* proc)
{
  Fetchqueue queue;
  queue = proc->queue_get ();
  Quartet q_rx = queue.quartet_get (2);
  int n_rx = q_rx.quartet_get ();

  int rx = proc->registers_get (n_rx);
  rx &= 0x1100;
  if (proc->z_get ())
    rx |= 0x0001;
  if (proc->s_get ())
    rx |= 0x0010;
  proc->registers_set (rx, n_rx);
}
