#ifndef STR_TRACK_HH_
# define STR_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class StrTrack : public Instr
{
  public:
    StrTrack (std::string name);
    virtual void exec (ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !STR_TRACK_HH_ */
