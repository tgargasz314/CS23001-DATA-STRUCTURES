// String Test Program
//
// Tests:  less than operator, uses == and <
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
  String Str1("1234");
  String Str2("12345");
  // Verify
  std::cout << Str1 << " < " << Str2 << std::endl;
  assert(Str1 < Str2);

  }

//==========================================================================
  {

    // Test 2
    String Str1('H');
    String Str2("Hi");
    // Verify
    std::cout << Str1 << " < " << Str2 << std::endl;
    assert(Str1 < Str2);

  }

//==========================================================================
  {

    // Test 3
    String Str1('a');
    String Str2('b');
    // Verify
    std::cout << Str2 << " > " << Str1 << std::endl;
    assert(Str1 < Str2);

  }


//==========================================================================
  {

    // Test 4
    String Str1("banana");
    String Str2('d');
    // Verify
    std::cout << Str2 << " > " << Str1 << std::endl;
    assert(Str1 < Str2);

  }

  //==========================================================================
  {

    // Test 5
    String Str1("banana");
    String Str2("watermelon");
    String Str3("fruits");

    // Verify
    std::cout << Str2 << " > " << Str1 << std::endl;
    assert(Str1 < Str2);

    std::cout << Str2 << " > " << Str1 << std::endl;
    assert(Str2 > Str1);

    std::cout << Str3 << " >= " << Str1 << std::endl;
    assert(Str3 >= Str1);

    std::cout << Str3 << " <= " << Str2 << std::endl;
    assert(Str3 <= Str2);


  }


  std::cout << "Done testing less than operator." << std::endl;
}
