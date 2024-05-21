// String Test Program
//
// Tests:  split function, uses ==
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
  String str("hello world");

  // Verify
  std::cout << "str == " << str << std::endl;
  std::vector<String> x = str.split(' ');
  assert(x[0] == "hello");
  assert(x[1] == "world");

  }

  {
    // Test 2
    String str("moo");

    // Verify
    std::cout << "str == " << str << std::endl;
    std::vector<String> x = str.split('m');
    assert(x[0] == "");
    assert(x[1] == "oo");

  }

  {
    // Test 3
    String str('a');

    // Verify
    std::cout << "str == " << str << std::endl;
    std::vector<String> x = str.split('a');
    assert(x[0] == "");
    assert(x[1] == "");

  }


  std::cout << "Done testing split." << std::endl;
}

