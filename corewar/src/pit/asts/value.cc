#include "value.hh"

Value::Value (int	val, std::string	str)
  : value_ (val),
    str_ (str)
{
}

void
Value::accept (Visitor& v)
{
  v (*this);
}

int
Value::value_get ()
{
  return value_;
}


void
Value::value_set (int n)
{
  value_ = n;
}

std::ostream&
operator<< (std::ostream& output, const Value& val)
{
  return output << "\033[32m" << val.value_ << "\033[0m from " << val.str_;
}
