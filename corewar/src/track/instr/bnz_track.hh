#ifndef BNZ_TRACK_HH_
# define BNZ_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class BnzTrack : public Instr
{
  public:
    BnzTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
};

#endif /* !BNZ_TRACK_HH_ */
