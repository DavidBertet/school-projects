#ifndef BS_TRACK_HH_
# define BS_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class BsTrack : public Instr
{
  public:
    BsTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !BS_TRACK_HH_ */
