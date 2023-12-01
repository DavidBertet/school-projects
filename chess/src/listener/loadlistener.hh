#ifndef LOADLISTENER_HH_
# define LOADLISTENER_HH_
# include <dlfcn.h>
# include "listener.hh"
class LoaderListener
{
  public:
    LoaderListener (std::string k);
    ~LoaderListener ();
    Listener* load ();
  private:
    std::string name_;
    void *lib_;
};

#endif /* !LOADLISTENER_HH_ */
