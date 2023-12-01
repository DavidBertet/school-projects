#ifndef DEBUG_HH_
# define DEBUG_HH_

# include <string>
# include <sstream>
# include <iostream>

class Debug
{
  public:
    static void print_verbose (std::string msg, int verb_mode);
    static void print_verbose (std::stringstream& ss, int verb_mode);
    static std::ostream& verbose_output;
};

#endif /* !DEBUG_HH_ */
