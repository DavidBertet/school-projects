#ifndef LC_TRACK_HH_
# define LC_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class LcTrack : public Instr
{
  public:
    LcTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !LC_TRACK_HH_ */
