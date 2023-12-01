#ifndef TRACK_PHANTOM_HH_
# define TRACK_PHANTOM_HH_

# include <list>
# include "track_rapier.hh"

class TrackPhantom: public TrackRapier
{
  public:
    TrackPhantom ();
    bool is_rail (int entree_pc);
    bool is_blue_arrow (int entree_pc);
  private:
    std::list<int> last_write;
};

#endif // !TRACK_PHANTOM_HH_
