#ifndef STAT_TRACK_HH_
# define STAT_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class StatTrack : public Instr
{
  public:
    StatTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector * proc);
  private:
    ProcessorVector* proc_;
    void stat_4 (ProcessorVector * proc);
    void stat_5 (ProcessorVector * proc);
    void stat_6 (ProcessorVector * proc);
    void stat_9 (ProcessorVector * proc);
    void stat_12 (ProcessorVector * proc);
    void stat_13 (ProcessorVector * proc);
    void stat_14 (ProcessorVector * proc);
    void stat_15 (ProcessorVector * proc);
};

#endif /* !STAT_TRACK_HH_ */
