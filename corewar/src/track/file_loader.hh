#ifndef FILE_LOADER_HH_
# define FILE_LOADER_HH_

# include <fstream>
# include <iostream>
# include <string>

class FileLoader
{
  public:
    FileLoader ();
    void load (const std::string& input_file);
    std::ifstream* file_in_get ();
    int size_get ();
    std::string name_get ();
    std::string comment_get ();
  private:
    int size_;
    void test_magic_number (std::ifstream& file_in);
    void test_size_ship (std::ifstream& file_in);
    void get_name_ship (std::ifstream& file_in);
    void get_comment (std::ifstream& file_in);
    std::string name_;
    std::string comment_;
    std::string ship_;
    std::ifstream* file_in_;
};

#endif // !FILE_LOADER_HH_
