// String Test Program
//
// Tests:  charArray constructor, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String Str("abcdef");

  // Verify
  std::cout << "abcdef == " << Str << std::endl;
  assert(Str == "abcdef");

  std::cout << "Done testing charArray constructor." << std::endl;
}

