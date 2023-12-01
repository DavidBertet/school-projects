#ifndef INSTR_HH_
# define INSTR_HH_

class ProcessorVector;

class Instr
{
  public:
    Instr (std::string name);
    std::string name_get ();

    virtual void exec (ProcessorVector * proc) = 0;
    virtual std::string text_get (ProcessorVector * proc) = 0;

  private:
    std::string name_;
};

#endif /* !INSTR_HH_ */
