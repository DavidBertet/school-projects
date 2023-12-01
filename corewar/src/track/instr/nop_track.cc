#include <string>
#include <iostream>
#include "nop_track.hh"

NopTrack::NopTrack (std::string name)
  : Instr (name)
{
}

void
NopTrack::exec (ProcessorVector* proc)
{
  proc = proc;
}

std::string
NopTrack::text_get (ProcessorVector * proc)
{
  proc = proc;

  return "            nop";
}
