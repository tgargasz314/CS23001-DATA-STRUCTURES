// String Test Program
//
// Tests:  find string, uses ==
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
  String words("apples, pears, and bananas");
  //Str.findstr(0, "pears");

  // Verify
  std::cout << "pears starts at: " << words.findstr(0, "pears") << std::endl;
  assert(words.findstr(0, "pears") == 8);

  }

  {

    // Test 2
    String words("apples, pears, and bananas");
    //Str.findstr(0, "");

    // Verify
    std::cout << "bananas starts at: " << words.findstr(0, "bananas") << std::endl;
    assert(words.findstr(0, "bananas") == 19);

  }


  std::cout << "Done testing findstr." << std::endl;
}
