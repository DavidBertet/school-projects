#ifndef MOV_TRACK_HH_
# define MOV_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class MovTrack : public Instr
{
  public:
    MovTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !MOV_TRACK_HH_ */
