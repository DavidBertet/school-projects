#include <assert.h>
#include <iostream>
#include <sstream>
#include <map>
#include "quartet.hh"
#include "fetchqueue.hh"

#include "instr.hh"
#include "crash_track.hh"
#include "nop_track.hh"
#include "ll_track.hh"
#include "lc_track.hh"
#include "add_track.hh"
#include "sub_track.hh"
#include "cmp_track.hh"
#include "addi_track.hh"
#include "cmpi_track.hh"
#include "neg_track.hh"
#include "asr_track.hh"
#include "mov_track.hh"
#include "swp_track.hh"
#include "check_track.hh"
#include "mode_track.hh"
#include "stat_track.hh"
#include "str_track.hh"
#include "b_track.hh"
#include "bs_track.hh"
#include "bz_track.hh"
#include "bnz_track.hh"
#include "ldb_track.hh"
#include "stb_track.hh"
#include "write_track.hh"
#include "and_track.hh"
#include "or_track.hh"
#include "xor_track.hh"
#include "not_track.hh"

void
init (std::map<int, std::pair<Instr*, int> >& map_instr)
{
  typedef std::pair<Instr *, int> pair_type;

  pair_type my_pair = *new pair_type (new CrashTrack ("crash"), 1);
  map_instr.insert (std::pair<int, pair_type>(0, my_pair));

  my_pair = *new pair_type (new NopTrack ("nop"), 1);
  map_instr.insert (std::pair<int, pair_type>(1, my_pair));

  my_pair = *new pair_type (new AndTrack ("and"), 3);
  map_instr.insert (std::pair<int, pair_type>(2, my_pair));

  my_pair = *new pair_type (new OrTrack ("or"), 3);
  map_instr.insert (std::pair<int, pair_type>(3, my_pair));

  my_pair = *new pair_type (new XorTrack ("xor"), 3);
  map_instr.insert (std::pair<int, pair_type>(4, my_pair));

  my_pair = *new pair_type (new NotTrack ("not"), 3);
  map_instr.insert (std::pair<int, pair_type>(5, my_pair));

//   my_pair = *new pair_type ("rol", 3);
//   map_instr.insert (std::pair<int, pair_type>(6, my_pair));

  my_pair = *new pair_type (new AsrTrack ("asr"), 3);
  map_instr.insert (std::pair<int, pair_type>(7, my_pair));

  my_pair = *new pair_type (new AddTrack ("add"), 3);
  map_instr.insert (std::pair<int, pair_type>(8, my_pair));

  my_pair = *new pair_type (new SubTrack ("sub"), 3);
  map_instr.insert (std::pair<int, pair_type>(9, my_pair));

  my_pair = *new pair_type (new CmpTrack ("cmp"), 3);
  map_instr.insert (std::pair<int, pair_type>(10, my_pair));

  my_pair = *new pair_type (new NegTrack ("neg"), 3);
  map_instr.insert (std::pair<int, pair_type>(11, my_pair));
}

Fetchqueue::Fetchqueue ()
{
  typedef std::pair<Instr *, int> pair_type;

  init (this->map_instr_);

  pair_type my_pair = *new pair_type (new MovTrack ("mov"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(12, my_pair));

//   my_pair = *new pair_type (LdrTrack ("ldr"), 3);
//   this->map_instr_.insert (std::pair<int, pair_type>(13, my_pair));

  my_pair = *new pair_type (new StrTrack ("str"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(14, my_pair));

  my_pair = *new pair_type (new LdbTrack ("ldb"), 7);
  this->map_instr_.insert (std::pair<int, pair_type>(240, my_pair));

  my_pair = *new pair_type (new StbTrack ("stb"), 7);
  this->map_instr_.insert (std::pair<int, pair_type>(241, my_pair));

  my_pair = *new pair_type (new LcTrack ("lc"), 5);
  this->map_instr_.insert (std::pair<int, pair_type>(242, my_pair));

  my_pair = *new pair_type (new LlTrack ("ll"), 7);
  this->map_instr_.insert (std::pair<int, pair_type>(243, my_pair));

  my_pair = *new pair_type (new SwpTrack ("swp"), 4);
  this->map_instr_.insert (std::pair<int, pair_type>(244, my_pair));

  my_pair = *new pair_type (new AddiTrack ("addi"), 4);
  this->map_instr_.insert (std::pair<int, pair_type>(245, my_pair));

  my_pair = *new pair_type (new CmpiTrack ("cmpi"), 4);
  this->map_instr_.insert (std::pair<int, pair_type>(246, my_pair));

  my_pair = *new pair_type (new BTrack ("b"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(247, my_pair));

  my_pair = *new pair_type (new BzTrack ("bz"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(248, my_pair));

  my_pair = *new pair_type (new BnzTrack ("bnz"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(249, my_pair));

  my_pair = *new pair_type (new BsTrack ("bs"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(250, my_pair));

  my_pair = *new pair_type (new StatTrack ("stat"), 4);
  this->map_instr_.insert (std::pair<int, pair_type>(251, my_pair));

  my_pair = *new pair_type (new CheckTrack ("check"), 2);
  this->map_instr_.insert (std::pair<int, pair_type>(252, my_pair));

  my_pair = *new pair_type (new ModeTrack ("mode"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(253, my_pair));

//   my_pair = *new pair_type (ForkTrack ("fork"), 2);
//   this->map_instr_.insert (std::pair<int, pair_type>(254, my_pair));

  my_pair = *new pair_type (new WriteTrack ("write"), 3);
  this->map_instr_.insert (std::pair<int, pair_type>(255, my_pair));

  this->index_ = 0;
}

#include <iostream>
bool
Fetchqueue::is_instruction ()
{
  if (this->index_ > 0)
  {
    if (this->queue_[0].quartet_get () < 15)
    {
      return this->index_ ==
	this->map_instr_[this->queue_[0].quartet_get ()].second;
    }
    else
    {
      return this->index_ ==
	this->map_instr_[this->queue_[1].quartet_get () + 240].second;
    }
  }

  return false;
}

std::string
Fetchqueue::get_instruction_name ()
{
  if (this->index_ > 0)
  {
    if (this->queue_[0].quartet_get () < 15)
    {
      return (this->map_instr_[this->queue_[0].quartet_get ()]
	      .first)->name_get ();
    }
    else
    {
      return this->map_instr_[this->queue_[1].quartet_get () +
			      240].first->name_get ();
    }
  }

  return "none";
}

void
Fetchqueue::add_quartet (Quartet& quartet)
{
  assert (this->index_ < 7);

  this->queue_[this->index_] = quartet;

  this->index_++;
}

Quartet
Fetchqueue::quartet_get (int pos) const
{
  assert (this->index_ >= pos);

  return this->queue_[pos];
}

Instr*
Fetchqueue::instr_get ()
{
  if (this->index_ > 0)
  {
    if (this->queue_[0].quartet_get () < 15)
    {
      return this->map_instr_[this->queue_[0].quartet_get ()].first;
    }
    else
    {
      return this->map_instr_[this->queue_[1].quartet_get () + 240].first;
    }
  }

  return 0;
}

/*!
** Clear the queue
**
*/
void
Fetchqueue::clear_queue ()
{
  for (int i = 0; i < this->index_; ++i)
  {
//     delete &this->queue_[i];
  }

  this->index_ = 0;
}

/*!
** Return the fetchqueue formated in a string
**
** @return The formated string
*/
std::string
Fetchqueue::str_queue_get ()
{
  std::stringstream ss;

  for (int i = 0; i < this->index_; ++i)
  {
    char c;

    if (this->queue_[i].quartet_get () < 10)
      c = '0' + this->queue_[i].quartet_get ();
    else
    {
      ss << '1';
      c = '0' + this->queue_[i].quartet_get () - 10;
    }
    if (i != this->index_)
      ss << c << " ";
  }

  return ss.str ();
}

/*!
** Print the fetchqueue
**
** @param o Output stream
*/
void
Fetchqueue::print (std::ostream& o)
{
  for (int i = 0; i < this->index_; ++i)
  {
    this->queue_[i].print(o);
    if (i != this->index_)
      o << " ";
  }
}

int
Fetchqueue::index_get ()
{
  return this->index_;
}
