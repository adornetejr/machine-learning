#pragma once

#include <map>
#include <string>


class DataSet;
class InfoTheoryUtils {
public:
  static std::map<std::string, double> CalculateEntropy(DataSet *);
};