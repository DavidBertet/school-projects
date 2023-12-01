#ifndef CHECK_TRACK_HH_
# define CHECK_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class CheckTrack : public Instr
{
  public:
    CheckTrack (std::string name);
    virtual void exec (ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !CHECK_TRACK_HH_ */
