#pragma once

#include "parser.h"

class TennisParser : public Parser {
public:
  TennisParser(std::string file_path)
    : Parser(file_path) {
  }
  virtual ~TennisParser() {}
public:
  virtual void Init() {}
  virtual void Fill(DataSet *);
  virtual void Finalize() {}
};