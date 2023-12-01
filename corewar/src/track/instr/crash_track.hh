#ifndef CRASH_HH_
# define CRASH_HH_

# include "processor_vector.hh"
# include "instr.hh"

class CrashTrack : public Instr
{
  public:
    CrashTrack (std::string name);

    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
};

#endif /* !CRASH_HH_ */
