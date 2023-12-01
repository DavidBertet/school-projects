#include "track_vector.hh"
#include "file_loader.hh"
#include "delays.hh"
#include "track_vector.hh"
#include "track_venom.hh"
#include "track_rapier.hh"
#include "track_phantom.hh"
#include "debug.hh"

#ifdef BONUS

#include "../../../bonus/mainloop.h"

#endif /* !BONUS */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

TrackVector::TrackVector ()
{
  cycle_ = 0;
  // initialisation of the race
  init_race ();

  // initialisation of the file's vector
  std::vector<std::string> vect_files;
  vect_files = Delays::get_instance ().vect_file_get ();
  std::vector<std::string>::iterator it;
  ////////////////////////////
  // determinisation of the offset between the ships
  int nb_ship = vect_files.size ();
  test_nb_ship (nb_ship);
  int offset = Delays::get_instance ().memory_size_get () / nb_ship;
  /////////////////////////////
  // writing the ship
  int add_init_ship = 0;
  int add_ship = 0;
  FileLoader file_loader;
  ProcessorVector* proc;

  for (it = vect_files.begin ();
       it != vect_files.end ();
       it++)
  {
    file_loader.load (*it);
    std::stringstream oss;
    oss << "Loading ";
    oss << (*it);
    Debug::print_verbose(oss, 3);
    std::ifstream* file_in = file_loader.file_in_get ();
    int   size = file_loader.size_get ();
    char  oct_char;
    for (int i = 0; i < (size + 1) / 2; i++)
    {
      file_in->get (oct_char);
      write_quartet (oct_char, add_ship);
    }
//     if (Delays::get_instance ().mode_get () == 0)
      proc = new ProcessorVector (this);
//     else if (Delays::get_instance ().mode_get () == 1)
//       proc = new ProcessorVenom (this);
//     else if (Delays::get_instance ().mode_get () == 2)
//       proc = new ProcessorRapier (this);
//     else if (Delays::get_instance ().mode_get () == 3)
//       proc = new ProcessorPhantom (this);
    proc->ship_name_set (file_loader.name_get ().c_str ());
    proc->ship_comment_set (file_loader.comment_get ().c_str ());
    proc->start_address_set (add_init_ship);
    this->processors_.push_back (proc);

    file_in->close ();
    add_init_ship += offset;
    add_ship = add_init_ship;

  }
  Debug::print_verbose("Ships loaded. All systems nominal.", 3);

}

void
TrackVector::print ()
{

  for (int i = 0;
       i < Delays::get_instance ().memory_size_get ();
       i++)
  {
    track_[i].print_hex (std::cout);
  }
  std::cout << std::endl;
}

void
TrackVector::write_quartet (char quartet,
			    int& address)
{
  char oct1;
  char oct2;

  oct1 = (quartet & 0xf0) >> 4;
  oct2 = quartet & 0x0f;
  track_[address].quartet_set (oct1);
  track_[address + 1].quartet_set (oct2);
  address += 2;
}

Quartet*
TrackVector::read_quartet (int address)
{
  Quartet* q;

  q = new Quartet;
  *q = track_[address];
  return q;
}

void
TrackVector::write_quartet_buff (char value,
				 int address)
{
  std::stringstream ss;

  ss << "Write at address " << address;
  Debug::print_verbose(ss, 5);

  writting_buf_.insert (std::pair<int, char>(address, value));
}

void
TrackVector::run ()
{
  std::vector<ProcessorVector*>::iterator it;
  bool running = true;
  int nb_proc = 0;
  while (running)
  {
    std::vector<ProcessorVector*>::iterator it2;
    it2 = processors_.end ();
    nb_proc = 0;
#ifdef BONUS
    std::string	disp (650, ' ');
#endif	// BONUS
    for (it = processors_.begin ();
	 it != it2;
	 it++)
    {
      print_head (nb_proc,
		  (*it)->ship_name_get (),
		  (*it)->ship_comment_get ());
      nb_proc++;

      int blue = Delays::get_instance ().blue_arrow_spacing_get ();

#ifdef BONUS
      // get position (dist parcourus)
      disp[(*it)->pc_get () / 100] = '>';
      // dans ../delays.hh ~65000
      // int		laps_number_get ();
      // int		memory_size_get ();
#endif	// BONUS

      bool alive = (*it)->run ((*it)->pc_get() % blue == 0 , false);

      if (!alive)
      {
	processors_.erase (it);
      }
    }

#ifdef BONUS
#ifdef BONUS2
    std::cout << "\033[H\033[2J";
#endif	// BONUS2
    std::cout << "\033[31m|\033[32m" << disp << "\033[31m|\033[0m"
	      << std::endl;
#endif	// BONUS
    cycle_++;
    write_race ();
    running = up_track ();
  }
}

void
TrackVector::print_head (int nb_proc,
			 std::string ship_name,
			 std::string ship_comment)
{
  std::stringstream ss;

  ss << "Starting cycle " << cycle_;
  Debug::print_verbose(ss, 6);

  ss << "Dumping processor " << nb_proc;
  ss << " (" << ship_name << ")";
  Debug::print_verbose(ss, 10);

  ss << "Manifest : ";
  ss << ship_comment;
  Debug::print_verbose(ss, 10);
}

void
TrackVector::write_race  ()
{
  std::multimap<int, char>::iterator it;
//  std::multimap<int, Quartet>::iterator it2;

  for (it = this->writting_buf_.begin ();
       it != this->writting_buf_.end ();
       it++)
  {
    track_[(*it).first].quartet_set ((*it).second);
    this->writting_buf_.erase (it);
    if (this->writting_buf_.empty ())
      break;
  }
}

bool
TrackVector::up_track ()
{
  std::vector<ProcessorVector*>::iterator it;
  int win = 0;

  if (processors_.empty ())
  {
    std::stringstream oss;
    oss << "Track runned " << cycle_;
    oss << " cycles.";
    Debug::print_verbose (oss, 1);
    std::cout << "Hah, losers." << std::endl;
    if (Delays::get_instance ().debug_get ())
      this->print ();
    exit (1);
  }
  std::vector<ProcessorVector*> ship_vect;
  for (it = processors_.begin ();
       it != processors_.end ();
       it++)
  {
    int lap = Delays::get_instance ().laps_number_get ();

    if ((*it)->nb_lap_get () >= lap)
    {
      win++;
      std::stringstream oss;
      oss << (*it)->ship_name_get ().c_str ();
      oss << " finished the race !";
      Debug::print_verbose (oss, 1);
      ship_vect.push_back(*it);
    }
  }
  win_up (win, ship_vect);
  return true;
}

void
TrackVector::win_up (int win,
		     std::vector<ProcessorVector*> ship_vect)
{
  std::stringstream oss;
  std::vector<ProcessorVector*>::iterator it;

  if (win)
  {
    oss << "Track runned " << cycle_;
    oss << " cycles.";
    Debug::print_verbose (oss, 1);
  }

  if (win == 1)
  {
    oss << "Ship " << ship_vect[0]->ship_name_get ();
    oss << " won!";
    Debug::print_verbose (oss, 0);
  }

  if (win > 1)
  {
    Debug::print_verbose ("It's a draw, man, a DRAW!", 0);
    oss << "There are several winners :";
    for (it = ship_vect.begin ();
	 it != ship_vect.end ();
	 it++)
    {
      oss << " ";
      oss << (*it)->ship_name_get ().c_str ();
    }
    oss << ".";
    Debug::print_verbose (oss, 1);
  }
  if (win)
  {
    oss.clear ();
    oss << "Rank PJ|     Cycles |  Ship Type | Name & comment";
    oss << std::endl;
    oss << "-------+------------+------------+------------------------";
    Debug::print_verbose (oss, 1);
    for (it = ship_vect.begin ();
	 it != ship_vect.end ();
	 it++)
    {
      oss << "   1 * |";
      print_cycle (oss);
      oss << got_mode (*it) << " ";
      oss << (*it)->ship_name_get ().c_str ();
      oss << " (" << (*it)->ship_comment_get ().c_str () << ")";
      Debug::print_verbose (oss, 1);
    }
    exit (0);
  }

}

void
TrackVector::print_cycle (std::stringstream& oss)
{
  std::stringstream ss;

  ss << cycle_ - 1;
  if (ss.str ().size () < 11)
  {
    std::stringstream ss1;

    for (unsigned int i = 0; i < 11 - ss.str ().size (); ++i)
    {
      ss1 << " ";
    }
    ss1 << ss.str ();
    oss << ss1.str () << " |";
  }
  else
  {
    oss << "  too big   |";
  }
}

std::string
TrackVector::got_mode (ProcessorVector* proc)
{
  int mode = proc->ship_type_get ();

  if (mode == 0)
    return std::string ("     Feisar |");
  if (mode == 1)
    return std::string ("   Goteki45 |");
  if (mode == 2)
    return std::string ("   Agsytems |");
  if (mode == 3)
    return std::string ("    Auricom |");
  if (mode == 4)
    return std::string ("    Assegai |");
  if (mode == 5)
    return std::string ("    Piranha |");
  if (mode == 6)
    return std::string ("      Qirex |");
  if (mode == 7)
    return std::string ("     Icaras |");
  if (mode == 8)
    return std::string ("     Rocket |");
  if (mode == 9)
    return std::string ("    Missile |");
  if (mode == 10)
    return std::string ("       Mine |");
  if (mode == 11)
    return std::string ("     Plasma |");
  if (mode == 12)
    return std::string (" Miniplasma |");
  return "";
}

void
TrackVector::init_race ()
{
  for (int i = 0;
       i < Delays::get_instance ().memory_size_get ();
       i++)
  {
    track_.push_back(Quartet (0));
  }
}

void
TrackVector::test_nb_ship (int nb_ship)
{
  if (nb_ship == 0)
  {
    std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
    std::cerr << std::endl;
    exit (2);
  }
}
