#ifndef TRACK_VECTOR_HH_
# define TRACK_VECTOR_HH_

#include <vector>
#include "data.h"
#include "quartet.hh"
#include "processor_vector.hh"
#include "delays.hh"
#include <map>

class TrackVector
{
  public:
    TrackVector ();
    Quartet* read_quartet (int address);
    void write_quartet_buff (char value,
			     int address);
    void write_quartet (char quartet,
			int& address);
    void run ();
    void write_race  ();
    bool up_track ();
    void print ();
    void print_head (int nb_ship,
		     std::string ship_name,
		     std::string comment);
  private:
    void win_up (int win,
		 std::vector<ProcessorVector*> ship_vect);
    std::string got_mode (ProcessorVector* proc);
    void print_cycle (std::stringstream& oss);
    void init_race ();
    void test_nb_ship (int nb_ship);
    int cycle_;
    std::vector<Quartet> track_;
    std::vector<ProcessorVector*> processors_;
    // bufffer of writing
    std::multimap<int, char> writting_buf_;
};

#endif // !TRACK_VECTOR_HH_
