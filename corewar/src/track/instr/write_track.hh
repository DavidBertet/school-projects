#ifndef WRITE_TRACK_HH_
# define WRITE_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class WriteTrack : public Instr
{
  public:
    WriteTrack (std::string name);
    virtual void exec (ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !WRITE_TRACK_HH_ */
