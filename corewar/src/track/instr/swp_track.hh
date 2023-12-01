#ifndef SWP_TRACK_HH_
# define SWP_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class SwpTrack : public Instr
{
  public:
    SwpTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !SWP_TRACK_HH_ */
