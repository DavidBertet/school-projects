#ifndef OR_TRACK_HH_
# define OR_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class OrTrack : public Instr
{
  public:
    OrTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !OR_TRACK_HH_ */
