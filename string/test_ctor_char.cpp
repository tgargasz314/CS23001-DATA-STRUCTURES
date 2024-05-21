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
  String Str('c');

  // Verify
  std::cout << "c == " << Str << std::endl;
  assert(Str[0] == 'c');
  assert(Str[1] == '\0'); 
  std::cout << "Done testing character constructor." << std::endl;
}
