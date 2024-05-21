// String Test Program
//
// Tests:  tests ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
  // Setup

  {
  // Test 1
  String Str1("Hello");
  String Str2("Hello");

  // Verify
  std::cout << Str1 << " == " << Str2 << std::endl;
  assert(Str1 == Str2);

  }

  {
    // Test 2
    String Str1('i');
    String Str2('i');

    // Verify
    std::cout << Str1 << " == " << Str2 << std::endl;
    assert(Str1 == Str2);

  }


  std::cout << "Done testing == operator." << std::endl;
}



