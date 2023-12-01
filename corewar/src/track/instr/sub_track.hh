#ifndef SUB_TRACK_HH_
# define SUB_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class SubTrack : public Instr
{
  public:
    SubTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !SUB_TRACK_HH_ */
