#include <iostream>
#include "labels.hh"
#include "exeption.hh"

Labels* Labels::instance_ = 0;

Labels&
Labels::instance_get ()
{
  if (!instance_)
    instance_ = new Labels ();
  return *instance_;
}

Labels::Labels ()
{
}

size_t
Labels::value_get (std::string label)
{
  if (labels_[label])
    return labels_[label];
  else
    throw Error ("Undefined label " + label, 1);
}

void
Labels::labels_set (std::string label, size_t addr)
{
  labels_[label] = addr;
}
