#ifndef PROCESSOR_PHANTOM_HH_
# define PROCESSOR_PHANTOM_HH_

# include "processor_rapier.hh"
# include "track_vector.hh"

class ProcessorPhantom : public ProcessorRapier
{
  public:
    ProcessorPhantom (TrackVector* track);
  private:

};

#endif /* !PROCESSOR_PHANTOM_HH_ */
