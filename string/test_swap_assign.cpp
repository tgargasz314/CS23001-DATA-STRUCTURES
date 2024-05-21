// String Test Program
//
// Tests:  swap and assign functions, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

  //===========================================================================
int main () {
  // Setup

  {
  // Test Swap
  String str1("world");
  String str2("hello");

  // Verify
  std::cout << "str1 == " << str1 << std::endl;
  std::cout << "str2 == " << str2 << std::endl;
  str1.swap(str2);
  std::cout << "str1 == " << str1 << std::endl;
  std::cout << "str2 == " << str2 << std::endl;
  assert(str1 == "hello");
  assert(str2 == "world");

  std::cout << "Done testing swap function." << std::endl;
  }

  {
    // Test Assign
    String str1("yes");
    String str2("no");

    // Verify
    std::cout << "str1 == " << str1 << std::endl;
    std::cout << "str2 == " << str2 << std::endl;
    str1 = str2;
    std::cout << "str1 == " << str1 << std::endl;
    assert(str1 == "no");

    std::cout << "Done testing assign function." << std::endl;
  }
  }

