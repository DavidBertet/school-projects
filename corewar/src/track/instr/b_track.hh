#ifndef B_TRACK_HH_
# define B_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class BTrack : public Instr
{
  public:
    BTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !B_TRACK_HH_ */
