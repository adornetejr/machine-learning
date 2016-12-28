#pragma once

#include <math.h> 

#include <map>
#include <algorithm>
#include <string>


class DataSet;
class InfoTheoryUtils {
public:
  static std::map<std::string, double> CalculateEntropy(DataSet *);

  template<typename T>
  static
  double
  CalculateEntropyForValues(std::vector<ValueImpl<T> *> values) {
    double sum = 0.0;
    uint32_t num_of_samples = values.size();
    std::vector<T> seen_values;
    for (uint32_t i = 0; i < values.size(); i++) {
      if (std::find(seen_values.begin(), seen_values.end(), values[i]->v) != seen_values.end()) {
        continue;
      }
      seen_values.push_back(values[i]->v);
      uint32_t frequency = 0;
      for (uint32_t j = 0; j < values.size(); j++) {
        if (values[i]->v == values[j]->v) {
          frequency++;
        }
      }
      double probablity = frequency / num_of_samples;
      sum += probablity * log2(probablity);
    }
    return -sum;
  }
};