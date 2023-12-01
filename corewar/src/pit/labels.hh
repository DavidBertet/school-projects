#ifndef LABELS_HH_
# define LABELS_HH_
# include <map>
# include <string>

struct Labels
{
public:
  static Labels& instance_get ();
  size_t	value_get (std::string label);
  void		labels_set (std::string label, size_t addr);
private:
  static Labels* instance_;
  Labels ();
  typedef std::map<std::string, size_t>	my_map;
  my_map labels_;
};

#endif  //! LABELS_HH_
