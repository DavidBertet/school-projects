#ifndef LL_HH_
# define LL_HH_

# include "processor_vector.hh"
# include "instr.hh"

class LlTrack : public Instr
{
  public:
    LlTrack (std::string name);

    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !LL_HH_ */
