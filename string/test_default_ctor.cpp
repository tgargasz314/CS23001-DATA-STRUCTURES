// String Test Program
//
// Tests:  default constructor, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String Str;

  // Verify
  std::cout << "'\0' == " << Str << std::endl;
  assert(Str[0] == '\0');

  std::cout << "Done testing default constructor." << std::endl;
}
