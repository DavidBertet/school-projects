#ifndef FETCHQUEUE_HH_
# define FETCHQUEUE_HH_

# include <string>
# include <iostream>
# include <map>
# include "quartet.hh"
# include "instr.hh"

class Fetchqueue
{
  public:
    Fetchqueue ();
    bool	is_instruction ();
    std::string get_instruction_name ();

    void add_quartet (Quartet& quartet);
    Quartet quartet_get (int pos) const;
    void clear_queue ();
    Instr* instr_get ();

    std::string str_queue_get ();
    void print (std::ostream& o);

    int	index_get ();

  private:
    Quartet	queue_[7];
    int		index_;
    std::string	name_;
    std::map<int, std::pair<Instr*, int> > map_instr_;
};

#endif /* !FETCHQUEUE_HH_ */
