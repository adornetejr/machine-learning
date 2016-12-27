#include <iostream>

#include "data.h"
#include "tennis_parser.h"

int main(int argc, char **argv) {
  // Read tennis dataset
  Parser *parser = new TennisParser("samples/tennis.txt");
  DataSet data_set;
  parser->Init();
  parser->Fill(&data_set);
  parser->Finalize();
  delete parser;
  // Make decision tree
  return 0;
}