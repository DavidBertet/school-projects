#ifndef ADDI_TRACK_HH_
# define ADDI_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class AddiTrack : public Instr
{
  public:
    AddiTrack (std::string name);
    virtual void exec(ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !ADDI_TRACK_HH_ */
