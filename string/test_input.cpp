#include <iostream>
#include <fstream>
#include <cstdlib>
#include "string.hpp"

int main() {
  std::ifstream in("test_input.txt");    // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
    std::cerr << "Could not open test_input.txt, exiting." << std::endl;
    exit(1);
  }

  String log;

  while(!in.eof()){
    in >> log;
    if(!in.eof()) {std::cout << log << std::endl;}

  }
  //std::cout << log << std::endl;
  in.close();
  return 0;
}
