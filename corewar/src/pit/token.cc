#include <string>
#include <iostream>
#include <sstream>
#include <bitset>
#include <limits>
#include "token.hh"

Token::Token (std::string val)
{
  this->value_ = val;
}

Token::Token ()
{
  this->value_ = "";
}

Token::~Token ()
{
}

std::ostream&
operator<< (std::ostream&	out, Token&	tok)
{
  return out << tok.value_;
}

std::istream&
operator>> (std::istream&	in, Token&	tok)
{
  in >> tok.value_;

  return in;
}

std::string&
operator>> (std::string&	in, Token&	tok)
{
  tok.value_ = in;

  return in;
}

/*!
** Find if a number is inside the correct base
**
** @param c The number
** @param type The type of the base, 1 for binary, 2 for octal, 3 for decimal,
** otherwise it's in hexadecimal
**
** @return Bool, true if it's ok, false otherwise
*/
bool
is_correct_number (char c, int type)
{
  if (type == 1) //binary
    return c >= '0' && c <= '1';
  if (type == 2) //octal
    return c >= '0' && c <= '7';
  if (type == 3) //decimal
    return c >= '0' && c <= '9';
  else //hexa
    return (c >= '0' && c <= '9' ||
            (std::tolower(c) >= 'a' && std::tolower(c) <= 'f'));
}

/*!
** Search if the parameter is a register
**
** @param str The string to parse
**
** @return True if it's a register, false otherwise
*/
bool
match_register (std::string& str)
{
  if (str == "r0" || str == "r1" || str == "r2" || str == "r3" ||
      str == "r4" || str == "r5" || str == "r6" || str == "r7" ||
      str == "r8" || str == "r9" || str == "r10" || str == "r11" ||
      str == "r12" || str == "r13" || str == "r14" ||str == "r15")
    return true;
  return false;
}

/*!
** Search if the parameter is an advanced register
**
** @param str The string to parse
**
** @return True if it's an advanced register, false otherwise
*/
bool
match_advanced_register (std::string& str)
{
  if (str == "[r0]" || str == "[r1]" || str == "[r2]" || str == "[r3]" ||
      str == "[r4]" || str == "[r5]" || str == "[r6]" || str == "[r7]" ||
      str == "[r8]" || str == "[r9]" || str == "[r10]" || str == "[r11]" ||
      str == "[r12]" || str == "[r13]" || str == "[r14]" || str == "[r15]")
    return true;
  return false;
}

/*!
** Search if the parameter is a number (binary, octal, decimal, hexadecimal)
**
** @param str The string to parse
**
** @return return 0 if its not a number
** return 1 if its a syntax error
** return 2 if its a valid number
*/
int
match_number (std::string& str)
{
  int num = 0;
  int pos = 1;
  std::stringstream ss;

  //find the type of number
  if (str[0] == '%')
  {
    num = 1;
  }
  if (is_correct_number (str[0], 2))
  {
    ss << str[0];
    num = 3;
  }
  if (str[0] == '0')
  {
    if (str[1] == 'x')
    {
      pos = 2;
      num = 4;
    }
    else
      num = 2;
  }

  //if it's a number, find it
  if (num)
  {
    for (unsigned int i = pos; i < str.size (); ++i)
    {
      if (is_correct_number (str[i], num))
	ss << str[i];
      else if  (str[i] != '_')
      {
	std::cout << str << " is a bad number" << std::endl;
	return 1;
      }
    }
    if (is_correct_number (str[str.size() - 1], num))
    {
      int number;

      if (num == 1)
      {
	std::cout << str << " give " << ss.str()
		  << " is a binary number equal to "
		  << std::bitset<std::numeric_limits<unsigned long>::digits>
	  (std::string(ss.str())).to_ulong()
		  << std::endl;
      }
      if (num == 2)
      {
	ss >> std::oct >> number;
	std::cout << str  << " give " << ss.str()
		  << " is an octal number equal to " << number << std::endl;
      }
      if (num == 3)
      {
	ss >> std::dec >> number;
	std::cout << str << " give " << ss.str()
		  << " is a decimal number" << std::endl;
      }
      if (num == 4)
      {
	ss >> std::hex >> number;
	std::cout << str << " give " << ss.str()
		  << " is an hexadecimal number equal to " << number << std::endl;
      }
      return 2;
    }
    else
    {
      std::cout << str << " has an syntax error" << std::endl;
      return 1;
    }
  }

  return 0;
}

/*!
** Match a string and search his type
** raise SyntaxeError if error
*/
void
Token::match_type ()
{
  if (!match_number (this->value_))
    if (!match_register (this->value_))
      std::cout << this->value_ << " is nothing" << std::endl;
}
