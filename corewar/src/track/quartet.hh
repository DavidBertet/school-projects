#ifndef QUARTET_HH_
# define QUARTET_HH_

class Quartet
{
  public:
    Quartet ();
    Quartet (char quartet);

    void quartet_set (char quartet);
    char quartet_get () const;

    void print (std::ostream& o);
    void print_hex (std::ostream& o);

  private:
    char	quartet_;
};

#endif /* !QUARTET_HH_ */
