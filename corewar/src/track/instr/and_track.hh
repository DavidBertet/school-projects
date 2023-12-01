#ifndef AND_TRACK_HH_
# define AND_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class AndTrack : public Instr
{
  public:
    AndTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !AND_TRACK_HH_ */
