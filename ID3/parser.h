#pragma once

#include <string>

class DataSet;
class Parser {
public:
  Parser(std::string file_path)
    : file_path_(file_path) {
  }
  virtual ~Parser() {
  }
public:
  virtual void Init() = 0;
  virtual void Fill(DataSet *) = 0;
  virtual void Finalize() = 0;
protected:
  std::string file_path_;
};