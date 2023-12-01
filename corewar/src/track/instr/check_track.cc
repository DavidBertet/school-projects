#include <iostream>
#include <string>
#include <sstream>
#include "delays.hh"
#include "check_track.hh"
#include "fetchqueue.hh"

CheckTrack::CheckTrack (std::string name)
  : Instr (name)
{
}

std::string
CheckTrack::text_get (ProcessorVector* proc)
{
  proc = proc;

  return "          check";
}

void
CheckTrack::exec (ProcessorVector* proc)
{
  int check_per_lap = Delays::get_instance ().checkpoints_per_lap_get ();
  int size_lap = Delays::get_instance ().memory_size_get ();

  int size_between_checkpoints = size_lap / check_per_lap;

  if (proc->w0_get () / size_between_checkpoints >
      proc->last_zone_check_get ())
  {
    int check_delay = Delays::get_instance ().checkpoint_delay_get ();

    proc->cycles_left_check_set (check_delay);

    proc->last_zone_check_set (proc->last_zone_check_get () + 1);
  }
}
