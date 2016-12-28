#pragma once

class DataSet;
class DataUtils {
public:
  static Value* CopyValue(Value *); 
  static void Print(DataSet *);
  static DataSet* ExtractFields(DataSet *, std::vector<std::string>);
  static std::vector<Value *> ExtractValues(DataSet *, std::string);
};