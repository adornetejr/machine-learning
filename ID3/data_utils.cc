#include <iostream>
#include <algorithm>

#include "data.h"
#include "data_utils.h"

Value*
DataUtils::CopyValue(Value *source_value) {
  Value *target_value = nullptr;
  if (source_value->type == "string") {
    target_value = new ValueImpl<std::string>;
    ((ValueImpl<std::string> *)target_value)->type = "string";
    ((ValueImpl<std::string> *)target_value)->v = ((ValueImpl<std::string> *)source_value)->v;
  } else if (source_value->type == "bool") {
    target_value = new ValueImpl<bool>;
    ((ValueImpl<bool> *)target_value)->type = "bool";
    ((ValueImpl<bool> *)target_value)->v = ((ValueImpl<bool> *)source_value)->v;
  }
  return target_value;
}

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
        std::cout << delim << "UNK. DATA TYPE";
      }
      delim = ",";
    }
    delim = " ~> ";
    if (data_set->data_entries[c]->output_value->type == "string") {
      std::cout << delim << ((ValueImpl<std::string> *)(data_set->data_entries[c]->output_value))->v;
    } else if (data_set->data_entries[c]->output_value->type == "bool") {
      std::cout << delim << ((ValueImpl<bool> *)(data_set->data_entries[c]->output_value))->v;
    } else {
      std::cout << delim << "UNK. DATA TYPE";
    }
    std::cout << std::endl;
  }
}

DataSet*
DataUtils::ExtractFields(DataSet *data_set, std::vector<std::string> field_names) {
  DataSet *target_data_set = new DataSet;
  DataShape *data_shape = new DataShape;
  data_shape->has_output_field = false;
  for (uint32_t i = 0; i < data_set->data_shape->input_field_names.size(); i++) {
    if (std::find(field_names.begin(), field_names.end(), data_set->data_shape->input_field_names[i]) != field_names.end()) {
      data_shape->input_field_names.push_back(data_set->data_shape->input_field_names[i]);
      data_shape->input_types.push_back(data_set->data_shape->input_types[i]);
    }
  }
  for (uint32_t i = 0; i < data_set->data_shape->input_field_names.size(); i++) {
    if (std::find(field_names.begin(), field_names.end(), data_set->data_shape->input_field_names[i]) != field_names.end()) {
      for (uint32_t c = 0; c < data_set->data_entries.size(); c++) {
        DataEntry *data_entry = new DataEntry;
        data_entry->data_shape = data_shape;
        data_entry->input_values.push_back(CopyValue(data_set->data_entries[c]->input_values[i]));
        target_data_set->data_entries.push_back(data_entry);
      }
    }
  }
  return target_data_set;
}