#ifndef ASR_TRACK_HH_
# define ASR_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class AsrTrack : public Instr
{
  public:
    AsrTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !ASR_TRACK_HH_ */
