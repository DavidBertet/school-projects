#ifndef ADD_TRACK_HH_
# define ADD_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class AddTrack : public Instr
{
  public:
    AddTrack (std::string name);
    virtual void exec (ProcessorVector* proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !ADD_TRACK_HH_ */
