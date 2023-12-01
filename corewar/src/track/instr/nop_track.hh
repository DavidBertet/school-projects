#ifndef NOP_HH_
# define NOP_HH_

# include "processor_vector.hh"
# include "instr.hh"

class NopTrack : public Instr
{
  public:
    NopTrack (std::string name);

    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !NOP_HH_ */
