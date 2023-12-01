#ifndef STB_TRACK_HH_
# define STB_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class StbTrack : public Instr
{
  public:
    StbTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !STB_TRACK_HH_ */
