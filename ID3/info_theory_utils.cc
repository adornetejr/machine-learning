#include "data.h"
#include "data_utils.h"
#include "info_theory_utils.h"

std::map<std::string, double>
InfoTheoryUtils::CalculateEntropy(DataSet *data_set) {
  std::map<std::string, double> m;
  for (uint32_t i = 0; i < data_set->data_shape->input_field_names.size(); i++) {
    if (data_set->data_shape->input_types[i] == "string") {
      std::vector<ValueImpl<std::string> *> values = DataUtils::ExtractValues<std::string>(data_set, data_set->data_shape->input_field_names[i]);
      double entropy = CalculateEntropyForValues(values);
      m[data_set->data_shape->input_field_names[i]] = entropy;
    } else if (data_set->data_shape->input_types[i] == "bool") {
      std::vector<ValueImpl<bool> *> values = DataUtils::ExtractValues<bool>(data_set, data_set->data_shape->input_field_names[i]);
      double entropy = CalculateEntropyForValues(values);
      m[data_set->data_shape->input_field_names[i]] = entropy;
    }
  }
  return m;
}
