#pragma once

#include <vector>


struct DataShape {
  std::vector<std::string> input_field_names;
  std::string output_field_name;
};

struct Value {
protected:
  Value() {}
  virtual ~Value() {};
};

template<typename T>
struct ValueImpl : public Value {
  T v;
};

struct DataEntry {
public:
  DataEntry() 
    : shape(nullptr),
      output_value(nullptr) {
  }
  virtual ~DataEntry() {
    // CAUTION: Do not delete shape. Data entry is not shape owner.
    for (uint32_t i = 0; i < input_values.size(); i++) {
      delete input_values[i];
    }
    input_values.clear();
    if (output_value) {
      delete output_value;
    }
  }
public:
  DataShape *shape;
  std::vector<Value *> input_values;
  Value *output_value;
}

struct DataSet {
public:
  DataSet() 
    : shape(nullptr) {
  }
  virtual ~DataSet() {
    if (shape) {
      delete shape;
    }
    for (uint32_t i = 0; i < entries.size(); i++) {
      delete entries[i];
    }
    entries.clear();
  }
public:
  DataShape *shape;
  std::vector<DataEntry *> entries;
};