// String Test Program
//
// Tests:  subscript operator, uses == and 
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
    String Str("1234");

    // Verify
    std::cout << "Str(1234), Str[1] == " << Str[1] << std::endl;
    assert(Str[1] == '2');

  }

  //==========================================================================
  {

    // Test 2
    String Str('i');

    // Verify
    std::cout << "Str('i'), Str[0] == " << Str[0] << std::endl;
    assert(Str[0] == 'i');

  }

//==========================================================================
  {

    // Test 3
    String Str("Hello");
    Str[3] = 'n';

    // Verify
    std::cout << "Str(Hello), Str[3] = 'n'; == " << Str << std::endl;
    assert(Str == "Helno");

  }


  std::cout << "Done testing subscript operators." << std::endl;
}
