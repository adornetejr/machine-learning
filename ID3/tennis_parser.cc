#include <iostream>
#include <fstream>

#include "data.h"
#include "tennis_parser.h"

void
TennisParser::Fill(DataSet *data_set) {
  // Read shape
  std::string line;
  std::fstream f(file_path_);
  if (not f) {
    std::cout << "File '" << file_path_ << "' can't be opened." << std::endl;
    exit(1);
  }
  std::getline(f, line);
  std::cout << line << std::endl;
  // Read entries
  f.close();
}