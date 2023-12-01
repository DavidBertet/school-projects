#ifndef PROCESSOR_VECTOR_HH_
# define PROCESSOR_VECTOR_HH_

# include <vector>
# include "quartet.hh"
# include "fetchqueue.hh"

# define FETCH 0
# define DECODE 1
# define EXECUTE 2

class TrackVector;

class ProcessorVector
{
  public:
    ProcessorVector (TrackVector* track);
    bool run (bool is_blue_arrow, bool is_rail);

    int		start_address_get ();
    int		waiting_cycles_get ();
    short	registers_get (int pos);
    bool	z_get ();
    bool	s_get ();
    int		w0_get ();
    unsigned short	pc_get ();
    Fetchqueue&		queue_get ();
    int			reexecute_get ();
    int			cycles_left_check_get ();
    int			last_zone_check_get ();
    TrackVector*	track_get ();
    char		buffer_get (int pos);
    int			nb_lap_get ();

    int			on_blue_arrow_;
    int			on_rail_;
    int			ship_type_get ();
    std::string		ship_name_get ();
    std::string		ship_comment_get ();

    void	start_address_set (int start_address);
    void	waiting_cycles_set (int waiting_cycles);
    void	registers_set (short value, int pos);
    void	z_set (bool z);
    void	s_set (bool s);
    void	w0_set (int w0);
    void	mode_set (int mode);
    void	pc_set (unsigned short pc);
    void	queue_set (Fetchqueue queue);
    void	reexecute_set (int reexecute);
    void	cycles_left_check_set (int cycles_left_check);
    void	last_zone_check_set (int last_zone_check);
    void	ship_type_set (int ship_type);
    void	ship_name_set (std::string name);
    void	ship_comment_set (std::string comment);
    void	buffer_set (char value, int pos);
    void	nb_lap_set (int nb_lap);

    virtual void	print_infos ();
    void		print_fetchqueue ();

  private:
    bool		fetch ();
    void		decode ();
    void		execute ();

    int			waiting_cycles_;
    unsigned short	registers_[16];
    bool		z_;
    bool		s_;
    int			w0_;
    unsigned short	pc_;
    Fetchqueue		queue_;
    int			reexecute_;
    TrackVector*	track_;
    int			mode_;
    int			cycles_left_check_;
    int			last_zone_check_;
    int			nb_lap_;

    int			start_address_;
    int			ship_type_;
    std::string		ship_name_;
    std::string		ship_comment_;
    std::vector<Quartet> buffer_;
};

#endif /* !PROCESSOR_VECTOR_HH_ */
