#ifndef CMP_TRACK_HH_
# define CMP_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class CmpTrack : public Instr
{
  public:
    CmpTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !CMP_TRACK_HH_ */
