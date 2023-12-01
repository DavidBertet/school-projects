#ifndef NOT_TRACK_HH_
# define NOT_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class NotTrack : public Instr
{
  public:
    NotTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !NOT_TRACK_HH_ */
