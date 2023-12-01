#include "file_loader.hh"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "data.h"
#include "delays.hh"

FileLoader::FileLoader ()
{
  size_ = 0;
}

void
FileLoader::test_magic_number (std::ifstream& file_in)
{
  char		m1;
  int 		m1_int;
  int		magic = MAGIC_NUMBER;
  int		m2;
  int		i;
  bool		magic_number_ok = true;

  i = 0;
  while (i < 4)
  {
    file_in >> m1;
    m1_int = m1;
    m2 = magic % 256;
    if ((magic_number_ok) && (m1 != m2))
      magic_number_ok = false;
    magic = magic / 256;
    i++;
  }
  if (!magic_number_ok)
  {
    std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
    std::cerr << std::endl;
    exit (2);
  }
}

void
FileLoader::test_size_ship (std::ifstream& file_in)
{
  int	i;
  char  oct_char;
  int	oct;
  int	size = 0;
  int	offset = 1;

  i = 0;
  while (i < 4)
  {
    file_in.get (oct_char);
    oct = oct_char;
    size = size + oct * offset;
    offset = offset * 256;
    i++;
  }
  if (size > MAX_CODE_SIZE)
  {
    std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
    std::cerr << std::endl;
    exit (2);
  }
  size_ = size;
}

void
FileLoader::get_name_ship (std::ifstream& file_in)
{
  char  oct_char;
  std::stringstream oss;

  for (int i = 0; i < NAME_LENGTH; i++)
  {
    file_in.get (oct_char);
    oss << oct_char;
  }
  name_ = oss.str ();
}

void
FileLoader::get_comment (std::ifstream& file_in)
{
  char  oct_char;
  std::stringstream oss;

  for (int i = 0; i < COMMENT_LENGTH; i++)
  {
    file_in.get (oct_char);
    oss << oct_char;
  }
  comment_ = oss.str ();
}

std::ifstream*
FileLoader::file_in_get ()
{
  return file_in_;
}

void
FileLoader::load (const std::string& input_file)
{
  std::ifstream* file_in = new std::ifstream;

  file_in->open (input_file.c_str ());
  if (!(file_in->is_open ()))
  {
    std::cerr << "Damn, I wanted to kick ass, and they feed me an error.";
    std::cerr << std::endl;
    exit (2);
  }
  test_magic_number (*file_in);
  test_size_ship (*file_in);
  get_name_ship (*file_in);
  get_comment (*file_in);
  file_in_ = file_in;
}

int
FileLoader::size_get ()
{
  return size_;
}

std::string
FileLoader::name_get ()
{
  return name_;
}

std::string
FileLoader::comment_get ()
{
  return comment_;
}
