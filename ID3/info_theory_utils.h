#pragma once

#include <map>
#include <string>


class DataSet;
class InfoTheoryUtils {
public:
  static double CalculateEntropyForValues(std::vector<Value *> );
  static std::map<std::string, double> CalculateEntropy(DataSet *);
};