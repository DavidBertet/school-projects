#ifndef DELAYS_HH_
# define DELAYS_HH_

# include <map>
# include <string>
# include <vector>

# define FEISAR		0
# define GOTEKI45	1
# define AGSYSTEMS	2
# define AURICOM	3
# define ASSEGAI	4
# define PIRANHA	5
# define QIREX		6
# define ICARAS		7
# define ROCKET		8
# define MISSILE	9
# define MINE		10
# define PLASMA		11
# define MINIPLASMA	12

typedef std::pair<std::string, int> pair_t;
typedef std::map<pair_t, int> map_t;

class Delays
{
  public:
    static Delays& get_instance ();

    int		execute_delay_get (std::string instr, int mode);
    int		decode_delay_get (std::string instr, int mode);
    int		idx_mod_get (int mode);
    void	create_idx_mod ();

    void	help_set (bool help);
    void	debug_set (bool debug);
    void	display_set (bool display);
    void	mode_set (int mode);
    void	laps_number_set (int laps_number);
    void	memory_size_set (int memory_size);
    void	checkpoints_per_lap_set (int checkpoints_per_lap);
    void	checkpoint_delay_set (int checkpoint_delay);
    void	blue_arrow_spacing_set (int blue_arrow_spacing);
    void	verbose_set (int verbose);
    void	file_add (std::string file);

    bool	help_get ();
    bool	debug_get ();
    bool	display_get ();
    int		mode_get ();
    int		laps_number_get ();
    int		memory_size_get ();
    int		checkpoints_per_lap_get ();
    int		checkpoint_delay_get ();
    int		blue_arrow_spacing_get ();
    int		verbose_get ();
    std::vector<std::string> vect_file_get ();

  private:
    Delays ();
    map_t execute_delays_;
    map_t decode_delays_;
    std::vector<int> idx_mod_;

    bool help_;
    bool debug_;
    bool display_;
    int mode_;
    int laps_number_;
    int memory_size_;
    int checkpoints_per_lap_;
    int checkpoint_delay_;
    int blue_arrow_spacing_;
    int verbose_;
    std::vector<std::string> vect_file_;

    static Delays* instance_;
};

#endif /* !DELAYS_HH_ */
