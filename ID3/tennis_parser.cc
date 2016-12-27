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
  // Read lines
  while (not f.eof()) {
    std::getline(f, line);
    std::stringstream ss2(line);
    std::vector<std::string> str_values;
    std::string str_value;
    while (ss2 >> str_value) {
      str_values.push_back(str_value);
      if (ss2.peek() == ' ') {
        ss2.ignore();
      }
    }
    auto outlook_value = new ValueImpl<std::string>;
    outlook_value->v = str_values[0];
    auto temperature_value = new ValueImpl<std::string>;
    temperature_value->v = str_values[1];
    auto humidity_value = new ValueImpl<std::string>;
    humidity_value->v = str_values[2];
    auto wind_value = new ValueImpl<bool>;
    wind_value->v = (str_values[3] == "TRUE");
    DataEntry *data_entry = new DataEntry;
    data_entry->data_shape = data_set->data_shape;
    data_entry->input_values.push_back(outlook_value);
    data_entry->input_values.push_back(temperature_value);
    data_entry->input_values.push_back(humidity_value);
    data_entry->input_values.push_back(wind_value);
    auto playtennis_value = new ValueImpl<bool>;
    playtennis_value->v = (str_values[4] == "yes");
    data_entry->output_value = playtennis_value;
    data_set->data_entries.push_back(data_entry);
  }
  f.close();
}