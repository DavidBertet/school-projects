#ifndef NEG_TRACK_HH_
# define NEG_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class NegTrack : public Instr
{
  public:
    NegTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !NEG_TRACK_HH_ */
