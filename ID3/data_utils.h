#pragma once

#include <vector>

class DataSet;
class DataUtils {
public:
  static Value* CopyValue(Value *);
  static void Print(DataSet *);
  static DataSet* ExtractFields(DataSet *, std::vector<std::string>);

  template<typename T>
  static
  std::vector<ValueImpl<T> *>
  ExtractValues(DataSet *data_set, std::string field_name) {
    std::vector<ValueImpl<T> *> values;
    for (uint32_t i = 0; i < data_set->data_shape->input_field_names.size(); i++) {
      if (data_set->data_shape->input_field_names[i] == field_name) {
        for (uint32_t c = 0; c < data_set->data_entries.size(); c++) {
          values.push_back((ValueImpl<T> *)CopyValue(data_set->data_entries[c]->input_values[i]));
        }
        break;
      }
    }
    return values;
  }
};