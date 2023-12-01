#include <sstream>

#include "processor_vector.hh"
#include "track_vector.hh"
#include "debug.hh"

//*******************/
//   CONSTRUCTOR     /
//*******************/
ProcessorVector::ProcessorVector (TrackVector* track)
{
  this->z_ = 0;
  this->s_ = 0;
  this->w0_ = 0;
  this->waiting_cycles_ = 0;
  this->pc_ = 0;

  this->mode_ = FETCH;
  this->ship_type_ = 0;

  this->track_ = track;

  for (int i = 0; i < 16; ++i)
  {
    this->registers_[i] = 0;
  }

  this->cycles_left_check_ = Delays::get_instance ().checkpoint_delay_get ();
  this->last_zone_check_ = 0;
  this->reexecute_ = -1;

  for (int i = 0;
       i < Delays::get_instance ().memory_size_get ();
       i++)
  {
    this->buffer_.push_back(Quartet (0));
  }
}


//************/
//   MISC     /
//************/
bool
ProcessorVector::run (bool is_blue_arrow, bool is_rail)
{
  if (this->cycles_left_check_ == 0)
  {
    return false;
  }

  --this->cycles_left_check_;

  this->print_infos ();
  this->print_fetchqueue ();

  Debug::print_verbose ("", 10);

  this->on_rail_ = is_rail;
  this->on_blue_arrow_ = is_blue_arrow;

  if (this->mode_ == FETCH)
  {
    if (!this->fetch ())
      return false;
  }

  if (this->mode_ == DECODE)
  {
    this->decode ();
  }

  if (this->mode_ == EXECUTE)
  {
    this->execute ();
  }

  return true;
}

bool
ProcessorVector::fetch ()
{
  std::stringstream ss;

  ss << "Read at address " << this->pc_;
  Debug::print_verbose (ss, 5);

  //add a quartet in the fetchqueue
  this->queue_.add_quartet (*this->track_->read_quartet (this->pc_));

  if (this->queue_.is_instruction ())
  {
    if (this->queue_.get_instruction_name () == "crash")
    {
      Debug::print_verbose ("          crash |", 3);
      Debug::print_verbose ("", 4);
      return false;
    }

    //go to decode mode
    this->mode_ = DECODE;

    //put the time needed to decode the instruction
    this->waiting_cycles_ = Delays::get_instance ().decode_delay_get
      (this->queue_.get_instruction_name (), this->ship_type_);
  }

  ++this->pc_;
  if (this->pc_ >= Delays::get_instance ().memory_size_get ())
    this->pc_ = 0;

  ++this->w0_;

  return true;
}

void
ProcessorVector::decode ()
{
  std::stringstream ss;

  --this->waiting_cycles_;

  if (this->waiting_cycles_ == -1)
  {
    ss << this->queue_.instr_get ()->text_get(this) << " |";
    Debug::print_verbose (ss, 3);

    Debug::print_verbose ("", 5);

    //go to execute mode
    this->mode_ = EXECUTE;

    //put the time needed to execute the instruction
    this->waiting_cycles_ = Delays::get_instance ().execute_delay_get
      (this->queue_.get_instruction_name (), this->ship_type_);

    if (Delays::get_instance ().mode_get () > 1 &&
      this->on_blue_arrow_)
      this->waiting_cycles_ /= 2;

    //execute the instruction
    this->queue_.instr_get ()->exec (this);
  }
}

void
ProcessorVector::execute ()
{
  --this->waiting_cycles_;

  if (this->waiting_cycles_ <= -1)
  {
    ++this->waiting_cycles_;

    if (this->reexecute_ > 0)
    {
      //execute the instruction
      this->queue_.instr_get ()->exec (this);
    }

    if (this->reexecute_ > 1)
    {
      --this->reexecute_;

      //put the time needed to reexecute the instruction
      this->waiting_cycles_ = Delays::get_instance ().execute_delay_get
	(this->queue_.get_instruction_name (), this->ship_type_);

    if (Delays::get_instance ().mode_get () > 1 &&
      this->on_blue_arrow_)
      this->waiting_cycles_ /= 2;

      --this->waiting_cycles_;
    }
    else
    {
      if (this->queue_.get_instruction_name () == "check")
      {
	int size_lap = Delays::get_instance ().memory_size_get ();
	this->nb_lap_set (this->w0_ / size_lap);
      }

      //clear the reexecute option
      this->reexecute_ = -1;

      //go to fetch mode
      this->mode_ = FETCH;

      //clear fetch queue
      this->queue_.clear_queue ();
    }
  }
}

//***************/
//   GETTER      /
//***************/
int
ProcessorVector::start_address_get ()
{
  return this->start_address_;
}

int
ProcessorVector::waiting_cycles_get ()
{
  return this->waiting_cycles_;
}

short
ProcessorVector::registers_get (int pos)
{
  return this->registers_[pos];
}

bool
ProcessorVector::z_get ()
{
  return this->z_;
}

bool
ProcessorVector::s_get ()
{
  return this->s_;
}

int
ProcessorVector::w0_get ()
{
  return this->w0_;
}

unsigned short
ProcessorVector::pc_get ()
{
  return this->pc_;
}

Fetchqueue&
ProcessorVector::queue_get ()
{
  return this->queue_;
}

int
ProcessorVector::reexecute_get ()
{
  return this->reexecute_;
}

int
ProcessorVector::ship_type_get ()
{
  return this->ship_type_;
}

std::string
ProcessorVector::ship_name_get ()
{
  return this->ship_name_;
}

std::string
ProcessorVector::ship_comment_get ()
{
  return this->ship_comment_;
}

int
ProcessorVector::cycles_left_check_get ()
{
  return this->cycles_left_check_;
}

int
ProcessorVector::last_zone_check_get ()
{
  return this->last_zone_check_;
}

TrackVector*
ProcessorVector::track_get ()
{
  return this->track_;
}

char
ProcessorVector::buffer_get (int pos)
{
  return this->buffer_[pos].quartet_get ();
}

int
ProcessorVector::nb_lap_get ()
{
  return this->nb_lap_;
}

//***************/
//   SETTER      /
//***************/
void
ProcessorVector::start_address_set (int start_address)
{
  this->start_address_ = start_address;
}

void
ProcessorVector::waiting_cycles_set (int waiting_cycles)
{
  this->waiting_cycles_ = waiting_cycles;
}

void
ProcessorVector::registers_set (short value, int pos)
{
  this->registers_[pos] = value;
}

void
ProcessorVector::z_set (bool z)
{
  this->z_ = z;
}

void
ProcessorVector::s_set (bool s)
{
  this->s_ = s;
}

void
ProcessorVector::w0_set (int w0)
{
  this->w0_ = w0;
}

void
ProcessorVector::mode_set (int mode)
{
  this->mode_ = mode;
}

void
ProcessorVector::pc_set (unsigned short pc)
{
  this->pc_ = pc;
}

void
ProcessorVector::queue_set (Fetchqueue queue)
{
  this->queue_ = queue;
}

void
ProcessorVector::reexecute_set (int reexecute)
{
  this->reexecute_ = reexecute;
}

void
ProcessorVector::cycles_left_check_set (int cycles_left_check)
{
  this->cycles_left_check_ = cycles_left_check;
}

void
ProcessorVector::last_zone_check_set (int last_zone_check)
{
  this->last_zone_check_ = last_zone_check;
}

void
ProcessorVector::ship_type_set (int ship_type)
{
  this->ship_type_ = ship_type;
}

void
ProcessorVector::ship_name_set (std::string name)
{
  this->ship_name_ = name;
}

void
ProcessorVector::ship_comment_set (std::string comment)
{
  this->ship_comment_ = comment;
}

void
ProcessorVector::buffer_set (char value, int pos)
{
  this->buffer_[pos].quartet_set (value);
}

void
ProcessorVector::nb_lap_set (int nb_lap)
{
  this->nb_lap_ = nb_lap;
}

//***************/
//   PRINTER     /
//***************/
void
ProcessorVector::print_infos ()
{
  std::stringstream ss;

  Debug::print_verbose ("  Registers & memories :", 10);

  ss << "    PC\t\t" << this->pc_;
  Debug::print_verbose (ss, 10);

  ss << "    W'0\"\t" << this->w0_;
  Debug::print_verbose (ss, 10);

  ss << "    Z\t\t" << this->z_;
  Debug::print_verbose (ss, 10);

  ss << "    S\t\t" << this->s_;
  Debug::print_verbose (ss, 10);

  for (int i = 0; i < 16; ++i)
  {
    if (i < 10)
      ss << "    r0" << i << "\t\t\t\t " << this->registers_[i];
    else
      ss << "    r" << i<< "\t\t\t\t " << this->registers_[i];
    Debug::print_verbose (ss, 10);
  }

  ss << "    Instruction buffer\t\t ";
  for (int i = 0; i < 64; ++i)
  {
    char c;

    if (this->buffer_[i].quartet_get () < 10)
      c = '0' + this->buffer_[i].quartet_get ();
    else
    {
      ss << '1';
      c = '0' + this->buffer_[i].quartet_get () - 10;
    }

    ss << c;
    if (i != 63)
      ss <<  " ";
  }
  Debug::print_verbose (ss, 10);
}

void
ProcessorVector::print_fetchqueue ()
{
  std::stringstream ss;

  ss << "Dumping Fetchqueue :";
  Debug::print_verbose (ss, 10);

  ss << "  Read : " << this->queue_.index_get ();
  Debug::print_verbose (ss, 10);

  ss << "  Queue : " << this->queue_.str_queue_get () << std::endl;
  Debug::print_verbose (ss, 10);

  Debug::print_verbose ("  State : ", 10);

  ss << "    Type\t\t\t  " << this->ship_type_;
  Debug::print_verbose (ss, 10);

  ss << "    Lap\t\t\t\t  ?";
  Debug::print_verbose (ss, 10);

  ss << "    Last zone checked\t\t  " << this->last_zone_check_;
  Debug::print_verbose (ss, 10);

  ss << "    Cycles left before next check " << this->cycles_left_check_;
  Debug::print_verbose (ss, 10);

  Debug::print_verbose ("", 10);

  Debug::print_verbose ("  Miscellani : ", 10);

  if (this->on_blue_arrow_)
    Debug::print_verbose ("    On a blue arrow\t\t  Yes", 10);
  else
    Debug::print_verbose ("    On a blue arrow\t\t  No", 10);

  if (this->on_rail_)
    Debug::print_verbose ("    Rail : yes", 10);
  else
    Debug::print_verbose ("    Rail : no", 10);

  Debug::print_verbose ("    Current state\t\t    Dumping context :", 10);

  if (this->mode_ == FETCH)
    ss << "  State\t\t: fetch";
  else if (this->mode_ == DECODE)
    ss << "  State\t\t: decode";
  else if (this->mode_ == EXECUTE)
    ss << "  State\t\t: execute";
  Debug::print_verbose (ss, 10);

  ss << "  Wait cycles\t: " << this->waiting_cycles_;
  Debug::print_verbose (ss, 10);

  ss << "  Instr cookie\t: ?";
  Debug::print_verbose (ss, 10);
}
