#include <string>
#include <iostream>
#include "crash_track.hh"

CrashTrack::CrashTrack (std::string name)
  : Instr (name)
{
}

void
CrashTrack::exec (ProcessorVector* proc)
{
  proc = proc;
}

std::string
CrashTrack::text_get (ProcessorVector * proc)
{
  proc = proc;

  return "          crash";
}
