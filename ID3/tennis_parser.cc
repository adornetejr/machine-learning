#include <iostream>
#include <fstream>
#include <sstream>

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
  data_set->data_shape = new DataShape;
  std::stringstream ss(line);
  std::vector<std::string> field_names;
  std::string field_name;
  while (ss >> field_name) {
    field_names.push_back(field_name);
    if (ss.peek() == ' ') {
      ss.ignore();
    }
  }
  for (uint32_t i = 0; i < field_names.size() - 1; i++) {
    data_set->data_shape->input_field_names.push_back(field_names[i]);
  }
  data_set->data_shape->output_field_name = field_names[field_names.size() - 1];
  // Read entries
  f.close();
}