// String Test Program
//
// Tests:  private int constructor, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  // Test
  String str1;String(13);

  // Verify
  std::cout << "str1 == " << str1 << std::endl;
  assert(str1.capacity() == 12);
  assert(str1.length() == 0);

  std::cout << "Done testing private int constructor." << std::endl;
  }

