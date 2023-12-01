#include <iostream>
#include "file_loader.hh"
#include "parse_opt.hh"
#include "track_vector.hh"
#include "track_venom.hh"
#include "track_rapier.hh"
#include "track_phantom.hh"
#include "fetchqueue.hh"
#include "quartet.hh"
#include "delays.hh"

int main (int argc, char** argv)
{
  ParseOpt parser_opt;
  TrackVector* track;

  Fetchqueue fetch;

  parser_opt.parse (argc, argv);
  parser_opt.execute_opt ();
  int mode = parser_opt.mode_get ();

  if (mode == 0)
    track = new TrackVector;
  else if (mode == 1)
    track = new TrackVenom;
  else if (mode == 2)
    track = new TrackRapier;
  else if (mode == 3)
    track = new TrackPhantom;

  track->run ();

}
