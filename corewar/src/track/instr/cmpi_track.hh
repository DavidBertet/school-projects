#ifndef CMPI_TRACK_HH_
# define CMPI_TRACK_HH_

# include "processor_vector.hh"
# include "instr.hh"

class CmpiTrack : public Instr
{
  public:
    CmpiTrack (std::string name);
    virtual void exec (ProcessorVector * proc);
    virtual std::string text_get (ProcessorVector* proc);
};

#endif /* !CMPI_TRACK_HH_ */
