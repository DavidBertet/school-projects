#ifndef BZ_TRACK_HH_
# define BZ_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class BzTrack : public Instr
{
  public:
    BzTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !BZ_TRACK_HH_ */
