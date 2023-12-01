#ifndef LDB_TRACK_HH_
# define LDB_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class LdbTrack : public Instr
{
  public:
    LdbTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !LDB_TRACK_HH_ */
