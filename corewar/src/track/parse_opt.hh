#ifndef PARSE_OPT_HH_
# define PARSE_OPT_HH_

# include <vector>
# include <string>
class ParseOpt
{
  public:
    ParseOpt ();
    void parse (int argc, char** argv);
    void execute_opt ();
    void fct_help ();
    void verif_mode (std::string& mode);
    void verif_lap_number (std::string& arg, std::string& opt);
    void verif_memory_size (std::string& arg, std::string& opt);
    void verif_checkpoints_per_lap (std::string& arg, std::string& opt);
    void verif_checkpoint_delay (std::string& arg, std::string& opt);
    void verif_verbose (std::string& arg, std::string& opt);
    bool test_option_double (std::string& word, std::string& arg);
    bool test_option_double2 (std::string& word, std::string& arg);
    void test_option_simple (std::string& word);
    void add_file (std::string& word);
    int mode_get ();

  private:
    bool help_;
    bool debug_;
    bool display_;
    int mode_;
    int laps_number_;
    int memory_size_;
    int checkpoints_per_lap_;
    int checkpoint_delay_;
    int verbose_;
};

#endif // !PARSE_OPT_HH_
