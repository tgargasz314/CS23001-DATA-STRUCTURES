// String Test Program
//
// Tests:  substring, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String Str("Hello World");

  // Verify
  std::cout << "Wor == " << Str.substr(6, 8) << std::endl;
  assert(Str.substr(6, 8) == "Wor");

  std::cout << "Done testing substring" << std::endl;
}
