#ifndef MODE_TRACK_HH_
# define MODE_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class ModeTrack : public Instr
{
  public:
    ModeTrack (std::string name);
    virtual void exec (ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !MODE_TRACK_HH_ */
