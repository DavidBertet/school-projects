#ifndef BUFFER_HH_
# define BUFFER_HH_

# include "quartet.hh"

class Buffer
{
  public:
    Quartet	read_quartet (int address);
    void	write_quartet (Quartet quartet, int address);

  private:
    Quartet buffer_[64];
};

#endif /* !BUFFER_HH_ */
