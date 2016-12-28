#include <iostream>

#include "data.h"
#include "data_utils.h"

void
DataUtils::Print(DataSet *data_set) {
  std::string delim = "";
  for (uint32_t i = 0; i < data_set->data_shape->input_field_names.size(); i++) {
    std::cout << delim << data_set->data_shape->input_field_names[i];
    delim = ",";
  }
  delim = " ~> ";
  std::cout << delim << data_set->data_shape->output_field_name;
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  for (uint32_t c = 0; c < data_set->data_entries.size(); c++) {
    delim = "";
    for (uint32_t cc = 0; cc < data_set->data_entries[c]->input_values.size(); cc++) {
      if (data_set->data_entries[c]->input_values[cc]->type == "string") {
        std::cout << delim << ((ValueImpl<std::string> *)(data_set->data_entries[c]->input_values[cc]))->v;
      } else if (data_set->data_entries[c]->input_values[cc]->type == "bool") {
        std::cout << delim << ((ValueImpl<bool> *)(data_set->data_entries[c]->input_values[cc]))->v;
      } else {
        std::cout << delim << "UNIDENTIFIED DATA TYPE";
      }
      delim = ",";
    }
    delim = " ~> ";
    if (data_set->data_entries[c]->output_value->type == "string") {
        std::cout << delim << ((ValueImpl<std::string> *)(data_set->data_entries[c]->output_value))->v;
      } else if (data_set->data_entries[c]->output_value->type == "bool") {
        std::cout << delim << ((ValueImpl<bool> *)(data_set->data_entries[c]->output_value))->v;
      } else {
        std::cout << delim << "UNIDENTIFIED DATA TYPE";
      }
    std::cout << std::endl;
  }
}