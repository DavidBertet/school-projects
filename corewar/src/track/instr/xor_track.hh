#ifndef XOR_TRACK_HH_
# define XOR_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class XorTrack : public Instr
{
  public:
    XorTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !XOR_TRACK_HH_ */
