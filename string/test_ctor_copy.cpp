// String Test Program
//
// Tests:  copy constructor, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String str1("hello");
  String str2(str1);

  // Verify
  std::cout << "str1 == " << str1 << std::endl;
  std::cout << "str2 == " << str2 << std::endl;
  assert(str1 == "hello");
  assert(str2 == "hello");
  std::cout << "Done testing copy constructor." << std::endl;
}
