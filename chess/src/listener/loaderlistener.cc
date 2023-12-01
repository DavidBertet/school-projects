#include "loadlistener.hh"
#include "listener.hh"
#include "error.hh"

Listener*
LoaderListener::load ()
{
  ListenerExport *p;

  p = (ListenerExport*) dlsym (lib_, "listener_plugin");

  if (!p)
    throw new error::Error ("load error");

  Listener* listener = (p->create)();

  return listener;
}

LoaderListener::LoaderListener (std::string file)
      : name_(file)
{
  lib_ = dlopen (file.c_str (), RTLD_LAZY);
}

LoaderListener::~LoaderListener ()
{
  dlclose (lib_);
}
