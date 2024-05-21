
// String Test Program
//
// Tests:  concatination, uses ==
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {

  {
  // Setup

  // Test 1
  String Str1("Hello");
  String Str2("World");

  // Verify
  std::cout << Str1 + Str2 << std::endl;
  assert(Str1 == "Hello");
  assert(Str2 == "World");
  // assert(Str1 + Str2 == "HelloWorld");
  }

//===========================================================================

  {
// Test 2
String Str1("Hello");
String Str2(" my baby");

// Verify
std::cout << Str1 + Str2 << std::endl;
assert(Str1 == "Hello");
assert(Str2 == " my baby");

Str1 += Str2;

assert(Str1 == "Hello my baby");

  }

  //===========================================================================

  {
    // Test 3
    String Str1('H');
    String Str2("ello my honey");

    // Verify
    std::cout << Str1 + Str2 << std::endl;
    assert(Str1 == 'H');
    assert(Str2 == "ello my honey");

    Str1 += Str2;

    assert(Str1 == "Hello my honey");

  }

  {
    // Test 4
    String Str1("Hello my ragtime ga");
    String Str2('l');
    String Str3;

    // Verify
    std::cout << Str1 + Str2 << std::endl;
    assert(Str1 == "Hello my ragtime ga");
    assert(Str2 == 'l');

    Str3 = Str1 + Str2;

    assert(Str3 == "Hello my ragtime gal");

  }

std::cout << "Done testing concatination." << std::endl;
}
